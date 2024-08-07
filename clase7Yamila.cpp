#include <iostream>
using namespace std;

void inicializar(int vec[], int len, int valorIni)
{
    for (int i = 0; i < len; i++)
    {
        vec[i] = valorIni;
    }
}

void mostrar(int vec[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "El vector en posicion" << i << ": " << vec[i] << endl;
    }
}

void insertar(int vec[], int &len, int valor, int pos)
{
    for (int i = len; i > pos; i--)
    {
        vec[i] = vec[i - 1];
    }
    vec[pos] = valor;
    len++;
}

void insertarOrdenado(int vec[], int &len, int valor)
{
    // donde voy a cargar el vector
    int i = 0;
    while (i < len && vec[i] <= valor)
    {
        i++;
    }

    // cargar el vector
    if (i == len)
    {
        vec[len] = valor;
        len++;
    }
    else
        insertar(vec, len, valor, i);
}

int buscar(int vec[], int len, int valor)
{
    int i = 0;
    while (i < len && vec[i] != valor)
    {
        i++;
    }

    if (i == len)
    {
        return -1;
    }
    else
        return 1;
}

void eliminar(int vec[], int &len, int pos)
{
    for (int i = pos; i < len - 1; i++)
    {
        vec[i] = vec[i + 1];
    }
    len--;
}

void cargaMasiva(int vec[], int &len, int cantP)
{
    for (int i = 0; i < cantP; i++)
    {
        cout << "Ingresa un valor: " << endl;
        cin >> vec[i];
        len++;
    }
}

int main()
{

    return 0;
}