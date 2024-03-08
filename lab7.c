#include<stdio.h>

// swap values
void swap (int * x, int * y) {

    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// select sort
int selectSort(int a[2][10], int n) {

    int swaps = 0;
    for (int i = 0; i < n; i++) {
        int low = i; 
        for (int x = low; x < n; x++) {
            // check if value is lower than low
            if (a[0][x] < a[0][low]) {
                low = x;
            }
        }
        // values not the same so swap
        if (a[0][low] != a[0][i]) {
            swap(&a[0][low], &a[0][i]);
            a[1][low]++;
            a[1][i]++;
            swap(&a[1][low], &a[1][i]);
            swaps++;
            low++;
        }
    }
    return swaps;
}

// bubble sort
int bubbleSort(int a[2][10], int n) {

    int swaps = 0;
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < n-1; x++) {
            // check if x > next value and swap
            if (a[0][x] > a[0][x+1]) {
                swap(&a[0][x], &a[0][x+1]);
                a[1][x]++;
                a[1][x+1]++;
                swap(&a[1][x], &a[1][x+1]);
                swaps++;
            }
        }
    }
    return swaps;
}   

// print bubble sort
void printBubb(int a[2][10], int n, int anum) {

    printf("\narray %d bubble sort:\n", anum);

    int swaps = bubbleSort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", a[0][i], a[1][i]);
    }
    printf("%d\n\n", swaps);
}

// print selection sort
void printSel(int a[2][10], int n, int anum) {

    printf("array %d selection sort:\n", anum);
    
    int swaps = selectSort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", a[0][i], a[1][i]);
    }
    printf("%d\n\n", swaps);
}

int main(void) {

    // arrays to sort
    int a1[2][10] = {97,16,45,63,13,22,7,58,72,0,0,0,0,0,0,0,0,0,0}; 
    int a2[2][10] = {90,80,70,60,50,40,30,20,10,0,0,0,0,0,0,0,0,0,0};
    int a1b[2][10] = {97,16,45,63,13,22,7,58,72,0,0,0,0,0,0,0,0,0,0}; 
    int a2b[2][10] = {90,80,70,60,50,40,30,20,10,0,0,0,0,0,0,0,0,0,0};

    int n = 9; // size of array
    int anum = 1; // array number 

    printBubb(a1, n, anum);
    printBubb(a2, n, anum+1);

    printSel(a1b, n, anum);
    printSel(a2b, n, anum+1);
}