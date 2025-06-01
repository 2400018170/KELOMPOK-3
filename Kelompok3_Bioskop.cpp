#include <iostream>
#include <fstream>      // Diperlukan untuk file
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

// Fungsi untuk menyimpan data pembeli
void simpanDataPembeli() {
    string nama, nowa;

    cin.ignore(); // Bersihkan buffer sebelum getline
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
    cout << "\n? Data berhasil disimpan ke file.\n\n";
}

// Fungsi untuk menampilkan data pembeli
void tampilkanDataPembeli() {
    ifstream file("datapembeliantiket.txt");
    if (!file.is_open()) {
        cerr << "? Gagal membuka file untuk dibaca." << endl;
        return;
    }

    cout << "\n=========== DAFTAR DATA PEMBELI ===========" << endl;
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
    cout << "===========================================\n\n";
}

// Fungsi login admin
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
        cout << " Login berhasil!\n" << endl;
        return true;
    } else {
        cout << " Login gagal! Silakan coba lagi.\n" << endl;
        return false;
    }
}

int main() {
    bool isLoggedIn = false;
    while (!isLoggedIn) {
        isLoggedIn = adminlogin();
    }
    system("pause");
    system("CLS");

    char ulang;
    do {
        int opsi;
        cout <<"========DAFTAR MENU========" <<endl;
        cout <<" 1. Tambah Pembeli Ke Antrian "<<endl;
        cout <<" 2. Daftar FILM "<<endl;
        cout <<" 3. Pemesanan Tiket "<<endl;
        cout <<" 4. Chekout "<<endl;
        cout <<" 5. Cetak Tiket "<<endl;
        cout <<" 6. Keluar "<<endl;
        cout << "Masukkan pilihan anda : ";
        cin >> opsi;

        switch (opsi) {
            case 1: {
                char tambahLagi;
                do {
                    simpanDataPembeli();
                    cout << "Tambah pembeli lagi? (y/n) : ";
                    cin >> tambahLagi;
                    cin.ignore();
                } while (tambahLagi == 'y' || tambahLagi == 'Y');
                break;
            }
            case 2:
                tampilkanDataPembeli();
                break;
            case 6:
                cout << "Keluar dari program. Terima kasih!\n";
                return 0;
            default:
                cout << " Pilihan tidak tersedia.\n";
        }

        cout << "Kembali ke menu utama? (y/n): ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}
