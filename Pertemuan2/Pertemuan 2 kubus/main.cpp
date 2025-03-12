#include <GL/glut.h>

void drawCube(float x, float y, float r, float g, float b) {
    // Gambar isi kubus dengan warna berbeda
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    
    glVertex2f(x, y);
    glVertex2f(x + 0.2, y);
    glVertex2f(x + 0.2, y + 0.2);
    glVertex2f(x, y + 0.2);
    
    glEnd();
    
    // Gambar border kubus
    glLineWidth(2.0);
    glColor3f(0.0, 0.0, 0.3); // Warna garis biru gelap
    glBegin(GL_LINE_LOOP);
    
    glVertex2f(x, y);
    glVertex2f(x + 0.2, y);
    glVertex2f(x + 0.2, y + 0.2);
    glVertex2f(x, y + 0.2);
    
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Baris bawah (3 kubus)
    drawCube(-0.3, -0.2, 1.0, 0.0, 0.0); // Merah
    drawCube(-0.1, -0.2, 0.0, 1.0, 0.0); // Hijau
    drawCube(0.1, -0.2, 0.0, 0.0, 1.0);  // Biru
    
    // Baris tengah (2 kubus)
    drawCube(-0.2, 0.0, 1.0, 1.0, 0.0); // Kuning
    drawCube(0.0, 0.0, 1.0, 0.0, 1.0);  // Ungu
    
    // Puncak (1 kubus di atas)
    drawCube(-0.1, 0.2, 0.0, 1.0, 1.0); // Cyan
    
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Latar belakang putih
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Kubus Bertingkat");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

