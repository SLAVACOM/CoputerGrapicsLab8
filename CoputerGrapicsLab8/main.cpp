#include <GL/glut.h>
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;

float cameraX = 0.0f, cameraY = 0.0f, cameraZ = 10.0f;
float cameraAngleX = 0.0f, cameraAngleY = 0.0f;

GLfloat lightPos[] = { 5.0f, 10.0f, 5.0f, 1.0f };
GLfloat whiteLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat matSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat matShininess = 50.0f;

struct Point {
    float x, y, z;
    Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

vector<vector<vector<Point>>> letters = {
    {
        { Point(-5.0f, 2.0f, 0.0f),

            Point(-5.0f, -2.0f, 0.0f),
            Point(-3.0f, 2.0f, 0.0f),
            Point(-3.0f, -2.0f, 0.0f)}
    },
    {
       { Point(-2.0f, 2.0f, 0.0f), Point(-2.0f, -2.0f, 0.0f) },
       { Point(-2.0f, 2.0f, 0.0f), Point(-1.0f, 2.0f, 0.0f),
         Point(-1.0f, 0.0f, 0.0f), Point(-2.0f, 0.0f, 0.0f) },
       { Point(-2.0f, 0.0f, 0.0f), Point(-0.0f, 0.0f, 0.0f),
         Point(-0.0f, -2.0f, 0.0f), Point(-2.0f, -2.0f, 0.0f) }
    },
    {
        { Point(1.0f, -2.0f, 0.0f), Point(2.0f, 2.0f, 0.0f), Point(3.0f, -2.0f, 0.0f) },
        { Point(1.5f, 0.0f, 0.0f), Point(2.5f, 0.0f, 0.0f) }
    },
    {
        { Point(4.0f, -2.0f, 0.0f), Point(4.0f, 2.0f, 0.0f) },
        { Point(6.0f, -2.0f, 0.0f), Point(6.0f, 2.0f, 0.0f) },
        { Point(4.0f, 0.0f, 0.0f), Point(6.0f, 0.0f, 0.0f) }
    },
    {
        { Point(7.5f, -2.f, 0.0f), Point(7.5f, 2.f, 0.0f), Point(9.5f, 2.f, 0.0f),
          Point(9.5f, -2.f, 0.0f), Point(7.5f, -2.f, 0.0f) }
    },
    {
        {   Point(10.0f, 2.0f, 0.0f), Point(10.0f, -2.0f, 0.0f) },
        {   Point(10.0f, 2.0f, 0.0f), Point(11.0f, 2.0f, 0.0f),
            Point(11.0f, 0.0f, 0.0f), Point(10.0f, 0.0f, 0.0f) },
        {
            Point(10.0f, 0.0f, 0.0f), Point(12.0f, 0.0f, 0.0f),
            Point(12.0f, -2.0f, 0.0f), Point(10.0f, -2.0f, 0.0f) }
    }
};

float colors[6][3] = {
    {1.0f, 1.0f, 1.0f},
    {1.0f, 1.0f, 1.0f},
    {1.0f, 1.0f, 1.0f},
    {1.0f, 1.0f, 1.0f},
    {1.0f, 1.0f, 1.0f},
    {1.0f, 1.0f, 1.0f}
};


float lineThickness = 0.1f;
float extrusionDepth = 2.0f;

void init() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, whiteLight);

    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialf(GL_FRONT, GL_SHININESS, matShininess);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

void drawExtrudedSegment(const Point& p0, const Point& p1, float r, float g, float b) {
    float dx = p1.x - p0.x;
    float dy = p1.y - p0.y;
    float length = sqrt(dx * dx + dy * dy);
    if (length == 0) return;

    dx /= length; dy /= length;
    float px = -dy;
    float py = dx;
    float offsetX = px * lineThickness;
    float offsetY = py * lineThickness;

    float v0x = p0.x + offsetX, v0y = p0.y + offsetY;
    float v1x = p0.x - offsetX, v1y = p0.y - offsetY;
    float v2x = p1.x - offsetX, v2y = p1.y - offsetY;
    float v3x = p1.x + offsetX, v3y = p1.y + offsetY;

    float v0x_b = v0x, v0y_b = v0y;
    float v1x_b = v1x, v1y_b = v1y;
    float v2x_b = v2x, v2y_b = v2y;
    float v3x_b = v3x, v3y_b = v3y;

    glColor3f(r, g, b);

    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(v0x, v0y, 0.0f);
    glVertex3f(v1x, v1y, 0.0f);
    glVertex3f(v2x, v2y, 0.0f);
    glVertex3f(v3x, v3y, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(v0x_b, v0y_b, -extrusionDepth);
    glVertex3f(v3x_b, v3y_b, -extrusionDepth);
    glVertex3f(v2x_b, v2y_b, -extrusionDepth);
    glVertex3f(v1x_b, v1y_b, -extrusionDepth);
    glEnd();

    glBegin(GL_QUADS);
    glNormal3f(px, py, 0.0f);
    glVertex3f(v0x, v0y, 0.0f);
    glVertex3f(v0x_b, v0y_b, -extrusionDepth);
    glVertex3f(v1x_b, v1y_b, -extrusionDepth);
    glVertex3f(v1x, v1y, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    float edx = v2x - v1x, edy = v2y - v1y;
    float edlen = sqrt(edx * edx + edy * edy);
    if (edlen != 0) { edx /= edlen; edy /= edlen; }
    float nx = -edy, ny = edx;
    glNormal3f(nx, ny, 0.0f);
    glVertex3f(v1x, v1y, 0.0f);
    glVertex3f(v1x_b, v1y_b, -extrusionDepth);
    glVertex3f(v2x_b, v2y_b, -extrusionDepth);
    glVertex3f(v2x, v2y, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glNormal3f(-px, -py, 0.0f);
    glVertex3f(v2x, v2y, 0.0f);
    glVertex3f(v2x_b, v2y_b, -extrusionDepth);
    glVertex3f(v3x_b, v3y_b, -extrusionDepth);
    glVertex3f(v3x, v3y, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    edx = v0x - v3x; edy = v0y - v3y;
    edlen = sqrt(edx * edx + edy * edy);
    if (edlen != 0) { edx /= edlen; edy /= edlen; }
    nx = -edy; ny = edx;
    glNormal3f(nx, ny, 0.0f);
    glVertex3f(v3x, v3y, 0.0f);
    glVertex3f(v3x_b, v3y_b, -extrusionDepth);
    glVertex3f(v0x_b, v0y_b, -extrusionDepth);
    glVertex3f(v0x, v0y, 0.0f);
    glEnd();
}

void drawExtrudedLetterStroke(const vector<Point>& stroke, float r, float g, float b) {
    for (size_t i = 0; i < stroke.size() - 1; i++) {
        drawExtrudedSegment(stroke[i], stroke[i + 1], r, g, b);
    }
}

void draw3DName() {
    int colorIndex = 0;
    for (size_t i = 0; i < letters.size(); i++) {
        float r = colors[colorIndex][0];
        float g = colors[colorIndex][1];
        float b = colors[colorIndex][2];
        for (size_t j = 0; j < letters[i].size(); j++) {
            drawExtrudedLetterStroke(letters[i][j], r, g, b);
        }
        colorIndex = (colorIndex + 1) % 6;
    }
}

int lastMouseX, lastMouseY;
bool leftButtonDown = false;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);
    gluPerspective(45.0, (double)width / height, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float radY = cameraAngleY;
    float radX = cameraAngleX;
    float lx = sin(radY) * cos(radX);
    float ly = sin(radX);
    float lz = -cos(radY) * cos(radX);
    gluLookAt(cameraX, cameraY, cameraZ, cameraX + lx, cameraY + ly, cameraZ + lz, 0.0f, 1.0f, 0.0f);

    glPushMatrix();
    glTranslatef(-3.5f, 0.0f, 0.0f);
    draw3DName();
    glPopMatrix();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    float moveSpeed = 0.3f;
    switch (key) {
    case 'w':
    case 'W':
        cameraX += sin(cameraAngleY) * moveSpeed;
        cameraZ += -cos(cameraAngleY) * moveSpeed;
        break;
    case 's':
    case 'S':
        cameraX -= sin(cameraAngleY) * moveSpeed;
        cameraZ -= -cos(cameraAngleY) * moveSpeed;
        break;
    case 'a':
    case 'A':
        cameraX -= cos(cameraAngleY) * moveSpeed;
        cameraZ -= sin(cameraAngleY) * moveSpeed;
        break;
    case 'd':
    case 'D':
        cameraX += cos(cameraAngleY) * moveSpeed;
        cameraZ += sin(cameraAngleY) * moveSpeed;
        break;
    case 'q':
    case 'Q':
        cameraY -= moveSpeed;
        break;
    case 'e':
    case 'E':
        cameraY += moveSpeed;
        break;
    case 'r':
    case 'R': 
        cameraX = 0.0f;
        cameraY = 0.0f;
        cameraZ = 10.0f;
        cameraAngleX = 0.0f;
        cameraAngleY = 0.0f;
        break;
    case 27: 
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    float rotateSpeed = 0.05f;
    switch (key) {
    case GLUT_KEY_LEFT:
        cameraAngleY -= rotateSpeed;
        break;
    case GLUT_KEY_RIGHT:
        cameraAngleY += rotateSpeed;
        break;
    case GLUT_KEY_UP:
        cameraAngleX += rotateSpeed;
        break;
    case GLUT_KEY_DOWN:
        cameraAngleX -= rotateSpeed;
        break;
    }
    glutPostRedisplay();
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            leftButtonDown = true;
            lastMouseX = x;
            lastMouseY = y;
        }
        else {
            leftButtonDown = false;
        }
    }
}

void mouseMotion(int x, int y) {
    if (leftButtonDown) {
        int dx = x - lastMouseX;
        int dy = y - lastMouseY;
        float sensitivity = 0.005f;
        cameraAngleY += dx * sensitivity;
        cameraAngleX += dy * sensitivity;
        lastMouseX = x;
        lastMouseY = y;
        glutPostRedisplay();
    }
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("Лого");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMotion);

    glutMainLoop();
    return 0;
}