#include<iostream>
#include<exception>
using namespace std;
#define NOT_AVIABLE 0
#define EMPTY_SPACE 1
#define WHITE_TAB 2
#define BLACK_TAB 3

#define WHITE_QUEEN 4
#define BLACK_QUEEN 5
#define ROWS 8
#define COLUMNS 8

int intro();
void intercambio(int board[ROWS][COLUMNS], int OriginRow, int OriginColumn, int DestinationRow, int DestinationColumn);
int turno(int board[ROWS][COLUMNS], int player, int OriginRow, int OriginColumn, int DestinationRow, int DestinationColumn);
char simbolos(int i);
void tablero(int board[ROWS][COLUMNS], int ficha_turno);

int intro() {
    int op = 0;
    do {
        do {
            //system("cls");
            cout << "\033[2J\033[1;1H";
            cout << "\t\t_________________________" << endl;
            cout << "\t\t                                                                    " << endl;
            cout << "\t\t UNIVERSIDAD EUROPEA - ESCUELA DE ARQUITECTURA, INGENIERIA Y DISEÑO" << endl;
            cout << "\t\t_________________________" << endl << endl;
            cout << "\t\tProf.:Christian Sucuzhanay.                  Alumno : Daniel Sabbagh. " << endl << endl << endl;
            cout << "\t\t              << JUEGO DE LAS DAMAS ESPAÑOLAS >>" << endl << endl;
            cout << "\t\t\t    * Seleccione una opcion del menu [ 0-2] *" << endl << endl;
            cout << "\t\t\t\t  [ 1 ] Ver reglas del juego " << endl;
            cout << "\t\t\t\t  [ 2 ] Jugar" << endl;
            cout << "\t\t\t\t  [ 0 ] SALIR" << endl << endl;
            cout << "\t\t\t              Ingrese su opcion : ";
            cin >> op;
        } while (op<0 || op>2);
        switch (op) {
            case 1:
                system("cls");
                cout << "\t\t_________________________" << endl;
                cout << "\t\t                                                                    " << endl;
                cout << "\t\t UNIVERSIDAD EUROPEA - ESCUELA DE ARQUITECTURA, INGENIERIA Y DISEÑO" << endl;
                cout << "\t\t_________________________" << endl << endl;
                cout << "\t\tProf.:Christian Sucuzhanay.                  Alumno: Daniel Sabbgh. " << endl << endl << endl;
                cout << "\t\t            << REGLAS DEL JUEGO DE LAS DAMAS ESPAÑOLAS >>\n";
                cout << "\t\t           ----------------------------------------------\n\n";
                cout << "\t\t1.- Inician el juego las fichas blancas por defecto" << endl << endl;
                cout << "\t\t2.- Las fichas SOLO se mueven 1 casilla hacia ADELANTE y en DIAGONAL\n ";
                cout << "\t\t    excepto al comer FICHA que pueden saltar\n\n";
                cout << "\t\t3.- Las fichas SALTAN mas de una casilla  SOLO cuando haya una ficha\n ";
                cout << "\t\t    contaria y la siguiente este vacia\n\n ";
                cout << "\t\t4.- Si alcanzamos la ultima fila opuesta a nuestro turno con una ficha\n";
                cout << "\t\t    esta se convierte en dama\n\n ";
                cout << "\t\t5.- Las damas solo se pueden mover en diagonal pero pueden moverse tantas\n\n";
                cout << "\t\t    casillas como quieran, eso si, no pueden ni comer fichas propias, ni\n\n ";
                cout << "\t\t    dos fichas contrarias seguidas. Es decir, si se mueve N posiciones\n\n ";
                cout << "\t\t    en diagonal y se encuentra una ficha contraria, se la come y se queda\n\n ";
                cout << "\t\t    una posicion tras la ficha comida\n\n ";
                cout << "\t\t6.- Gana quien coma mas fichas \n\n";
                cout << "\t\t7.- Si pasan mas de 2 horas sin que nadie gane se declara EMPATE\n\n\n\n ";
                cout << "\t\t\t\t PULSE [ 0 ] para SALIR: ";
                cin >> op;
                intro();
            case 2:
                break;
            case 0:
                system("cls");
                abort();
        }
        return 0;
    } while (op != 0);
    abort();
}
void tablero(int board[ROWS][COLUMNS], int turno){
    int drawRows, drawCol;
    system("cls");
    cout << "\t\t_________________________" << endl;
    cout << "\t\t                                                                    " << endl;
    cout << "\t\t UNIVERSIDAD EUROPEA - ESCUELA DE ARQUITECTURA, INGENIERIA Y DISEÑO" << endl;
    cout << "\t\t_________________________" << endl << endl;
    cout << "\t\tProf.: Christian Sucuzhanay                  Alumno: Daniel Sabbagh." << endl << endl << endl;
    cout << "\t\t                << TABLERO DE LAS DAMAS ESPANOLAS >>" << endl << endl;
    cout << "\n\t\t\t\t     B = fichas BLANCAS";
    cout << "\n\t\t\t\t     N = fichas NEGRAS";
    cout << "\n\t\t\t\t     v = espacios VACIOS jugables";
    cout << "\n\t\t\t\t     w = fichas DAMAS BLANCAS";
    cout << "\n\t\t\t\t     b = fichas DAMAS NEGRAS";
    cout << "\n\n\t\t\t\t   +---+---+---+---+---+---+---+---+\n";
    for (drawRows = 0; drawRows < ROWS; ++drawRows)
    {
        cout << "\t\t\t\t" << drawRows + 1 << "  | ";
        for (drawCol = 0; drawCol < COLUMNS; ++drawCol)
        {
            cout << simbolos(board[drawRows][drawCol]) << " | ";

        }
        cout << "\n";
        cout << "\t\t\t\t   +---+---+---+---+---+---+---+---+\n";
    }
    cout << "\n\t\t\t\t     a   b   c   d   e   f   g   h\n\n\n";
}

int turno(int board[ROWS][COLUMNS], int player, int OriginRow, int OriginColumn, int DestinationRow, int DestinationColumn)
{
    int eatWhiteTab;
    int eatBlackTab;
    if ((OriginRow < 0 && ROWS <= OriginRow) && (OriginColumn < 0 && COLUMNS <= OriginColumn)) {
        cout << "\n Te saliste fuera del tablero!!\n";
        return -1;
    }if ((DestinationRow < 0 && ROWS <= DestinationRow) && (DestinationColumn < 0 && COLUMNS <= DestinationColumn)) {
        cout << "\n Te saliste fuera del tablero!!\n";
        return -1;
    }if (player == -1) {
        cout << "Ficha no valida";
        return -1;
    }if (board[DestinationRow][DestinationColumn] != EMPTY_SPACE) {
        cout << "\nSolo puedes mover a un espacios VACIOS!!";
        return -1;
    }if (player == WHITE_TAB) {
        if (OriginRow <= DestinationRow) {
            cout << "\nImposible mover hacia atras o quedarte en las misma posicion\n";
            return -1;
        }
    }if(player == BLACK_TAB){
        if (OriginRow >= DestinationRow) {
            cout << "\nImposible mover hacia atras o quedarte en las misma posicion\n";
            return -1;
        }
    }if ((player == WHITE_TAB) || (player == BLACK_TAB)) {
        if (OriginRow - DestinationRow == -1 || OriginRow - DestinationRow == 1) {
            if (OriginColumn - DestinationColumn == 1 || OriginColumn - DestinationColumn == -1) {
                intercambio(board, OriginRow, OriginColumn, DestinationRow, DestinationColumn);
                return 0;
            }
        }if (OriginRow - DestinationRow == -2 || OriginRow - DestinationRow == 2) {
            if (OriginColumn - DestinationColumn == -2 || OriginColumn - DestinationColumn == 2) {
                if (OriginRow < DestinationRow) {
                    eatWhiteTab = OriginRow + 1;
                }else {
                    eatWhiteTab = OriginRow - 1;
                }if (OriginColumn < DestinationColumn) {
                    eatBlackTab = OriginColumn + 1;
                }else {
                    eatBlackTab = OriginColumn - 1;
                }if (player == WHITE_TAB){
                    if ((board[eatWhiteTab][eatBlackTab] != BLACK_TAB) && (board[eatWhiteTab][eatBlackTab] != BLACK_QUEEN)) {
                        cout << "\nSolo puedes saltar si te comes una ficha negra\n";
                        return -1;
                    }
                }if (player == BLACK_TAB) {
                    if ((board[eatWhiteTab][eatBlackTab] != WHITE_TAB) && (board[eatWhiteTab][eatBlackTab] != WHITE_QUEEN)) {
                        cout << "\nSolo puedes saltar si te comes una ficha blanca\n";
                        return -1;
                    }
                }
                board[eatWhiteTab][eatBlackTab] = 1;
                intercambio(board, OriginRow, OriginColumn, DestinationRow, DestinationColumn);
                return 0;
            }
        }
    }
    if ((player == WHITE_QUEEN) || (player == BLACK_QUEEN)) {
        if ((OriginRow + OriginColumn) == (DestinationRow + DestinationColumn)) {
            if ((OriginRow > DestinationRow) && (OriginColumn < DestinationColumn)) {
                for (int i = OriginRow-1, j = OriginColumn+1; i >= DestinationRow && j <= DestinationColumn; i--, j++) {
                    if (player == WHITE_QUEEN) {
                        if ((board[i][j] == WHITE_TAB)||(board[i][j] == WHITE_QUEEN)) {
                            cout << "No tienes permitdo hacer eso" << endl;
                            return -1;
                        }if (((board[i][j] == BLACK_TAB) && (board[i - 1][j + 1] == BLACK_TAB))||((board[i][j] == BLACK_QUEEN)&&(board[i - 1][j + 1] == BLACK_QUEEN))) {

                            cout << "Tienes doble ficha negra, no puedes hacer eso" << endl;
                            return -1;
                        }if (((board[i][j] == BLACK_TAB)||(board[i][j] == BLACK_QUEEN))&&(board[i - 1][j + 1] == EMPTY_SPACE)) {
                            board[i][j] = EMPTY_SPACE;
                            intercambio(board, OriginRow, OriginColumn, i - 1, j + 1);
                            return 0;
                        }if ((i == DestinationRow) && (j == DestinationColumn)) {

                            intercambio(board, OriginRow, OriginColumn, DestinationRow, DestinationColumn);
                            return 0;
                        }
                    }else {
                        if ((board[i][j] == BLACK_TAB) || (board[i][j] == BLACK_QUEEN)) {
                            cout << "No puedes pasar fichas negras" << endl;
                            return -1;
                        }if (((board[i][j] == WHITE_TAB) && (board[i - 1][j + 1] == WHITE_TAB))||((board[i][j] == WHITE_QUEEN)&&(board[i - 1][j + 1] == WHITE_QUEEN))) {

                            cout << "Tienes doble ficha blanca, no puedes hacer eso" << endl;
                            return -1;
                        }if (((board[i][j] == WHITE_TAB)||(board[i][j] == WHITE_QUEEN)) && (board[i - 1][j + 1] == EMPTY_SPACE)) {
                            board[i][j] = EMPTY_SPACE;
                            intercambio(board, OriginRow, OriginColumn, i - 1, j + 1);
                            return 0;
                        }if ((i == DestinationRow) && (j == DestinationColumn)) {
                            intercambio(board, OriginRow, OriginColumn, DestinationRow, DestinationColumn);
                            return 0;
                        }
                    }
                }
            }
            if ((OriginRow < DestinationRow) && (OriginColumn > DestinationColumn)) {
                for (int i = OriginRow+1, j = OriginColumn-1; i <= DestinationRow && j >= DestinationColumn; i++, j--) {
                    if (player == WHITE_QUEEN) {
                        if ((board[i][j] == WHITE_TAB) || (board[i][j] == WHITE_QUEEN)) {
                            cout << "No puedes hacerlo" << endl;
                            return -1;
                        }if (((board[i][j] == BLACK_TAB) && (board[i + 1][j - 1] == BLACK_TAB)) || ((board[i][j] == BLACK_QUEEN) && (board[i + 1][j - 1] == BLACK_QUEEN))) {

                            cout << "Tienes doble ficha negra, no puedes hacer eso" << endl;
                            return -1;
                        }if (((board[i][j] == BLACK_TAB) || (board[i][j] == BLACK_QUEEN)) && (board[i + 1][j - 1] == EMPTY_SPACE)) {

                            board[i][j] = EMPTY_SPACE;
                            intercambio(board, OriginRow, OriginColumn, i + 1, j - 1);
                            return 0;
                        }if ((i == DestinationRow) && (j == DestinationColumn)) {
                            intercambio(board, OriginRow, OriginColumn, DestinationRow, DestinationColumn);
                            return 0;
                        }
                    }else {
                        if ((board[i][j] == BLACK_TAB) || (board[i][j] == BLACK_QUEEN)) {
                            cout << "No puedes pasar fichas negras" << endl;
                            return -1;
                        }if (((board[i][j] == WHITE_TAB) && (board[i + 1][j - 1] == WHITE_TAB)) || ((board[i][j] == WHITE_QUEEN) && (board[i + 1][j - 1] == WHITE_QUEEN))) {
                            cout << "Tienes doble ficha blanca, no puedes hacer eso" << endl;
                            return -1;
                        }if (((board[i][j] == WHITE_TAB) || (board[i][j] == WHITE_QUEEN)) && (board[i + 1][j - 1] == EMPTY_SPACE)) {
                            board[i][j] = EMPTY_SPACE;
                            intercambio(board, OriginRow, OriginColumn, i + 1, j - 1);
                            return 0;
                        }if ((i == DestinationRow) && (j == DestinationColumn)) {
                            intercambio(board, OriginRow, OriginColumn, DestinationRow, DestinationColumn);
                            return 0;
                        }
                    }
                }
            }
        }
        if ((OriginRow - OriginColumn) == (DestinationRow - DestinationColumn)) {
            if ((OriginRow < DestinationRow) && (OriginColumn < DestinationColumn)) {
                for (int i = OriginRow+1, j = OriginColumn+1; i <= DestinationRow && j <= DestinationColumn; i++, j++) {
                    if (player == WHITE_QUEEN) {
                        if ((board[i][j] == WHITE_TAB)||(board[i][j] == WHITE_QUEEN)) {
                            cout << "No puedes pasar Fichas Blancas o Damas Blancas" << endl;
                            return -1;
                        }if (((board[i][j] == BLACK_TAB) && (board[i + 1][j + 1] == BLACK_TAB))||((board[i][j] == BLACK_QUEEN)&&(board[i + 1][j + 1] == BLACK_QUEEN))) {
                            cout << "Tienes doble ficha negra, no puedes hacer eso" << endl;
                            return -1;
                        }if (((board[i][j] == BLACK_TAB)||(board[i][j] == BLACK_QUEEN))&&(board[i + 1][j + 1] == EMPTY_SPACE)) {
                            board[i][j] = EMPTY_SPACE;
                            intercambio(board, OriginRow, OriginColumn, i + 1, j + 1);
                            return 0;
                        }if ((i == DestinationRow) && (j == DestinationColumn)) {
                            intercambio(board, OriginRow, OriginColumn, DestinationRow, DestinationColumn);
                            return 0;
                        }
                    }else {
                        if ((board[i][j] == BLACK_TAB) || (board[i][j] == BLACK_QUEEN)) {
                            cout << "No puedes pasar fichas negras" << endl;
                            return -1;
                        }if (((board[i][j] == WHITE_TAB) && (board[i + 1][j + 1] == WHITE_TAB))||((board[i][j] == WHITE_QUEEN)&&(board[i + 1][j + 1] == WHITE_QUEEN))) {
                            cout << "Tienes doble ficha blanca, no puedes hacer eso" << endl;
                            return -1;
                        }if (((board[i][j] == WHITE_TAB)||(board[i][j] == WHITE_QUEEN)) && (board[i + 1][j + 1] == EMPTY_SPACE)) {
                            board[i][j] = EMPTY_SPACE;
                            intercambio(board, OriginRow, OriginColumn, i + 1, j + 1);
                            return 0;
                        }if ((i == DestinationRow) && (j == DestinationColumn)) {
                            intercambio(board, OriginRow, OriginColumn, DestinationRow, DestinationColumn);
                            return 0;
                        }
                    }
                }
            }
            if ((OriginRow > DestinationRow) && (OriginColumn > DestinationColumn)) {
                for (int i = OriginRow-1, j = OriginColumn-1; i >= DestinationRow && j >= DestinationColumn; i--, j--) {
                    if (player == WHITE_QUEEN) {
                        if ((board[i][j] == WHITE_TAB)||(board[i][j] == WHITE_QUEEN)) {
                            cout << "No puedes pasar Fichas Blancas o Damas Blancas" << endl;
                            return -1;
                        }if (((board[i][j] == BLACK_TAB) && (board[i - 1][j - 1] == BLACK_TAB))||((board[i][j] == BLACK_QUEEN)&&(board[i - 1][j - 1] == BLACK_QUEEN))) {

                            cout << "Tienes doble ficha negra, no puedes hacer eso" << endl;
                            return -1;
                        }if (((board[i][j] == BLACK_TAB)||(board[i][j] == BLACK_QUEEN))&&(board[i - 1][j - 1] == EMPTY_SPACE)) {

                            board[i][j] = EMPTY_SPACE;
                            intercambio(board, OriginRow, OriginColumn, i - 1, j - 1);
                            return 0;
                        }if ((i == DestinationRow) && (j == DestinationColumn)) {

                            intercambio(board, OriginRow, OriginColumn, DestinationRow, DestinationColumn);
                            return 0;
                        }
                    }
                    else {
                        if ((board[i][j] == BLACK_TAB) || (board[i][j] == BLACK_QUEEN)) {
                            cout << "No puedes pasar fichas negras" << endl;
                            return -1;
                        }if (((board[i][j] == WHITE_TAB) && (board[i - 1][j - 1] == WHITE_TAB))||((board[i][j] == WHITE_QUEEN)&&(board[i - 1][j - 1] == WHITE_QUEEN))) {

                            cout << "Tienes doble ficha blanca, no puedes hacer eso" << endl;
                            return -1;
                        }if (((board[i][j] == WHITE_TAB)||(board[i][j] == WHITE_QUEEN)) && (board[i - 1][j - 1] == EMPTY_SPACE)) {

                            board[i][j] = EMPTY_SPACE;
                            intercambio(board, OriginRow, OriginColumn, i - 1, j - 1);
                            return 0;
                        }if ((i == DestinationRow) && (j == DestinationColumn)) {

                            intercambio(board, OriginRow, OriginColumn, DestinationRow, DestinationColumn);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "Las fichas solo se pueden mover en diagonal\n";
    return -1;
}

void intercambio(int board[ROWS][COLUMNS], int OriginRow, int OriginColumn, int DestinationRow, int DestinationColumn){
    int temp;

    if ((board[OriginRow][OriginColumn] == WHITE_TAB)&&(DestinationRow == 0)) {
        board[OriginRow][OriginColumn] = board[DestinationRow][DestinationColumn];
        board[DestinationRow][DestinationColumn] = WHITE_QUEEN;
    }
    else if ((board[OriginRow][OriginColumn] == BLACK_TAB) && (DestinationRow == 7)) {
        board[OriginRow][OriginColumn] = board[DestinationRow][DestinationColumn];
        board[DestinationRow][DestinationColumn] = BLACK_QUEEN;
    }
    else {
        temp = board[OriginRow][OriginColumn];
        board[OriginRow][OriginColumn] = board[DestinationRow][DestinationColumn];
        board[DestinationRow][DestinationColumn] = temp;
    }
}
char simbolos(int i){
    switch (i){
        case 0:
            return ' ';
        case 1:
            return 'v';
        case 2:
            return 'B';
        case 3:
            return 'N';
        case 4:
            return 'w';
        case 5:
            return 'b';
    }
    return ('?');
}
int main(){
    int OriginRow, DestinationRow;
    char OriginColumn, DestinationColumn;
    int board[ROWS][COLUMNS] = {
            { 0,3,0,3,0,3,0,3 },
            { 3,0,3,0,3,0,3,0 },
            { 0,3,0,3,0,3,0,3 },
            { 1,0,1,0,1,0,1,0 },
            { 0,1,0,1,0,1,0,1 },
            { 2,0,2,0,2,0,2,0 },
            { 0,2,0,2,0,2,0,2 },
            { 2,0,2,0,2,0,2,0 } };
    intro();
    system("cls");
    for (;;) {
        tablero(board, 2);
        while (1) {
            cout << "\nTURNO de las  * BLANCAS *  Ingrese FILA 1-8 y COLUMNA a-h de la ficha que desea mover, por ejemplo 3b\n";
            cin >> OriginRow >> OriginColumn;
            OriginColumn = tolower(OriginColumn);
            cout << "Introduzca FILA 1-8 y COLUMNA a-h del destino de la ficha a mover,  por ejemplo 4a \n";
            cin >> DestinationRow >> DestinationColumn;
            DestinationColumn = tolower(DestinationColumn);

            int tipo_ficha;
            if (board[OriginRow-1][OriginColumn - 'a'] == WHITE_TAB) {
                tipo_ficha = WHITE_TAB;
            }else if (board[OriginRow-1][OriginColumn - 'a'] == WHITE_QUEEN) {
                tipo_ficha = WHITE_QUEEN;
            }else {
                tipo_ficha = -1;
            }
            if (turno(board, tipo_ficha, OriginRow - 1, OriginColumn - 'a', DestinationRow - 1, DestinationColumn - 'a') == 0)
                break;
            cout << "\nINTENTA de nuevo :\n";
        }
        system("cls");
        tablero(board,3);
        while (1) {
            cout << "\nTURNO de las  * NEGRAS *  Ingrese FILA 1-8 y COLUMNA a-h de la ficha que desea mover, por ejemplo 6g\n";
            cin >> OriginRow >> OriginColumn;
            OriginColumn = tolower(OriginColumn);
            cout << "Introduzca FILA 1-8 y COLUMNA a-h del destino de la ficha a mover,  por ejemplo 5h \n";
            cin >> DestinationRow >> DestinationColumn;
            DestinationColumn = tolower(DestinationColumn);

            int tipo_ficha;
            if (board[OriginRow-1][OriginColumn - 'a'] == BLACK_TAB) {
                tipo_ficha = BLACK_TAB;
            }else if (board[OriginRow-1][OriginColumn - 'a'] == BLACK_QUEEN) {
                tipo_ficha = BLACK_QUEEN;
            }else {
                tipo_ficha = -1;
            }
            if (turno(board, tipo_ficha, OriginRow - 1, OriginColumn - 'a', DestinationRow - 1, DestinationColumn - 'a') == 0)
                break;
            cout << "\nINTENTA de nuevo :\n)";
        }
    }
    return 0;
}
