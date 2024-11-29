#include <stdio.h>
#include <stdlib.h>


struct Mahasiswa {
    char name[50];
    int nim; 
    char prodi[30];
    char citacita[30];
} Mahasiswa;

// Fungsi untuk menambahkan data mahasiswa
void tambahData() {
    FILE *file = fopen("mahasiswa.txt", "a");
    if (!file) {
        printf("Error: File tidak dapat dibuka untuk menulis.\n");
        return;
    }

    struct Mahasiswa m;
    printf("Masukkan Nama: ");
    scanf(" %[^\n]", m.name); 
    printf("Masukkan NIM: ");
    scanf("%d", &m.nim);      
    printf("Masukkan Program Studi: ");
    scanf(" %[^\n]", m.prodi);
    printf("Masukkan Cita-cita: ");
    scanf(" %[^\n]", m.citacita);

    // Menulis data mahasiswa ke dalam file
    fprintf(file, "%s|%d|%s|%s\n", m.name, m.nim, m.prodi, m.citacita);
    fclose(file);
    printf("Data mahasiswa berhasil disimpan!\n");
}

// Fungsi untuk membaca dan menampilkan data mahasiswa
void bacaData() {
    FILE *file = fopen("mahasiswa.txt", "r");
    if (!file) {
        printf("Error: File tidak ditemukan atau tidak dapat dibuka.\n");
        return;
    }

    struct Mahasiswa m;
    printf("\nData Mahasiswa:\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("%-20.20s %-15s %-20s %-50s\n", "Nama", "NIM", "Program Studi", "Cita-cita");
    printf("-------------------------------------------------------------------------------------\n");

    // Membaca data dari file baris demi baris
    while (fscanf(file, " %[^|]|%d|%[^|]|%[^\n]\n", m.name, &m.nim, m.prodi, m.citacita) != EOF) {
        printf("%-20.20s %-15d %-20s %-50s\n", m.name, m.nim, m.prodi, m.citacita);
    }
    printf("-------------------------------------------------------------------------------------\n");
    fclose(file);
}

// Menu utama program
int main() {
    int pilihan;

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Data Mahasiswa\n");
        printf("2. Tampilkan Data Mahasiswa\n");
        printf("3. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                bacaData();
                break;
            case 3:
                printf("Keluar dari program. Babayy!\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi yaa.\n");
        }
    } while (pilihan != 3);

    return 0;
}