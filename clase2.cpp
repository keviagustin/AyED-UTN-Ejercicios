#include <iostream>

using namespace std;

bool esBisiesto(int ano)
{
    if (ano % 4 == 0)
    {
        if (ano % 100 == 0)
        {
            if (ano % 400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

int diasDelMes(int mes, int ano)
{
    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if (esBisiesto(ano))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    default:
        return -1;
    }
}

int main()
{
    /* Ejercicio 1 */
    // int x, y;

    // cout << "Ingresa un numero ";
    // cin >> x;
    // cout << "Ingresa otro numero ";
    // cin >> y;

    // cout << x << "+" << y << "= " << x + y << endl;
    // cout << x << "*" << y << "= " << x * y << endl;

    // if ((x - y) > 0)
    // {
    //     cout << x << "-" << y << "= " << x - y << endl;
    // }
    // else
    // {
    //     cout << "La resta no da mayor que cero" << endl;
    // }

    /* Ejercicio 2 */
    // int notas[3], promedio = 0;

    // for (int i = 0; i < 3; i++)
    // {
    //     do
    //     {
    //         cout << "Ingresar la nota " << i + 1 << " del estudiante entre (0 y 10) ";
    //         cin >> notas[i];
    //         if (notas[i] > 10 || notas[i] < 0)
    //         {
    //             cout << "Nota invalida. Debe ser entre 0 y 10." << endl;
    //         }
    //         else
    //         {
    //             promedio += notas[i];
    //         }
    //     } while (notas[i] > 10 || notas[i] < 0);
    // }

    // cout << "El promedio del estudiante es: " << promedio / 3 << endl;

    /* Ejercicio 3 */
    // int ladosDelDado[5];
    // bool esGenerala;

    // for(int i = 0; i<5; i++){
    //     cout<<"ingrese el valor del dado "<< i+1<< ": "<<endl;
    //     cin>> ladosDelDado[i];

    //     if(i > 0 && ladosDelDado[i] != ladosDelDado[0]){
    //         esGenerala = false;
    //     }
    // }

    // if(esGenerala){
    //     cout<<"Es generala"<<endl;
    // }else{
    //     cout<<"No es generala"<<endl;
    // }

    // /* Ejercicio 4 */
    // int numeroIngresado;
    // cout<< "Ingresa un número: ";
    // cin>>numeroIngresado;
    // if(numeroIngresado % 2 != 0 ){
    //     cout<<"El número "<< numeroIngresado<< " es impar"<<endl;
    // }else{
    //     cout<<"El número "<< numeroIngresado<< " es par"<<endl;
    // }

    //    /* Ejercicio 5 */
    //    int ladosTriangulo[3];

    //    for(int i = 0; i < 3; i++){
    //     cout<<"Ingresa el lado "<< i+1<< " del triangulo"<<endl;
    //     cin>>ladosTriangulo[i];
    //    }

    //    if(ladosTriangulo[0] == ladosTriangulo[1] && ladosTriangulo[1] == ladosTriangulo[2]){
    //         cout<<"El triángulo es Equilátero"<<endl;
    //     }else if(ladosTriangulo[0] == ladosTriangulo[1] || ladosTriangulo[1] == ladosTriangulo[2] || ladosTriangulo[0] == ladosTriangulo[2]){
    //         cout<<"El triángulo es Isósceles"<<endl;
    //     }else{
    //         cout<<"El triángulo es Escaleno"<<endl;
    //     }

    /* Ejercicio 6 */
    // int valorIngresado;
    // cout << "Ingresar valor a determinar: ";
    // cin >> valorIngresado;

    // cout << "La quinta parte del valor " << valorIngresado << " es " << valorIngresado / 5 << endl;
    // cout << "El resto de la division por 5 " << " es " << valorIngresado % 5 << endl;
    // cout << "La septima parte de la quinta parte es " << ((valorIngresado / 5) / 7) << endl;

    /* Ejercicio 7 */
    // int mes, ano;
    // cout << "Ingresa el mes: ";
    // cin >> mes;
    // cout << "Ingresa el anio: ";
    // cin >> ano;

    // int dias = diasDelMes(mes, ano);
    // if (dias != -1)
    // {
    //     cout << "El mes " << mes << " del anio" << ano << " tiene " << dias << " dias" << endl;
    // }
    // else
    // {
    //     cout << "Mes invalido" << endl;
    // }

    return 0;
}