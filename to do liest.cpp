#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

// Add a task
void addTask() {
    Task t;
    cin.ignore();  // Clear input buffer
    cout << "Enter task: ";
    getline(cin, t.description);
    t.completed = false;
    tasks.push_back(t);
    cout << "Task added.\n";
}

// View tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
        return;
    }

    cout << "\n--- TASK LIST ---\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description;
        cout << " [" << (tasks[i].completed ? "completed" : "Pending") << "]\n";
    }
}

// Mark a task as completed
void markCompleted() {
    int num;
    viewTasks();
    if (tasks.empty()) return;

    cout << "Enter task number to mark as done: ";
    cin >> num;

    if (num < 1 || num > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks[num - 1].completed = true;
    cout << "Task marked as done.\n";
}

// Remove a task
void removeTask() {
    int num;
    viewTasks();
    if (tasks.empty()) return;

    cout << "Enter task number to remove: ";
    cin >> num;

    if (num < 1 || num > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks.erase(tasks.begin() + num - 1);
    cout << "Task removed.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== TO-DO LIST =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}

