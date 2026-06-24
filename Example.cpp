#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct ServiceNode
{
    int RecordID;
    string CarPlate;
    string CarModel;
    double ServicePrice;
    string Status;

    ServiceNode *next;
};

class VSRP
{
private:
    ServiceNode *temp, *front, *rear, *head;

public:
    VSRP() {
        temp = NULL;
        front = NULL;
        rear = NULL;
        head = NULL;
    }

    // 1. Add Record to Linked List
    void AddRecord() {
        ServiceNode *newNode = new ServiceNode;
        cout << "\nEnter Record ID: ";
        cin >> newNode->RecordID;
        cout << "Enter Car Plate: ";
        cin >> ws; // clear input buffer whitespace
        getline(cin, newNode->CarPlate);
        cout << "Enter Car Model: ";
        getline(cin, newNode->CarModel);
        cout << "Enter Service Price: RM ";
        cin >> newNode->ServicePrice;
        cout << "Enter Status (e.g., Serviced, Pending): ";
        cin >> ws;
        getline(cin, newNode->Status);
        
        newNode->next = NULL;

        // Insert at the end of the linked list
        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << ">>> Service Record Added Successfully!\n";
    }

    // 2. Display All Records in Linked List
    void DisplayRecords() {
        if(head == NULL) {
            cout << "\n>>> No records to display.\n";
            return;
        }

        cout << "\n----------------------------------------------------------------------------\n";
        cout << left << setw(12) << "Record ID" 
             << setw(15) << "Car Plate" 
             << setw(20) << "Car Model" 
             << setw(15) << "Price (RM)" 
             << "Status\n";
        cout << "----------------------------------------------------------------------------\n";
        
        temp = head;
        while (temp != NULL) {
            cout << left << setw(12) << temp->RecordID 
                 << setw(15) << temp->CarPlate 
                 << setw(20) << temp->CarModel 
                 << setw(15) << fixed << setprecision(2) << temp->ServicePrice 
                 << temp->Status << "\n";
            temp = temp->next;
        }
        cout << "----------------------------------------------------------------------------\n";
    }

    // 3. Search for a Record by ID
    void SearchRecord() {
        if (head == NULL) {
            cout << "\n>>> The list is empty.\n";
            return;
        }
        
        int searchID;
        cout << "\nEnter Record ID to search: ";
        cin >> searchID;

        temp = head;
        while (temp != NULL) {
            if (temp->RecordID == searchID) {
                cout << "\n>>> Record Found:\n";
                cout << "Record ID   : " << temp->RecordID << "\n";
                cout << "Car Plate   : " << temp->CarPlate << "\n";
                cout << "Car Model   : " << temp->CarModel << "\n";
                cout << "Service Price: RM " << fixed << setprecision(2) << temp->ServicePrice << "\n";
                cout << "Status      : " << temp->Status << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "\n>>> Record with ID " << searchID << " not found.\n";
    }

    // 4. Edit an Existing Record
    void EditRecord() {
        if (head == NULL) {
            cout << "\n>>> The list is empty.\n";
            return;
        }

        int editID;
        cout << "\nEnter Record ID to edit: ";
        cin >> editID;

        temp = head;
        while (temp != NULL) {
            if (temp->RecordID == editID) {
                cout << "\n>>> Record Found. Enter New Details:\n";
                cout << "Enter New Car Plate: ";
                cin >> ws;
                getline(cin, temp->CarPlate);
                cout << "Enter New Car Model: ";
                getline(cin, temp->CarModel);
                cout << "Enter New Service Price: RM ";
                cin >> temp->ServicePrice;
                cout << "Enter New Status: ";
                cin >> ws;
                getline(cin, temp->Status);
                
                cout << ">>> Record Updated Successfully!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "\n>>> Record with ID " << editID << " not found.\n";
    }

    // 5. Delete a Record from Linked List
    void DeleteRecord() {
        if (head == NULL) {
            cout << "\n>>> The list is empty. Nothing to delete.\n";
            return;
        }

        int deleteID;
        cout << "\nEnter Record ID to delete: ";
        cin >> deleteID;

        // If the node to be deleted is the head
        if (head->RecordID == deleteID) {
            temp = head;
            head = head->next;
            delete temp;
            cout << "\n>>> Record deleted successfully!\n";
            return;
        }

        // Search for the node to delete, keeping track of the previous node
        ServiceNode *prev = head;
        temp = head->next;
        
        while (temp != NULL) {
            if (temp->RecordID == deleteID) {
                prev->next = temp->next;
                delete temp;
                cout << "\n>>> Record deleted successfully!\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        
        cout << "\n>>> Record with ID " << deleteID << " not found.\n";
    }

    // 6. Sort Records by ID using Bubble Sort (Swapping Data)
    void SortRecords() {
        if (head == NULL || head->next == NULL) {
            cout << "\n>>> Not enough records to sort.\n";
            return;
        }

        bool swapped;
        ServiceNode *ptr1;
        ServiceNode *lptr = NULL; // Tracks the last swapped node

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->RecordID > ptr1->next->RecordID) {
                    // Swap the data within the nodes
                    swap(ptr1->RecordID, ptr1->next->RecordID);
                    swap(ptr1->CarPlate, ptr1->next->CarPlate);
                    swap(ptr1->CarModel, ptr1->next->CarModel);
                    swap(ptr1->ServicePrice, ptr1->next->ServicePrice);
                    swap(ptr1->Status, ptr1->next->Status);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);

        cout << "\n>>> Records successfully sorted by Record ID!\n";
    }

    // 7. Add a car to the Waiting Queue (Enqueue)
    void AddToQueue() {
        ServiceNode *newNode = new ServiceNode;
        cout << "\n--- Add Car to Waiting Queue ---\n";
        cout << "Enter Queue/Record ID: ";
        cin >> newNode->RecordID;
        cout << "Enter Car Plate: ";
        cin >> ws;
        getline(cin, newNode->CarPlate);
        
        newNode->CarModel = "N/A";
        newNode->ServicePrice = 0.0;
        newNode->Status = "Waiting";
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << ">>> Car added to the waiting queue!\n";
    }

    // 8. View the Waiting Queue
    void ViewQueue() {
        if (front == NULL) {
            cout << "\n>>> The waiting queue is currently empty.\n";
            return;
        }

        cout << "\n-------------------------------------------------\n";
        cout << left << setw(15) << "Queue ID" 
             << setw(20) << "Car Plate" 
             << "Status\n";
        cout << "-------------------------------------------------\n";
        
        temp = front;
        while (temp != NULL) {
            cout << left << setw(15) << temp->RecordID 
                 << setw(20) << temp->CarPlate 
                 << temp->Status << "\n";
            temp = temp->next;
        }
        cout << "-------------------------------------------------\n";
    }
};

int main()
{
    VSRP system; // Create an instance of the class
    int choice;
    
    do
    {
        cout << "\n================================================================" << endl;
        cout << "                 Vehicle Service Record Program                 " << endl;
        cout << "================================================================" << endl;
        cout << "1. Add Service Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Search Record\n";
        cout << "4. Edit Record\n";
        cout << "5. Delete Record\n";
        cout << "6. Sort Records (Bubble Sort)\n";
        cout << "7. Add to Waiting Queue\n";
        cout << "8. View Waiting Queue\n";
        cout << "0. Exit\n";
        cout << "\nSelection: ";
        cin >> choice;

        switch (choice)
        {
            case 1: system.AddRecord(); break;
            case 2: system.DisplayRecords(); break;
            case 3: system.SearchRecord(); break;
            case 4: system.EditRecord(); break;
            case 5: system.DeleteRecord(); break;
            case 6: system.SortRecords(); break;
            case 7: system.AddToQueue(); break;
            case 8: system.ViewQueue(); break;
            case 0: cout << "\nExiting Program. Goodbye!\n"; break;
            default: cout << "\nInvalid selection. Please try again.\n"; break;
        }
 
    } while (choice != 0);

    return 0;
}