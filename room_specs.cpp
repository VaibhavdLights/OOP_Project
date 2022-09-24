#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class Data_Room_Specs{
    private:
        vector <string> column_names;
        vector <pair<string,string>> room_data;
    public:
        // Data_Room_Specs(){
        //     void setData();
        //     void getData();
        // }
        void setData(string value, string col){
            int temp=0;
            // cout << value << " " << col << "\n";
            for(int i=0;i<column_names.size();i++){
                // cout <<type_info(column_names[i]) << " " << type_info(col) << "\n";
                // cout <<column_names[i] << " " << col << "\n";
                if(column_names[i] == col){
                    temp = 1;
                    break;
                }
            }
            if(!temp) column_names.push_back(col);
            // cout << col << " " << value << "\n";
            room_data.push_back(make_pair(col,value));
        }
        void getData(){
            // cout << "kal";
            for(int i=0;i<column_names.size();i++){
                if(i!=column_names.size()-1)
                cout << left << setw(20) << column_names[i];
                else
                cout << column_names[i] << "\n";
            }

            for(int i=0;i<column_names.size();i++){
                if(i!=column_names.size()-1)
                cout << left << setw(20) << "----------";
                else
                cout << "----------\n";
            }

            for(int i=0,j=0;i<room_data.size();i++,j++){
                if(j==column_names.size()) {
                    j=0;
                    cout << "\n";
                }

                if(room_data[i].first == column_names[j])
                    cout << left << setw(20) << room_data[i].second;
            }

            room_data.clear();
            column_names.clear();
        }
};

Data_Room_Specs D;

static int callback_get_roomSpecs(void* data, int argc, char** argv, char** colName){
    for(int i=0;i<argc;i++){
        D.setData(string(argv[i] ? argv[i] : "NULL"), (string)colName[i]);
    }
    // D.getData();
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
    // Data_Room_Specs D;
    D.getData();
    return 0;    
}