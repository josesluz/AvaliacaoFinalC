#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Declara��o de vari�veis
int num = 0;
//Vari�veis para posi��es dos vetores professor, disciplina e turma
int posicaoProfessor = 0,posicaoDisciplina = 0, posicaoTurma = 0;
//Vari�veis para op��o de escolha dos switch
int opcaoMenu, opcaoProfessor, opcaoDisciplina, opcaoTurma;
//Vari�veis da estrutura de cria��o da turma
int escolhaDisciplina, escolhaProfessor, escolhaHorario;

  //Struct Professor
  typedef struct{
      char nome[20];
      char cargo[30];
      char dedicacaoExclusiva;
      char titulacao;
  } professor;

//Struct Disciplina
  typedef struct{
      char nomeDisciplina[20];
      int cargaHoraria;
  } disciplina;

//Struct Turma
  typedef struct{
      char horarioTurma;
  } turma;

  professor prof[3];
  disciplina disc[20];
  turma turm[25];

  // Fun��o para cadastro de Professores
    void cadastrarProfessores(){
    	do{
        printf("\n====================================================\n OP��O ESCOLHIDA:   1   | Cadastro de professores\n====================================================\n\n");
        printf("Nome: ");
        scanf("%s" ,&prof[posicaoProfessor].nome);
        printf("Cargo: ");
        scanf("%s" ,&prof[posicaoProfessor].cargo);
        printf("Dedica��o Exclusiva (S - Sim | N - N�o): ");
        scanf("%s" ,&prof[posicaoProfessor].dedicacaoExclusiva);
        printf("Titula��o (G - Graduado | E - Especialista | M - Mestre | D - Doutor ): ");
        scanf("%s" ,&prof[posicaoProfessor].titulacao);
        printf("\nESCOLHA UMA OP��O: 1 - Realizar novo cadastro | 2 - Voltar ao menu:\n" );
        printf("OP��O: ");
        scanf("%i", &opcaoProfessor);

        switch (opcaoProfessor) {
          case 1:
            posicaoProfessor++;
            cadastrarProfessores();
            break;
          case 2:
            menu();
            break;
          default:
            printf("Digite uma op��o v�lida");
            break;
        }
    } while (posicaoProfessor <= 2);
      }

      //Fun��o para cadastro de disciplinas
      void cadastrarDisciplinas(){
          printf("\n====================================================\n OP��O ESCOLHIDA:    2   | Cadastro de Disciplinas\n====================================================\n\n");
          printf("Disciplina: ");
          scanf("%s" ,&disc[posicaoDisciplina].nomeDisciplina);
          printf("Carga Hor�ria: ");
          scanf("%i" ,&disc[posicaoDisciplina].cargaHoraria);
          printf("\nESCOLHA UMA OP��O: 1 - Realizar novo cadastro | 2 - Voltar ao menu\n" );
          printf("OP��O: ");
          scanf("%i", &opcaoDisciplina);

          switch (opcaoDisciplina) {
            case 1:
              posicaoDisciplina++;
              cadastrarDisciplinas();
              break;
            case 2:
              menu();
              break;
            default:
              printf("Digite uma op��o v�lida");
              break;
          }
        }

        //Fun��o patra cadastro de turmas
        void cadastrarTurma(){
            do{
            printf("\n====================================================\n OP��O ESCOLHIDA:    3   | Cadastro de Turmas\n====================================================\n\n");
            printf("Escolha a Disciplina: ");
            for (num = 0; num <= posicaoDisciplina; num++){
                printf("%i" "%s" "%s" "%s" ,num ," - ",disc[num].nomeDisciplina ," | ");
              }
              printf("\nOP��O: ");
              scanf("%i" ,&escolhaDisciplina);

              printf("Escolha o Professor: ");
              for (num = 0; num <= posicaoProfessor; num++){
                  printf("%i" "%s" "%s" "%s" ,num ," - ",prof[num].nome ," | ");
                }
                printf("\nOP��O: ");
                scanf("%i" ,&escolhaProfessor);

                printf("Escolha um hor�rio: ");
                scanf("%s" ,&escolhaHorario);

              printf("\n\nESCOLHA UMA OP��O: 1 - Realizar novo cadastro | 2 - Voltar ao menu\n" );
              printf("OP��O: ");
              scanf("%i", &opcaoTurma);

            switch (opcaoTurma) {
              case 1:
                posicaoTurma++;
                cadastrarTurma();
                break;
              case 2:
                menu();
                break;
              //case 3:
                //exibirTurmas();
              default:
                printf("Digite uma op��o v�lida");
                break;
            }
          } while (opcaoTurma ==1);
        }
    //Fun��o para leitura dos professores cadastrados
    void exibirProfessores(){
      for (num = 0; num <= posicaoProfessor; num++){
          printf("%s" "%s" ,"\n\nNome: " ,prof[num].nome);
          printf("%s" "%s" ,"\nCargo: " ,prof[num].cargo);
          printf("%s" "%c" ,"\nDedica��o Exclusiva: " ,prof[num].dedicacaoExclusiva);
          printf("%s" "%c" ,"\nTitula��o: " ,prof[num].titulacao);
          printf("\n");
        }
    }

    //Fun��o para leitura das disciplinas cadastradas
    void exibirDisciplinas(){
      for (num = 0; num <= posicaoDisciplina; num++){
          printf("%s" "%s" ,"\n\nDisciplina: " ,disc[num].nomeDisciplina);
          printf("%s" "%i" ,"\nCarga Hor�ria: " ,disc[num].cargaHoraria);
          printf("\n");
        }
    }

    //Fun��o para leitura das turmas cadastradas VETORES PROFESSOR | DISCIPLINA | TURMAS
    void exibirTurmas(){
	//Vetor de disciplinas:
        printf("%i" "%s" "%s" "%s" "%i"," - " ,"Nome: " ,disc[num].nomeDisciplina ,"Carga Hor�ria: " ,disc[num].cargaHoraria);
        printf("\n");
        //Vetor de professores:
        printf("%i" "%s" "%s" ," - " ,"Nome: " ,prof[num].nome);

        //Vetor de Turmas:
        printf("%s" "%s" "%s" "%s" ," - " ,"Disciplina: " ,disc[posicaoDisciplina].nomeDisciplina ,"Professor: " ,prof[posicaoProfessor].nome);

            }

    //Menu Principal do programa
    int menu(){
      printf("\nESCOLHA UMA OP��O DESEJADA:\n\n====================================================\n OP��O |       A��O\n====================================================\n   1   | Cadastro de professores\n   2   | Cadastro de disciplinas\n   3   | Cadastro de turmas\n   4   | Cadastro de alunos\n   5   | Consulta de melhor aluno\n   6   | Disciplina com mais reprova��es\n   7   | Sair\n\n");
      printf("OP��O: ");
      scanf("%i", &opcaoMenu);
        switch (opcaoMenu){
        case 1:
          cadastrarProfessores();
          break;
        case 2:
          cadastrarDisciplinas();
          break;
          case 3:
        cadastrarTurma();  
          case 8:
        exibirProfessores();          
          break;
        default:
          printf (">>> A��o n�o implementada, escolha outra op��o <<<");
      }
    }

int main(void) {
	setlocale(LC_ALL,"portuguese");


    //Execu��o do menu principal
    menu();

    //Valida��o de dados cadastrados em professores e disciplinas
    printf("\n====================================================\n PROFESSORES CADASTRADOS \n====================================================\n\n");
    exibirProfessores();
    printf("\n====================================================\n DISCIPLINAS CADASTRADAS \n====================================================\n\n");
    exibirDisciplinas();
}
