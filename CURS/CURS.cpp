#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <conio.h>
#include <math.h>

int HP = 5, enemies = 0, strongens = 0, enemy1hp = 0, enemy2hp = 0, enemy3hp = 0, UZIbulls = 30, RPGrocks = 5;
int frame = 1, enframe = 1, enframe2 = 1, enframe3 = 1, knframe = 1, mapframe = 1, bullframe = 1, rockframe = 1;
int picw = 128, pich = 128, picw2 = 640, pich2 = 512, ldscrw = 1366, ldscrh = 768, LOADW = 1366, LOADH = 768,
newh = 64, neww = 256, enemyh = 256, enemyw = 512, knifeh = 256, knifew = 256,
bh = 73, bw = 236, butth = 81, buttw = 224, deserth = 1536, desertw = 5464,
fullenemyh = 256, fullenemyw = 640, pauseh = 450, pausew = 700, bulleth = 3, bulletw = 5, rocketh = 9, rocketw = 25,
hph = 88, hpw = 295, barh = 87, barw = 63, wbullw = 7, wbullh = 5, Xh = 33, Xw = 29, numw = 34, numh = 65, 
ensw = 140, ensh = 65;
float wid = 1366, hei = 768, a, b, z, c, n, m;
float my_x = 0.0, my_y = 0.0,
enemy1_x = 0, enemy1_y = 0,
enemy2_x = 0, enemy2_y = 0,
enemy3_x = 0, enemy3_y = 0,
bullet_x = 0.0, bullet_y = 0.0,
rocket_x = 0.0, rocket_y = 0.0,
wormbull_x = 0.0, wormbull_y = 0.0,
deltaMove_x = 0, deltaMove_y = 0, deltaMove2_x = 0, deltaMove2_y = 0;
bool down = false;
bool fullscr = false, mainmenu = true, Move = false, mainloc = false, loc1 = false, loc2 = false, loc3 = false,
knifehit = false, guide = false, pause = false, KNIFE = true, UZI = false, RPG = false, LEFT = false, RIGHT = true,
TRAP = false, DEAD = false, under = false, above = false, lock1 = false, lock2 = false, lock3 = false,
bullet = false, rocket = false, wormbull = false, rghtab = false, rghtund = false, lftab = false, lftund = false,
rghtab2 = false, rghtund2 = false, lftab2 = false, lftund2 = false, enemy1near = false, enemy2near = false, 
enemy3near = false, en1dmg = false, en3dmg = false, en2dmg = false;
int X = 0.0, Y = 0.0; //mouse

GLuint texture[56];

void init();
void textures();
void reshape(int w, int h);
void Keyboard(unsigned char key, int x, int y);
void SKeyboard(int key, int x, int y);
void releaseKey(int key, int x, int y);
void ReleaseSKey(unsigned char key, int x, int y);
void display();
void initialize();
void animation(int);
void MousePressedMove(int ax, int ay);
void MousePressed(int button, int state, int ax, int ay);
void MouseMove(int ax, int ay);
void MainMenu();
void buttons();
void move();
void computePos(float deltaMove_x, float deltaMove_y, float deltaMove2_x, float deltaMove2_y);
void enemy1();
void mainlocation();
void location1();
void knhit();
void guidescr();
void pausescr();
void location2();
void location3();
void hp0();
void hp1();
void hp2();
void hp3();
void hp4();
void hp5();
void weapon1();
void weapon2();
void weapon3();
void moveuzi();
void moverpg();
void bat();
void penguin();
void worm();
void ghost();
void deadscr();
void victory();
void uzibullet();
void rpgrocket();
void wormbullet();
void numbersandenemies();

void init()
{
	initialize();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMotionFunc(MousePressedMove);//Кнопка нажата и мышка двигается
	glutPassiveMotionFunc(MouseMove);
	glutMouseFunc(MousePressed);

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SKeyboard);
	glutSpecialUpFunc(releaseKey);
	glutKeyboardUpFunc(ReleaseSKey);

	glutTimerFunc(40, animation, 1);

}

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(wid, hei);
	glutInitWindowPosition(wid/4.0, hei/4.0);
	glutCreateWindow("Once Again");
	
	glEnable(GL_TEXTURE_2D);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	textures();
	
	init();

	glutMainLoop();
	glDisable(GL_BLEND);
	return 0;
}

void initialize()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, wid, hei, 0); 
	glMatrixMode(GL_MODELVIEW);
}

void computePos(float deltaMove_x, float deltaMove_y, float deltaMove2_x, float deltaMove2_y)
{
	if (pause == true) {}
	else {
		if (mainloc == true) {
			if (my_y + deltaMove_y < 0 || my_y + deltaMove2_y < 0 || my_x + deltaMove_x > 1248 || my_x + deltaMove2_x > 1248 || my_x + deltaMove_x < 0 || my_x + deltaMove2_x < 0 || my_y + deltaMove_y > 640 || my_y + deltaMove2_y > 640) {}
			else {
				my_x += deltaMove_x;
				my_x += deltaMove2_x;
				my_y += deltaMove_y;
				my_y += deltaMove2_y;
			}
			if (my_x >= 1233 && my_y >= 0 && my_y <= 252 && !lock1)
			{
				loc1 = true;
				enemies = 15;
				strongens = 5;
				mainloc = false;
				my_x = 100;
				my_y = 320;
				enemy1hp = 1;
				enemy2hp = 3;
				enemy3hp = 1;
				enemy1_x = 1366.0 / 2, enemy1_y = 80.0,
				enemy2_x = 1160.0, enemy2_y = 315.0,
				enemy3_x = 1366.0 / 2, enemy3_y = 570.0;
			}
			if (my_x >= 532 && my_x <= 646 && my_y >= 635 && !lock2)
			{
				loc2 = true;
				enemies = 8;
				strongens = 5;
				mainloc = false;
				my_x = 100;
				my_y = 320;
				enemy1hp = 2;
				enemy2hp = 1;
				enemy3hp = 2;
				enemy1_x = 1366.0 / 2, enemy1_y = 80.0,
				enemy2_x = 1160.0, enemy2_y = 315.0,
				enemy3_x = 1366.0 / 2, enemy3_y = 570.0;
			}
			if (my_x >= 1233 && my_y >= 586 && !lock3)
			{
				loc3 = true;
				enemies = 8;
				strongens = 5;
				mainloc = false;
				my_x = 100;
				my_y = 320;
				enemy1hp = 2;
				enemy2hp = 2;
				enemy3hp = 2;
				enemy1_x = 1366.0 / 2, enemy1_y = 80.0,
				enemy2_x = 1160.0, enemy2_y = 315.0,
				enemy3_x = 1366.0 / 2, enemy3_y = 570.0;
			}
		}
		if (loc1 == true && !lock1) {
			if (my_y + deltaMove_y < 56 || my_y + deltaMove2_y < 56 || my_x + deltaMove_x > 1180 || my_x + deltaMove2_x > 1180 || my_x + deltaMove_x < 55 || my_x + deltaMove2_x < 55 || my_y + deltaMove_y > 575 || my_y + deltaMove2_y > 575) {}
			else {
				if (my_x >= 70 && my_x <= 480 && my_y >= 0 && my_y <= 120) {
					if (deltaMove_x == -10)
						deltaMove_x = -4;
					if (deltaMove2_x == 10)
						deltaMove2_x = 4;
					if (deltaMove_y == -10)
						deltaMove_y = -4;
					if (deltaMove2_y == 10)
						deltaMove2_y = 4;
				}
				if (my_x >= 930 && my_x <= 1050 && my_y >= 80 && my_y <= 260) {
					if (deltaMove_x == -10)
						deltaMove_x = -4;
					if (deltaMove2_x == 10)
						deltaMove2_x = 4;
					if (deltaMove_y == -10)
						deltaMove_y = -4;
					if (deltaMove2_y == 10)
						deltaMove2_y = 4;
				}
				if (my_x >= 880 && my_x <= 1030 && my_y >= 260 && my_y <= 492) {
					if (deltaMove_x == -10)
						deltaMove_x = -4;
					if (deltaMove2_x == 10)
						deltaMove2_x = 4;
					if (deltaMove_y == -10)
						deltaMove_y = -4;
					if (deltaMove2_y == 10)
						deltaMove2_y = 4;
				}
				if (my_x >= 230 && my_x <= 572 && my_y >= 426 && my_y <= 535) {
					if (deltaMove_x == -10)
						deltaMove_x = -4;
					if (deltaMove2_x == 10)
						deltaMove2_x = 4;
					if (deltaMove_y == -10)
						deltaMove_y = -4;
					if (deltaMove2_y == 10)
						deltaMove2_y = 4;
				}
				my_x += deltaMove_x;
				my_y += deltaMove_y;
				my_x += deltaMove2_x;
				my_y += deltaMove2_y;
			}
		}
		if (loc2 == true && !lock2) {
			if (my_y + deltaMove_y < 55 || my_y + deltaMove2_y < 55 || my_x + deltaMove_x > 1180 || my_x + deltaMove2_x > 1180 || my_x + deltaMove_x < 55 || my_x + deltaMove2_x < 55 || my_y + deltaMove_y > 575 || my_y + deltaMove2_y > 575) {}
			else {
				if (my_x >= 486 && my_x <= 657 && my_y >= 0 && my_y <= 128) {
					if (deltaMove_x == -10)
						deltaMove_x = -4;
					if (deltaMove2_x == 10)
						deltaMove2_x = 4;
					if (deltaMove_y == -10)
						deltaMove_y = -4;
					if (deltaMove2_y == 10)
						deltaMove2_y = 4;
				}
				if (my_x >= 794 && my_x <= 968 && my_y >= 203 && my_y <= 368) {
					if (deltaMove_x == -10)
						deltaMove_x = -4;
					if (deltaMove2_x == 10)
						deltaMove2_x = 4;
					if (deltaMove_y == -10)
						deltaMove_y = -4;
					if (deltaMove2_y == 10)
						deltaMove2_y = 4;
				}
				if (my_x >= 34 && my_x <= 205 && my_y >= 375) {
					if (deltaMove_x == -10)
						deltaMove_x = -4;
					if (deltaMove2_x == 10)
						deltaMove2_x = 4;
					if (deltaMove_y == -10)
						deltaMove_y = -4;
					if (deltaMove2_y == 10)
						deltaMove2_y = 4;
				}
				my_x += deltaMove_x;
				my_y += deltaMove_y;
				my_x += deltaMove2_x;
				my_y += deltaMove2_y;
			}
		}
		if (loc3 == true && !lock3) {
			if (my_y + deltaMove_y < 55 || my_y + deltaMove2_y < 55 || my_x + deltaMove_x > 1180 || my_x + deltaMove2_x > 1180 || my_x + deltaMove_x < 55 || my_x + deltaMove2_x < 55 || my_y + deltaMove_y > 575 || my_y + deltaMove2_y > 575) {}
			else {
				if (my_x >= 786 && my_x <= 952 && my_y <= 71) {
					if (!TRAP) {
						HP--;
						TRAP = true;
					}
				}
				else if (my_x >= 146 && my_x <= 313 && my_y >= 186 && my_y <= 216) {
					if (!TRAP) {
						HP--;
						TRAP = true;
					}
				}
				else if (my_x >= 364 && my_x <= 530 && my_y >= 434 && my_y <= 464) {
					if (!TRAP) {
						HP--;
						TRAP = true;
					}
				}
				else if (my_x >= 963 && my_x <= 1129 && my_y >= 496 && my_y <= 526) {
					if (!TRAP) {
						HP--;
						TRAP = true;
					}
				}
				else
					TRAP = false;
				my_x += deltaMove_x;
				my_y += deltaMove_y;
				my_x += deltaMove2_x;
				my_y += deltaMove2_y;
			}
		}
	}
}

void display()
{
	if (mainmenu == true)
	{
		MainMenu();
		buttons();
	}
	else if (guide == true) 
	{
		guidescr();
	}
	else {
		glClear(GL_COLOR_BUFFER_BIT);
		if (lock1 && lock2 && lock3) {
			victory();
		}
		else if (HP <= 0) {
			deadscr();
			DEAD = true;
		}
		else
		{
			if (mainloc == true)
			{
				mainlocation();
			}
			if (loc1 == true)
			{
				location1();
				numbersandenemies();
				if (enemy1hp > 0 || enemy3hp > 0)
					enemy1();
				if (enemy2hp > 0)
					penguin();
				if (enemies == 0 && strongens == 0) {
					loc1 = false;
					enframe = 0;
					enframe2 = 0;
					enframe3 = 0;
					mainloc = true;
					lock1 = true;
					my_x = 150.0, my_y = 120.0;
				}
			}
			if (loc2 == true)
			{
				location2();
				numbersandenemies();
				if (!pause) {
					if (my_x >= 486 && my_x <= 657 && my_y >= 0 && my_y <= 128) {
						if (my_x >= 572)
							my_x -= 1;
						if (my_x <= 572)
							my_x += 1;
						if (my_y >= 64)
							my_y -= 1;
						if (my_y <= 64)
							my_y += 1;
					}
					if (my_x >= 794 && my_x <= 968 && my_y >= 203 && my_y <= 368) {
						if (my_x >= 881)
							my_x -= 1;
						if (my_x <= 881)
							my_x += 1;
						if (my_y >= 286)
							my_y -= 1;
						if (my_y <= 286)
							my_y += 1;
					}
					if (my_x >= 34 && my_x <= 205 && my_y >= 375) {
						if (my_x >= 120)
							my_x -= 1;
						if (my_x <= 120)
							my_x += 1;
						if (my_y >= 470)
							my_y -= 1;
						if (my_y <= 470)
							my_y += 1;
					}
				}
				if (enemy1hp > 0 || enemy3hp > 0)
					ghost();
				if (enemy2hp > 0) {
					worm();
					if (enframe2 == 25)
						wormbull = true;
				}
				if (wormbull)
					wormbullet();
				if (enemies == 0 && strongens == 0) {
					loc2 = false;
					mainloc = true;
					enframe = 0;
					enframe2 = 0;
					enframe3 = 0;
					wormbull = false;
					lock2 = true;
					my_x = 150.0, my_y = 120.0;
				}
			}
			if (loc3 == true)
			{
				location3();
				numbersandenemies();
				if (enemy1hp > 0 || enemy3hp > 0)
					bat();
				if (enemy2hp > 0)
					ghost();
				if (enemies == 0 && strongens == 0) {
					loc3 = false;
					enframe = 0;
					enframe2 = 0;
					enframe3 = 0;
					mainloc = true;
					lock3 = true;
					my_x = 150.0, my_y = 120.0;
				}
			}

			if (deltaMove_x || deltaMove_y || deltaMove2_x || deltaMove2_y)
			{
				Move = true;
				computePos(deltaMove_x, deltaMove_y, deltaMove2_x, deltaMove2_y);
			}
			else
				Move = false;
			if (!Move) {
				if (KNIFE)
				{
					if (KNIFE && knifehit && !mainmenu && !mainloc) {
						knhit();
					}
					else {
						if (RIGHT) {
							glBindTexture(GL_TEXTURE_2D, texture[0]);
							glBegin(GL_QUADS);


							glTexCoord2f(0.0, 0.0);
							glVertex2f(my_x, my_y);
							glTexCoord2f(0.0, 1.0);
							my_y += 128.0;
							glVertex2f(my_x, my_y);
							glTexCoord2f(1.0, 1.0);
							my_x += 128.0;
							glVertex2f(my_x, my_y);
							glTexCoord2f(1.0, 0.0);
							my_y -= 128.0;
							glVertex2f(my_x, my_y);
							my_x -= 128.0;
							glEnd();
						}
						if (LEFT)
						{
							glBindTexture(GL_TEXTURE_2D, texture[0]);
							glBegin(GL_QUADS);


							glTexCoord2f(1.0, 0.0);
							glVertex2f(my_x, my_y);
							glTexCoord2f(1.0, 1.0);
							my_y += 128.0;
							glVertex2f(my_x, my_y);
							glTexCoord2f(0.0, 1.0);
							my_x += 128.0;
							glVertex2f(my_x, my_y);
							glTexCoord2f(0.0, 0.0);
							my_y -= 128.0;
							glVertex2f(my_x, my_y);
							my_x -= 128.0;
							glEnd();
						}
					}
				}
				else if (UZI)
				{
					if (RIGHT) {
						glBindTexture(GL_TEXTURE_2D, texture[27]);
						glBegin(GL_QUADS);


						glTexCoord2f(0.0, 0.0);
						glVertex2f(my_x, my_y);
						glTexCoord2f(0.0, 1.0);
						my_y += 128.0;
						glVertex2f(my_x, my_y);
						glTexCoord2f(1.0, 1.0);
						my_x += 128.0;
						glVertex2f(my_x, my_y);
						glTexCoord2f(1.0, 0.0);
						my_y -= 128.0;
						glVertex2f(my_x, my_y);
						my_x -= 128.0;
						glEnd();
					}
					if (LEFT)
					{
						glBindTexture(GL_TEXTURE_2D, texture[27]);
						glBegin(GL_QUADS);


						glTexCoord2f(1.0, 0.0);
						glVertex2f(my_x, my_y);
						glTexCoord2f(1.0, 1.0);
						my_y += 128.0;
						glVertex2f(my_x, my_y);
						glTexCoord2f(0.0, 1.0);
						my_x += 128.0;
						glVertex2f(my_x, my_y);
						glTexCoord2f(0.0, 0.0);
						my_y -= 128.0;
						glVertex2f(my_x, my_y);
						my_x -= 128.0;
						glEnd();
					}
				}
				else if (RPG)
				{
					if (RIGHT) {
						glBindTexture(GL_TEXTURE_2D, texture[28]);
						glBegin(GL_QUADS);


						glTexCoord2f(0.0, 0.0);
						glVertex2f(my_x, my_y);
						glTexCoord2f(0.0, 1.0);
						my_y += 128.0;
						glVertex2f(my_x, my_y);
						glTexCoord2f(1.0, 1.0);
						my_x += 128.0;
						glVertex2f(my_x, my_y);
						glTexCoord2f(1.0, 0.0);
						my_y -= 128.0;
						glVertex2f(my_x, my_y);
						my_x -= 128.0;
						glEnd();
					}
					if (LEFT)
					{
						glBindTexture(GL_TEXTURE_2D, texture[28]);
						glBegin(GL_QUADS);


						glTexCoord2f(1.0, 0.0);
						glVertex2f(my_x, my_y);
						glTexCoord2f(1.0, 1.0);
						my_y += 128.0;
						glVertex2f(my_x, my_y);
						glTexCoord2f(0.0, 1.0);
						my_x += 128.0;
						glVertex2f(my_x, my_y);
						glTexCoord2f(0.0, 0.0);
						my_y -= 128.0;
						glVertex2f(my_x, my_y);
						my_x -= 128.0;
						glEnd();
					}
				}

			}
			else
			{
				if (KNIFE) {
					if (KNIFE && knifehit && !mainmenu && !mainloc) {
						knhit();
					}
					else
						move();
				}
				else if (UZI)
					moveuzi();
				else if (RPG)
					moverpg();
			}
			if (HP == 5)
				hp5();
			else if (HP == 4)
				hp4();
			else if (HP == 3)
				hp3();
			else if (HP == 2)
				hp2();
			else if (HP == 1)
				hp1();
			else if (HP <= 0)
				hp0();

			if (KNIFE && !mainmenu)
				weapon1();
			else if (UZI && !mainmenu)
				weapon2();
			else if (RPG && !mainmenu)
				weapon3();

			if (rocket && !mainmenu) {
				rpgrocket();
			}
			
			if (bullet && !mainmenu) {
				uzibullet();
			}
			if (pause)
				pausescr();
		}
		glutSwapBuffers();
	}
}

void reshape(int w, int h) {
	if (h == 0)
		h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, h, 0);
	glMatrixMode(GL_MODELVIEW);
}

void animation(int)
{
	if (pause == true) {}
	else {
		if (loc1 == true) {
			if (enemy1hp > 0) {
				if (enemy1_x - my_x >= 64)
					enemy1_x -= 5;
				if (enemy1_x - my_x <= -64)
					enemy1_x += 5;
				if (enemy1_y - my_y >= 0)
					enemy1_y -= 5;
				if (enemy1_y - my_y <= 0)
					enemy1_y += 5;

				if (enemy1_x - my_x <= 70 && enemy1_x - my_x >= -70 && enemy1_y - my_y <= 5 && enemy1_y - my_y >= -5) {
					if (!enemy1near) {
						HP--;
						enemy1near = true;
					}
				}
				else
					enemy1near = false;
			}

			if (enemy2hp > 0) {
				if (enemy2_x - my_x >= 64)
					enemy2_x -= 5;
				if (enemy2_x - my_x <= -64)
					enemy2_x += 5;
				if (enemy2_y - my_y >= 0)
					enemy2_y -= 5;
				if (enemy2_y - my_y <= 0)
					enemy2_y += 5;

				if (enemy2_x - my_x <= 70 && enemy2_x - my_x >= -70 && enemy2_y - my_y <= 5 && enemy2_y - my_y >= -5) {
					if (!enemy2near) {
						HP -= 2;
						enemy2near = true;
					}
				}
				else
					enemy2near = false;
			}

			if (enemy3hp > 0) {
				if (enemy3_x - my_x >= 64)
					enemy3_x -= 5;
				if (enemy3_x - my_x <= -64)
					enemy3_x += 5;
				if (enemy3_y - my_y >= 0)
					enemy3_y -= 5;
				if (enemy3_y - my_y <= 0)
					enemy3_y += 5;

				if (enemy3_x - my_x <= 70 && enemy3_x - my_x >= -70 && enemy3_y - my_y <= 5 && enemy3_y - my_y >= -5) {
					if (!enemy3near) {
						HP--;
						enemy3near = true;
					}
				}
				else
					enemy3near = false;
			}
			if (enemy2hp <= 0) {
				if (strongens > 0) {
					strongens--;
					enemy2_x = 0.0 / 2, enemy2_y = 0.0;
				}
				if (strongens > 0) {
					enemy2hp = 3;
					enemy2_x = 1160.0, enemy2_y = 315.0;
				}
			}
			if (enemy1hp <= 0) {
				if (enemies > 1 || enemy3hp <= 0 && enemies == 1) {
					enemies--;
					enemy1_x = 0.0 / 2, enemy1_y = 0.0;
				}
				if (enemies > 1) {
					enemy1hp = 1;
					enemy1_x = 1366.0 / 2, enemy1_y = 80.0;
				}
			}
			if (enemy3hp <= 0) {
				if (enemies > 1 || enemy1hp <= 0 && enemies == 1) {
					enemies--;
					enemy3_x = 0.0 / 2, enemy3_y = 0.0;
				}
				if (enemies > 1) {
					enemy3hp = 1;
					enemy3_x = 1366.0 / 2, enemy3_y = 570.0;
				}
			}
			if (bullet) {
				if (bullet_x >= enemy1_x && bullet_x <= enemy1_x + 128 && bullet_y >= enemy1_y && bullet_y <= enemy1_y + 128) {
					enemy1hp--;
					bullet = false;
					bullframe = 1;
					bullet_x = my_x + 128, bullet_y = my_y + 83;
				}
				if (bullet_x >= enemy2_x && bullet_x <= enemy2_x + 128 && bullet_y >= enemy2_y && bullet_y <= enemy2_y + 128) {
					enemy2hp--;
					bullet = false;
					bullframe = 1;
					bullet_x = my_x + 128, bullet_y = my_y + 83;
				}
				if (bullet_x >= enemy3_x && bullet_x <= enemy3_x + 128 && bullet_y >= enemy3_y && bullet_y <= enemy3_y + 128) {
					enemy3hp--;
					bullet = false;
					bullframe = 1;
					bullet_x = my_x + 128, bullet_y = my_y + 83;
				}
			}

			if (knifehit) {
				if (X >= enemy1_x && X <= enemy1_x + 128 && Y >= enemy1_y && Y <= enemy1_y + 128) {
					if (enemy1_x - my_x <= 170 && enemy1_x - my_x >= -170 && enemy1_y - my_y <= 130 && enemy1_y - my_y >= -130) {
						if (knframe == 3)
							enemy1hp--;
					}
				}
				if (X >= enemy2_x && X <= enemy2_x + 128 && Y >= enemy2_y && Y <= enemy2_y + 128) {
					if (enemy2_x - my_x <= 170 && enemy2_x - my_x >= -170 && enemy2_y - my_y <= 130 && enemy2_y - my_y >= -130) {
						if (knframe == 3)
							enemy2hp--;
					}
				}
				if (X >= enemy3_x && X <= enemy3_x + 128 && Y >= enemy3_y && Y <= enemy3_y + 128) {
					if (enemy3_x - my_x <= 170 && enemy3_x - my_x >= -170 && enemy3_y - my_y <= 130 && enemy3_y - my_y >= -130) {
						if (knframe == 3)
							enemy3hp--;
					}
				}
			}

			if (rocket) {
				if (rocket_x >= enemy1_x && rocket_x <= enemy1_x + 128 && rocket_y >= enemy1_y && rocket_y <= enemy1_y + 128) {
					enemy1hp -= 3;
					enemy2hp -= 3;
					enemy3hp -= 3;
					rocket = false;
					rockframe = 1;
					rocket_x = my_x + 128, rocket_y = my_y + 83;
				}
				if (rocket_x >= enemy2_x && rocket_x <= enemy2_x + 128 && rocket_y >= enemy2_y && rocket_y <= enemy2_y + 128) {
					enemy1hp -= 3;
					enemy2hp -= 3;
					enemy3hp -= 3;
					rocket = false;
					rockframe = 1;
					rocket_x = my_x + 128, rocket_y = my_y + 83;
				}
				if (rocket_x >= enemy3_x && rocket_x <= enemy3_x + 128 && rocket_y >= enemy3_y && rocket_y <= enemy3_y + 128) {
					enemy1hp -= 3;
					enemy2hp -= 3;
					enemy3hp -= 3;
					rocket = false;
					rockframe = 1;
					rocket_x = my_x + 128, rocket_y = my_y + 83;
				}
			}
		}
	
		if (loc2 == true) {
			if (enemy1hp > 0) {
				if (enemy1_x - my_x >= 64)
					enemy1_x -= 5;
				if (enemy1_x - my_x <= -64)
					enemy1_x += 5;
				if (enemy1_y - my_y >= 0)
					enemy1_y -= 5;
				if (enemy1_y - my_y <= 0)
					enemy1_y += 5;

				if (enemy1_x - my_x <= 70 && enemy1_x - my_x >= -70 && enemy1_y - my_y <= 5 && enemy1_y - my_y >= -5) {
					if (!enemy1near) {
						HP -= 2;
						enemy1near = true;
					}
				}
				else
					enemy1near = false;
			}

			if (!pause && wormbullet) {
				wormbull_x -= a;
				if (above)
					wormbull_y -= b;
				else if (under)
					wormbull_y += b;
			}

			if (wormbull_x - my_x >= 0 && wormbull_x - my_x <= 110 && wormbull_y - my_y <= 110 && wormbull_y - my_y >= -1) {
				if (!enemy2near) {
					HP -= 2;
					enemy2near = true;
				}
				wormbull = false;
			}
			else
			{
				enemy2near = false;
			}

			if (enemy3hp > 0) {
				if (enemy3_x - my_x >= 64)
					enemy3_x -= 5;
				if (enemy3_x - my_x <= -64)
					enemy3_x += 5;
				if (enemy3_y - my_y >= 0)
					enemy3_y -= 5;
				if (enemy3_y - my_y <= 0)
					enemy3_y += 5;

				if (enemy3_x - my_x <= 70 && enemy3_x - my_x >= -70 && enemy3_y - my_y <= 5 && enemy3_y - my_y >= -5) {
					if (!enemy3near) {
						HP -= 2;
						enemy3near = true;
					}
				}
				else
					enemy3near = false;
			}
			
			if (enemy2hp <= 0) {
				if (strongens > 0) {
					strongens--;
					enemy2_x = 0.0 / 2, enemy2_y = 0.0;
				}
				if (strongens > 0) {
					enemy2hp = 1;
					enemy2_x = 1160.0, enemy2_y = 315.0;
				}
			}

			if (enemy1hp <= 0) {
				if (enemies > 1 || enemy3hp <= 0 && enemies == 1) {
					enemies--;
					enemy1_x = 0.0 / 2, enemy1_y = 0.0;
				}
				if (enemies > 1) {
					enemy1hp = 2;
					enemy1_x = 1366.0 / 2, enemy1_y = 80.0;
				}
			}
			if (enemy3hp <= 0) {
				if (enemies > 1 || enemy1hp <= 0 && enemies == 1) {
					enemies--;
					enemy3_x = 0.0 / 2, enemy3_y = 0.0;
				}
				if (enemies > 1) {
					enemy3hp = 2;
					enemy3_x = 1366.0 / 2, enemy3_y = 570.0;
				}
			}

			if (bullet) {
				if (bullet_x >= enemy1_x && bullet_x <= enemy1_x + 128 && bullet_y >= enemy1_y && bullet_y <= enemy1_y + 128) {
					enemy1hp--;
					bullet = false;
					bullframe = 1;
					bullet_x = my_x + 128, bullet_y = my_y + 83;
				}
				if (bullet_x >= enemy2_x && bullet_x <= enemy2_x + 128 && bullet_y >= enemy2_y && bullet_y <= enemy2_y + 128) {
					enemy2hp--;
					bullet = false;
					bullframe = 1;
					bullet_x = my_x + 128, bullet_y = my_y + 83;
				}
				if (bullet_x >= enemy3_x && bullet_x <= enemy3_x + 128 && bullet_y >= enemy3_y && bullet_y <= enemy3_y + 128) {
					enemy3hp--;
					bullet = false;
					bullframe = 1;
					bullet_x = my_x + 128, bullet_y = my_y + 83;
				}
			}

			if (knifehit) {
				if (X >= enemy1_x && X <= enemy1_x + 128 && Y >= enemy1_y && Y <= enemy1_y + 128) {
					if (enemy1_x - my_x <= 110 && enemy1_x - my_x >= -110 && enemy1_y - my_y <= 80 && enemy1_y - my_y >= -80) {
						if (knframe == 3)
							enemy1hp--;
					}
				}
				if (X >= enemy2_x && X <= enemy2_x + 128 && Y >= enemy2_y && Y <= enemy2_y + 128) {
					if (enemy2_x - my_x <= 110 && enemy2_x - my_x >= -110 && enemy2_y - my_y <= 80 && enemy2_y - my_y >= -80) {
						if (knframe == 3)
							enemy2hp--;
					}
				}
				if (X >= enemy3_x && X <= enemy3_x + 128 && Y >= enemy3_y && Y <= enemy3_y + 128) {
					if (enemy3_x - my_x <= 110 && enemy3_x - my_x >= -110 && enemy3_y - my_y <= 80 && enemy3_y - my_y >= -80) {
						if (knframe == 3)
							enemy3hp--;
					}
				}
			}

			if (rocket) {
				if (rocket_x >= enemy1_x && rocket_x <= enemy1_x + 128 && rocket_y >= enemy1_y && rocket_y <= enemy1_y + 128) {
					enemy1hp -= 3;
					enemy2hp -= 3;
					enemy3hp -= 3;
					rocket = false;
					rockframe = 1;
					rocket_x = my_x + 128, rocket_y = my_y + 83;
				}
				if (rocket_x >= enemy2_x && rocket_x <= enemy2_x + 128 && rocket_y >= enemy2_y && rocket_y <= enemy2_y + 128) {
					enemy1hp -= 3;
					enemy2hp -= 3;
					enemy3hp -= 3;
					rocket = false;
					rockframe = 1;
					rocket_x = my_x + 128, rocket_y = my_y + 83;
				}
				if (rocket_x >= enemy3_x && rocket_x <= enemy3_x + 128 && rocket_y >= enemy3_y && rocket_y <= enemy3_y + 128) {
					enemy1hp -= 3;
					enemy2hp -= 3;
					enemy3hp -= 3;
					rocket = false;
					rockframe = 1;
					rocket_x = my_x + 128, rocket_y = my_y + 83;
				}
			}
		}

		if (loc3 == true) {
			if (enemy1hp > 0) {
				if (enemy1_x - my_x >= 64)
					enemy1_x -= 5;
				if (enemy1_x - my_x <= -64)
					enemy1_x += 5;
				if (enemy1_y - my_y >= 0)
					enemy1_y -= 5;
				if (enemy1_y - my_y <= 0)
					enemy1_y += 5;

				if (enemy1_x - my_x <= 70 && enemy1_x - my_x >= -70 && enemy1_y - my_y <= 5 && enemy1_y - my_y >= -5) {
					if (!enemy1near) {
						HP--;
						enemy1near = true;
					}
				}
				else
					enemy1near = false;
			}

			if (enemy2hp > 0) {
				if (enemy2_x - my_x >= 64)
					enemy2_x -= 5;
				if (enemy2_x - my_x <= -64)
					enemy2_x += 5;
				if (enemy2_y - my_y >= 0)
					enemy2_y -= 5;
				if (enemy2_y - my_y <= 0)
					enemy2_y += 5;

				if (enemy2_x - my_x <= 70 && enemy2_x - my_x >= -70 && enemy2_y - my_y <= 5 && enemy2_y - my_y >= -5) {
					if (!enemy2near) {
						HP -= 2;
						enemy2near = true;
					}
				}
				else
					enemy2near = false;
			}

			if (enemy3hp > 0) {
				if (enemy3_x - my_x >= 64)
					enemy3_x -= 5;
				if (enemy3_x - my_x <= -64)
					enemy3_x += 5;
				if (enemy3_y - my_y >= 0)
					enemy3_y -= 5;
				if (enemy3_y - my_y <= 0)
					enemy3_y += 5;

				if (enemy3_x - my_x <= 70 && enemy3_x - my_x >= -70 && enemy3_y - my_y <= 5 && enemy3_y - my_y >= -5) {
					if (!enemy3near) {
						HP--;
						enemy3near = true;
					}
				}
				else
					enemy3near = false;
			}
			if (enemy2hp <= 0) {
				if (strongens > 0) {
					strongens--;
					enemy2_x = 0.0 / 2, enemy2_y = 0.0;
				}
				if (strongens > 0) {
					enemy2hp = 2;
					enemy2_x = 1160.0, enemy2_y = 315.0;
				}
			}
			if (enemy1hp <= 0) {
				if (enemies > 1 || enemy3hp <= 0 && enemies == 1) {
					enemies--;
					enemy1_x = 0.0 / 2, enemy1_y = 0.0;
				}
				if (enemies > 1) {
					enemy1hp = 2;
					enemy1_x = 1366.0 / 2, enemy1_y = 80.0;
				}
			}
			if (enemy3hp <= 0) {
				if (enemies > 1 || enemy1hp <= 0 && enemies == 1) {
					enemies--;
					enemy3_x = 0.0 / 2, enemy3_y = 0.0;
				}
				if (enemies > 1) {
					enemy3hp = 2;
					enemy3_x = 1366.0 / 2, enemy3_y = 570.0;
				}
			}  

			if (bullet) {
				if (bullet_x >= enemy1_x && bullet_x <= enemy1_x + 128 && bullet_y >= enemy1_y && bullet_y <= enemy1_y + 128) {
					enemy1hp--;
					bullet = false;
					bullframe = 1;
					bullet_x = my_x + 128, bullet_y = my_y + 83;
				}
				if (bullet_x >= enemy2_x && bullet_x <= enemy2_x + 128 && bullet_y >= enemy2_y && bullet_y <= enemy2_y + 128) {
					enemy2hp--;
					bullet = false;
					bullframe = 1;
					bullet_x = my_x + 128, bullet_y = my_y + 83;
				}
				if (bullet_x >= enemy3_x && bullet_x <= enemy3_x + 128 && bullet_y >= enemy3_y && bullet_y <= enemy3_y + 128) {
					enemy3hp--;
					bullet = false;
					bullframe = 1;
					bullet_x = my_x + 128, bullet_y = my_y + 83;
				}
			}
			
			if (knifehit) {
				if (X >= enemy1_x && X <= enemy1_x + 128 && Y >= enemy1_y && Y <= enemy1_y + 128) {
					if (enemy1_x - my_x <= 110 && enemy1_x - my_x >= -110 && enemy1_y - my_y <= 80 && enemy1_y - my_y >= -80) {
						if (knframe == 3)
							enemy1hp--;
					}
				}
				if (X >= enemy2_x && X <= enemy2_x + 128 && Y >= enemy2_y && Y <= enemy2_y + 128) {
					if (enemy2_x - my_x <= 110 && enemy2_x - my_x >= -110 && enemy2_y - my_y <= 80 && enemy2_y - my_y >= -80) {
						if (knframe == 3)
							enemy2hp--;
					}
				}
				if (X >= enemy3_x && X <= enemy3_x + 128 && Y >= enemy3_y && Y <= enemy3_y + 128) {
					if (enemy3_x - my_x <= 110 && enemy3_x - my_x >= -110 && enemy3_y - my_y <= 80 && enemy3_y - my_y >= -80) {
						if (knframe == 3)
							enemy3hp--;
					}
				}
			}

			if (rocket) {
				if (rocket_x >= enemy1_x && rocket_x <= enemy1_x + 128 && rocket_y >= enemy1_y && rocket_y <= enemy1_y + 128) {
					enemy1hp -= 3;
					enemy2hp -= 3;
					enemy3hp -= 3;
					rocket = false;
					rockframe = 1;
					rocket_x = my_x + 128, rocket_y = my_y + 83;
				}
				if (rocket_x >= enemy2_x && rocket_x <= enemy2_x + 128 && rocket_y >= enemy2_y && rocket_y <= enemy2_y + 128) {
					enemy1hp -= 3;
					enemy2hp -= 3;
					enemy3hp -= 3;
					rocket = false;
					rockframe = 1;
					rocket_x = my_x + 128, rocket_y = my_y + 83;
				}
				if (rocket_x >= enemy3_x && rocket_x <= enemy3_x + 128 && rocket_y >= enemy3_y && rocket_y <= enemy3_y + 128) {
					enemy1hp -= 3;
					enemy2hp -= 3;
					enemy3hp -= 3;
					rocket = false;
					rockframe = 1;
					rocket_x = my_x + 128, rocket_y = my_y + 83;
				}
			}
		}

	}
		glutPostRedisplay();
		glutTimerFunc(40, animation, 0);
}

void MouseMove(int ax, int ay)
{
	X = ax; 
	Y = ay;
}

void MousePressed(int button, int state, int ax, int ay)
{
	X = ax; Y = ay;
	down = button == GLUT_LEFT_BUTTON && state == GLUT_LEFT;
	if (down) {
		if (guide == true)
		{
			if (X >= 1102 && X <= 1337 && Y >= 677 && Y <= 749)	
			{
				mainmenu = true;
				guide = false;
			}
		}
		else if (mainmenu) {
			if (X >= 1018 && X <= 1264 && Y >= 620 && Y <= 676) {
				exit(0);
			}
			else if (X >= 1010 && X <= 1266 && Y >= 340 && Y <= 404)
			{
				RPGrocks = 5;
				UZIbulls = 30;
				rocket = false;
				knifehit = false;
				bullet = false;
				UZI = false;
				RPG = false;
				KNIFE = true;
				DEAD = false;
				mainmenu = false;
				mainloc = true;
				my_x = 150.0, my_y = 120.0;
				glutSwapBuffers();
				glutPostRedisplay();
			}
			else if (X >= 1016 && X <= 1272 && Y >= 482 && Y <= 546)
			{
				mainmenu = false;
				guide = true;
			}
		}
		if (loc1 || loc2 || loc3) {
			if (UZI && UZIbulls != 0 && !pause && !mainmenu) {
				bullet = true;
			}
			if (RPG && RPGrocks != 0 && !pause && !mainmenu) {
				rocket = true;
			}
			if (KNIFE && !pause && !mainmenu)
				knifehit = true;
		}
		if (pause == true)
		{
			if (X >= 575 && X <= 799 && Y >= 288 && Y <= 369)
				pause = false;
			else if (X >= 575 && X <= 799 && Y >= 385 && Y <= 466)
			{
				enframe = 0;
				enframe2 = 0;
				enframe3 = 0;
				wormbull = false;
				knifehit = false;
				bullet = false;
				UZI = false;
				RPG = false;
				KNIFE = true;
				RPGrocks = 5;
				UZIbulls = 30;
				lock1 = false;
				lock2 = false;
				lock3 = false;
				DEAD = false;
				enemies = 0;
				strongens = 0;
				loc3 = false;
				loc2 = false;
				loc1 = false;
				pause = false;
				mainloc = true;
				my_x = 150.0, my_y = 120.0;
				HP = 5;
			}
			else if (X >= 575 && X <= 799 && Y >= 486 && Y <= 567)
			{
				enframe = 0;
				enframe2 = 0;
				enframe3 = 0;
				wormbull = false;
				knifehit = false;
				bullet = false;
				UZI = false;
				RPG = false;
				KNIFE = true;
				RPGrocks = 5;
				UZIbulls = 30;
				lock1 = false;
				lock2 = false;
				lock3 = false;
				DEAD = false;
				enemies = 0;
				strongens = 0;
				loc3 = false;
				loc2 = false;
				loc1 = false;
				pause = false;
				mainmenu = true;
				HP = 5;
			}
		}
		if (lock1 && lock2 && lock3)
		{
			if (X >= 550 && X <= 773 && Y >= 571 && Y <= 651)
			{
				enframe = 0;
				enframe2 = 0;
				enframe3 = 0;
				wormbull = false;
				knifehit = false;
				bullet = false;
				UZI = false;
				RPG = false;
				KNIFE = true;
				RPGrocks = 5;
				UZIbulls = 30;
				lock1 = false;
				lock2 = false;
				lock3 = false;
				DEAD = false;
				enemies = 0;
				strongens = 0;
				loc3 = false;
				loc2 = false;
				loc1 = false;
				pause = false;
				mainmenu = true;
				HP = 5;
			}
		}
		if (DEAD)
		{
			if (X >= 550 && X <= 773 && Y >= 397 && Y <= 477)
			{
				enframe = 0;
				enframe2 = 0;
				enframe3 = 0;
				wormbull = false;
				knifehit = false;
				bullet = false;
				UZI = false;
				RPG = false;
				KNIFE = true;
				RPGrocks = 5;
				UZIbulls = 30;
				lock1 = false;
				lock2 = false;
				lock3 = false;
				DEAD = false;
				enemies = 0;
				strongens = 0;
				loc3 = false;
				loc2 = false;
				loc1 = false;
				pause = false;
				mainloc = true;
				my_x = 150.0, my_y = 120.0;
				HP = 5;
			}
			else if (X >= 550 && X <= 773 && Y >= 571 && Y <= 651)
			{
				enframe = 0;
				enframe2 = 0;
				enframe3 = 0;
				wormbull = false;
				knifehit = false;
				bullet = false;
				UZI = false;
				RPG = false;
				KNIFE = true;
				RPGrocks = 5;
				UZIbulls = 30;
				lock1 = false;
				lock2 = false;
				lock3 = false;
				DEAD = false;
				enemies = 0;
				strongens = 0;
				loc3 = false;
				loc2 = false;
				loc1 = false;
				pause = false;
				mainmenu = true;
				HP = 5;
			}
		}
	}
}

void MousePressedMove(int ax, int ay)
{
	if (down) {
		X = ax;
		Y = ay;
	}
}

void Keyboard(unsigned char key, int x, int y)
{
	if (mainmenu == true) 
	{

	}
	else {
		switch (key)
		{
		case 'w':
			deltaMove_y = -10.0;
			glutPostRedisplay();
			break;
		case 's':
			deltaMove2_y = 10.0;
			glutPostRedisplay();
			break;
		case 'a':
			LEFT = true;
			RIGHT = false;
			deltaMove_x = -10.0;
			glutPostRedisplay();
			break;
		case 'd':
			RIGHT = true;
			LEFT = false;
			deltaMove2_x = 10.0;
			glutPostRedisplay();
			break;
		case 'W':
			deltaMove_y = -10.0;
			glutPostRedisplay();
			break;
		case 'S':
			deltaMove2_y = 10.0;
			glutPostRedisplay();
			break;
		case 'A':
			LEFT = true;
			RIGHT = false;
			deltaMove_x = -10.0;
			glutPostRedisplay();
			break;
		case 'D':
			RIGHT = true;
			LEFT = false;
			deltaMove2_x = 10.0;
			glutPostRedisplay();
			break;
		case 27:
			if (pause == false)
				pause = true;
			else if (pause == true)
				pause = false;
			if (guide == true)
			{
				mainmenu = true;
				guide = false;
				pause = false;
			}
			break;
		case '3':
			KNIFE = false;
			RPG = true;
			UZI = false;
			knifehit = false;
			break;
		case '2':
			KNIFE = false;
			RPG = false;
			UZI = true;
			knifehit = false;
			break;
		case '1':
			KNIFE = true;
			RPG = false;
			UZI = false;
			knifehit = false;
			break;
		}
	}
}

void SKeyboard(int key, int x, int y)
{
	switch (key)
	{
	case 11:
		if (!fullscr) {
			glutFullScreen();
			fullscr = true;
		}
		else {
			glutReshapeWindow(wid, hei);
			fullscr = false;
		}
		break;
	}
	if (mainmenu == false) {
		switch (key) {
		case GLUT_KEY_UP:
			deltaMove_y = -10.0;
			glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN:
			deltaMove2_y = 10.0;
			glutPostRedisplay();
			break;
		case GLUT_KEY_LEFT:
			LEFT = true;
			RIGHT = false;
			deltaMove_x = -10.0;
			glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT:
			RIGHT = true;
			LEFT = false;
			deltaMove2_x = 10.0;
			glutPostRedisplay();
			break;
		}
	}
}

void releaseKey(int key, int x, int y) 
{
	switch (key) {	
	case GLUT_KEY_UP:frame = 1, deltaMove_y = 0; break;
	case GLUT_KEY_DOWN:frame = 1, deltaMove2_y = 0; break;
	case GLUT_KEY_RIGHT:frame = 1, deltaMove2_x = 0;
		if (deltaMove_x < 0) {
			RIGHT = false;
			LEFT = true;
		}
		break;
	case GLUT_KEY_LEFT:frame = 1, deltaMove_x = 0;
		if (deltaMove2_x > 0) {
			RIGHT = true;
			LEFT = false;
		}
		break;
	}
}

void ReleaseSKey(unsigned char key, int x, int y)
{
	switch (key) {
	case 'W':frame = 1, deltaMove_y = 0; break;
	case 'S':frame = 1, deltaMove2_y = 0; break;
	case 'D':frame = 1, deltaMove2_x = 0;
		if (deltaMove_x < 0) {
			RIGHT = false;
			LEFT = true;
		}
		break;
	case 'A':frame = 1, deltaMove_x = 0;
		if (deltaMove2_x > 0) {
			RIGHT = true;
			LEFT = false;
		}
		break;
	case 'w':frame = 1, deltaMove_y = 0; break;
	case 's':frame = 1, deltaMove2_y = 0; break;
	case 'd':frame = 1, deltaMove2_x = 0; 
		if (deltaMove_x < 0){
			RIGHT = false;
			LEFT = true;
		}
		break;
	case 'a':frame = 1, deltaMove_x = 0; 
		if (deltaMove2_x > 0) {
			RIGHT = true;
			LEFT = false;
		}
		break;
	}
}

void textures() 
{
	unsigned char* image = stbi_load("textures/cat2B.png", &picw, &pich, 0, 4);
	unsigned char* image2 = stbi_load("textures/cat2B(W).png", &picw, &pich, 0, 4);
	unsigned char* imagem = stbi_load("textures/FULL.png", &picw2, &pich2, 0, 4);
	unsigned char* ldscr = stbi_load("textures/LOADSCR.png", &ldscrw, &ldscrh, 0, 4);
	unsigned char* new1 = stbi_load("textures/NEWGAME1.png", &neww, &newh, 0, 4);
	unsigned char* new2 = stbi_load("textures/NEWGAME2.png", &neww, &newh, 0, 4);
	unsigned char* con1 = stbi_load("textures/CONTINUE1.png", &neww, &newh, 0, 4);
	unsigned char* con2 = stbi_load("textures/CONTINUE2.png", &neww, &newh, 0, 4);
	unsigned char* exit1 = stbi_load("textures/EXIT1.png", &neww, &newh, 0, 4);
	unsigned char* exit2 = stbi_load("textures/EXIT2.png", &neww, &newh, 0, 4);
	unsigned char* enemy1 = stbi_load("textures/FULLENEMY.png", &enemyw, &enemyh, 0, 4);
	unsigned char* mainloc = stbi_load("textures/MainLocation.png", &LOADW, &LOADH, 0, 4);
	unsigned char* location1 = stbi_load("textures/location1.png", &ldscrw, &ldscrh, 0, 4);
	unsigned char* knifehit = stbi_load("textures/knifehit.png", &knifew, &knifeh, 0, 4);

		unsigned char* backtom = stbi_load("textures/BACKTOM.png", &bw, &bh, 0, 4);
		unsigned char* conpause = stbi_load("textures/CONTINUE_PAUSE.png", &buttw, &butth, 0, 4);
		unsigned char* desert = stbi_load("textures/DESERT.png", &desertw, &deserth, 0, 4);
		unsigned char* uzi = stbi_load("textures/FULL2.png", &picw2, &pich2, 0, 4);
		unsigned char* rpg = stbi_load("textures/FULL3.png", &picw2, &pich2, 0, 4);
		unsigned char* enemy2 = stbi_load("textures/FULLENEMY2.png", &enemyw, &enemyh, 0, 4);
		unsigned char* enemy3 = stbi_load("textures/FULLENEMY3.png", &fullenemyw, &fullenemyh, 0, 4);
		unsigned char* enemy4 = stbi_load("textures/FULLENEMY4.png", &enemyw, &enemyh, 0, 4);
		unsigned char* guide = stbi_load("textures/GUIDE.png", &ldscrw, &ldscrh, 0, 4);
		unsigned char* location2 = stbi_load("textures/location2.png", &ldscrw, &ldscrh, 0, 4);
		unsigned char* mainpause = stbi_load("textures/MAINMENU_PAUSE.png", &buttw, &butth, 0, 4);
		unsigned char* pause = stbi_load("textures/PAUSE.png", &pausew, &pauseh, 0, 4);
		unsigned char* enemy5 = stbi_load("textures/RANGE.png", &enemyw, &enemyh, 0, 4);
		unsigned char* restartpause = stbi_load("textures/RESTART_PAUSE.png", &buttw, &butth, 0, 4);
		unsigned char* uzist = stbi_load("textures/UZI.png", &picw, &pich, 0, 4);
		unsigned char* rpgst = stbi_load("textures/RPG.png", &picw, &pich, 0, 4);
		unsigned char* udied = stbi_load("textures/YOUDIED.png", &ldscrw, &ldscrh, 0, 4);
		unsigned char* the_end = stbi_load("textures/THE_END.png", &ldscrw, &ldscrh, 0, 4);
		unsigned char* rockett = stbi_load("textures/ROCKET.png", &rocketw, &rocketh, 0, 4);
		unsigned char* bullett = stbi_load("textures/UZIBULLET.png", &bulletw, &bulleth, 0, 4);
		unsigned char* hp0 = stbi_load("textures/0(5).png", &hpw, &hph, 0, 4);
		unsigned char* hp1 = stbi_load("textures/1(5).png", &hpw, &hph, 0, 4);
		unsigned char* hp2 = stbi_load("textures/2(5).png", &hpw, &hph, 0, 4);
		unsigned char* hp3 = stbi_load("textures/3(5).png", &hpw, &hph, 0, 4);
		unsigned char* hp4 = stbi_load("textures/4(5).png", &hpw, &hph, 0, 4);
		unsigned char* hp5 = stbi_load("textures/5(5).png", &hpw, &hph, 0, 4);
		unsigned char* knbar = stbi_load("textures/KNIFEBAR.png", &barw, &barh, 0, 4);
		unsigned char* rpgbar = stbi_load("textures/RPGBAR.png", &barw, &barh, 0, 4);
		unsigned char* uzibar = stbi_load("textures/UZIBAR.png", &barw, &barh, 0, 4);
		unsigned char* wormbullet = stbi_load("textures/worm_bullet.png", &wbullw, &wbullh, 0, 4);

		unsigned char* zero = stbi_load("textures/zero.png", &numw, &numh, 0, 4);
		unsigned char* one = stbi_load("textures/one.png", &numw, &numh, 0, 4);
		unsigned char* two = stbi_load("textures/two.png", &numw, &numh, 0, 4);
		unsigned char* three = stbi_load("textures/three.png", &numw, &numh, 0, 4);
		unsigned char* four = stbi_load("textures/four.png", &numw, &numh, 0, 4);
		unsigned char* five = stbi_load("textures/five.png", &numw, &numh, 0, 4);
		unsigned char* six = stbi_load("textures/six.png", &numw, &numh, 0, 4);
		unsigned char* seven = stbi_load("textures/seven.png", &numw, &numh, 0, 4);
		unsigned char* eight = stbi_load("textures/eight.png", &numw, &numh, 0, 4);
		unsigned char* nine = stbi_load("textures/nine.png", &numw, &numh, 0, 4);
		unsigned char* X = stbi_load("textures/X.png", &Xw, &Xh, 0, 4);
		unsigned char* ens = stbi_load("textures/ENEMIES.png", &ensw, &ensh, 0, 4);

	glGenTextures(56, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, picw, pich, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenTextures(56, &texture[1]);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, picw, pich, 0, GL_RGBA, GL_UNSIGNED_BYTE, image2);
	glGenTextures(56, &texture[2]);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, picw2, pich2, 0, GL_RGBA, GL_UNSIGNED_BYTE, imagem);
	glGenTextures(56, &texture[3]);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ldscrw, ldscrh, 0, GL_RGBA, GL_UNSIGNED_BYTE, ldscr);
	
	glGenTextures(56, &texture[4]);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, neww, newh, 0, GL_RGBA, GL_UNSIGNED_BYTE, new1);
	glGenTextures(56, &texture[5]);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, neww, newh, 0, GL_RGBA, GL_UNSIGNED_BYTE, new2);
	glGenTextures(56, &texture[6]);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, neww, newh, 0, GL_RGBA, GL_UNSIGNED_BYTE, con1);
	glGenTextures(56, &texture[7]);
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, neww, newh, 0, GL_RGBA, GL_UNSIGNED_BYTE, con2);
	glGenTextures(56, &texture[8]);
	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, neww, newh, 0, GL_RGBA, GL_UNSIGNED_BYTE, exit1);
	glGenTextures(56, &texture[9]);
	glBindTexture(GL_TEXTURE_2D, texture[9]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, neww, newh, 0, GL_RGBA, GL_UNSIGNED_BYTE, exit2);
	glGenTextures(56, &texture[10]);
	glBindTexture(GL_TEXTURE_2D, texture[10]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, enemyw, enemyh, 0, GL_RGBA, GL_UNSIGNED_BYTE, enemy1);

	glGenTextures(56, &texture[11]);
	glBindTexture(GL_TEXTURE_2D, texture[11]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, LOADW, LOADH, 0, GL_RGBA, GL_UNSIGNED_BYTE, mainloc);
	glGenTextures(56, &texture[12]);
	glBindTexture(GL_TEXTURE_2D, texture[12]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ldscrw, ldscrh, 0, GL_RGBA, GL_UNSIGNED_BYTE, location1);
	glGenTextures(56, &texture[13]);
	glBindTexture(GL_TEXTURE_2D, texture[13]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, knifew, knifeh, 0, GL_RGBA, GL_UNSIGNED_BYTE, knifehit);
	glGenTextures(56, &texture[14]);
	glBindTexture(GL_TEXTURE_2D, texture[14]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bw, bh, 0, GL_RGBA, GL_UNSIGNED_BYTE, backtom);
	glGenTextures(56, &texture[15]);
	glBindTexture(GL_TEXTURE_2D, texture[15]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, buttw, butth, 0, GL_RGBA, GL_UNSIGNED_BYTE, conpause);
	glGenTextures(56, &texture[16]);
	glBindTexture(GL_TEXTURE_2D, texture[16]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, picw2, pich2, 0, GL_RGBA, GL_UNSIGNED_BYTE, uzi);
	glGenTextures(56, &texture[17]);
	glBindTexture(GL_TEXTURE_2D, texture[17]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, picw2, pich2, 0, GL_RGBA, GL_UNSIGNED_BYTE, rpg);
	glGenTextures(56, &texture[18]);
	glBindTexture(GL_TEXTURE_2D, texture[18]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, enemyw, enemyh, 0, GL_RGBA, GL_UNSIGNED_BYTE, enemy2);
	glGenTextures(56, &texture[19]);
	glBindTexture(GL_TEXTURE_2D, texture[19]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, fullenemyw, fullenemyh, 0, GL_RGBA, GL_UNSIGNED_BYTE, enemy3);
	glGenTextures(56, &texture[20]);
	glBindTexture(GL_TEXTURE_2D, texture[20]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, enemyw, enemyh, 0, GL_RGBA, GL_UNSIGNED_BYTE, enemy4);
	glGenTextures(56, &texture[21]);
	glBindTexture(GL_TEXTURE_2D, texture[21]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ldscrw, ldscrh, 0, GL_RGBA, GL_UNSIGNED_BYTE, guide);
	glGenTextures(56, &texture[22]);
	glBindTexture(GL_TEXTURE_2D, texture[22]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ldscrw, ldscrh, 0, GL_RGBA, GL_UNSIGNED_BYTE, location2);
	glGenTextures(56, &texture[23]);
	glBindTexture(GL_TEXTURE_2D, texture[23]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, buttw, butth, 0, GL_RGBA, GL_UNSIGNED_BYTE, mainpause);
	glGenTextures(56, &texture[24]);
	glBindTexture(GL_TEXTURE_2D, texture[24]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, pausew, pauseh, 0, GL_RGBA, GL_UNSIGNED_BYTE, pause);
	glGenTextures(56, &texture[25]);
	glBindTexture(GL_TEXTURE_2D, texture[25]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, enemyw, enemyh, 0, GL_RGBA, GL_UNSIGNED_BYTE, enemy5);
	glGenTextures(56, &texture[26]);
	glBindTexture(GL_TEXTURE_2D, texture[26]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, buttw, butth, 0, GL_RGBA, GL_UNSIGNED_BYTE, restartpause);
	glGenTextures(56, &texture[27]);
	glBindTexture(GL_TEXTURE_2D, texture[27]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, picw, pich, 0, GL_RGBA, GL_UNSIGNED_BYTE, uzist);
	glGenTextures(56, &texture[28]);
	glBindTexture(GL_TEXTURE_2D, texture[28]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, picw, pich, 0, GL_RGBA, GL_UNSIGNED_BYTE, rpgst);
	glGenTextures(56, &texture[29]);
	glBindTexture(GL_TEXTURE_2D, texture[29]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ldscrw, ldscrh, 0, GL_RGBA, GL_UNSIGNED_BYTE, udied);
	glGenTextures(56, &texture[30]);
	glBindTexture(GL_TEXTURE_2D, texture[30]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, rocketw, rocketh, 0, GL_RGBA, GL_UNSIGNED_BYTE, rockett);
	glGenTextures(56, &texture[31]);
	glBindTexture(GL_TEXTURE_2D, texture[31]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bulletw, bulleth, 0, GL_RGBA, GL_UNSIGNED_BYTE, bullett);
	glGenTextures(56, &texture[32]);
	glBindTexture(GL_TEXTURE_2D, texture[32]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, desertw, deserth, 0, GL_RGBA, GL_UNSIGNED_BYTE, desert);
	glGenTextures(56, &texture[33]);
	glBindTexture(GL_TEXTURE_2D, texture[33]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, hpw, hph, 0, GL_RGBA, GL_UNSIGNED_BYTE, hp0);
	glGenTextures(56, &texture[34]);
	glBindTexture(GL_TEXTURE_2D, texture[34]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, hpw, hph, 0, GL_RGBA, GL_UNSIGNED_BYTE, hp1);
	glGenTextures(56, &texture[35]);
	glBindTexture(GL_TEXTURE_2D, texture[35]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, hpw, hph, 0, GL_RGBA, GL_UNSIGNED_BYTE, hp2);
	glGenTextures(56, &texture[36]);
	glBindTexture(GL_TEXTURE_2D, texture[36]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, hpw, hph, 0, GL_RGBA, GL_UNSIGNED_BYTE, hp3);
	glGenTextures(56, &texture[37]);
	glBindTexture(GL_TEXTURE_2D, texture[37]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, hpw, hph, 0, GL_RGBA, GL_UNSIGNED_BYTE, hp4);
	glGenTextures(56, &texture[38]);
	glBindTexture(GL_TEXTURE_2D, texture[38]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, hpw, hph, 0, GL_RGBA, GL_UNSIGNED_BYTE, hp5);
	glGenTextures(56, &texture[39]);
	glBindTexture(GL_TEXTURE_2D, texture[39]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, barw, barh, 0, GL_RGBA, GL_UNSIGNED_BYTE, knbar);
	glGenTextures(56, &texture[40]);
	glBindTexture(GL_TEXTURE_2D, texture[40]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, barw, barh, 0, GL_RGBA, GL_UNSIGNED_BYTE, rpgbar);
	glGenTextures(56, &texture[41]);
	glBindTexture(GL_TEXTURE_2D, texture[41]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, barw, barh, 0, GL_RGBA, GL_UNSIGNED_BYTE, uzibar);
	glGenTextures(56, &texture[42]);
	glBindTexture(GL_TEXTURE_2D, texture[42]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, wbullw, wbullh, 0, GL_RGBA, GL_UNSIGNED_BYTE, wormbullet);
	glGenTextures(56, &texture[43]);
	glBindTexture(GL_TEXTURE_2D, texture[43]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ldscrw, ldscrh, 0, GL_RGBA, GL_UNSIGNED_BYTE, the_end);
	glGenTextures(56, &texture[44]);
	glBindTexture(GL_TEXTURE_2D, texture[44]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, numw, numh, 0, GL_RGBA, GL_UNSIGNED_BYTE, zero);
	glGenTextures(56, &texture[45]);
	glBindTexture(GL_TEXTURE_2D, texture[45]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, numw, numh, 0, GL_RGBA, GL_UNSIGNED_BYTE, one);
	glGenTextures(56, &texture[46]);
	glBindTexture(GL_TEXTURE_2D, texture[46]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, numw, numh, 0, GL_RGBA, GL_UNSIGNED_BYTE, two);
	glGenTextures(56, &texture[47]);
	glBindTexture(GL_TEXTURE_2D, texture[47]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, numw, numh, 0, GL_RGBA, GL_UNSIGNED_BYTE, three);
	glGenTextures(56, &texture[48]);
	glBindTexture(GL_TEXTURE_2D, texture[48]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, numw, numh, 0, GL_RGBA, GL_UNSIGNED_BYTE, four);
	glGenTextures(56, &texture[49]);
	glBindTexture(GL_TEXTURE_2D, texture[49]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, numw, numh, 0, GL_RGBA, GL_UNSIGNED_BYTE, five);
	glGenTextures(56, &texture[50]);
	glBindTexture(GL_TEXTURE_2D, texture[50]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, numw, numh, 0, GL_RGBA, GL_UNSIGNED_BYTE, six);
	glGenTextures(56, &texture[51]);
	glBindTexture(GL_TEXTURE_2D, texture[51]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, numw, numh, 0, GL_RGBA, GL_UNSIGNED_BYTE, seven);
	glGenTextures(56, &texture[52]);
	glBindTexture(GL_TEXTURE_2D, texture[52]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, numw, numh, 0, GL_RGBA, GL_UNSIGNED_BYTE, eight);
	glGenTextures(56, &texture[53]);
	glBindTexture(GL_TEXTURE_2D, texture[53]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, numw, numh, 0, GL_RGBA, GL_UNSIGNED_BYTE, nine);
	glGenTextures(56, &texture[54]);
	glBindTexture(GL_TEXTURE_2D, texture[54]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Xw, Xh, 0, GL_RGBA, GL_UNSIGNED_BYTE, X);
	glGenTextures(56, &texture[55]);
	glBindTexture(GL_TEXTURE_2D, texture[55]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ensw, ensh, 0, GL_RGBA, GL_UNSIGNED_BYTE, ens);
}

void MainMenu()
{
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(0.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(0, 768);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(1366, 768);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(1366, 0);
	glEnd();
}

void buttons()
{
	if (X >= 1010 && X <= 1266 && Y >= 340 && Y <= 404)
	{
		glBindTexture(GL_TEXTURE_2D, texture[5]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(1010.0, 340.0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(1010.0, 404.0);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(1266.0, 404.0);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(1266.0, 340.0);
		glEnd();
	}
	else {
		glBindTexture(GL_TEXTURE_2D, texture[4]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(1010.0, 340.0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(1010.0, 404.0);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(1266.0, 404.0);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(1266.0, 340.0);
		glEnd();
	}
	if (X >= 1016 && X <= 1272 && Y >= 482 && Y <= 546)	
	{
		glBindTexture(GL_TEXTURE_2D, texture[7]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(1016.0, 482.0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(1016.0, 546.0);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(1272.0, 546.0);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(1272.0, 482.0);
		glEnd();
	}
	else {
		glBindTexture(GL_TEXTURE_2D, texture[6]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(1016.0, 482.0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(1016.0, 546.0);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(1272.0, 546.0);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(1272.0, 482.0);
		glEnd();
	}
	if (X >= 1018 && X <= 1264 && Y >= 620 && Y <= 676) 
	{
		glBindTexture(GL_TEXTURE_2D, texture[9]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(1018.0, 620.0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(1018.0, 676.0);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(1264.0, 676.0);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(1264.0, 620.0);
		glEnd();
	}
	else {
		glBindTexture(GL_TEXTURE_2D, texture[8]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(1018.0, 620.0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(1018.0, 676.0);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(1264.0, 676.0);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(1264.0, 620.0);
		glEnd();
	}
	glutSwapBuffers();
}

void move()
{
	if (RIGHT) {
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glBegin(GL_QUADS);
		if (frame == 1) {
			glTexCoord2f(0.0, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 2) {
			glTexCoord2f(0.2, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 3) {
			glTexCoord2f(0.4, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 4) {
			glTexCoord2f(0.6, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 5) {
			glTexCoord2f(0.8, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 6) {
			glTexCoord2f(0.0, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 7) {
			glTexCoord2f(0.2, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 8) {
			glTexCoord2f(0.4, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 9) {
			glTexCoord2f(0.6, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 10) {
			glTexCoord2f(0.8, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 11) {
			glTexCoord2f(0.0, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 12) {
			glTexCoord2f(0.2, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 13) {
			glTexCoord2f(0.4, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 14) {
			glTexCoord2f(0.6, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 15) {
			glTexCoord2f(0.8, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 16) {
			glTexCoord2f(0.0, 0.75);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 1.0);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 1.0);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.75);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 17) {
			glTexCoord2f(0.2, 0.75);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 1.0);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 1.0);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.75);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		if (frame == 17)
			frame = 1;
		if (pause == true) {}
		else
			frame++;
	}
	if (LEFT) {
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glBegin(GL_QUADS);
		if (frame == 1) {
			glTexCoord2f(0.2, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 2) {
			glTexCoord2f(0.4, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 3) {
			glTexCoord2f(0.6, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 4) {
			glTexCoord2f(0.8, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 5) {
			glTexCoord2f(1.0, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 6) {
			glTexCoord2f(0.2, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 7) {
			glTexCoord2f(0.4, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 8) {
			glTexCoord2f(0.6, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 9) {
			glTexCoord2f(0.8, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 10) {
			glTexCoord2f(1.0, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 11) {
			glTexCoord2f(0.2, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 12) {
			glTexCoord2f(0.4, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 13) {
			glTexCoord2f(0.6, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 14) {
			glTexCoord2f(0.8, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 15) {
			glTexCoord2f(1.0, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 16) {
			glTexCoord2f(0.2, 0.75);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 1.0);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 1.0);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.75);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 17) {
			glTexCoord2f(0.4, 0.75);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 1.0);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 1.0);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.75);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		if (frame == 17)
			frame = 1;
		if (pause == true) {}
		else
			frame++;
	}
}

void enemy1()
{
	if (enemy1hp > 0) {
		glBindTexture(GL_TEXTURE_2D, texture[10]);
		glBegin(GL_QUADS);
		if (enframe == 1 || enframe == 2 || enframe == 3) {
			glTexCoord2f(0.0, 0.0);
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.0, 0.5);
			enemy1_y += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.25, 0.5);
			enemy1_x += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.25, 0.0);
			enemy1_y -= 128;
			glVertex2f(enemy1_x, enemy1_y);
			enemy1_x -= 128;
			glEnd();
		}
		else if (enframe == 4 || enframe == 5 || enframe == 6) {
			glTexCoord2f(0.25, 0.0);
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.25, 0.5);
			enemy1_y += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.5, 0.5);
			enemy1_x += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.5, 0.0);
			enemy1_y -= 128;
			glVertex2f(enemy1_x, enemy1_y);
			enemy1_x -= 128;
			glEnd();
		}
		else if (enframe == 7 || enframe == 8 || enframe == 9) {
			glTexCoord2f(0.5, 0.0);
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.5, 0.5);
			enemy1_y += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.75, 0.5);
			enemy1_x += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.75, 0.0);
			enemy1_y -= 128;
			glVertex2f(enemy1_x, enemy1_y);
			enemy1_x -= 128;
			glEnd();
		}
		else if (enframe == 10 || enframe == 11 || enframe == 12) {
			glTexCoord2f(0.75, 0.0);
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.75, 0.5);
			enemy1_y += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(1.0, 0.5);
			enemy1_x += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(1.0, 0.0);
			enemy1_y -= 128;
			glVertex2f(enemy1_x, enemy1_y);
			enemy1_x -= 128;
			glEnd();
		}
		else if (enframe == 13 || enframe == 14 || enframe == 15) {
			glTexCoord2f(0.0, 0.5);
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.0, 1.0);
			enemy1_y += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.25, 1.0);
			enemy1_x += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.25, 0.5);
			enemy1_y -= 128;
			glVertex2f(enemy1_x, enemy1_y);
			enemy1_x -= 128;
			glEnd();
		}
		else if (enframe == 16 || enframe == 17 || enframe == 18) {
			glTexCoord2f(0.25, 0.5);
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.25, 1.0);
			enemy1_y += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.5, 1.0);
			enemy1_x += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.5, 0.5);
			enemy1_y -= 128;
			glVertex2f(enemy1_x, enemy1_y);
			enemy1_x -= 128;
			glEnd();
		}
		if (enframe == 18)
			enframe = 1;
		if (pause == true) {}
		else
			enframe++;
	}

	if (enemy3hp > 0) {
		glBindTexture(GL_TEXTURE_2D, texture[10]);
		glBegin(GL_QUADS);
		if (enframe3 == 10 || enframe3 == 11 || enframe3 == 12) {
			glTexCoord2f(0.0, 0.0);
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.0, 0.5);
			enemy3_y += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.25, 0.5);
			enemy3_x += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.25, 0.0);
			enemy3_y -= 128;
			glVertex2f(enemy3_x, enemy3_y);
			enemy3_x -= 128;
			glEnd();
		}
		else if (enframe3 == 13 || enframe3 == 14 || enframe3 == 15) {
			glTexCoord2f(0.25, 0.0);
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.25, 0.5);
			enemy3_y += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.5, 0.5);
			enemy3_x += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.5, 0.0);
			enemy3_y -= 128;
			glVertex2f(enemy3_x, enemy3_y);
			enemy3_x -= 128;
			glEnd();
		}
		else if (enframe3 == 16 || enframe3 == 17 || enframe3 == 18) {
			glTexCoord2f(0.5, 0.0);
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.5, 0.5);
			enemy3_y += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.75, 0.5);
			enemy3_x += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.75, 0.0);
			enemy3_y -= 128;
			glVertex2f(enemy3_x, enemy3_y);
			enemy3_x -= 128;
			glEnd();
		}
		else if (enframe3 == 1 || enframe3 == 2 || enframe3 == 3) {
			glTexCoord2f(0.75, 0.0);
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.75, 0.5);
			enemy3_y += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(1.0, 0.5);
			enemy3_x += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(1.0, 0.0);
			enemy3_y -= 128;
			glVertex2f(enemy3_x, enemy3_y);
			enemy3_x -= 128;
			glEnd();
		}
		else if (enframe3 == 4 || enframe3 == 5 || enframe3 == 6) {
			glTexCoord2f(0.0, 0.5);
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.0, 1.0);
			enemy3_y += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.25, 1.0);
			enemy3_x += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.25, 0.5);
			enemy3_y -= 128;
			glVertex2f(enemy3_x, enemy3_y);
			enemy3_x -= 128;
			glEnd();
		}
		else if (enframe3 == 7 || enframe3 == 8 || enframe3 == 9) {
			glTexCoord2f(0.25, 0.5);
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.25, 1.0);
			enemy3_y += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.5, 1.0);
			enemy3_x += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.5, 0.5);
			enemy3_y -= 128;
			glVertex2f(enemy3_x, enemy3_y);
			enemy3_x -= 128;
			glEnd();
		}
		if (enframe3 == 18)
			enframe3 = 1;
		if (pause == true) {}
		else
			enframe3++;
	}
}

void mainlocation() {
	glBindTexture(GL_TEXTURE_2D, texture[11]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(0.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(0, 768);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(1366, 768);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(1366, 0);
	glEnd();
}

void location1() {
	glBindTexture(GL_TEXTURE_2D, texture[12]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(0.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(0, 768);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(1366, 768);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(1366, 0);
	glEnd();
}

void knhit() {
	if (RIGHT) {
		glBindTexture(GL_TEXTURE_2D, texture[13]);
		glBegin(GL_QUADS);
		if (knframe == 1 || knframe == 2) {
			glTexCoord2f(0.0, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.5, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.5, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (knframe == 3 || knframe == 4) {
			glTexCoord2f(0.5, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.5, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (knframe == 5 || knframe == 6) {
			glTexCoord2f(0.0, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 1.0);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.5, 1.0);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.5, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (knframe == 7 || knframe == 8) {
			glTexCoord2f(0.5, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.5, 1.0);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 1.0);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		if (knframe == 8)
		{
			knifehit = false;
			knframe = 1;
		}
	}
	else if (LEFT)
	{
		glBindTexture(GL_TEXTURE_2D, texture[13]);
		glBegin(GL_QUADS);
		if (knframe == 1 || knframe == 2) {
			glTexCoord2f(0.5, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.5, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (knframe == 3 || knframe == 4) {
			glTexCoord2f(1.0, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.5, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.5, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (knframe == 5 || knframe == 6) {
			glTexCoord2f(0.5, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.5, 1.0);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 1.0);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (knframe == 7 || knframe == 8) {
			glTexCoord2f(1.0, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 1.0);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.5, 1.0);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.5, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}

		if (knframe == 8 || !knifehit)
		{
			knifehit = false;
			knframe = 1;
		}
	}
	if (pause == true) {}
	else
		knframe++;
}

void guidescr() 
{
	glBindTexture(GL_TEXTURE_2D, texture[21]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(0.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(0, 768);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(1366, 768);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(1366, 0);
	glEnd();
	if (X >= 1102 && X <= 1337 && Y >= 677 && Y <= 749)
	{
		glBindTexture(GL_TEXTURE_2D, texture[14]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(1102.0, 677.0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(1102.0, 750.0);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(1338.0, 750.0);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(1338.0, 677.0);
		glEnd();
	}
	glutSwapBuffers();
}

void pausescr() 
{
	glBindTexture(GL_TEXTURE_2D, texture[24]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(333.0, 159.0);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(333.0, 609.0);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(1033.0, 609.0);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(1033.0, 159.0);
	glEnd();
	if (X >= 575 && X <= 799 && Y >= 288 && Y <= 369)
	{
		glBindTexture(GL_TEXTURE_2D, texture[15]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(575.0, 288.0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(575.0, 369.0);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(799.0, 369.0);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(799.0, 288.0);
		glEnd();
	}
	if (X >= 575 && X <= 799 && Y >= 385 && Y <= 466)
	{
		glBindTexture(GL_TEXTURE_2D, texture[26]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(575.0, 385.0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(575.0, 466.0);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(799.0, 466.0);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(799.0, 385.0);
		glEnd();
	}
	if (X >= 575 && X <= 799 && Y >= 486 && Y <= 567)
	{
		glBindTexture(GL_TEXTURE_2D, texture[23]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(575.0, 486.0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(575.0, 567.0);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(799.0, 567.0);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(799.0, 486.0);
		glEnd();
	}
}

void location2()
{
	glBindTexture(GL_TEXTURE_2D, texture[32]);
	glBegin(GL_QUADS);
	if (mapframe == 1 || mapframe == 2 || mapframe == 3 || mapframe == 4) {
		glTexCoord2f(0.0, 0.0);
		glVertex2f(0.0, 0.0);
		glTexCoord2f(0.0, 0.5);
		glVertex2f(0, 768);
		glTexCoord2f(0.25, 0.5);
		glVertex2f(1366, 768);
		glTexCoord2f(0.25, 0.0);
		glVertex2f(1366, 0);
		glEnd();
	}
	else if (mapframe == 5 || mapframe == 6 || mapframe == 7 || mapframe == 8) {
		glTexCoord2f(0.25, 0.0);
		glVertex2f(0.0, 0.0);
		glTexCoord2f(0.25, 0.5);
		glVertex2f(0, 768);
		glTexCoord2f(0.5, 0.5);
		glVertex2f(1366, 768);
		glTexCoord2f(0.5, 0.0);
		glVertex2f(1366, 0);
		glEnd();
	}
	else if (mapframe == 9 || mapframe == 10 || mapframe == 11 || mapframe == 12) {
		glTexCoord2f(0.5, 0.0);
		glVertex2f(0.0, 0.0);
		glTexCoord2f(0.5, 0.5);
		glVertex2f(0, 768);
		glTexCoord2f(0.75, 0.5);
		glVertex2f(1366, 768);
		glTexCoord2f(0.75, 0.0);
		glVertex2f(1366, 0);
		glEnd();
	}
	else if (mapframe == 13 || mapframe == 14 || mapframe == 15 || mapframe == 16) {
		glTexCoord2f(0.75, 0.0);
		glVertex2f(0.0, 0.0);
		glTexCoord2f(0.75, 0.5);
		glVertex2f(0, 768);
		glTexCoord2f(1.0, 0.5);
		glVertex2f(1366, 768);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(1366, 0);
		glEnd();
	}
	else if (mapframe == 17 || mapframe == 18 || mapframe == 19 || mapframe == 20) {
		glTexCoord2f(0.0, 0.5);
		glVertex2f(0.0, 0.0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(0, 768);
		glTexCoord2f(0.25, 1.0);
		glVertex2f(1366, 768);
		glTexCoord2f(0.25, 0.5);
		glVertex2f(1366, 0);
		glEnd();
	}
	else if (mapframe == 21 || mapframe == 22 || mapframe == 23 || mapframe == 24) {
		glTexCoord2f(0.25, 0.5);
		glVertex2f(0.0, 0.0);
		glTexCoord2f(0.25, 1.0);
		glVertex2f(0, 768);
		glTexCoord2f(0.5, 1.0);
		glVertex2f(1366, 768);
		glTexCoord2f(0.5, 0.5);
		glVertex2f(1366, 0);
		glEnd();
	}
	else if (mapframe == 25|| mapframe == 26 || mapframe == 27 || mapframe == 28) {
		glTexCoord2f(0.5, 0.5);
		glVertex2f(0.0, 0.0);
		glTexCoord2f(0.5, 1.0);
		glVertex2f(0, 768);
		glTexCoord2f(0.75, 1.0);
		glVertex2f(1366, 768);
		glTexCoord2f(0.75, 0.5);
		glVertex2f(1366, 0);
		glEnd();
	}
	else if (mapframe == 29 || mapframe == 30 || mapframe == 31 || mapframe == 32) {
		glTexCoord2f(0.75, 0.5);
		glVertex2f(0.0, 0.0);
		glTexCoord2f(0.75, 1.0);
		glVertex2f(0, 768);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(1366, 768);
		glTexCoord2f(1.0, 0.5);
		glVertex2f(1366, 0);
		glEnd();
	}
	if (mapframe == 32)
		mapframe = 1;
	if (pause == true) {}
	else
		mapframe++;
}

void location3()
{
	glBindTexture(GL_TEXTURE_2D, texture[22]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(0.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(0, 768);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(1366, 768);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(1366, 0);
	glEnd();
}

void hp0() 
{
	glBindTexture(GL_TEXTURE_2D, texture[33]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(1071.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(1071.0, 65.0);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(1366, 65.0);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(1366, 0);
	glEnd();
}

void hp1() 
{
	glBindTexture(GL_TEXTURE_2D, texture[34]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(1071.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(1071.0, 65.0);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(1366, 65.0);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(1366, 0);
	glEnd();
}

void hp2() 
{
	glBindTexture(GL_TEXTURE_2D, texture[35]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(1071.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(1071.0, 65.0);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(1366, 65.0);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(1366, 0);
	glEnd();
}

void hp3()
{
	glBindTexture(GL_TEXTURE_2D, texture[36]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(1071.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(1071.0, 65.0);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(1366, 65.0);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(1366, 0);
	glEnd();
}

void hp4()
{
	glBindTexture(GL_TEXTURE_2D, texture[37]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(1071.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(1071.0, 65.0);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(1366, 65.0);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(1366, 0);
	glEnd();
}

void hp5() 
{
	glBindTexture(GL_TEXTURE_2D, texture[38]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(1071.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(1071.0, 65.0);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(1366, 65.0);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(1366, 0);
	glEnd();
}

void weapon1()
{
	glBindTexture(GL_TEXTURE_2D, texture[39]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(1007.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(1007.0, 65.0);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(1070, 65.0);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(1070, 0);
	glEnd();
}

void weapon2()
{
	glBindTexture(GL_TEXTURE_2D, texture[41]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(1007.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(1007.0, 65.0);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(1070, 65.0);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(1070, 0);
	glEnd();
}

void weapon3()
{
	glBindTexture(GL_TEXTURE_2D, texture[40]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(1007.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(1007.0, 65.0);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(1070, 65.0);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(1070, 0);
	glEnd();
}

void moveuzi()
{
	if (RIGHT) {
		glBindTexture(GL_TEXTURE_2D, texture[16]);
		glBegin(GL_QUADS);
		if (frame == 1) {
			glTexCoord2f(0.0, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 2) {
			glTexCoord2f(0.2, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 3) {
			glTexCoord2f(0.4, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 4) {
			glTexCoord2f(0.6, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 5) {
			glTexCoord2f(0.8, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 6) {
			glTexCoord2f(0.0, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 7) {
			glTexCoord2f(0.2, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 8) {
			glTexCoord2f(0.4, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 9) {
			glTexCoord2f(0.6, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 10) {
			glTexCoord2f(0.8, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 11) {
			glTexCoord2f(0.0, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 12) {
			glTexCoord2f(0.2, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 13) {
			glTexCoord2f(0.4, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 14) {
			glTexCoord2f(0.6, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 15) {
			glTexCoord2f(0.8, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 16) {
			glTexCoord2f(0.0, 0.75);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 1.0);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 1.0);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.75);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 17) {
			glTexCoord2f(0.2, 0.75);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 1.0);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 1.0);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.75);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		if (frame == 17)
			frame = 1;
		if (pause == true) {}
		else
			frame++;
	}
	if (LEFT) {
		glBindTexture(GL_TEXTURE_2D, texture[16]);
		glBegin(GL_QUADS);
		if (frame == 1) {
			glTexCoord2f(0.2, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 2) {
			glTexCoord2f(0.4, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 3) {
			glTexCoord2f(0.6, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 4) {
			glTexCoord2f(0.8, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 5) {
			glTexCoord2f(1.0, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 6) {
			glTexCoord2f(0.2, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 7) {
			glTexCoord2f(0.4, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 8) {
			glTexCoord2f(0.6, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 9) {
			glTexCoord2f(0.8, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 10) {
			glTexCoord2f(1.0, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 11) {
			glTexCoord2f(0.2, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 12) {
			glTexCoord2f(0.4, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 13) {
			glTexCoord2f(0.6, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 14) {
			glTexCoord2f(0.8, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 15) {
			glTexCoord2f(1.0, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 16) {
			glTexCoord2f(0.2, 0.75);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 1.0);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 1.0);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.75);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 17) {
			glTexCoord2f(0.4, 0.75);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 1.0);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 1.0);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.75);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		if (frame == 17)
			frame = 1;
		if (pause == true) {}
		else
			frame++;
	}
}

void moverpg()
{
	if (RIGHT) {
		glBindTexture(GL_TEXTURE_2D, texture[17]);
		glBegin(GL_QUADS);
		if (frame == 1) {
			glTexCoord2f(0.0, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 2) {
			glTexCoord2f(0.2, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 3) {
			glTexCoord2f(0.4, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 4) {
			glTexCoord2f(0.6, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 5) {
			glTexCoord2f(0.8, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 6) {
			glTexCoord2f(0.0, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 7) {
			glTexCoord2f(0.2, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 8) {
			glTexCoord2f(0.4, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 9) {
			glTexCoord2f(0.6, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 10) {
			glTexCoord2f(0.8, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 11) {
			glTexCoord2f(0.0, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 12) {
			glTexCoord2f(0.2, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 13) {
			glTexCoord2f(0.4, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 14) {
			glTexCoord2f(0.6, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 15) {
			glTexCoord2f(0.8, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 16) {
			glTexCoord2f(0.0, 0.75);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 1.0);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 1.0);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.75);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 17) {
			glTexCoord2f(0.2, 0.75);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 1.0);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 1.0);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.75);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		if (frame == 17)
			frame = 1;
		if (pause == true) {}
		else
			frame++;
	}
	if (LEFT) {
		glBindTexture(GL_TEXTURE_2D, texture[17]);
		glBegin(GL_QUADS);
		if (frame == 1) {
			glTexCoord2f(0.2, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 2) {
			glTexCoord2f(0.4, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 3) {
			glTexCoord2f(0.6, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 4) {
			glTexCoord2f(0.8, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 5) {
			glTexCoord2f(1.0, 0.0);
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.25);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.25);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.0);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 6) {
			glTexCoord2f(0.2, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 7) {
			glTexCoord2f(0.4, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 8) {
			glTexCoord2f(0.6, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 9) {
			glTexCoord2f(0.8, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 10) {
			glTexCoord2f(1.0, 0.25);
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.5);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.5);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.25);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 11) {
			glTexCoord2f(0.2, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 12) {
			glTexCoord2f(0.4, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 13) {
			glTexCoord2f(0.6, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 14) {
			glTexCoord2f(0.8, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.6, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 15) {
			glTexCoord2f(1.0, 0.5);
			glVertex2f(my_x, my_y);
			glTexCoord2f(1.0, 0.75);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.75);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.8, 0.5);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 16) {
			glTexCoord2f(0.2, 0.75);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 1.0);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 1.0);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.0, 0.75);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		else if (frame == 17) {
			glTexCoord2f(0.4, 0.75);
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.4, 1.0);
			my_y += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 1.0);
			my_x += 128;
			glVertex2f(my_x, my_y);
			glTexCoord2f(0.2, 0.75);
			my_y -= 128;
			glVertex2f(my_x, my_y);
			my_x -= 128;
			glEnd();
		}
		if (frame == 17)
			frame = 1;
		if (pause == true) {}
		else
			frame++;
	}
}

void bat()
{
	if (enemy1hp > 0) {
		glBindTexture(GL_TEXTURE_2D, texture[19]);
		glBegin(GL_QUADS);
		if (enframe == 1 || enframe == 2 || enframe == 3) {
			glTexCoord2f(0.0, 0.0);
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.0, 0.5);
			enemy1_y += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.2, 0.5);
			enemy1_x += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.2, 0.0);
			enemy1_y -= 128;
			glVertex2f(enemy1_x, enemy1_y);
			enemy1_x -= 128;
			glEnd();
		}
		else if (enframe == 4 || enframe == 5 || enframe == 6) {
			glTexCoord2f(0.2, 0.0);
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.2, 0.5);
			enemy1_y += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.4, 0.5);
			enemy1_x += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.4, 0.0);
			enemy1_y -= 128;
			glVertex2f(enemy1_x, enemy1_y);
			enemy1_x -= 128;
			glEnd();
		}
		else if (enframe == 7 || enframe == 8 || enframe == 9) {
			glTexCoord2f(0.4, 0.0);
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.4, 0.5);
			enemy1_y += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.6, 0.5);
			enemy1_x += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.6, 0.0);
			enemy1_y -= 128;
			glVertex2f(enemy1_x, enemy1_y);
			enemy1_x -= 128;
			glEnd();
		}
		else if (enframe == 10 || enframe == 11 || enframe == 12) {
			glTexCoord2f(0.6, 0.0);
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.6, 0.5);
			enemy1_y += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.8, 0.5);
			enemy1_x += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.8, 0.0);
			enemy1_y -= 128;
			glVertex2f(enemy1_x, enemy1_y);
			enemy1_x -= 128;
			glEnd();
		}
		else if (enframe == 13 || enframe == 14 || enframe == 15) {
			glTexCoord2f(0.8, 0.0);
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.8, 0.5);
			enemy1_y += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(1.0, 0.5);
			enemy1_x += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(1.0, 0.0);
			enemy1_y -= 128;
			glVertex2f(enemy1_x, enemy1_y);
			enemy1_x -= 128;
			glEnd();
		}
		else if (enframe == 16 || enframe == 17 || enframe == 18) {
			glTexCoord2f(0.0, 0.5);
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.0, 1.0);
			enemy1_y += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.2, 1.0);
			enemy1_x += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.2, 0.5);
			enemy1_y -= 128;
			glVertex2f(enemy1_x, enemy1_y);
			enemy1_x -= 128;
			glEnd();
		}
		else if (enframe == 19 || enframe == 20 || enframe == 21) {
			glTexCoord2f(0.2, 0.5);
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.2, 1.0);
			enemy1_y += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.4, 1.0);
			enemy1_x += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.4, 0.5);
			enemy1_y -= 128;
			glVertex2f(enemy1_x, enemy1_y);
			enemy1_x -= 128;
			glEnd();
		}
		else if (enframe == 22 || enframe == 23 || enframe == 24) {
			glTexCoord2f(0.4, 0.5);
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.4, 1.0);
			enemy1_y += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.6, 1.0);
			enemy1_x += 128;
			glVertex2f(enemy1_x, enemy1_y);
			glTexCoord2f(0.6, 0.5);
			enemy1_y -= 128;
			glVertex2f(enemy1_x, enemy1_y);
			enemy1_x -= 128;
			glEnd();
		}
		if (enframe == 24)
			enframe = 1;
		if (pause == true) {}
		else
			enframe++;
	}
	if (enemy3hp > 0) {
		glBindTexture(GL_TEXTURE_2D, texture[19]);
		glBegin(GL_QUADS);
		if (enframe3 == 13 || enframe3 == 14 || enframe3 == 15) {
			glTexCoord2f(0.0, 0.0);
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.0, 0.5);
			enemy3_y += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.2, 0.5);
			enemy3_x += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.2, 0.0);
			enemy3_y -= 128;
			glVertex2f(enemy3_x, enemy3_y);
			enemy3_x -= 128;
			glEnd();
		}
		else if (enframe3 == 16 || enframe3 == 17 || enframe3 == 18) {
			glTexCoord2f(0.2, 0.0);
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.2, 0.5);
			enemy3_y += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.4, 0.5);
			enemy3_x += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.4, 0.0);
			enemy3_y -= 128;
			glVertex2f(enemy3_x, enemy3_y);
			enemy3_x -= 128;
			glEnd();
		}
		else if (enframe3 == 19 || enframe3 == 20 || enframe3 == 21) {
			glTexCoord2f(0.4, 0.0);
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.4, 0.5);
			enemy3_y += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.6, 0.5);
			enemy3_x += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.6, 0.0);
			enemy3_y -= 128;
			glVertex2f(enemy3_x, enemy3_y);
			enemy3_x -= 128;
			glEnd();
		}
		else if (enframe3 == 22 || enframe3 == 23 || enframe3 == 24) {
			glTexCoord2f(0.6, 0.0);
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.6, 0.5);
			enemy3_y += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.8, 0.5);
			enemy3_x += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.8, 0.0);
			enemy3_y -= 128;
			glVertex2f(enemy3_x, enemy3_y);
			enemy3_x -= 128;
			glEnd();
		}
		else if (enframe3 == 1 || enframe3 == 2 || enframe3 == 3) {
			glTexCoord2f(0.8, 0.0);
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.8, 0.5);
			enemy3_y += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(1.0, 0.5);
			enemy3_x += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(1.0, 0.0);
			enemy3_y -= 128;
			glVertex2f(enemy3_x, enemy3_y);
			enemy3_x -= 128;
			glEnd();
		}
		else if (enframe3 == 4 || enframe3 == 5 || enframe3 == 6) {
			glTexCoord2f(0.0, 0.5);
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.0, 1.0);
			enemy3_y += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.2, 1.0);
			enemy3_x += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.2, 0.5);
			enemy3_y -= 128;
			glVertex2f(enemy3_x, enemy3_y);
			enemy3_x -= 128;
			glEnd();
		}
		else if (enframe3 == 7 || enframe3 == 8 || enframe3 == 9) {
			glTexCoord2f(0.2, 0.5);
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.2, 1.0);
			enemy3_y += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.4, 1.0);
			enemy3_x += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.4, 0.5);
			enemy3_y -= 128;
			glVertex2f(enemy3_x, enemy3_y);
			enemy3_x -= 128;
			glEnd();
		}
		else if (enframe3 == 10 || enframe3 == 11 || enframe3 == 12) {
			glTexCoord2f(0.4, 0.5);
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.4, 1.0);
			enemy3_y += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.6, 1.0);
			enemy3_x += 128;
			glVertex2f(enemy3_x, enemy3_y);
			glTexCoord2f(0.6, 0.5);
			enemy3_y -= 128;
			glVertex2f(enemy3_x, enemy3_y);
			enemy3_x -= 128;
			glEnd();
		}
		if (enframe3 == 24)
			enframe3 = 1;
		if (pause == true) {}
		else
			enframe3++;
	}
}

void worm()
{
	glBindTexture(GL_TEXTURE_2D, texture[25]);
	glBegin(GL_QUADS);
	if (enframe2 >= 1 && enframe2 <= 7) {
		glTexCoord2f(0.0, 0.0);
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.0, 0.5);
		enemy2_y += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.25, 0.5);
		enemy2_x += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.25, 0.0);
		enemy2_y -= 128;
		glVertex2f(enemy2_x, enemy2_y);
		enemy2_x -= 128;
		glEnd();
	}
	else if (enframe2 >= 8 && enframe2 <= 14) {
		glTexCoord2f(0.25, 0.0);
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.25, 0.5);
		enemy2_y += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.5, 0.5);
		enemy2_x += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.5, 0.0);
		enemy2_y -= 128;
		glVertex2f(enemy2_x, enemy2_y);
		enemy2_x -= 128;
		glEnd();
	}
	else if (enframe2 >= 15 && enframe2 <= 21) {
		glTexCoord2f(0.5, 0.0);
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.5, 0.5);
		enemy2_y += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.75, 0.5);
		enemy2_x += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.75, 0.0);
		enemy2_y -= 128;
		glVertex2f(enemy2_x, enemy2_y);
		enemy2_x -= 128;
		glEnd();
	}
	else if (enframe2 >= 22 && enframe2 <= 28) {
		glTexCoord2f(0.75, 0.0);
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.75, 0.5);
		enemy2_y += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(1.0, 0.5);
		enemy2_x += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(1.0, 0.0);
		enemy2_y -= 128;
		glVertex2f(enemy2_x, enemy2_y);
		enemy2_x -= 128;
		glEnd();
	}
	else if (enframe2 >= 29 && enframe2 <= 35) {
		glTexCoord2f(0.0, 0.5);
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.0, 1.0);
		enemy2_y += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.25, 1.0);
		enemy2_x += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.25, 0.5);
		enemy2_y -= 128;
		glVertex2f(enemy2_x, enemy2_y);
		enemy2_x -= 128;
		glEnd();
	}
	else if (enframe2 >= 36 && enframe2 <= 42) {
		glTexCoord2f(0.25, 0.5);
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.25, 1.0);
		enemy2_y += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.5, 1.0);
		enemy2_x += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.5, 0.5);
		enemy2_y -= 128;
		glVertex2f(enemy2_x, enemy2_y);
		enemy2_x -= 128;
		glEnd();
	}
	if (enframe2 == 42)
		enframe2 = 1;
	if (pause == true) {}
	else
		enframe2++;
}

void penguin()
{
	glBindTexture(GL_TEXTURE_2D, texture[20]);
	glBegin(GL_QUADS);
	if (enframe2 == 1 || enframe2 == 2 || enframe2 == 3) {
		glTexCoord2f(0.0, 0.0);
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.0, 0.5);
		enemy2_y += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.25, 0.5);
		enemy2_x += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.25, 0.0);
		enemy2_y -= 128;
		glVertex2f(enemy2_x, enemy2_y);
		enemy2_x -= 128;
		glEnd();
	}
	else if (enframe2 == 4 || enframe2 == 5 || enframe2 == 6) {
		glTexCoord2f(0.25, 0.0);
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.25, 0.5);
		enemy2_y += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.5, 0.5);
		enemy2_x += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.5, 0.0);
		enemy2_y -= 128;
		glVertex2f(enemy2_x, enemy2_y);
		enemy2_x -= 128;
		glEnd();
	}
	else if (enframe2 == 7 || enframe2 == 8 || enframe2 == 9) {
		glTexCoord2f(0.5, 0.0);
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.5, 0.5);
		enemy2_y += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.75, 0.5);
		enemy2_x += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.75, 0.0);
		enemy2_y -= 128;
		glVertex2f(enemy2_x, enemy2_y);
		enemy2_x -= 128;
		glEnd();
	}
	else if (enframe2 == 10 || enframe2 == 11 || enframe2 == 12) {
		glTexCoord2f(0.75, 0.0);
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.75, 0.5);
		enemy2_y += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(1.0, 0.5);
		enemy2_x += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(1.0, 0.0);
		enemy2_y -= 128;
		glVertex2f(enemy2_x, enemy2_y);
		enemy2_x -= 128;
		glEnd();
	}
	else if (enframe2 == 13 || enframe2 == 14 || enframe2 == 15) {
		glTexCoord2f(0.0, 0.5);
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.0, 1.0);
		enemy2_y += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.25, 1.0);
		enemy2_x += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.25, 0.5);
		enemy2_y -= 128;
		glVertex2f(enemy2_x, enemy2_y);
		enemy2_x -= 128;
		glEnd();
	}
	else if (enframe2 == 16 || enframe2 == 17 || enframe2 == 18) {
		glTexCoord2f(0.25, 0.5);
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.25, 1.0);
		enemy2_y += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.5, 1.0);
		enemy2_x += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.5, 0.5);
		enemy2_y -= 128;
		glVertex2f(enemy2_x, enemy2_y);
		enemy2_x -= 128;
		glEnd();
	}
	else if (enframe2 == 19 || enframe2 == 20 || enframe2 == 21) {
		glTexCoord2f(0.5, 0.5);
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.5, 1.0);
		enemy2_y += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.75, 1.0);
		enemy2_x += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.75, 0.5);
		enemy2_y -= 128;
		glVertex2f(enemy2_x, enemy2_y);
		enemy2_x -= 128;
		glEnd();
	}
	else if (enframe2 == 22 || enframe2 == 23 || enframe2 == 24) {
		glTexCoord2f(0.75, 0.5);
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(0.75, 1.0);
		enemy2_y += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(1.0, 1.0);
		enemy2_x += 128;
		glVertex2f(enemy2_x, enemy2_y);
		glTexCoord2f(1.0, 0.5);
		enemy2_y -= 128;
		glVertex2f(enemy2_x, enemy2_y);
		enemy2_x -= 128;
		glEnd();
	}
	if (enframe2 == 24)
		enframe2 = 1;
	if (pause == true) {}
	else
		enframe2++;
}

void ghost()
{
	if (loc2) {
		if (enemy1hp > 0) {
			glBindTexture(GL_TEXTURE_2D, texture[18]);
			glBegin(GL_QUADS);
			if (enframe == 1 || enframe == 2 || enframe == 3) {
				glTexCoord2f(0.0, 0.0);
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.0, 0.5);
				enemy1_y += 128;
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.25, 0.5);
				enemy1_x += 128;
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.25, 0.0);
				enemy1_y -= 128;
				glVertex2f(enemy1_x, enemy1_y);
				enemy1_x -= 128;
				glEnd();
			}
			else if (enframe == 4 || enframe == 5 || enframe == 6) {
				glTexCoord2f(0.25, 0.0);
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.25, 0.5);
				enemy1_y += 128;
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.5, 0.5);
				enemy1_x += 128;
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.5, 0.0);
				enemy1_y -= 128;
				glVertex2f(enemy1_x, enemy1_y);
				enemy1_x -= 128;
				glEnd();
			}
			else if (enframe == 7 || enframe == 8 || enframe == 9) {
				glTexCoord2f(0.5, 0.0);
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.5, 0.5);
				enemy1_y += 128;
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.75, 0.5);
				enemy1_x += 128;
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.75, 0.0);
				enemy1_y -= 128;
				glVertex2f(enemy1_x, enemy1_y);
				enemy1_x -= 128;
				glEnd();
			}
			else if (enframe == 10 || enframe == 11 || enframe == 12) {
				glTexCoord2f(0.75, 0.0);
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.75, 0.5);
				enemy1_y += 128;
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(1.0, 0.5);
				enemy1_x += 128;
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(1.0, 0.0);
				enemy1_y -= 128;
				glVertex2f(enemy1_x, enemy1_y);
				enemy1_x -= 128;
				glEnd();
			}
			else if (enframe == 13 || enframe == 14 || enframe == 15) {
				glTexCoord2f(0.0, 0.5);
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.0, 1.0);
				enemy1_y += 128;
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.25, 1.0);
				enemy1_x += 128;
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.25, 0.5);
				enemy1_y -= 128;
				glVertex2f(enemy1_x, enemy1_y);
				enemy1_x -= 128;
				glEnd();
			}
			else if (enframe == 16 || enframe == 17 || enframe == 18) {
				glTexCoord2f(0.25, 0.5);
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.25, 1.0);
				enemy1_y += 128;
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.5, 1.0);
				enemy1_x += 128;
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.5, 0.5);
				enemy1_y -= 128;
				glVertex2f(enemy1_x, enemy1_y);
				enemy1_x -= 128;
				glEnd();
			}
			else if (enframe == 19 || enframe == 20 || enframe == 21) {
				glTexCoord2f(0.5, 0.5);
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.5, 1.0);
				enemy1_y += 128;
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.75, 1.0);
				enemy1_x += 128;
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.75, 0.5);
				enemy1_y -= 128;
				glVertex2f(enemy1_x, enemy1_y);
				enemy1_x -= 128;
				glEnd();
			}
			else if (enframe == 22 || enframe == 23 || enframe == 24) {
				glTexCoord2f(0.75, 0.5);
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(0.75, 1.0);
				enemy1_y += 128;
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(1.0, 1.0);
				enemy1_x += 128;
				glVertex2f(enemy1_x, enemy1_y);
				glTexCoord2f(1.0, 0.5);
				enemy1_y -= 128;
				glVertex2f(enemy1_x, enemy1_y);
				enemy1_x -= 128;
				glEnd();
			}
			if (enframe == 24)
				enframe = 1;
			if (pause == true) {}
			else
				enframe++;
		}

		if (enemy3hp > 0) {
			glBindTexture(GL_TEXTURE_2D, texture[18]);
			glBegin(GL_QUADS);
			if (enframe3 == 13 || enframe3 == 14 || enframe3 == 15) {
				glTexCoord2f(0.0, 0.0);
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.0, 0.5);
				enemy3_y += 128;
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.25, 0.5);
				enemy3_x += 128;
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.25, 0.0);
				enemy3_y -= 128;
				glVertex2f(enemy3_x, enemy3_y);
				enemy3_x -= 128;
				glEnd();
			}
			else if (enframe3 == 16 || enframe3 == 17 || enframe3 == 18) {
				glTexCoord2f(0.25, 0.0);
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.25, 0.5);
				enemy3_y += 128;
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.5, 0.5);
				enemy3_x += 128;
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.5, 0.0);
				enemy3_y -= 128;
				glVertex2f(enemy3_x, enemy3_y);
				enemy3_x -= 128;
				glEnd();
			}
			else if (enframe3 == 19 || enframe3 == 20 || enframe3 == 21) {
				glTexCoord2f(0.5, 0.0);
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.5, 0.5);
				enemy3_y += 128;
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.75, 0.5);
				enemy3_x += 128;
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.75, 0.0);
				enemy3_y -= 128;
				glVertex2f(enemy3_x, enemy3_y);
				enemy3_x -= 128;
				glEnd();
			}
			else if (enframe3 == 22 || enframe3 == 23 || enframe3 == 24) {
				glTexCoord2f(0.75, 0.0);
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.75, 0.5);
				enemy3_y += 128;
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(1.0, 0.5);
				enemy3_x += 128;
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(1.0, 0.0);
				enemy3_y -= 128;
				glVertex2f(enemy3_x, enemy3_y);
				enemy3_x -= 128;
				glEnd();
			}
			else if (enframe3 == 1 || enframe3 == 2 || enframe3 == 3) {
				glTexCoord2f(0.0, 0.5);
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.0, 1.0);
				enemy3_y += 128;
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.25, 1.0);
				enemy3_x += 128;
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.25, 0.5);
				enemy3_y -= 128;
				glVertex2f(enemy3_x, enemy3_y);
				enemy3_x -= 128;
				glEnd();
			}
			else if (enframe3 == 4 || enframe3 == 5 || enframe3 == 6) {
				glTexCoord2f(0.25, 0.5);
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.25, 1.0);
				enemy3_y += 128;
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.5, 1.0);
				enemy3_x += 128;
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.5, 0.5);
				enemy3_y -= 128;
				glVertex2f(enemy3_x, enemy3_y);
				enemy3_x -= 128;
				glEnd();
			}
			else if (enframe3 == 7 || enframe3 == 8 || enframe3 == 9) {
				glTexCoord2f(0.5, 0.5);
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.5, 1.0);
				enemy3_y += 128;
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.75, 1.0);
				enemy3_x += 128;
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.75, 0.5);
				enemy3_y -= 128;
				glVertex2f(enemy3_x, enemy3_y);
				enemy3_x -= 128;
				glEnd();
			}
			else if (enframe3 == 10 || enframe3 == 11 || enframe3 == 12) {
				glTexCoord2f(0.75, 0.5);
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(0.75, 1.0);
				enemy3_y += 128;
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(1.0, 1.0);
				enemy3_x += 128;
				glVertex2f(enemy3_x, enemy3_y);
				glTexCoord2f(1.0, 0.5);
				enemy3_y -= 128;
				glVertex2f(enemy3_x, enemy3_y);
				enemy3_x -= 128;
				glEnd();
			}
			if (enframe3 == 24)
				enframe3 = 1;
			if (pause == true) {}
			else
				enframe3++;
		}
	}
	else if (loc3) {
		glBindTexture(GL_TEXTURE_2D, texture[18]);
		glBegin(GL_QUADS);
		if (enframe2 == 1 || enframe2 == 2 || enframe2 == 3) {
			glTexCoord2f(0.0, 0.0);
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.0, 0.5);
			enemy2_y += 128;
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.25, 0.5);
			enemy2_x += 128;
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.25, 0.0);
			enemy2_y -= 128;
			glVertex2f(enemy2_x, enemy2_y);
			enemy2_x -= 128;
			glEnd();
		}
		else if (enframe2 == 4 || enframe2 == 5 || enframe2 == 6) {
			glTexCoord2f(0.25, 0.0);
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.25, 0.5);
			enemy2_y += 128;
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.5, 0.5);
			enemy2_x += 128;
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.5, 0.0);
			enemy2_y -= 128;
			glVertex2f(enemy2_x, enemy2_y);
			enemy2_x -= 128;
			glEnd();
		}
		else if (enframe2 == 7 || enframe2 == 8 || enframe2 == 9) {
			glTexCoord2f(0.5, 0.0);
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.5, 0.5);
			enemy2_y += 128;
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.75, 0.5);
			enemy2_x += 128;
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.75, 0.0);
			enemy2_y -= 128;
			glVertex2f(enemy2_x, enemy2_y);
			enemy2_x -= 128;
			glEnd();
		}
		else if (enframe2 == 10 || enframe2 == 11 || enframe2 == 12) {
			glTexCoord2f(0.75, 0.0);
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.75, 0.5);
			enemy2_y += 128;
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(1.0, 0.5);
			enemy2_x += 128;
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(1.0, 0.0);
			enemy2_y -= 128;
			glVertex2f(enemy2_x, enemy2_y);
			enemy2_x -= 128;
			glEnd();
		}
		else if (enframe2 == 13 || enframe2 == 14 || enframe2 == 15) {
			glTexCoord2f(0.0, 0.5);
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.0, 1.0);
			enemy2_y += 128;
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.25, 1.0);
			enemy2_x += 128;
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.25, 0.5);
			enemy2_y -= 128;
			glVertex2f(enemy2_x, enemy2_y);
			enemy2_x -= 128;
			glEnd();
		}
		else if (enframe2 == 16 || enframe2 == 17 || enframe2 == 18) {
			glTexCoord2f(0.25, 0.5);
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.25, 1.0);
			enemy2_y += 128;
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.5, 1.0);
			enemy2_x += 128;
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.5, 0.5);
			enemy2_y -= 128;
			glVertex2f(enemy2_x, enemy2_y);
			enemy2_x -= 128;
			glEnd();
		}
		else if (enframe2 == 19 || enframe2 == 20 || enframe2 == 21) {
			glTexCoord2f(0.5, 0.5);
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.5, 1.0);
			enemy2_y += 128;
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.75, 1.0);
			enemy2_x += 128;
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.75, 0.5);
			enemy2_y -= 128;
			glVertex2f(enemy2_x, enemy2_y);
			enemy2_x -= 128;
			glEnd();
		}
		else if (enframe2 == 22 || enframe2 == 23 || enframe2 == 24) {
			glTexCoord2f(0.75, 0.5);
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(0.75, 1.0);
			enemy2_y += 128;
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(1.0, 1.0);
			enemy2_x += 128;
			glVertex2f(enemy2_x, enemy2_y);
			glTexCoord2f(1.0, 0.5);
			enemy2_y -= 128;
			glVertex2f(enemy2_x, enemy2_y);
			enemy2_x -= 128;
			glEnd();
		}
		if (enframe2 == 24)
			enframe2 = 1;
		if (pause == true) {}
		else
			enframe2++;
	}
}

void deadscr()
{
	glBindTexture(GL_TEXTURE_2D, texture[29]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(0.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(0, 768);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(1366, 768);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(1366, 0);
	glEnd();
	if (X >= 550 && X <= 773 && Y >= 397 && Y <= 477)
	{
		glBindTexture(GL_TEXTURE_2D, texture[26]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(550.0, 397.0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(550.0, 478.0);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(774.0, 478.0);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(774.0, 397.0);
		glEnd();
	}
	if (X >= 550 && X <= 773 && Y >= 571 && Y <= 651)
	{
		glBindTexture(GL_TEXTURE_2D, texture[23]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(550.0, 571.0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(550.0, 652.0);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(774.0, 652.0);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(774.0, 571.0);
		glEnd();
	}
}

void victory()
{
	glBindTexture(GL_TEXTURE_2D, texture[43]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(0.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(0, 768);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(1366, 768);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(1366, 0);
	glEnd();
	if (X >= 550 && X <= 773 && Y >= 571 && Y <= 651)
	{
		glBindTexture(GL_TEXTURE_2D, texture[23]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(550.0, 571.0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(550.0, 652.0);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(774.0, 652.0);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(774.0, 571.0);
		glEnd();
	}
}

void uzibullet() {
	float  g, d, f;
	if (bullframe == 1) {
		bullet_x = my_x + 128, bullet_y = my_y + 83;
		if (X >= my_x + 64 && Y <= my_y + 64) {
			d = X - (my_x + 132);
			f = (my_y + 86) - Y;
			g = sqrt((d*d)+(f*f));
			rghtab = true;
			rghtund = false;
			lftab = false;
			lftund = false;
			z = 5 * (d / g);
			c = 5 * (f / g);
		}
		else if (X >= my_x + 64 && Y >= my_y + 64) {
			d = X - (my_x + 132);
			f = Y - (my_y + 86);
			g = sqrt((d*d) + (f*f));
			rghtund = true;
			rghtab = false;
			lftab = false;
			lftund = false;
			z = 5 * (d / g);
			c = 5 * (f / g);
		}
		else if (X <= my_x + 64 && Y <= my_y + 64) {
			d = (my_x - 5) - X;
			f = (my_y + 86) - Y;
			g = sqrt((d*d) + (f*f));
			lftab = true;
			rghtab = false;
			rghtund = false;
			lftund = false;
			z = 5 * (d / g);
			c = 5 * (f / g);
		}
		else if (X <= my_x + 64 && Y >= my_y + 64) {
			d = (my_x - 5) - X;
			f = Y - (my_y + 86);
			g = sqrt((d*d) + (f*f));
			lftund = true;
			rghtab = false;
			rghtund = false;
			lftab = false;
			z = 5 * (d / g);
			c = 5 * (f / g);
		};
	}
	glBindTexture(GL_TEXTURE_2D, texture[31]);
	if (rghtab) {
		glBegin(GL_QUADS);
		if (bullframe == 1) {
			UZIbulls--;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 2 || bullframe == 3 || bullframe == 4 || bullframe == 5 || bullframe == 6 ) {
			bullet_x += (bullframe - 1.5) * z;
			bullet_y -= (bullframe - 1.5) * c;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 7 || bullframe == 8 || bullframe == 9 || bullframe == 10 || bullframe == 11 ) {
			bullet_x += (bullframe - 1.5) * z;
			bullet_y -= (bullframe - 1.5) * c;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 12 || bullframe == 13 || bullframe == 14 || bullframe == 15 || bullframe == 16) {
			bullet_x += (bullframe - 1.5) * z;
			bullet_y -= (bullframe - 1.5) * c;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 17 || bullframe == 18 || bullframe == 19 || bullframe == 20 || bullframe == 21) {
			bullet_x += (bullframe - 1.5) * z;
			bullet_y -= (bullframe - 1.5) * c;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 22 || bullframe == 23 || bullframe == 24 || bullframe == 25 || bullframe == 26) {
			bullet_x += (bullframe - 1.5) * z;
			bullet_y -= (bullframe - 1.5) * c;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}

		if (bullframe == 26) {
			bullet = false;
			bullframe = 0;
		}
	}
	else if (rghtund) {
		glBegin(GL_QUADS);
		if (bullframe == 1) {
			UZIbulls--;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 2 || bullframe == 3 || bullframe == 4 || bullframe == 5 || bullframe == 6) {
			bullet_x += (bullframe - 1.5) * z;
			bullet_y += (bullframe - 1.5) * c;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 7 || bullframe == 8 || bullframe == 9 || bullframe == 10 || bullframe == 11) {
			bullet_x += (bullframe - 1.5) * z;
			bullet_y += (bullframe - 1.5) * c;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 12 || bullframe == 13 || bullframe == 14 || bullframe == 15 || bullframe == 16) {
			bullet_x += (bullframe - 1.5) * z;
			bullet_y += (bullframe - 1.5) * c;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 17 || bullframe == 18 || bullframe == 19 || bullframe == 20 || bullframe == 21) {
			bullet_x += (bullframe - 1.5) * z;
			bullet_y += (bullframe - 1.5) * c;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 22 || bullframe == 23 || bullframe == 24 || bullframe == 25 || bullframe == 26) {
			bullet_x += (bullframe - 1.5) * z;
			bullet_y += (bullframe - 1.5) * c;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}

		if (bullframe == 26) {
			bullet = false;
			bullframe = 0;
		}
	}
	else if (lftab)
	{
		glBegin(GL_QUADS);
		if (bullframe == 1) {
			UZIbulls--;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 2 || bullframe == 3 || bullframe == 4 || bullframe == 5 || bullframe == 6) {
			bullet_x -= (bullframe - 1.5) *  z;
			bullet_y -= (bullframe - 1.5) *  c;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 7 || bullframe == 8 || bullframe == 9 || bullframe == 10 || bullframe == 11) {
			bullet_x -= (bullframe - 1.5) * z;
			bullet_y -= (bullframe - 1.5) * c;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 12 || bullframe == 13 || bullframe == 14 || bullframe == 15 || bullframe == 16) {
			bullet_x -= (bullframe - 1.5) * z;
			bullet_y -= (bullframe - 1.5) * c;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 17 || bullframe == 18 || bullframe == 19 || bullframe == 20 || bullframe == 21) {
			bullet_x -= (bullframe - 1.5) * z;
			bullet_y -= (bullframe - 1.5) * c;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 22 || bullframe == 23 || bullframe == 24 || bullframe == 25 || bullframe == 26) {
			bullet_x -= (bullframe - 1.5) * z;
			bullet_y -= (bullframe - 1.5) * c;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}

		if (bullframe == 26) {
			bullet = false;
			bullframe = 0;
		}
	}
	else if (lftund)
	{
		glBegin(GL_QUADS);
		if (bullframe == 1) {
			UZIbulls--;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 2 || bullframe == 3 || bullframe == 4 || bullframe == 5 || bullframe == 6) {
			bullet_x -= (bullframe - 1.5) * z;
			bullet_y += (bullframe - 1.5) * c;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 7 || bullframe == 8 || bullframe == 9 || bullframe == 10 || bullframe == 11) {
			bullet_x -= (bullframe - 1.5) * z;
			bullet_y += (bullframe - 1.5) * c;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 12 || bullframe == 13 || bullframe == 14 || bullframe == 15 || bullframe == 16) {
			bullet_x -= (bullframe - 1.5) * z;
			bullet_y += (bullframe - 1.5) * c;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 17 || bullframe == 18 || bullframe == 19 || bullframe == 20 || bullframe == 21) {
			bullet_x -= (bullframe - 1.5) * z;
			bullet_y += (bullframe - 1.5) * c;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}
		else if (bullframe == 22 || bullframe == 23 || bullframe == 24 || bullframe == 25 || bullframe == 26) {
			bullet_x -= (bullframe - 1.5) * z;
			bullet_y += (bullframe - 1.5) * c;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(1.0, 1.0);
			bullet_y += 3;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 1.0);
			bullet_x += 5;
			glVertex2f(bullet_x, bullet_y);
			glTexCoord2f(0.0, 0.0);
			bullet_y -= 3;
			glVertex2f(bullet_x, bullet_y);
			bullet_x -= 5;
			glEnd();
		}

		if (bullframe == 26) {
			bullet = false;
			bullframe = 0;
		}
	}
	if (bullet_x <= 65 || bullet_x >= 1301 || bullet_y <= 65 || bullet_y >= 703) {
		bullet = false;
		bullframe = 0;
	}
	if (pause == true) {}
	else
		bullframe++;
}

void rpgrocket() {
	float  g, d, f;
	if (rockframe == 1) {
		rocket_x = my_x + 128, rocket_y = my_y + 83;
		if (X >= my_x + 64 && Y <= my_y + 64) {
			d = X - (my_x + 128);
			f = (my_y + 86) - Y;
			g = sqrt((d*d) + (f*f));
			rghtab2 = true;
			rghtund2 = false;
			lftab2 = false;
			lftund2 = false;
			n = 5 * (d / g);
			m = 5 * (f / g);
		}
		else if (X >= my_x + 64 && Y >= my_y + 64) {
			d = X - (my_x + 128);
			f = Y - (my_y + 86);
			g = sqrt((d*d) + (f*f));
			rghtund2 = true;
			rghtab2 = false;
			lftab2 = false;
			lftund2 = false;
			n = 5 * (d / g);
			m = 5 * (f / g);
		}
		else if (X <= my_x + 64 && Y <= my_y + 64) {
			d = (my_x - 25) - X;
			f = (my_y + 86) - Y;
			g = sqrt((d*d) + (f*f));
			lftab2 = true;
			rghtab2 = false;
			rghtund2 = false;
			lftund2 = false;
			n = 5 * (d / g);
			m = 5 * (f / g);
		}
		else if (X <= my_x + 64 && Y >= my_y + 64) {
			d = (my_x - 25) - X;
			f = Y - (my_y + 86);
			g = sqrt((d*d) + (f*f));
			lftund2 = true;
			rghtab2 = false;
			rghtund2 = false;
			lftab2 = false;
			n = 5 * (d / g);
			m = 5 * (f / g);
		};
	}
	glBindTexture(GL_TEXTURE_2D, texture[30]);
	if (rghtab2) {
		glBegin(GL_QUADS);
		if (rockframe == 1) {
			RPGrocks--;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 2 || rockframe == 3 || rockframe == 4 || rockframe == 5 || rockframe == 6) {
			rocket_x += (rockframe - 1) * n;
			rocket_y -= (rockframe - 1) * m;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 7 || rockframe == 8 || rockframe == 9 || rockframe == 10 || rockframe == 11) {
			rocket_x += (rockframe - 1) * n;
			rocket_y -= (rockframe - 1) * m;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 12 || rockframe == 13 || rockframe == 14 || rockframe == 15 || rockframe == 16) {
			rocket_x += (rockframe - 1) * n;
			rocket_y -= (rockframe - 1) * m;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 17 || rockframe == 18 || rockframe == 19 || rockframe == 20 || rockframe == 21) {
			rocket_x += (rockframe - 1) * n;
			rocket_y -= (rockframe - 1) * m;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 22 || rockframe == 23 || rockframe == 24 || rockframe == 25 || rockframe == 26) {
			rocket_x += (rockframe - 1) * n;
			rocket_y -= (rockframe - 1) * m;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}

		if (rockframe == 26) {
			rocket = false;
			rockframe = 0;
		}
	}
	else if (rghtund2)
	{
		glBegin(GL_QUADS);
		if (rockframe == 1) {
			RPGrocks--;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 2 || rockframe == 3 || rockframe == 4 || rockframe == 5 || rockframe == 6) {
			rocket_x += (rockframe - 1) * n;
			rocket_y += (rockframe - 1) * m;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 7 || rockframe == 8 || rockframe == 9 || rockframe == 10 || rockframe == 11) {
			rocket_x += (rockframe - 1) * n;
			rocket_y += (rockframe - 1) * m;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 12 || rockframe == 13 || rockframe == 14 || rockframe == 15 || rockframe == 16) {
			rocket_x += (rockframe - 1) * n;
			rocket_y += (rockframe - 1) * m;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 17 || rockframe == 18 || rockframe == 19 || rockframe == 20 || rockframe == 21) {
			rocket_x += (rockframe - 1) * n;
			rocket_y += (rockframe - 1) * m;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 22 || rockframe == 23 || rockframe == 24 || rockframe == 25 || rockframe == 26) {
			rocket_x += (rockframe - 1) * n;
			rocket_y += (rockframe - 1) * m;
			glTexCoord2f(0.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}

		if (rockframe == 26) {
			rocket = false;
			rockframe = 0;
		}
	}
	else if (lftab2)
	{
		glBegin(GL_QUADS);
		if (rockframe == 1) {
			RPGrocks--;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 2 || rockframe == 3 || rockframe == 4 || rockframe == 5 || rockframe == 6) {
			rocket_x -= (rockframe - 1) * n;
			rocket_y -= (rockframe - 1) * m;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 7 || rockframe == 8 || rockframe == 9 || rockframe == 10 || rockframe == 11) {
			rocket_x -= (rockframe - 1) * n;
			rocket_y -= (rockframe - 1) * m;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 12 || rockframe == 13 || rockframe == 14 || rockframe == 15 || rockframe == 16) {
			rocket_x -= (rockframe - 1) * n;
			rocket_y -= (rockframe - 1) * m;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 17 || rockframe == 18 || rockframe == 19 || rockframe == 20 || rockframe == 21) {
			rocket_x -= (rockframe - 1) * n;
			rocket_y -= (rockframe - 1) * m;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 22 || rockframe == 23 || rockframe == 24 || rockframe == 25 || rockframe == 26) {
			rocket_x -= (rockframe - 1) * n;
			rocket_y -= (rockframe - 1) * m;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}

		if (rockframe == 26) {
			rocket = false;
			rockframe = 0;
		}
	}
	else if (lftund2)
	{
		glBegin(GL_QUADS);
		if (rockframe == 1) {
			RPGrocks--;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 2 || rockframe == 3 || rockframe == 4 || rockframe == 5 || rockframe == 6) {
			rocket_x -= (rockframe - 1) * n;
			rocket_y += (rockframe - 1) * m;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 7 || rockframe == 8 || rockframe == 9 || rockframe == 10 || rockframe == 11) {
			rocket_x -= (rockframe - 1) * n;
			rocket_y += (rockframe - 1) * m;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 12 || rockframe == 13 || rockframe == 14 || rockframe == 15 || rockframe == 16) {
			rocket_x -= (rockframe - 1) * n;
			rocket_y += (rockframe - 1) * m;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 17 || rockframe == 18 || rockframe == 19 || rockframe == 20 || rockframe == 21) {
			rocket_x -= (rockframe - 1) * n;
			rocket_y += (rockframe - 1) * m;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}
		else if (rockframe == 22 || rockframe == 23 || rockframe == 24 || rockframe == 25 || rockframe == 26) {
			rocket_x -= (rockframe - 1) * n;
			rocket_y += (rockframe - 1) * m;
			glTexCoord2f(1.0, 0.0);
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(1.0, 1.0);
			rocket_y += 9;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 1.0);
			rocket_x += 25;
			glVertex2f(rocket_x, rocket_y);
			glTexCoord2f(0.0, 0.0);
			rocket_y -= 9;
			glVertex2f(rocket_x, rocket_y);
			rocket_x -= 25;
			glEnd();
		}

		if (rockframe == 26) {
			rocket = false;
			rockframe = 0;
		}
	}
	if (rocket_x <= 65 || rocket_x >= 1301 || rocket_y <= 65 || rocket_y >= 703) {
		enemy1hp -= 3;
		enemy2hp -= 3;
		enemy3hp -= 3;
		rocket = false;
		rockframe = 0;
	}
	if (pause == true) {}
	else
		rockframe++;
}

void wormbullet() {
	glBindTexture(GL_TEXTURE_2D, texture[42]);
	if (enframe2 == 25) {
		wormbull_x = enemy2_x + 1, wormbull_y = enemy2_y + 37;

	}
	if (wormbull_x <= 65 || wormbull_x >= 1361 || wormbull_y <= 65 || wormbull_y >= 703) {
		wormbull = false;
	}
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(wormbull_x, wormbull_y);
	glTexCoord2f(0.0, 1.0);
	wormbull_y += 5;
	glVertex2f(wormbull_x, wormbull_y);
	glTexCoord2f(1.0, 1.0);
	wormbull_x += 7;
	glVertex2f(wormbull_x, wormbull_y);
	glTexCoord2f(1.0, 0.0);
	wormbull_y -= 5;
	glVertex2f(wormbull_x, wormbull_y);
	wormbull_x -= 7;
	glEnd();
	if (enframe2 == 25) {
		a = (enemy2_x - my_x + 128) / 42;
		if (enemy2_y > my_y) {
			b = (enemy2_y - my_y + 64) / 42;
			above = true;
			under = false;
		}
		else {
			b = (my_y + 64 - enemy2_y) / 42;
			under = true; 
			above = false;
		}
	}
}

void numbersandenemies() {
	int z = UZIbulls / 10;
	int c = UZIbulls % 10;
	int all = strongens + enemies;
	int v = all / 10;
	int b = all % 10;

	glBindTexture(GL_TEXTURE_2D, texture[55]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(0, 0);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(0, 65);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(140, 65);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(140, 0);
	glEnd();

	if (!KNIFE) {
		glBindTexture(GL_TEXTURE_2D, texture[54]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(911, 32);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(911, 65);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(940, 65);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(940, 32);
		glEnd();
	}

	if (v == 2) {
		glBindTexture(GL_TEXTURE_2D, texture[46]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(140, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(140, 65);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(174, 65);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(174, 0);
		glEnd();
	}
	else if (v == 1) {
		glBindTexture(GL_TEXTURE_2D, texture[45]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(140, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(140, 65);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(174, 65);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(174, 0);
		glEnd();
	}
	else if (v == 0) {
		glBindTexture(GL_TEXTURE_2D, texture[44]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(140, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(140, 65);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(174, 65);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(174, 0);
		glEnd();
	}

	if (b == 0) {
		glBindTexture(GL_TEXTURE_2D, texture[44]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(174, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(174, 65);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(208, 65);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(208, 0);
		glEnd();
	}
	else if (b == 1) {
		glBindTexture(GL_TEXTURE_2D, texture[45]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(174, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(174, 65);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(208, 65);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(208, 0);
		glEnd();
	}
	else if (b == 2) {
		glBindTexture(GL_TEXTURE_2D, texture[46]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(174, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(174, 65);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(208, 65);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(208, 0);
		glEnd();
	}
	else if (b == 3) {
		glBindTexture(GL_TEXTURE_2D, texture[47]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(174, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(174, 65);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(208, 65);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(208, 0);
		glEnd();
	}
	else if (b == 4) {
		glBindTexture(GL_TEXTURE_2D, texture[48]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(174, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(174, 65);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(208, 65);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(208, 0);
		glEnd();
	}
	else if (b == 5) {
		glBindTexture(GL_TEXTURE_2D, texture[49]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(174, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(174, 65);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(208, 65);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(208, 0);
		glEnd();
	}
	else if (b == 6) {
		glBindTexture(GL_TEXTURE_2D, texture[50]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(174, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(174, 65);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(208, 65);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(208, 0);
		glEnd();
	}
	else if (b == 7) {
		glBindTexture(GL_TEXTURE_2D, texture[51]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(174, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(174, 65);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(208, 65);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(208, 0);
		glEnd();
	}
	else if (b == 8) {
		glBindTexture(GL_TEXTURE_2D, texture[52]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(174, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(174, 65);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(208, 65);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(208, 0);
		glEnd();
	}
	else if (b == 9) {
		glBindTexture(GL_TEXTURE_2D, texture[53]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(174, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(174, 65);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(208, 65);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(208, 0);
		glEnd();
	}
	
	if (UZI) {
		if (z == 0) {
			glBindTexture(GL_TEXTURE_2D, texture[44]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(940, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(940, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(974, 0);
			glEnd();
		}
		else if (z == 1) {
			glBindTexture(GL_TEXTURE_2D, texture[45]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(940, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(940, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(974, 0);
			glEnd();
		}
		else if (z == 2) {
			glBindTexture(GL_TEXTURE_2D, texture[46]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(940, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(940, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(974, 0);
			glEnd();
		}
		else if (z == 3) {
			glBindTexture(GL_TEXTURE_2D, texture[47]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(940, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(940, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(974, 0);
			glEnd();
		}

		if (c == 0) {
			glBindTexture(GL_TEXTURE_2D, texture[44]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(974, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(1008, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(1008, 0);
			glEnd();
		}
		else if (c == 1) {
			glBindTexture(GL_TEXTURE_2D, texture[45]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(974, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(1008, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(1008, 0);
			glEnd();
		}
		else if (c == 2) {
			glBindTexture(GL_TEXTURE_2D, texture[46]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(974, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(1008, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(1008, 0);
			glEnd();
		}
		else if (c == 3) {
			glBindTexture(GL_TEXTURE_2D, texture[47]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(974, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(1008, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(1008, 0);
			glEnd();
		}
		else if (c == 4) {
			glBindTexture(GL_TEXTURE_2D, texture[48]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(974, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(1008, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(1008, 0);
			glEnd();
		}
		else if (c == 5) {
			glBindTexture(GL_TEXTURE_2D, texture[49]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(974, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(1008, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(1008, 0);
			glEnd();
		}
		else if (c == 6) {
			glBindTexture(GL_TEXTURE_2D, texture[50]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(974, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(1008, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(1008, 0);
			glEnd();
		}
		else if (c == 7) {
			glBindTexture(GL_TEXTURE_2D, texture[51]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(974, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(1008, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(1008, 0);
			glEnd();
		}
		else if (c == 8) {
			glBindTexture(GL_TEXTURE_2D, texture[52]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(974, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(1008, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(1008, 0);
			glEnd();
		}
		else if (c == 9) {
			glBindTexture(GL_TEXTURE_2D, texture[53]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(974, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(1008, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(1008, 0);
			glEnd();
		}
	}
	if (RPG) {
		glBindTexture(GL_TEXTURE_2D, texture[44]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(940, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(940, 65);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(974, 65);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(974, 0);
		glEnd();
		if (RPGrocks <= 0) {
			glBindTexture(GL_TEXTURE_2D, texture[44]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(974, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(1008, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(1008, 0);
			glEnd();
		}
		else if (RPGrocks == 1) {
			glBindTexture(GL_TEXTURE_2D, texture[45]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(974, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(1008, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(1008, 0);
			glEnd();
		}
		else if (RPGrocks == 2) {
			glBindTexture(GL_TEXTURE_2D, texture[46]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(974, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(1008, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(1008, 0);
			glEnd();
		}
		else if (RPGrocks == 3) {
			glBindTexture(GL_TEXTURE_2D, texture[47]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(974, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(1008, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(1008, 0);
			glEnd();
		}
		else if (RPGrocks == 4) {
			glBindTexture(GL_TEXTURE_2D, texture[48]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(974, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(1008, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(1008, 0);
			glEnd();
		}
		else if (RPGrocks == 5) {
			glBindTexture(GL_TEXTURE_2D, texture[49]);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(974, 0);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(974, 65);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(1008, 65);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(1008, 0);
			glEnd();
		}
	}
}