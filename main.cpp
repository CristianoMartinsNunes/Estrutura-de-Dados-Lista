#include <cstdlib>
#include <iostream>
#include <stdio.h>
// Criação dos Tipos Abstratos de Dados TElemento & TLista

// Estrutura TElemento:
typedef struct tipoElemento 
               { int elemento;
                      } TElemento;

// Estrutura TLista:
typedef struct tipoLista
               { TElemento listaElemento[5];
                 int tamanhoLista;
                 int posicaoLista;
                      } TLista;

// Função Criar Lista:
void criarLista(TLista *pLista) 
{
     pLista->tamanhoLista = 0;
     pLista->posicaoLista = 0;
	 printf("\n -> Lista Criada c/Sucesso!!!\n\n");
}    

                          
// Função Inserir Elemento:                          
void inserirElemento(TLista *pLista) 
{	 
	 int elementoAuxiliar;

	 if(pLista->tamanhoLista == 0)
	   {
	       printf("\n -> Digite um Numero: ");
     	   scanf("%d",&elementoAuxiliar);	     	   
     	   pLista->listaElemento[pLista->tamanhoLista].elemento = elementoAuxiliar;
	       pLista->tamanhoLista++;           
		   printf("\n");                                       
	   }
	    
	 else if(pLista->tamanhoLista < 5) 
	 		{ 
			  printf( "\n -> Digite um Numero: ");
     	      scanf("%d",&elementoAuxiliar);
     	      printf("\n");  
     	      
			  for( int i = 0; i < pLista->tamanhoLista;  i++ ) 
			     { if(elementoAuxiliar < pLista->listaElemento[i].elemento)
					 { pLista->posicaoLista = i; 
			           for( int j = pLista->tamanhoLista; j > pLista->posicaoLista; j-- )
              		      { pLista->listaElemento[j].elemento = pLista->listaElemento[j-1].elemento;
						    	}   			    	
					   pLista->listaElemento[pLista->posicaoLista].elemento = elementoAuxiliar;
					   pLista->tamanhoLista++;  
					   break;						 				         										
                      }														
			     }
				    
				if(elementoAuxiliar > pLista->listaElemento[pLista->tamanhoLista-1].elemento)
				  { pLista->listaElemento[pLista->tamanhoLista].elemento = elementoAuxiliar;
					pLista->tamanhoLista++; }				  
		    }    	          
	 else
          { printf("\n -> Lista Cheia!!!\n\n"); }
}

// Função Excluir Elemento:
void excluirElemento(TLista *pLista) 
{
	 if(pLista->tamanhoLista == 0 )
	   {  
	      printf("\n -> Lista Vazia!!!\n\n");
	   }
	 else { 
	 	  	 printf("\n -> Informe Posicao: ");
             scanf("%d",&pLista->posicaoLista);
             
             if((pLista->posicaoLista >= 0) && (pLista->posicaoLista <= 4 ))
               {
                	for( int i = pLista->posicaoLista; i < pLista->tamanhoLista; i++ )
                	    {
                	    	pLista->listaElemento[i] = pLista->listaElemento[i+1];
                	    }
               	    
					pLista->tamanhoLista--;
					printf("\n -> Elemento Excluido da Lista!!!\n\n");                	
               }
               else {
               		      printf("\n -> Posicao Inexistente na Lista !!!\n\n");                      			        				 				  	 		 
                    }
         }

} 


// Função Localizar Elemento:
void localizarElemento(TLista *pLista) 
{ 
	 int elementoAuxiliar;
	 bool status = false;

     if(pLista->tamanhoLista == 0)
       { printf("\n -> Lista Vazia!!!\n\n");
                }
	else 
		{  printf("\n -> Informe o Elemento: ");
		   scanf("%d",&elementoAuxiliar);
		   
		   for( int i = 0; i <= 4; i++ )
		      {
		      	if(elementoAuxiliar == pLista->listaElemento[i].elemento )
		      	   { printf("\n");
		      	   	 printf("   Posicao: ");
                     printf("%d",i);     
                     printf("   Elemento: ");
                     printf("%d\n",pLista->listaElemento[i].elemento);
                     status = true;
                     break;
		      	   }
		      	
		      }
		    if (status == false)
				{ printf("\n -> Elemento nao Existe!!!\n"); } 
		}
		printf("\n");
}


// Função Mostrar Elementos:
void mostrarLista(TLista *pLista) 
{    
     if(pLista->tamanhoLista == 0)
         { printf("\n -> Lista Vazia!!!\n\n");
           }
     else
         {
           printf("\n-> Conteudo da Lista:\n\n");     
           for( int i = 0; i < pLista->tamanhoLista; i++)
              { printf("   Posicao: ");
                printf("%d",i);     
                printf("   Elemento: ");
                printf("%d\n",pLista->listaElemento[i].elemento); 
              }
           }
     printf("\n");
}
                                                       
using namespace std;

int main(int argc, char *argv[])
{   
    // Declaração de Variáveis: 
    TLista lista;
    int opcao;

    do {
        cout << "*******************************\n";
        cout << "   Estrutura de Dados Lista    \n";
        cout << "      - Lista Ordenada -       \n";
        cout << "*******************************\n";
        cout << " [ 01 ] - Criar Lista          \n";
        cout << " [ 02 ] - Inserir Elemento     \n";
        cout << " [ 03 ] - Excluir Elemento     \n";    
	    cout << " [ 04 ] - Localizar Elemento   \n";		     
        cout << " [ 05 ] - Mostrar Lista        \n";		
        cout << " [ 06 ] - Sair                 \n";    
        cout << "*******************************\n";
        cout << " Informe Opcao: ";
        cin >> opcao;
        cout << "*******************************\n\n";
        
        switch(opcao){
    
                      case 1 : {  system("CLS");
                                  criarLista(&lista);
                                  break;
                                   } 
                                  
                      case 2 : {  system("CLS");
                                  inserirElemento(&lista);
                                  break;
                                   } 
                     
                      case 3 : {  system("CLS");
                                  excluirElemento(&lista);
                                  break;
                                   }
                      
                      case 4 : {  system("CLS");
                                  localizarElemento(&lista);
                                  break;
                                  }
                                  
					  case 5 : {  system("CLS");
                                  mostrarLista(&lista);
                                  break;
                                  }                                                                                                      
                      }
    } while(opcao!=6);
    
    system("PAUSE");
    return EXIT_SUCCESS;   
}
 
