#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// --- 1. STRUCTURE REQUIREMENT [cite: 38] ---
struct ServiceRecord {
    string licensePlate;
    string serviceType;
    string date;
    double cost;
};

// Node for Linked List implementation 
struct Node {
    ServiceRecord data;
    Node* next;
};

// --- 2. CLASS REQUIREMENT [cite: 38] ---
class VehicleServiceSystem {
private:
    Node* head; // Linked List head
    
    // Queue (Array Implementation) for pending services 
    string pendingQueue[10]; 
    int front, rear, count;
    int maxQueue = 10;

public:
    VehicleServiceSystem() {
        head = NULL;
        front = 0;
        rear = -1;
        count = 0;
    }

    // --- CRUD: ADD / CREATE [cite: 40] ---
    void addRecord() {
        Node* newNode = new Node;
        cout << "\n--- Add New Service Record ---" << endl;
        cout << "Enter License Plate: ";
        cin >> newNode->data.licensePlate;
        cout << "Enter Service Type (e.g., Oil_Change): ";
        cin >> newNode->data.serviceType;
        cout << "Enter Date (DD/MM/YYYY): ";
        cin >> newNode->data.date;
        cout << "Enter Cost: ";
        cin >> newNode->data.cost;
        
        newNode->next = head;
        head = newNode;
        cout << "Record added successfully!\n";
    }

    // --- CRUD: DISPLAY / READ [cite: 43] ---
    void displayAll() {
        if (!head) {
            cout << "No records found.\n";
            return;
        }
        Node* temp = head;
        cout << "\n------------------------------------------------------------\n";
        cout << left << setw(15) << "Plate" << setw(20) << "Service" << setw(15) << "Date" << setw(10) << "Cost" << endl;
        cout << "------------------------------------------------------------\n";
        while (temp != NULL) {
            cout << left << setw(15) << temp->data.licensePlate 
                 << setw(20) << temp->data.serviceType 
                 << setw(15) << temp->data.date 
                 << "$" << fixed << setprecision(2) << temp->data.cost << endl;
            temp = temp->next;
        }
    }

    // --- ALGORITHM: LINEAR SEARCH  ---
    // --- CRUD: SEARCH [cite: 44] ---
    void searchRecord() {
        string plate;
        cout << "Enter License Plate to search: ";
        cin >> plate;
        
        Node* temp = head;
        bool found = false;
        while (temp != NULL) {
            if (temp->data.licensePlate == plate) {
                cout << "\nRecord Found:\n";
                cout << "Service: " << temp->data.serviceType << "\nDate: " << temp->data.date << "\nCost: $" << temp->data.cost << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found) cout << "No records found for " << plate << endl;
    }

    // --- CRUD: EDIT / UPDATE [cite: 41] ---
    void editRecord() {
        string plate;
        cout << "Enter License Plate to edit: ";
        cin >> plate;
        
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data.licensePlate == plate) {
                cout << "Enter New Service Type: ";
                cin >> temp->data.serviceType;
                cout << "Enter New Cost: ";
                cin >> temp->data.cost;
                cout << "Update complete!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Record not found.\n";
    }

    // --- CRUD: DELETE [cite: 42] ---
    void deleteRecord() {
        string plate;
        cout << "Enter License Plate to delete: ";
        cin >> plate;

        Node *temp = head, *prev = NULL;
        if (temp != NULL && temp->data.licensePlate == plate) {
            head = temp->next;
            delete temp;
            cout << "Record deleted.\n";
            return;
        }
        while (temp != NULL && temp->data.licensePlate != plate) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Record not found.\n";
            return;
        }
        prev->next = temp->next;
        delete temp;
        cout << "Record deleted.\n";
    }

    // --- ALGORITHM: BUBBLE SORT  ---
    void sortByPlate() {
        if (!head || !head->next) return;
        bool swapped;
        Node* ptr1;
        Node* lptr = NULL;

        do {
            swapped = false;
            ptr1 = head;
            while (ptr1->next != lptr) {
                if (ptr1->data.licensePlate > ptr1->next->data.licensePlate) {
                    swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
        cout << "Records sorted by License Plate.\n";
    }

    // --- ALGORITHM: QUEUE (ARRAY)  ---
    void addToServiceQueue() {
        if (count == maxQueue) {
            cout << "Queue full!\n";
            return;
        }
        string plate;
        cout << "Enter Plate for pending service: ";
        cin >> plate;
        rear = (rear + 1) % maxQueue;
        pendingQueue[rear] = plate;
        count++;
        cout << "Added to waiting list.\n";
    }

    void viewQueue() {
        if (count == 0) {
            cout << "No vehicles waiting.\n";
            return;
        }
        cout << "\nPending Service Queue:\n";
        int current = front;
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << pendingQueue[current] << endl;
            current = (current + 1) % maxQueue;
        }
    }
};

int main() {
    VehicleServiceSystem system;
    int choice;

    do {
        cout << "\n===== VEHICLE SERVICE MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Service Record";
        cout << "\n2. Display All Records";
        cout << "\n3. Search Record";
        cout << "\n4. Edit Record";
        cout << "\n5. Delete Record";
        cout << "\n6. Sort Records (Bubble Sort)";
        cout << "\n7. Add to Waiting Queue";
        cout << "\n8. View Waiting Queue";
        cout << "\n0. Exit";
        cout << "\nSelection: ";
        cin >> choice;

        switch (choice) {
            case 1: system.addRecord(); break;
            case 2: system.displayAll(); break;
            case 3: system.searchRecord(); break;
            case 4: system.editRecord(); break;
            case 5: system.deleteRecord(); break;
            case 6: system.sortByPlate(); break;
            case 7: system.addToServiceQueue(); break;
            case 8: system.viewQueue(); break;
            case 0: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}