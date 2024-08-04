#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

/* Funciones */

/* 1 */
float totalComisionesGeneradas(float equipoVentas[], int ventas, float comision)
{
    float totalComisiones = 0;
    for (int i = 0; i < ventas; i++)
    {
        totalComisiones += equipoVentas[i] * (comision / 100);
    }
    return totalComisiones;
}

/* 2 */
struct Sucursal
{
    int idSucursal;
    int ventasTotalesSucursal;
};

int totalVentasPorSucursal(Sucursal sucursales[], int cantidadSucursales)
{
    for (int i = 0; i < cantidadSucursales; i++)
    {
        int totalVentas = 0;
        for (int j = 0; j < cantidadSucursales; j++)
        {
            if (sucursales[j].idSucursal == sucursales[i].idSucursal)
            {
                totalVentas += sucursales[j].ventasTotalesSucursal;
            }
        }

        bool yaImpreso = false;
        for (int k = 0; k < i; k++)
        {
            if (sucursales[k].idSucursal == sucursales[i].idSucursal)
            {
                yaImpreso = true;
                break;
            }
        }
        if (!yaImpreso)
        {
            cout << "Sucursal " << sucursales[i].idSucursal << " tiene un total de ventas de: $" << totalVentas << endl;
        }
    }
}

/* 3 */
struct Producto
{
    int idProducto;
    string descripcion;
    int stock;
    int deposito;
};

void vectorConsolidado(Producto deposito1[], int tam1, Producto deposito2[], int tam2, Producto consolidado[], int &tamConsolidado)
{
    int i = 0, j = 0, k = 0;

    while (i < tam1 && j < tam2)
    {
        if (deposito1[i].idProducto < deposito2[j].idProducto)
        {
            consolidado[k] = deposito1[i];
            consolidado[k].deposito = 1;
            i++;
        }
        else
        {
            consolidado[k] = deposito2[j];
            consolidado[k].deposito = 2;
            j++;
        }
        k++;
    }

    while (i < tam1)
    {
        consolidado[k] = deposito1[i];
        consolidado[k].deposito = 1;
        i++;
        k++;
    }

    while (j < tam2)
    {
        consolidado[k] = deposito2[j];
        consolidado[k].deposito = 2;
        j++;
        k++;
    }

    tamConsolidado = k;
}

void ordenarPorStock(Producto consolidado[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam - i - 1; j++)
        {
            if (consolidado[j].stock < consolidado[j + 1].stock)
            {
                // Intercambiar
                Producto temp = consolidado[j];
                consolidado[j] = consolidado[j + 1];
                consolidado[j + 1] = temp;
            }
        }
    }
}

void imprimirTop10(Producto consolidado[], int tam)
{
    cout << "Top 10 productos con más stock: " << endl;
    for (int i = 0; i < 10 && i < tam; i++)
    {
        cout << "ID Producto: " << consolidado[i].idProducto << ", Descripcion: " << consolidado[i].descripcion << ", Stock: " << consolidado[i].stock << ", Deposito: " << consolidado[i].deposito << endl;
    }
}

/* 4 */
struct Gol
{
    int codigoJugador;
    int codigoPartido;
    char nombreApellido[50];
    char seleccion[30];
    int cantidadGoles;
};

struct Jugador
{
    int codigoJugador;
    char nombreApellido[50];
    int totalGoles;
};

struct Seleccion
{
    char nombre[30];
    int totalGoles;
};

int buscarSeleccion(Seleccion selecciones[], int tam, const char nombre[])
{
    for (int i = 0; i < tam; i++)
    {
        bool iguales = true;
        for (int j = 0; nombre[j] != '\0' || selecciones[i].nombre[j] != '\0'; j++)
        {
            if (nombre[j] != selecciones[i].nombre[j])
            {
                iguales = false;
                break;
            }
        }
        if (iguales)
        {
            return i;
        }
    }
    return -1;
}

void copiarCadena(char destino[], const char origen[])
{
    int i = 0;
    while (origen[i] != '\0')
    {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0';
}

int main()
{
    /* 1 */
    // int ventas;
    // float equipoVentas[ventas], comision;

    // cout << "Ingresa la cantidad de ventas: ";
    // cin >> ventas;

    // for (int i = 0; i < ventas; i++)
    // {
    //     cout << "Ingresa el monto de cada venta " << i + 1 << ": ";
    //     cin >> equipoVentas[i];
    // }

    // cout << "Ingresa cuanto de comisión se aplicará: ";
    // cin >> comision;

    // cout << "El total de comisiones generadas fue: " << totalComisionesGeneradas(equipoVentas, ventas, comision) << endl;

    /* 3 */
    // Producto deposito1[500], deposito2[500], consolidado[1000];
    // int tam1, tam2, tamConsolidado;

    // cout << "Ingresa la cantidad de productos en el deposito 1: ";
    // cin >> tam1;
    // cout << "Ingresa la cantidad de productos en el deposito 2: ";
    // cin >> tam2;

    // for (int i = 0; i < tam1; i++)
    // {
    //     cout << "Ingresa el ID del producto " << i + 1 << " en el deposito 1: ";
    //     cin >> deposito1[i].idProducto;
    //     cout << "Ingresa la descripcion del producto " << i + 1 << " en el deposito 1: ";
    //     cin.ignore();
    //     getline(cin, deposito1[i].descripcion);
    //     cout << "Ingresa el stock del producto " << i + 1 << " en el deposito 1: ";
    //     cin >> deposito1[i].stock;
    // }

    // for (int i = 0; i < tam2; i++)
    // {
    //     cout << "Ingresa el ID del producto " << i + 1 << " en el deposito 2: ";
    //     cin >> deposito2[i].idProducto;
    //     cout << "Ingresa la descripcion del producto " << i + 1 << " en el deposito 2: ";
    //     cin.ignore();
    //     getline(cin, deposito2[i].descripcion);
    //     cout << "Ingresa el stock del producto " << i + 1 << " en el deposito 2: ";
    //     cin >> deposito2[i].stock;
    // }

    // vectorConsolidado(deposito1, tam1, deposito2, tam2, consolidado, tamConsolidado);

    // ordenarPorStock(consolidado, tamConsolidado);

    // ofstream archivo("top10.dat");
    // archivo << imprimirTop10;
    // archivo.close();

    /* 4 */
    ifstream archivo("golesXpartido.dat", ios::binary);
    if (!archivo)
    {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    Gol goles[1000];
    int cantidadGoles = 0;

    while (archivo.read((char *)&goles[cantidadGoles], sizeof(Gol)))
    {
        cantidadGoles++;
    }
    archivo.close();

    // a.
    Jugador maxJugador = {0, "", 0};

    Jugador jugadores[1000];
    int cantidadJugadores = 0;

    for (int i = 0; i < cantidadGoles; i++)
    {
        int j;
        for (j = 0; j < cantidadJugadores; j++)
        {
            if (jugadores[j].codigoJugador == goles[i].codigoJugador)
            {
                jugadores[j].totalGoles += goles[i].cantidadGoles;
                break;
            }
            if (j == cantidadJugadores)
            {
                jugadores[cantidadJugadores].codigoJugador = goles[i].codigoJugador;
                copiarCadena(jugadores[cantidadJugadores].nombreApellido, goles[i].nombreApellido);
                jugadores[cantidadJugadores].totalGoles = goles[i].cantidadGoles;
                cantidadJugadores++;
            }
        }
        }

    for (int i = 0; i < cantidadJugadores; i++)
    {
        if (jugadores[i].totalGoles > maxJugador.totalGoles)
        {
            maxJugador = jugadores[i];
        }
    }

    cout << "El jugador mas goleador es: " << maxJugador.nombreApellido << " con " << maxJugador.totalGoles << " goles." << endl;

    // b.
    cout << "Goles por jugador: " << endl;
    for (int i = 0; i < cantidadJugadores; i++)
    {
        cout << jugadores[i].nombreApellido << ": " << jugadores[i].totalGoles << " goles" << endl;
    }

    // c.
    Seleccion selecciones[16];
    int cantidadSelecciones = 0;

    for (int i = 0; i < cantidadGoles; i++)
    {
        int idx = buscarSeleccion(Selecciones, cantidadSelecciones, goles[i].seleccion);
        if (idx == -1)
        {
            copiarCadena(selecciones[cantidadSelecciones].nombre, goles[i].seleccion);
            selecciones[cantidadSelecciones].totalGoles = goles[i].cantidadGoles;
            cantidadSelecciones++;
        }
        else
        {
            selecciones[idx].totalGoles += goles[i].cantidadGoles;
        }
    }

    // Encontrar las selecciones con menos goles
    int minGoles = selecciones[0].totalGoles;
    for (int i = 1; i < cantidadSelecciones; i++)
    {
        if (selecciones[i].totalGoles < minGoles)
        {
            minGoles = selecciones[i].totalGoles;
        }
    }

    cout << "Las selecciones que convirtieron menos goles son: " << endl;
    for (int i = 0; i < cantidadSelecciones; i++)
    {
        if (selecciones[i].totalGoles == minGoles)
        {
            cout << selecciones[i].nombre << ": " << selecciones[i].totalGoles << " goles" << endl;
        }
    }
    return 0;
}