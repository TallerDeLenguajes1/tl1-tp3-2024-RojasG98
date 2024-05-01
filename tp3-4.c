#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAMA 100

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
typedef struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         //  entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10- 100
} Producto;
typedef struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;         // El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
} Cliente;

void menuClientes(Cliente *cliente, int cantidad);
void mostrarProductos(Producto *Producto, int cantidad);
void cargaClientes(Cliente *clientes, int cantidad);
void crearProductos(Cliente *clientes,int nrocliente, int cantidad);
float calcularCostoTotal(Producto producto);

int main()
{
    int cantClientes;
    puts("ingrese la cantidad de clientes");
    scanf("%d", &cantClientes);
    Cliente *clientes;
    clientes = (Cliente *)malloc(sizeof(Cliente *) * cantClientes);
    cargaClientes(clientes, cantClientes);
    menuClientes(clientes, cantClientes);
}

void menuClientes(Cliente *cliente, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("Cliente: %s\n", cliente[i].NombreCliente);
        printf("ID: %d\n", cliente[i].ClienteID);
        mostrarProductos(cliente[i].Productos, cliente[i].CantidadProductosAPedir);
        printf("--------------------------------------------------------------\n");
    }
}

void mostrarProductos(Producto *producto, int cantidad)
{
    float total = 0;
    for (size_t i = 0; i < cantidad; i++)
    {
        printf("    Producto: %d\n", producto[i].ProductoID);
        printf("    Tipo: %s\n", producto[i].TipoProducto);
        printf("    Cantidad: %d\n", producto[i].Cantidad);
        printf("    Precio: $%.2f\n", producto[i].PrecioUnitario);
        puts("-----------------------------------------------------------");
        total += calcularCostoTotal(producto[i]);
    }
    printf("TOTAL A PAGAR: $%.2f\n",total);
}

void cargaClientes(Cliente *clientes, int cantidad)
{
    char *buff;
    char **nombres;
    srand(time(NULL));
    for (int i = 0; i < cantidad; i++)
    {
        clientes[i].ClienteID = i + 1;
        nombres = (char **)malloc(sizeof(char *) * TAMA);
        buff = (char *)malloc(100 * sizeof(char));
        fflush(stdin);
        printf("Ingrese nombre cliente: ");
        gets(buff);
        clientes[i].NombreCliente = (char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(clientes[i].NombreCliente, buff);
        clientes[i].CantidadProductosAPedir = rand() % 5 + 1;
        clientes[i].Productos = (Producto *)malloc(sizeof(Producto) * clientes[i].CantidadProductosAPedir);
        crearProductos(clientes,i, clientes[i].CantidadProductosAPedir);
    }
    free(buff);
}

void crearProductos(Cliente *cliente,int nrocliente, int cantidad)
{
    int tipoRand;
    srand(time(NULL));
    for (int i = 0; i < cantidad; i++)
    {
        cliente[nrocliente].Productos[i].ProductoID = i + 1;
        cliente[nrocliente].Productos[i].Cantidad = rand() % 10 + 1;
        tipoRand = rand() % 6;
        cliente[nrocliente].Productos[i].TipoProducto = TiposProductos[tipoRand];
        cliente[nrocliente].Productos[i].PrecioUnitario = rand() % 91 + 10;
    }
}

float calcularCostoTotal(Producto producto)
{
    return (producto.PrecioUnitario * producto.Cantidad);
}
