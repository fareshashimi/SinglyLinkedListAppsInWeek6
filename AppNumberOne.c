#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char name[50];
    struct Node *next;
}node;
node *head, *prevNode, *newNode, *deleted;

void find(char *wanted){
    node *p = head;
    prevNode = head;

    while(p->next!=NULL){
        p = p->next;
        if(strcmp(p->name, wanted) >= 0) break;
        prevNode = p;
    }
    printf("\n\n");
}

void add(char *s){
    newNode = malloc(sizeof(node));
    strcpy(newNode->name, s);
    find(newNode->name);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    printf("\n\n");
}

void delete(char *s){
    find(s);
    deleted = prevNode->next;
    prevNode->next = deleted->next;
    free(deleted);
    printf("\n\n");
}

void print(void){
    int x=1;
    node *p = head;

    p = p->next;
    while(p!=NULL){
        printf("%d. %s\n", x, p->name);
        p = p->next;
        x++;
    }
    printf("\n\n");
}

void findTheLongest(node *head){
    node *p, *longest;
    p = head;
    p = p->next;
    longest = p;

    while(p!=NULL){
        if(strlen(p->name) >= strlen(longest->name)){
            longest = p;
        }
        p = p->next;
    }
    printf("The longest: %s\nLength: %d\n\n", longest->name, strlen(longest->name));
    getchar();
}

void main(){
    int c;
    char s[50];
    head = malloc(sizeof(node));

    strcpy(head->name, "The top of the list:\n");
    head->next = NULL;

    while(1){
        system("cls");

        printf("1.Add.\n2.Delete.\n3.The longest name.\n4.Exit.\n\n");
        printf("Select your choice: ");
        scanf("%d", &c);

        switch(c){
            case 1:
                printf("\nName: ");
                gets(s);
                add(s);
                print();
            break;

            case 2:
                printf("\nName: ");
                gets(s);
                delete(s);
                print();
            break;

            case 3:
                findTheLongest(head);
                print();
            break;

            case 4:
                exit(0);
            break;

            default:
                printf("\n Wrong choice. Try again...\n\n");
            break;
        }
    }
}
