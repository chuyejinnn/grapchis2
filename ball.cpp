#include <cstdio>
#include "elastic_ball.h"

// 중력 및 탄성 계수
const float gravity = -0.02f;   // 중력 값 증가
const float elasticity = 0.85f; // 탄성 계수

// 변형 효과를 위한 변수
float scaleX = 1.0f, scaleY = 1.0f;
bool isCompressing = false;

void updateBall() {
    ballVelocity += gravity; // 중력 적용
    ballY += ballVelocity;   // 공 위치 업데이트

    // 바닥 충돌 처리
    if (ballY < -0.5f) {
        ballY = -0.5f;
        ballVelocity = -ballVelocity * elasticity; // 속도 반전 및 탄성 적용
        isCompressing = true; // 변형 시작
    } else {
        isCompressing = false; // 변형 해제
    }

    // 속도가 너무 작을 경우 초기화
    if (ballVelocity > -0.001f && ballVelocity < 0.001f && ballY <= -0.5f) {
        ballVelocity = 0.2f;
    }

    // 디버깅용 출력
    printf("BallY: %f, BallVelocity: %f\n", ballY, ballVelocity);

    // 변형 계산
    if (isCompressing) { // 바닥에 닿았을 때
        scaleX = 1.2f;
        scaleY = 0.8f;
    } else { // 공이 올라갈 때
        scaleX = 1.0f;
        scaleY = 1.0f + (ballVelocity * 0.1f); // 속도에 따라 상하로 늘어남
    }
}
