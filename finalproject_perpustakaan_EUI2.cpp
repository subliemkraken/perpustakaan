#include <iostream>
#include <string>
#include <cstring> p

using namespace std;

void menu_utama();
void daftar_buku();
void list_anggota();
void pinjam_buku();
void setor_buku();
void reg_anggota();
void cek_anggota();

string input_id, pilihan; 
char password[10], username[10];// login admin
int pilih_pinjam, jumlah, urutan, i, opsi;// memasukkan input pilihan

struct kartu_anggota // Mendaftarkan anggota baru lalu menampilkannya.
{
    string nama_anggota;
    string id_anggota;  
    int jumlah_anggota;
};
kartu_anggota data[100], jml_anggota;

struct data_peminjaman // Menghitung jumlah peminjaman buku dan pengembalian buku
{
    int jumlah_pinjam;
    int jumlah_kembali;
};
data_peminjaman juml[100];

struct data_buku // Menampilkan nama dan kode buku yang nantinya akan dipinjam
{
    string nama_buku;
    string id_buku;
};
data_buku buku[100];

void menu_utama() // Tampilan awal saat user masuk ke program
{
    system("cls");
    cout << "~~~~~~~~~~~~~~~~~~~oOo~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "| Selamat Datang di Perpustakaan Gulag! |" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\n1. Daftar Buku" << endl;
    cout << "2. Daftar Anggota Perpustakaan (Administrator)" << endl;
    cout << "3. Peminjaman Buku" << endl;
    cout << "4. Pengembalian Buku" << endl;
    cout << "5. Registrasi Anggota Perpustakaan" << endl;
    cout << "6. Cek Anggota dan Jumlah Buku yang Dipinjam" << endl;
    cout << "0. Keluar\n" << endl;
    cout << "Input: ";
    cin >> opsi;

    switch (opsi)
    {
        case 1:
            daftar_buku();
            break;
        case 2:
            list_anggota();
            break;
        case 3:
            pinjam_buku();
            break;
        case 4:
            setor_buku();
            break;
        case 5:
            reg_anggota();
            break;
        case 6:
            cek_anggota();
            break;
        case 0:
            cout << "Terima kasih telah menggunakan aplikasi kami." << endl;
            exit(0);
        default:
            cout << "Invalid input. Kembali ke menu utama" << endl;
            system("pause");
            menu_utama();
    }
}

void daftar_buku() // Untuk menampilkan nama dan kode buku
{
    system("cls");
    cout << "List buku yang terdapat di perpustakaan:\n" << endl;
    for (urutan = 0; urutan <= 7; urutan++) {
        cout << urutan + 1 << ". " << buku[urutan].nama_buku << endl;
        cout << "   Kode Buku: " << buku[urutan].id_buku << endl;
    }
    cout << "\nIngin meminjam buku? (y/n): ";
    cin >> pilihan;
    if (pilihan == "y" || pilihan == "Y")
    {
        pinjam_buku();
    }
    else if (pilihan == "n" || pilihan == "N")
    {
        cout << "Kembali ke menu utama" << endl;
        system("pause");
        menu_utama();
    }
}

void reg_anggota() // Untuk registrasi atau mendaftarkan anggota baru
{
    system("cls");
    jumlah += 0;
    jml_anggota.jumlah_anggota += 0;
    cout << "Registrasi Anggota Perpustakaan Gulag\n" << endl;
    cout << "Masukkan nama: ";
    cin >> data[jumlah].nama_anggota;
    cout << "Masukkan id: ";
    cin >> data[jumlah].id_anggota;
    jml_anggota.jumlah_anggota++;
    jumlah++;
    cout << "Registrasi telah selesai. Kembali ke menu utama? (y/n (jika ingin tambah anggota) ): ";
    cin >> pilihan;
    if (pilihan == "y" || pilihan == "Y")
    {
        cout << "\nKembali ke menu utama" << endl;
        system("pause");
        menu_utama();
    }
    else if (pilihan == "n" || pilihan == "N")
    {
        reg_anggota();
    }
}

void cek_anggota() // Mengecek anggota perpustakaan pribadi
{
    system("cls");

    cout << "Masukkan id: "; cin >> input_id;
    for (i = 0; i < jml_anggota.jumlah_anggota; i++)
    {
        if(input_id == data[i].id_anggota)
        {
            system("cls");
            cout << "==== Kartu Anggota Perpustakaan Gulag ====\n" << endl;
            cout << "Nama                      : " << data[i].nama_anggota << endl;
            cout << "Id                        : " << data[i].id_anggota << endl;
            cout << "Jumlah buku yang dipinjam : " << juml[i].jumlah_pinjam << endl;
            cout << "\n==========================================\n" << endl;
            cout << "\nIngin meminjam buku? (y/n): "; cin >> pilihan;
            if (pilihan == "y" || pilihan == "Y")
            {
                pinjam_buku();
            } 
            else if (pilihan == "n" || pilihan == "N") {
                cout << "\nKembali ke menu utama" << endl;
                system("pause");
                menu_utama();
            }
        }
    }
    cout << "Id tidak terdaftar. \n1. Masukkan id yang sesuai dengan kartu anggota anda\n2. Mendaftar sebagai anggota perpustakaan \n0. Kembali ke menu utama\n\nPilihan: ";
    cin >> opsi;
    if (opsi == 1) {
        system("pause");
        cek_anggota();
    }
    else if (opsi == 2) {
        cout << "\n\nKe proses pendaftaran." << endl;
        system ("pause");
        reg_anggota();
    }
    else if (opsi == 0) {
        cout << "Kembali ke menu utama.\n" << endl;
        system("pause");
        menu_utama();
    }
}

void list_anggota() // Ibarat seperti menjadi administrator, nantinya akan menampilkan keseluruhan data anggota serta jumlah buku yang dipinjam
{
    jml_anggota.jumlah_anggota += 0;
    juml[100].jumlah_pinjam += 0;
    system("cls");
    cout << "Silahkan masukkan username dan password.\n" << endl;
    cout << "Username: "; cin >> username;
    cout << "Password: "; cin >> password;
    if (strcmp(password, "12345") == 0 && strcmp(username, "admin") == 0) {
        if (jml_anggota.jumlah_anggota != 0)
        {
            system("cls");
            cout << "Daftar Anggota Perpustakaan Gulag\n\n";
            cout << "Jumlah anggota: " << jumlah << endl << endl;
            for (i = 0; i < jumlah; i++)
            {
                cout << i + 1 << ". " << "Nama: " << data[i].nama_anggota << endl;
                cout << "   Id: " << data[i].id_anggota << endl;
                cout << "   Jumlah buku yang dipinjam: " << juml[i].jumlah_pinjam << endl << endl;
            }
        } else {
            cout << "\nBelum ada anggota." << endl;
            cout << "Kembali ke menu utama\n";
            system("pause");
            menu_utama();
        }
        cout << "\nKembali ke menu utama\n";
        system("pause");
        menu_utama();
    } else {
        cout << "Password atau username salah.\n\n1. Login kembali\n2. Kembali ke menu utama\n\nPilihan : ";
        cin >> opsi;
        
        if (opsi == 1){
            system ("pause");
            list_anggota();
        }
        else if (opsi == 2){
            system ("pause");
            menu_utama();
        }   
    }
}

void pinjam_buku() { // Untuk proses meminjam buku

    system("cls");
    juml[100].jumlah_pinjam += 0;
    i = 0;
    cout << "Masukkan id: ";
    cin >> input_id;
    for (i = 0; i < jml_anggota.jumlah_anggota; i++) {
        if (input_id == data[i].id_anggota) {
            system("cls");
            cout << "Selamat datang, " << data[i].nama_anggota << "! Berikut adalah daftar buku yang tersedia: \n" << endl;
            for (urutan = 0; urutan <= 7; urutan++) {
                cout << urutan + 1 << ". " << buku[urutan].nama_buku << endl;
                cout << "   Kode Buku: " << buku[urutan].id_buku << endl;
            }
            cout << "\nSilakan pilih buku yang akan anda pinjam: "; cin >> pilih_pinjam;
            switch (pilih_pinjam) {
                case 1:
                    cout << "\nAnda memilih buku berjudul: " << buku[pilih_pinjam-1].nama_buku << "\nDengan kode buku: " << buku[pilih_pinjam-1].id_buku << endl;
                    juml[i].jumlah_pinjam++;
                    break;
                case 2:
                    cout << "\nAnda memilih buku berjudul: " << buku[pilih_pinjam-1].nama_buku << "\nDengan kode buku: " << buku[pilih_pinjam-1].id_buku << endl;
                    juml[i].jumlah_pinjam++;
                    break;
                case 3:
                    cout << "\nAnda memilih buku berjudul: " << buku[pilih_pinjam-1].nama_buku << "\nDengan kode buku: " << buku[pilih_pinjam-1].id_buku << endl;
                    juml[i].jumlah_pinjam++;
                    break;
                case 4:
                    cout << "\nAnda memilih buku berjudul: " << buku[pilih_pinjam-1].nama_buku << "\nDengan kode buku: " << buku[pilih_pinjam-1].id_buku << endl;
                    juml[i].jumlah_pinjam++;
                    break;
                case 5:
                    cout << "\nAnda memilih buku berjudul: " << buku[pilih_pinjam-1].nama_buku << "\nDengan kode buku: " << buku[pilih_pinjam-1].id_buku << endl;
                    juml[i].jumlah_pinjam++;
                    break;
                case 6:
                    cout << "\nAnda memilih buku berjudul: " << buku[pilih_pinjam-1].nama_buku << "\nDengan kode buku: " << buku[pilih_pinjam-1].id_buku << endl;
                    juml[i].jumlah_pinjam++;
                    break;
                case 7:
                    cout << "\nAnda memilih buku berjudul: " << buku[pilih_pinjam-1].nama_buku << "\nDengan kode buku: " << buku[pilih_pinjam-1].id_buku << endl;
                    juml[i].jumlah_pinjam++;
                    break;
                case 8:
                    cout << "\nAnda memilih buku berjudul: " << buku[pilih_pinjam-1].nama_buku << "\nDengan kode buku: " << buku[pilih_pinjam-1].id_buku << endl;
                    juml[i].jumlah_pinjam++;
                    break;
                default:
                    cout << "Error input." << endl;
                    system("pause");
                    menu_utama();
            }
            cout << "\nProses peminjaman buku telah berhasil.";
            cout << "\n\nKembali ke menu utama" << endl;
            system("pause");
            menu_utama();   
        }
    }
    cout << "Id tidak terdaftar. \n1. Masukkan id yang sesuai dengan kartu anggota anda \n2. Kembali ke menu utama\n\nPilihan: ";
    cin >> opsi;
    if (opsi == 1) {
        system("pause");
        pinjam_buku();
    }
    else if (opsi == 2) {
        cout << "Kembali ke menu utama\n" << endl;
        system("pause");
        menu_utama();
    }
}

void setor_buku() { // Untuk proses mengembalikan buku

    system("cls");
    cout << "Masukkan id: ";
    cin >> input_id;
    for (i = 0; i < jml_anggota.jumlah_anggota; i++) {
        if (input_id == data[i].id_anggota) {
            if(juml[i].jumlah_pinjam != 0) {
                system("cls");
                cout << data[i].nama_anggota << " : " << data[i].id_anggota;
                cout << "\nJumlah buku yang dipinjam : " << juml[i].jumlah_pinjam;
                cout << "\n\nBerapa banyak buku yang akan dikembalikan? (0 jika tidak jadi mengembalikan buku): "; cin >> juml[i].jumlah_kembali;
                juml[i].jumlah_pinjam -= juml[i].jumlah_kembali;

                while (juml[i].jumlah_pinjam < 0) // Peringatan jika buku yang akan dikembalikan melebihi buku yang dipinjam
                {
                    cout << "\nJumlah buku yang dikembalikan melebihi jumlah buku yang dipinjam." << endl;
                    juml[i].jumlah_pinjam += juml[i].jumlah_kembali; 
                    cout << "\nMasukkan ulang jumlah buku yang akan dikembalikan: "; cin >> juml[i].jumlah_kembali;
                    juml[i].jumlah_pinjam -= juml[i].jumlah_kembali;
                    system("cls");
                }

                cout << "\nProses pengembalian buku telah berhasil." << endl;
                cout << "\nKembali ke menu utama" << endl;
                system("pause");
                menu_utama();
            } else {
                system("cls");
                cout << data[i].nama_anggota << " : " << data[i].id_anggota;
                cout << "\nJumlah buku yang dipinjam : " << juml[i].jumlah_pinjam;
                cout << "\n\nAnda belum meminjam buku sama sekali. Ingin meminjam buku? (y/n): "; cin >> pilihan;
                if (pilihan == "y" || pilihan == "Y")
                {
                    system("cls");
                    pinjam_buku();
                }
                else if (pilihan == "n" || pilihan == "N")
                {
                    cout << "Kembali ke menu utama\n";
                    system("pause");
                    menu_utama();
                }
            }
        }
    }
    cout << "Id tidak terdaftar. \n1. Masukkan id yang sesuai dengan kartu anggota anda \n2. Kembali ke menu utama\n\nPilihan : ";
    cin >> opsi;
    if (opsi == 1) {
        system("pause");
        setor_buku();
    }
    else if (opsi == 2) {
        cout << "Kembali ke menu utama\n" << endl;
        system("pause");
        menu_utama();
    }
}

int main() {

    buku[0].nama_buku = "Algoritma dan Pemrograman Bahasa C/C++";           buku[0].id_buku = "AP-215";
    buku[1].nama_buku = "Buku Panduan Pembelajaran MySQL";                  buku[1].id_buku = "BD-721";
    buku[2].nama_buku = "Dasar-Dasar Logika Matematika";                    buku[2].id_buku = "MD-349";
    buku[3].nama_buku = "Gerbang Logika Beserta Penerapannya";              buku[3].id_buku = "SD-105";
    buku[4].nama_buku = "Matriks dan Vektor Beserta Penerapannya";          buku[4].id_buku = "AL-458";
    buku[5].nama_buku = "Ideologi dan Konstitusi: Edisi Pancasila";         buku[5].id_buku = "PK-566";
    buku[6].nama_buku = "Pembuktian Keberadaan Tuhan Dengan Sains Modern";  buku[6].id_buku = "PA-612";
    buku[7].nama_buku = "Sistem Teknologi dan Informasi";                   buku[7].id_buku = "ST-814";

    system("cls");
    menu_utama();
    return 0;
}
