#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct ServiceNode
{
    int RecordID;
    string CarPlate;
    string CarBrand;
    string CarModel;
    double ServicePrice;
    string Status;

    ServiceNode *next;
};

class VSRP
{
private:
    ServiceNode *temp, *front, *rear, *head;
    int NextRecordID;

public:
    VSRP(){
        temp = NULL;
        front = NULL;
        rear = NULL;
        head = NULL;
        NextRecordID = 1;
    }

    bool isEmpty(){
        if(head == NULL)
            return true;
        else
            return false;
    }

    void AddRecord(){
        ServiceNode *newNode = new ServiceNode;

        newNode->RecordID = NextRecordID++; 
        cout << "\nRecord ID: " << newNode->RecordID << "\n";
        cout << "Enter Car Plate: ";
        cin >> newNode->CarPlate;
        cout << "Enter Car Brand: ";
        cin >> newNode->CarBrand;
        cout << "Enter Car Model: ";
        cin >> newNode->CarModel;
        cout << "Enter Service Price: RM ";
        cin >> newNode->ServicePrice;
        cout << "Enter Status (e.g., Serviced, Pending): ";
        cin >> newNode->Status;
        
        newNode->next = NULL;

        if(head == NULL)
            head = newNode;
        else
        {
            temp = head;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
        cout << ">>> Service Record Added Successfully!\n";
    }

    void DisplayRecords(){
        if(!isEmpty())
        {
            cout << "\n----------------------------------------------------------------------------\n";
            cout << left << setw(12) << "Record ID" 
                 << setw(15) << "Car Plate" 
                 << setw(20) << "Car Brand" 
                 << setw(20) << "Car Model" 
                 << setw(15) << "Price (RM)" 
                 << "Status\n";
            cout << "----------------------------------------------------------------------------\n";
            
            temp = head;
            while(temp != NULL)
            {
                cout << left << setw(12) << temp->RecordID 
                     << setw(15) << temp->CarPlate 
                     << setw(20) << temp->CarBrand
                     << setw(20) << temp->CarModel 
                     << setw(15) << fixed << setprecision(2) << temp->ServicePrice 
                     << temp->Status << "\n";
                temp = temp->next;
            }
            cout << "----------------------------------------------------------------------------\n";
        }else
            cout<<"\n>>> No records to display.\n";
    }

    void SearchRecord(){
        if(!isEmpty())
        {
            int searchID;
            cout << "\nEnter Record ID to search: ";
            cin >> searchID;

            temp = head;
            while(temp != NULL)
            {
                if(temp->RecordID == searchID)
                {
                    cout << "\n>>> Record Found:\n";
                    cout << "Record ID   : " << temp->RecordID << "\n";
                    cout << "Car Plate   : " << temp->CarPlate << "\n";
                    cout << "Car Brand   : " << temp->CarBrand << "\n";
                    cout << "Car Model   : " << temp->CarModel << "\n";
                    cout << "Service Price: RM " << fixed << setprecision(2) << temp->ServicePrice << "\n";
                    cout << "Status      : " << temp->Status << "\n";
                    return;
                }
                temp = temp->next;
            }
            cout<<"\n>>> Record with ID "<<searchID<<" not found.\n";
        }else
            cout<<"\n>>> The list is empty.\n";
    }

    void EditRecord(){
        if (!isEmpty())
        {
            int editID;
            cout << "\nEnter Record ID to edit: ";
            cin >> editID;

            temp = head;
            while (temp != NULL) {
                if (temp->RecordID == editID) {
                    cout << "\n>>> Record Found.";
                    
                    int choice;
                    do 
                    {
                        cout << "\nWhat would you like to edit?\n";
                        cout << "1. Car Plate\n";
                        cout << "2. Car Brand\n";
                        cout << "3. Car Model\n";
                        cout << "4. Service Price\n";
                        cout << "5. Status\n";
                        cout << "6. Cancel Edit\n";
                        cout << "Enter your choice (1-6): ";
                        cin >> choice;

                        switch (choice) {
                            case 1:
                                cout << "Enter New Car Plate: ";
                                cin >> temp->CarPlate;
                                cout << ">>> Car Plate Updated Successfully!\n";
                                return;
                            case 2:
                                cout << "Enter New Car Brand: ";
                                cin >> temp->CarBrand;
                                cout << ">>> Car Brand Updated Successfully!\n";
                                return; 
                            case 3:
                                cout << "Enter New Car Model: ";
                                cin >> temp->CarModel;
                                cout << ">>> Car Model Updated Successfully!\n";
                                return; 
                            case 4:
                                cout << "Enter New Service Price: RM ";
                                cin >> temp->ServicePrice;
                                cout << ">>> Service Price Updated Successfully!\n";
                                return; 
                            case 5:
                                cout << "Enter New Status: ";
                                cin >> temp->Status;
                                cout << ">>> Status Updated Successfully!\n";
                                return; 
                            case 6:
                                cout << "Edit cancelled.\n";
                                return;
                            default:
                                cout << "Invalid choice. Please select a valid option.\n";
                                break;
                        }
                    } while (choice < 1 || choice > 6);
                }    
                temp = temp->next;
            }
            cout << "\n>>> Record with ID " << editID << " not found.\n";
        }else
            cout << "\n>>> The list is empty.\n";
    }

    void DeleteRecord(){
        if(!isEmpty())
        {
            int deleteID;
            cout << "\nEnter Record ID to delete: ";
            cin >> deleteID;

            ServiceNode *prev = NULL;
            temp = head;

            while(temp != NULL)
            {
                if(temp->RecordID == deleteID)
                {
                    if(prev == NULL)
                    {
                        head = temp->next;
                    }
                    else
                    {
                        prev->next = temp->next;
                    }
                    delete temp;
                    cout << ">>> Record with ID " << deleteID << " deleted successfully.\n";
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
            cout << "\n>>> Record with ID " << deleteID << " not found.\n";
        }else
            cout << "\n>>> The list is empty. Nothing to delete.\n";
    }

    void SortRecords(){
        if(!isEmpty()){
            ServiceNode *sortedHead = NULL;

            temp = head;
            while(temp != NULL){
                ServiceNode *nextNodes = temp->next;

                if(sortedHead == NULL || temp->RecordID < sortedHead->RecordID){
                    temp->next = sortedHead;
                    sortedHead = temp;

                }else{
                    ServiceNode *search = sortedHead;

                    while(search->next != NULL && search->next->RecordID < temp->RecordID)
                        search = search->next;

                    temp->next = search->next;
                    search->next = temp;
                }

                temp = nextNodes;
            }

            head = sortedHead;

            cout << "\n>>> Records Sorted Successfully by Record ID (Insertion Sort)!\n";
            
        }else
            cout << "\n>>> The list is empty. Nothing to sort.\n";
    }

    void AddToQueue(){

    }

    void ViewQueue(){

    }
};

int main()
{
    VSRP s;
    int choice;

    do
    {
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"                  Vehicle Service Record Program                "<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
        cout<< "\n1. Add Service Record";
        cout<< "\n2. Display All Records";
        cout<< "\n3. Search Record";
        cout<< "\n4. Edit Record";
        cout<< "\n5. Delete Record";
        cout<< "\n6. Sort Records (Insertion Sort)";
        cout<< "\n7. Add to Waiting Queue";
        cout<< "\n8. View Waiting Queue";
        cout<< "\n0. Exit";
        cout<< "\n\nSelection: ";
        cin>>choice;

    switch(choice)
    {
    case 1: s.AddRecord(); break;
    case 2: s.DisplayRecords(); break;
    case 3: s.SearchRecord(); break;
    case 4: s.EditRecord(); break;
    case 5: s.DeleteRecord(); break;
    case 6: s.SortRecords(); break;
    case 7: s.AddToQueue(); break;
    case 8: s.ViewQueue(); break;
    }
 
    }while(choice != 0);

    return 0;
}