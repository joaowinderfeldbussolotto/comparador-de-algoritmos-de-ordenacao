#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 50000
#define LEN 10

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
      *(v + i) = len -i;
    }
    else
    {
      *(v + i) = rand() % MAX;
    }
  }

  return v;
}

int getLenghtFromTerminal(int argc, char *argv[])
{
  if (argc > 1)
  {
    char *charNum = argv[1];
    return atoi(*(argv + 1));
  }
  else
  {
    return LEN;
  }
}

void printArrayToFile(int *v, int len, FILE *file)
{
  int i = 0;
  fprintf(file, "%d\n", len);

  for (; i < len; i++)
  {
    fprintf(file, "%d\n", *(v + i));
  }
}
char* createFileName(int mode, int lenght)
{
  char* filename = malloc(sizeof(char)*20);

  if (mode == 1)
  {
    strcpy(filename,"crescente-");
  }
  else if (mode == 2)
  {
    strcpy(filename,"decrescente-");
  }
  else
  {
    strcpy(filename,"aleatorio-");
  }
  char strLenght[10];
  sprintf(strLenght, "%d", lenght);
  strcat(filename,strLenght);

  return filename;
}

int main(int argc, char *argv[])
{
  int mode;
  int lenght = getLenghtFromTerminal(argc, argv);
  printf("Informe a ordem do vetor:\n 1 - crescente\n2 - decrescente\n3 - aleatorio\n");
  scanf("%d", &mode);

  int *v = generateRandomArray(lenght, mode);
  FILE *f = fopen(createFileName(mode, lenght), "w");
  printArrayToFile(v, lenght, f);
  return 0;
}