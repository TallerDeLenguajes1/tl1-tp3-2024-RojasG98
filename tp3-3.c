#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAMA 5

int main(){
    char *buff;
    char **nombres;
    nombres = (char **)malloc(sizeof(char *)* TAMA);
    buff = (char *) malloc(100*sizeof(char));
    for (int i = 0; i < TAMA; i++)
    {
        printf("Ingrese su nombre: ");
        gets(buff);
        *(nombres+i) = (char *) malloc((strlen(buff)+1)*sizeof(char));
        strcpy(nombres[i],buff);
    }
    free(buff);
    for (int i = 0; i < TAMA; i++)
    {
        printf("Nombre %d: %s\n",i+1,nombres[i]);
    }
    free(nombres);
    
}