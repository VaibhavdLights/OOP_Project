#include<bits/stdc++.h>
#include<sqlite3.h>
#include<string>

#include "insertion_check.cpp"
#include "query_exec.cpp"
#include "room.cpp"
#include "customer.cpp"
#include "room_allotment.cpp"
#include "calculate_rent.cpp"
#include "add_guest.cpp"
#include "update_checkout.cpp"

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
        case 2 : queryExec("SELECT * FROM ROOM_SPECIFICATIONS;");
        break;
        case 3 : {
            int choice1;
            cout << "1. Get Guest Details Alphabetically... ( > 1 )->> \n";
            cout << "2. Get Guest Details ID Wise... ( > 2 )->> \n";
            cout << "3. Get Guest Details Check IN Date Wise... ( > 3 )->> \n";
            cout << "4. Get Guest Details Check OUT Date Wise... ( > 4 )->> \n";
            cout << "5. Get Guest Details Room Number Wise... ( > 5 )->> \n";
            cout << "6. Back To Main Menu... ( > 6 )->> \n";
            cin >> choice1;
            switch(choice1){
                case 1 : queryExec("SELECT * FROM AJAX_DB ORDER BY NAME ASC;");
                break;
                case 2 : {
                    int search_ID;
                    cout << "Enter Guest ID to search ->> ";
                    cin >> search_ID;
                    queryExec("SELECT * FROM AJAX_DB WHERE ID = "+to_string(search_ID)+";");
                }
                break;
                case 3 : {
                    string search_check_in_date;
                    cout << "Enter Check IN Date to search (DD-MM-YYYY) ->> ";
                    cin >> search_check_in_date;
                    queryExec("SELECT * FROM AJAX_DB WHERE IN_DATE = '"+search_check_in_date+"';");
                }
                break;
                case 4 : {
                    string search_check_out_date;
                    cout << "Enter Check OUT Date to search (DD-MM-YYYY) ->> ";
                    cin >> search_check_out_date;
                    queryExec("SELECT * FROM AJAX_DB WHERE OUT_DATE = '"+search_check_out_date+"';");
                }
                break;
                case 5 : {
                    int search_rno;
                    cout << "Enter Room Number to search ->> ";
                    cin >> search_rno;
                    queryExec("SELECT * FROM AJAX_DB WHERE ROOM_NO = "+to_string(search_rno)+";");
                }
                break;
                case 6 : //continue
                break;
                default : cout << "Sorry, Wrong Choice !!!\n"; 
            }
        }
        break;
        case 4 : updateCheckout();
        break;
        case 5 : queryExec("SELECT * FROM AJAX_OLD_DB;");
        break;
        case 6 :
        break;
        case 7 : return 1;
        break;
        default : cout << "Sorry, Wrong Choice !!!\n";
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