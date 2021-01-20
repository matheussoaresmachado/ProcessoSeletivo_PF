#include <stdio.h> //Inserção de biblioteca de entrada e saída padrão

int main(){ //Função principal do programa
    int n = 0, m = 0; //Declaração das variáveis n (número de posições de memória) e m (quantidade de instruções a serem executadas)
    int tipo, posicao, numero; //Declaração das variáveis que irão armazenar o tipo de instrução, a posição e o número
    int i = 0, j = 0, aux = 0; //Declaração dos contadores i, j e da variável auxiliar

    scanf("%d %d", &n, &m); //Captura do usuário o número de posições de memória e a quantidade de instruções a serem executadas e salvas nas variáveis n e m respectivamente
    
    if(n <= 0 || m <= 0){ //Avalia se n ou m são menores ou iguais a zero
        printf("Numero de posicoes de memoria e quantidade de instrucoes a serem executadas devem ser maiores ou iguais a 1.\n"); //Mensagem de alerta ao usuário
        return 0; //Encerra o programa retornando 0
    }
        
    int vetor[n]; //Declaração de um vetor com n posições

    for(i = 0; i < n; i++) //Laço de repetição para percorrer todo o vetor
        vetor[i] = 0; //Atribui o valor 0 a todas as posições do vetor

    for(i = 0; i < m; i++){ //Laço de repetição para capturar m instruções
        scanf("%d", &tipo); //Captura do tipo de instrução

        if(tipo < 1 || tipo > 3){ //Avalia se tipo está fora do range de 1 a 3
            printf("Tipo de instrucao deve ser maior ou igual a 1 e menor ou igual a 3.\n"); //Mensagem de alerta ao usuário
            return 0; //Encerra o programa retornando 0
        }
        
        switch(tipo){ //Verifica o tipo de instrução
            case 1: //Caso seja 1
                scanf("%d %d", &posicao, &numero); //Captura a posição de início e o número

                if(posicao <= 0 || numero <= 0){ //Avalia se posicao ou numero é menor ou igual a zero
                    printf("Posicao de memoria e numero devem ser maiores ou iguais a 1.\n"); //Mensagem de alerta ao usuário
                    return 0; //Encerra o programa retornando 0
                }

                for(j = posicao-1; ( (j < n) && (numero != aux) ); j++){ //Laço de repetição para realizar o somatório salvando na posição j enquanto j for menor que n (tamanho do vetor) e o número for diferente da variável auxiliar
                    vetor[j] += (numero - aux); //Vetor na posição j recebe vetor na posição j + número menos variável auxiliar
                    aux++; //Incrementa a variável auxiliar
                }
                j = 0; //Reinicia a variável j com o valor 0
                aux = 0; //Reinicia a variável aux com o valor 0
                break; //Sai do case

            case 2: //Caso seja 2
                scanf("%d %d", &posicao, &numero); //Captura a posição de início e o número

                if(posicao <= 0 || numero <= 0){ //Avalia se posicao ou numero é menor ou igual a zero
                    printf("Posicao de memoria e numero devem ser maiores ou iguais a 1.\n"); //Mensagem de alerta ao usuário
                    return 0; //Encerra o programa retornando 0 
                }

                for(j = posicao-1; ( (j >= 0) && (numero != aux) ); j--){ //Laço de repetição para realizar o somatório salvando na posição j enquanto j for maior ou igual a zero (início do vetor) e o número for diferente da variável auxiliar
                    vetor[j] += (numero - aux); //Vetor na posição j recebe vetor na posição j + número menos variável auxiliar
                    aux++; //Incrementa a variável auxiliar
                }
                j = 0; //Reinicia a variável j com o valor 0
                aux = 0; //Reinicia a variável aux com o valor 0
                break; //Sai do case

            case 3: //Caso seja 3
                scanf("%d", &posicao); //Captura a posição a ser impressa

                if(posicao <= 0){ //Avalia se posicao é menor ou igual a zero
                    printf("Posicao de memoria deve ser maior ou igual a 1.\n"); //Mensagem de alerta ao usuário
                    return 0; //Encerra o programa retornando 0
                }

                printf("%d\n", vetor[posicao-1]); //Imprime o número salvo na posição requisitada do vetor e quebra linha
                break; //Sai do case

            default: 
                printf("Tipo de instrucao deve ser maior ou igual a 1 e menor ou igual a 3.\nDigite novamente:\n"); //Mensagem de alerta ao usuário
                return 0; //Encerra o programa retornando 0
        }
    }

    return 0; //Retorna zero
}