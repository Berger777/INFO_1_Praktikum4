#include "dateiFunktionen.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "std.h"

char input[STD_ARR_SIZE];

/**
 * Liest einen String ein
 * @return charPointer auf den String vom UserInput
 */
char *getUserInput() {
    fgets(input, STD_ARR_SIZE, stdin);
    strtok(input, "\n");
    //printf("%s",input);
    return input;
}


/**
 * Öffnet ein File
 * @param dateiname Name der Datei
 * @return Fehlercode
 */
FILE *openFile(char *dateiname) {
    FILE *file = fopen(dateiname, "r");
    if (file == NULL) {
        fprintf(stderr, "Datei konnte nicht gefunden werden!");
        return NULL;
    }
    return file;
}