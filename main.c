#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define FILAS 5
#define COLUMNAS 20
#define TAM 5
#define SIZE_NAME 100
float calcularPromedio(int num1, int num2);
void mostrarAlumnos (int leg[], char sexos[],int n1[], int n2[], float prom[],char names[][20], int tam);
void ordenarAlumnos(int leg[], char sexos[], int n1[], int n2[], float prom[],char names[][20], int tam);
void mostrarAlumno(char nombres[],int leg,char sexos,int n1,int n2,float prom);
int main()
{
    int legajos[TAM];//={1,2,3,4,5};
    char sexos[TAM];//={'m','f','m','f','m'};
    int notas1[TAM];//={4,3,2,4,10};
    int notas2[TAM];//={5,8,9,5,10};
    float promedios[TAM];
    char auxCad[SIZE_NAME];
    char nombres[FILAS][COLUMNAS];//={{"ivan"},{"maximiliano"},{"aldana"},{"belen"},{"cielo"}};

    for(int i=0; i<TAM;i++)
    {
        printf("Ingrese nombre: \n");
        fflush(stdin);
        gets(auxCad);
          while(strlen(auxCad)>=COLUMNAS)
       {
           printf("Nombre demasiado largo");
           fflush(stdin);
           gets(auxCad);
       }
        strcpy(nombres[i],auxCad);
        printf("ingrese primera nota: ");
        scanf("%d",&notas1[i]);
        printf("ingrese segunda nota: ");
        scanf("%d",&notas2[i]);
        printf("Ingrese legajo: ");
        scanf("%d",&legajos[i]);
        printf("ingrese sexo: ");
        fflush(stdin);
        scanf("%c",&sexos[i]);

    promedios[i]=calcularPromedio(notas1[i], notas2[i]);
    }
    mostrarAlumnos(legajos,sexos, notas1,notas2,promedios,nombres, TAM);
    ordenarAlumnos(legajos, sexos, notas1, notas2, promedios,nombres, TAM);
    mostrarAlumnos(legajos,sexos, notas1,notas2,promedios,nombres, TAM);
}

float calcularPromedio(int num1, int num2)
{
    return (float) (num1 + num2)/2;
}
void mostrarAlumnos(int leg[], char sexos[],int n1[], int n2[], float prom[],char names[][20], int tam)
{
    //system("cls");
    printf("-------------------------------------------------------------------------------\n");
    printf("--------------------listado de promedios de  alumnos---------------------------\n");
    printf("-------------------------------------------------------------------------------\n");
    printf(" Parcial 1| parcial 2|    promedio|      legajo|      sexo|     nombre Alumno\n");
    printf("-------------------------------------------------------------------------------\n");
    for(int i=0; i<tam; i++)
    {
       // printf("    %2d    |     %2d   |      %5.2f |      %2d    |    %c     |     %10s ",n1[i], n2[i], prom[i],leg[i],sexos[i],names[i]);
      //  printf("\n\n");
      mostrarAlumno(names[i],leg[i],sexos[i],n1[i],n2[i],prom[i]);
    }
}
void ordenarAlumnos(int leg[],char sexos[],  int n1[], int n2[], float prom[],char names[][20], int tam)
{
    int auxInt;
    float auxFloat;
    char auxChar;
    char auxCad[SIZE_NAME];

    for(int i=0; i<tam;i++)
    {
        for(int j=i+1; j<tam;j++)
        {
            //if(strcmp(names[i],names[j])>0)//ordeno por nombre, para invertir el orden, solo cambiar el signo <
            //if(prom[i]<prom[j])//ordeno por promedio
            if(sexos[i]<sexos[j] || (sexos[i]==sexos[j] && leg[i]>leg[j] ))//ordena por sexo y por legajo strcmp(names[i],names[j])>0;
            {
                auxFloat=prom[i];
                prom[i]=prom[j];
                prom[j]=auxFloat;

                auxInt=n1[i];
                n1[i]=n1[j];
                n1[j]=auxInt;

                auxInt=n2[i];
                n2[i]=n2[j];
                n2[j]=auxInt;

                auxInt=leg[i];
                leg[i]=leg[j];
                leg[j]=auxInt;

                auxChar=sexos[i];
                sexos[i]=sexos[j];
                sexos[j]=auxChar;

                strcpy(auxCad, names[i]);
                strcpy(names[i],names[j]);
                strcpy(names[j],auxCad);
            }



        }
    }
}
void mostrarAlumno(char nombres[],int leg,char sexos,int n1,int n2,float prom)
{
     printf("    %2d    |     %2d   |      %5.2f |      %2d    |    %c     |     %10s ",n1, n2, prom,leg,sexos,nombres);
        printf("\n\n");

}
/*void mostrarAlumno(char nombres[],int leg[],char sexos[],int n1[],int n2[],float prom[])
{
     printf("    %2d    |     %2d   |      %5.2f |      %2d    |    %c     |     %10s ",n1, n2, prom,leg,sexos,nombres);
        printf("\n\n");
}*/
