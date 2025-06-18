#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algorithms.h"


int main(void) {
    int *arr      = NULL;
    int  n        = 0;
    int  choice;

    srand((unsigned)time(NULL));

    do {
        printf("\n 1.Init \n 2.Print \n 3.Free \n 4.Sort \n 5.Search \n 6.Fib \n 0.Exit\n");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Input error\n");
            return EXIT_FAILURE;
        }

        switch (choice) {
            case 1:
                free(arr);
                arr = NULL;
                printf("N = ");
                if (scanf("%d", &n) != 1 n <= 0) {
                    fprintf(stderr, "Invalid size\n");
                    return EXIT_FAILURE;
                }
                arr = malloc(n * sizeof *arr);
                if (!arr) {
                    perror("malloc failed");
                    return EXIT_FAILURE;
                }
                for (int i = 0; i < n; i++) {
                    arr[i] = rand();
                }
                break;

            case 2:
                if (!arr) {
                    printf("Array not initialized\n");
                } else {
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                free(arr);
                arr = NULL;
                n   = 0;
                break;

            case 4:
                if (!arr) {
                    printf("Array not initialized\n");
                } else {
                    printf("Sel:  %.6f s\n", time_selection_sort(arr, n));
                    printf("Heap: %.6f s\n", time_heap_sort(arr, n));
                }
                break;

            case 5:
                if (!arr) {
                    printf("Array not initialized\n");
                } else {
                    int trials = 10000;
                    int *t = malloc(trials * sizeof *t);
                    if (!t) {
                        perror("malloc failed");
                        free(arr);
                        return EXIT_FAILURE;
                    }
                    for (int i = 0; i < trials; i++) {
                        t[i] = arr[rand() % n];
                    }
                    printf("Lin: %.6f s\n", time_linear_search(arr, n, t, trials));
                    printf("Bin: %.6f s\n", time_binary_search(arr, n, t, trials));
                    free(t);
                }
                break;

            case 6:
                {
                    int fn;
                    printf("Fib N = ");
                    if (scanf("%d", &fn) != 1  fn < 0) {
                        fprintf(stderr, "Invalid N\n");
                        free(arr);
                        return EXIT_FAILURE;
                    }
                    clock_t s = clock();
                    unsigned long long r = fib_memo(fn);
                    clock_t e = clock();
                    printf("Fib(%d) = %llu  Time = %.6f s\n",
                           fn, r, (double)(e - s) / CLOCKS_PER_SEC);
                }
                break;

            case 0:
                break;

            default:
                printf("Invalid option\n");
                break;
        }
    } while (choice != 0);

    free(arr);
    return EXIT_SUCCESS;
}