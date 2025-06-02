#include <iostream>
#include <fstream>      // Diperlukan untuk file.txt
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cctype>

using namespace std;

struct Akun {
    string nama;
    string telepon;
    string email;
    string username;
    string password;
};

void registrasi() {
    Akun akun;
    cout << "\n=== REGISTRASI AKUN ===\n";
    cout << "Nama Lengkap     : ";
    getline(cin, akun.nama);
    cout << "Nomor Telepon    : ";
    getline(cin, akun.telepon);
    cout << "Email            : ";
    getline(cin, akun.email);
    cout << "Username         : ";
    getline(cin, akun.username);
    cout << "Password         : ";
    getline(cin, akun.password);

    ofstream file("akun.txt", ios::app);
    if (file.is_open()) {
        file << akun.nama << ";" << akun.telepon << ";" << akun.email << ";" << akun.username << ";" << akun.password << endl;
        file.close();
        cout << "\nRegistrasi berhasil!\n";
    } else {
        cout << "\nGagal menyimpan data!\n";
    }
}

void menu_login(){
	cout << "\n=== MENU ===\n";
        cout << "1. Registrasi\n";
        cout << "2. Login\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
}

bool login() {
    string inputUser, inputPass;
    system("cls");
    cout << "\n=== LOGIN ===\n";
    cout << "Username: ";
    getline(cin, inputUser);
    cout << "Password: ";
    getline(cin, inputPass);

    ifstream file("akun.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka file data akun.\n";
        return false;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string nama, telepon, email, username, password;

        getline(ss, nama, ';');
        getline(ss, telepon, ';');
        getline(ss, email, ';');
        getline(ss, username, ';');
        getline(ss, password, ';');

        if (username == inputUser && password == inputPass) {
            cout << "\nLogin berhasil!\n";
            cout << "Selamat datang, " << nama << "!\n";
            cout << "Email   : " << email << "\n";
            cout << "Telepon : " << telepon << "\n";
            return true;
        }
    }

    cout << "\nLogin gagal. Username atau password salah.\n";
    system("pause");
    login();
    return false;
}



//***Fungsi untuk menyimpan data pembeli***
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
        cerr << " Gagal membuka file untuk ditulis." << endl;
        return;
    }

    file << "Nama Pembeli     : " << nama << endl;
    file << "Nomor WhatsApp   : " << nowa << endl;
    file << "------------------------------------------\n";

    file.close();
    cout << "\nData berhasil disimpan ke file.\n\n";
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

const int JUMLAH_FILM = 9;

// Struktur film
struct Film {
    string judul;
    string deskripsi;
    string genre;
    string durasi;
    string jadwal[5];
    int harga; // Tambahan: harga tiket
};

// Data film
Film daftarFilm[JUMLAH_FILM] = {
   {
        "KARATE KID: LEGENDS",
        "Setelah pindah ke New York, Li Fong berusaha menyesuaikan diri di sekolah barunya. Saat mengikuti kompetisi karate demi membantu temannya, ia menyadari keterampilannya belum cukup. Dengan bimbingan Tn. Han dan Daniel LaRusso, Li belajar menggabungkan dua gaya bela diri untuk menghadapi pertarungan penting.",
        "Action",
        "1 jam 30 menit",
        {"13:30", "15:20", "17:10", "19:00", "20:50"},
        45000
    },
    {
        "GOWOK KAMASUTRA JAWA",
        "Ratri, anak seorang pelacur yang diasuh oleh Nyai Santi, tumbuh menjadi gadis cantik dan pewaris ilmu gowokan. Ia jatuh cinta pada Kamanjaya, namun dikhianati setelah mereka bercinta. Dua puluh tahun kemudian, mereka bertemu lagi saat putra Kamanjaya, Bagas, datang belajar pada Nyai Santi dan jatuh cinta pada Ratri, tanpa mengetahui masa lalu orang tua mereka. Ratri pun melihat kesempatan untuk membalas dendam.",
        "Drama",
        "2 jam 5 menit",
        {"13:10", "15:30", "17:00", "19:00", "20:30"},
        35000
    },
    {
        "LILO & STITCH",
        "Lilo (Maia Kealoha) seorang anak kecil dari Hawaii yang kesepian bertemu dengan Stitch (Chris Sanders), seorang alien yang melarikan diri dari planet asalnya. Keduanya kini berteman dan mencoba memperbaiki kondisi keluarga yang terpecah belah.",
        "Adventure, Fantasy",
        "1 jam 48 menit",
        {"11:00", "14:30", "15:00", "18:00", "  "},
        40000
    },
    {
        "MISSION:IMPOSSIBLE - THE FINAL RECKONING",
        "Melanjutkan kisah dari film sebelumnya, Mission: Impossible - Dead Reckoning Part One. Ethan Hunt (Tom Cruise) akan kembali meneruskan misi untuk menghancurkan musuh lama dan musuh baru yang lebih berbahaya.",
        "Action",
        "2 jam 49 menit",
        {"13:00", "14:35", "17:40", "20:15", "20:45"},
        45000
    },
    {
        "FINAL DESTINATION: BLOODLINES",
        "Film horor terbaru dari waralaba New Line Cinema ini mengikuti Stefanie, seorang mahasiswi yang diteror mimpi buruk berulang. Ia kembali ke kampung halamannya untuk mencari orang yang bisa mematahkan kutukan dan menyelamatkan keluarganya dari kematian tragis yang tak terelakkan.",
        "Action",
        "1 jam 30 menit",
        {"12:15", "14:20", "16:25", "18:00", "20:25"},
        45000
    },
    {
        "BALLERINA",
        "Eve (Ana de Armas) seorang pembunuh yang terlatih dalam tradisi organisasi Ruska Roma berangkat untuk membalas dendam setelah kematian ayahnya.",
        "Action, Thriller",
        "2 jam 4 menit",
        {"12:00", "14:20", "16:40", "19:00", "21:20"},
        35000
    },
    {
        "GOWOK KAMASUTRA JAWA UNCUT",
        "Ratri (Alika Jantinia) merupakan anak dari seorang pelacur, tanpa mengetahui siapa ayahnya. Sejak bayi, ia diasuh oleh Nyai Santi (Lola Amaria), seorang gowok yang bijaksana dan disegani.",
        "Drama",
        "2 jam 12 menit",
        {"  ", "  ", "  ", "  ", "20:50"},
        40000
    },
    {
        "WAKTU MAGHRIB 2",
        "Dua puluh tahun setelah kejadian di Jatijajar, Jin Ummu Sibyan kembali meneror, kini di desa Giritirto. Usai keributan saat pertandingan bola, sekelompok anak menyumpahi tim lawan dalam perjalanan pulang saat maghrib. Tanpa sadar, mereka membangkitkan kembali teror lama. Kali ini, Ummu Sibyan merasuki salah satu dari mereka dan mulai memburu nyawa anak-anak dengan lebih mencekam.",
        "Horror",
        "1 jam 47 menit",
        {"12:35", "14:40", "16:45", "18:50", "20:55"},
        40000
    },
    {
        "GUNDIK",
        "Osman, mantan tentara, merencanakan perampokan bersama timnya, termasuk menantunya, Baim. Namun, mereka terjebak mimpi buruk saat mengetahui target mereka adalah siluman sakti penguasa Pantai Selatan.",
        "Action",
        "1 jam 52 menit",
        {"12:05", "  ", "16:15", "  ", "20:25"},
        45000
    }
};

// Fungsi untuk membersihkan input
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Fungsi menampilkan daftar film
void tampilkanDaftarFilm() {
    cout << "=== Daftar Film di Bioskop ===\n";
    for (int i = 0; i < JUMLAH_FILM; i++) {
        cout << "\n" << i + 1 << ". " << daftarFilm[i].judul << endl;
        cout << "   Genre     : " << daftarFilm[i].genre << endl;
        cout << "   Durasi    : " << daftarFilm[i].durasi << endl;
        cout << "   Harga     : Rp" << daftarFilm[i].harga << endl;
        cout << "   Deskripsi : " << daftarFilm[i].deskripsi << endl;
        cout << "   Jadwal    : ";
        for (int j = 0; j < 5; j++) {
            if (!daftarFilm[i].jadwal[j].empty()) {
                cout << daftarFilm[i].jadwal[j];
                if (j < 4 && !daftarFilm[i].jadwal[j + 1].empty()) cout << " | ";
            }
        }
        cout << "\n";
    }
}

// Fungsi memilih film
int pilihFilm() {
    int pilihan;
    cout << "\nPilih nomor film (1-" << JUMLAH_FILM << "): ";
    cin >> pilihan;

    if (cin.fail()) {
        clearInput();
        cout << "Input tidak valid.\n";
        return -1;
    }

    if (pilihan < 1 || pilihan > JUMLAH_FILM) {
        cout << "Pilihan tidak tersedia.\n";
        return -1;
    }

    return pilihan - 1;
}



// Fungsi memilih jadwal
string pilihJadwal(Film f) {
    cout << "\nPilih jadwal tayang:\n";

    int opsiValid[5];
    int jumlahOpsi = 0;

    for (int i = 0; i < 5; i++) {
        if (!f.jadwal[i].empty()) {
            cout << jumlahOpsi + 1 << ". " << f.jadwal[i] << endl;
            opsiValid[jumlahOpsi++] = i;
        }
    }

    int pilihan;
    cout << "Pilihan: ";
    cin >> pilihan;

    if (cin.fail() || pilihan < 1 || pilihan > jumlahOpsi) {
        clearInput();
        cout << "Pilihan tidak valid.\n";
        return "";
    }

    return f.jadwal[opsiValid[pilihan - 1]];
}

// Fungsi memasukkan jumlah tiket
int masukkanJumlahTiket() {
    int jumlah;
    cout << "\nMasukkan jumlah tiket yang ingin dipesan: ";
    cin >> jumlah;

    if (cin.fail() || jumlah <= 0) {
        clearInput();
        cout << "Jumlah tiket tidak valid.\n";
        return -1;
    }

    return jumlah;
}

const int ROWS = 17;
const int COLS = 20;
const int JUMLAH_STUDIO = 5;
const int JUMLAH_KURSI = ROWS * COLS;

char studio[JUMLAH_STUDIO][JUMLAH_KURSI]; // Array 1D kursi tiap studio

// Inisialisasi semua kursi ke 'O'
void inisialisasiKursi() {
    for (int s = 0; s < JUMLAH_STUDIO; ++s) {
        for (int k = 0; k < JUMLAH_KURSI; ++k) {
            studio[s][k] = 'O'; // O = Kosong
        }
    }
}

// Menampilkan daftar studio
void tampilkanStudio() {
    cout << "\n=========== PILIH STUDIO ===========" << endl;
    for (int i = 0; i < JUMLAH_STUDIO; ++i) {
        if (i == JUMLAH_STUDIO - 1)
            cout << i + 1 << ". Studio " << i + 1 << " (VIP)" << endl;
        else
            cout << i + 1 << ". Studio " << i + 1 << " (Reguler)" << endl;
    }
    cout << "====================================\n";
}

// Menampilkan kursi dari studio tertentu
void tampilkanKursi(int studioIndex) {
    cout << "\nTampilan Kursi di Studio " << studioIndex + 1;
    if (studioIndex == JUMLAH_STUDIO - 1) cout << " (VIP)";
    cout << endl;

    // Header kolom
    cout << "    ";
    for (int j = 0; j < COLS; ++j) {
        cout << setw(2) << j + 1 << " ";
    }
    cout << endl;

    // Baris A-Q (0..16)
    for (int i = 0; i < ROWS; ++i) {
        cout << " " << char('A' + i) << "  ";
        for (int j = 0; j < COLS; ++j) {
            int idx = i * COLS + j;
            cout << " " << studio[studioIndex][idx] << " ";
        }
        cout << endl;
    }
}

//FUNGSI MEMESAN KURSI
void pesanKursi() {
    tampilkanStudio();
    int pilihanStudio;
    cout << "Pilih nomor studio (1-5): ";
    cin >> pilihanStudio;

    if (pilihanStudio < 1 || pilihanStudio > JUMLAH_STUDIO) {
        cout << "Pilihan studio tidak valid.\n";
        return;
    }

    int studioIndex = pilihanStudio - 1;
    tampilkanKursi(studioIndex);

    char barisChar;
    int kolom;

    cout << "\nMasukkan Baris Kursi (A-Q): ";
    cin >> barisChar;
    barisChar = toupper(barisChar);

    cout << "Masukkan Nomor Kursi (1-20): ";
    cin >> kolom;

    int baris = barisChar - 'A';
    kolom -= 1;

    if (baris < 0 || baris >= ROWS || kolom < 0 || kolom >= COLS) {
        cout << "Posisi kursi tidak valid.\n";
        return;
    }

    int idx = baris * COLS + kolom;

    if (studio[studioIndex][idx] == 'X') {
        cout << "\n Kursi " << barisChar << kolom + 1 << " sudah dipesan.\n";
    } else {
        studio[studioIndex][idx] = 'X';
        cout << "\n Kursi " << barisChar << kolom + 1 << " berhasil dipesan di Studio " << pilihanStudio;
        if (studioIndex == 4) cout << " (VIP)";
        cout << ".\n";
    }

    tampilkanKursi(studioIndex);
}

void daftar_menu(){
	cout <<"======== DAFTAR MENU ========" <<endl;
        cout <<" 1. Tambah Pembeli Ke Antrian "<<endl;
        cout <<" 2. Daftar FILM dan Pemesanan Tiket "<<endl;
        cout <<" 3. Pemilihan Kursi "<<endl;
        cout <<" 4. Chekout "<<endl;
        cout <<" 5. Cetak Tiket "<<endl;
        cout <<" 6. Tampilkan Data Pembeli "<<endl;
        cout <<" 7. Keluar "<<endl;
        cout << "Masukkan pilihan anda : ";
}

//***MAIN FUNCTION***
int main() {
	int pilihan;
    	do {
        	menu_login();
        	cin >> pilihan;
        	cin.ignore(); // membersihkan newline dari input buffer

        	switch (pilihan) {
            	case 1:
                	registrasi();
                	break;
            	case 2:
                	login();
                	pilihan = 0;
                	break;
            	case 0:
                	cout << "Terima kasih!\n";
                	return 0;
                	break;
            	default:
                	cout << "Pilihan tidak valid.\n";
        	}
    	} while (pilihan != 0);
    cout << "\n";
    system("pause");
    system("CLS");

    char ulang;
    	do {
        	int opsi;
        	daftar_menu();
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
            	case 2: {
            		char mengulang;
            		do{
            			tampilkanDaftarFilm();
            		
            			int indexFilm = pilihFilm();
				    	if (indexFilm == -1) return 1;
				
				    	Film filmTerpilih = daftarFilm[indexFilm];
				    	cout << "\nAnda memilih: " << filmTerpilih.judul << endl;
				
				    	string jadwalDipilih = pilihJadwal(filmTerpilih);
				    	if (jadwalDipilih == "") return 1;
				
				    	int jumlahTiket = masukkanJumlahTiket();
				    	if (jumlahTiket == -1) return 1;
				
				    	int totalHarga = jumlahTiket * filmTerpilih.harga;
				
				    	cout << "\n=== Ringkasan Pesanan ===\n";
				    	cout << "Judul       : " << filmTerpilih.judul << endl;
				    	cout << "Genre       : " << filmTerpilih.genre << endl;
				    	cout << "Durasi      : " << filmTerpilih.durasi << endl;
				    	cout << "Jadwal      : " << jadwalDipilih << endl;
				    	cout << "Harga Tiket : Rp" << filmTerpilih.harga << endl;
				    	cout << "Jumlah      : " << jumlahTiket << " tiket\n";
				    	cout << "Total Harga : Rp" << totalHarga << endl;
				    	cout << "Tiket berhasil dipesan! Selamat menonton!\n";
				    
				    	cout << "Ingin memesan lagi? (y/n) : ";
                    	cin >> mengulang;
						}while (mengulang == 'y' || mengulang == 'Y');
					break;
				}
				case 3: {
					char ulang;
					do{
						inisialisasiKursi();
			        	cout << "\n====== SISTEM PEMESANAN KURSI BIOSKOP XXI ======\n";
			        	pesanKursi();
			
			        	cout << "\nPesan kursi lagi? (y/n): ";
			        	cin >> ulang;
					}while (ulang == 'y' || ulang == 'Y');
					break;
				}
            	case 6:
                	tampilkanDataPembeli();
                	break;
            	case 7:
                	cout << "Keluar dari program. Terima kasih!\n";
                	return 0;
            	default:
                	cout << "Pilihan tidak tersedia.\n";
        	}

        	cout << "Kembali ke menu utama? (y/n): ";
        	cin >> ulang;
    	} while (ulang == 'y' || ulang == 'Y');

	cout << "Keluar dari program. Terima kasih!\n";
    return 0;
}
