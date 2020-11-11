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


void print(struct Node* node) {
  while (node!= NULL) {
    printf("%s    ", node->name);
    printf("%d\n", node->bill);
    node = node->next;
  }

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

void addName(struct Node* node, char name[50], int bill) {
    while (node != NULL) {
        if (strcmp(name, (node)->name) < 0) {
            int prevBill = node->bill;
            char prevName[50];
            strcpy(prevName, node->name);

            node->bill = bill;
            strcpy(node->name, name);

            node = node->next;

            while (node != NULL) {
                int bufferBill = node->bill;
                char bufferName[50];
                strcpy(bufferName, node->name);

                node->bill = prevBill;
                prevBill = bufferBill;

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

void addBill(struct Node* node, char name[50], int bill) {
    while (node != NULL) {
        if (bill > node->bill) {
            int prevBill = node->bill;
            char prevName[50];
            strcpy(prevName, node->name);

            node->bill = bill;
            strcpy(node->name, name);

            node = node->next;

            while (node != NULL) {
                int bufferBill = node->bill;
                char bufferName[50];
                strcpy(bufferName, node->name);

                node->bill = prevBill;
                prevBill = bufferBill;

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

void add(struct Node* node, char name[50], int bill)  {
    while (node != NULL) {
      if (node->name[0] == 'Z') {
          strcpy(node->name, name);
          node->bill = bill;
          break;
        }
        else {
          node = node->next;
        }
      } 
  }


int main(void)
{
    //three lists were created with size of fifteen

    struct Node* head = NULL;
    struct Node* head2 = NULL;
    struct Node* head3 = NULL;
    for (int i = 0; i < 15; i++) {
        push(&head);
    }
     for (int i = 0; i < 15; i++) {
        push(&head2);
    }
     for (int i = 0; i < 15; i++) {
        push(&head3);
    }

  //adds to list without sorting
  
    add(head,"Ahmet", 100);
    add(head, "Bilal", 1000);
    add(head,"Cemal", 600);
    add(head,"Adem", 650);
    add(head,"Yasin", 350);
    add(head,"Esin", 270);
    add(head,"Emel", 410);
    add(head,"Mustafa", 750);
    add(head,"Ayten", 600);
    add(head,"Ceylan", 1000);
    add(head,"Nesrin", 900);
    add(head,"Bekir", 850);
    add(head,"Emin", 790);
    add(head,"Hakan", 610);
    add(head,"Hatice", 550);

 //adds to list according to number 
    addBill(head2,"Ahmet", 100);
    addBill(head2, "Bilal", 1000);
    addBill(head2,"Cemal", 600);
    addBill(head2,"Adem", 650);
    addBill(head2,"Yasin", 350);
    addBill(head2,"Esin", 270);
    addBill(head2,"Emel", 410);
    addBill(head2,"Mustafa", 750);
    addBill(head2,"Ayten", 600);
    addBill(head2,"Ceylan", 1000);
    addBill(head2,"Nesrin", 900);
    addBill(head2,"Bekir", 850);
    addBill(head2,"Emin", 790);
    addBill(head2,"Hakan", 610);
    addBill(head2,"Hatice", 550);


  //adds to list according to name 

    addName(head3,"Ahmet", 100);
    addName(head3, "Bilal", 1000);
    addName(head3,"Cemal", 600);
    addName(head3,"Adem", 650);
    addName(head3,"Yasin", 350);
    addName(head3,"Esin", 270);
    addName(head3,"Emel", 410);
    addName(head3,"Mustafa", 750);
    addName(head3,"Ayten", 600);
    addName(head3,"Ceylan", 1000);
    addName(head3,"Nesrin", 900);
    addName(head3,"Bekir", 850);
    addName(head3,"Emin", 790);
    addName(head3,"Hakan", 610);
    addName(head3,"Hatice", 550);


    //prints all  names starting with 'A'
    printName(head3, 'A');


    printf("-----------\n");

     //Prints all numbers equals and greater than 900
    printBill(head3, 900);

    




}
