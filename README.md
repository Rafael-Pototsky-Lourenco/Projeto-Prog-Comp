# Sistema de Gestão de Contas Steam

## Descrição do Projeto

Este projeto em C implementa um sistema simples para gestão de contas e jogos na plataforma Steam. Ele permite que os usuários criem contas, visualizem contas existentes, excluam contas, comprem jogos de um catálogo e gerenciem saldo.

## Funcionalidades

1. **Cadastro de Contas:**
   - Permite criar contas com informações como ID, nome, apelido, email e senha.
   - Validações: O ID deve ser numérico e maior que 100. O nome deve conter apenas letras.

2. **Listagem de Contas:**
   - Exibe todas as contas cadastradas, ocultando as senhas com asteriscos por segurança.

3. **Exclusão de Contas:**
   - Remove uma conta pelo ID informado.

4. **Catálogo de Jogos:**
   - Exibe uma lista de jogos disponíveis para compra.
   - Permite que os usuários adicionem saldo à conta e comprem jogos, desde que tenham saldo suficiente.

5. **Persistência de Dados:**
   - Salva as contas em um arquivo (`contas.txt`) ao sair do programa.
   - Carrega contas salvas ao iniciar o programa.

## Estrutura de Dados

- **`Conta_Steam`**: Representa uma conta de usuário com os seguintes campos:
  - `id`: Identificador único da conta.
  - `nome`: Nome completo do usuário.
  - `apelido`: Apelido do usuário.
  - `idade`: Idade do usuário (não utilizada diretamente no programa).
  - `email`: Email do usuário.
  - `senha`: Senha do usuário.
  - `saldo`: Saldo disponível para compras.
  - `saldototal`: Saldo total na conta.

- **`catalogoGames`**: Representa os jogos disponíveis para compra:
  - `codigoJogo`: Código identificador do jogo.
  - `nomeJogo`: Nome do jogo.
  - `precoJogo`: Preço do jogo.

## Arquivo de Dados

- **Nome do Arquivo**: `contas.txt`
- Contém os dados persistidos das contas em formato estruturado.

## Execução do Programa

O programa apresenta um menu principal com as opções:

1. **Cadastrar Conta Steam**: Para criar uma nova conta.
2. **Listar Conta Steam**: Para exibir todas as contas cadastradas.
3. **Excluir Conta Steam**: Para remover uma conta pelo ID.
4. **Entre no Catálogo**: Para adicionar saldo, comprar jogos e visualizar a biblioteca do usuário.
5. **Sair**: Encerra o programa e salva os dados das contas.
