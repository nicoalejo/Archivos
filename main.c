
// Un programa para un torneo de fútbol, este programa primero pide que se ingresen lo equipos esto hasta que el usuario ponga terminar, a continuación debe preguntar si desea ingresar el los goles de cada equipo en el torneo o si desea que se generen aleatoriamente.
// Si desea ingresar el los resultados debe presentarse los dos equipos a jugar y entonces que se ingresen los goles del equipo 1 y del equipo2. El torneo se llevará a cabo de forma de Round Robin, cada victoria serán 3 puntos, empate 1 y pérdida 0. 
// Se le debe mostrar al usuario todas las combinaciones posibles de una en una para que pueda ingresar todos los resultados de los partidos.
// Estos ingresos se deben guardar en otro archivo "resultados.txt"
// Cuando acaba de ingresar se debe mostrar una tabla con los resultados de cada partido y otra ordenada según puntos de cada uno de los equipos de mayor a menor.
// Un archivo debe ser para ingreso de los equipos
// Un archivo para Ingreso de resultados
// Un archivo para calculo e impresión de resultados.


//Write a program that reads a file, if there not exists, create it and asks for a string to write in the file.
//Close the file and open it again to read the string and display it on the screen.
//Use the functions: fopen(), fclose(), fprintf(), fscanf().
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//File Write Open
void FileWriteOpen(FILE **fp){
    *fp = fopen("file.txt", "a+");
    if(*fp == NULL){
        printf("File does not exist creating File\n");
        //create a file
        *fp = fopen("file.txt", "w+");        
    }
    else{
        printf("File exists\n");
        
    }
}

void FileOpenChecker(FILE **fp){
    //check if file exists
    *fp = fopen("file.txt", "r");
    if(*fp == NULL){
        printf("File does not exist creating File\n");        
              
    }
    else{
        printf("File exists\n");
        
    }
}


int main(void){

    FILE *fp;
    
    FileWriteOpen(&fp);
    //fp = fopen("file.txt", "a+");

    //write file
    char str1[100];
    char str2[100] = "\nEsta es una prueba\nde una cadena de caracteres\n";
    printf("Enter a string to write in the file: ");
    scanf("%[^\n]", str1);
    fprintf(fp, "%s %s", str1, str2);
    
    fclose(fp);

    FileOpenChecker(&fp);

    //read file
        // char str[100];
        // fscanf(fp, "%s", str);
        // printf("String from file: %s\n", str);
        // fclose(fp);

        // char buffer[256];
        // while (fscanf(fp, "%255s", buffer) == 1) {
        // printf("%s\n", buffer);
        // }
        // fclose(fp);


       char buffer2[1000] = {0}; // Inicializa todos los caracteres a '\0'
    
        fread(buffer2, sizeof(char), sizeof(buffer2), fp);

        printf("Contenido del archivo: %s\n", buffer2);
}

