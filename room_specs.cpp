#include <bits/stdc++.h>
#include <string>

using namespace std;

class Data_Room_Specs{
    public:
        
};

static int callback(void* data, int argc, char** argv, char** colName){
    for(int i=0;i<argc;i++){
        
    }
    return 0;
}

int roomSpecs(){
    sqlite3 *DB;
    int myCursor = 0;
    char *error;

    myCursor = sqlite3_open("AJAX HMS.db", &DB);
    //error handling
    if(myCursor){
        cerr << "Error While Loading Database!\n";
        cout << sqlite3_errmsg(DB) << "\n";
        return -1;
    }
    
    string query = "SELECT * FROM ROOM_SPECIFICATIONS;";
    
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_roomSpecs, NULL, NULL);
        
}