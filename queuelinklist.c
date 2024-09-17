#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (rear == NULL) { // Empty queue
        front = rear = newnode;
        printf("1st value entered\n");
        return;
    }
    rear->next = newnode;
    rear = newnode;
    printf("Value entered\n");
}

void dequeue() {
    if (front == NULL) {
        printf("Underflow\n");
        return;
    }
    struct node* temp = front;
    int data = temp->data;
    front = front->next;
    if (front == NULL) { // Queue becomes empty
        rear = NULL;
    }
    free(temp);
    printf("%d\n", data);
}

void display() {
    struct node* ptr = front;
    if (ptr == NULL) {
        printf("Queue is empty\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    int ch;
    int val;
    do {
        printf("Menu\n");
        printf("1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter a value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
        }
    } while (ch != 4);
    return 0;
}