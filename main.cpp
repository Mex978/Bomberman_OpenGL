using namespace std;

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <winuser.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "variaveis_globais.h"
#include "funcoes.h"
#include "bomba.h"
#include "mapa.h"

#define ESC 27

void init(void);
void keyboard (unsigned char key, int x, int y);
void display(void);
void reshape (int w, int h);

int main(int argc, char * * argv) {
	glutInit( & argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bomberman");
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}

void init(void) {
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	inicializarPosicoes();
	iluminacao();
	preencherMatrizBlocosDestrutiveis();
}

void reshape (int w, int h) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	gluPerspective(60, (float)w / (float)h, 1.0, 20.0);

	gluLookAt(0.0, 9, 5, 	// posição da câmera (olho)
			  0.0, 0.0, 0.0, 	// centro da cena
			  0.0, 1.0, 0.0); // direção de cima
}

void keyboard (unsigned char key, int x, int y) {
	switch (key) {
	case ESC:
		exit(0);
		break;
	case 'w':
		if (person_z > z_personagem_min) {
			if (movimentar("z", 0)) {
				person_z -= 0.1;
			}
		}

		break;
	case 's':
		if (person_z < z_personagem_max) {
			if (movimentar("z", 1)) {
				person_z += 0.1;
			}
		}
		break;
	case 'a':
		if (person_x > x_personagem_min) {
			if (movimentar("x", 0)) {
				person_x -= 0.1;
			}
		}
		break;
	case 'd':
		if (person_x < x_personagem_max) {
			if (movimentar("x", 1)) {
				person_x += 0.1;
			}
		}
		break;
	case ' ':
		if (!bomba && !exploda) {
			bomba = true;
			glutTimerFunc(3000, explodirBomba, 0);
		}
		break;
	default:
		break;
	}
	display();
}

void display(void) {
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Limpa o Buffer de Cores

	glTranslatef (-2.8, 4, 0.0);
	glBegin(GL_QUADS);
		glColor3d(1, 1, 1);
		glVertex3d(1, 1, 4.85);
		glVertex3d(4.85, 1, 4.85);
		glVertex3d(4.85, 1, 1);
		glVertex3d(1, 1, 1);
	glEnd();

	desenharBlocosIndestrutiveis();
	desenharBlocosDestrutiveis();
	desenharPersonagem();
	botarBomba();
	explosao();

	glutSwapBuffers();
	glutPostRedisplay();
}
