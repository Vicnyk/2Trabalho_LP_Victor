#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void heapHeap(bool vetorheap[], int met){
   int resp,i,j,espacoRequis,bestYet;
   char c,cNova;
   typedef struct {
      char letra;
      int tam,com;
   }memoria ;
   memoria mem[26];
   for(i=0;i<26;i++){mem[i].tam=0;}
   resp=0;
   while(resp !=6){
    printf("Digite o que deseja fazer:\n");
    if(met==1){
      printf("1-Digite 1 para mudar para o metodo best\n");
    }
    else{
      printf("1-Digite 1 para mudar para o metodo first\n");
    }
    printf("2-Digite 2 para adicionar alguma memoria ao heap\n");
    printf("3-Digite 3 para fazer um memoria apontar para outra area ja existente\n");
    printf("3-Digite 4 para retirar alguma memoria do heap\n");
    printf("4-Digite 5 para exibir o estado atual do heap e o metodo de escolha\n");
    printf("5-Digite 6 para fechar o programa\n");
    scanf("%d", &resp);
      switch(resp){
       //Muda o metodo, facil
       case 1:
         if(met==1){
            met = 2;
         }
         else{
            met = 1;
         }
       break;
       case 2:
         j=0;
         //Primeiro, acha um posicao vazia no vetor de letras
         while(mem[j].tam != 0){
            j++;
         }
         printf("Digite a letra correspondente e o tamanho da memoria adicionada\n");
         scanf(" %c %d", &mem[j].letra, &mem[j].tam);
         i=espacoRequis=0;
         if(met == 1){
            //Enquanto nao achou um lugar que cabe ou ate chegar no fim do heap
            while( (espacoRequis!=mem[j].tam) && (i!=16)){
               if(vetorheap[i]==false){
                    espacoRequis++;
                    i++;
               }
               else{
                espacoRequis=0;
                i++;
               }
            }
            if(i==16){
                printf("\nNao ha espaco de memoria restante");
                mem[j].letra = '0';
                mem[j].tam = 0;
            }
            else{
                mem[j].com = (i-espacoRequis);
                for((i-espacoRequis);(i-espacoRequis)<i;espacoRequis--){
                vetorheap[i-espacoRequis] = true;
                }
            j++;
            }
         }
         else{
            bestYet = 16;
            espacoRequis = 0;
            //Procura no heap inteiro o menor espaco
            for(i=0;i<15;i++){
               if(vetorheap[i] == false){
                    espacoRequis++;
               }
               else{
                //Se achou um "buraco", se enfie nele. Se achar outro menor depois, simplesmente saia do anterior e va para esse.
                if((espacoRequis<bestYet) && (espacoRequis >= mem[j].tam) ){
                    bestYet = espacoRequis;
                    mem[j].com =(i-espacoRequis);
                }
                espacoRequis=0;
               }
             }
                if(espacoRequis >= mem[j].tam && (espacoRequis<bestYet)){
                    mem[j].com =(i-espacoRequis);
                }
              for(i=(mem[j].com);i<(mem[j].com+mem[j].tam);i++){
                    vetorheap[i] = true;
               }
         }
         break;
       case 3:
        printf("Digite qual e a letra que voce gostaria de apontar e a outra letra\n");
        scanf(" %c %c", &c, &cNova);
        i=0;
        //achar dados da letra a ser copiada
        while(mem[i].letra != cNova && i!=26){
            i++;
        }
        if(i==26){
            printf("Esta letra nao esta no heap");
        }
        else{
            j=0;
            //verifica se é uma memoria nova sendo apontada para algo já existente ou se é uma área já no heap apontando para outro lugar.
            while(mem[j].letra != c && j!=26){
                j++;
            }
            if(j==26){
                j=0;
                //se é uma memória nova apontando, acha um local para ficar no vetor de letras.
                while(mem[j].tam !=0){
                    j++;
                }
                mem[j].letra = c;
                mem[j].tam = mem[i].tam;
                mem[j].com = mem[i].com;
            }
            //senão for nova, substitui os valores dela pela outra letra.
            else{
                mem[j].tam = mem[i].tam;
                mem[j].com = mem[i].com;
            }
        }
         break;
       case 4:
         printf("Qual letra do heap voce gostaria de retirar?\n");
         scanf(" %c", &c);
         i=j=0;
         while(mem[i].letra != c && i!=26){
            i++;
         }
         if(i==26){
            printf("Esta letra nao esta no heap");
         }
         else{
            for(j=(mem[i].com);j<(mem[i].com+mem[i].tam);j++){
                vetorheap[j]=false;
            }
                mem[i].letra = '0';
                mem[i].tam = 0;
         }
         break;
       case 5:
         if(met==1){
            printf("O metodo atual e first\n");
         }
         else{
            printf("O metodo atual e last\n");
         }
         for(i=0;i<26;i++){
            if(mem[i].tam != 0){
                printf("|Memoria %c|Tamanho %d|Comeca na %da posicao\n",mem[i].letra,mem[i].tam,(mem[i].com+1) );
            }
         }
         printf("O Heap esta assim:\n");
         for(i=0;i<15;i++){
          printf("%d|",vetorheap[i]);
         }
         printf("\n");
         break;
      }
   }
 }


void main (){
 int met,i;
 bool heap[15];
 for(i=0;i<15;i++){
    heap[i]=false;
 }
 met=1;
 printf("Digite qual metodo de HEAP voce gostaria de usar\n1-First\n2-Best\n");
 scanf(" %d", &met);
 heapHeap(heap,met);
}
