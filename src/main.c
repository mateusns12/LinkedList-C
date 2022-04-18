#include <stdlib.h>
#include <stdio.h>

struct Dados{
	float data;
	struct Dados * next; 
};

struct Dados * first = NULL;
struct Dados * last = NULL;

void Init(float data);
void printList();
void Menu();

void Init(float data){
	struct Dados * aux = NULL;
	struct Dados * auxcp = NULL;
	aux = (struct Dados*)malloc(sizeof(struct Dados));
	auxcp = (struct Dados*)malloc(sizeof(struct Dados));
	if(first==NULL){
		first = (struct Dados*)malloc(sizeof(struct Dados));
		first->data = data;
		first->next = NULL;
		printf("\n\tFirst = NULL : first->data = %f\n",first->data);
		printf("\n\tLast adress : %p\n\tFirst Next adress : %p\n",&last,&first->next);
	}else if(first != NULL){
		printf("\n\tFirst != NULL\n");
		if(last == NULL){
			printf("\n\tLast == NULL : ");
			last = (struct Dados*)malloc(sizeof(struct Dados));
			last->data = data;
			last->next = NULL;
			printf("last->data = %f\n", last->data);
			first->next = last;
			struct Dados * temp;
			temp = first->next;
			printf("First next data : %f\n",temp->data); 
		}else if(last != NULL) {
			printf("\n\tLast != NULL : ");
			struct Dados * temp;                                       temp = first->next;                                        printf("First next data : %f\n",temp->data);
			aux = (struct Dados*)malloc(sizeof(struct Dados));
			//--------------------------
			auxcp = last;
	
			 
			aux->data = data;
			aux->next = NULL;

			last->next = aux;
			last = aux;
			
			
			
			printf("last->data = %f\n",last->data);
		}
	}else {
		printf("¯\\_(ツ)_/¯");
	}
}

void Menu(){
	char* options = "\n\t1 - Insert node\n\t2 - Print List\n\t5 - Exit\n";
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
				printList(first);
				break;
			case 5:
				printf("Exiting...");
				break;
			default:
				printf("\n\tInvalid\n");
		}
	}while(option != 5);
}
		
void printList(struct Dados * aux){
	struct Dados * str = NULL;
	//aux = str;
	while(aux != NULL){
		printf("%f\n",aux->data);
		aux = aux->next;
	}
	//printf("\n%f\n",str->data);
}

int main(){
	printf("\t Lets do this ¯\\_(ツ)_/¯ \n");
	Menu();
	printf(" Goodbye \U0001f984 \n");
	return 0;
}
