#include <stdio.h>
#include "std.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <zconf.h>

int main() {
    printf("Praktikum 4\n-------------------\n");
    //return aufgabe1();
    //aufgabe2_easy();
    aufgabe2();
    aufgabe3();
    return EXIT_SUCCESS;
}

/**
 * Aufgabe 1
 * @return Fehlercode bei FILE-Problemen
 */
int aufgabe1() {
    FILE *datei = openFile(getUserInput());
    char puffer[STD_ARR_SIZE];

    if (datei == NULL) {
        fclose(datei);
        return EXIT_FAILURE;
    } else {
        int lineCounter = 1;
        printf("Datei wird gelesen:\n");
        while (fgets(puffer, STD_ARR_SIZE, datei) != NULL) {
            printf("%d. Zeile: %s", lineCounter++, puffer);
        }
    }

    fclose(datei);
    return EXIT_SUCCESS;
}

/**
 * Aufgabe 2
 */
void aufgabe2() {
    int **vektor = gen_random(X_SIZE);
    printf("Zufallszahlen:\n");
    printVektor(vektor, X_SIZE);
    printf("\nSortieren:\n");
    quick_sort(vektor, X_SIZE);
    printVektor(vektor, X_SIZE);
    freeGenRandom(vektor, X_SIZE);
}

/**
 * Generiert ein zweidimensionales Array arr[anzahl][2]
 * @param anzahl - Anzahl der eindimensionalen Arrays mit der größe 2
 * @return Pointer auf das erste Element des ersten Arrays
 */
int **gen_random(int anzahl) {
    //int* ptrFelder[anzahl];
    int **ptrptr = malloc(anzahl *
                          sizeof(int *));     //Erstellt einen 2-Dimensionalen Pointer und für jeden Index bis Anzahl einen weiteren Pointer Speicherplatz
    if (ptrptr == NULL) {
        printf("Fehler bei Malloc!");
    }

    for (int i = 0; i < anzahl; ++i) {
        *(ptrptr + i) = malloc(sizeof(int) * 2);    //Erstellt für jeden Pointer zwei int Speicherplätze

        if (ptrptr[i] == NULL) {
            printf("Fehler bei Malloc!");
        }
    }

    //Zuweisung
    for (int i = 0; i < anzahl; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (j) {  //[i][1]
                *(*(ptrptr + i) + j) = (int) random() % 1000;
            } else {  //[i][0]
                *(*(ptrptr + i) + j) = i + 1;
            }
        }
    }
    return ptrptr;
}

/**
 * Gibt den allozierten Speicher aus gen_random wieder frei
 * @param ptrptr pointer des ersten Elments von zweidimensionalen Arrays
 * @param size Anzahl der eindimensionalen Arrays
 */
void freeGenRandom(int **ptrptr, int size) {
    for (int i = 0; i < size; ++i) {
        free(*(ptrptr + i));
    }
    free(ptrptr);
}

/**
 * Gibt den Vektor aus
 * @param ptrptr Vektor
 * @param size Größe des Vektors
 */
void printVektor(int **ptrptr, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf(":%d:\t", *(*(ptrptr + i) + j));
        }
        printf("\n");
    }
}


/**
 * Aufgabe 3
 */
void aufgabe3() {
    printf("Anzahl: \t Dauer:\n");
    for (int i = 10; i <= 100000000; i *= 10) {
        time_t vorher = time(NULL); // Anzahl Sekunden seit 1.1.1970 0:0
        int **ptr = gen_random(i);
        //printVektor(ptr, i);
        quick_sort(ptr, i);
        time_t nachher = time(NULL); // Anzahl Sekunden seit 1.1.1970 0:0
        printf("%d \t\t %d Sekunden\n", i, (int) (nachher - vorher));
        freeGenRandom(ptr, i);
    }
}


//Einfachere Aufgabe 2 -- nicht beachten

void aufgabe2_easy() {
    int *vektor = gen_random_easy(X_SIZE);
    printf("Zufallszahlen:\n");
    printVektorEasy(vektor);
    printf("\nSortieren:\n");
    sortVektor(vektor);
    printVektorEasy(vektor);
    free(vektor);
}

int *gen_random_easy(int anzahl) {
    int *ptr = malloc(sizeof(int) * anzahl * 2);
    for (int i = 0; i < anzahl; ++i) {
        *(ptr + (2 * i)) = i + 1;
        *(ptr + (2 * i) + 1) = (int) random() % 1000;
    }
    return ptr;
}


void printVektorEasy(int *ptr) {
    printf("Index\tZufallszahl\n");
    for (int i = 0; i < X_SIZE; ++i) {
        printf("%d\t\t", *(ptr + (2 * i)));
        printf("%d\n", *(ptr + (2 * i) + 1));
    }
}

void sortVektor(int *ptr) {
    for (int i = 0; i < X_SIZE; ++i) {
        for (int j = 0; j < X_SIZE; ++j) {
            int firstValue = *(ptr + 2 * i + 1);
            int nextValue = *(ptr + 2 * j + 1);
            int firstIndex = *(ptr + 2 * i);
            int nextIndex = *(ptr + 2 * j);
            if (firstValue < nextValue) {
                *(ptr + 2 * i + 1) = nextValue;
                *(ptr + 2 * j + 1) = firstValue;
                *(ptr + 2 * i) = nextIndex;
                *(ptr + 2 * j) = firstIndex;
            }
        }
    }
}
