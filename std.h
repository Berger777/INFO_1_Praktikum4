#define STD_ARR_SIZE 128
#define X_SIZE  10

FILE *openFile(char *dateiname);

char *getUserInput();

int aufgabe1();

void aufgabe2();

void aufgabe2_easy();

void aufgabe3();

void quick_sort(int **vektor, int size);

void freeGenRandom(int **ptrptr, int size);

void sortVektor(int *ptr);

void printVektor(int **ptrptr, int size);

void printVektorEasy(int *ptr);

int *gen_random_easy(int anzahl);

int **gen_random(int anzahl);