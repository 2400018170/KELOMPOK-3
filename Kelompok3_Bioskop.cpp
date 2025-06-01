#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <limits>  
using namespace std;

struct Bioskop {
  string nama;
}

// Fungsi untuk login admin
bool adminlogin() {
    string username, password;
    const string ADMIN_USERNAME = "kelompok3";
    const string ADMIN_PASSWORD = "152169170";

    cout << "==== Login Admin ====" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD) {
        cout << "Login berhasil!\n" << endl;
        return true;
    } else {
        cout << "Login gagal! Silakan coba lagi.\n" << endl;
        return false;
    }
}

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main (){
     bool isLoggedIn = false;

    while (!isLoggedIn) {
        isLoggedIn = adminlogin();
    }
    
    return 0;
}
