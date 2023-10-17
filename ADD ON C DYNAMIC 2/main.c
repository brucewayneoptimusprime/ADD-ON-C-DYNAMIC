#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a to-do item
struct TodoItem {
    char description[100];
    char dueDate[20];
};

int main() {
    struct TodoItem *todoList = NULL;
    int listSize = 0;

    while (1) {
        int choice;
        printf("\nTo-Do List Menu:\n");
        printf("1. Add To-Do Item\n");
        printf("2. Display To-Do List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add To-Do Item
                if (listSize == 0) {
                    todoList = (struct TodoItem *)malloc(sizeof(struct TodoItem));
                } else {
                    todoList = (struct TodoItem *)realloc(todoList, (listSize + 1) * sizeof(struct TodoItem));
                }

                if (todoList == NULL) {
                    printf("Memory allocation failed. Exiting...");
                    return 1;
                }

                printf("Enter the description: ");
                scanf(" %[^\n]", todoList[listSize].description);
                printf("Enter the due date: ");
                scanf(" %[^\n]", todoList[listSize].dueDate);
                listSize++;
                break;

            case 2:
                // Display To-Do List
                printf("\nTo-Do List:\n");
                for (int i = 0; i < listSize; i++) {
                    printf("%d. Description: %s, Due Date: %s\n", i + 1, todoList[i].description, todoList[i].dueDate);
                }
                break;

            case 3:
                // Exit
                free(todoList);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
