#include <iostream>
#include <stdio.h>

using namespace std;

bool impar(int anio)
{
    return (anio % 2);
}

void numALetras(int numero)
{
    switch (numero)
    {
    case 100:
        cout << "CIEN" << endl;
        break;
    case 200:
        cout << "DOSCIENTOS" << endl;
        break;
    case 300:
        cout << "TRESCIENTOS" << endl;
        break;
    case 400:
        cout << "CUATROCIENTOS" << endl;
        break;
    case 500:
        cout << "QUINIENTOS" << endl;
        break;
    default:
        cout << "ERROR" << endl;
        break;
    }
}

struct Producto
{
    int codigoProducto;
    int cant;
};

void masUnidades(Producto vec[], int len)
{
    int pos = 0;
    int max = vec[0].cant;

    for (int i = 1; i < len; i++)
    {
        if (vec[i].cant > max)
        {
            pos = i;
            max = vec[i].cant;
        }
    }

    cout << "El producto: " << vec[pos].codigoProducto << " tiene el maximo de unidades, con un total de: " << max << endl;
}
void menosUnidades(Producto vec[], int len)
{
    int pos = 0;
    int min = vec[0].cant;

    for (int i = 1; i < len; i++)
    {
        if (vec[i].cant < min)
        {
            pos = i;
            min = vec[i].cant;
        }
    }

    cout << "El producto: " << vec[pos].codigoProducto << " tiene el minimo de unidades, con un total de: " << min << endl;
}
void sumatoria(Producto vec[], int len)
{
    int sum = 0;

    for (int i = 1; i < len; i++)
    {
        sum += vec[i].cant;
    }

    cout << "La cantidad total de productos almacenada es: " << sum << endl;
}

struct Pelicula
{
    int codigoPelicula;
    int opinionesPositivas;
    int vistas;
};

// TODO
// vecA -> definir/inicializar/cargar (mientras leo el archivo)/usarlo pisar el archivo
// vecB -> definir/inicializar/cargar (mientras leo el archivo)/usarlo para mostrar los 10 primeros de mayor a menor

void inicializar(Pelicula vec[], int len, Pelicula valorIni)
{
    for (int i = 0; i < len; i++)
    {
        vec[i].codigoPelicula = valorIni.codigoPelicula;
        vec[i].opinionesPositivas = valorIni.opinionesPositivas;
        vec[i].vistas = valorIni.vistas;
    }
}

void insertar(Pelicula vec[], int &len, Pelicula valor, int pos)
{
    for (int i = len; i > pos; i--)
    {
        vec[i].codigoPelicula = vec[i - 1].codigoPelicula;
        vec[i].opinionesPositivas = vec[i - 1].opinionesPositivas;
        vec[i].vistas = vec[i - 1].vistas;
    }
    vec[pos].codigoPelicula = valor.codigoPelicula;
    vec[pos].opinionesPositivas = valor.opinionesPositivas;
    vec[pos].vistas = valor.vistas;
    len++;
}

// opiniones positivas

void insertarOrdenado1(Pelicula vec[], int &len, Pelicula valor)
{
    // donde voy a cargar el vector
    int i = 0;
    while (i < len && vec[i].opinionesPositivas >= valor.opinionesPositivas)
    {
        i++;
    }

    // cargar el vector
    if (i == len)
    {
        vec[len].codigoPelicula = valor.codigoPelicula;
        vec[len].opinionesPositivas = valor.opinionesPositivas;
        vec[len].vistas = valor.vistas;
        len++;
    }
    else
        insertar(vec, len, valor, i);
}

// vistas

void insertarOrdenado2(Pelicula vec[], int &len, Pelicula valor)
{
    // donde voy a cargar el vector
    int i = 0;
    while (i < len && vec[i].vistas >= valor.vistas)
    {
        i++;
    }

    // cargar el vector
    if (i == len)
    {
        vec[len].codigoPelicula = valor.codigoPelicula;
        vec[len].opinionesPositivas = valor.opinionesPositivas;
        vec[len].vistas = valor.vistas;
        len++;
    }
    else
        insertar(vec, len, valor, i);
}

int main()
{
    // bool aux = impar(5);
    // cout << "  -- " << aux << "  -- " << endl;

    // Producto vec[150];
    // int len;

    // masUnidades(vec, len);
    // menosUnidades(vec, len);
    // sumatoria(vec, len);

    Pelicula vecA[50];
    int lenA = 0;
    Pelicula vecB[50];
    int lenB = 0;
    FILE *titulos;

    Pelicula ini;
    ini.codigoPelicula = 0;
    ini.opinionesPositivas = 0;
    ini.vistas = 0;

    inicializar(vecA, 50, ini);
    inicializar(vecB, 50, ini);

    titulos = fopen("infantil.dat", "rb");

    Pelicula raux;
    fread(&raux, sizeof(struct Pelicula), 1, titulos);

    while (!feof(titulos))
    {
        insertarOrdenado1(vecA, lenA, raux);
        insertarOrdenado2(vecB, lenB, raux);
        fread(&raux, sizeof(struct Pelicula), 1, titulos);
    }

    fclose(titulos);

    titulos = fopen("infantil.dat", "wb");

    for (int i = 0; i < lenA; i++)
    {
        fwrite(&vecA[i], sizeof(struct Pelicula), 1, titulos);
    }

    fclose(titulos);

    if (lenB > 10)
        for (int i = 0; i < 10; i++)
        {
            cout << "--------------" << endl;
            cout << "Codigo: " << vecB[i].codigoPelicula << endl;
            cout << "Opiniones Positivas: " << vecB[i].opinionesPositivas << endl;
            cout << "vistas: " << vecB[i].vistas << endl;
        }
    else
        for (int i = 0; i < lenB; i++)
        {
            cout << "--------------" << endl;
            cout << "Codigo: " << vecB[i].codigoPelicula << endl;
            cout << "Opiniones Positivas: " << vecB[i].opinionesPositivas << endl;
            cout << "vistas: " << vecB[i].vistas << endl;
        }

    return 0;
}