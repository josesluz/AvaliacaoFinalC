#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
	char nome[100];
	char cargo[30];
	char dedicacaoExclusiva;
	char titulacao;
} professor;

typedef struct{
	char nome[20];
	int cargaHoraria;
} disciplina;

typedef struct{
	disciplina disciplinaTurma;
	professor professorTurma;
	char horario[30];	
} turma;

typedef struct{
	char nome[40];
	int quantidadeTurmasCursadas;
	turma turmaAluno[25];
	float notas[25];
	float media;
} aluno;

int quantidadeProfessores = 0, quantidadeDisciplinas = 0, quantidadeTurmas = 0, quantidadeAlunos = 0, maisTurma = 1, numeroTurma, numerodeTurmas = 0, i, j, k;
float mediaAux;
char melhorAluno[40], alunoAux[40];
professor prof[20];
disciplina disc[20];
turma turm[25];
aluno al[500];

void cadastrarProfessores(){
	int opc;
	setlocale(LC_ALL,"portuguese");
	if (quantidadeProfessores < 20){
		for (i = 0; i < quantidadeProfessores; i++)
		{
		}
		printf("\n==========================\n OPÇÃO ESCOLHIDA:\n==========================\n   1   | Cadastro de professores\n\n");
		printf ("Nome: ");
		scanf (" %s", &prof[i].nome);
		printf ("Cargo: ");
		scanf (" %s", &prof[i].cargo);
		printf ("Dedicação exclusiva? S - Sim; N - Nao: ");
		scanf (" %c", &prof[i].dedicacaoExclusiva);
		printf ("Titulação: G - Graduado; E - Especialista; M - Mestre; D - Doutor: ");
		scanf (" %c", &prof[i].titulacao);
	}
	else
	{
		printf ("Número máximo de professores atingido\n");
	}
	for (i = 0; i <= quantidadeProfessores; i++)
	{
		printf ("%d	%d	%s	%s	%c	%c\n", i + 1, quantidadeProfessores + 1, prof[i].nome, prof[i].cargo, prof[i].dedicacaoExclusiva, prof[i].titulacao);
	}
	quantidadeProfessores++;
	printf ("Digite\n1 para cadastrar outro professor\n2 para voltar ao menu principal\n");
	scanf ("%d", &opc);
	switch (opc)
	{
		case 1:
			cadastrarProfessores ();
			break;
		case 2:
			main ();
			break;
		default:
			printf ("Opção não existente");
	}
}

void cadastrarDisciplinas(){
	int opc;
	setlocale(LC_ALL,"portuguese");
	if (quantidadeDisciplinas < 20){
		for (i = 0; i < quantidadeDisciplinas; i++)
		{
		}
		printf("\n==========================\n OPÇÃO ESCOLHIDA:\n==========================\n   2   | Cadastro de disciplinas\n\n");
		printf ("Nome: ");
		scanf (" %s", &disc[i].nome);
		printf ("Carga horária: ");
		scanf ("%d", &disc[i].cargaHoraria);
	}
	else
	{
		printf ("Número máximode disciplinas atingido");
	}
	for (i = 0; i <= quantidadeDisciplinas; i++)
	{
		printf ("%d	%d	%s	%d\n", i + 1, quantidadeDisciplinas + 1, disc[i].nome, disc[i].cargaHoraria);
	}
	quantidadeDisciplinas++;
	printf ("Digite\n1 para cadastrar outra disciplina\n2 para voltar ao menu principal\n");
	scanf ("%d", &opc);
	switch (opc)
	{
		case 1:
			cadastrarDisciplinas ();
			break;
		case 2:
			main ();
			break;
		default:
			printf ("Opção não existente");
	}
}

  void cadastrarTurmas(){
	int opc, quantidadeProfessorTurma;
	setlocale(LC_ALL,"portuguese");
	if (quantidadeTurmas < 25)
	{
		for (i = 0; i < quantidadeTurmas; i++)
		{
		}
		printf("\n==========================\n OPÇÃO ESCOLHIDA:\n==========================\n   3   | Cadastro de turmas\n\n");
		printf ("Disciplina: ");
		scanf (" %s", &turm[i].disciplinaTurma.nome);
		printf ("Professor: ");
		scanf (" %s", &turm[i].professorTurma.nome);
		printf ("Horario: ");
		scanf (" %s", &turm[i].horario);
		for (j = 0; turm[i].disciplinaTurma.nome != disc[j].nome; j++)
		{
		}
		turm[i].disciplinaTurma.cargaHoraria = disc[j].cargaHoraria;
		for (quantidadeProfessorTurma = 0; quantidadeProfessorTurma < i; quantidadeProfessorTurma++)
		{
		}
		if (quantidadeProfessorTurma < 3)
		{
			for (j = 0; turm[i].professorTurma.nome != prof[j].nome; j++)
			{
			}
			strcpy (turm[i].professorTurma.cargo, prof[j].cargo);
			turm[i].professorTurma.dedicacaoExclusiva = prof[j].dedicacaoExclusiva;
			turm[i].professorTurma.titulacao = prof[j].titulacao;
		}
		else
		{
			strcpy (turm[i].disciplinaTurma.nome, turm[i + 1].disciplinaTurma.nome);
			strcpy (turm[i].professorTurma.nome, turm[i + 1].professorTurma.nome);
			strcpy (turm[i].horario, turm[i + 1].horario);
			printf ("Número máximo de turmas atingido para o professor");
			cadastrarTurmas ();			
		}
	}
	else
	{
		printf ("Número máximo de turmas atingido");
	}
	for (i = 0; i <= quantidadeTurmas; i++)
	{
		printf ("%d	%d	%s	%s	%s\n", i + 1, quantidadeTurmas + 1, turm[i].disciplinaTurma.nome, turm[i].professorTurma.nome, turm[i].horario);
	}
	quantidadeTurmas++;
	printf ("Digite\n1 para cadastrar outra turma\n2 para voltar ao menu principal\n");
	scanf ("%d", &opc);
	switch (opc)
	{
		case 1:
			cadastrarTurmas ();
			break;
		case 2:
			main ();
			break;
		default:
			printf ("Opção não existente");
	}
  }
  
  void cadastrarAlunos(){
	int opc;
	float soma;
	setlocale(LC_ALL,"portuguese");
	if (quantidadeAlunos < 500)
	{
		for (i = 0; i < quantidadeAlunos; i++)
		{
		}
		printf("\n==========================\n OPÇÃO ESCOLHIDA:\n==========================\n   4   | Cadastro de alunos\n\n");
		printf ("Nome: ");
		scanf ("%s", &al[i].nome);
		maisTurma = 1;
		for (j = 0; maisTurma != 0; j++)
		{
			soma = 0;
			printf ("Numero da turma: ");
			scanf ("%d", &numeroTurma);
			for (k = 0; k < numeroTurma; k++)
			{
			}
			strcpy (al[i].turmaAluno[j].disciplinaTurma.nome, turm[k].disciplinaTurma.nome);
			strcpy (al[i].turmaAluno[j].professorTurma.nome, turm[k].professorTurma.nome);
			strcpy (al[i].turmaAluno[j].horario, turm[k].horario);
			printf ("Nota do aluno na disciplina: ");
			scanf ("%f", &al[i].notas[j]);
			for (k = -1; k < j; k++)
			{
				soma = soma + al[i].notas[j];
			}
			al[i].media = soma / (j + 1);
			printf ("%f\n", al[i].media);
			printf ("Outra turma? Digite 0 para encerrar cadastro de turmas para o aluno. ");
			scanf ("%d", &maisTurma);
			al[i].quantidadeTurmasCursadas++;
		}
		for (i = 0; i <= quantidadeAlunos; i++)
		{
			for (j = 0; j < al[i].quantidadeTurmasCursadas; j++)
			{
				printf ("%s	%s	%s	%f\n", al[i].turmaAluno[j].disciplinaTurma.nome, al[i].turmaAluno[j].professorTurma.nome, al[i].turmaAluno[j].horario, al[i].notas[j]);
			}
			printf ("%d\n", al[i].quantidadeTurmasCursadas);
		}
	}
	else
	{
		printf ("Numero maximo de alunos atingido");
	}
	for (i = 0; i <= quantidadeAlunos; i++)
	{
		printf ("%d	%d	%s\n", i + 1, quantidadeAlunos + 1, al[i].nome);
	}
	quantidadeAlunos++;
	printf ("Digite\n1 para cadastrar outro aluno\n2 para voltar ao menu principal\n");
	scanf ("%d", &opc);
	switch (opc)
	{
		case 1:
			cadastrarAlunos ();
			break;
		case 2:
			main ();
			break;
		default:
			printf ("Opcao nao existente");
	}
  }
  
  void consultarMelhorAluno(){
	for (i = 0; i <= quantidadeAlunos; i++)
	{
		if (al[i].media > mediaAux)
		{
			mediaAux = al[i].media;
			strcpy (alunoAux, al[i].nome);
		}
	}
	strcpy (melhorAluno, alunoAux);
	printf ("O aluno de melhor e %d\n", melhorAluno);
	main ();
  }
  
  void disciplinaComMaisReprovacoes(){
  }


int menu ()
{
	int opcao;
	setlocale(LC_ALL,"portuguese");	
	while (opcao != 7)
	{
		printf ("Digite\n1 para cadastrar professores\n2 para cadastrar disciplinas\n3 para cadastrar turmas\n4 para cadastrar alunos\n5 para consultar melhor aluno\n6 para disciplina com mais reprovações\n7 para sair\n");
		scanf ("%d", &opcao);
		return opcao;
	}
}
int main ()
{ 
	int minhaOpcao = 8;
	minhaOpcao = menu ();
	setlocale(LC_ALL,"portuguese");
	printf ("\n");
	switch (minhaOpcao)
	{
		case 1:
			cadastrarProfessores ();
			break;
		case 2:
			cadastrarDisciplinas ();
			break;
		case 3:
			cadastrarTurmas ();
			break;
		case 4:
			cadastrarAlunos ();
			break;
		case 5:
			consultarMelhorAluno ();
			break;
		case 6:
			disciplinaComMaisReprovacoes ();
			break;
		case 7:
			break;
		default:
			printf ("Opcao nao existente\n");
	}
	return 0;
}
