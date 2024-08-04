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
    // int numeros[50];
    // int sumaMayores100 = 0;
    // int conteoMayores100 = 0;
    // int sumaMenoresMenos10 = 0;

    // for (int i = 0; i < 50; i++)
    // {
    //     cout << "Ingresa el numero: " << i + 1 << ": ";
    //     cin >> numeros[i];

    //     if (numeros[i] > 100)
    //     {
    //         sumaMayores100 += numeros[i];
    //         conteoMayores100++;
    //     }

    //     if (numeros[i] < -10)
    //     {
    //         sumaMenoresMenos10 += numeros[i];
    //     }
    // }

    // double promedioMayores100 = 0;
    // if (conteoMayores100 > 0)
    // {
    //     promedioMayores100 = sumaMayores100 / (double)conteoMayores100;
    // }

    // cout << "El promedio de los números mayores que 100 es: " << promedioMayores100 << endl;
    // cout << "La suma de los números menores que -10 es: " << sumaMenoresMenos10 << endl;

    /* Ejercicio 3 */
    int tam = 0;
    int valor;

    cout << "Ingresa valores positivos (termina con un valor negativo): " << endl;

    int valoresPositivos[100];
    int valorMaximo = -1;
    int posicionMaxima = -1;

    while (true)
    {
        cin >> valor;
        if (valor < 0)
        {
            break;
        }

        valoresPositivos[tam] = valor;

        if (valor > valorMaximo)
        {
            valorMaximo = valor;
            posicionMaxima = tam;
        }

        tam++;
    }

    if (tam == 0)
    {
        cout << "No se ingresaron valores positivos." << endl;
    }
    else
    {
        cout << "El valor maximo del conjunto es: " << valorMaximo << endl;
        cout << "La posicion relativa del valor maximo es: " << posicionMaxima + 1 << endl;
    }
    return 0;
}