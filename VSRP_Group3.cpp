#include<iostream>
#include<string>
#include<iomanip>
using namespace std;





int main()
{
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
        cout<< "\nSelection: ";
        cin>>choice;

    switch (choice)
    {
    case 1: /* code */ break;
    case 2: /* code */ break;
    case 3: /* code */ break;
    case 4: /* code */ break;
    case 5: /* code */ break;
    case 6: /* code */ break;
    case 7: /* code */ break;
    case 8: /* code */ break;
    
    default: cout<<"Invalid choice!"<<endl; break;
    }

     
    } while (choice != 0);



    return 0;
}