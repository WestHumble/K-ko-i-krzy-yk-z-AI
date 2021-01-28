#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

const int board_size = 9;

//Funkcja czyszczaca tablice
void clearBoard(int board[])
{
    int i;

    for (i = 0; i < board_size; ++i) {
        board[i] = -i - 1;
    }
}

// Funkcja rysująca tablice (kolumny i wiersze). Przypisuje X graczowi 2 i O Graczowi 1 a jeśli jest puste to _ .
void drawBoard(int board[])
{
    int i, j;

    for (i = 0; i <= 6; i += 3) {
        for (j = 0; j < 3; ++j) {
            if (board[i + j] == 2)
                cout << "| X |";
            else if (board[i + j] == 1)
                cout << "| O |";
            else
                cout << "| _ |";
        }
        cout << endl << endl;
    }
}


// Funkcja zwracająca ruch gracza (Pobiera ruch i zwraca)
int getPlayerMove(int player)
{
    int move;

    cout << "Gracz " << player << " wykonuje ruch: ";
    cin >> move;
    cout << endl;
    return move;
}

// Funkcja zwracająca ruch komputera (Do ruchu wykorzystujemy randomową liczbę w przedziale board_size)
int makeRandMove(int player)
{
    cout << "Komputer wykonuje ruch" << endl << endl;
    return rand() % board_size;
}

// Powtarzanie puki gracz bądz komputer nie podadzą pustego miejsca
bool isMoveValid(int board[], int move)
{
    if (board[move] < 0)
        return true;
    return false;
}

//Funkcja sprawdzająca wygraną w wierszach i kolumanch i po skosie
bool isaWin(int board[], int move)
{
    if ((board[0] == board[1] && board[0] == board[2]) ||
        (board[3] == board[4] && board[3] == board[5]) ||
        (board[6] == board[7] && board[6] == board[8]) ||
        (board[0] == board[3] && board[0] == board[6]) ||
        (board[1] == board[4] && board[1] == board[7]) ||
        (board[2] == board[5] && board[2] == board[8]) ||
        (board[0] == board[4] && board[0] == board[8]) ||
        (board[2] == board[4] && board[2] == board[6]))
        return true;
    return false;
}

int main()
{
    int board[board_size];
    int turn = 0;
    int move = 10;
    int menu;

    cout << endl << "Witaj w grze Kolko i krzyzyk z komputerem" << endl << "Autor: Dominik Soj i Tomasz Marszalek" << endl;
    while (true) {
           // cout << "Wybierz pozycje: " << endl << "1. Zagraj w gre kolko i krzyzyk " << endl << "2. Wyswietl instrukcje " << endl;
           

            cout << "****************************************************" << endl;
            cout << "******************** MENU GLOWNE *******************" << endl;
            cout << "****************************************************" << endl;
            cout << "*                                                  *" << endl;
            cout << "* PROGRAM          DESCRIPTION                     *" << endl;
            cout << "* ------------------------------------------------ *" << endl;
            cout << "*                                                  *" << endl;
            cout << "*   1              Zagraj w gre kolko i krzyzyk    *" << endl;
            cout << "*                                                  *" << endl;
            cout << "*   2              Wyswietl instrukcje             *" << endl;
            cout << "*                                                  *" << endl;
            cout << "*                                                  *" << endl;
            cout << "* ------------------------------------------------ *" << endl;
            cout << "*                                                  *" << endl;
            cout << "****************************************************" << endl;

            //cin >> menu;
              while (!(cin >> menu && menu==1 || menu==2 )) {
            cout << "Prosze wybrac Poprawna opcje " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

            switch (menu) {

            case 1:

                    cout << endl;
                    srand(time(0));

                    clearBoard(board);

                    while (!isaWin(board, move)) {
                        drawBoard(board);
                        if (2 == turn)
                            turn = 1;
                        else
                            turn = 2;

                        do {
                            if (2 == turn)
                                move = getPlayerMove(turn);
                            else
                                move = makeRandMove(turn);
                        } while (!isMoveValid(board, move));

                        board[move] = turn;
                    }

                    drawBoard(board);
                    cout << "Gracz " << turn << " wygrywa!!!" << endl;

                break;

            case 2:

                    cout << "****************************************************" << endl;
                    cout << "******************** INSTRUKCJA ********************" << endl;
                    cout << "****************************************************" << endl << endl ;


                    cout << "Kółko i krzyżyk to gra umysłowa rozgrywana przez dwóch graczy." << endl ;
                    cout << "Gracze stawiają na przemian kółko i krzyżyk dążąc do zajęcia trzech pól w jednej linii. " << endl;
                    cout << "Wygrywa ten z graczy, któremu jako pierwszemu uda ułożyć się trzy znaki w jednej linii." << endl;
                    cout << "Niestety, kółko i krzyżyk jest grą, która przy dobrze grających graczach zawsze kończy się remisem." << endl;
                    cout << "Grę może wygrać gracz zaczynający, który postawi znak w środku, a przeciwnik na to zagranie odpowie źle." << endl;
                    cout << "W tej sytuacji drugi z graczy, aby nie przegrać gry - na ruch w centrum powinien swój znak umieścić w dowolnym narożniku," << endl;
                    cout << "a następnie blokować możliwość uzyskania przez przeciwnika trzech znaków w linii.Wówczas gra kończy się zawsze remisem" << endl;
                   
                break;
            }
        cout << "Jesli chcesz wyjsc kliknij ESC, a jesli chcesz zagrac jeszcze raz wcisnij dowolny klawisz" << endl << endl;
        if (_getch() == 27) exit(0);
    }
}

