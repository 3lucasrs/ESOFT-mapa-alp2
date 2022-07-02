/*
- ACADÊMICO: LUCAS RAFAEL DA SILVA
- RA: 22001488-5
- CURSO: BACHARELADO EM ENGENHARIA DE SOFTWARE
- DISCIPLINA: ALGORITMOS E LÓGICA DE PROGRAMAÇÃO II
SOFTWARE DESIGNADO A REGISTRAR E INFORMAR OS DADOS DE APLICAÇÕES DE VACINAS DO COVID-19
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

struct dadosCadastro
{
    int codigo;
    char nome[64];
    char cpf[15];
    char vacina[20];
    char data[10];
    int lote;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct dadosCadastro paciente[999];
    int operation, i = 0, j = 0, cod = 1;
    int found, y;
    char busca[15];
    char novaVacina;

    do
    {
        do
        {
            system("cls");
            printf("1 - Cadastrar Vacina\n");
            printf("2 - Listar Aplicações\n");
            printf("3 - Consultar por CPF\n");
            printf("4 - Sair\n");
            printf("Digite a operação desejada: ");
            fflush(stdin);
            scanf("%d", &operation);
        } while (operation < 0 || operation > 5);

        system("cls");
        switch (operation)
        {
        case 0:
            break;
        case 1:
            do
            {
                if (i > 998)
                {
                    printf("A lista atingiu sua capacidade máxima!\n");
                    system("pause");
                    system("cls");
                    break;
                }
                system("cls");

                printf("Código: %d\n", cod);
                paciente[i].codigo = cod;

                printf("Nome: ");
                fflush(stdin);
                gets(paciente[i].nome);

                printf("CPF: ");
                fflush(stdin);
                scanf("%s", &paciente[i].cpf);

                printf("Vacina: ");
                fflush(stdin);
                gets(paciente[i].vacina);

                printf("Data [MM/DD/AAAA]: ");
                fflush(stdin);
                scanf("%s", &paciente[i].data);

                printf("Lote: ");
                fflush(stdin);
                scanf("%d", &paciente[i].lote);

                i++;
                cod++;

                printf("\nCadastrar nova vacina? [s/n]: ");
                scanf(" %c", &novaVacina);

            } while (toupper(novaVacina) != 'N');
            break;
        case 2:
            if (i == 0)
            {
                printf("Não há nenhuma vacina cadastrada para ser exibida!\n");
            }
            else
                for (j = 0; j < i; j++)
                {
                    printf("Código: %d\n", paciente[j].codigo);
                    printf("Nome: %s\n", paciente[j].nome);
                    printf("CPF: %s\n", paciente[j].cpf);
                    printf("Vacina: %s\n", paciente[j].vacina);
                    printf("Data: %s\n", paciente[j].data);
                    printf("Lote: %d\n", paciente[j].lote);
                    printf("==================================\n");
                }
            system("Pause");
            break;
        case 3:
            printf("Digite o CPF de quem deseja buscar: ");
            scanf("%s", &busca);
            y = 0;
            found = 0;
            while ((y < i) && (found == 0))
            {
                if (strcmp(paciente[y].cpf, busca) == 0)
                {
                    found = 1;
                }
                else
                {
                    y++;
                }
            }
            if (found == 1)
            {
                printf("\nResultado encontrado:\n\n");
                printf("Código: %d\n", paciente[y].codigo);
                printf("Nome: %s\n", paciente[y].nome);
                printf("CPF: %s\n", paciente[y].cpf);
                printf("Vacina: %s\n", paciente[y].vacina);
                printf("Data: %s\n", paciente[y].data);
                printf("Lote: %d\n\n", paciente[y].lote);
            }
            else
            {
                printf("CPF não encontrado!\n\n");
            }

            system("pause");
            break;
        case 4:
            exit(0);
            break;
        }
    } while (operation != 0);

    system("pause");
    return 0;
}
