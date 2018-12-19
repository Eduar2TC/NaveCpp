#include <iostream>
#include <windows.h>
#include <conio.h>
#define Arriba 72
#define Abajo 80
#define Izquierda 75
#define Derecha 77

using namespace std;
class Nave
{
  private:
    int x;
    int y;
    int Vidas;
    int Creditos;

  public:
    Nave(int x, int y, int Vidas, int Creditos);
    void SituaCoord(int a, int b);
    int CoordX();
    int CoordY();
    void OcultaCursor();
    void Dibuja();
    void Borra();
    void Mueve();
    void PintaLimite();
    void PintaLife();
    void Chocar(class Asteroide &ObjetoAst);
    void ExplotarNave();
};

Nave::Nave(int x, int y, int Vidas, int Creditos)
{
    Nave::x = x;
    Nave::y = y;
    Nave::Vidas = Vidas;
    Nave::Creditos = Creditos;
}

void Nave::SituaCoord(int a, int b)
{
    HANDLE mueve;
    mueve = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Posicion;
    Posicion.X = a;
    Posicion.Y = b;
    SetConsoleCursorPosition(mueve, Posicion);
}
void Nave::OcultaCursor()
{
    HANDLE Posicion;
    Posicion = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO rosruC;
    rosruC.dwSize = 2;
    rosruC.bVisible = FALSE;
    SetConsoleCursorInfo(Posicion, &rosruC);
}
void Nave::Dibuja()
{
    Nave::SituaCoord(x, y);
    cout << "  \x1E  ";
    Nave::SituaCoord(x, y + 1);
    cout << "\x18\xDB\xF8\xDB\x18";
    Nave::SituaCoord(x, y + 2);
    cout << "\xDB \x16 \xDB";
    Nave::SituaCoord(x, y + 3);
    cout << "\x7F   \x7F";
}
void Nave::PintaLimite()
{ /*Equina sup izquierda (0,2), Sup Derecha (78,2), Inf derecha (78,23) Inf izquierda (0,78) */
    for (int i = 0; i <= 78; i++)
    {
        Nave::SituaCoord(i, 2);
        cout << "::";
        Nave::SituaCoord(i, 23);
        cout << "::";
    }
    for (int y = 2; y <= 23; y++)
    {
        Nave::SituaCoord(0, y);
        cout << "::";
        Nave::SituaCoord(78, y);
        cout << "::";
    }
}
void Nave::PintaLife()
{
    Nave::SituaCoord(63, 1);
    cout << "Vidas: ";
    Nave::SituaCoord(70, 1);
    for (int Lifes = 0; Lifes < Nave::Vidas; Lifes++)
    {
        Nave::SituaCoord(70 + Lifes, 1); //Dibuja numero de vidas en coord (x,y) tal que i<vidas.
        cout << "\x02";
    }
    Nave::SituaCoord(69, 1);
    for (int Lifes = 3; Lifes > Nave::Vidas; --Lifes)
    {
        Nave::SituaCoord(69 + Lifes, 1); //Dibuja numero de muertes en coord inicial x=69+3.
        cout << "\x01";
    }
    Nave::SituaCoord(50, 1);
    cout << "Creditos: ";
    Nave::SituaCoord(60, 1);
    cout << Nave::Creditos;
}
void Nave::Borra()
{
    Nave::SituaCoord(x, y);
    cout << "     ";
    Nave::SituaCoord(x, y + 1);
    cout << "     ";
    Nave::SituaCoord(x, y + 2);
    cout << "     ";
    Nave::SituaCoord(x, y + 3);
    cout << "     ";
}
int Nave::CoordX()
{
    return Nave::x;
}
int Nave::CoordY()
{
    return Nave::y;
}
void Nave::Chocar(class Asteroide &ObjetoAst)
{ ///////----------------------->
}
void Nave::ExplotarNave()
{
    if (Nave::Creditos > 0)
    {
        Nave::SituaCoord(Nave::x, Nave::y);
        cout << "     ";
        SituaCoord(Nave::x, Nave::y + 1);
        cout << " *** ";
        SituaCoord(Nave::x, Nave::y + 2);
        cout << " *** ";
        SituaCoord(Nave::x, Nave::y + 3);
        cout << "     ";
        Sleep(100);
        Nave::Borra();
        Nave::SituaCoord(Nave::x, Nave::y);
        cout << "*   *";
        SituaCoord(Nave::x, Nave::y + 1);
        cout << " *** ";
        SituaCoord(Nave::x, Nave::y + 2);
        cout << " *** ";
        SituaCoord(Nave::x, Nave::y + 3);
        cout << "*   *";
        Sleep(200);
        Nave::Borra();
        Nave::SituaCoord(Nave::x, Nave::y);
        cout << "  *  ";
        SituaCoord(Nave::x, Nave::y + 1);
        cout << "*   *";
        SituaCoord(Nave::x, Nave::y + 2);
        cout << "*   *";
        SituaCoord(Nave::x, Nave::y + 3);
        cout << "  *  ";
        Sleep(300);
        Nave::Borra();
        Nave::Dibuja();
        Nave::Creditos--;
        Nave::Vidas = 3;
    }
}
void Nave::Mueve()
{
    if (kbhit() == true)
    {
        char PresTecla = getch();

        switch (PresTecla)
        {
        case 'w':
            if (y > 3)
            {
                SituaCoord(x, y);
                Nave::Borra();
                y--;
                Nave::Dibuja();
            }
            break;
        case Arriba:
            if (y > 3)
            {
                SituaCoord(x, y);
                Nave::Borra();
                y--;
                Nave::Dibuja();
            }
            break;
        case 's':
            if (y < 19)
            {
                SituaCoord(x, y);
                Nave::Borra();
                y++;
                Nave::Dibuja();
            }
            break;
        case Abajo:
            if (y < 19)
            {
                SituaCoord(x, y);
                Nave::Borra();
                y++;
                Nave::Dibuja();
            }
            break;
        case 'a':
            if (x > 2)
            {
                SituaCoord(x, y);
                Nave::Borra();
                x--;
                Nave::Dibuja();
            }
            break;
        case Izquierda:
            if (x > 2)
            {
                SituaCoord(x, y);
                Nave::Borra();
                x--;
                Nave::Dibuja();
            }
            break;
        case 'd':
            if (x < 73)
            {
                SituaCoord(x, y);
                Nave::Borra();
                x++;
                Nave::Dibuja();
            }
            break;
        case Derecha:
            if (x < 73)
            {
                SituaCoord(x, y);
                Nave::Borra();
                x++;
                Nave::Dibuja();
            }
            break;
        case 'f':
            if (Nave::Vidas > 0)
            {
                Nave::Vidas--;
                Nave::PintaLife();
                if (Nave::Vidas == 0)
                {
                    Nave::ExplotarNave();
                }
            }
            Nave::PintaLife();
            break;
        default:
            SituaCoord(x, y);
            Nave::Dibuja();
            break;
        }
    }
}

class Asteroide
{
  private:
    int x;
    int y;

  public:
    Asteroide(int x, int y);
    void SituaXY(int a, int b);
    void Dibuja();
    void Mover();
};
Asteroide::Asteroide(int x, int y)
{
    Asteroide::x = x;
    Asteroide::y = y;
}
void Asteroide::SituaXY(int a, int b)
{
    HANDLE Mueve;
    Mueve = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Posicion;
    Posicion.X = a;
    Posicion.Y = b;
    SetConsoleCursorPosition(Mueve, Posicion);
}

void Asteroide::Dibuja()
{
    Asteroide::SituaXY(Asteroide::x, Asteroide::y);
    cout << "\x0F";
}
void Asteroide::Mover()
{
    Asteroide::SituaXY(Asteroide::x, Asteroide::y);
    cout << " ";
    Asteroide::y++;
    if (Asteroide::y > 22)
    {
        Asteroide::x = rand() % 75 + 3; //si rand =0 ent x=0+2
        if (Asteroide::x == 78)
        {
            Asteroide::x = 75;
        }
        Asteroide::y = 3;
    }
    Asteroide::Dibuja();
    //Posiblemente Sleep(100);
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    bool terminar_juego = false;
    Nave Nave1(6, 6, 3, 3);
    Asteroide Asteroide1(10, 4);
    Nave1.PintaLimite();
    Nave1.OcultaCursor();
    Nave1.Dibuja();
    Nave1.PintaLife();

    while (terminar_juego == false)
    {
        Nave1.Mueve();
        Asteroide1.Mover();
        Sleep(50);
    }

    return 0;
}
