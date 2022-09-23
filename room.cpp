#include<bits/stdc++.h>
#include<sqlite3.h>
#include<string>

using namespace std;

// void insertion_check(int check, char *error){
//     if(check != SQLITE_OK){
//         cerr << "ERROR INSERTING DATA\n";
//         cout << error << "\n";
//     }
// }

class Room{
    private:
        int addRoomInfoToDB();
        int addRoomInfoToDB(bool isData, sqlite3* DB);
    public:
        Room(){
            addRoomInfoToDB();
        }
};

int Room :: addRoomInfoToDB(bool isData, sqlite3 *DB){
    //ask isData flag from database of variables and let it not feed data twice to show unneccessary error.
    int myCursor = 0;
    char *error;
    string query;

    query = "INSERT INTO ROOM_SPECIFICATIONS VALUES('AJAX1', 'SINGLE', 1, 'YES', 'YES', 'NO', 'NO', 3000);";
    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
    insertion_check(myCursor, error);

    query = "INSERT INTO ROOM_SPECIFICATIONS VALUES('AJAX2', 'DOUBLE', 2, 'YES', 'YES', 'NO', 'NO', 4500);";
    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
    insertion_check(myCursor, error);

    query = "INSERT INTO ROOM_SPECIFICATIONS VALUES('AJAX3', 'SUITE', 2, 'YES', 'YES', 'YES', 'NO', 6000);";
    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
    insertion_check(myCursor, error);

    query = "INSERT INTO ROOM_SPECIFICATIONS VALUES('AJAX4', 'MURPHY', 4, 'YES', 'YES', 'YES', 'NO', 8000);";
    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
    insertion_check(myCursor, error);

    query = "INSERT INTO ROOM_SPECIFICATIONS VALUES('AJAX5', 'CABANA', 2, 'YES', 'YES', 'YES', 'YES', 10000);";
    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
    insertion_check(myCursor, error);
    return 0;
}

int Room :: addRoomInfoToDB(){
    sqlite3 *DB;
    int myCursor = 0;
    char *error;
    myCursor = sqlite3_open("AJAX HMS.db", &DB);

    if(myCursor){
        cerr << "Error While Loading Database!\n";
        cout << sqlite3_errmsg(DB) << "\n";
        return -1;
    }
    else{
        cout << "Successfully Created/Loaded Hotel Management System Environment!\n";
    }

    string query = "CREATE TABLE IF NOT EXISTS ROOM_SPECIFICATIONS(ID TEXT PRIMARY KEY NOT NULL, "
                                                                 "TYPE TEXT NOT NULL, BEDS INT NOT NULL, "
                                                                 "AC TEXT NOT NULL, WiFi TEXT NOT NULL, "
                                                                 "AI TEXT NOT NULL, SWIMMING_POOL TEXT NOT NULL, "
                                                                 "RENT INT NOT NULL);";

    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);

    if(myCursor != SQLITE_OK){
        cerr << "ERROR CREATING ROOM SPECIFICATION TABLE\n";
        cout << error << "\n";
        sqlite3_free(error);
    }
    // int tmp;
    // cout << "press 1 to insert data";
    // cin >> tmp;
    addRoomInfoToDB(true, DB);//insert values in database
    sqlite3_close(DB);
    return 0;
}