void desenharBlocosIndestrutiveis() {
	int i, j, aux_i = 0, aux_j;
	for (i = 0; i < 19; i++) {
		aux_j = 0;
		if (i == 0) {
			for (j = 0; j < 19; j++) {
				posicoes[aux_i][aux_j] = 1;
				posicoes[aux_i][aux_j + 1] = 1;
				posicoes[aux_i + 1][aux_j] = 1;
				posicoes[aux_i + 1][aux_j + 1] = 1;
				aux_j += 2;

				glPushMatrix();
				glTranslatef (1.15 + j * 0.2, 1.2, 1.2);
				glColor3d(0, 0, 1);
				glutSolidCube(0.2);
				glPopMatrix();

			}
		} else if (i == 18) {
			for (j = 0; j < 19; j++) {
				posicoes[aux_i][aux_j] = 1;
				posicoes[aux_i][aux_j + 1] = 1;
				posicoes[aux_i + 1][aux_j] = 1;
				posicoes[aux_i + 1][aux_j + 1] = 1;
				aux_j += 2;

				glPushMatrix();
				glTranslatef (1.15 + j * 0.2, 1.2, 4.8);
				glColor3d(0, 0, 1);
				glutSolidCube(0.2);
				glPopMatrix();
			}
		} else if (i % 2 == 0) {
			for (j = 0; j < 19; j++) {
				if (j % 2 == 0) {
					glPushMatrix();
					glTranslatef (1.15 + j * 0.2, 1.2, 1.2 + i * 0.2);
					glColor3d(0, 0, 1);
					glutSolidCube(0.2);
					glPopMatrix();

					posicoes[aux_i][aux_j] = 1;
					posicoes[aux_i][aux_j + 1] = 1;
					posicoes[aux_i + 1][aux_j] = 1;
					posicoes[aux_i + 1][aux_j + 1] = 1;
					aux_j += 2;
				} else {
					aux_j += 2;
				}
			}
		} else {
			glPushMatrix();
			glTranslatef (1.15, 1.2, 1.2 + i * 0.2);
			glColor3d(0, 0, 1);
			glutSolidCube(0.2);
			glPopMatrix();
			posicoes[aux_i][0] = 1;
			posicoes[aux_i][1] = 1;
			posicoes[aux_i + 1][0] = 1;
			posicoes[aux_i + 1][1] = 1;


			glPushMatrix();
			glTranslatef (4.75, 1.2, 1.2 + i * 0.2);
			glColor3d(0, 0, 1);
			glutSolidCube(0.2);
			glPopMatrix();
			posicoes[aux_i][36] = 1;
			posicoes[aux_i][37] = 1;
			posicoes[aux_i + 1][36] = 1;
			posicoes[aux_i + 1][37] = 1;
		}
		aux_i += 2;
	}
}

void desenharBlocosDestrutiveis() {
	int i, j;
	for (i = 1; i < 18; i++) {
		for (j = 1; j < 18; j++) {
			if (blocosDestrutiveis[i][j]) {
				glPushMatrix();
				glTranslatef (1.15 + j * 0.2, 1.2, 1.2 + i * 0.2);
				glColor3d(0.667, 0.333, 0.0);
				glutSolidCube(0.2);
				glPopMatrix();
			}
		}
	}
}

void preencherMatrizBlocosDestrutiveis() {
	int i, j;
	for (i = 1; i < 18; i++) {
		if (i == 1) {
			for (j = 3; j < 18; j++) {
				if (rand() % 2 == 0) {
					blocosDestrutiveis[i][j] = true;
					posicoes[i * 2][j * 2] = 2;
					posicoes[i * 2][j * 2 + 1] = 2;
					posicoes[i * 2 + 1][j * 2] = 2;
					posicoes[i * 2 + 1][j * 2 + 1] = 2;
				}
			}
		} else if (i == 2) {
			for (j = 3; j < 18; j++) {
				if (j % 2 != 0) {
					if (rand() % 2 == 0) {
						blocosDestrutiveis[i][j] = true;
						posicoes[i * 2][j * 2] = 2;
						posicoes[i * 2][j * 2 + 1] = 2;
						posicoes[i * 2 + 1][j * 2] = 2;
						posicoes[i * 2 + 1][j * 2 + 1] = 2;
					}
				}
			}
		} else if (i % 2 != 0) {
			for (j = 1; j < 18; j++) {
				if (rand() % 2 == 0) {
					blocosDestrutiveis[i][j] = true;
					posicoes[i * 2][j * 2] = 2;
					posicoes[i * 2][j * 2 + 1] = 2;
					posicoes[i * 2 + 1][j * 2] = 2;
					posicoes[i * 2 + 1][j * 2 + 1] = 2;
				}
			}
		} else if (i % 2 == 0) {
			for (j = 1; j < 18; j++) {
				if (j % 2 != 0) {
					if (rand() % 2 == 0) {
						blocosDestrutiveis[i][j] = true;
						posicoes[i * 2][j * 2] = 2;
						posicoes[i * 2][j * 2 + 1] = 2;
						posicoes[i * 2 + 1][j * 2] = 2;
						posicoes[i * 2 + 1][j * 2 + 1] = 2;
					}
				}
			}
		}
	}
}
