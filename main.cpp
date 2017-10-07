#include <iostream>
#include <GL/glut.h>

using namespace std;

GLfloat lXpos = 1.0,lYPos = 1.0, lZpos = 1.0;

void init(void){
    GLfloat mat_specular[] = {1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[] = {50.0};
    GLfloat light_pos[] = {lXpos,lYPos,lZpos,0.0};
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0,GL_POSITION,light_pos);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void changeLightPosition(){
    cout<<lXpos << " " << lYPos << endl;
    GLfloat mat_specular[] = {1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[] = {50.0};
    GLfloat light_pos[] = {lXpos,lYPos,lZpos,0.0};
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0,GL_POSITION,light_pos);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidSphere(1.0,20,16);
    glFlush();
}

void changeLightPosition(GLint x, GLint y){
    lXpos = x;
    lYPos = y;
    changeLightPosition();
}

void kbFunc(GLubyte key, GLint xMouse, GLint yMouse){
    switch (key){
        case 'w':
            lYPos = lYPos+1;
            break;
        case 'a':
            lXpos = lXpos-1;
            break;
        case 's':
            lYPos = lYPos-1;
            break;
        case 'd':
            lXpos = lXpos+1;
            break;
        case 'r':
            lZpos = lZpos+1;
            break;
        case 't':
            lZpos = lZpos-1;
    }
    changeLightPosition();
}

void mousePickSpot(GLint button, GLint action, GLint xMouse, GLint yMouse){
    if(button == GLUT_LEFT_BUTTON && action == GLUT_DOWN){
        changeLightPosition(xMouse, 420 - yMouse);
    }
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidSphere(1.0,20,16);
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200,200);
    glutInitWindowSize(420,420);
    glutCreateWindow("Iluminacion");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(kbFunc);
    glutMouseFunc(mousePickSpot);

    glutMainLoop();
    return 0;
}