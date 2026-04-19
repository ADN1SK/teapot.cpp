#include <GL/glut.h>
#include <GL/glu.h>
#include <dlfcn.h>

// Interactive rotation state
static float angleX = 30.0f;
static float angleY = 45.0f;
static int lastMouseX = 0;
static int lastMouseY = 0;
static int leftButtonDown = 0;
// Zoom (distance from camera)
static float zoomDist = 5.0f;
static const float minZoom = 2.0f;
static const float maxZoom = 20.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // translate by zoom distance
    glTranslatef(0.0f, 0.0f, -zoomDist);
    // apply interactive rotations
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);

    glColor3f(1.0f, 0.0f, 1.0f); // white wireframe
    glutWireTeapot(1.0);

    glutSwapBuffers();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLdouble)w / (GLdouble)h, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

void idle() {
    // auto-rotate around Y axis
    angleY += 0.3f;
    if (angleY > 360.0f) angleY -= 360.0f;
    glutPostRedisplay();
}

// Mouse button handler: start/stop drag
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            leftButtonDown = 1;
            lastMouseX = x;
            lastMouseY = y;
        } else {
            leftButtonDown = 0;
        }
    }
    // Mouse wheel: some GLUT implementations send wheel as button 3 (up) and 4 (down)
    if (button == 3) { // wheel up -> zoom in
        zoomDist -= 0.5f;
        if (zoomDist < minZoom) zoomDist = minZoom;
    } else if (button == 4) { // wheel down -> zoom out
        zoomDist += 0.5f;
        if (zoomDist > maxZoom) zoomDist = maxZoom;
    }
}

// Mouse motion while button pressed: update angles
void motion(int x, int y) {
    if (!leftButtonDown) return;
    int dx = x - lastMouseX;
    int dy = y - lastMouseY;
    // scale movement to degrees
    angleY += dx * 0.5f;
    angleX += dy * 0.5f;
    // clamp pitch to avoid flipping
    if (angleX > 89.0f) angleX = 89.0f;
    if (angleX < -89.0f) angleX = -89.0f;
    lastMouseX = x;
    lastMouseY = y;
    glutPostRedisplay();
}

// Mouse wheel handler for freeglut (wheel, direction, x, y)
void mouseWheel(int wheel, int direction, int x, int y) {
    (void)wheel; (void)x; (void)y;
    if (direction > 0) { // scroll up
        zoomDist -= 0.5f;
        if (zoomDist < minZoom) zoomDist = minZoom;
    } else { // scroll down
        zoomDist += 0.5f;
        if (zoomDist > maxZoom) zoomDist = maxZoom;
    }
}

// Keyboard zoom: +/- keys
void keyboard(unsigned char key, int x, int y) {
    (void)x; (void)y;
    if (key == '+' || key == '=') {
        zoomDist -= 0.5f;
        if (zoomDist < minZoom) zoomDist = minZoom;
    } else if (key == '-') {
        zoomDist += 0.5f;
        if (zoomDist > maxZoom) zoomDist = maxZoom;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Wireframe Teapot");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    // register interactive handlers
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    // prefer mouse wheel callback (freeglut) and keyboard zoom
    // try to register mouse wheel callback at runtime (if available)
    void* sym = dlsym(RTLD_DEFAULT, "glutMouseWheelFunc");
    if (sym) {
        typedef void (*WheelReg)(void (*)(int,int,int,int));
        WheelReg reg = (WheelReg)sym;
        reg(mouseWheel);
    }
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
// Compile with: g++ main.cpp -o teapot -lGL -lGLU -lglut -ldl
