//
//  elastic_ball.h
//  ElasticBall
//
//  Created by 추예진 on 11/17/24.
//

#ifndef ELASTIC_BALL_H
#define ELASTIC_BALL_H

// 공의 전역 변수 선언 (정의는 다른 .cpp 파일에서)
extern float ballY;
extern float ballVelocity;

// 함수 선언
void updateBall();
void drawBall();
void drawFloor();

#endif // ELASTIC_BALL_H
