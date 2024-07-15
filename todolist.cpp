#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ToDoList {
private:
    vector<string> tasks;

public:
    void addTask(const string& task) {
        tasks.push_back(task);
        cout << "Task added: " << task << endl;
    }

    void deleteTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            cout << "Task deleted: " << tasks[index] << endl;
            tasks.erase(tasks.begin() + index);
        } else {
            cout << "Invalid task index!" << endl;
        }
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
        } else {
            cout << "To-Do List:" << endl;
            for (int i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i] << endl;
            }
        }
    }
};

int main() {
    ToDoList todo;
    int choice;
    string task;
    int index;

    do {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Delete Task\n";
        cout << "3. View Tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();  // Ignore the newline character left in the input buffer

        switch (choice) {
            case 1:
                cout << "Enter the task: ";
                getline(cin, task);
                todo.addTask(task);
                break;
            case 2:
                cout << "Enter the task number to delete: ";
                cin >> index;
                todo.deleteTask(index - 1);
                break;
            case 3:
                todo.viewTasks();
                break;
            case 4:
                cout << "Exiting the to-do list application.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}