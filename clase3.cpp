#include <iostream>
using namespace std;

void cualEsElMayor(int vector[], int cardinal)
{
    int mayor = vector[0];
    for (int i = 0; i < cardinal; i++)
    {
        if (vector[i] > mayor)
        {
            mayor = vector[i];
        }
    }
    cout << "El mayor valor es: " << mayor << endl;
}

int main()
{
    /* Ejercicio 1 */
    // int numeros[10];

    // cout << "Ingresa 10 numeros: ";
    // for (int i = 0; i < 10; i++)
    // {
    //     cin >> numeros[i];
    // }

    // cualEsElMayor(numeros, 10);

    /* Ejercicio 2 */

    return 0;
}