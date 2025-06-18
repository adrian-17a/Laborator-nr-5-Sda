
#ifndef ALGORITHMS_H
#define ALGORITHMS_H


void selection_sort(int *arr, int n);
void heapify(int *arr, int n, int i);
void heap_sort(int *arr, int n);

int linear_search(int *arr, int n, int x);
int binary_search(int *arr, int n, int x);

unsigned long long fib_memo(int n);


double time_selection_sort(const int *arr, int n);
double time_heap_sort(const int *arr, int n);
double time_linear_search(const int *arr, int n, const int *targets, int trials);
double time_binary_search(const int *arr, int n, const int *targets, int trials);

#endif // ALGORITHMS_H