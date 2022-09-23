#include<bits/stdc++.h>
#include<sqlite3.h>
#include<string>

using namespace std;

static int callback1(void* data, int argc, char** argv, char** colName){
    cout << argv[0];
    return 0;
}
static int callback(void* data, int argc, char** argv, char** colName){
    for(int i=0;i<argc;i++){
        cout << colName[i] << " = " << (argv[i] ? argv[i] : NULL);
        cout << "\n";
    }
    cout << "\n";
    return 0;
}

int main(){
    sqlite3 *db;
    int exit = 0;
    exit = sqlite3_open("test.db", &db);

    if(exit){
        cerr << "Error Open DB " << sqlite3_errmsg(db) << "\n";
        // return -1;
    }
    else{
        cout << "Opened database Successfully!\n";
        // return 0;
    }

    string query = "CREATE TABLE if not exists PERSON("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "FULL_NAME           TEXT    NOT NULL, "
                      "SURNAME          TEXT     NOT NULL, "
                      "AGE            INT     NOT NULL, "
                      "ADDRESS        CHAR(50), "
                      "SALARY         REAL );";

    char *error;
    exit = sqlite3_exec(db, query.c_str(), NULL, 0, &error);
    
    if (exit != SQLITE_OK) {
        cerr << "Error Create Table\n";
        cout << error << "\n";
        sqlite3_free(error);
    }
    else
        cout << "Table created Successfully!\n";
    

    cout << "\n";

    query = "SELECT * FROM PERSON;";
    sqlite3_exec(db, query.c_str(), callback, NULL, NULL);

    string query1("INSERT INTO PERSON VALUES(1, 'STEVE', 'GATES', 30, 'PALO ALTO', 1000.0);"
               "INSERT INTO PERSON VALUES(2, 'BILL', 'ALLEN', 20, 'SEATTLE', 300.22);"
               "INSERT INTO PERSON VALUES(3, 'PAUL', 'JOBS', 24, 'SEATTLE', 9900.0);");

    string query2("INSERT INTO PERSON VALUES(2, 'BILL', 'ALLEN', 20, 'SEATTLE', 300.22);");

    exit = sqlite3_exec(db, query1.c_str(), NULL, 0, &error);
    if (exit != SQLITE_OK) {
        cerr << "Error Insert\n";
        cout << error << "\n";
        sqlite3_free(error);
    }
    else
        cout << "Records created Successfully!\n";

    cout << "\n";

    query = "SELECT * FROM PERSON;";
    sqlite3_exec(db, query.c_str(), callback, NULL, NULL);

    query = "DELETE FROM PERSON WHERE ID = 2;";
    exit = sqlite3_exec(db, query.c_str(), callback, NULL, NULL);

    if (exit != SQLITE_OK) {
        cerr << "Error DELETE\n";
        sqlite3_free(error);
    }
    else
        cout << "Records deleted Successfully!\n";

    cout << "\n";    

    cout << "\nAFTER DELETION\n";
    query = "SELECT * FROM PERSON;";
    sqlite3_exec(db, query.c_str(), callback, NULL, NULL);

    query = "SELECT DATE(now);";
    int t = sqlite3_exec(db, query.c_str(), callback1, NULL, NULL);
    cout << t;
    sqlite3_close(db);
    return (0);
}