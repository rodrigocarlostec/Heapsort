#include <stdio.h>
#include <stdlib.h>

void heapsort(int *vetor, int tam){

    int i, troca;

    for(i = tam/2; i>=0; i--){
        controiHeap(vetor,tam, i);
        // Build the Heap structure
    }

    while(tam>0){
        troca = vetor[0];
        vetor[0] = vetor[tam];
        vetor[tam] = troca;
        controiHeap(vetor, --tam, 0);
    }
}

void controiHeap(int *vetor, int tam, int indice_raiz){
    
    int ramificacao, valor;
    valor = vetor[indice_raiz];

    while(indice_raiz<= tam/2){
        
        ramificacao = 2* indice_raiz;
        if(ramificacao < tam && vetor[ramificacao] < vetor[ramificacao+1]){
            ramificacao++;
        }
        if(valor >= vetor[ramificacao]){
            break;
        }

        vetor[indice_raiz] = vetor[ramificacao];
        indice_raiz = ramificacao;
    }
    vetor[indice_raiz] = valor;
}

int main()
{
    
    int v[]= {9,56,34,78,92,23,12,45,65,3,2,7,20};
    // It is the vector
    
    int tam = sizeof(v)/sizeof(int);
    // It is the length of vector
    int i;

    for(i=0; i<tam; i++){
        printf("%d ", v[i]);
        // Present the vector without order
    }

    heapsort(v, tam-1);
    // Function for HeapSort

    printf("\n");

    for(i=0; i<tam; i++){
        printf("%d ", v[i]);
        // Vector already in order
    }

    return 0;
}
