//
//  main.cpp
//  project02
//
//  Created by 추예진 on 11/17/24.
//

#include <GL/glut.h> // GLUT, include glu.h and gl.h

// Transformation variables
GLfloat rotationX = 0.0f, rotationY = 0.0f;
GLfloat translateX = 0.0f, translateY = 0.0f, translateZ = -5.0f;
GLfloat scale = 1.0f;

// Function to initialize OpenGL settings
void initGL() {
    glEnable(GL_DEPTH_TEST);  // Enable depth testing for z-culling
    glEnable(GL_COLOR_MATERIAL); // Enable coloring
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Background color
}

// Function to handle drawing of the cube
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glLoadIdentity(); // Reset transformations

    // Apply transformations
    glTranslatef(translateX, translateY, translateZ); // Translation
    glScalef(scale, scale, scale);                   // Scaling
    glRotatef(rotationX, 1.0f, 0.0f, 0.0f);          // Rotation around X-axis
    glRotatef(rotationY, 0.0f, 1.0f, 0.0f);          // Rotation around Y-axis

    // Draw a cube
    glBegin(GL_QUADS);

    // Front face
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);

    // Back face
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    // Left face
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);

    // Right face
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);

    glEnd();

    glutSwapBuffers(); // Swap front and back buffers
}

// Function to handle key press events
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': rotationX -= 5.0f; break; // Rotate up
        case 's': rotationX += 5.0f; break; // Rotate down
        case 'a': rotationY -= 5.0f; break; // Rotate left
        case 'd': rotationY += 5.0f; break; // Rotate right
        case 'q': scale -= 0.1f; break;    // Scale down
        case 'e': scale += 0.1f; break;    // Scale up
        case 'z': translateZ -= 0.5f; break; // Move closer
        case 'x': translateZ += 0.5f; break; // Move farther
        case 27: exit(0); // ESC key exits the program
    }
    glutPostRedisplay();
}

// Function to handle window resizing
void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1; // Prevent divide by zero
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION); // Set the projection matrix
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW); // Return to modelview matrix
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Cube Transformation");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(handleKeypress);
    initGL();
    glutMainLoop();
    return 0;
}
