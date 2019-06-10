// 0 - negativo | 1 - positivo
bool movimentar(string eixo, int orientacao) {
	if (eixo == "x") {
		if (orientacao == 0) {
			if (posicoes[posicaoPersonagem[0].x1][posicaoPersonagem[0].x2 - 1] == 1 ||
					posicoes[posicaoPersonagem[0].x1][posicaoPersonagem[0].x2 - 1] == 2)
				return false;
			else if (posicoes[posicaoPersonagem[1].x1][posicaoPersonagem[1].x2 - 1] == 1 ||
					 posicoes[posicaoPersonagem[1].x1][posicaoPersonagem[1].x2 - 1] == 2)
				return false;
			posicaoPersonagem[0].x2 -= 1;
			posicaoPersonagem[0].x4 -= 1;
			posicaoPersonagem[1].x2 -= 1;
			posicaoPersonagem[1].x4 -= 1;
		} else if (orientacao == 1) {
			if (posicoes[posicaoPersonagem[0].x3][posicaoPersonagem[0].x4 + 1] == 1 ||
					posicoes[posicaoPersonagem[0].x3][posicaoPersonagem[0].x4 + 1] == 2)
				return false;
			else if (posicoes[posicaoPersonagem[1].x3][posicaoPersonagem[1].x4 + 1] == 1 ||
					 posicoes[posicaoPersonagem[1].x3][posicaoPersonagem[1].x4 + 1] == 2)
				return false;
			posicaoPersonagem[0].x2 += 1;
			posicaoPersonagem[0].x4 += 1;
			posicaoPersonagem[1].x2 += 1;
			posicaoPersonagem[1].x4 += 1;
		}
	} else if (eixo == "z") {
		if (orientacao == 0) {
			if (posicoes[posicaoPersonagem[0].x1 - 1][posicaoPersonagem[0].x2] == 1 ||
					posicoes[posicaoPersonagem[0].x1 - 1][posicaoPersonagem[0].x2] == 2)
				return false;
			else if (posicoes[posicaoPersonagem[0].x3 - 1][posicaoPersonagem[0].x4] == 1 ||
					 posicoes[posicaoPersonagem[0].x3 - 1][posicaoPersonagem[0].x4] == 2)
				return false;
			posicaoPersonagem[0].x1 -= 1;
			posicaoPersonagem[0].x3 -= 1;
			posicaoPersonagem[1].x1 -= 1;
			posicaoPersonagem[1].x3 -= 1;
		} else if (orientacao == 1) {
			if (posicoes[posicaoPersonagem[1].x1 + 1][posicaoPersonagem[1].x2] == 1 ||
					posicoes[posicaoPersonagem[1].x1 + 1][posicaoPersonagem[1].x2] == 2)
				return false;
			else if (posicoes[posicaoPersonagem[1].x3 + 1][posicaoPersonagem[1].x4] == 1 ||
					 posicoes[posicaoPersonagem[1].x3 + 1][posicaoPersonagem[1].x4] == 2)
				return false;
			posicaoPersonagem[0].x1 += 1;
			posicaoPersonagem[0].x3 += 1;
			posicaoPersonagem[1].x1 += 1;
			posicaoPersonagem[1].x3 += 1;
		}
	}
	return true;
}

void desenharPersonagem() {
	if (posicoes[posicaoPersonagem[0].x1][posicaoPersonagem[0].x2] == 3) {
		MessageBox(NULL, "GameOver", "GameOver", MB_OK | MB_ICONEXCLAMATION);
		exit(0);
	} else if (posicoes[posicaoPersonagem[0].x3][posicaoPersonagem[0].x4] == 3) {
		MessageBox(NULL, "GameOver", "GameOver", MB_OK | MB_ICONEXCLAMATION);
		exit(0);
	} else if (posicoes[posicaoPersonagem[1].x1][posicaoPersonagem[1].x2] == 3) {
		MessageBox(NULL, "GameOver", "GameOver", MB_OK | MB_ICONEXCLAMATION);
		exit(0);
	} else if (posicoes[posicaoPersonagem[1].x3][posicaoPersonagem[1].x4] == 3) {
		MessageBox(NULL, "GameOver", "GameOver", MB_OK | MB_ICONEXCLAMATION);
		exit(0);
	}

	glPushMatrix();
	glTranslatef (person_x, 1.2, person_z);
	glColor3d(0, 1, 0);
	glutSolidSphere(0.1, 64, 64);
	glPopMatrix();
}

void inicializarPosicoes() {
	tipoPosicao pos1 = {2, 2, 2, 3};
	tipoPosicao pos2 = {3, 2, 3, 3};
	posicaoPersonagem.push_back(pos1);
	posicaoPersonagem.push_back(pos2);

	tipoPosicao bomba_pos1 = {0, 0, 0, 0};
	tipoPosicao bomba_pos2 = {0, 0, 0, 0};
	posicaoBomba.push_back(bomba_pos1);
	posicaoBomba.push_back(bomba_pos2);

	int i, j;
	for (i = 0; i < 38; i++) {
		vector<int> vetorInt;
		posicoes.push_back(vetorInt);
		for (j = 0; j < 38; j++) {
			posicoes[i].push_back(0);
		}
	}

	for (i = 0; i < 18; i++) {
		vector<bool> vetorBool;
		blocosDestrutiveis.push_back(vetorBool);
		for (j = 0; j < 18; j++) {
			blocosDestrutiveis[i].push_back(false);
		}
	}

}

void iluminacao (void) {
	const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
	const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat light_position[] = { 6.0f, 5.0f, 5.0f, 0.0f };

	const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
	const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
	const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat high_shininess[] = { 100.0f };

	glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);
}

void resetMatrizes() {
	int i, j;
	for (i = 0; i < 38; i++) {
		for (j = 0; j < 38; j++) {
			posicoes[i][j] = 0;
		}
	}

	for (i = 0; i < 18; i++) {
		for (j = 0; j < 18; j++) {
			blocosDestrutiveis[i][j] = false;
		}
	}
}


