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

public:
    VSRP(){
        temp = NULL;
        front = NULL;
        rear = NULL;
        head = NULL;
    }

    bool isEmpty() {
        if(head == NULL)
            return true;
        else
            return false;
    }

    void AddRecord(){
        ServiceNode *newNode = new ServiceNode;
        cout << "\nEnter Record ID: ";
        cin >> newNode->RecordID;
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
        }
        else
        {
            cout<<"\n>>> No records to display.\n";
        }
    }

    void SearchRecord(){

    }

    void EditRecord(){

    }

    void DeleteRecord(){

    }

    void SortRecords(){

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
        cout<< "\n6. Sort Records (Bubble Sort)";
        cout<< "\n7. Add to Waiting Queue";
        cout<< "\n8. View Waiting Queue";
        cout<< "\n0. Exit";
        cout<< "\n\nSelection: ";
        cin>>choice;

    switch (choice)
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
 
    } while (choice != 0);

    return 0;
}