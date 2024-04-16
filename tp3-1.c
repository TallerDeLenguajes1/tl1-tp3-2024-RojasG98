#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 5
#define m 12

void calcularPromedioAnual(int gananciasAnios[5][12]);
void minimoyMaximo(int gananciasAnios[5][12]);

int main(){
    int ganancias[n][m];
    srand(time(NULL));

    //CARGAMOS MATRIZ
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ganancias[i][j] = (rand() % (50000-10000+1)) +10000;
        }   
    }
    //MOSTRAMOS MATRIZ
    for (int i = 0; i < n; i++)
    {
        printf("----------------------------------- Año %d -----------------------------------\n\n",i+1);
        for (int j = 0; j < m; j++)
        {
            printf("%d ", ganancias[i][j]);
        }
        printf("\n\n");
    }
    calcularPromedioAnual(ganancias);
    minimoyMaximo(ganancias);
    
    return 0;
}

void calcularPromedioAnual(int gananciasAnios[5][12]){
    float promedio,suma;
    for (int i = 0; i < n; i++)
    {
        suma = 0;
        for (int j = 0; j < m; j++)
        {
            suma += gananciasAnios[i][j];
        }
        promedio =(float)suma / m;
        printf("El promedio del año %d es: $%.2f\n",i+1,promedio);
    }   
}

void minimoyMaximo(int gananciasAnios[5][12]){
    float min = 50000, max = 0;
    int anioMax,mesMax,anioMin,mesMin;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //VERIFICAMOS SI EL VALOR ES EL MAXIMO
            if (gananciasAnios[i][j] > max)
            {
                max = gananciasAnios[i][j];
                anioMax = i+1;
                mesMax = j+1;
            }
            //VERIFICAMOS SI EL VALOR ES EL MINIMO
            if (gananciasAnios[i][j] < min)
            {
                min = gananciasAnios[i][j];
                anioMin = i+1;
                mesMin = j+1;
            }   
        }
    }
    printf("El valor Maximo obtenido es: $%.2f en el mes %d y año %d\n",max,mesMax,anioMax); 
    printf("El valor Minimo obtenido es: $%.2f en el mes %d y año %d\n",min,mesMin,anioMin); 

}
