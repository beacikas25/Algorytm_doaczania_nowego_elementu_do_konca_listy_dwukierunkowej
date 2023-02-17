#include <stdio.h>
#include <stdlib.h>

// Struktura dla pojedynczego elementu listy
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Funkcja do tworzenia nowego elementu
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Funkcja do dodawania nowego elementu na koncu listy
void appendNode(struct Node** head_ref, int data) {
    // Tworzymy nowy element
    struct Node* newNode = createNode(data);

    // Jesli lista jest pusta, nowy element jest pierwszym i ostatnim elementem
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    // Znajdz ostatni element
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    // Polacz nowy element z ostatnim elementem
    last->next = newNode;
    newNode->prev = last;
}

// Funkcja do wyswietlania listy
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Dodajemy kilka elementow na koncu listy
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    // Wyswietlamy liste
    printf("Lista dwukierunkowa: ");
    printList(head);

    return 0;
}
