#include <GL/glut.h>

// Fungsi utama untuk menggambar ke layar
void tampilkan() {
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Set warna dasar transparan biru muda
    glColor4f(0.2f, 0.7f, 0.9f, 0.15f);

    float posisiX = -0.25f;
    float posisiY = 0.25f;
    float ukuran = 0.2f;

    // Gambar 10 kotak berurutan secara diagonal
    for (int langkah = 0; langkah < 10; ++langkah) {
        float geser = langkah * 0.1f;

        // Menggambar persegi menggunakan glRectf (kanan atas, kiri bawah)
        glRectf(posisiX + geser, posisiY - geser, posisiX + geser + ukuran, posisiY - geser - ukuran);
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Visual Kotak Transparan");

    glutDisplayFunc(tampilkan);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Latar belakang gelap

    glutMainLoop();
    return 0;
}

