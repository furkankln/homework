#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int bill;
    char name[50];
    struct Node* next;
};

void push(struct Node** headRef) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, "Z");
    newNode->bill = 0;
    newNode->next = *headRef;
    *headRef = newNode;
}

void printName(struct Node* node, char ch) {
    while (node != NULL) {
        if (node->name[0] == ch) {
            printf("%s    ", node->name);
            printf("%d\n", node->bill);
        }
        node = node->next;
    }
}

void printBill(struct Node* node, int bl) {
    while (node != NULL) {
        if (node->bill >= bl) {
            printf("%s    ", node->name);
            printf("%d\n", node->bill);
        }
        node = node->next;
    }
}

void addName(struct Node* node, char name[50]) {
    while (node != NULL) {
        if (strcmp(name, (node)->name) < 0) {
            char prevName[50];
            strcpy(prevName, node->name);
            
            strcpy(node->name, name);
            node = node->next;
            
            while(node != NULL) {
                char bufferName[50];
                strcpy(bufferName, node->name); 
                strcpy(node->name, prevName);
                strcpy(prevName, bufferName);
                node = node->next;
            }
            break;

        }
        else {
            node = node->next;
        }
    }

}

void addBill(struct Node* node, int bill) {
    while (node != NULL) {
        if (bill > node->bill) {
            int prevBill = node->bill;
            node->bill = bill;
            node = node->next;
            
            
            
            while (node != NULL) {
                int bufferBill = node->bill;
                node->bill = prevBill;
                prevBill = bufferBill;
                node = node->next;
                
            }
            break;
        }
        else {
            node = node->next;
        
        }
    }
    
}


int main(void)
{

    struct Node* head = NULL;
    for (int i = 0; i < 15; i++) {
        push(&head);
    }
    
    addBill(head, 100);
    addBill(head, 1000);
    addBill(head, 600);
    addBill(head, 650);
    addBill(head, 350);
    addBill(head, 270);
    addBill(head, 410);
    addBill(head, 750);
    addBill(head, 600);
    addBill(head, 1000);
    addBill(head, 900);
    addBill(head, 850);
    addBill(head, 790);
    addBill(head, 610);
    addBill(head, 550);

    addName(head, "Ahmet");
    addName(head, "Bilal");
    addName(head, "Cemal");
    addName(head, "Adem");
    addName(head, "Yasin");
    addName(head, "Esin");
    addName(head, "Emel");
    addName(head, "Mustafa");
    addName(head, "Ayten");
    addName(head, "Ceylan");
    addName(head, "Nesrin");
    addName(head, "Bekir");
    addName(head, "Emin");
    addName(head, "Hakan");
    addName(head, "Hatice");

    
   //prints all  names starting with 'A'
    printName(head , 'A');

  
    printf("-----------\n");

 // Prints all numbers equals and greater than 500
    printBill(head , 500 );

   


}
