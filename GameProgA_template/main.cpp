#include <iostream>
#ifdef WIN32
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLUT.h>
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif
#include <time.h>

// ゲームの設定
int screenWidth = 600;
int screenHeight = 600;

// 時間の管理
static uint64_t prevTime;
uint64_t getTimestamp()
{
#ifdef WIN32
    LARGE_INTEGER freq, t;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&t);
    return t.QuadPart * 1e6 / freq.QuadPart;
#else
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    uint64_t absolute_micro =
        static_cast<int64_t>(ts.tv_sec) * 1000000
        + static_cast<int64_t>(ts.tv_nsec) / 1000;
    return absolute_micro;
#endif
}

struct PlayerBox
{
    int cx;
    int cy;
    int width;
    int height;
    PlayerBox()
    {
        width = 100;
        height = 100;
        cx = 50;
        cy = 50;
    }
    void draw()
    {
        glBegin(GL_POLYGON);
        glVertex2i(cx - width / 2, cy - height / 2);
        glVertex2i(cx - width / 2, cy + height / 2);
        glVertex2i(cx + width / 2, cy + height / 2);
        glVertex2i(cx + width / 2, cy - height / 2);
        glEnd();
    }
};

PlayerBox player;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    player.draw();
    
    glutSwapBuffers();
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'q':
        case 'Q':
            exit(0);
            break;
        default:
            break;
    }
}

void mouseMotion(int x, int y)
{
    player.cx = x;
    player.cy = screenHeight - y;
}

void passiveMotion(int x, int y)
{
    player.cx = x;
    player.cy = screenHeight - y;
}

void idle()
{
    uint64_t time = getTimestamp();
    if (time - prevTime > 1.0e6 / 30.0)
    {
        display();
        prevTime = time;
    }
}

int main(int argc, char* argv[])
{
    // GLUTフレームワークの初期化（おまじない）
    glutInit(&argc, argv);
    // 表示ウィンドウのサイズを設定

    glutInitWindowSize(screenWidth, screenHeight);
    // 表示モードの設定（おまじない）
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    // ウィンドウの表示
    glutCreateWindow("GameProgA_template");
    // イベントハンドラの設定
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutMotionFunc(mouseMotion);
    glutPassiveMotionFunc(passiveMotion);
    // ゲーム世界のサイズを設定
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, screenWidth, 0, screenHeight);
    // ゲーム開始時刻の記録
    prevTime = getTimestamp();
    glutMainLoop();
    return 0;
}
