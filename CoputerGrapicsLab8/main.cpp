#include <GL/glut.h>
#include <cmath>

float cameraX = 0.0f;
float rotationAngle = 0.0f;
bool isRotating = false;


void connectVertices(float x1, float y1, float z1, float x2, float y2, float z2) {
    glBegin(GL_LINES);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
    glEnd();
}

// Буква И
void drawI() {
    glBegin(GL_LINES);
    glVertex3f(-2.0f, -2.0f, 0.0f);
    glVertex3f(-2.0f, 2.0f, 0.0f);
    glVertex3f(2.0f, -2.0f, 0.0f);
    glVertex3f(2.0f, 2.0f, 0.0f);
    glVertex3f(-2.0f, -2.0f, 0.0f);
    glVertex3f(2.0f, 2.0f, 0.0f);
    glEnd();


    glBegin(GL_LINES);
    glVertex3f(-2.0f, -2.0f, -2.0f);
    glVertex3f(-2.0f, 2.0f, -2.0f);
    glVertex3f(2.0f, -2.0f, -2.0f);
    glVertex3f(2.0f, 2.0f, -2.0f);
    glVertex3f(-2.0f, -2.0f, -2.0f);
    glVertex3f(2.0f, 2.0f, -2.0f);
    glEnd();

    connectVertices(-2.0f, -2.0f, 0.0f, -2.0f, -2.0f, -2.0f);
    connectVertices(-2.0f, 2.0f, 0.0f, -2.0f, 2.0f, -2.0f);
    connectVertices(2.0f, -2.0f, 0.0f, 2.0f, -2.0f, -2.0f);
    connectVertices(2.0f, 2.0f, 0.0f, 2.0f, 2.0f, -2.0f);
}

// Буква В
void drawV() {
    glBegin(GL_LINES);
    glVertex3f(-2.0f, -2.0f, 0.0f);
    glVertex3f(-2.0f, 2.0f, 0.0f);
    glVertex3f(-2.0f, 2.0f, 0.0f);
    glVertex3f(2.0f, 1.5f, 0.0f);
    glVertex3f(2.0f, 1.5f, 0.0f);
    glVertex3f(-2.0f, 0.0f, 0.0f);
    glVertex3f(-2.0f, 0.0f, 0.0f);
    glVertex3f(2.0f, -1.5f, 0.0f);
    glVertex3f(2.0f, -1.5f, 0.0f);
    glVertex3f(-2.0f, -2.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-2.0f, -2.0f, -2.0f);
    glVertex3f(-2.0f, 2.0f, -2.0f);
    glVertex3f(-2.0f, 2.0f, -2.0f);
    glVertex3f(2.0f, 1.5f, -2.0f);
    glVertex3f(2.0f, 1.5f, -2.0f);
    glVertex3f(-2.0f, 0.0f, -2.0f);
    glVertex3f(-2.0f, 0.0f, -2.0f);
    glVertex3f(2.0f, -1.5f, -2.0f);
    glVertex3f(2.0f, -1.5f, -2.0f);
    glVertex3f(-2.0f, -2.0f, -2.0f);
    glEnd();

    connectVertices(-2.0f, -2.0f, 0.0f, -2.0f, -2.0f, -2.0f);
    connectVertices(-2.0f, 2.0f, 0.0f, -2.0f, 2.0f, -2.0f);
    connectVertices(2.0f, 1.5f, 0.0f, 2.0f, 1.5f, -2.0f);
    connectVertices(-2.0f, 0.0f, 0.0f, -2.0f, 0.0f, -2.0f);
    connectVertices(2.0f, -1.5f, 0.0f, 2.0f, -1.5f, -2.0f);
}

// Буква А
void drawA() {
    
    glBegin(GL_LINES);
    glVertex3f(-2.0f, -2.0f, 0.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);
    glVertex3f(2.0f, -2.0f, 0.0f);
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-2.0f, -2.0f, -2.0f);
    glVertex3f(0.0f, 2.0f, - 2.0f);
    glVertex3f(0.0f, 2.0f, -2.0f);
    glVertex3f(2.0f, -2.0f, -2.0f);
    glVertex3f(-1.0f, 0.0f, -2.0f);
    glVertex3f(1.0f, 0.0f, -2.0f);
    glEnd();

    connectVertices(-2.0f, -2.0f, 0.0f, -2.0f, -2.0f, -2.0f);
    connectVertices(2.0f, -2.0f, 0.0f, 2.0f, -2.0f, -2.0f);
    connectVertices(0.0f, 2.0f, 0.0f, 0.0f, 2.0f, -2.0f);
}

// Буква Н
void drawN() {
    glBegin(GL_LINES);
    glVertex3f(-2.0f, -2.0f, 0.0f);
    glVertex3f(-2.0f, 2.0f, 0.0f);
    glVertex3f(2.0f, -2.0f, 0.0f);
    glVertex3f(2.0f, 2.0f, 0.0f);
    glVertex3f(-2.0f, 0.0f, 0.0f);
    glVertex3f(2.0f, 0.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-2.0f, -2.0f, -2.0f);
    glVertex3f(-2.0f, 2.0f, -2.0f);
    glVertex3f(2.0f, -2.0f, -2.0f);
    glVertex3f(2.0f, 2.0f, -2.0f);
    glVertex3f(-2.0f, 0.0f, -2.0f);
    glVertex3f(2.0f, 0.0f, -2.0f);
    glEnd();

    connectVertices(-2.0f, -2.0f, 0.0f, -2.0f, -2.0f, -2.0f);
    connectVertices(-2.0f, 2.0f, 0.0f, -2.0f, 2.0f, -2.0f);
    connectVertices(2.0f, -2.0f, 0.0f, 2.0f, -2.0f, -2.0f);
    connectVertices(2.0f, 2.0f, 0.0f, 2.0f, 2.0f, -2.0f);
    connectVertices(-2.0f, 0.0f, 0.0f, -2.0f, 0.0f, -2.0f);
    connectVertices(2.0f, 0.0f, 0.0f, 2.0f, 0.0f, -2.0f);

}

// Буква О
void drawO() {
    glBegin(GL_LINE_LOOP);
    for (float angle = 0; angle < 360; angle += 10) {
        float rad = angle * 3.14159 / 180;
        glVertex3f(2.0f * cos(rad), 2.0f * sin(rad), 0.0f);
    }
    glEnd();

    glBegin(GL_LINE_LOOP);
    for (float angle = 0; angle < 360; angle += 10) {
        float rad = angle * 3.14159 / 180;
        glVertex3f(2.0f * cos(rad), 2.0f * sin(rad), -2.0f);
    }
    glEnd();

    for (float angle = 0; angle < 360; angle += 10) {
        float rad = angle * 3.14159 / 180;
        connectVertices(2.0f * cos(rad), 2.0f * sin(rad), 0.0f,
            2.0f * cos(rad), 2.0f * sin(rad), -2.0f);
    }
}

// Буква В
void drawB() {
    drawV();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(cameraX, -2.0f, -15.0f);
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPushMatrix(); glTranslatef(-15.0f, 0.0f, 0.0f); drawI(); glPopMatrix();
    glPushMatrix(); glTranslatef(-9.0f, 0.0f, 0.0f); drawV(); glPopMatrix();
    glPushMatrix(); glTranslatef(-3.0f, 0.0f, 0.0f); drawA(); glPopMatrix();
    glPushMatrix(); glTranslatef(3.0f, 0.0f, 0.0f); drawN(); glPopMatrix();
    glPushMatrix(); glTranslatef(9.0f, 0.0f, 0.0f); drawO(); glPopMatrix();
    glPushMatrix(); glTranslatef(15.0f, 0.0f, 0.0f); drawB(); glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void initOpenGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void timer(int value) {
    if (isRotating) {
        rotationAngle += 2.0f;
        if (rotationAngle > 360.0f) rotationAngle -= 360.0f;
        glutPostRedisplay();
    }
    glutTimerFunc(16, timer, 0);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'p' || key == 'P') isRotating = true;
    if (key == 'l' || key == 'L') isRotating = false;
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) cameraX += 0.5f;
    if (key == GLUT_KEY_RIGHT) cameraX -= 0.5f;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Лабораторная работа #8");
    initOpenGL();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
