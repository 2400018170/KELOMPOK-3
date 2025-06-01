#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <limits>  
using namespace std;

void simpanDataPembeli() {
    string nama, nowa;

    cin.ignore();
    cout << "=========== INPUT DATA PEMBELI ===========" << endl;
    cout << "Masukkan Nama Pembeli       : ";
    getline(cin, nama);

    cout << "Masukkan Nomor WhatsApp     : ";
    getline(cin, nowa);

    ofstream file("datapembeliantiket.txt", ios::app);
    if (!file.is_open()) {
        cerr << "? Gagal membuka file untuk ditulis." << endl;
        return;
    }

    file << "Nama Pembeli     : " << nama << endl;
    file << "Nomor WhatsApp   : " << nowa << endl;
    file << "------------------------------------------\n";

    file.close();
    cout << "\n Data berhasil disimpan ke file.\n\n";
}

// Fungsi untuk menampilkan semua data pembeli dari file
void tampilkanDataPembeli() {
    ifstream file("datapembeliantiket.txt");
    if (!file.is_open()) {
        cerr << "? Gagal membuka file untuk dibaca." << endl;
        return;
    }

    cout << "=========== DAFTAR DATA PEMBELI ===========" << endl;
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
    cout << "===========================================\n\n";
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

void cetakBingkaiAtasBawah(int panjang) {
    for (int i = 0; i < panjang; i++) {
        cout << "=";
    }
    cout << endl;
}

int main (){
     bool isLoggedIn = false;

    while (!isLoggedIn) {
        isLoggedIn = adminlogin();
    }

  char ulang;
    do{
        int opsi;
        cout <<"========DAFTAR MENU========" <<endl;
        cout <<" 1. Tambah Pembeli Ke Antrian "<<endl;
        cout <<" 2. Daftar FILM "<<endl;
        cout <<" 3. Pemesanan Tiket "<<endl;
        cout <<" 4. Chekout "<<endl;
        cout <<" 5. Cetak Tiket "<<endl;
        cout <<" 6. Keluar "<<endl;
        
        cout<<"Masukkan pilihan anda : "; cin>>opsi;
        
        if(opsi==1){
            char ulang;
            do{
                simpanDataPembeli();
                cout<<"Tambah pembeli lagi? (y/n) : "; cin>>ulang;
                cin.ignore();
            }while(ulang=='y' || ulang=='Y');
        }
        cout << "Apakah Anda ingin mengulangi program Utama? (y/n): ";
        cin >> ulang;
    }while (ulang == 'y' || ulang == 'Y');
    
    return 0;
}
