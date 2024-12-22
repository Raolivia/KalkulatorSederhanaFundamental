/*
    Programming : Ranalda Olivia
    NIM         : 24343125
    Program     : Kalkulator sederhana
    Mata kuliah : Fundamental Programming
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    char operator;
    double a, b, hasil;

    // membuka file input_1.txt untuk membaca
    inputFile = fopen("input_1.txt", "r");  // Make sure the file exists in the current directory
    if (inputFile == NULL) {
        printf("File input_1.txt tidak dapat dibuka! Pastikan file ada di direktori yang tepat.\n");
        return 1;
    }

    // membuka atau membuat file output_1.txt untuk menulis
    outputFile = fopen("output_1.txt", "w");  // Output will be saved in the current directory
    if (outputFile == NULL) {
        printf("File output_1.txt tidak dapat dibuka! Pastikan Anda memiliki izin untuk menulis di direktori.\n");
        fclose(inputFile);
        return 1;
    }

    // Membaca data dari input file dan melakukan perhitungan
    while (fscanf(inputFile, "%lf %c %lf", &a, &operator, &b) != EOF) {
        // Menggunakan switch untuk memilih operasi berdasarkan operator
        switch (operator) {
            case '+':
                hasil = a + b;
                break;
            case '-':
                hasil = a - b;
                break;
            case '*':
                hasil = a * b;
                break;
            case '/':
                if (b != 0) {
                    hasil = a / b;
                } else {
                    fprintf(outputFile, "Error: Pembagian dengan nol tidak diperbolehkan.\n");
                    continue;  // Skip the current iteration if division by zero
                }
                break;
            default:
                fprintf(outputFile, "Error: Operator '%c' tidak valid.\n", operator);
                continue;  // Skip the current iteration if the operator is invalid
        }

        // Menulis hasil ke file output_1.txt
        fprintf(outputFile, "Hasil dari %.4f %c %.4f adalah: %.4f\n", a, operator, b, hasil);
    }

    // Menutup file
    fclose(inputFile);
    fclose(outputFile);

    printf("Proses selesai. Hasil telah disimpan di output_1.txt.\n");

    return 0;
}
