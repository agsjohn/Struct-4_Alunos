#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define T 100

struct cadastro
{
  int matricula;
  char nome[50];
  int codigo;
  int nota1;
  int nota2;
  int nota3;
  float media;
} alunos[T];

main(){
  int escolha, x, cont, remover, aux;
  for(x = 0; x < T; x++){
    alunos[x].matricula = -1;
  }
  system("clear");
  do{
    printf("[0] - Inserir alunos\n[1] - Remover alunos\n[2] - Alterar dados\n[3] - Exibir alunos cadastrados\n[4] - Sair do programa\n");
    scanf("%i", &escolha);
    getchar();
    for(x = 0; x < T; x++){
      if(alunos[x].matricula == -1){
        cont = x;
        x = T;
      }
    }
    switch(escolha){
      case 0:
        system("clear");
        printf("Digite a matrícula do aluno: ");
        scanf("%i", &alunos[cont].matricula);
        getchar();
        printf("Digite o nome do aluno: ");
        gets(alunos[cont].nome);
        printf("Digite o codigo da disciplina: ");
        scanf("%i", &alunos[cont].codigo);
        getchar();
        for(x = 1; x <= 3; x++){
          printf("Digite a %iº nota do aluno: ", x);
          switch(x){
            case 1: 
              scanf("%i", &alunos[cont].nota1);
            break;
            case 2: 
              scanf("%i", &alunos[cont].nota2);
            break;
            case 3: 
              scanf("%i", &alunos[cont].nota3);
            break;
          }
          getchar();
        }
        alunos[cont].media = alunos[cont].nota1 + alunos[cont].nota2 + alunos[cont].nota3;
        alunos[cont].media = alunos[cont].media / 3;
        printf("\n");
      break;
      case 1:
        system("clear");
        printf("\nDigite o número do alunos que deseja deletar: ");
        scanf("%i", &remover);
        getchar();
        if(alunos[remover - 1].matricula == -1){
          printf("\nAluno não encontrado\n\n");
        } else {
          alunos[remover - 1].matricula = -1;
          system("clear");
        }
      break;
      case 2:
        system("clear");
        printf("Digite o número do aluno do qual deseja alterar os dados cadastrados: ");
        scanf("%i", &remover);
        getchar();
        if(alunos[remover - 1].matricula != -1){
          printf("Escolha qual informação deseja alterar:\n[0] - Matrícula\n[1] - Nome\n[2] - Código da disciplina\n[3] - Nota 1\n[4] - Nota 2\n[5] - Nota 3\n");
          scanf("%i", &aux);
          getchar();
          switch(aux){
            case 0:
              printf("Digite o novo código de matrícula: ");
              scanf("%i", &alunos[remover - 1].matricula);
              getchar();
            break;
            case 1:
              printf("Digite o novo nome: ");
              gets(alunos[remover - 1].nome);
            break;
            case 2:
              printf("Digite o novo código da disciplina: ");
              scanf("%i", &alunos[remover - 1].codigo);
              getchar();
            break;
            case 3:
              printf("Digite a nova nota 1: ");
              scanf("%i", &alunos[remover - 1].nota1);
              getchar();
            break;
            case 4:
              printf("Digite a nova nota 2: ");
              scanf("%i", &alunos[remover - 1].nota2);
              getchar();
            break;
            case 5:
              printf("Digite a nova nota 3: ");
              scanf("%i", &alunos[remover - 1].nota3);
              getchar();
            break;
            default:
              printf("Codigo inválido\n");
          }
          alunos[remover - 1].media = alunos[remover - 1].nota1 + alunos[remover - 1].nota2 + alunos[remover - 1].nota3;
          alunos[remover - 1].media = alunos[remover - 1].media / 3;
        } else {
          printf("Aluno não encontrado\n");
        }
      break;
      case 3:
        system("clear");
        printf("//--Alunos--// \n");
        for(x = 0; x < T; x++){
          if(alunos[x].matricula != -1){
            printf("Aluno nº %i\n", x + 1);
            printf("Matricula: %i\nNome: %s\nCodigo da disciplina: %i\nNota 1: %i\nNota 2: %i\nNota 3: %i\nMedia: %.1f\n", alunos[x].matricula, alunos[x].nome, alunos[x].codigo, alunos[x].nota1, alunos[x].nota2, alunos[x].nota3, alunos[x].media);
            printf("--------\n");
          }
        }
        printf("\n");
      break;
      case 4:
        printf("\nFinalizando programa\n");
        getchar();
      break;
      default:
        printf("\nEscolha inválida\n\n");
    }
  }while(escolha != 4);
}