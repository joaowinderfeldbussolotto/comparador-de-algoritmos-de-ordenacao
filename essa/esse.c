#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define MAX 50000;

int *generateRandomArray(int len, int mode)
{
  int *v = (int *)malloc(len * sizeof(int));
  int i = 0;
  srand(time(NULL));

  for (; i < len; i++)
  {
    if (mode == 1)
    {
        *(v + i) = i;
    }
    else if (mode == 2)
    {
      *(v + i) = len-i;
    }
    else
    {
      *(v + i) = rand() % MAX;
    }
  }
  return v;
}


void printArray(int *v, int len)
{
  int i = 0;
  printf("[");
  for (; i < len; i++)
  {
    printf("%d, ", *(v + i));
  }
  printf("]\n");
}

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return ((t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f);
}


void printInfo(char* methodName, struct timeval start, struct timeval stop, long long int numCompare, long long int numSwaps, int lenght){
  //double time = 0;
  float otherTimeAttempt = timedifference_msec(start, stop);
  //time = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
  printf("----%s----\n", methodName);
  printf("Tamanho: %d\n", lenght);
  //printf("Tempo: %lu (us) \n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
  //printf("Tempo: %f (s) \n", time);
  printf(" ESSE Tempo dnv: %f (ms) \n", otherTimeAttempt);
  printf("Numero de comparacoes: %lld\n", numCompare);
  printf("Numero de trocas: %lld\n", numSwaps);
}

void swap(int i, int j, int *v)
{
  int aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

void bubbleSort(int *v, int len)
{
  struct timeval start, stop;
  int i, j, aux;
  long long int numCompare, numSwaps;
  numCompare = numSwaps = 0;
  int isInOrder = 1;

  gettimeofday(&start, NULL);
  for (i = len - 1; i > 0; i--)
  {
    for (j = 0; j < i; j++)
    {
      if (v[j] > v[j + 1])
      {
        isInOrder = 0;
        swap(j, j + 1, v);
        numSwaps++;
      }
      numCompare++;
    }
    if (isInOrder)
    {
      gettimeofday(&stop, NULL);
      printInfo("Bubble sort", start, stop, numCompare, numSwaps, len);
      return;
    }
  }
  gettimeofday(&stop, NULL);
  printInfo("Bubble sort", start, stop, numCompare, numSwaps, len);
}

void selectionSort(int *v, int len)
{
  struct timeval start, stop;
  int i, j, min;
  long long int numCompare, numSwaps;
  numCompare = numSwaps = 0;
  gettimeofday(&start, NULL);
  for (j = 0; j < len - 1; j++)
  {
    min = j;
    for (i = j + 1; i < len; i++)
    {
      if (v[i] < v[min])
      {
        min = i;
      }
      numCompare++;
    }
    if (min != j)
    {
      swap(j, min, v);
      numSwaps++;
    }
  }
  gettimeofday(&stop, NULL);

  printInfo("Selection sort", start, stop, numCompare, numSwaps, len);
}

void insertionSort(int *v, int len)
{
   struct timeval start, stop;
   int i,j;
   long long int numCompare, numSwaps;
   numCompare = numSwaps = 0;
  gettimeofday(&start, NULL);
   for (i = 1; i < len; i++){
    j = i;
    while (j > 0 && v[j-1] > v[j]){
        numCompare++;
        swap(j,j-1, v);
        numSwaps++;
        j--;
    }
    if(j!=0){
      numCompare++;
    }

   }

  gettimeofday(&stop, NULL);
  printInfo("Insertion sort", start, stop, numCompare, numSwaps, len);

}


int main(int argc, char *argv[])
{

  // int lenght = 10000; 
  // int *v1 = generateRandomArray(lenght, 1);
  // bubbleSort(v1, lenght);

  // lenght = 50000;
  // int *v2 = generateRandomArray(lenght, 1);
  // bubbleSort(v2, lenght);

  // lenght = 100000;
  // int *v3 = generateRandomArray(lenght, 1);
  // bubbleSort(v3, lenght);

  int lenght = 10000; 
  int *v1 = generateRandomArray(lenght, 1);
  insertionSort(v1, lenght);

  lenght = 50000;
  int *v2 = generateRandomArray(lenght, 1);
  insertionSort(v2, lenght);

  lenght = 100000;
  int *v3 = generateRandomArray(lenght, 1);
  insertionSort(v3, lenght);
  
  
  //insertionSort(v, lenght);
  //selectionSort(v, lenght);
  return 0;
}
