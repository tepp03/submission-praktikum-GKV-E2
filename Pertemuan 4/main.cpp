#include <GL/glut.h>

// Inisialisasi OpenGL
void setup() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.33, 1.0, 100.0);
}

// Fungsi menggambar mobil wireframe
void renderMobil() {
    glPushMatrix();
    glTranslatef(0.0f, -2.5f, -20.0f);

    // Badan mobil (kubus rangka)
    glColor3f(0.5f, 0.7f, 0.9f);
    float titik[][3] = {
        {-3, -1, 2}, {3, -1, 2}, {3, 1, 2}, {-3, 1, 2},
        {-3, -1, -2}, {3, -1, -2}, {3, 1, -2}, {-3, 1, -2}
    };
    int garis[][2] = {
        {0,1}, {1,2}, {2,3}, {3,0},
        {4,5}, {5,6}, {6,7}, {7,4},
        {0,4}, {1,5}, {2,6}, {3,7}
    };
    glBegin(GL_LINES);
    for (int i = 0; i < 12; i++) {
        glVertex3fv(titik[garis[i][0]]);
        glVertex3fv(titik[garis[i][1]]);
    }
    glEnd();

    // Roda
    glColor3f(0.1f, 0.1f, 0.1f);
    for (int x = -2; x <= 2; x += 4) {
        for (int z = -1; z <= 1; z += 2) {
            glPushMatrix();
            glTranslatef(x, -1.3f, z * 1.9f);
            glutWireTorus(0.2, 0.6, 10, 20);
            glPopMatrix();
        }
    }

    // Atap trapesium
    float atap[][3] = {
        {-2,1,1.5}, {2,1,1.5}, {1.5,3,1}, {-1.5,3,1},
        {-2,1,-1.5}, {2,1,-1.5}, {1.5,3,-1}, {-1.5,3,-1}
    };
    int garisAtap[][2] = {
        {0,1}, {1,2}, {2,3}, {3,0},
        {4,5}, {5,6}, {6,7}, {7,4},
        {0,4}, {1,5}, {2,6}, {3,7}
    };
    glColor3f(0.4f, 0.6f, 0.8f);
    glBegin(GL_LINES);
    for (int i = 0; i < 12; i++) {
        glVertex3fv(atap[garisAtap[i][0]]);
        glVertex3fv(atap[garisAtap[i][1]]);
    }
    glEnd();

    glPopMatrix();
}

// Fungsi display utama
void tampil() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(10, 5, 20, 0, 0, -20, 0, 1, 0);
    renderMobil();
    glutSwapBuffers();
}

// Main Program
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil 3D - OpenGL");

    setup();
    glutDisplayFunc(tampil);
    glutMainLoop();

    return 0;
}

