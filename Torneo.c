#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEAMS 100
#define MAX_NAME_LENGTH 50

int main() {
    char teams[MAX_TEAMS][MAX_NAME_LENGTH];
    int points[MAX_TEAMS] = {0};
    int teamCount = 0;

    // Pedir nombres de equipos
    printf("Ingresa los nombres de los equipos. Escribe 'terminar' cuando hayas terminado.\n");

    while (strcmp(teams[teamCount], "terminar") != 0) {
        printf("Equipo %d: ", teamCount + 1);
        scanf("%s", teams[teamCount]);
        teamCount++;
    }

    // Preguntar cómo se generan los resultados de los partidos
    int randomResults;
    printf("¿Quieres ingresar los resultados de los partidos (1) o generarlos aleatoriamente (2)? ");
    scanf("%d", &randomResults);

    // Generar y registrar resultados de los partidos
    remove("resultados.txt");
    FILE *file = fopen("resultados.txt", "w");    
    srand(time(NULL));
    for (int i = 0; i < teamCount; i++) {
        for (int j = i + 1; j < teamCount; j++) {
            int score1, score2;
            if (randomResults == 2) {
                score1 = rand() % 10;
                score2 = rand() % 10;
            } else {
                printf("Ingresa el resultado del partido entre %s y %s (formato: goles1 goles2): ", teams[i], teams[j]);
                scanf("%d %d", &score1, &score2);
            }
            fprintf(file, "%s vs %s: %d - %d\n", teams[i], teams[j], score1, score2);
            if (score1 > score2) {
                points[i] += 3;
            } else if (score1 < score2) {
                points[j] += 3;
            } else {
                points[i] += 1;
                points[j] += 1;
            }
        }
    }
    fclose(file);

    // Mostrar tabla de resultados
    for (int i = 0; i < teamCount; i++) {
        printf("%s: %d puntos\n", teams[i], points[i]);
    }

    return 0;
}
