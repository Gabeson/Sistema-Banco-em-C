#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check = 0;

struct c_corrente{
    int numconta;
    int agencia;
    float saldo;
    char nome[10];
    int id;
}conta[10];

void operationError(){
    printf("\nOperacao Interrompida\nSem Contas registradas no Banco");
}

void addconta(){
    int esc,i=0;
    do{
    printf("\n===[Nova Conta]===\n");
    printf("Digite seu Nome:\n");
    fgets(conta[i].nome, 10, stdin);
    fgets(conta[i].nome, 10, stdin);
    printf("\n");
    printf("Digite o numero da Agencia: ");
    scanf("%d",&conta[i].agencia);
    printf("Digite o numero da Conta: ");
    scanf("%d",&conta[i].numconta);
    conta[i].saldo = 0;
    printf("\nDeseja adicionar outra Conta?\n1 - Adicionar Nova Conta\n2 - Nao adicionar\n");
    scanf("%d",&esc);
    i++;
    conta[i].id=i;
    if(esc==1){
        printf("\nAdicionando Nova Conta...\n");
        check += 1;
    }else if(i>1){
        printf("\n%d Contas Criadas com Sucesso\n",i);
    }else{
        printf("\n%dConta Criada com Sucesso\n",i);
    }
    }while(esc!=2);
}

void excluiconta(){
    int i,ag,num,esc;
    
    printf("\n===[Excluir Conta]===\n");
    printf("\nDigite o numero da Conta que deseja excluir\n");
    scanf("%d",&num);
    fflush(stdin);
    printf("\nDigite o numero da Agencia\n");
    scanf("%d",&ag);
    fflush(stdin);
    for(i=0;i<10;i++){
             if(num==conta[i].numconta && ag==conta[i].agencia){
            printf("\nConta [%d]",conta[i].id);
            fflush(stdin);
            printf("\nNome: %s",conta[i].nome);
            fflush(stdin);
            printf("\nAgencia: %d",conta[i].agencia);
            fflush(stdin);
            printf("\nNumero de Conta: %d",conta[i].numconta);
            fflush(stdin);
            printf("\nSaldo da Conta: %.2f",conta[i].saldo);
            fflush(stdin);
        printf("\nDeseja excluir essa Conta?\n1-sim\n2-não\n");
        scanf("%d",&esc);
        if(esc==1){
            conta[i].saldo = 0;
            conta[i].agencia = 0;
            conta[i].numconta = 0;
            
            printf("\nConta Excluida\n");
            }else{
                printf("\nRetornando para o menu...\n");
            }
        }
    }
}

void depositar(){
    int i,nconta,ag;
    float novosaldo[10],dep;
    
    printf("\nDigite o numero da Agencia\n");
    scanf("%d",&ag);
    printf("\nDigite o numero da Conta Corrente\n");
    scanf("%d",&nconta);
    for(i=0;i<10;i++){
    if(ag==conta[i].agencia && nconta==conta[i].numconta){
        printf("\nConta %d",i+1);
        printf("\nNome: %s",conta[i].nome);
        printf("\nSaldo Atual: %.2f",conta[i].saldo);
        printf("\nDigite o valor do deposito\n");
        scanf("%f",&dep);

        if(dep<=0){
            printf("\nValor Invalido\n");
        }else{
            printf("\nDeposito R$ %.2f",dep);
            printf("\n%.2f + %.2f",conta[i].saldo,dep);
            conta[i].saldo = conta[i].saldo+dep;
            printf("\nSaldo Atual: %.2f",conta[i].saldo);
            printf("\n");
            }
        }
    }
}

void saque(){
    int i,nconta,ag,retry;
    float valor;
    
    do{
    printf("\nDigite o numero da Agencia\n");
    scanf("%d",&ag);
    printf("\nDigite o numero da Conta Corrente que deseja fazer o saque\n");
    scanf("%d",&nconta);
    
    for(i=0;i<10;i++){
        if(ag==conta[i].agencia && nconta==conta[i].numconta){
        printf("\nConta %d",i+1);
        printf("\nNome: %s",conta[i].nome);
        printf("\nSaldo Atual: %.2f",conta[i].saldo);
        
        printf("\nDigite o valor que deseja sacar\n");
        scanf("%f",&valor);

        if(valor>conta[i].saldo){
            printf("\nValor de Saque Indisponivel\n");
            printf("\nDeseja realizar o saque novamente?\n1-sim\n2-não\n");
            scanf("%d",&retry);
        }else{
            printf("\nSaque R$ %.2f",valor);
            printf("%.2f - %.2f",conta[i].saldo,valor);
            conta[i].saldo = conta[i].saldo - valor;
            printf("\nSaldo Atual: %.2f",conta[i].saldo);
            printf("\n");
             printf("\nDeseja realizar o saque novamente?\n1 - Sim\n2 - Não\n");
         scanf("%d",&retry);
          }
        }
      }
  }while(retry==1);
}

void consulta(){
    int i,ag,nconta;
    printf("\n===[Consulta de Conta Corrente]===\n");
    printf("\nDigite o número da Agencia da Conta\n");
    scanf("%d",&ag);
    printf("\nDigite o numero da Conta\n");
    scanf("%d",&nconta);
    for(i=0;i<10;i++){
    if(ag==conta[i].agencia && nconta==conta[i].numconta){
        printf("\nConta %d",i+1);
        printf("\nNome: %s",conta[i].nome);
        printf("\nSeu Saldo Atual: R$ %.2f",conta[i].saldo);
        printf("\n");
        }
    }
}

void transferencia(){
    int i,orig_ag,orig_conta;
    int destiny_ag,destiny_conta;
    float transfer,origem,destino;
    origem=destino=0;

         printf("\n===[Transferencia entre Contas]===\n");
         printf("\nDigite o numero da Agencia da Conta de Origem\n");
         scanf("%d",&orig_ag);
         printf("\nDigite o numero da Conta de Origem\n");
         scanf("%d",&orig_conta);
    
         printf("\nDigite o numero da Agencia da Conta de Destino\n");
         scanf("%d",&destiny_ag);
         printf("\nDigite o numero da Conta de Destino\n");
         scanf("%d",&destiny_conta);  

    for(i=0;i<10;i++){
        if(orig_ag==conta[i].agencia && orig_conta==conta[i].numconta){
             printf("\nDados da Conta de Origem\n");
            printf("\nConta %d",i+1);
            printf("\nNome: %s",conta[i].nome);
            printf("\nSaldo Atual: %.2f",conta[i].saldo);
            printf("\n");
            origem = conta[i].saldo;
            conta[i].saldo = 0;
            
            printf("Digite o Valor da Transferencia\n");
            scanf("%f",&transfer);
            
            if(transfer>origem){
                printf("\nValor de tranferencia acima do limite de saldo da Conta\n");
                conta[i].saldo = origem;
                transfer = 0;
            }else if(transfer<=origem){
                printf("\nValor da Transferencia: R$ %.2f",transfer);
                origem = origem - transfer;
                conta[i].saldo = origem;
                printf("\nNovo Saldo de %s: %.2f",conta[i].nome,conta[i].saldo);
            }
        }
             if(destiny_ag==conta[i].agencia && destiny_conta==conta[i].numconta){
             printf("\nConta Destino\n");
            printf("\nConta %d",i+1);
            printf("\nNome: %s",conta[i].nome);
            printf("\nSaldo Atual: %.2f",conta[i].saldo);
            printf("\n");
            destino = conta[i].saldo;
            conta[i].saldo =0;
            
            if(transfer>origem){
                printf("\nEncerrando Transferencias...\n");
                conta[i].saldo = destino;
            }else if(transfer<=origem){
            destino = destino + transfer;
            conta[i].saldo = destino;
            printf("Novo Saldo de %s: %.2f",conta[i].nome,conta[i].saldo);
            printf("\n");
            }
        }
    }
}

void listagem(){
    int i;
    for(i=0;i<10;i++){
        if (conta[i].agencia != 0 && conta[i].numconta != 0) { 
        printf("\n");
        printf("\nConta [%d]\n",i+1);
        printf("Nome: %s",conta[i].nome);
        printf("\nAgencia: %d",conta[i].agencia);
        printf("\nNumero da Conta: %d",conta[i].numconta);
        printf("\nSaldo Disponível: %.2f",conta[i].saldo);
        printf("\n");
        } else {
        printf("\n");
        }
    }
}

void sair(){
    printf("\n");
    printf("\n[Encerrando Sistema]\nSaindo....\n");
    abort();
}

int main(void){
    int esc,i;
    system("clear");

    do{
        printf("\n===[Menu Bancario]===\n");
        printf("\n1 - Abrir Conta Corrente\n\n2 - Encerrar Conta Corrente\n\n3 - Depositar\n\n");
        printf("4 - Sacar\n\n5 - Consultar Saldo em Conta\n\n6 - Transferencia entre Contas\n\n");
        printf("7 - Listagem de Contas Correntes Abertas\n\n8 - Sair\n");
        scanf("%d",&esc);
        printf("\n");
    
        switch(esc){
            case 1: printf("\nAbrindo nova Conta Corrente\n");
            addconta();
            break;
            
            case 2:  
            if (check >= 1){
                printf("\nExclusão de Conta Corrente\n");
                excluiconta();
            } else {
               operationError();
            }
            break;
            
            case 3: 
            if (check >= 1){
                printf("\nDepositar\n");
                depositar();
            } else {
                operationError();
            }
            break;
            
            case 4: 
            if (check >= 1){
                printf("\nSacar\n");
                saque();
            } else {
                operationError();
            }
            break;
            
            case 5: 
            if (check >= 1){
                printf("\nConsultando Saldo\n");
                consulta();
            } else {
                operationError();
            }
            break;
            
            case 6: 
            if (check >= 1){
                printf("\nIniciando Transferencia entre Contas\n");
                transferencia();
            } else {
                operationError();
            }
            break;
            
            case 7: printf("\nVerificando Contas...");
            if (check >= 1){
                printf("\nLista de Contas Abertas:\n");
                listagem();
            } else {
                operationError();
            }
            break;
            
            case 8: 
            sair();
            break;

            default: printf("\nNenhuma opção selecionada\n");
            break;
        }
        printf("\n"); 
    }while(esc!=8);
}