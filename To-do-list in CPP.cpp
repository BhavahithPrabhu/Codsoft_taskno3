#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

std::vector<Task> taskList;

void addTask() {
    Task newTask;
    std::string description;

    std::cout << "Enter the task description: ";
    std::cin.ignore();  // Clear the input buffer
    std::getline(std::cin, description);

    newTask.description = description;
    newTask.completed = false;
    
    taskList.push_back(newTask);
    std::cout << "Task added successfully.\n";
}

void viewTasks() {
    if (taskList.empty()) {
        std::cout << "The to-do list is empty.\n";
    } else {
        std::cout << "To-Do List:\n";
        for (size_t i = 0; i < taskList.size(); i++) {
            std::cout << i + 1 << ". ";
            if (taskList[i].completed) {
                std::cout << "[Completed] ";
            }
            std::cout << taskList[i].description << std::endl;
        }
    }
}

void markAsCompleted() {
    viewTasks();
    if (!taskList.empty()) {
        int taskIndex;
        std::cout << "Enter the number of the task to mark as completed: ";
        std::cin >> taskIndex;

        if (taskIndex > 0 && taskIndex <= static_cast<int>(taskList.size())) {
            taskList[taskIndex - 1].completed = true;
            std::cout << "Task marked as completed.\n";
        } else {
            std::cout << "Invalid task number.\n";
        }
    }
}

void removeTask() {
    viewTasks();
    if (!taskList.empty()) {
        int taskIndex;
        std::cout << "Enter the number of the task to remove: ";
        std::cin >> taskIndex;

        if (taskIndex > 0 && taskIndex <= static_cast<int>(taskList.size())) {
            taskList.erase(taskList.begin() + taskIndex - 1);
            std::cout << "Task removed.\n";
        } else {
            std::cout << "Invalid task number.\n";
        }
    }
}

int main() {
    int choice;

    do {
        std::cout << "To-Do List Manager by Bhavahith Prabhu\n"
                  << "1. Add Task\n"
                  << "2. View Tasks\n"
                  << "3. Mark Task as Completed\n"
                  << "4. Remove Task\n"
                  << "5. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markAsCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}