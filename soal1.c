/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 4 (Dynamic Structures)
 *   Hari dan Tanggal    : Senin, 4 Mei 2026
 *   Nama (NIM)          : Davina Alya Shakira (13224081)
 *   Nama File           : soal1.c
 *   Deskripsi           : Program untuk mensimulasikan rangkaian kereta kargo yang sedang disusun ulang di stasiun bongkar muat dengan linked list berdasarkan serangkain operasi (PUSH_FRONT, PUSH_BACK, DELETE, dan FIND)
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int x;
    struct Node* next;
} Node;

Node *createNode(int x){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->next = NULL;
    return newNode;
}

void PUSH_FRONT(Node **head, int x){
    Node *newNode = createNode(x);
    newNode->next = *head;
    *head = newNode;
}

void PUSH_BACK(Node **head, int x){
    Node *newNode = createNode(x);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void DELETE(Node **head, int x){
    Node *temp = *head;
    Node *prev = NULL;

    if (temp != NULL && temp->x == x){
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->x != x){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void FIND(Node *head, int x){
    Node *temp = head;
    int posisi = 0;

    while (temp !=NULL){
        if(temp->x == x){
            printf("FOUND %d\n", posisi);
            return;
        }
        posisi++;
        temp = temp->next;
    }
    printf("NOT FOUND\n");
}

void printList(Node *head){
    if (head == NULL){
        printf("List Empty");
        return;
    }
    printf("LIST");
    Node *temp = head;
    while (temp != NULL){
        printf(" %d", temp->x);
        temp = temp->next;
    }
}

int main(){
    Node *head = NULL;
    int Q, op, x;

    scanf("%d", &Q);
    for (int i = 0; i < Q; i++){
        scanf("%d %d", &op, &x);
        if (op == 1){
            PUSH_FRONT(&head, x);
        }
        else if (op == 2){
            PUSH_BACK(&head, x);
        }
        else if (op == 3){
            DELETE(&head, x);
        }
        else if (op == 4){
            FIND(head, x);
        }
    }
    printList(head);
    return 0;
}
