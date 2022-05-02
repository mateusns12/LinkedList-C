#include <stdlib.h>
#include <stdio.h>

typedef struct dados{
	float data;
	struct dados * next; 
}Dados;

Dados * first = NULL;
Dados * last = NULL;

void Init(float data);
void PrintList(Dados * aux);
void Menu();
void FreeList();

int main(){
	printf("\n\t Lets do this ¯\\_(ツ)_/¯ \n");
	Menu();	
	FreeList();
	printf("\nGoodbye \U0001f984 \n");
	last = NULL;
	first = NULL;
	return 0;
}

void Init(float data){
	Dados * aux = (Dados*)malloc(sizeof(Dados));
	aux->data = data;
	if(first==NULL){
		first = aux;
		last = first;	
		//free(aux);	
	}else {
		last->next = aux;
		last = last->next;
		//free(aux);
	}last->next = NULL;	
	//printf("¯\\_(ツ)_/¯");
	free(aux);	
	
}

void Menu(){
	char* options = "\n\t1 - Insert node\n\t2 - Print List\n\t3 - Free list\n\t5 - Exit\n";
	int option = 0;
	float data = 0;
	do{
		printf("%s",options);
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter value : ");
				scanf("%f",&data);
				Init(data);
				break;
			case 2:
				PrintList(first);
				break;
			case 3:
				FreeList();
				break;
			case 5:
				printf("Exiting...");
				break;
			default:
				printf("\n\tInvalid\n");
		}
	}while(option != 5);
}
		
