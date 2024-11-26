#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define contas 1
#define jogos 3
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
void DadosCadastrais(Conta_Steam cs[], catalogoGames cg[])
{
    int escolha = 0, i, j, idExcluir, escolhaJogo = 0, quantidadeJogo[3] = {0}, idCompra = 0;
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
        printf("Entre com a opcao desejada: ");
        scanf("%i", &escolha);
        getchar();
        printf("\n-------------------------------------------------------------------------------------------\n\n");
        switch (escolha)
        {
        case 1:
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
            for (i = 0; i < contas; i++)
            {
                printf("Informe o numero da conta (deve ser maior que 100): ");
                scanf("%i", &cs[i].id);
                getchar();
                while (cs[i].id < 100 && cs[i].id != 0)
                {
                    printf("Nao aceitamos valores menor que 100.\n");
                    printf("Informe um numero da conta maior que 100: ");
                    scanf("%i", &cs[i].id);
                    getchar();
                }
                if (cs[i].id == 0)
                {
                    printf("\nVoltando ao Menu Principal.\n\n");
                    break;
                }
                printf("Informe o Nome do Usuario (Esse nome so vai aparecer para seus amigos): ");
                fgets(cs[i].nome, 50, stdin);
                printf("Informe o Apelido do Usuario (Esse apelido sera visivel para todos): ");
                fgets(cs[i].apelido, 50, stdin);
                printf("Informe o email do Usuario: ");
                fgets(cs[i].email, 50, stdin);
                printf("Informe a senha do Usuario: ");
                fgets(cs[i].senha, 50, stdin);
                printf("\n*******************************************************************************************\n");
                printf("*\t  Usuario Cadastrado com Sucesso! Aproveite a Steam!\t\t\t          *\n");
                printf("*******************************************************************************************\n\n");
            }
            printf("-------------------------------------------------------------------------------------------\n\n");
            break;
        case 2:
            printf("\n*******************************************************************************************\n");
            printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
            printf("*\t\t\t\tLista de Conta Steam\t\t\t\t\t  *\n");
            printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
            for (i = 0; i < contas; i++)
            {
                printf("*******************************************************************************************\n");
                if (cs[i].id != 0)
                {
                    printf("*\n*\t\t\t\tNumero da Conta: %i \n", cs[i].id);
                    printf("*\t\t\t\tNome do Usuario: %s\n", cs[i].nome);
                    printf("*\t\t\t\tApelido do Usuario: %s\n", cs[i].apelido);
                    printf("*\t\t\t\tEmail do Usuario: %s\n", cs[i].email);
                    printf("*\t\t\t\tSenha do Usuario: ");
                    for (j = 1; j < strlen(cs[i].senha);j++)
                    {
                        printf("*");
                    }
                    printf("\n*\n");
                }
                printf("*******************************************************************************************\n");
            }
            printf("-------------------------------------------------------------------------------------------\n\n");
            break;
        case 3:
            printf("\n*******************************************************************************************\n");
            printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
            printf("*\t\t\t\tExclusao de Conta Steam\t\t\t\t\t  *\n");
            printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
            printf("*******************************************************************************************\n");
            printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
            printf("*\t\t\tEntre com valor de conta = 0 para encerrar.\t\t\t  *\n");
            printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
            printf("*******************************************************************************************\n\n");
            for (i = 0; i < contas; i++)
            {
                printf("Escreva o numero da conta a ser excluida: ");
                scanf("%i", &idExcluir);
                getchar();
                if (idExcluir == 0)
                {
                    printf("\nVoltando ao Menu Principal.\n\n");
                    break;
                }
                while (idExcluir != cs[i].id)
                {
                    printf("Digite um id correto.\n");
                    printf("Escreva o numero da conta a ser excluida: ");
                    scanf("%i", &idExcluir);
                    getchar();
                }
                if (idExcluir == cs[i].id)
                {
                    printf("Numero da Conta: %i\n", cs[i].id);
                    printf("Nome do Usuario: %s\n", cs[i].nome);
                    printf("Apelido do Usuario: %s\n", cs[i].apelido);
                    printf("Email do Usuario: %s\n", cs[i].email);
                    printf("Senha do Usuario: *********\n");
                    printf("Confirmar a exclusao? [S / N]: ");
                    scanf(" %c", &apague);
                    getchar();
                    while (apague != 'S' && apague != 's' && apague != 'n' && apague != 'N')
                    {
                        printf("\nEscreva a opcao corretamente.\n");
                        printf("Confirmar a exclusao? [S / N]: ");
                        scanf(" %c", &apague);
                        getchar();
                    }
                    if (apague == 'S' || apague == 's')
                    {
                        cs[i].id = 0;
                        strcpy(cs[i].nome, "");
                        strcpy(cs[i].apelido, "");
                        strcpy(cs[i].email, "");
                        strcpy(cs[i].senha, "");
                        printf("\n*******************************************************************************************\n");
                        printf("*  Conta Excluida. Ficamos tristes em despedir de voce :(\t\t\t\t  *\n");
                        printf("*******************************************************************************************\n");
                    }
                    else if (apague == 'N' || apague == 'n')
                    {
                        printf("\n*******************************************************************************************\n");
                        printf("*\t\t\t\t\tOperacao cancelada!\t\t\t\t\t\t  *\n");
                        printf("*******************************************************************************************\n");
                    }
                    printf("\n");
                }
            }
            printf("-------------------------------------------------------------------------------------------\n\n");
            break;
        case 4:
            escolhaJogo = 0;
            while (escolhaJogo != 4)
            {
                printf("*******************************************************************************************\n");
                printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
                printf("*\t\t\t1 - Adicionar Saldo\t\t\t\t\t  *\n");
                printf("*\t\t\t2 - Comprar Jogos\t\t\t\t\t\t  *\n");
                printf("*\t\t\t3 - Mostrar Biblioteca\t\t\t\t\t\t  *\n");
                printf("*\t\t\t4 - Voltar ao Menu\t\t\t\t\t\t  *\n");
                printf("*\t\t\t\t\t\t\t\t\t\t\t  *\n");
                printf("*******************************************************************************************\n\n");
                printf("Entre com a opcao desejada: ");
                scanf("%i", &escolhaJogo);
                getchar();
                switch (escolhaJogo)
                {
                case 1:
                    for (i = 0; i < contas; i++)
                    {
                        printf("Adicione saldo na conta: ");
                        scanf("%f", &cs[i].saldo);
                        cs[i].saldototal = cs[i].saldototal + cs[i].saldo;
                    }
                    printf("Saldo Adicionado!\n");
                    break;
                case 2:
                    for (i = 0; i < jogos; i++)
                    {
                        printf("Nome: %s\n", cg[i].nomeJogo);
                        printf("Preco: R$ %.2f\n", cg[i].precoJogo);
                        printf("ID: %d\n\n", cg[i].codigoJogo);
                    }
                    printf("Digite o ID do jogo para comprar: ");
                    scanf("%d", &idCompra);
                    for (i = 0; i < jogos; i++)
                    {
                        if (idCompra == cg[i].codigoJogo)
                        {
                            printf("SALDO: %.2f\n", cs[i].saldototal);
                            printf("Gostaria de comprar %s no valor de %d [S/N]: ", cg[i].nomeJogo, cg[i].precoJogo);
                            scanf(" %c", &compra);
                            if (compra == 'N' || compra == 'n')
                            {
                                printf("Compra nao efetuada. \n");
                                break;
                            }
                            else if (compra == 'S' || compra == 's')
                            {
                                if (cs[i].saldototal >= cg[i].precoJogo)
                                {
                                    printf("Compra efetuada para a conta.\n");
                                    cs[i].saldototal = cs[i].saldototal - cg[i].precoJogo;
                                    printf("Saldo restante: %.2f\n", cs[i].saldototal);
                                    quantidadeJogo[i]++;
                                    break;
                                }
                                else if (cs[i].saldototal < cg[i].precoJogo)
                                {
                                    printf("Saldo insuficiente, compra cancelada.\n ");
                                    break;
                                }
                            }
                        }
                    }
                    break;
                case 3:
                    for (i = 0; i < contas; i++)
                    {
                        printf("Usuario: %s \n", cs[i].apelido);
                        printf("Saldo em conta: %.2f\n", cs[i].saldototal);
                    }
                    for (i = 0; i < jogos; i++)
                    {
                        printf("Nome: %s\t", cg[i].nomeJogo);
                        printf("Quantidade: %i\n", quantidadeJogo[i]);
                    }
                    break;
                default:
                printf("Escreva uma opcao valida[1|2|3|4]: \n");
                    break;
                }
            }
            break;
        case 5:
            printf("*******************************************************************************************\n");
            printf("*\t\t\t\t\tAte Breve!\t\t\t\t\t  *\n");
            printf("*******************************************************************************************\n");
            break;
        default:
            printf("Escolha um valor correto de 1 a 5! \n");
        }
    }
}
int main()
{
    catalogoGames cg[jogos] = {
        {1010, "Call Of Duty", 300},
        {2030, "EAFC", 150},
        {4080, "PICO PARK", 20}};
    Conta_Steam cs[contas];
    DadosCadastrais(cs, cg);
    return 0;
}