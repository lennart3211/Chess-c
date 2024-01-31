#include <raylib.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define SQUARE_SIZE (SCREEN_WIDTH / 8)

typedef enum {
    PAWN = 0,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
} PieceType;

typedef struct {
    PieceType type;
    int color;
    Texture2D *texture;
    Vector2D position;
} Piece;

typedef struct {
    Rectangle squares[8][8];
    Piece pieces[32];
} Board;

typedef struct {
    Texture2D pawn;
    Texture2D rook;
    Texture2D knight;
    Texture2D bishop;
    Texture2D queen;
    Texture2D king;
} PieceTextures;

Board SetupBoard();
PieceTextures LoadPieceTextures();
void DrawBoard(Board *board);
void DrawPieces(Piece **pieces, int size);
void UnloadPieces(Piece **pieces);

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Chess");
    SetTargetFPS(60);

    PieceTextures textures = LoadPieceTextures();
    Board board = SetupBoard(&board);

    while (!WindowShouldClose()) {
        

        BeginDrawing(); {
            DrawBoard(board);
            DrawPieces(board.pieces);
        }
    }
}

Board SetupBoard(PieceTextures *textures) {
    Board board;

    for (size_t i = 0; i < 8; ++i) {
        for (size_t j = 0; j < 8; ++j) {
            board.squares[i][j] = (Rectangle){ SQUARE_SIZE * i, SQUARE_SIZE * j, SQUARE_SIZE, SQUARE_SIZE };
        }
    }

    board.pieces = {
        {PAWN,   0, &textures->pawn,   { 1*SQUARE_SIZE, 0*SQUARE_SIZE }}, {PAWN,   0, &textures->pawn,   { 1*SQUARE_SIZE, 1*SQUARE_SIZE }}, {PAWN,   0, &textures->pawn,   { 1*SQUARE_SIZE, 2*SQUARE_SIZE }}, {PAWN,   0, &textures->pawn,   { 1*SQUARE_SIZE, 3*SQUARE_SIZE }},
        {PAWN,   0, &textures->pawn,   { 1*SQUARE_SIZE, 4*SQUARE_SIZE }}, {PAWN,   0, &textures->pawn,   { 1*SQUARE_SIZE, 5*SQUARE_SIZE }}, {PAWN,   0, &textures->pawn,   { 1*SQUARE_SIZE, 6*SQUARE_SIZE }}, {PAWN,   0, &textures->pawn,   { 1*SQUARE_SIZE, 7*SQUARE_SIZE }},
        {PAWN,   1, &textures->pawn,   { 1*SQUARE_SIZE, 0*SQUARE_SIZE }}, {PAWN,   1, &textures->pawn,   { 6*SQUARE_SIZE, 1*SQUARE_SIZE }}, {PAWN,   1, &textures->pawn,   { 6*SQUARE_SIZE, 2*SQUARE_SIZE }}, {PAWN,   1, &textures->pawn,   { 6*SQUARE_SIZE, 3*SQUARE_SIZE }},
        {PAWN,   1, &textures->pawn,   { 6*SQUARE_SIZE, 4*SQUARE_SIZE }}, {PAWN,   1, &textures->pawn,   { 6*SQUARE_SIZE, 5*SQUARE_SIZE }}, {PAWN,   1, &textures->pawn,   { 6*SQUARE_SIZE, 6*SQUARE_SIZE }}, {PAWN,   1, &textures->pawn,   { 6*SQUARE_SIZE, 7*SQUARE_SIZE }},
        {ROOK,   0, &textures->rook,   { 0*SQUARE_SIZE, 0*SQUARE_SIZE }}, {ROOK,   0, &textures->rook,   { 0*SQUARE_SIZE, 7*SQUARE_SIZE }}, {ROOK,   1, &textures->rook,   { 7*SQUARE_SIZE, 0*SQUARE_SIZE }}, {ROOK,   1, &textures->rook,   { 7*SQUARE_SIZE, 7*SQUARE_SIZE }},
        {KNIGHT, 0, &textures->knight, { 0*SQUARE_SIZE, 0*SQUARE_SIZE }}, {KNIGHT, 0, &textures->knight, { 0*SQUARE_SIZE, 0*SQUARE_SIZE }}, {KNIGHT, 1, &textures->knight, { 0*SQUARE_SIZE, 0*SQUARE_SIZE }}, {KNIGHT, 1, &textures->knight, { 7*SQUARE_SIZE, 6*SQUARE_SIZE }},
        {BISHOP, 0, &textures->bishop, { 0*SQUARE_SIZE, 0*SQUARE_SIZE }}, {BISHOP, 0, &textures->bishop, { 0*SQUARE_SIZE, 0*SQUARE_SIZE }}, {BISHOP, 1, &textures->bishop, { 0*SQUARE_SIZE, 0*SQUARE_SIZE }}, {BISHOP, 1, &textures->bishop, { 7*SQUARE_SIZE, 5*SQUARE_SIZE }},
        {QUEEN,  0, &textures->queen,  { 0*SQUARE_SIZE, 0*SQUARE_SIZE }}, {QUEEN,  1, &textures->queen,  { 0*SQUARE_SIZE, 0*SQUARE_SIZE }}, {KING,   0, &textures->king,   { 0*SQUARE_SIZE, 0*SQUARE_SIZE }}, {KING,   1, textures->king,    { 0*SQUARE_SIZE, 0*SQUARE_SIZE }}
    }

    return board;
}

PieceTextures LoadPieceTextures() {
    PieceTextures textures;

    textures.pawn   = LoadTexture("resources/pawn.png");
    textures.rook   = LoadTexture("resources/rook.png");
    textures.knight = LoadTexture("resources/knight.png");
    textures.bishop = LoadTexture("resources/bishop.png");
    textures.queen  = LoadTexture("resources/queen.png");
    textures.king   = LoadTexture("resources/king.png");

    return textures;
}


void UnloadPieceTextures(PieceTextures textures) {
    UnloadTexture(textures.pawn);
    UnloadTexture(textures.rook);
    UnloadTexture(textures.knight);
    UnloadTexture(textures.bishop);
    UnloadTexture(textures.queen);
    UnloadTexture(textures.king);
}

void DrawBoard(Board *board) {
    for (size_t i = 0; i < 16; ++i) {
        for (size_t j = 0; j < 16; ++j) {
            DrawRectangleRec(board->squares[i][j]);
        }
    }
}

void DrawPieces(Piece **pieces, int size) {
    for (size_t i = 0; i < n; ++i) {
        DrawTexture(pieces[i]->texture, pieces[i]->position.x, pieces[i]->position.y, pieces[i]->color ? WHITE : BLACK);
    }
}
