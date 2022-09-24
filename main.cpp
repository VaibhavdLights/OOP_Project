#include<bits/stdc++.h>
#include<sqlite3.h>
#include<string>

#include "insertion_check.cpp"
#include "room_specs.cpp"
#include "room.cpp"
#include "customer.cpp"
#include "room_allotment.cpp"
#include "calculate_rent.cpp"
#include "add_guest.cpp"

using namespace std;

int mainMenu(){
    int choice;
    cout << "1.Add New Guest( > 1 ) ->> \n";
    cout << "2.View Room Specifications( > 2 ) ->> \n";
    cout << "3.Query( > 3 ) ->> \n";
    cout << "4.Update Check Out Time( > 4 ) ->> \n";
    cout << "5.Display Data of Old Customers( > 5 ) ->> \n";
    cout << "6.Refresh database( > 6 ) ->> \n";
    cout << "7.Exit( > 7 ) ->> \n";
    cout << "\n";
    cout << "Enter your Choice  ->> ";
    cin >> choice;
    switch(choice){
        case 1 : addGuest();
        break;
        case 2 : roomSpecs();
        break;
        case 3 :
        break;
        case 4 :
        break;
        case 5 :
        break;
        case 6 :
        break;
        case 7 : return 1;
        break;
        default : cout << "Sorry, Wrong Choice !!!";
        break;
    }
    return 0;
}

int main(){
    Room R;
    Customer C(true);
    while(true){
        cout << "\n";
        int exit = mainMenu();
        if(exit) return 0;
    }
}