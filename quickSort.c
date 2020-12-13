#include <stdio.h>
#include <string.h>

#define PUFFER_GROESSE 128

/**
 * Diese Funktion sortiert die Daten im Parameter daten
 * mit dem Quicksort-Algorithmus. Sie sollte nicht direkt
 * aufgerufen werden, sondern über die Funktion
 * "quick_sort(char *daten)".
 * @param daten Die Daten, die sortiert werden sollen
 * @param links Der Index links
 * @param rechts Der Index rechts
 */
void qs(int **vektor, int links, int rechts) {
    int l, r;
    int m, y;

    l = links;
    r = rechts;
    m = vektor[(links + rechts) / 2][1]; // mittleres Element

    do {
        while (vektor[l][1] < m && l < rechts) l++; // suche Element für "große Klasse"
        while (m < vektor[r][1] && r > links) r--;  // suche Element für "kleine Klasse"

        if (l <= r) {  // vertausche Elemente
            y = vektor[l][1];
            vektor[l][1] = vektor[r][1];
            vektor[r][1] = y;
            l++;
            r--;
        }
    } while (l <= r);

    if (links < r) qs(vektor, links, r); // Aufruf für "kleine Klasse"
    if (l < rechts) qs(vektor, l, rechts); // Aufruf für "große Klasse"
}

/**
* Diese Funktion sortiert das Array daten mit dem
* Quicksort-Algorithmus
* @param daten Das Array mit den Daten, die sortiert werden sollen. Die Rückgabe erfolgt über das gleiche Array (Call by reference).
*/
void quick_sort(int **vektor, int size) { // Quicksort vorbereiten;
    qs(vektor, 0, size - 1);
}

