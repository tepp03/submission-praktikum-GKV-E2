#include <GL/glut.h>
#include <cstdlib>

// Resolusi geometri
int jumlahSlices = 16;
int jumlahStacks = 16;

// Fungsi untuk mengatur viewport dan proyeksi
void aturUkuran(int lebar, int tinggi) {
    float rasio = (float)lebar / (float)tinggi;

    glViewport(0, 0, lebar, tinggi);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-rasio, rasio, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Fungsi untuk menggambar semua objek
void tampilkan() {
    double waktu = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double sudutRotasi = waktu * 90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1, 0, 0);

    // Fungsi bantu untuk menggambar objek 3D
    auto gambarObjek = [&](void(*bentuk)(), double x, double y) {
        glPushMatrix();
            glTranslated(x, y, -6);
            glRotated(60, 1, 0, 0);
            glRotated(sudutRotasi, 0, 0, 1);
            bentuk();
        glPopMatrix();
    };

    // Objek solid
    gambarObjek([]() { glutSolidSphere(1, jumlahSlices, jumlahStacks); }, -2.4, 1.2);
    gambarObjek([]() { glutSolidCone(1, 1, jumlahSlices, jumlahStacks); },  0.0, 1.2);
    gambarObjek([]() { glutSolidTorus(0.2, 0.8, jumlahSlices, jumlahStacks); }, 2.4, 1.2);

    // Objek wireframe
    gambarObjek([]() { glutWireSphere(1, jumlahSlices, jumlahStacks); }, -2.4, -1.2);
    gambarObjek([]() { glutWireCone(1, 1, jumlahSlices, jumlahStacks); },  0.0, -1.2);
    gambarObjek([]() { glutWireTorus(0.2, 0.8, jumlahSlices, jumlahStacks); }, 2.4, -1.2);

    glutSwapBuffers();
}

// Fungsi untuk menangani input keyboard
void tombolKeyboard(unsigned char key, int, int) {
    switch (key) {
        case 27: // ESC
        case 'q':
            exit(0);
            break;
        case '+':
            jumlahSlices++;
            jumlahStacks++;
            break;
        case '-':
            if (jumlahSlices > 3 && jumlahStacks > 3) {
                jumlahSlices--;
                jumlahStacks--;
            }
            break;
    }
    glutPostRedisplay();
}

// Fungsi idle untuk terus memutar objek
void idleAnimasi() {
    glutPostRedisplay();
}

// Inisialisasi pencahayaan dan material
void inisialisasiOpenGL() {
    const GLfloat ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
    const GLfloat diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat posisi[]   = { 2.0f, 5.0f, 5.0f, 0.0f };

    const GLfloat matAmbient[]  = { 0.7f, 0.7f, 0.7f, 1.0f };
    const GLfloat matDiffuse[]  = { 0.8f, 0.8f, 0.8f, 1.0f };
    const GLfloat matSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat shininess[]   = { 100.0f };

    glClearColor(1, 1, 1, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_POSITION, posisi);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   matAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
}

// Fungsi utama
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Demo Objek 3D OpenGL");
    glutReshapeFunc(aturUkuran);
    glutDisplayFunc(tampilkan);
    glutKeyboardFunc(tombolKeyboard);
    glutIdleFunc(idleAnimasi);

    inisialisasiOpenGL();
    glutMainLoop();

    return EXIT_SUCCESS;
}

