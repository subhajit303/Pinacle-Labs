#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100

struct Task {
    char description[100];
    int completed;
};

void displayMenu() {
    printf("\n===== To-Do List Manager =====\n");
    printf("1. Add Task\n");
    printf("2. Edit Task\n");
    printf("3. Mark Task as Complete\n");
    printf("4. Display To-Do List\n");
    printf("5. Exit\n");
    printf("================================\n");
}

int addTask(struct Task tasks[], int taskCount) {
    if (taskCount < MAX_TASKS) {
        printf("Enter task description: ");
        scanf(" %[^\n]", tasks[taskCount].description);
        tasks[taskCount].completed = 0;  // Set as not completed by default
        printf("Task added successfully!\n");
        return taskCount + 1;  // Increment task count
    } else {
        printf("Error: To-Do list is full\n");
        return taskCount;
    }
}

void editTask(struct Task tasks[], int taskCount) {
    int taskIndex;
    printf("Enter task number to edit (1-%d): ", taskCount);
    scanf("%d", &taskIndex);

    if (taskIndex >= 1 && taskIndex <= taskCount) {
        printf("Enter new task description: ");
        scanf(" %[^\n]", tasks[taskIndex - 1].description);
        printf("Task edited successfully!\n");
    } else {
        printf("Error: Invalid task number\n");
    }
}

void markAsComplete(struct Task tasks[], int taskCount) {
    int taskIndex;
    printf("Enter task number to mark as complete (1-%d): ", taskCount);
    scanf("%d", &taskIndex);

    if (taskIndex >= 1 && taskIndex <= taskCount) {
        tasks[taskIndex - 1].completed = 1;
        printf("Task marked as complete!\n");
    } else {
        printf("Error: Invalid task number\n");
    }
}

void displayToDoList(struct Task tasks[], int taskCount) {
    if (taskCount > 0) {
        printf("\n===== To-Do List =====\n");
        for (int i = 0; i < taskCount; i++) {
            printf("%d. %s - %s\n", i + 1, tasks[i].completed ? "[Completed]" : "[Pending]", tasks[i].description);
        }
        printf("=======================\n");
    } else {
        printf("To-Do list is empty\n");
    }
}

int main() {
    struct Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                taskCount = addTask(tasks, taskCount);
                break;
            case 2:
                editTask(tasks, taskCount);
                break;
            case 3:
                markAsComplete(tasks, taskCount);
                break;
            case 4:
                displayToDoList(tasks, taskCount);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Error: Invalid choice. Please enter a number between 1 and 5.\n");
        }

    } while (choice != 5);

    return 0;
}
