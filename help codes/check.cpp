#include <ctime>
#include <iomanip>
#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
    auto ztime = time(0);
    stringstream _time;
    _time << put_time(localtime(&ztime), "%H:%M");
    // cout << _time;  
    string x = _time.str();
    cout << x;
}