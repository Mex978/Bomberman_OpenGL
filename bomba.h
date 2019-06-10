void botarBomba() {
	if (!bomba) {
		posicaoBomba[0].x1 = posicaoPersonagem[0].x1;
		posicaoBomba[0].x2 = posicaoPersonagem[0].x2;
		posicaoBomba[0].x3 = posicaoPersonagem[0].x3;
		posicaoBomba[0].x4 = posicaoPersonagem[0].x4;

		posicaoBomba[1].x1 = posicaoPersonagem[1].x1;
		posicaoBomba[1].x2 = posicaoPersonagem[1].x2;
		posicaoBomba[1].x3 = posicaoPersonagem[1].x3;
		posicaoBomba[1].x4 = posicaoPersonagem[1].x4;
		bomba_x = person_x;
		bomba_z = person_z;
	} else if (bomba) {
		glPushMatrix();
		glTranslatef (bomba_x, 1.2, bomba_z);
		glColor3d(0, 0, 0);
		glutSolidSphere(0.1, 64, 64);
		glPopMatrix();
	}
}

void sumirExplosao(int value) {
	if (exploda) {
		int i, j;
		bomba = false;

		if (posicoes[posicaoBomba[0].x1][posicaoBomba[0].x2] != 1) {
			posicoes[posicaoBomba[0].x1][posicaoBomba[0].x2] = 0;
		}

		if (posicoes[posicaoBomba[0].x3][posicaoBomba[0].x4] != 1) {
			posicoes[posicaoBomba[0].x3][posicaoBomba[0].x4] = 0;
		}

		if (posicoes[posicaoBomba[1].x1][posicaoBomba[1].x2] != 1) {
			posicoes[posicaoBomba[1].x1][posicaoBomba[1].x2] = 0;
		}

		if (posicoes[posicaoBomba[1].x3][posicaoBomba[1].x4] != 1) {
			posicoes[posicaoBomba[1].x3][posicaoBomba[1].x4] = 0;
		}


		for (i = 1; i < tamanho_explosao + 1; i++) {
			if (posicoes[posicaoBomba[0].x1][posicaoBomba[0].x2 + i * 2] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[0].x1][posicaoBomba[0].x2 + i * 2] = 0;
			}

			if (posicoes[posicaoBomba[0].x3][posicaoBomba[0].x4 + i * 2] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[0].x3][posicaoBomba[0].x4 + i * 2] = 0;
			}

			if (posicoes[posicaoBomba[1].x1][posicaoBomba[1].x2 + i * 2] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[1].x1][posicaoBomba[1].x2 + i * 2] = 0;
			}

			if (posicoes[posicaoBomba[1].x3][posicaoBomba[1].x4 + i * 2] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[1].x3][posicaoBomba[1].x4 + i * 2] = 0;
			}
			blocosDestrutiveis[posicaoBomba[0].x1 / 2][(posicaoBomba[0].x2 + i * 2) / 2] = false;
			blocosDestrutiveis[posicaoBomba[1].x1 / 2][(posicaoBomba[1].x2 + i * 2) / 2] = false;
		}
		for (i = tamanho_explosao; i > 0; i--) {
			if (posicoes[posicaoBomba[0].x1][posicaoBomba[0].x2 - i * 2] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[0].x1][posicaoBomba[0].x2 - i * 2] = 0;
			}
			if (posicoes[posicaoBomba[0].x3][posicaoBomba[0].x4 - i * 2] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[0].x3][posicaoBomba[0].x4 - i * 2] = 0;
			}
			if (posicoes[posicaoBomba[1].x1][posicaoBomba[1].x2 - i * 2] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[1].x1][posicaoBomba[1].x2 - i * 2] = 0;
			}
			if (posicoes[posicaoBomba[1].x3][posicaoBomba[1].x4 - i * 2] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[1].x3][posicaoBomba[1].x4 - i * 2] = 0;
			}
			blocosDestrutiveis[posicaoBomba[0].x1 / 2][(posicaoBomba[0].x4 - i * 2) / 2] = false;
			blocosDestrutiveis[posicaoBomba[1].x1 / 2][(posicaoBomba[1].x4 - i * 2) / 2] = false;
		}
		for (j = 1; j < tamanho_explosao + 1; j++) {
			if (posicoes[posicaoBomba[0].x1 + j * 2][posicaoBomba[0].x2] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[0].x1 + j * 2][posicaoBomba[0].x2] = 0;
			}
			if (posicoes[posicaoBomba[0].x3 + j * 2][posicaoBomba[0].x4] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[0].x3 + j * 2][posicaoBomba[0].x4] = 0;
			}
			if (posicoes[posicaoBomba[1].x1 + j * 2][posicaoBomba[1].x2] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[1].x1 + j * 2][posicaoBomba[1].x2] = 0;
			}
			if (posicoes[posicaoBomba[1].x3 + j * 2][posicaoBomba[1].x4] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[1].x3 + j * 2][posicaoBomba[1].x4] = 0;
			}
			blocosDestrutiveis[(posicaoBomba[0].x1 + j * 2) / 2][(posicaoBomba[0].x2) / 2] = false;

		}
		for (j = tamanho_explosao; j > 0; j--) {
			if (posicoes[posicaoBomba[0].x1 - j * 2][posicaoBomba[0].x2] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[0].x1 - j * 2][posicaoBomba[0].x2] = 0;
			}
			if (posicoes[posicaoBomba[0].x3 - j * 2][posicaoBomba[0].x4] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[0].x3 - j * 2][posicaoBomba[0].x4] = 0;
			}
			if (posicoes[posicaoBomba[1].x1 - j * 2][posicaoBomba[1].x2] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[1].x1 - j * 2][posicaoBomba[1].x2] = 0;
			}
			if (posicoes[posicaoBomba[1].x3 - j * 2][posicaoBomba[1].x4] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[1].x3 - j * 2][posicaoBomba[1].x4] = 0;
			}
			blocosDestrutiveis[(posicaoBomba[1].x1 - j * 2) / 2][(posicaoBomba[1].x2) / 2] = false;
		}
		exploda = false;

		glutPostRedisplay();
	}
}

void explodirBomba(int value) {
	if (bomba) {
		exploda = true;
		glutTimerFunc(1000, sumirExplosao, 0);
		glutPostRedisplay();
	}
}

void explosao() {
	if (exploda) {
		int i, j;
		glPushMatrix();
		glColor3d(1, 1, 0);
		glTranslatef(bomba_x, 1.2, bomba_z);
		glutSolidCube(0.2);
		glPopMatrix();

		if (posicoes[posicaoBomba[0].x1][posicaoBomba[0].x2] != 1) {
			posicoes[posicaoBomba[0].x1][posicaoBomba[0].x2] = 3;
		}

		if (posicoes[posicaoBomba[0].x3][posicaoBomba[0].x4] != 1) {
			posicoes[posicaoBomba[0].x3][posicaoBomba[0].x4] = 3;
		}

		if (posicoes[posicaoBomba[1].x1][posicaoBomba[1].x2] != 1) {
			posicoes[posicaoBomba[1].x1][posicaoBomba[1].x2] = 3;
		}

		if (posicoes[posicaoBomba[1].x3][posicaoBomba[1].x4] != 1) {
			posicoes[posicaoBomba[1].x3][posicaoBomba[1].x4] = 3;
		}

		for (i = 1; i < tamanho_explosao + 1; i++) {
			if (posicoes[posicaoBomba[0].x1][posicaoBomba[0].x2 + i * 2] == 1) {
				break;
			} else if (posicoes[posicaoBomba[0].x3][posicaoBomba[0].x4 + i * 2] == 1) {
				break;
			} else 	if (posicoes[posicaoBomba[1].x1][posicaoBomba[1].x2 + i * 2] == 1) {
				break;
			} else if (posicoes[posicaoBomba[1].x3][posicaoBomba[1].x4 + i * 2] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[0].x1][posicaoBomba[0].x2 + i * 2] = 3;
				posicoes[posicaoBomba[0].x3][posicaoBomba[0].x4 + i * 2] = 3;
				posicoes[posicaoBomba[1].x1][posicaoBomba[1].x2 + i * 2] = 3;
				posicoes[posicaoBomba[1].x3][posicaoBomba[1].x4 + i * 2] = 3;
			}

			glPushMatrix();
			glColor3d(1, 1, 0);
			glTranslatef(bomba_x + 0.2 * i, 1.2, bomba_z);
			glutSolidCube(0.2);
			glPopMatrix();
		}
		for (i = tamanho_explosao; i > 0; i--) {
			if (posicoes[posicaoBomba[0].x1][posicaoBomba[0].x2 - i * 2] == 1) {
				break;
			} else if (posicoes[posicaoBomba[0].x3][posicaoBomba[0].x4 - i * 2] == 1) {
				break;
			} else if (posicoes[posicaoBomba[1].x1][posicaoBomba[1].x2 - i * 2] == 1) {
				break;
			} else if (posicoes[posicaoBomba[1].x3][posicaoBomba[1].x4 - i * 2] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[0].x1][posicaoBomba[0].x2 - i * 2] = 3;
				posicoes[posicaoBomba[0].x3][posicaoBomba[0].x4 - i * 2] = 3;
				posicoes[posicaoBomba[1].x1][posicaoBomba[1].x2 - i * 2] = 3;
				posicoes[posicaoBomba[1].x3][posicaoBomba[1].x4 - i * 2] = 3;
			}

			glPushMatrix();
			glColor3d(1, 1, 0);
			glTranslatef (bomba_x - 0.2 * i, 1.2, bomba_z);
			glutSolidCube(0.2);
			glPopMatrix();
		}
		for (j = 1; j < tamanho_explosao + 1; j++) {
			if (posicoes[posicaoBomba[0].x1 + j * 2][posicaoBomba[0].x2] == 1) {
				break;
			} else if (posicoes[posicaoBomba[0].x3 + j * 2][posicaoBomba[0].x4] == 1) {
				break;
			} else if (posicoes[posicaoBomba[1].x1 + j * 2][posicaoBomba[1].x2] == 1) {
				break;
			} else if (posicoes[posicaoBomba[1].x3 + j * 2][posicaoBomba[1].x4] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[0].x1 + j * 2][posicaoBomba[0].x2] = 3;
				posicoes[posicaoBomba[0].x3 + j * 2][posicaoBomba[0].x4] = 3;
				posicoes[posicaoBomba[1].x1 + j * 2][posicaoBomba[1].x2] = 3;
				posicoes[posicaoBomba[1].x3 + j * 2][posicaoBomba[1].x4] = 3;
			}

			glPushMatrix();
			glColor3d(1, 1, 0);
			glTranslatef (bomba_x, 1.2, bomba_z + 0.2 * j);
			glutSolidCube(0.2);
			glPopMatrix();
		}
		for (j = tamanho_explosao; j > 0; j--) {
			if (posicoes[posicaoBomba[0].x1 - j * 2][posicaoBomba[0].x2] == 1) {
				break;
			} else if (posicoes[posicaoBomba[0].x3 - j * 2][posicaoBomba[0].x4] == 1) {
				break;
			} else if (posicoes[posicaoBomba[1].x1 - j * 2][posicaoBomba[1].x2] == 1) {
				break;
			} else if (posicoes[posicaoBomba[1].x3 - j * 2][posicaoBomba[1].x4] == 1) {
				break;
			} else {
				posicoes[posicaoBomba[0].x1 - j * 2][posicaoBomba[0].x2] = 3;
				posicoes[posicaoBomba[0].x3 - j * 2][posicaoBomba[0].x4] = 3;
				posicoes[posicaoBomba[1].x1 - j * 2][posicaoBomba[1].x2] = 3;
				posicoes[posicaoBomba[1].x3 - j * 2][posicaoBomba[1].x4] = 3;
			}

			glPushMatrix();
			glColor3d(1, 1, 0);
			glTranslatef (bomba_x, 1.2, bomba_z - 0.2 * j);
			glutSolidCube(0.2);
			glPopMatrix();
		}
	}
}
