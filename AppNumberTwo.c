#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int num;
    char name[50];
    char surname[50];
    int vize, final;
    struct node *next;
}node;

node *createStdList(node *head){
    int i, n;
    node *p;

    printf("How many students we have?\n");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        if(i==0){
            head = malloc(sizeof(node));
            p = head;
        }
        else{
            p->next = malloc(sizeof(node));
            p = p->next;
        }
        printf("\nRecord No.%d\n", i+1);
        printf("Number: "); scanf("%d", &p->num);
        printf("Name: "); scanf("%s", p->name);
        printf("Surname: "); scanf("%s", p->surname);
        printf("Midterm's grade: "); scanf("%d", &p->vize);
        printf("Final's grade: "); scanf("%d", &p->final);
    }
    p->next = NULL;
    printf("\n\n");

    return head;
}

node *addNewStudent(node *head){
    int stdNum;
    node *p, *q;

    node *newNode = malloc(sizeof(node));
    printf("New record:\n");
    printf("Number: "); scanf("%d", &newNode->num);
    printf("Name: "); scanf("%s", newNode->name);
    printf("Surname: "); scanf("%s", newNode->surname);
    printf("Midterm's grade: "); scanf("%d", &newNode->vize);
    printf("Final's grade: "); scanf("%d", &newNode->final);

    printf("\nInsert a student number that will be added:\n");
    printf("Press 0 to add it to the end of the list.\n");
    scanf("%d", &stdNum);

    p = head;
    if(p->num==stdNum){
        newNode->next = p;
        head = newNode;
    }
    else{
        while((p->next!=NULL) && (p->num!=stdNum)){
            q = p;
            p = p->next;
        }

        if(p->num==stdNum){
            q->next = newNode;
            newNode->next = p;
        }
        else if(p->next==NULL){
            p->next = newNode;
            newNode->next = NULL;
        }
    }
    printf("\n\n");

    return head;
}

node *deleteTheStudent(node *head){
    int stdNum;
    node *p, *q;

    printf("Insert a student number to be deleted:\n");
    scanf("%d", &stdNum);

    p = head;
    if(p->num==stdNum){
        head = p->next;
        free(p);
    }
    else{
        while((p->next!=NULL) && (p->num!=stdNum)){
            q = p;
            p = p->next;
        }

        if(p->num==stdNum){
            q->next = p->next;
            free(p);
        }
        else if(p->next==NULL){
            printf(" No lists in the system.\n\n");
        }
    }
    printf("\n\n");

    return head;
}

double calculateSuccGrade(int vize, int final){
    return (vize*0.4) + (final*0.6);
}

void mostSuccStudent(node *head){
    node *p = head;
    node *mostSucc = head;

    while(p->next!=NULL){
        p = p->next;
        if((calculateSuccGrade(p->vize, p->final)) > (calculateSuccGrade(mostSucc->vize, mostSucc->final))){
                mostSucc = p;

        }
    }
    printf("The most successful student:\n");
    printf("Number: %d\nFull Name: %s %s\nResult: %.2f\n\n\n", mostSucc->num, mostSucc->name, mostSucc->surname, calculateSuccGrade(mostSucc->vize, mostSucc->final));
}

void calculateAvgClass(node *head){
    double averageGrdPoint = 0;
    double sum = 0;
    int x = 0;

    node *p = head;
    if(p==NULL){
        printf("No entries in the list!\n");
    }
    else{
        do{
            sum+=calculateSuccGrade(p->vize, p->final);
            p = p->next;
            x++;
        }while(p!=NULL);
        averageGrdPoint = sum/x;
        printf("The average grade point is %.2f\n\n\n", averageGrdPoint);
    }
}

void printStdList(node *head){
    double grade;
    int x=1;
    node *p = head;

    while(p!=NULL){
        printf("Record No.%d\n", x);
        printf("Number: %d\n", p->num);
        printf("Full Name: %s %s\n", p->name, p->surname);
        printf("Midterm's grade: %d\n", p->vize);
        printf("Final's grade: %d\n", p->final);
        grade = (p->vize*0.4) + (p->final*0.6);
        printf("Your final grade id %.2f\n\n", grade);
        p = p->next;
        x++;
    }
    printf("\n\n");
}

int main(){
    int c;
    node *head;

    while(1){
        printf("1.Creating a record of a student.\n2.Adding a new record of a student.\n3.Deleting a record of a student.\n4.Finding the student with highest final term grade.\n5.Calculating the final term average of the class.\n6.Printing the records of the students.\n7.Exit.\n\n");
        printf("Select your choice: ");
        scanf("%d", &c);
        printf("\n");

        switch(c){
            case 1:
                head = createStdList(head);
            break;

            case 2:
                head = addNewStudent(head);
            break;

            case 3:
                head = deleteTheStudent(head);
            break;

            case 4:
                mostSuccStudent(head);
            break;

            case 5:
                calculateAvgClass(head);
            break;

            case 6:
                printStdList(head);
            break;

            case 7:
                exit(0);
            break;

            default:
                printf(" Wrong choice. Try again...\n\n");
            break;
        }
    }

    return 0;
}
