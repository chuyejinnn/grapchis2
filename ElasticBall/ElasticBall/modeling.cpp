#include <GL/glut.h>
#include "elastic_ball.h"

float ballY = 2.0f;        // 공의 초기 Y 위치
float ballVelocity = 0.0f; // 공의 초기 속도

extern float scaleX, scaleY; // 변형 변수 외부 참조
extern bool isWireframe;     // 와이어프레임 모드

void drawBall() {
    glPushMatrix();

    // 공 변형 적용
    glScalef(scaleX, scaleY, 1.0f);
    glTranslatef(0.0f, ballY, 0.0f);

    // 공 색상 및 렌더링
    glColor3f(1.0f, 0.5f, 0.0f); // 주황색 공
    if (isWireframe) {
        glutWireSphere(1.0, 32, 32);
    } else {
        glutSolidSphere(1.0, 32, 32);
    }

    glPopMatrix();
}

void drawFloor() {
    glPushMatrix();
    glColor3f(0.6f, 0.6f, 0.6f); // 밝은 회색 바닥
    glTranslatef(0.0f, -1.0f, 0.0f);
    glScalef(5.0f, 0.1f, 5.0f);
    glutSolidCube(1.0f);
    glPopMatrix();
}
