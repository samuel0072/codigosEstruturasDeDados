#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Programa de analise de trafego em uma cidade hipotetica
typedef struct info info;
typedef struct semaforo;
struct info{
  int tipo;
  short direcao;
  semaforo* objeto;
};

struct semaforo{
  short cor;
  short tempo;
  short tempo_mudar;
};

info** aloc_cidade(int n, int m);
void iniciar_cidade(info** cidade);

int main()
{
  int i, j;
  info** cidade = aloc_cidade(7, 7);
  iniciar_cidade(cidade);
  /*for(i = 0;i < 7; i++)
  {
    for(j = 0; j < 7; j++)
    {
      printf("%d ", (cidade[i][j]).tipo);
    }
    printf("\n");
  }*/

  return 0;
}

void iniciar_cidade(info** cidade)
{
  srand((unsigned)time(NULL));
  int i, j;
  for(i = 0; i < 7; i++)
  {
    for(j = 0;j < 7; j++)
    {
      if((i == 2) || (i == 4))
      {
        if((j == 2) || (j == 4))
        {
          cidade[i][j].tipo = 2;
          cidade[i][j]->objeto = (semaforo*)malloc(sizeof(semaforo));
          cidade[i][j]->objeto->cor = 1;
          cidade[i][j]->objeto->tempo = 0;
          cidade[i][j]->objeto->tempo_mudar = rand()%10;
        }
        else
        {
          cidade[i][j].tipo = 1;
          
        }
      }
      else if(i == 1 || i == 3 || i == 5)
      {
        if(j == 1 || j == 3 || j == 5)
        {
          cidade[i][j].tipo = 0;
        }
        else
        {
          cidade[i][j].tipo = 1;
        }
      }
      else
      {
        cidade[i][j].tipo = 1;
      }
    }
  }
}

info** aloc_cidade(int n, int m)
{
  info** M = (info**)malloc(n*sizeof(info*));
  int i;
  for(i = 0; i < n; i++)
  {
    M[i] = (info*)malloc(m*sizeof(info));
  }

  return M;
}
