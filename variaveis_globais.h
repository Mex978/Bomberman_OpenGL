// Personagens -------------------------------------------------
struct tipoPosicao {
	int x1, x2, x3, x4;
};
const float x_personagem_min = 1.35;
const float z_personagem_min = 1.4;
const float x_personagem_max = 4.5;
const float z_personagem_max = 4.55;
static float person_x = x_personagem_min;
static float person_z = z_personagem_min;
static vector<tipoPosicao> posicaoPersonagem;
// -------------------------------------------------------------

// Bomba -------------------------------------------------------
static bool bomba = false;
static float bomba_x = 0, bomba_z = 0;
static int tamanho_explosao = 1;
static bool exploda = false;
static vector<tipoPosicao> posicaoBomba;
// -------------------------------------------------------------

// Iluminacao --------------------------------------------------
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
// -------------------------------------------------------------

// Mapa --------------------------------------------------------
static vector<vector<int> > posicoes;
static vector< vector<bool> > blocosDestrutiveis;
// -------------------------------------------------------------
