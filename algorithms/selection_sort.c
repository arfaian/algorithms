//
//  SelectionSort.c
//  algorithms
//
//  Created by Arian Arfaian on 3/12/14.
//  Copyright (c) 2014 arfaian. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "cairo.h"
#include "sort.h"

void sort(int array[]);
void show(int array[]);
void exch(int array[], int i, int j);
int less(int a, int b);

void execute() {
  int array[N];
  srand(time(NULL));

  for (int i = 0; i < N; i++) {
    array[i] = rand() % 1000;
  }

  show(array);
  sort(array);
  show(array);
}

void sort(int array[]) {
  for (int i = 0; i < N; i++) {
    int min = i;
    for (int j = i; j < N; j++) {
      if (less(array[j], array[min])) {
        min = j;
      }
    }
    exch(array, i, min);
  }
}

int less(int a, int b) {
  return a < b;
}

void exch(int array[], int i, int j) {
  int t = array[i];
  array[i] = array[j];
  array[j] = t;
}

void show(int array[]) {
  for (int i = 0; i < N; i++) {
    printf("index: %d, value: %d\n", i, array[i]);
  }
}