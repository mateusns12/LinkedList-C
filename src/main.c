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
	printf("\t Lets do this ¯\\_(ツ)_/¯ \n");
	Menu();	
	FreeList();
	printf(" Goodbye \U0001f984 \n");
	last = NULL;
	first = NULL;
	return 0;
}

void Init(float data){
	Dados * aux;
	//struct Dados * auxcp;
	aux = (Dados*)malloc(sizeof(Dados));
	aux->data = data;
	//auxcp = (struct Dados*)malloc(sizeof(struct Dados));
	if(first==NULL){
		//first = (struct Dados*)malloc(sizeof(struct Dados));
		first = aux;
		//first->next = NULL;
		//printf("\n\tFirst = NULL : first->data = %f\n",first->data);
		//printf("\n\tLast adress : %p\n\tFirst Next adress : %p\n",&last,&first->next);
	}else if(first != NULL){
		//printf("\n\tFirst != NULL\n");
		if(last == NULL){
			//printf("\n\tLast == NULL : ");
			//last = (struct Dados*)malloc(sizeof(struct Dados));
			
			last = aux;
			last->next = NULL;
			//printf("last->data = %f\n", last->data);
			first->next = last;
			Dados * temp;
			temp = first->next;
			//printf("First next data : %f\n",temp->data); 
			//free(temp);
		}else if(last != NULL) {
			//printf("\n\tLast != NULL : ");
			Dados * temp;
			temp = first->next;
			//printf("First next data : %f\n",temp->data);
			//aux = (struct Dados*)malloc(sizeof(struct Dados));
			//--------------------------
			//auxcp = last;
				 
			
			//aux->next = NULL;

			last->next = aux;
			last = last->next;
			
			//printf("last->data = %f\n",last->data);
			//free(aux);
			last->next = NULL;
		}
	}else {
		printf("¯\\_(ツ)_/¯");
	}	
	
	free(aux);
	//free(auxcp);
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
		
void PrintList(Dados * aux){
	//struct Dados * str = NULL;
	//aux = str;
	while(aux != NULL){
		printf("%f\n",aux->data);
		aux = aux->next;
	}
	//printf("\n%f\n",str->data);
	free(aux);
}

void FreeList(){
    Dados * aux = first;
    while(first!=NULL){
		aux = first;
        first=first->next;
    }
    printf("\nList free'd\n");	
	//printf("Last:%f ",last->data);
}
