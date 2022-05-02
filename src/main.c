#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct data{	
	float data;
	char * string;
	struct data * next; 
}Data;

Data * first = NULL;
Data * last = NULL;

void Menu();
void Insert(float data, char string[]);
void Print();
void Delete();
void RemoveLast();
void RemoveSelected();
void RemoveLast();

int main(){
	printf("\n\t Lets do this ¯\\_(ツ)_/¯ \n");
	Menu();	
	Delete();
	printf("\nGoodbye \U0001f984 \n");
	last = NULL;
	first = NULL;
	return 0;
}

void Menu(){
	char * options = "\n\t1 - Insert Data\n\t2 - Print Data\n\t3 - Delete Data\n\t4 - Remove Last\n\t5 - Remove selected\n\t6 - Exit\n";     
	int option = 0;	
	char stropt[5];	
	do{
		printf("%s",options);
		scanf("%s",&stropt);
        option = atoi(stropt);
		switch(option){
			case 1:
				float data = 0;
				char string[20];
				printf("Enter value : ");
				scanf("%f",&data);
				printf("Enter a string: ");
				scanf("%s",&string);
				Insert(data,string);
				break;
			case 2:
				Print();
				break;
			case 3:
				Delete();
				break;
			case 4:
				RemoveLast();
				break;
			case 5:
				RemoveSelected();
				break;
			case 6:
				printf("Exiting...");
				break;
			default:
				printf("\n\tInvalid\n");
		}
	}while(option != 6);
}

void Insert(float data, char string[]){    
    if(first==NULL){   
		first = (Data*)calloc(1,sizeof(struct data));   		//using calloc, to not let float value unnitialized
		first->data = data; 		     
        first->string = (char*)malloc(21 * sizeof(char)); 
        strcpy(first->string,string);		
        last = first;
    }else{
		last->next = (Data*)calloc(1,sizeof(struct data));
		last->next->data = data;
		last->next->string = (char*)malloc(21 * sizeof(char));        
        strcpy(last->next->string,string);		
        last = last->next;
    }last->next = NULL;	
}
		
void Print(){
	Data * aux = first;
    while(aux!=NULL){
        printf("\n\tObject value: %f\n\tObject string: %s\n",aux->data,aux->string);
		//printf("\n\tObject value: %f\n",aux->data);
		//printf("\n\tObject string: %s\n",aux->string);
        aux = aux->next;
    }
}

void Delete(){
    Data * aux = first;
    while(first!=NULL){
        aux = first->next;
        free(first->string);
        free(first);
        first = aux;
    }free(aux);
}

void RemoveSelected(){
    Data * aux = first;
    Data * actual = aux;
    char * str = malloc(20 * sizeof(char));
    scanf("%s",str);
    if(aux==NULL){
        printf("\nList empty");
    }else if(!strcmp(aux->string,str)){
        Data * save = first->next;
        free(first->string);
        free(first);
        first = NULL;
        first = save;
    }else if(!strcmp(aux->next->string,str) && aux->next == last){
        free(last->string);
        free(last);
        first->next = NULL;
        last = first;
    }else{        
        while(aux->next!=NULL){
            actual = aux;
            if(!strcmp(aux->next->string,str)){
                break;
            }
            aux = aux->next;
        }      
        Data * save = aux->next->next;
        free(aux->next->string);
        free(aux->next);
        actual->next = save;
    }  
    free(str);
}

void RemoveLast(){
    Data * aux = first;
    Data * actual;
    if(aux==NULL){
        printf("\nList empty");
    }else if(aux->next==NULL){
        free(first->string);
        free(first);
        first = NULL;
    }else if(aux->next == last){
        free(last->string);
        free(last);
        first->next = NULL;
        last = first;
    }else{ 
        while(aux->next->next!=NULL){
            aux = aux->next;
        }
        Data * lst = aux->next;    
        free(lst->string);
        free(lst);
        last = aux;   
        last->next = NULL;  
    }   
}