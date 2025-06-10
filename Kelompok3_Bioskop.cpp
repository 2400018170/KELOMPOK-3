#include <iostream>
#include <fstream>     
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cctype>
#include <limits>
using namespace std;

struct Akun {
    string nama_lengkap;
    string no_telepon;
    string email;
    string username;
    string password;
};

// Membaca semua akun dari file
vector<Akun> bacaAkun() {
    vector<Akun> daftar;
    ifstream file("akun.txt");
    Akun a;

    while (getline(file, a.nama_lengkap)) {
        getline(file, a.no_telepon);
        getline(file, a.email);
        getline(file, a.username);
        getline(file, a.password);
        daftar.push_back(a);
    }
    file.close();
    return daftar;
}

// Menyimpan semua akun ke file
void simpanAkun(const vector<Akun>& daftar) {
    ofstream file("akun.txt");
    for (size_t i = 0; i < daftar.size(); ++i) {
        file << daftar[i].nama_lengkap << "\n"
             << daftar[i].no_telepon << "\n"
             << daftar[i].email << "\n"
             << daftar[i].username << "\n"
             << daftar[i].password << "\n";
    }
    file.close();
}

// Registrasi akun baru
void registrasi() {
    system("CLS");
    Akun baru;
    cout << "== Registrasi Akun Baru ==\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nama lengkap : "; getline(cin, baru.nama_lengkap);
    cout << "Nomor telepon: "; getline(cin, baru.no_telepon);
    cout << "Email        : "; getline(cin, baru.email);
    cout << "Username     : "; getline(cin, baru.username);
    cout << "Password     : "; getline(cin, baru.password);

    vector<Akun> daftar = bacaAkun();

    for (size_t i = 0; i < daftar.size(); ++i) {
        if (daftar[i].username == baru.username) {
            cout << "Username sudah digunakan.\n";
            system("pause");
            return;
        }
    }

    daftar.push_back(baru);
    simpanAkun(daftar);
    cout << "Registrasi berhasil.\n";
    system("pause");
}

// Login, return index akun yang login atau -1 jika gagal
int login() {
    system("CLS");
    string uname, pass;
    cout << "== Login ==\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Username: "; getline(cin, uname);
    cout << "Password: "; getline(cin, pass);

    vector<Akun> daftar = bacaAkun();

    for (size_t i = 0; i < daftar.size(); ++i) {
        if (daftar[i].username == uname && daftar[i].password == pass) {
            cout << "Login berhasil. Selamat datang, " << daftar[i].nama_lengkap << "!\n";
            system("pause");
    		system("CLS");
            return (int)i;
        }
    }
    cout << "Username atau password salah.\n";
    system("pause");
    return -1;
}

// Hapus akun
void hapusAkun() {
    system("CLS");
    string uname, pass;
    char konfirmasi;
    cout << "== Hapus Akun ==\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Username: "; getline(cin, uname);
    cout << "Password: "; getline(cin, pass);

    vector<Akun> daftar = bacaAkun();
    bool ditemukan = false;

    for (size_t i = 0; i < daftar.size(); ++i) {
        if (daftar[i].username == uname && daftar[i].password == pass) {
            cout << "Yakin ingin menghapus akun ini? (y/n): ";
            cin >> konfirmasi;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                daftar.erase(daftar.begin() + i);
                simpanAkun(daftar);
                cout << "Akun berhasil dihapus.\n";
                system("pause");
            } else if(konfirmasi == 'n' || konfirmasi == 'N'){
                cout << "Penghapusan dibatalkan.\n";
                system("pause");
            } else {
                cout << "Input Invalid!. Penghapusan dibatalkan.\n";
                system("pause");
            }
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Akun tidak ditemukan atau password salah.\n";
        system("pause");
    }
}

// Menu sebelum login
void menu_before_login() {
    system("CLS");
    cout << "--------------------------------\n";
    cout << "=== MENU LOGIN===\n";
    cout << "1. Registrasi Akun\n";
    cout << "2. Login\n";
    cout << "3. Hapus Akun\n";
    cout << "0. Keluar\n";
    cout << "Pilih: ";
}

// Menu setelah login
void menu_after_login() {
    cout << "--------------------------------\n";
    cout << "=== MENU UTAMA ===\n";
    cout << "1. Lihat Data Diri\n";
    cout << "2. Lihat Jadwal Tayangan\n";
    cout << "3. Logout\n";
    cout << "0. Keluar\n";
    cout << "Pilih: ";
}

// Tampilkan data diri username & nama lengkap user yang login
void lihatDataDiri(const Akun& user){
    system("CLS");
    cout << "=== Data Diri ===\n";
    cout << "Username   : " << user.username << "\n";
    cout << "Nama lengkap: " << user.nama_lengkap << "\n";
    cout << "Nomer Telepon: " << user.no_telepon << "\n";
    cout << "Alamat Email: " << user.email << "\n";    
}

struct Film {
    char judul[100];
    char sinopsis[1000];
    char waktu[30];
    char durasi[50];
};

struct Studio {
    char nama[20];
    Film jadwal[10];
    int jumlahFilm;
};

// Data studio & jadwal film (dipotong, Anda bisa gunakan data lengkap dari sebelumnya)
Studio bioskop[7] = {
    {"STUDIO 1", {
        {"BALLERINA","Eve (Ana de Armas) seorang pembunuh yang terlatih dalam tradisi organisasi Ruska Roma berangkat untuk membalas dendam setelah kematian ayahnya.",
		 "12:00:00 - 14:04:00", "2 jam 4 menit"},
        {"FINAL DESTINATION: BLOODLINES","Film horor terbaru dari waralaba New Line Cinema ini mengikuti Stefanie, seorang mahasiswi yang diteror mimpi buruk berulang. Ia kembali ke kampung halamannya untuk mencari orang yang bisa mematahkan kutukan dan menyelamatkan keluarganya dari kematian tragis yang tak terelakkan.",
		 "14:20:00 - 15:50:00", "1 jam 30 menit"},
        {"GUNDIK","Osman, mantan tentara, merencanakan perampokan bersama timnya, termasuk menantunya, Baim. Namun, mereka terjebak mimpi buruk saat mengetahui target mereka adalah siluman sakti penguasa Pantai Selatan.",
		 "16:15:00 - 18:07:00", "1 jam 52 menit"},
        {"WAKTU MAGHRIB 2","Dua puluh tahun setelah kejadian di Jatijajar, Jin Ummu Sibyan kembali meneror, kini di desa Giritirto. Usai keributan saat pertandingan bola, sekelompok anak menyumpahi tim lawan dalam perjalanan pulang saat maghrib. Tanpa sadar, mereka membangkitkan kembali teror lama. Kali ini, Ummu Sibyan merasuki salah satu dari mereka dan mulai memburu nyawa anak-anak dengan lebih mencekam.",
		 "18:50:00 - 20:37:00", "1 jam 47 menit"},
        {"KARATE KID: LEGENDS","Setelah pindah ke New York, Li Fong berusaha menyesuaikan diri di sekolah barunya. Saat mengikuti kompetisi karate demi membantu temannya, ia menyadari keterampilannya belum cukup. Dengan bimbingan Tn. Han dan Daniel LaRusso, Li belajar menggabungkan dua gaya bela diri untuk menghadapi pertarungan penting.", 
		"20:50:00 - 22:20:00", "1 jam 30 menit"},
        {"GOWOK KAMASUTRA JAWA","Ratri, anak seorang pelacur yang diasuh oleh Nyai Santi, tumbuh menjadi gadis cantik dan pewaris ilmu gowokan. Ia jatuh cinta pada Kamanjaya, namun dikhianati setelah mereka bercinta. Dua puluh tahun kemudian, mereka bertemu lagi saat putra Kamanjaya, Bagas, datang belajar pada Nyai Santi dan jatuh cinta pada Ratri, tanpa mengetahui masa lalu orang tua mereka. Ratri pun melihat kesempatan untuk membalas dendam.",
		 "22:30:00 - 00:35:00", "2 jam 5 menit"},
    }, 6},
    {"STUDIO 2", {
        {"GUNDIK","Osman, mantan tentara, merencanakan perampokan bersama timnya, termasuk menantunya, Baim. Namun, mereka terjebak mimpi buruk saat mengetahui target mereka adalah siluman sakti penguasa Pantai Selatan.",
		 "12:05:00 - 13:57:00", "1 jam 52 menit"},
        {"BALLERINA","Eve (Ana de Armas) seorang pembunuh yang terlatih dalam tradisi organisasi Ruska Roma berangkat untuk membalas dendam setelah kematian ayahnya.",
		 "14:20:00 - 16:24:00", 
		 "2 jam 4 menit"},
        {"BALLERINA","Eve (Ana de Armas) seorang pembunuh yang terlatih dalam tradisi organisasi Ruska Roma berangkat untuk membalas dendam setelah kematian ayahnya.",
		 "16:40:00 - 18:44:00", "2 jam 4 menit"},
        {"GOWOK KAMASUTRA JAWA","Ratri, anak seorang pelacur yang diasuh oleh Nyai Santi, tumbuh menjadi gadis cantik dan pewaris ilmu gowokan. Ia jatuh cinta pada Kamanjaya, namun dikhianati setelah mereka bercinta. Dua puluh tahun kemudian, mereka bertemu lagi saat putra Kamanjaya, Bagas, datang belajar pada Nyai Santi dan jatuh cinta pada Ratri, tanpa mengetahui masa lalu orang tua mereka. Ratri pun melihat kesempatan untuk membalas dendam.",
		 "17:00:00 - 19:05:00", "2 jam 5 menit"},
        {"MISSION:IMPOSSIBLE - THE FINAL RECKONING","Melanjutkan kisah dari film sebelumnya, Mission: Impossible - Dead Reckoning Part One. Ethan Hunt (Tom Cruise) akan kembali meneruskan misi untuk menghancurkan musuh lama dan musuh baru yang lebih berbahaya.",
		 "20:15:00 - 23:04:00", "2 jam 49 menit"},
        {"WAKTU MAGHRIB 2","Dua puluh tahun setelah kejadian di Jatijajar, Jin Ummu Sibyan kembali meneror, kini di desa Giritirto. Usai keributan saat pertandingan bola, sekelompok anak menyumpahi tim lawan dalam perjalanan pulang saat maghrib. Tanpa sadar, mereka membangkitkan kembali teror lama. Kali ini, Ummu Sibyan merasuki salah satu dari mereka dan mulai memburu nyawa anak-anak dengan lebih mencekam.",
		 "23:14:00 - 01:01:00", "1 jam 47 menit"},
    }, 6},
    {"STUDIO 3", {
        {"FINAL DESTINATION: BLOODLINES","Film horor terbaru dari waralaba New Line Cinema ini mengikuti Stefanie, seorang mahasiswi yang diteror mimpi buruk berulang. Ia kembali ke kampung halamannya untuk mencari orang yang bisa mematahkan kutukan dan menyelamatkan keluarganya dari kematian tragis yang tak terelakkan.",
		 "12:15:00 - 13:45:00"},
        {"LILO & STITCH", "Lilo (Maia Kealoha) seorang anak kecil dari Hawaii yang kesepian bertemu dengan Stitch (Chris Sanders), seorang alien yang melarikan diri dari planet asalnya. Keduanya kini berteman dan mencoba memperbaiki kondisi keluarga yang terpecah belah.",
		 "14:30:00 - 16:18:00", "1 jam 48 menit"},
        {"FINAL DESTINATION: BLOODLINES","Film horor terbaru dari waralaba New Line Cinema ini mengikuti Stefanie, seorang mahasiswi yang diteror mimpi buruk berulang. Ia kembali ke kampung halamannya untuk mencari orang yang bisa mematahkan kutukan dan menyelamatkan keluarganya dari kematian tragis yang tak terelakkan.",
		 "16:25:00 - 17:55:00", "1 jam 30 menit"},
        {"FINAL DESTINATION: BLOODLINES","Film horor terbaru dari waralaba New Line Cinema ini mengikuti Stefanie, seorang mahasiswi yang diteror mimpi buruk berulang. Ia kembali ke kampung halamannya untuk mencari orang yang bisa mematahkan kutukan dan menyelamatkan keluarganya dari kematian tragis yang tak terelakkan.",
		 "18:00:00 - 19:30:00", "1 jam 30 menit"},
        {"FINAL DESTINATION: BLOODLINES","Film horor terbaru dari waralaba New Line Cinema ini mengikuti Stefanie, seorang mahasiswi yang diteror mimpi buruk berulang. Ia kembali ke kampung halamannya untuk mencari orang yang bisa mematahkan kutukan dan menyelamatkan keluarganya dari kematian tragis yang tak terelakkan.",
		 "19:45:00 - 21:15:00", "1 jam 30 menit"},
        {"WAKTU MAGHRIB 2","Dua puluh tahun setelah kejadian di Jatijajar, Jin Ummu Sibyan kembali meneror, kini di desa Giritirto. Usai keributan saat pertandingan bola, sekelompok anak menyumpahi tim lawan dalam perjalanan pulang saat maghrib. Tanpa sadar, mereka membangkitkan kembali teror lama. Kali ini, Ummu Sibyan merasuki salah satu dari mereka dan mulai memburu nyawa anak-anak dengan lebih mencekam.",
		 "23:14:00 - 01:01:00", "1 jam 47 menit"},
    }, 6},
    {"STUDIO 4", {
        {"WAKTU MAGHRIB 2","Dua puluh tahun setelah kejadian di Jatijajar, Jin Ummu Sibyan kembali meneror, kini di desa Giritirto. Usai keributan saat pertandingan bola, sekelompok anak menyumpahi tim lawan dalam perjalanan pulang saat maghrib. Tanpa sadar, mereka membangkitkan kembali teror lama. Kali ini, Ummu Sibyan merasuki salah satu dari mereka dan mulai memburu nyawa anak-anak dengan lebih mencekam.",
		 "12:35:00 - 14:22:00", "1 jam 47 menit"},
        {"WAKTU MAGHRIB 2","Dua puluh tahun setelah kejadian di Jatijajar, Jin Ummu Sibyan kembali meneror, kini di desa Giritirto. Usai keributan saat pertandingan bola, sekelompok anak menyumpahi tim lawan dalam perjalanan pulang saat maghrib. Tanpa sadar, mereka membangkitkan kembali teror lama. Kali ini, Ummu Sibyan merasuki salah satu dari mereka dan mulai memburu nyawa anak-anak dengan lebih mencekam.",
		 "14:40:00 - 16:27:00", "1 jam 47 menit"},
        {"BALLERINA","Eve (Ana de Armas) seorang pembunuh yang terlatih dalam tradisi organisasi Ruska Roma berangkat untuk membalas dendam setelah kematian ayahnya.",
		 "16:40:00 - 18:44:00", "2 jam 4 menit"},
        {"BALLERINA","Eve (Ana de Armas) seorang pembunuh yang terlatih dalam tradisi organisasi Ruska Roma berangkat untuk membalas dendam setelah kematian ayahnya.",
		 "19:00:00 - 21:04:00", "2 jam 4 menit"},
        {"BALLERINA","Eve (Ana de Armas) seorang pembunuh yang terlatih dalam tradisi organisasi Ruska Roma berangkat untuk membalas dendam setelah kematian ayahnya.",
		 "21:30:00 - 23:34:00", "2 jam 4 menit"},
        {"KARATE KID: LEGENDS","Setelah pindah ke New York, Li Fong berusaha menyesuaikan diri di sekolah barunya. Saat mengikuti kompetisi karate demi membantu temannya, ia menyadari keterampilannya belum cukup. Dengan bimbingan Tn. Han dan Daniel LaRusso, Li belajar menggabungkan dua gaya bela diri untuk menghadapi pertarungan penting.",
		 "23:45:00 - 01:15:00", "1 jam 30 menit"},
    }, 6},
    {"STUDIO 5", {
        {"MISSION:IMPOSSIBLE - THE FINAL RECKONING","Melanjutkan kisah dari film sebelumnya, Mission: Impossible - Dead Reckoning Part One. Ethan Hunt (Tom Cruise) akan kembali meneruskan misi untuk menghancurkan musuh lama dan musuh baru yang lebih berbahaya.",
		 "13:00:00 - 15:49:00", "2 jam 49 menit"},
        {"KARATE KID: LEGENDS","Setelah pindah ke New York, Li Fong berusaha menyesuaikan diri di sekolah barunya. Saat mengikuti kompetisi karate demi membantu temannya, ia menyadari keterampilannya belum cukup. Dengan bimbingan Tn. Han dan Daniel LaRusso, Li belajar menggabungkan dua gaya bela diri untuk menghadapi pertarungan penting.",
		 "17:10:00 - 18:40:00", "1 jam 30 menit"},
        {"KARATE KID: LEGENDS","Setelah pindah ke New York, Li Fong berusaha menyesuaikan diri di sekolah barunya. Saat mengikuti kompetisi karate demi membantu temannya, ia menyadari keterampilannya belum cukup. Dengan bimbingan Tn. Han dan Daniel LaRusso, Li belajar menggabungkan dua gaya bela diri untuk menghadapi pertarungan penting.",
		 "19:00:00 - 20:30:00", "1 jam 30 menit"},
        {"MISSION:IMPOSSIBLE - THE FINAL RECKONING","Melanjutkan kisah dari film sebelumnya, Mission: Impossible - Dead Reckoning Part One. Ethan Hunt (Tom Cruise) akan kembali meneruskan misi untuk menghancurkan musuh lama dan musuh baru yang lebih berbahaya.",
		 "20:45:00 - 23:34:00", "2 jam 49 menit"},
        {"LILO & STITCH","Lilo (Maia Kealoha) seorang anak kecil dari Hawaii yang kesepian bertemu dengan Stitch (Chris Sanders), seorang alien yang melarikan diri dari planet asalnya. Keduanya kini berteman dan mencoba memperbaiki kondisi keluarga yang terpecah belah.",
		 "23:45:00 - 01:33:00", "1 jam 48 menit"},
    }, 5},
    {"STUDIO 6", {
        {"KARATE KID: LEGENDS","Setelah pindah ke New York, Li Fong berusaha menyesuaikan diri di sekolah barunya. Saat mengikuti kompetisi karate demi membantu temannya, ia menyadari keterampilannya belum cukup. Dengan bimbingan Tn. Han dan Daniel LaRusso, Li belajar menggabungkan dua gaya bela diri untuk menghadapi pertarungan penting.",
		 "13:30:00 - 15:00:00", "1 jam 30 menit"},
        {"GOWOK KAMASUTRA JAWA","Ratri, anak seorang pelacur yang diasuh oleh Nyai Santi, tumbuh menjadi gadis cantik dan pewaris ilmu gowokan. Ia jatuh cinta pada Kamanjaya, namun dikhianati setelah mereka bercinta. Dua puluh tahun kemudian, mereka bertemu lagi saat putra Kamanjaya, Bagas, datang belajar pada Nyai Santi dan jatuh cinta pada Ratri, tanpa mengetahui masa lalu orang tua mereka. Ratri pun melihat kesempatan untuk membalas dendam.",
		 "15:30:00 - 17:35:00", "2 jam 5 menit"},
        {"LILO & STITCH","Lilo (Maia Kealoha) seorang anak kecil dari Hawaii yang kesepian bertemu dengan Stitch (Chris Sanders), seorang alien yang melarikan diri dari planet asalnya. Keduanya kini berteman dan mencoba memperbaiki kondisi keluarga yang terpecah belah.",
		 "18:00:00 - 19:48:00", "1 jam 48 menit"},
        {"GOWOK KAMASUTRA JAWA","Ratri, anak seorang pelacur yang diasuh oleh Nyai Santi, tumbuh menjadi gadis cantik dan pewaris ilmu gowokan. Ia jatuh cinta pada Kamanjaya, namun dikhianati setelah mereka bercinta. Dua puluh tahun kemudian, mereka bertemu lagi saat putra Kamanjaya, Bagas, datang belajar pada Nyai Santi dan jatuh cinta pada Ratri, tanpa mengetahui masa lalu orang tua mereka. Ratri pun melihat kesempatan untuk membalas dendam.",
		 "20:30:00 - 22:35:00", "2 jam 5 menit"},
        {"GUNDIK","Osman, mantan tentara, merencanakan perampokan bersama timnya, termasuk menantunya, Baim. Namun, mereka terjebak mimpi buruk saat mengetahui target mereka adalah siluman sakti penguasa Pantai Selatan.",
		 "22:50:00 - 00:42:00", "1 jam 52 menit"},
    }, 5},
    {"STUDIO 7", {
        {"LILO & STITCH","Lilo (Maia Kealoha) seorang anak kecil dari Hawaii yang kesepian bertemu dengan Stitch (Chris Sanders), seorang alien yang melarikan diri dari planet asalnya. Keduanya kini berteman dan mencoba memperbaiki kondisi keluarga yang terpecah belah.",
		 "11:00:00 - 12:48:00", "1 jam 48 menit"},
        {"GOWOK KAMASUTRA JAWA","Ratri, anak seorang pelacur yang diasuh oleh Nyai Santi, tumbuh menjadi gadis cantik dan pewaris ilmu gowokan. Ia jatuh cinta pada Kamanjaya, namun dikhianati setelah mereka bercinta. Dua puluh tahun kemudian, mereka bertemu lagi saat putra Kamanjaya, Bagas, datang belajar pada Nyai Santi dan jatuh cinta pada Ratri, tanpa mengetahui masa lalu orang tua mereka. Ratri pun melihat kesempatan untuk membalas dendam.",
		 "13:10:00 - 15:15:00", "2 jam 5 menit"},
        {"KARATE KID: LEGENDS","Setelah pindah ke New York, Li Fong berusaha menyesuaikan diri di sekolah barunya. Saat mengikuti kompetisi karate demi membantu temannya, ia menyadari keterampilannya belum cukup. Dengan bimbingan Tn. Han dan Daniel LaRusso, Li belajar menggabungkan dua gaya bela diri untuk menghadapi pertarungan penting.",
		 "15:20:00 - 16:50:00", "1 jam 30 menit"},
        {"MISSION:IMPOSSIBLE - THE FINAL RECKONING","Melanjutkan kisah dari film sebelumnya, Mission: Impossible - Dead Reckoning Part One. Ethan Hunt (Tom Cruise) akan kembali meneruskan misi untuk menghancurkan musuh lama dan musuh baru yang lebih berbahaya.",
		 "17:40:00 - 20:29:00", "2 jam 49 menit"},
        {"GOWOK KAMASUTRA JAWA UNCUT","Ratri (Alika Jantinia) merupakan anak dari seorang pelacur, tanpa mengetahui siapa ayahnya. Sejak bayi, ia diasuh oleh Nyai Santi (Lola Amaria), seorang gowok yang bijaksana dan disegani.",
		 "20:50:00 - 23:02:00", "2 jam 12 menit"},
    }, 5},
};

void jadwal() {
    struct JadwalGabungan {
        char judul[100];
        char studio[20][20];
        char waktu[20][30];
        char durasi[20][50];  
        int jumlahTayang;
        char sinopsis[1000];
    };

    JadwalGabungan daftarFilm[50];
    int jumlahJudul = 0;

    // Kumpulkan semua film unik dari bioskop (asumsi bioskop sudah didefinisikan)
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < bioskop[i].jumlahFilm; j++) {
            bool ditemukan = false;
            for (int k = 0; k < jumlahJudul; k++) {
                if (strcmp(daftarFilm[k].judul, bioskop[i].jadwal[j].judul) == 0) {
                    strcpy(daftarFilm[k].studio[daftarFilm[k].jumlahTayang], bioskop[i].nama);
                    strcpy(daftarFilm[k].waktu[daftarFilm[k].jumlahTayang], bioskop[i].jadwal[j].waktu);
                    strcpy(daftarFilm[k].durasi[daftarFilm[k].jumlahTayang], bioskop[i].jadwal[j].durasi);
                    daftarFilm[k].jumlahTayang++;
                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan) {
                strcpy(daftarFilm[jumlahJudul].judul, bioskop[i].jadwal[j].judul);
                strcpy(daftarFilm[jumlahJudul].studio[0], bioskop[i].nama);
                strcpy(daftarFilm[jumlahJudul].waktu[0], bioskop[i].jadwal[j].waktu);
                strcpy(daftarFilm[jumlahJudul].durasi[0], bioskop[i].jadwal[j].durasi);
                strcpy(daftarFilm[jumlahJudul].sinopsis, bioskop[i].jadwal[j].sinopsis);
                daftarFilm[jumlahJudul].jumlahTayang = 1;
                jumlahJudul++;
            }
        }
    }

    // Tampilkan jadwal semua film secara statis (langsung semua)
    cout << "======= DAFTAR JADWAL FILM =======\n";
    for (int i = 0; i < jumlahJudul; i++) {
        cout << "\nFilm        : " << daftarFilm[i].judul << endl;
        cout << "Sinopsis    : " << daftarFilm[i].sinopsis << endl;
        cout << "\nJadwal Tayang:\n";
        for (int j = 0; j < daftarFilm[i].jumlahTayang; j++) {
            cout << daftarFilm[i].waktu[j] 
                 << endl;
        }
        cout << "----------------------------------\n";
    }
    system("pause");
}



void pesan_tiket() {
    	struct JadwalGabungan {
    	char judul[100];
    	char studio[20][20];
    	char waktu[20][30];
		char durasi[20][50];  // Tambahan: menyimpan durasi
    	int jumlahTayang;
    	char sinopsis[1000];
	};


    JadwalGabungan daftarFilm[50];
    int jumlahJudul = 0;

    // Kumpulkan semua film unik
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < bioskop[i].jumlahFilm; j++) {
            bool ditemukan = false;
            for (int k = 0; k < jumlahJudul; k++) {
                if (strcmp(daftarFilm[k].judul, bioskop[i].jadwal[j].judul) == 0) {
                    // Tambah jadwal ke yang sudah ada
                    strcpy(daftarFilm[k].studio[daftarFilm[k].jumlahTayang], bioskop[i].nama);
                    strcpy(daftarFilm[k].waktu[daftarFilm[k].jumlahTayang], bioskop[i].jadwal[j].waktu);
                    strcpy(daftarFilm[k].durasi[daftarFilm[k].jumlahTayang], bioskop[i].jadwal[j].durasi);
                    daftarFilm[k].jumlahTayang++;
                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan) {
 					strcpy(daftarFilm[jumlahJudul].judul, bioskop[i].jadwal[j].judul);
				    strcpy(daftarFilm[jumlahJudul].studio[0], bioskop[i].nama);
				    strcpy(daftarFilm[jumlahJudul].waktu[0], bioskop[i].jadwal[j].waktu);
				    strcpy(daftarFilm[jumlahJudul].durasi[0], bioskop[i].jadwal[j].durasi);
				    strcpy(daftarFilm[jumlahJudul].sinopsis, bioskop[i].jadwal[j].sinopsis); // Salin sinopsis
				    daftarFilm[jumlahJudul].jumlahTayang = 1;
				    jumlahJudul++;
			}

        }
    }

    // Tampilkan daftar judul unik
    cout << "======= PILIH FILM =======\n";
    for (int i = 0; i < jumlahJudul; i++) {
        cout << "[" << i + 1 << "] " << daftarFilm[i].judul << endl;
    }

    int pilihanJudul;
    cout << "\nMasukkan nomor film: ";
    cin >> pilihanJudul;
    pilihanJudul--;

    if (pilihanJudul < 0 || pilihanJudul >= jumlahJudul) {
        cout << "Pilihan tidak valid!\n";
        return;
    }
	
	cout << "\nSINOPSIS: " << daftarFilm[pilihanJudul].sinopsis << "\n\n";

	
    // Tampilkan semua jam tayang untuk film tersebut
    cout << "\n======= JAM TAYANG UNTUK '" << daftarFilm[pilihanJudul].judul << "' =======\n";
    for (int i = 0; i < daftarFilm[pilihanJudul].jumlahTayang; i++) {
        cout << "[" << i + 1 << "] " << daftarFilm[pilihanJudul].waktu[i] << endl;
    }

    int pilihanJam;
    cout << "\nMasukkan nomor jam tayang: ";
    cin >> pilihanJam;
    pilihanJam--;

    if (pilihanJam < 0 || pilihanJam >= daftarFilm[pilihanJudul].jumlahTayang) {
        cout << "Pilihan tidak valid!\n";
        return;
    }

    int jumlahTiket;
    cout << "Jumlah tiket: ";
    cin >> jumlahTiket;
    
    

    // Ringkasan tiket
    cout << "\n=========== TIKET ANDA ===========\n";
    cout << "Studio       : " << daftarFilm[pilihanJudul].studio[pilihanJam] << endl;
    cout << "Film         : " << daftarFilm[pilihanJudul].judul << endl;
    cout << "Jam Tayang   : " << daftarFilm[pilihanJudul].waktu[pilihanJam] << endl;
    cout << "Durasi Film  : " << daftarFilm[pilihanJudul].durasi[pilihanJam] << endl;
	cout << "Jumlah Tiket : " << jumlahTiket << endl;
    cout << "==================================\n";
}

void initLayout() {
    ofstream f("layoutkursi.txt");
    if (!f) {
        cout << "Gagal membuat file kursi.\n";
        return;
    }

    for (char baris = 'A'; baris <= 'J'; ++baris) {
        for (int kolom = 1; kolom <= 17; ++kolom) {
            f << baris << kolom << " 0" << endl;
        }
    }

    f.close();
    cout << "[?] layoutkursi.txt dibuat ulang.\n";
}

void tampilLayout() {
    ifstream f("layoutkursi.txt");
    if (!f) {
        cout << "Gagal membuka layoutkursi.txt\n";
        return;
    }

    string kode;
    int status;
    int count = 0;

    cout << "\n=== Layout Kursi ===\n";
    while (f >> kode >> status) {
        if (status == 0)
            cout << "[" << kode << "] ";
        else
            cout << "[XX] ";

        count++;
        if (count % 17 == 0) cout << endl;
    }

    f.close();
}

void pesanKursi(string inputKode) {
    ifstream in("layoutkursi.txt");
    ofstream temp("temp.txt");

    if (!in || !temp) {
        cout << "Gagal membuka file.\n";
        return;
    }

    string kode;
    int status;
    bool ditemukan = false;
    bool sudahDipesan = false;

    while (in >> kode >> status) {
        if (kode == inputKode) {
            if (status == 1) {
                sudahDipesan = true;
            } else {
                temp << kode << " 1\n";  // ubah jadi dipesan
                ditemukan = true;
            }
        } else {
            temp << kode << " " << status << "\n";
        }
    }

    in.close();
    temp.close();

    remove("layoutkursi.txt");
    rename("temp.txt", "layoutkursi.txt");

    if (sudahDipesan) {
        cout << "? Kursi sudah dipesan!\n";
    } else if (ditemukan) {
        ofstream log("datapemesanankursi.txt", ios::app);
        log << "Kursi " << inputKode << " berhasil dipesan.\n";
        log.close();
        cout << "? Pemesanan berhasil.\n";
    } else {
        cout << "? Kursi tidak ditemukan.\n";
    }
}

void lihatPemesanan() {
    ifstream file("datapemesanankursi.txt");
    if (!file) {
        cout << "Belum ada pemesanan.\n";
        return;
    }

    string line;
    cout << "\n=== Riwayat Pemesanan ===\n";
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

int main() {
    system("color 2");
    ifstream cek("layoutkursi.txt");
    if (!cek || cek.peek() == ifstream::traits_type::eof()) {
        initLayout();
    }
    cek.close();

    int pilihan;
   int index_login = -1;  // -1 berarti belum login
   vector<Akun> daftar_akun = bacaAkun();

   do {
       if (index_login == -1) {
           menu_before_login();
           cin >> pilihan;
           switch (pilihan) {
               case 1:
                   registrasi();
                   daftar_akun = bacaAkun();
                   break;
               case 2:
                   index_login = login();
                   daftar_akun = bacaAkun();
                   break;
               case 3:
                   hapusAkun();
                   daftar_akun = bacaAkun();
                   break;
               case 0:
                   cout << "Keluar dari program.\n";
                   break;
               default:
                   cout << "Pilihan tidak valid.\n";
                   break;
           }
       } else {
           menu_after_login();
           cin >> pilihan;
           switch (pilihan) {
               case 1:
                   lihatDataDiri(daftar_akun[index_login]);
                   break;
               case 2:
               	jadwal();
               	break;
               case 3:
                   cout << "Logout berhasil.\n";
                   index_login = -1;
                   break;
               case 0:
                   cout << "Keluar dari program.\n";
                   break;
               case 4:
               	pesan_tiket();
               	break;
               default:
                   cout << "Pilihan tidak valid.\n";
                   break;
           }
       }
   } while (pilihan != 0);
string kode;

    do {
        cout << "\n=== MENU KURSI ===\n";
        cout << "1. Tampilkan Layout\n";
        cout << "2. Pesan Kursi\n";
        cout << "3. Lihat Riwayat Pemesanan\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilLayout();
                break;
            case 2:
            	tampilLayout();
                cout << "\n\nMasukkan kode kursi (misal A2): ";
                cin >> kode;
                pesanKursi(kode);
                break;
            case 3:
                lihatPemesanan();
                break;
            case 0:
                cout << "Keluar.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}
