#include <windows.h>
#include <gl/Gl.h>
#include <gl/glut.h>
#include <math.h>
#include <iostream>
#define _USE_MATH_DEFINES

// Nama kelompok 5
//Augie Sebastian 672018304
//Lathania Domi 672018294
//KerenHapuk Siwtiory(672018193)
//Patrick Najoan 672016131
//Soni Raweyai 672018349

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot = 0.f;
float yrot = 0.f;
float xdiff = 0.f;
float ydiff = 0.f;
bool mouseDown = false;
int is_depth;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 50);
    glutCreateWindow("TR CANDI DIENG KELOMPOK 5");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);

    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutReshapeFunc(ukuran);
    glutDisplayFunc(tampil);
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0, 0.8, 1, 0);
    glMatrixMode(GL_PROJECTION);
    //glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(3);
    glLineWidth(3);
}

void tampil(void)
{
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    gluLookAt(0, 0, 3, 0, 0, 0, 0, 1, 0);
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);


    //dasar 2
    glBegin(GL_POLYGON);
    glColor3ub(233, 150, 122);
    glVertex3f(-250, 0, 400);
    glVertex3f(250, 0, 400);
    glVertex3f(250, 0, -450);
    glVertex3f(-250, 0, -450);
    glEnd();

    //candi1
    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-190, 0.15, 200);
    glVertex3f(-50, 0.15, 200);
    glVertex3f(-50, 0.15, 350);
    glVertex3f(-190, 0.15, 350);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-190, 5, 200);
    glVertex3f(-50, 5, 200);
    glVertex3f(-50, 5, 350);
    glVertex3f(-190, 5, 350);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-190, 0, 200);
    glVertex3f(-50, 0, 200);
    glVertex3f(-50, 5, 200);
    glVertex3f(-190, 5, 200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-190, 0, 350);
    glVertex3f(-50, 0, 350);
    glVertex3f(-50, 5, 350);
    glVertex3f(-190, 5, 350);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-190, 0, 350);
    glVertex3f(-190, 0, 200);
    glVertex3f(-190, 5, 200);
    glVertex3f(-190, 5, 350);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-50, 0, 200);
    glVertex3f(-50, 0, 350);
    glVertex3f(-50, 5, 350);
    glVertex3f(-50, 5, 200);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-180, 5, 210);
    glVertex3f(-60, 5, 210);
    glVertex3f(-60, 15, 210);
    glVertex3f(-180, 15, 210);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-180, 5, 340);
    glVertex3f(-60, 5, 340);
    glVertex3f(-60, 15, 340);
    glVertex3f(-180, 15, 340);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-180, 5, 340);
    glVertex3f(-180, 5, 210);
    glVertex3f(-180, 15, 210);
    glVertex3f(-180, 15, 340);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-60, 5, 210);
    glVertex3f(-60, 5, 340);
    glVertex3f(-60, 15, 340);
    glVertex3f(-60, 15, 210);
    glEnd();
    //1
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-180, 15, 210);
    glVertex3f(-60, 15, 210);
    glVertex3f(-60, 18, 205);
    glVertex3f(-180, 18, 205);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-180, 15, 340);
    glVertex3f(-60, 15, 340);
    glVertex3f(-60, 18, 345);
    glVertex3f(-180, 18, 345);
    glEnd();
    //segitiga pojok1
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-180, 15, 210);
    glVertex3f(-185, 18, 210);
    glVertex3f(-180, 18, 205);
    glVertex3f(-180, 15, 205);
    glEnd();
    //segitiga pojok2
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-60, 15, 210);
    glVertex3f(-55, 18, 210);
    glVertex3f(-60, 18, 205);
    glVertex3f(-60, 15, 205);
    glEnd();
    //segitiga pojok3
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-180, 15, 340);
    glVertex3f(-185, 18, 340);
    glVertex3f(-180, 18, 345);
    glVertex3f(-180, 15, 345);
    glEnd();
    //segitiga pojok4
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-60, 15, 340);
    glVertex3f(-55, 18, 340);
    glVertex3f(-60, 18, 345);
    glVertex3f(-60, 15, 345);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-180, 15, 210);
    glVertex3f(-180, 15, 340);
    glVertex3f(-185, 18, 340);
    glVertex3f(-185, 18, 210);
    glEnd();
    //4
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60, 15, 340);
    glVertex3f(-60, 15, 210);
    glVertex3f(-55, 18, 210);
    glVertex3f(-55, 18, 340);
    glEnd();
    //5
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60, 18, 205);
    glVertex3f(-180, 18, 205);
    glVertex3f(-180, 21, 210);
    glVertex3f(-60, 21, 210);
    glEnd();
    //6
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60, 18, 345);
    glVertex3f(-180, 18, 345);
    glVertex3f(-180, 21, 340);
    glVertex3f(-60, 21, 340);
    glEnd();
    //segitiga pojok1
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-185, 18, 210);
    glVertex3f(-180, 21, 210);
    glVertex3f(-180, 18, 205);
    glVertex3f(-185, 21, 205);
    glEnd();
    //segitiga pojok2
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-185, 18, 340);
    glVertex3f(-180, 21, 340);
    glVertex3f(-180, 18, 345);
    glVertex3f(-185, 21, 345);
    glEnd();
    //segitiga pojok3
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-55, 18, 210);
    glVertex3f(-60, 21, 210);
    glVertex3f(-60, 18, 205);
    glVertex3f(-55, 21, 205);
    glEnd();
    //segitiga pojok4
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-55, 18, 340);
    glVertex3f(-60, 21, 340);
    glVertex3f(-60, 18, 345);
    glVertex3f(-55, 21, 345);
    glEnd();
    //7
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-185, 18, 340);
    glVertex3f(-185, 18, 210);
    glVertex3f(-180, 21, 210);
    glVertex3f(-180, 21, 340);
    glEnd();
    //8
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-55, 18, 210);
    glVertex3f(-55, 18, 340);
    glVertex3f(-60, 21, 340);
    glVertex3f(-60, 21, 210);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-180, 21, 210);
    glVertex3f(-60, 21, 210);
    glVertex3f(-60, 21, 340);
    glVertex3f(-180, 21, 340);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-175, 90, 215);
    glVertex3f(-65, 90, 215);
    glVertex3f(-65, 90, 335);
    glVertex3f(-175, 90, 335);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-175, 21, 215);
    glVertex3f(-65, 21, 215);
    glVertex3f(-65, 90, 215);
    glVertex3f(-175, 90, 215);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-175, 21, 335);
    glVertex3f(-65, 21, 335);
    glVertex3f(-65, 90, 335);
    glVertex3f(-175, 90, 335);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-175, 21, 335);
    glVertex3f(-175, 21, 215);
    glVertex3f(-175, 90, 215);
    glVertex3f(-175, 90, 335);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-65, 21, 215);
    glVertex3f(-65, 21, 335);
    glVertex3f(-65, 90, 335);
    glVertex3f(-65, 90, 215);
    glEnd();
    //1
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 90, 215);
    glVertex3f(-65, 90, 215);
    glVertex3f(-65, 93, 210);
    glVertex3f(-175, 93, 210);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 90, 335);
    glVertex3f(-65, 90, 335);
    glVertex3f(-65, 93, 340);
    glVertex3f(-175, 93, 340);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 90, 215);
    glVertex3f(-175, 90, 335);
    glVertex3f(-180, 93, 335);
    glVertex3f(-180, 93, 215);
    glEnd();
    //4
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-65, 90, 335);
    glVertex3f(-65, 90, 215);
    glVertex3f(-60, 93, 215);
    glVertex3f(-60, 93, 335);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 93, 210);
    glVertex3f(-65, 93, 210);
    glVertex3f(-65, 96, 215);
    glVertex3f(-175, 96, 215);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 93, 340);
    glVertex3f(-65, 93, 340);
    glVertex3f(-65, 96, 335);
    glVertex3f(-175, 96, 335);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-180, 93, 335);
    glVertex3f(-180, 93, 215);
    glVertex3f(-175, 96, 215);
    glVertex3f(-175, 96, 335);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60, 93, 215);
    glVertex3f(-60, 93, 335);
    glVertex3f(-65, 96, 335);
    glVertex3f(-65, 96, 215);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-170, 96, 220);
    glVertex3f(-70, 96, 220);
    glVertex3f(-70, 96, 330);
    glVertex3f(-170, 96, 330);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-170, 96, 220);
    glVertex3f(-70, 96, 220);
    glVertex3f(-70, 100, 220);
    glVertex3f(-170, 100, 220);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-170, 96, 330);
    glVertex3f(-70, 96, 330);
    glVertex3f(-70, 100, 330);
    glVertex3f(-170, 100, 330);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-170, 96, 330);
    glVertex3f(-170, 96, 220);
    glVertex3f(-170, 100, 220);
    glVertex3f(-170, 100, 330);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-70, 96, 220);
    glVertex3f(-70, 96, 330);
    glVertex3f(-70, 100, 330);
    glVertex3f(-70, 100, 220);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-170, 100, 220);
    glVertex3f(-70, 100, 220);
    glVertex3f(-70, 100, 330);
    glVertex3f(-170, 100, 330);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-170, 100, 220);
    glVertex3f(-70, 100, 220);
    glVertex3f(-80, 110, 230);
    glVertex3f(-160, 110, 230);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-170, 100, 330);
    glVertex3f(-70, 100, 330);
    glVertex3f(-80, 110, 320);
    glVertex3f(-160, 110, 320);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-170, 100, 330);
    glVertex3f(-170, 100, 220);
    glVertex3f(-160, 110, 230);
    glVertex3f(-160, 110, 320);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-70, 100, 330);
    glVertex3f(-70, 100, 220);
    glVertex3f(-80, 110, 230);
    glVertex3f(-80, 110, 320);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-160, 110, 230);
    glVertex3f(-80, 110, 230);
    glVertex3f(-80, 110, 320);
    glVertex3f(-160, 110, 320);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-155, 110, 235);
    glVertex3f(-85, 110, 235);
    glVertex3f(-85, 130, 235);
    glVertex3f(-155, 130, 235);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-155, 110, 315);
    glVertex3f(-85, 110, 315);
    glVertex3f(-85, 130, 315);
    glVertex3f(-155, 130, 315);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-155, 110, 315);
    glVertex3f(-155, 110, 235);
    glVertex3f(-155, 130, 235);
    glVertex3f(-155, 130, 315);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-85, 110, 235);
    glVertex3f(-85, 110, 315);
    glVertex3f(-85, 130, 315);
    glVertex3f(-85, 130, 235);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-155, 130, 235);
    glVertex3f(-85, 130, 235);
    glVertex3f(-85, 130, 315);
    glVertex3f(-155, 130, 315);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-150, 140, 240);
    glVertex3f(-90, 140, 240);
    glVertex3f(-90, 140, 310);
    glVertex3f(-150, 140, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-150, 130, 240);
    glVertex3f(-90, 130, 240);
    glVertex3f(-90, 140, 240);
    glVertex3f(-150, 140, 240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-150, 130, 310);
    glVertex3f(-90, 130, 310);
    glVertex3f(-90, 140, 310);
    glVertex3f(-150, 140, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-150, 130, 310);
    glVertex3f(-150, 130, 240);
    glVertex3f(-150, 140, 240);
    glVertex3f(-150, 140, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-90, 130, 240);
    glVertex3f(-90, 130, 310);
    glVertex3f(-90, 140, 310);
    glVertex3f(-90, 140, 240);
    glEnd();

    //CANDI RUSAK SEPARO
    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(10, 0.15, 200);
    glVertex3f(150, 0.15, 200);
    glVertex3f(150, 0.15, 350);
    glVertex3f(10, 0.15, 350);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(10, 5, 200);
    glVertex3f(150, 5, 200);
    glVertex3f(150, 5, 350);
    glVertex3f(10, 5, 350);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(150, 0, 200);
    glVertex3f(10, 0, 200);
    glVertex3f(10, 5, 200);
    glVertex3f(150, 5, 200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(150, 0, 350);
    glVertex3f(10, 0, 350);
    glVertex3f(10, 5, 350);
    glVertex3f(150, 5, 350);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(150, 0, 350);
    glVertex3f(150, 0, 200);
    glVertex3f(150, 5, 200);
    glVertex3f(150, 5, 350);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(10, 0, 200);
    glVertex3f(10, 0, 350);
    glVertex3f(10, 5, 350);
    glVertex3f(10, 5, 200);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(140, 5, 210);
    glVertex3f(20, 5, 210);
    glVertex3f(20, 15, 210);
    glVertex3f(140, 15, 210);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(140, 5, 340);
    glVertex3f(20, 5, 340);
    glVertex3f(20, 15, 340);
    glVertex3f(140, 15, 340);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(140, 5, 340);
    glVertex3f(140, 5, 210);
    glVertex3f(140, 15, 210);
    glVertex3f(140, 15, 340);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(20, 5, 210);
    glVertex3f(20, 5, 340);
    glVertex3f(20, 15, 340);
    glVertex3f(20, 15, 210);
    glEnd();
    //1
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(140, 15, 210);
    glVertex3f(20, 15, 210);
    glVertex3f(20, 18, 205);
    glVertex3f(140, 18, 205);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(140, 15, 340);
    glVertex3f(20, 15, 340);
    glVertex3f(20, 18, 345);
    glVertex3f(140, 18, 345);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(140, 15, 210);
    glVertex3f(140, 15, 340);
    glVertex3f(145, 18, 340);
    glVertex3f(145, 18, 210);
    glEnd();
    //4
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(20, 15, 340);
    glVertex3f(20, 15, 210);
    glVertex3f(15, 18, 210);
    glVertex3f(15, 18, 340);
    glEnd();
    //5
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(20, 18, 205);
    glVertex3f(140, 18, 205);
    glVertex3f(140, 21, 210);
    glVertex3f(20, 21, 210);
    glEnd();
    //6
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(20, 18, 345);
    glVertex3f(140, 18, 345);
    glVertex3f(140, 21, 340);
    glVertex3f(20, 21, 340);
    glEnd();
    //7
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(145, 18, 340);
    glVertex3f(145, 18, 210);
    glVertex3f(140, 21, 210);
    glVertex3f(140, 21, 340);
    glEnd();
    //8
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(15, 18, 210);
    glVertex3f(15, 18, 340);
    glVertex3f(20, 21, 340);
    glVertex3f(20, 21, 210);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(140, 21, 210);
    glVertex3f(20, 21, 210);
    glVertex3f(20, 21, 340);
    glVertex3f(140, 21, 340);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(145, 90, 215);
    glVertex3f(25, 90, 215);
    glVertex3f(25, 90, 335);
    glVertex3f(145, 90, 335);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(145, 21, 215);
    glVertex3f(25, 21, 215);
    glVertex3f(25, 90, 215);
    glVertex3f(145, 90, 215);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(145, 21, 335);
    glVertex3f(25, 21, 335);
    glVertex3f(25, 90, 335);
    glVertex3f(145, 90, 335);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(145, 21, 335);
    glVertex3f(145, 21, 215);
    glVertex3f(145, 90, 215);
    glVertex3f(145, 90, 335);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(25, 21, 215);
    glVertex3f(25, 21, 335);
    glVertex3f(25, 90, 335);
    glVertex3f(25, 90, 215);
    glEnd();
    //1
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(145, 90, 215);
    glVertex3f(25, 90, 215);
    glVertex3f(25, 93, 210);
    glVertex3f(145, 93, 210);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(145, 90, 335);
    glVertex3f(25, 90, 335);
    glVertex3f(25, 93, 340);
    glVertex3f(145, 93, 340);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(145, 90, 215);
    glVertex3f(145, 90, 335);
    glVertex3f(150, 93, 335);
    glVertex3f(150, 93, 215);
    glEnd();
    //4
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(25, 90, 335);
    glVertex3f(25, 90, 215);
    glVertex3f(20, 93, 215);
    glVertex3f(20, 93, 335);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(145, 93, 210);
    glVertex3f(25, 93, 210);
    glVertex3f(25, 96, 215);
    glVertex3f(145, 96, 215);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(145, 93, 340);
    glVertex3f(25, 93, 340);
    glVertex3f(25, 96, 335);
    glVertex3f(145, 96, 335);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(150, 93, 335);
    glVertex3f(150, 93, 215);
    glVertex3f(145, 96, 215);
    glVertex3f(145, 96, 335);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(20, 93, 215);
    glVertex3f(20, 93, 335);
    glVertex3f(25, 96, 335);
    glVertex3f(25, 96, 215);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(130, 96, 220);
    glVertex3f(30, 96, 220);
    glVertex3f(30, 96, 330);
    glVertex3f(130, 96, 330);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(130, 96, 220);
    glVertex3f(30, 96, 220);
    glVertex3f(30, 100, 220);
    glVertex3f(130, 100, 220);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(130, 96, 330);
    glVertex3f(30, 96, 330);
    glVertex3f(30, 100, 330);
    glVertex3f(130, 100, 330);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(130, 96, 330);
    glVertex3f(130, 96, 220);
    glVertex3f(130, 100, 220);
    glVertex3f(130, 100, 330);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(30, 96, 220);
    glVertex3f(30, 96, 330);
    glVertex3f(30, 100, 330);
    glVertex3f(30, 100, 220);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(130, 100, 220);
    glVertex3f(30, 100, 220);
    glVertex3f(30, 100, 330);
    glVertex3f(130, 100, 330);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(130, 100, 220);
    glVertex3f(30, 100, 220);
    glVertex3f(40, 110, 230);
    glVertex3f(120, 110, 230);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(130, 100, 330);
    glVertex3f(30, 100, 330);
    glVertex3f(40, 110, 320);
    glVertex3f(120, 110, 320);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(130, 100, 330);
    glVertex3f(130, 100, 220);
    glVertex3f(120, 110, 230);
    glVertex3f(120, 110, 320);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(30, 100, 330);
    glVertex3f(30, 100, 220);
    glVertex3f(40, 110, 230);
    glVertex3f(40, 110, 320);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(120, 110, 230);
    glVertex3f(40, 110, 230);
    glVertex3f(40, 110, 320);
    glVertex3f(120, 110, 320);
    glEnd();

    //3candi jejer(bagian belakang utuh)
    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-190, 0.15, -100);
    glVertex3f(-50, 0.15, -100);
    glVertex3f(-50, 0.15, -250);
    glVertex3f(-190, 0.15, -250);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-190, 5, -100);
    glVertex3f(-50, 5, -100);
    glVertex3f(-50, 5, -250);
    glVertex3f(-190, 5, -250);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-190, 0, -100);
    glVertex3f(-50, 0, -100);
    glVertex3f(-50, 5, -100);
    glVertex3f(-190, 5, -100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-190, 0, -250);
    glVertex3f(-50, 0, -250);
    glVertex3f(-50, 5, -250);
    glVertex3f(-190, 5, -250);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-190, 0, -250);
    glVertex3f(-190, 0, -100);
    glVertex3f(-190, 5, -100);
    glVertex3f(-190, 5, -250);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-50, 0, -100);
    glVertex3f(-50, 0, -250);
    glVertex3f(-50, 5, -250);
    glVertex3f(-50, 5, -100);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-180, 5, -110);
    glVertex3f(-60, 5, -110);
    glVertex3f(-60, 15, -110);
    glVertex3f(-180, 15, -110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-180, 5, -240);
    glVertex3f(-60, 5, -240);
    glVertex3f(-60, 15, -240);
    glVertex3f(-180, 15, -240);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-180, 5, -240);
    glVertex3f(-180, 5, -110);
    glVertex3f(-180, 15, -110);
    glVertex3f(-180, 15, -240);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-60, 5, -110);
    glVertex3f(-60, 5, -240);
    glVertex3f(-60, 15, -240);
    glVertex3f(-60, 15, -110);
    glEnd();
    //1
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-180, 15, -110);
    glVertex3f(-60, 15, -110);
    glVertex3f(-60, 18, -105);
    glVertex3f(-180, 18, -105);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-180, 15, -240);
    glVertex3f(-60, 15, -240);
    glVertex3f(-60, 18, -245);
    glVertex3f(-180, 18, -245);
    glEnd();
    //segitiga pojok1
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-180, 15, -110);
    glVertex3f(-185, 18, -110);
    glVertex3f(-180, 18, -105);
    glVertex3f(-180, 15, -105);
    glEnd();
    //segitiga pojok2
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-60, 15, -110);
    glVertex3f(-55, 18, -110);
    glVertex3f(-60, 18, -105);
    glVertex3f(-60, 15, -105);
    glEnd();
    //segitiga pojok3
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-180, 15, -240);
    glVertex3f(-185, 18, -240);
    glVertex3f(-180, 18, -245);
    glVertex3f(-180, 15, -245);
    glEnd();
    //segitiga pojok4
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-60, 15, -240);
    glVertex3f(-55, 18, -240);
    glVertex3f(-60, 18, -245);
    glVertex3f(-60, 15, -245);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-180, 15, -110);
    glVertex3f(-180, 15, -240);
    glVertex3f(-185, 18, -240);
    glVertex3f(-185, 18, -110);
    glEnd();
    //4
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60, 15, -240);
    glVertex3f(-60, 15, -110);
    glVertex3f(-55, 18, -110);
    glVertex3f(-55, 18, -240);
    glEnd();
    //5
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60, 18, -105);
    glVertex3f(-180, 18, -105);
    glVertex3f(-180, 21, -110);
    glVertex3f(-60, 21, -110);
    glEnd();
    //6
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60, 18, -245);
    glVertex3f(-180, 18, -245);
    glVertex3f(-180, 21, -240);
    glVertex3f(-60, 21, -240);
    glEnd();
    //segitiga pojok1
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-185, 18, -110);
    glVertex3f(-180, 21, -110);
    glVertex3f(-180, 18, -105);
    glVertex3f(-185, 21, -105);
    glEnd();
    //segitiga pojok2
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-185, 18, -240);
    glVertex3f(-180, 21, -240);
    glVertex3f(-180, 18, -245);
    glVertex3f(-185, 21, -245);
    glEnd();
    //segitiga pojok3
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-55, 18, -110);
    glVertex3f(-60, 21, -110);
    glVertex3f(-60, 18, -105);
    glVertex3f(-55, 21, -105);
    glEnd();
    //segitiga pojok4
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-55, 18, -240);
    glVertex3f(-60, 21, -240);
    glVertex3f(-60, 18, -245);
    glVertex3f(-55, 21, -245);
    glEnd();
    //7
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-185, 18, -240);
    glVertex3f(-185, 18, -110);
    glVertex3f(-180, 21, -110);
    glVertex3f(-180, 21, -240);
    glEnd();
    //8
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-55, 18, -110);
    glVertex3f(-55, 18, -240);
    glVertex3f(-60, 21, -240);
    glVertex3f(-60, 21, -110);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-180, 21, -110);
    glVertex3f(-60, 21, -110);
    glVertex3f(-60, 21, -240);
    glVertex3f(-180, 21, -240);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-175, 90, -115);
    glVertex3f(-65, 90, -115);
    glVertex3f(-65, 90, -235);
    glVertex3f(-175, 90, -235);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-175, 21, -115);
    glVertex3f(-65, 21, -115);
    glVertex3f(-65, 90, -115);
    glVertex3f(-175, 90, -115);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-175, 21, -235);
    glVertex3f(-65, 21, -235);
    glVertex3f(-65, 90, -235);
    glVertex3f(-175, 90, -235);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-175, 21, -235);
    glVertex3f(-175, 21, -115);
    glVertex3f(-175, 90, -115);
    glVertex3f(-175, 90, -235);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-65, 21, -115);
    glVertex3f(-65, 21, -235);
    glVertex3f(-65, 90, -235);
    glVertex3f(-65, 90, -115);
    glEnd();
    //1
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 90, -115);
    glVertex3f(-65, 90, -115);
    glVertex3f(-65, 93, -110);
    glVertex3f(-175, 93, -110);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 90, -235);
    glVertex3f(-65, 90, -235);
    glVertex3f(-65, 93, -240);
    glVertex3f(-175, 93, -240);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 90, -115);
    glVertex3f(-175, 90, -235);
    glVertex3f(-180, 93, -235);
    glVertex3f(-180, 93, -115);
    glEnd();
    //4
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-65, 90, -235);
    glVertex3f(-65, 90, -115);
    glVertex3f(-60, 93, -115);
    glVertex3f(-60, 93, -235);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 93, -110);
    glVertex3f(-65, 93, -110);
    glVertex3f(-65, 96, -115);
    glVertex3f(-175, 96, -115);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 93, -240);
    glVertex3f(-65, 93, -240);
    glVertex3f(-65, 96, -235);
    glVertex3f(-175, 96, -235);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-180, 93, -235);
    glVertex3f(-180, 93, -115);
    glVertex3f(-175, 96, -115);
    glVertex3f(-175, 96, -235);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60, 93, -115);
    glVertex3f(-60, 93, -235);
    glVertex3f(-65, 96, -235);
    glVertex3f(-65, 96, -115);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-170, 96, -120);
    glVertex3f(-70, 96, -120);
    glVertex3f(-70, 96, -230);
    glVertex3f(-170, 96, -230);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-170, 96, -120);
    glVertex3f(-70, 96, -120);
    glVertex3f(-70, 100, -120);
    glVertex3f(-170, 100, -120);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-170, 96, -230);
    glVertex3f(-70, 96, -230);
    glVertex3f(-70, 100, -230);
    glVertex3f(-170, 100, -230);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-170, 96, -230);
    glVertex3f(-170, 96, -120);
    glVertex3f(-170, 100, -120);
    glVertex3f(-170, 100, -230);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-70, 96, -120);
    glVertex3f(-70, 96, -230);
    glVertex3f(-70, 100, -230);
    glVertex3f(-70, 100, -120);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-170, 100, -120);
    glVertex3f(-70, 100, -120);
    glVertex3f(-70, 100, -230);
    glVertex3f(-170, 100, -230);
    glEnd();

    glBegin(GL_QUADS); //tidak dipakai
    glColor3ub(244, 164, 96);
    glVertex3f(-170, 100, -120);
    glVertex3f(-70, 100, -120);
    glVertex3f(-80, 110, -130);
    glVertex3f(-160, 110, -130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-170, 100, -230);
    glVertex3f(-70, 100, -230);
    glVertex3f(-80, 110, -220);
    glVertex3f(-160, 110, -220);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-170, 100, -230);
    glVertex3f(-170, 100, -120);
    glVertex3f(-160, 110, -130);
    glVertex3f(-160, 110, -220);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-70, 100, -230);
    glVertex3f(-70, 100, -120);
    glVertex3f(-80, 110, -130);
    glVertex3f(-80, 110, -220);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-160, 110, -130);
    glVertex3f(-80, 110, -130);
    glVertex3f(-80, 110, -220);
    glVertex3f(-160, 110, -220);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-155, 110, -135);
    glVertex3f(-85, 110, -135);
    glVertex3f(-85, 130, -135);
    glVertex3f(-155, 130, -135);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-155, 110, -215);
    glVertex3f(-85, 110, -215);
    glVertex3f(-85, 130, -215);
    glVertex3f(-155, 130, -215);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-155, 110, -215);
    glVertex3f(-155, 110, -135);
    glVertex3f(-155, 130, -135);
    glVertex3f(-155, 130, -215);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-85, 110, -135);
    glVertex3f(-85, 110, -215);
    glVertex3f(-85, 130, -215);
    glVertex3f(-85, 130, -135);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-155, 130, -135);
    glVertex3f(-85, 130, -135);
    glVertex3f(-85, 130, -215);
    glVertex3f(-155, 130, -215);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-150, 140, -140);
    glVertex3f(-90, 140, -140);
    glVertex3f(-90, 140, -210);
    glVertex3f(-150, 140, -210);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-150, 130, -140);
    glVertex3f(-90, 130, -140);
    glVertex3f(-90, 140, -140);
    glVertex3f(-150, 140, -140);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-150, 130, -210);
    glVertex3f(-90, 130, -210);
    glVertex3f(-90, 140, -210);
    glVertex3f(-150, 140, -210);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-150, 130, -210);
    glVertex3f(-150, 130, -140);
    glVertex3f(-150, 140, -140);
    glVertex3f(-150, 140, -210);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-90, 130, -140);
    glVertex3f(-90, 130, -210);
    glVertex3f(-90, 140, -210);
    glVertex3f(-90, 140, -140);
    glEnd(); //tidak dipakai

    //candi jejer 3 tengah utuh
    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-190, 0.15, -300);
    glVertex3f(-50, 0.15, -300);
    glVertex3f(-50, 0.15, -450);
    glVertex3f(-190, 0.15, -450);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-190, 5, -300);
    glVertex3f(-50, 5, -300);
    glVertex3f(-50, 5, -450);
    glVertex3f(-190, 5, -450);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-190, 0, -300);
    glVertex3f(-50, 0, -300);
    glVertex3f(-50, 5, -300);
    glVertex3f(-190, 5, -300);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-190, 0, -450);
    glVertex3f(-50, 0, -450);
    glVertex3f(-50, 5, -450);
    glVertex3f(-190, 5, -450);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-190, 0, -450);
    glVertex3f(-190, 0, -300);
    glVertex3f(-190, 5, -300);
    glVertex3f(-190, 5, -450);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-50, 0, -300);
    glVertex3f(-50, 0, -450);
    glVertex3f(-50, 5, -450);
    glVertex3f(-50, 5, -300);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-180, 5, -310);
    glVertex3f(-60, 5, -310);
    glVertex3f(-60, 15, -310);
    glVertex3f(-180, 15, -310);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-180, 5, -440);
    glVertex3f(-60, 5, -440);
    glVertex3f(-60, 15, -440);
    glVertex3f(-180, 15, -440);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-180, 5, -440);
    glVertex3f(-180, 5, -310);
    glVertex3f(-180, 15, -310);
    glVertex3f(-180, 15, -440);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-60, 5, -310);
    glVertex3f(-60, 5, -440);
    glVertex3f(-60, 15, -440);
    glVertex3f(-60, 15, -310);
    glEnd();
    //1
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-180, 15, -310);
    glVertex3f(-60, 15, -310);
    glVertex3f(-60, 18, -405);
    glVertex3f(-180, 18, -405);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-180, 15, -440);
    glVertex3f(-60, 15, -440);
    glVertex3f(-60, 18, -445);
    glVertex3f(-180, 18, -445);
    glEnd();
    //segitiga pojok1
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-180, 15, -310);
    glVertex3f(-185, 18, -310);
    glVertex3f(-180, 18, -305);
    glVertex3f(-180, 15, -305);
    glEnd();
    //segitiga pojok2
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-60, 15, -310);
    glVertex3f(-55, 18, -310);
    glVertex3f(-60, 18, -305);
    glVertex3f(-60, 15, -305);
    glEnd();
    //segitiga pojok3
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-180, 15, -440);
    glVertex3f(-185, 18, -440);
    glVertex3f(-180, 18, -445);
    glVertex3f(-180, 15, -445);
    glEnd();
    //segitiga pojok4
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-60, 15, -440);
    glVertex3f(-55, 18, -440);
    glVertex3f(-60, 18, -445);
    glVertex3f(-60, 15, -445);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-180, 15, -310);
    glVertex3f(-180, 15, -440);
    glVertex3f(-185, 18, -440);
    glVertex3f(-185, 18, -310);
    glEnd();
    //4
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60, 15, -440);
    glVertex3f(-60, 15, -310);
    glVertex3f(-55, 18, -310);
    glVertex3f(-55, 18, -440);
    glEnd();
    //5
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60, 18, -305);
    glVertex3f(-180, 18, -305);
    glVertex3f(-180, 21, -310);
    glVertex3f(-60, 21, -310);
    glEnd();
    //6
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60, 18, -445);
    glVertex3f(-180, 18, -445);
    glVertex3f(-180, 21, -440);
    glVertex3f(-60, 21, -440);
    glEnd();
    //segitiga pojok1
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-185, 18, -310);
    glVertex3f(-180, 21, -310);
    glVertex3f(-180, 18, -305);
    glVertex3f(-185, 21, -305);
    glEnd();
    //segitiga pojok2
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-185, 18, -440);
    glVertex3f(-180, 21, -440);
    glVertex3f(-180, 18, -445);
    glVertex3f(-185, 21, -445);
    glEnd();
    //segitiga pojok3
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-55, 18, -310);
    glVertex3f(-60, 21, -310);
    glVertex3f(-60, 18, -305);
    glVertex3f(-55, 21, -305);
    glEnd();
    //segitiga pojok4
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-55, 18, -440);
    glVertex3f(-60, 21, -440);
    glVertex3f(-60, 18, -445);
    glVertex3f(-55, 21, -445);
    glEnd();
    //7
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-185, 18, -440);
    glVertex3f(-185, 18, -310);
    glVertex3f(-180, 21, -310);
    glVertex3f(-180, 21, -440);
    glEnd();
    //8
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-55, 18, -310);
    glVertex3f(-55, 18, -440);
    glVertex3f(-60, 21, -440);
    glVertex3f(-60, 21, -310);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-180, 21, -310);
    glVertex3f(-60, 21, -310);
    glVertex3f(-60, 21, -440);
    glVertex3f(-180, 21, -440);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-175, 90, -315);
    glVertex3f(-65, 90, -315);
    glVertex3f(-65, 90, -435);
    glVertex3f(-175, 90, -435);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-175, 21, -315);
    glVertex3f(-65, 21, -315);
    glVertex3f(-65, 90, -315);
    glVertex3f(-175, 90, -315);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-175, 21, -435);
    glVertex3f(-65, 21, -435);
    glVertex3f(-65, 90, -435);
    glVertex3f(-175, 90, -435);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-175, 21, -435);
    glVertex3f(-175, 21, -315);
    glVertex3f(-175, 90, -315);
    glVertex3f(-175, 90, -435);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-65, 21, -315);
    glVertex3f(-65, 21, -435);
    glVertex3f(-65, 90, -435);
    glVertex3f(-65, 90, -315);
    glEnd();
    //1
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 90, -315);
    glVertex3f(-65, 90, -315);
    glVertex3f(-65, 93, -310);
    glVertex3f(-175, 93, -310);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 90, -435);
    glVertex3f(-65, 90, -435);
    glVertex3f(-65, 93, -440);
    glVertex3f(-175, 93, -440);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 90, -315);
    glVertex3f(-175, 90, -435);
    glVertex3f(-180, 93, -435);
    glVertex3f(-180, 93, -315);
    glEnd();
    //4
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-65, 90, -435);
    glVertex3f(-65, 90, -315);
    glVertex3f(-60, 93, -315);
    glVertex3f(-60, 93, -435);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 93, -310);
    glVertex3f(-65, 93, -310);
    glVertex3f(-65, 96, -315);
    glVertex3f(-175, 96, -315);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 93, -440);
    glVertex3f(-65, 93, -440);
    glVertex3f(-65, 96, -435);
    glVertex3f(-175, 96, -435);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-180, 93, -435);
    glVertex3f(-180, 93, -315);
    glVertex3f(-175, 96, -315);
    glVertex3f(-175, 96, -435);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60, 93, -315);
    glVertex3f(-60, 93, -435);
    glVertex3f(-65, 96, -435);
    glVertex3f(-65, 96, -315);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-170, 96, -320);
    glVertex3f(-70, 96, -320);
    glVertex3f(-70, 96, -430);
    glVertex3f(-170, 96, -430);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-170, 96, -320);
    glVertex3f(-70, 96, -320);
    glVertex3f(-70, 100, -320);
    glVertex3f(-170, 100, -320);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-170, 96, -430);
    glVertex3f(-70, 96, -430);
    glVertex3f(-70, 100, -430);
    glVertex3f(-170, 100, -430);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-170, 96, -430);
    glVertex3f(-170, 96, -320);
    glVertex3f(-170, 100, -320);
    glVertex3f(-170, 100, -430);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-70, 96, -320);
    glVertex3f(-70, 96, -430);
    glVertex3f(-70, 100, -430);
    glVertex3f(-70, 100, -320);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-170, 100, -320);
    glVertex3f(-70, 100, -320);
    glVertex3f(-70, 100, -430);
    glVertex3f(-170, 100, -430);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-170, 100, -320);
    glVertex3f(-70, 100, -320);
    glVertex3f(-80, 110, -330);
    glVertex3f(-160, 110, -330);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-170, 100, -430);
    glVertex3f(-70, 100, -430);
    glVertex3f(-80, 110, -420);
    glVertex3f(-160, 110, -420);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-170, 100, -430);
    glVertex3f(-170, 100, -320);
    glVertex3f(-160, 110, -330);
    glVertex3f(-160, 110, -420);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-70, 100, -430);
    glVertex3f(-70, 100, -320);
    glVertex3f(-80, 110, -330);
    glVertex3f(-80, 110, -420);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-160, 110, -330);
    glVertex3f(-80, 110, -330);
    glVertex3f(-80, 110, -420);
    glVertex3f(-160, 110, -420);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-155, 110, -335);
    glVertex3f(-85, 110, -335);
    glVertex3f(-85, 130, -335);
    glVertex3f(-155, 130, -335);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-155, 110, -415);
    glVertex3f(-85, 110, -415);
    glVertex3f(-85, 130, -415);
    glVertex3f(-155, 130, -415);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-155, 110, -415);
    glVertex3f(-155, 110, -335);
    glVertex3f(-155, 130, -335);
    glVertex3f(-155, 130, -415);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-85, 110, -335);
    glVertex3f(-85, 110, -415);
    glVertex3f(-85, 130, -415);
    glVertex3f(-85, 130, -335);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-155, 130, -335);
    glVertex3f(-85, 130, -335);
    glVertex3f(-85, 130, -415);
    glVertex3f(-155, 130, -415);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-150, 140, -340);
    glVertex3f(-90, 140, -340);
    glVertex3f(-90, 140, -410);
    glVertex3f(-150, 140, -410);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-150, 130, -340);
    glVertex3f(-90, 130, -340);
    glVertex3f(-90, 140, -340);
    glVertex3f(-150, 140, -340);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-150, 130, -410);
    glVertex3f(-90, 130, -410);
    glVertex3f(-90, 140, -410);
    glVertex3f(-150, 140, -410);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-150, 130, -410);
    glVertex3f(-150, 130, -340);
    glVertex3f(-150, 140, -340);
    glVertex3f(-150, 140, -410);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-90, 130, -340);
    glVertex3f(-90, 130, -410);
    glVertex3f(-90, 140, -410);
    glVertex3f(-90, 140, -340);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-190, 0.15, 40);
    glVertex3f(-50, 0.15, 40);
    glVertex3f(-50, 0.15, -80);
    glVertex3f(-190, 0.15, -80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-190, 5, 40);
    glVertex3f(-50, 5, 40);
    glVertex3f(-50, 5, -80);
    glVertex3f(-190, 5, -80);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-190, 0, 40);
    glVertex3f(-50, 0, 40);
    glVertex3f(-50, 5, 40);
    glVertex3f(-190, 5, 40);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-190, 0, -80);
    glVertex3f(-50, 0, -80);
    glVertex3f(-50, 5, -80);
    glVertex3f(-190, 5, -80);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-190, 0, -80);
    glVertex3f(-190, 0, 40);
    glVertex3f(-190, 5, 40);
    glVertex3f(-190, 5, -80);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-50, 0, 40);
    glVertex3f(-50, 0, -80);
    glVertex3f(-50, 5, -80);
    glVertex3f(-50, 5, 40);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-180, 5, 30);
    glVertex3f(-60, 5, 30);
    glVertex3f(-60, 15, 30);
    glVertex3f(-180, 15, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-180, 5, -70);
    glVertex3f(-60, 5, -70);
    glVertex3f(-60, 15, -70);
    glVertex3f(-180, 15, -70);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-180, 5, -70);
    glVertex3f(-180, 5, 30);
    glVertex3f(-180, 15, 30);
    glVertex3f(-180, 15, -70);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-60, 5, 30);
    glVertex3f(-60, 5, 3 - 70);
    glVertex3f(-60, 15, -70);
    glVertex3f(-60, 15, 30);
    glEnd();
    //1
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-180, 15, 30);
    glVertex3f(-60, 15, 30);
    glVertex3f(-60, 18, 35);
    glVertex3f(-180, 18, 35);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-180, 15, -70);
    glVertex3f(-60, 15, -70);
    glVertex3f(-60, 18, -75);
    glVertex3f(-180, 18, -75);
    glEnd();
    //segitiga pojok1
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-180, 15, 30);
    glVertex3f(-185, 18, 30);
    glVertex3f(-180, 18, 35);
    glVertex3f(-180, 15, 35);
    glEnd();
    //segitiga pojok2
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-60, 15, 30);
    glVertex3f(-55, 18, 30);
    glVertex3f(-60, 18, 35);
    glVertex3f(-60, 15, 35);
    glEnd();
    //segitiga pojok3
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-180, 15, -70);
    glVertex3f(-185, 18, -70);
    glVertex3f(-180, 18, -75);
    glVertex3f(-180, 15, -75);
    glEnd();
    //segitiga pojok4
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-60, 15, -70);
    glVertex3f(-55, 18, -70);
    glVertex3f(-60, 18, -75);
    glVertex3f(-60, 15, -75);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-180, 15, 30);
    glVertex3f(-180, 15, -70);
    glVertex3f(-185, 18, -70);
    glVertex3f(-185, 18, 30);
    glEnd();
    //4
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60, 15, -70);
    glVertex3f(-60, 15, 30);
    glVertex3f(-55, 18, 30);
    glVertex3f(-55, 18, -70);
    glEnd();
    //5
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60, 18, 35);
    glVertex3f(-180, 18, 35);
    glVertex3f(-180, 21, 30);
    glVertex3f(-60, 21, 30);
    glEnd();
    //6
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60, 18, -75);
    glVertex3f(-180, 18, -75);
    glVertex3f(-180, 21, -70);
    glVertex3f(-60, 21, -70);
    glEnd();
    //segitiga pojok1
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-185, 18, 30);
    glVertex3f(-180, 21, 30);
    glVertex3f(-180, 18, 35);
    glVertex3f(-185, 21, 35);
    glEnd();
    //segitiga pojok2
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-185, 18, -70);
    glVertex3f(-180, 21, -70);
    glVertex3f(-180, 18, -75);
    glVertex3f(-185, 21, -75);
    glEnd();
    //segitiga pojok3
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-55, 18, 30);
    glVertex3f(-60, 21, 30);
    glVertex3f(-60, 18, 35);
    glVertex3f(-55, 21, 35);
    glEnd();
    //segitiga pojok4
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-55, 18, -70);
    glVertex3f(-60, 21, -70);
    glVertex3f(-60, 18, -75);
    glVertex3f(-55, 21, -75);
    glEnd();
    //7
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-185, 18, -70);
    glVertex3f(-185, 18, 30);
    glVertex3f(-180, 21, 30);
    glVertex3f(-180, 21, -70);
    glEnd();
    //8
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-55, 18, 30);
    glVertex3f(-55, 18, -70);
    glVertex3f(-60, 21, -70);
    glVertex3f(-60, 21, 30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-180, 21, 30);
    glVertex3f(-60, 21, 30);
    glVertex3f(-60, 21, -70);
    glVertex3f(-180, 21, -70);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 128, 144);
    glVertex3f(-175, 90, 25);
    glVertex3f(-65, 90, 25);
    glVertex3f(-65, 90, -65);
    glVertex3f(-175, 90, -65);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-175, 21, 25);
    glVertex3f(-65, 21, 25);
    glVertex3f(-65, 90, 25);
    glVertex3f(-175, 90, 25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-175, 21, -65);
    glVertex3f(-65, 21, -65);
    glVertex3f(-65, 90, -65);
    glVertex3f(-175, 90, -65);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-175, 21, -65);
    glVertex3f(-175, 21, 25);
    glVertex3f(-175, 90, 25);
    glVertex3f(-175, 90, -65);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 164, 96);
    glVertex3f(-65, 21, 25);
    glVertex3f(-65, 21, -65);
    glVertex3f(-65, 90, -65);
    glVertex3f(-65, 90, 25);
    glEnd();
    //1
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 90, 25);
    glVertex3f(-65, 90, 25);
    glVertex3f(-65, 93, 30);
    glVertex3f(-175, 93, 30);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 90, -65);
    glVertex3f(-65, 90, -65);
    glVertex3f(-65, 93, -70);
    glVertex3f(-175, 93, -70);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 90, 25);
    glVertex3f(-175, 90, -65);
    glVertex3f(-180, 93, -65);
    glVertex3f(-180, 93, 25);
    glEnd();
    //4
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-65, 90, -65);
    glVertex3f(-65, 90, 25);
    glVertex3f(-60, 93, 25);
    glVertex3f(-60, 93, -65);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 93, 30);
    glVertex3f(-65, 93, 30);
    glVertex3f(-65, 96, 25);
    glVertex3f(-175, 96, 25);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 93, -70);
    glVertex3f(-65, 93, -70);
    glVertex3f(-65, 96, -65);
    glVertex3f(-175, 96, -65);
    glEnd();

    //pojokatasjilid2
    glBegin(GL_TRIANGLES);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 90, 215);
    glVertex3f(-180, 93, 215);
    glVertex3f(-175, 93, 210);
    glVertex3f(-175, 90, 210);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(128, 128, 128);
    glVertex3f(-65, 90, 215);
    glVertex3f(-60, 93, 215);
    glVertex3f(-65, 93, 210);
    glVertex3f(-65, 90, 210);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(128, 128, 128);
    glVertex3f(-175, 90, 335);
    glVertex3f(-180, 93, 335);
    glVertex3f(-175, 93, 340);
    glVertex3f(-175, 90, 340);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(128, 128, 128);
    glVertex3f(-65, 90, 335);
    glVertex3f(-60, 93, 335);
    glVertex3f(-65, 93, 340);
    glVertex3f(-65, 90, 340);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-180, 93, 215);
    glVertex3f(-175, 96, 215);
    glVertex3f(-175, 93, 210);
    glVertex3f(-180, 96, 210);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-180, 93, 335);
    glVertex3f(-175, 96, 335);
    glVertex3f(-175, 93, 340);
    glVertex3f(-180, 96, 340);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-60, 93, 335);
    glVertex3f(-65, 96, 335);
    glVertex3f(-65, 93, 340);
    glVertex3f(-60, 96, 340);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(-60, 93, 215);
    glVertex3f(-65, 96, 215);
    glVertex3f(-65, 93, 210);
    glVertex3f(-60, 96, 210);
    glEnd();


    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0, 0, 3);
        break;
    case 's':
    case 'S':
        glTranslatef(0, 0, -3);
        break;
    case 'd':
    case 'D':
        glTranslatef(3, 0, 0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3, 0, 0);
        break;
    case '7':
        glTranslatef(0, 3, 0);
        break;
    case '9':
        glTranslatef(0, -3, 0);
        break;
    case '2':
        glRotatef(2, 1, 0, 0);
        break;
    case '8':
        glRotatef(-2, 1, 0, 0);
        break;
    case '6':
        glRotatef(2, 0, 1, 0);
        break;
    case '4':
        glRotatef(-2, 0, 1, 0);
        break;
    case '1':
        glRotatef(2, 0, 0, 1);
        break;
    case '3':
        glRotatef(-2, 0, 0, 1);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void idle() {
    if (!mouseDown) {
        xrot += 0.3;
        yrot += 0.4;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi) {
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100, lebar / tinggi, 5, 500);
    glTranslatef(0, -85, -200);
    glMatrixMode(GL_MODELVIEW);
}