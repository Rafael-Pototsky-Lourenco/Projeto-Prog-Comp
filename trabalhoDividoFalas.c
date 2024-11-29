//RAFA

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define jogos 3
#define ARQUIVO_CONTAS "contas.txt"

int apenasNumero(const char *str)
{
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (!isdigit(str[i]))
            {
                return 0;
            }
        }
        return 1;
}

int apenasLetra(const char *str)
{
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (!isalpha(str[i]) && !isspace(str[i]))
            {
                return 0;
            }
        }
        return 1;
}

typedef struct
{
    int id;
    char nome[50];
    char apelido[50];
    int idade;
    char email[50];
    char senha[50];
    float saldo;
    float saldototal;
} Conta_Steam;

typedef struct
{
    int codigoJogo;
    char nomeJogo[30];
    float precoJogo;

} catalogoGames;

void DadosCadastrais(Conta_Steam **cs, int *numContas, catalogoGames cg[])
{
    int escolha = 0, i, j, idExcluir, escolhaJogo = 0, quantidadeJogo[jogos] = {0}, idCompra = 0, idValidacao;
    char apague, compra;

    while (escolha != 5)
    {
        printf("*******************************************************************************************\n");
        printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
        printf("*\t  SSSSSSSSS\t TTTTTTTTTTTTTTTTT EEEEEEE\t    AAA\t\tMMM     MMM\t  *\n");
        printf("*\t SSSSSSSSS\t TTTTTTTTTTTTTTTTT EEEEEE \t   AAAAA\tMMM     MMM\t  *\n");
        printf("*\tSSS\t\t\tTTTT\t   EEE\t\t  AAAAAAA\tMMMM   MMMM\t  *\n");
        printf("*\tSS \t\t\tTTTT\t   EEE\t\t AAAA AAAA\tMMMMM MMMMM\t  *\n");
        printf("*\tSSS\t\t\tTTTT\t   EEE\t\t AAA   AAA\tMMMMMMMMMMM\t  *\n");
        printf("*\tSSSSSSSSSS \t\tTTTT\t   EEEEEEE\t AAA   AAA\tMMMMMMMMMMM\t  *\n");
        printf("*\t SSSSSSSSSS\t\tTTTT\t   EEEEEEE\t AAAAAAAAA\tMMM  M  MMM\t  *\n");
        printf("*\t        SSS\t\tTTTT\t   EEE\t\t AAAA AAAA\tMMM     MMM\t  *\n");
        printf("*\t         SS\t\tTTTT\t   EEE\t\t AAA   AAA\tMMM     MMM\t  *\n");
        printf("*\t        SSS\t\tTTTT\t   EEE\t\t AAA   AAA\tMMM     MMM\t  *\n");
        printf("*\t SSSSSSSSS \t\tTTTT\t   EEEEEE \t AAA   AAA\tMMM     MMM\t  *\n");
        printf("*\tSSSSSSSSS  \t\tTTTT\t   EEEEEEE\t AAA   AAA\tMMM     MMM\t  *\n");
        printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
        printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
        printf("*******************************************************************************************\n");
        printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
        printf("*\t\t\t1 - Cadastrar Conta Steam\t\t\t\t\t  *\n");
        printf("*\t\t\t2 - Listar Conta Steam\t\t\t\t\t\t  *\n");
        printf("*\t\t\t3 - Excluir Conta Steam\t\t\t\t\t\t  *\n");
        printf("*\t\t\t4 - Entre no catalogo\t\t\t\t\t\t  *\n");
        printf("*\t\t\t5 - Sair\t\t\t\t\t\t \t  *\n");
        printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
        printf("*******************************************************************************************\n\n");
        
        printf("\nEntre com a opcao desejada: ");
        scanf("%i", & escolha);
        getchar();

        printf("\n-------------------------------------------------------------------------------------------\n\n");

        switch (escolha)
        {
            case 1:
            {
                printf("\n*******************************************************************************************\n");
                printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
                printf("*\t\t\tCadastro de Conta Steam\t\t\t\t\t\t  *\n");
                printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
                printf("*******************************************************************************************\n");
                printf("*******************************************************************************************\n");
                printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
                printf("*\t\tEntre com valor de conta = 0 para encerrar.\t\t\t\t  *\n");
                printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
                printf("*******************************************************************************************\n\n");

                Conta_Steam novaConta;
                char idStr[10];
                
                printf("Informe o numero da conta (deve ser maior que 100): ");
                fgets(idStr, sizeof(idStr), stdin);
                strtok(idStr, "\n");

                if (strcmp(idStr, "0") == 0)
                {
                    printf("\nVoltando ao menu principal.\n");
                    break;
                }
                
                while (!apenasNumero(idStr) || atoi(idStr) <= 100)
                {
                    if (strcmp(idStr, "0") == 0)
                    {
                        printf("\nVoltando ao menu principal.\n");
                        break;
                    }
                    
                    printf("Numero invalido. Informe um numero maior que 100: ");
                    fgets(idStr, sizeof(idStr), stdin);
                    strtok(idStr, "\n");
                }

                if (strcmp(idStr, "0") == 0)
                {
                    break;
                }

                novaConta.id = atoi(idStr);

                printf("Informe o Nome do Usuario: ");
                fgets(novaConta.nome, sizeof(novaConta.nome), stdin);
                strtok(novaConta.nome, "\n");

                while (!apenasLetra(novaConta.nome))
                {
                    printf("Informe o Nome do Usuario apenas com letras: ");
                    fgets(novaConta.nome, sizeof(novaConta.nome), stdin);
                    strtok(novaConta.nome, "\n");
                } 

                printf("Informe o Apelido do Usuario: ");
                fgets(novaConta.apelido, sizeof(novaConta.apelido), stdin);
                strtok(novaConta.apelido, "\n");

                printf("Informe o email do Usurio: ");
                fgets(novaConta.email, sizeof(novaConta.email), stdin);
                strtok(novaConta.email, "\n");

                printf("Informe a senha do Usuario: ");
                fgets(novaConta.senha, sizeof(novaConta.senha), stdin);
                strtok(novaConta.senha, "\n");

                novaConta.saldo = 0;
                novaConta.saldototal = 0;

                *cs = realloc(*cs, (*numContas + 1) * sizeof(Conta_Steam));
                if (!(*cs))
                {
                    printf("Erro de memoria. Encerrando o programa.\n");
                    exit(EXIT_FAILURE);
                }

                (*cs)[*numContas] = novaConta;
                (*numContas)++;

                printf("\n*******************************************************************************************\n");
                printf("*\t  Usuario Cadastrado com Sucesso! Aproveite a Steam!\t\t\t          *\n");
                printf("*******************************************************************************************\n\n");
                break;
            }
            
            case 2:
            {
                printf("\n*******************************************************************************************\n");
                printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
                printf("*\t\t\t\tLista de Contas Steam\t\t\t\t\t  *\n");
                printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");

                if (*numContas == 0)
                {
                    printf("*\tNenhuma conta cadastrada.\n");
                }

                else
                {
                    for (int i = 0; i < *numContas; i++)
                    {
                        if ((*cs)[i].id != 0)
                        {
                            printf("*******************************************************************************************\n");
                            printf("* ID: %d\n", (*cs)[i].id);

                            printf("* Nome do Usuario: %s\n", (*cs)[i].nome);

                            printf("* Apelido do Usuario: %s\n", (*cs)[i].apelido);

                            printf("* Email do Usuario: %s\n", (*cs)[i].email);

                            printf("* Senha do Usuario: ");
                            int senhaLen = strlen((*cs)[i].senha);
                            for (int j = 0; j < senhaLen; j++)
                            {
                                printf("*");
                            }
                            printf("\n");

                            printf("* Saldo Total: R$%.2f\n", (*cs)[i].saldototal);
                        }
                    }
                }

                printf("*******************************************************************************************\n");
                break;
            }
//RAFA

//EDUARDO
           case 3:
{
    printf("\n*******************************************************************************************\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
    printf("*\t\t\t\tExclusao de Conta Steam\t\t\t\t\t  *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
    printf("*******************************************************************************************\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
    printf("*\t\t\tEntre com valor de conta = 0 para encerrar.\t\t\t  *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
    printf("*******************************************************************************************\n\n");

    int idExcluir;
    char confirmar;

    while (1) 
    {
        printf("Escreva o numero da conta a ser excluida (ou 0 para encerrar): ");
        if (scanf("%i", &idExcluir) != 1) 
        {
            printf("Entrada invalida. Por favor, insira um numero.\n");
            getchar(); 
            continue; 
        }

        getchar(); 

        if (idExcluir == 0) 
        {
            printf("Encerrando a exclusao de contas. Voltando ao menu principal...\n");
            break; 
        }

        int contaEncontrada = 0;
        for (i = 0; i < *numContas; i++) 
        {
            if ((*cs)[i].id == idExcluir)
            {
                contaEncontrada = 1;
                printf("Numero da Conta: %d\n", (*cs)[i].id);
                printf("Deseja realmente excluir esta conta? [S/N]: ");
                scanf(" %c", &confirmar);
                getchar();

                if (confirmar == 'S' || confirmar == 's')
                {
                    (*cs)[i].id = 0; 
                    printf("\n*******************************************************************************************\n");
                    printf("*  Conta Excluida. Ficamos tristes em despedir de voce :(\t\t\t\t  *\n");
                    printf("*******************************************************************************************\n");
                    printf("Voltando ao menu principal...\n");
                    break; 
                }
                else
                {
                    printf("Exclusao cancelada. Voltando ao menu principal...\n");
                    break; 
                }
            }
        }

        if (contaEncontrada)
        {
            break;
        }

        if (!contaEncontrada)
        {
            printf("\nConta com o ID %d nao encontrada. Tente novamente.\n", idExcluir);
        }

        printf("-------------------------------------------------------------------------------------------\n\n");
    }
    break; 
}


        case 4:
        {
            printf("Digite o ID da conta para acessar o catalogo: ");
            scanf("%i", & idValidacao);
            getchar();

            int contaEncontrada = -1;
            for (i = 0; i < *numContas; i++)
            {
                if ((*cs)[i].id == idValidacao)
                {
                    contaEncontrada = i;
                    break;
                }
            }

            if (contaEncontrada == -1)
            {
                printf("Conta nao encontrada. Retornando ao menu principal.\n");
                break;
            }

            escolhaJogo = 0;
            while (escolhaJogo != 4)
            {
                printf("*******************************************************************************************\n");
                printf("*\t\t\t1 - Adicionar Saldo\t\t\t\t\t  *\n");
                printf("*\t\t\t2 - Comprar Jogos\t\t\t\t\t\t  *\n");
                printf("*\t\t\t3 - Mostrar Biblioteca\t\t\t\t\t\t  *\n");
                printf("*\t\t\t4 - Voltar ao Menu\t\t\t\t\t\t  *\n");
                printf("*******************************************************************************************\n\n");

                printf("\nEntre com a opcao desejada: ");
                scanf("%i", & escolhaJogo);
                getchar();

                switch (escolhaJogo)
                {
                    case 1:
                    {
                        printf("Digite o valor que deseja adicionar a conta: ");
                        float saldoAdicionado;

                        scanf("%f", & saldoAdicionado);
                        (*cs)[contaEncontrada].saldototal += saldoAdicionado;
                        
                        printf("Saldo atualizado! Novo saldo: R$%.2f\n", (*cs)[contaEncontrada].saldototal);
                        break;
                    }
                    case 2:
                    {
                        printf("Jogos disponiveis:\n");
                        for (i = 0; i < jogos; i++)
                        {
                            printf("ID: %d | Nome: %s | Preco: R$ %.2f\n", cg[i].codigoJogo, cg[i].nomeJogo, cg[i].precoJogo);
                        }

                        printf("Digite o ID do jogo que deseja comprar: ");
                        scanf("%i", & idCompra);

                        int jogoEncontrado = -1;
                        for (i = 0; i < jogos; i++)
                        {
                            if (idCompra == cg[i].codigoJogo)
                            {
                                jogoEncontrado = i;
                                break;
                            }
                        }

                        if (jogoEncontrado == -1)
                        {
                            printf("Jogo nao encontrado. Tente novamente.\n");
                            break;
                        }

                        if ((*cs)[contaEncontrada].saldototal >= cg[jogoEncontrado].precoJogo)
                        {
                            (*cs)[contaEncontrada].saldototal -= cg[jogoEncontrado].precoJogo;
                            quantidadeJogo[jogoEncontrado]++;
                            printf("Compra realizada com sucesso! Saldo restante: R$ %.2f\n", (*cs)[contaEncontrada].saldototal);
                        }

                        else
                        {
                            printf("Saldo insuficiente.\n");
                        }
                        break;
                    }
                    case 3:
                    {
                        printf("Usuario: %s\n", (*cs)[contaEncontrada].apelido);

                        printf("Saldo em conta: R$ %.2f\n", (*cs)[contaEncontrada].saldototal);

                        printf("Jogos na biblioteca:\n");
                        for (i = 0; i < jogos; i++)
                        {
                            if (quantidadeJogo[i] > 0)
                            {
                                printf("%s (Quantidade: %d)\n", cg[i].nomeJogo, quantidadeJogo[i]);
                            }
                        }
                        break;
                    }
                    case 4:
                    {
                        printf("Voltando ao menu principal.\n");
                        break;
                    }
                    default:
                    {
                        printf("Opcao invalida. Escolha novamente.\n");
                        break;
                    }
                }
            }
            break;
        }
        case 5:
        {
            printf("*******************************************************************************************\n");
            printf("*\t\t\t\t\tAte Breve!\t\t\t\t\t  *\n");
            printf("*******************************************************************************************\n");
            break;
        }
        default:
        {
            printf("Escolha um valor correto de 1 a 5! \n");
            break;
        }
        }
    }
}
//EDUARDO

// ANDRE
void SalvarContas(Conta_Steam *cs, int numContas)
{
    FILE *arquivo = fopen(ARQUIVO_CONTAS, "w");

    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo para salvar os dados.\n");
        return;
    }

    for (int i = 0; i < numContas; i++)
    {
        if (cs[i].id != 0)
        {
            fprintf(arquivo, "ID: %d\n", cs[i].id);

            fprintf(arquivo, "Nome: %s\n", cs[i].nome);

            fprintf(arquivo, "Apelido: %s\n", cs[i].apelido);

            fprintf(arquivo, "Email: %s\n", cs[i].email);

            fprintf(arquivo, "Senha: %s\n", cs[i].senha);

            fprintf(arquivo, "Saldo Total: R$%.2f\n", cs[i].saldototal);

            fprintf(arquivo, "---------------------------------\n");
        }
    }

    fclose(arquivo);
    printf("Contas salvas com sucesso!\n");
}

void CarregarContas(Conta_Steam **cs, int *numContas)
{
    FILE *arquivo = fopen(ARQUIVO_CONTAS, "r");

    if (!arquivo)
    {
        printf("Nenhum arquivo encontrado, começando sem contas salvas.\n");
        return;
    }

    Conta_Steam novaConta;
    char buffer[100];

    while (fscanf(arquivo, "ID: %d\n", & novaConta.id) != EOF)
    {
        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "Nome: %[^\n]", novaConta.nome);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "Apelido: %[^\n]", novaConta.apelido);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "Email: %[^\n]", novaConta.email);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "Senha: %[^\n]", novaConta.senha);

        fgets(buffer, sizeof(buffer), arquivo);
        sscanf(buffer, "Saldo Total: R$%f", & novaConta.saldototal);

        fgets(buffer, sizeof(buffer), arquivo);

        *cs = realloc(*cs, (*numContas + 1) * sizeof(Conta_Steam));

        if (!(*cs))
        {
            printf("Erro de memória ao carregar contas.\n");
            fclose(arquivo);
            return;
        }

        (*cs)[*numContas] = novaConta;
        (*numContas)++;
    }

    fclose(arquivo);
    printf("Contas carregadas com sucesso!\n");
}

void main()
{
    catalogoGames cg[jogos] =
    {
        {1010, "Call Of Duty", 300},
        {2030, "EAFC", 150},
        {4080, "PICO PARK", 20}
    };

    Conta_Steam *cs = NULL;

    int numContas = 0;

    CarregarContas(&cs, &numContas);

    DadosCadastrais(&cs, &numContas, cg);

    SalvarContas(cs, numContas);

    if (cs != NULL)
    {
        free(cs);
    }
}

//ANDRE
