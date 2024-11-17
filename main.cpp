#include <GL/glut.h>
#include "elastic_ball.h"

bool isWireframe = false; // 와이어프레임 모드 여부

void initGL() {
    glEnable(GL_DEPTH_TEST);              // 깊이 테스트 활성화
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f); // 밝은 회색 배경
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(0.0, 2.0, 6.0,
              0.0, 1.0, 0.0,
              0.0, 1.0, 0.0);

    drawFloor();
    drawBall();

    glutSwapBuffers();
}

void timer(int value) {
    updateBall();
    glutPostRedisplay(); // 화면 갱신 요청
    glutTimerFunc(16, timer, 0); // ~60 FPS
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': // 와이어프레임 모드 활성화
            isWireframe = true;
            break;
        case 's': // 솔리드 모드 활성화
            isWireframe = false;
            break;
        case 27: // ESC 키
            exit(0); // 프로그램 종료
    }
    glutPostRedisplay(); // 키 입력 후 화면 갱신
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Elastic Ball Animation");

    initGL();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard); // 키보드 입력 처리 함수 등록
    glutTimerFunc(16, timer, 0);

    glutMainLoop();
    return 0;
}
