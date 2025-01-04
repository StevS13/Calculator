#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 10

void clrscr(){
	#ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

typedef struct {
    char calculation[256];
} History;

void addToHistory(const char *entry){
    FILE *file;
	file = fopen("HISTORY_FILE.txt", "a");
    if (file) {
        fprintf(file, "%s\n", entry);
        fclose(file);
    } else {
        puts("Error: Unable to open history file.");
    }
}

void viewHistory(){
    FILE *file = fopen("HISTORY_FILE.txt", "r");
    if (!file) {
        puts("No history available.");
        return;
    }

    char buffer[256];
    puts("--- History ---");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

void searchHistory(const char *keyword){
    FILE *file = fopen("HISTORY_FILE.txt", "r");
    if (!file) {
        puts("No history available.");
        return;
    }

    char buffer[256];
    int found = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, keyword)) {
            printf("%s", buffer);
            found = 1;
        }
    }
    fclose(file);

    if (!found) {
        puts("No matching entries found.");
    }
}

void historyMenuEng(){
    int choice;
    char keyword[256];

    while (1) {
        puts("History Menu");
        puts("1. View History");
        puts("2. Search History");
        puts("0. Back");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            clrscr();
            viewHistory();
            break;
        case 2:
            clrscr();
            printf("Enter keyword to search: ");
            fgets(keyword, sizeof(keyword), stdin);
            keyword[strcspn(keyword, "\n")] = 0;
            searchHistory(keyword);
            break;
        case 0:
            clrscr();
            return;
        default:
            puts("Invalid choice.");
        }
    }
}

void historyMenuInd(){
    int choice;
    char keyword[256];

    while (1) {
        puts("Menu Riwayat");
        puts("1. Lihat Riwayat");
        puts("2. Cari Riwayat");
        puts("0. Kembali");
        printf("Pilih opsi: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            clrscr();
            viewHistory();
            break;
        case 2:
            clrscr();
            printf("Masukkan kata kunci untuk mencari: ");
            fgets(keyword, sizeof(keyword), stdin);
            keyword[strcspn(keyword, "\n")] = 0;
            searchHistory(keyword);
            break;
        case 0:
            clrscr();
            return;
        default:
            puts("Pilihan tidak valid.");
        }
    }
}

void scalarInd(){
	int scalarChoice;
	double x, y, result;
	char cont;
	char log[256];
	
	clrscr();
	while (1) { // Scalar Menu
    	puts("Kalkulator Skalar");
    	puts("=========================");
    	puts("1. Penjumlahan");
    	puts("2. Pengurangan");
    	puts("3. Perkalian");
    	puts("4. Pembagian");
  		puts("5. Persentase");
    	puts("6. Pangkat");
    	puts("7. Akar");
    	puts("0. Kembali");
    	puts("Pilih opsi (0-7)");
    	puts("Catatan: Semua hasil akan dibulatkan hingga 2 desimal");
    	printf(">>> ");
    	scanf("%d", &scalarChoice);
    	getchar();

    	switch (scalarChoice) {
        	case 0: // kembali ke menu utama
        		clrscr();
            	return;

        	case 1: // Penjumlahan
            	clrscr();
            	do {
                	puts("Masukkan dua angka untuk dijumlahkan:");
                	printf("Angka Pertama = ");
                	scanf("%lf", &x);
                	printf("Angka Kedua = ");
                	scanf("%lf", &y);
                	printf("Hasil: %.2f + %.2f = %.2f\n", x, y, x + y);
                	
					snprintf(log, sizeof(log), "%.2f + %.2f = %.2f", x, y, x+y);
					addToHistory(log);
                	puts("Apakah Anda ingin menghitung lagi untuk Penjumlahan? [Y/N]");
                	getchar();
                	scanf("%c", &cont);
            	} while (cont == 'Y' || cont == 'y');
            	clrscr();
            	break;

        	case 2: // Pengurangan
            	clrscr();
            	do {
                	puts("Masukkan dua angka untuk dikurangkan:");
                	printf("Angka = ");
                	scanf("%lf", &x);
                	printf("Dikurangi dengan = ");
                	scanf("%lf", &y);
                	printf("Hasil: %.2f - %.2f = %.2f\n", x, y, x - y);
                	snprintf(log, sizeof(log), "%.2f - %.2f = %.2f", x, y, x-y);
					addToHistory(log);
                	puts("Apakah Anda ingin menghitung lagi untuk Pengurangan? [Y/N]");
                	getchar();
                	scanf("%c", &cont);
            	} while (cont == 'Y' || cont == 'y');
            	clrscr();
            	break;

        	case 3: // Perkalian
            	clrscr();
            	do {
                	puts("Masukkan dua angka untuk dikalikan:");
                	printf("Angka Pertama = ");
                	scanf("%lf", &x);
                	printf("Angka Kedua = ");
                	scanf("%lf", &y);
                	printf("Hasil: %.2f * %.2f = %.2f\n", x, y, x * y);
                	snprintf(log, sizeof(log), "%.2f * %.2f = %.2f", x, y, x*y);
					addToHistory(log);
                	puts("Apakah Anda ingin menghitung lagi untuk Perkalian? [Y/N]");
                	getchar();
                	scanf("%c", &cont);
            	} while (cont == 'Y' || cont == 'y');
            	clrscr();
            	break;

        	case 4: // Pembagian
            	clrscr();
            	do {
                	puts("Masukkan dua angka untuk dibagi:");
                	printf("Angka = ");
                	scanf("%lf", &x);
                	printf("Dibagi dengan = ");
                	scanf("%lf", &y);
                	if (y == 0) {
                    	puts("Error: Pembagian dengan nol tidak diperbolehkan.");
                	} else {
                    	printf("Hasil: %.2f / %.2f = %.2f\n", x, y, x / y);
                	}
                	if (y != 0) {
    					snprintf(log, sizeof(log), "%.2f / %.2f = %.2f", x, y, x/y);
					    addToHistory(log);
					} else {
					    snprintf(log, sizeof(log), "%.2f dibagi 0", x);
					    addToHistory(log);
					}
                	puts("Apakah Anda ingin menghitung lagi untuk Pembagian? [Y/N]");
                	getchar();
                	scanf("%c", &cont);
            	} while (cont == 'Y' || cont == 'y');
            	clrscr();
            	break;

        	case 5: // Persentase
            	clrscr();
            	do {
                	puts("Masukkan total dan persentase untuk dihitung:");
                	printf("Angka = ");
                	scanf("%lf", &x);
                	printf("Persentase (tanpa simbol '%') = ");
                	scanf("%lf", &y);
                	result = (x * y) / 100.0;
                	printf("Hasil: %.2f%% dari %.2f = %.2f\n", y, x, result);
                	snprintf(log, sizeof(log), "%.2f%% dari %.2f = %.2f", y, x, result);
					addToHistory(log);
                	puts("Apakah Anda ingin menghitung lagi untuk Persentase? [Y/N]");
                	getchar();
                	scanf("%c", &cont);
            	} while (cont == 'Y' || cont == 'y');
            	clrscr();
            	break;

        	case 6: // Pangkat
            	clrscr();
            	do {
                	puts("Masukkan angka dasar dan eksponen:");
                	printf("Angka = ");
                	scanf("%lf", &x);
                	printf("Pangkatkan dengan = ");
                	scanf("%lf", &y);
                	result = pow(x, y);
                	printf("Hasil: %.2f ^ %.2f = %.2f\n", x, y, result);
                	snprintf(log, sizeof(log), "%.2f ^ %.2f = %.2f", x, y, result);
					addToHistory(log);
                	puts("Apakah Anda ingin menghitung lagi untuk Pangkat? [Y/N]");
                	getchar();
                	scanf("%c", &cont);
            	} while (cont == 'Y' || cont == 'y');
            	clrscr();
            	break;

        	case 7: // Akar
            	clrscr();
            	do {
                	puts("Masukkan angka dan akar yang akan dihitung:");
                	printf("Angka = ");
                	scanf("%lf", &x);
                	printf("Akar ke- = ");
                	scanf("%lf", &y);
                	if (x < 0 && ((int)y % 2 == 0)) {
                    	puts("Error: Tidak dapat menghitung akar genap dari angka negatif.");
                	} else {
                    	result = pow(x, 1 / y);
                    	printf("Hasil: Akar %.2f dari %.2f = %.2f\n", y, x, result);
                	}
                	if (x >= 0 || ((int)y % 2 != 0)) {
					    snprintf(log, sizeof(log), "Akar %.2f dari %.2f = %.2f", y, x, result);
					    addToHistory(log);
					} else {
					    snprintf(log, sizeof(log), "Tidak dapat menghitung akar %.2f dari %.2f", y, x);
					    addToHistory(log);
					}
                	puts("Apakah Anda ingin menghitung lagi untuk Akar? [Y/N]");
                	getchar();
                	scanf("%c", &cont);
            	} while (cont == 'Y' || cont == 'y');
            	clrscr();
            	break;

        	default: // Invalid
            	clrscr();
            	puts("Input tidak valid. Silakan pilih opsi yang valid.");
            	break;
    	}
	}
}

void scalarEng(){ 
	int scalarChoice;
	double x, y, result;
	char cont;
	char log[256];
	
	while (1){ // Scalar Menu
		puts("Scalar Calculators");
        puts("=========================");
        puts("1. Addition");
        puts("2. Subtraction");
        puts("3. Multiplication");
        puts("4. Division");
        puts("5. Percentage");
        puts("6. Power");        
        puts("7. Root"); 
        puts("0. Kembali");
        puts("Select an option (0-7)");
        puts("note : all the result will rounded to 2 decimals");
        printf(">>> ");
        scanf("%d", &scalarChoice);
        getchar();
		
		switch (scalarChoice) {
            case 0: // back to main menu
                clrscr();
				return;

            case 1: // Addition
            	clrscr();
                do {
                    puts("Enter two numbers to add:");
                    printf("First Number = ");
                    scanf("%lf", &x);
                    printf("Second Number = ");
                    scanf("%lf", &y);
                    printf("Result: %.2f + %.2f = %.2f\n", x, y, x+y);
                    snprintf(log, sizeof(log), "%.2f + %.2f = %.2f", x, y, x+y);
					addToHistory(log);
                    puts("Do you want to calculate again in Addition? [Y/N]");
                    getchar();
                    scanf("%c", &cont);
                } while (cont == 'Y' || cont == 'y');
                clrscr();
                break;

            case 2: // Subtraction
            	clrscr();
                do {
                    puts("Enter two numbers to subtract:");
                    printf("Number = ");
                    scanf("%lf", &x);
                    printf("Subtract by = ");
                    scanf("%lf", &y);
                    printf("Result: %.2f - %.2f = %.2f\n", x, y, x-y);
                    snprintf(log, sizeof(log), "%.2f - %.2f = %.2f", x, y, x-y);
					addToHistory(log);
                    puts("Do you want to calculate again in Subtraction? [Y/N]");
                    getchar();
                    scanf("%c", &cont);
                } while (cont == 'Y' || cont == 'y');
                clrscr();
                break;

            case 3: // Multiplication
            	clrscr();
                do {
                    puts("Enter two numbers to multiply:");
                    printf("First Number = ");
                    scanf("%lf", &x);
                    printf("Second Number = ");
                    scanf("%lf", &y);
                    printf("Result: %.2f * %.2f = %.2f\n", x, y, x*y);
                    snprintf(log, sizeof(log), "%.2f * %.2f = %.2f", x, y, x*y);
					addToHistory(log);
                    puts("Do you want to calculate again in Multiplication? [Y/N]");
                    getchar();
                    scanf("%c", &cont);
                } while (cont == 'Y' || cont == 'y');
                clrscr();
                break;

            case 4: // Division
            	clrscr();
                do {
                    puts("Enter two numbers to divide:");
                    printf("Number = ");
                    scanf("%lf", &x);
                    printf("Divided by = ");
                    scanf("%lf", &y);
                    if (y == 0) {
                        puts("Error: Division by zero is not allowed.");
                    } else {
                        printf("Result: %.2f / %.2f = %.2f\n", x, y, x/y);
                    }
                    if (y != 0) {
    					snprintf(log, sizeof(log), "%.2f / %.2f = %.2f", x, y, x/y);
					    addToHistory(log);
					} else {
					    snprintf(log, sizeof(log), "%.2f divided by 0", x);
					    addToHistory(log);
					}
                    puts("Do you want to calculate again in Division? [Y/N]");
                    getchar();
                    scanf("%c", &cont);
                } while (cont == 'Y' || cont == 'y');
                clrscr();
                break;

            case 5: // Percentage
            	clrscr();
                do {
                    puts("Enter the total and the percentage to calculate:");
                    printf("Number = ");
                    scanf("%lf", &x);
                    printf("Persentage (do not use '%') = ");
                    scanf("%lf", &y);
                    result = (x * y) / 100.0;
                    printf("Result: %.2f%% of %.2f = %.2f\n", y, x, result);
                    snprintf(log, sizeof(log), "%.2f%% of %.2f = %.2f", y, x, result);
					addToHistory(log);
                    puts("Do you want to calculate again in Percentage? [Y/N]");
                    getchar();
                    scanf("%c", &cont);
                } while (cont == 'Y' || cont == 'y');
                clrscr();
                break;

            case 6: // Power
            	clrscr();
                do {
                    puts("Enter the base and the exponent:");
                    printf("Number = ");
                    scanf("%lf", &x);
                    printf("Power by = ");
                    scanf("%lf", &y);
                    result = pow(x, y);
                    printf("Result: %.2f ^ %.2f = %.2f\n", x, y, result);
                    snprintf(log, sizeof(log), "%.2f ^ %.2f = %.2f", x, y, result);
					addToHistory(log);
                    puts("Do you want to calculate again in Power? [Y/N]");
                    getchar();
                    scanf("%c", &cont);
                } while (cont == 'Y' || cont == 'y');
                clrscr();
                break;

            case 7: // Root
            	clrscr();
                do {
                    puts("Enter the number and the root to calculate:");
                    printf("Number = ");
                    scanf("%lf", &x);
                    printf("Root by = ");
                    scanf("%lf", &y);
                    if (x < 0 && ((int)y % 2 == 0)) {
                        puts("Error: Cannot calculate even root of a negative number.");
                    } else {
                        result = pow(x, 1 / y);
                        printf("Result: %.2f root of %.2f = %.2f\n", y, x, result);
                    }
                    if (x >= 0 || ((int)y % 2 != 0)) {
					    snprintf(log, sizeof(log), "Root %.2f of %.2f = %.2f", y, x, result);
					    addToHistory(log);
					} else {
					    snprintf(log, sizeof(log), "Cannot calculate root %.2f of %.2f", y, x);
					    addToHistory(log);
					}
                    puts("Do you want to calculate again in Root? [Y/N]");
                    getchar();
                    scanf("%c", &cont);
                } while (cont == 'Y' || cont == 'y');
                clrscr();
                break;

            default: // Invalid
            	clrscr();
                puts("Invalid Input. Please select a valid option.");
                break;
        }
	} 
}

void matrixInd(){
	int matrixChoice, rows1, cols1, rows2, cols2, i, j, k;
    double mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX], scalar;
    char cont;

    while (1) {
        puts("Kalkulator Matriks");
        puts("=========================");
        puts("1. Penjumlahan");
        puts("2. Pengurangan");
        puts("3. Perkalian");
        puts("4. Perkalian dengan Skalar");
        puts("0. Kembali");
        printf("Pilih opsi (0-4): ");
        puts("Catatan: Semua hasil akan dibulatkan hingga 2 desimal.");
        scanf("%d", &matrixChoice);

        switch (matrixChoice) {
            case 0:
                clrscr();
                return;

            case 1: // Penjumlahan
                clrscr();
                do {
                    puts("Penjumlahan Matriks");
                    printf("Masukkan jumlah baris dan kolom [baris] [kolom]: ");
                    scanf("%d %d", &rows1, &cols1);
                    puts("Masukkan elemen-elemen matriks pertama:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("Masukkan elemen pada posisi [%d][%d]: ", i + 1, j + 1);
                            scanf("%lf", &mat1[i][j]);
                        }
                    }
                    puts("Masukkan elemen-elemen matriks kedua:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("Masukkan elemen pada posisi [%d][%d]: ", i + 1, j + 1);
                            scanf("%lf", &mat2[i][j]);
                        }
                    }
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            result[i][j] = mat1[i][j] + mat2[i][j];
                        }
                    }
                    puts("Hasil Matriks:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("%.2f\t", result[i][j]);
                        }
                        printf("\n");
                    }
                    puts("Apakah Anda ingin melakukan penjumlahan lagi? [Y/T]");
                    getchar();
                    scanf("%c", &cont);
                } while (cont == 'Y' || cont == 'y');
                clrscr();
                break;

            case 2: // Pengurangan
                clrscr();
                do {
                    puts("Pengurangan Matriks");
                    printf("Masukkan jumlah baris dan kolom [baris] [kolom]: ");
                    scanf("%d %d", &rows1, &cols1);
                    puts("Masukkan elemen-elemen matriks pertama:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("Masukkan elemen pada posisi [%d][%d]: ", i + 1, j + 1);
                            scanf("%lf", &mat1[i][j]);
                        }
                    }
                    puts("Masukkan elemen-elemen matriks kedua:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("Masukkan elemen pada posisi [%d][%d]: ", i + 1, j + 1);
                            scanf("%lf", &mat2[i][j]);
                        }
                    }
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            result[i][j] = mat1[i][j] - mat2[i][j];
                        }
                    }
                    puts("Hasil Matriks:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("%.2f\t", result[i][j]);
                        }
                        printf("\n");
                    }
                    puts("Apakah Anda ingin melakukan pengurangan lagi? [Y/T]");
                    getchar();
                    scanf("%c", &cont);
                } while (cont == 'Y' || cont == 'y');
                clrscr();
                break;

            case 3: // Perkalian
                clrscr();
                do {
                    puts("Perkalian Matriks");
                    printf("Masukkan jumlah baris dan kolom untuk matriks pertama [baris] [kolom]: ");
                    scanf("%d %d", &rows1, &cols1);
                    puts("Masukkan elemen-elemen matriks pertama:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("Masukkan elemen pada posisi [%d][%d]: ", i + 1, j + 1);
                            scanf("%lf", &mat1[i][j]);
                        }
                    }
                    printf("Masukkan jumlah baris dan kolom untuk matriks kedua [baris] [kolom]: ");
                    scanf("%d %d", &rows2, &cols2);

                    if (cols1 != rows2) {
                        puts("Kesalahan: Jumlah kolom pada matriks pertama harus sama dengan jumlah baris pada matriks kedua.");
                        break;
                    }

                    puts("Masukkan elemen-elemen matriks kedua:");
                    for (i = 0; i < rows2; i++) {
                        for (j = 0; j < cols2; j++) {
                            printf("Masukkan elemen pada posisi [%d][%d]: ", i + 1, j + 1);
                            scanf("%lf", &mat2[i][j]);
                        }
                    }
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols2; j++) {
                            result[i][j] = 0;
                            for (k = 0; k < cols1; k++) {
                                result[i][j] += mat1[i][k] * mat2[k][j];
                            }
                        }
                    }
                    puts("Hasil Matriks:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols2; j++) {
                            printf("%.2f\t", result[i][j]);
                        }
                        printf("\n");
                    }
                    puts("Apakah Anda ingin melakukan perkalian lagi? [Y/T]");
                    getchar();
                    scanf("%c", &cont);
                } while (cont == 'Y' || cont == 'y');
                clrscr();
                break;

            case 4: // Perkalian dengan Skalar
                clrscr();
                do {
                    puts("Perkalian Matriks dengan Skalar");
                    printf("Masukkan jumlah baris dan kolom [baris] [kolom]: ");
                    scanf("%d %d", &rows1, &cols1);
                    puts("Masukkan elemen-elemen matriks:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("Masukkan elemen pada posisi [%d][%d]: ", i + 1, j + 1);
                            scanf("%lf", &mat1[i][j]);
                        }
                    }
                    printf("Masukkan nilai skalar untuk dikalikan: ");
                    scanf("%lf", &scalar);
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            result[i][j] = mat1[i][j] * scalar;
                        }
                    }
                    puts("Hasil Matriks:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("%.2f\t", result[i][j]);
                        }
                        printf("\n");
                    }
                    puts("Apakah Anda ingin melakukan perkalian dengan skalar lagi? [Y/T]");
                    getchar();
                    scanf("%c", &cont);
                } while (cont == 'Y' || cont == 'y');
                clrscr();
                break;

            default:
                clrscr();
                puts("Input tidak valid. Silakan pilih opsi yang benar.");
                break;
        }
    }
	
}

void matrixEng(){
	int matrixChoice, rows1, cols1, rows2, cols2, i, j, k;
    double mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX], scalar;
    char cont;
	clrscr();
    while (1) {
        puts("Matrix Calculator");
        puts("=========================");
        puts("1. Addition");
        puts("2. Subtraction");
        puts("3. Multiplication");
        puts("4. Multiply with Scalar");
        puts("0. Kembali");
        printf("Select an option (0-4): ");
        puts("note : all the result will rounded to 2 decimals");
        scanf("%d", &matrixChoice);

        switch (matrixChoice) {
        	case 0:
        		clrscr();
        		return;
        		
            case 1: // Addition
            	clrscr();
                do {
                    puts("Matrix Addition");
                    printf("Enter the number of rows and columns [row] [column]: ");
                    scanf("%d %d", &rows1, &cols1);
                    puts("Enter elements of the first matrix:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("Enter element at position [%d][%d]: ", i + 1, j + 1);
                            scanf("%lf", &mat1[i][j]);
                        }
                    }
                    puts("Enter elements of the second matrix:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("Enter element at position [%d][%d]: ", i + 1, j + 1);
                            scanf("%lf", &mat2[i][j]);
                        }
                    }
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            result[i][j] = mat1[i][j] + mat2[i][j];
                        }
                    }
                    puts("Resultant Matrix:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("%.2f\t", result[i][j]);
                        }
                        printf("\n");
                    }
                    puts("Do you want to perform another addition? [Y/N]");
                    getchar();
                    scanf("%c", &cont);
                } while (cont == 'Y' || cont == 'y');
                clrscr();
                break;

            case 2: // Subtraction
                clrscr();
				do {
                    puts("Matrix Subtraction");
                    printf("Enter the number of rows and columns [row] [column]: ");
                    scanf("%d %d", &rows1, &cols1);
                    puts("Enter elements of the first matrix:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("Enter element at position [%d][%d]: ", i + 1, j + 1);
                            scanf("%lf", &mat1[i][j]);
                        }
                    }
                    puts("Enter elements of the second matrix:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("Enter element at position [%d][%d]: ", i + 1, j + 1);
                            scanf("%lf", &mat2[i][j]);
                        }
                    }
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            result[i][j] = mat1[i][j] - mat2[i][j];
                        }
                    }
                    puts("Resultant Matrix:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("%.2f\t", result[i][j]);
                        }
                        printf("\n");
                    }
                    puts("Do you want to perform another subtraction? [Y/N]");
                    getchar();
                    scanf("%c", &cont);
                } while (cont == 'Y' || cont == 'y');
                clrscr();
                break;

            case 3: // Multiplication
                clrscr();
				do {
                    puts("Matrix Multiplication");
                    printf("Enter rows and columns of the first matrix [row] [column]: ");
                    scanf("%d %d", &rows1, &cols1);
                    puts("Enter elements of the first matrix:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("Enter element at position [%d][%d]: ", i + 1, j + 1);
                            scanf("%lf", &mat1[i][j]);
                        }
                    }
                    printf("Enter rows and columns of the second matrix [row] [column]: ");
                    scanf("%d %d", &rows2, &cols2);

                    if (cols1 != rows2) {
                        puts("Error: The number of columns in the first matrix must equal the number of rows in the second matrix.");
                        break;
                    }

                    puts("Enter elements of the second matrix:");
                    for (i = 0; i < rows2; i++) {
                        for (j = 0; j < cols2; j++) {
                            printf("Enter element at position [%d][%d]: ", i + 1, j + 1);
                            scanf("%lf", &mat2[i][j]);
                        }
                    }
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols2; j++) {
                            result[i][j] = 0;
                            for (k = 0; k < cols1; k++) {
                                result[i][j] += mat1[i][k] * mat2[k][j];
                            }
                        }
                    }
                    puts("Resultant Matrix:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols2; j++) {
                            printf("%.2f\t", result[i][j]);
                        }
                        printf("\n");
                    }
                    puts("Do you want to perform another multiplication? [Y/N]");
                    getchar();
                    scanf("%c", &cont);
                } while (cont == 'Y' || cont == 'y');
                clrscr();
                break;

            case 4: // Multiply with Scalar
                clrscr();
				do {
                    puts("Multiply Matrix with Scalar");
                    printf("Enter rows and columns of the matrix [row] [column]: ");
                    scanf("%d %d", &rows1, &cols1);
                    puts("Enter elements of the matrix:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("Enter element at position [%d][%d]: ", i + 1, j + 1);
                            scanf("%lf", &mat1[i][j]);
                        }
                    }
                    printf("Enter the scalar value to multiply with: ");
                    scanf("%lf", &scalar);
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            result[i][j] = mat1[i][j] * scalar;
                        }
                    }
                    puts("Resultant Matrix:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("%.2f\t", result[i][j]);
                        }
                        printf("\n");
                    }
                    puts("Do you want to perform another scalar multiplication? [Y/N]");
                    getchar();
                    scanf("%c", &cont);
                } while (cont == 'Y' || cont == 'y');
                clrscr();
                break;

            default:
                clrscr();
				puts("Invalid Input. Please select a valid option.");
                break;
        }
    }
}

void twoDInd(){
	int twoDchoice;
    char sameCase;

    while (1) {
        puts("Kalkulator 2D (Luas & Keliling)");
        puts("========================================");
        puts("1. Persegi Panjang");
        puts("2. Persegi");
        puts("3. Lingkaran");
        puts("4. Segitiga");
        puts("5. Jajaran Genjang");
        puts("6. Belah Ketupat");
        puts("7. Layang-layang");
        puts("8. Trapesium");
        puts("0. Kembali");
        printf("Pilih opsi (0-8): ");
        scanf("%d", &twoDchoice);

        switch (twoDchoice) {
            case 1: // Persegi Panjang
                clrscr();
                do {
                    double length, width, area, perimeter;
                    puts("Masukkan panjang:");
                    scanf("%lf", &length);
                    puts("Masukkan lebar:");
                    scanf("%lf", &width);
                    area = length * width;
                    perimeter = 2 * (length + width);
                    printf("Luas Persegi Panjang: %.2f\n", area);
                    printf("Keliling Persegi Panjang: %.2f\n", perimeter);

                    puts("Apakah Anda ingin menghitung lagi persegi panjang? [Y/T]:");
                    getchar(); // Consume newline
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;

            case 2:  // Persegi
                clrscr();
                do {
                    double side, area, perimeter;
                    puts("Masukkan panjang sisi:");
                    scanf("%lf", &side);
                    area = side * side;
                    perimeter = 4 * side;
                    printf("Luas Persegi: %.2f\n", area);
                    printf("Keliling Persegi: %.2f\n", perimeter);

                    puts("Apakah Anda ingin menghitung lagi persegi? [Y/T]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 3:  // Lingkaran
                clrscr();
                do {
                    const double pi = 3.14159;
                    double radius, area, circumference;
                    puts("Masukkan jari-jari:");
                    scanf("%lf", &radius);
                    area = pi * radius * radius;
                    circumference = 2 * pi * radius;
                    printf("Luas Lingkaran: %.2f\n", area);
                    printf("Keliling Lingkaran: %.2f\n", circumference);

                    puts("Apakah Anda ingin menghitung lagi lingkaran? [Y/T]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 4:  // Segitiga
                clrscr();
                do {
                    double base, height, side1, side2, side3, area, perimeter;
                    puts("Masukkan panjang alas:");
                    scanf("%lf", &base);
                    puts("Masukkan tinggi:");
                    scanf("%lf", &height);
                    puts("Masukkan panjang sisi pertama:");
                    scanf("%lf", &side1);
                    puts("Masukkan panjang sisi kedua:");
                    scanf("%lf", &side2);
                    puts("Masukkan panjang sisi ketiga:");
                    scanf("%lf", &side3);
                    area = 0.5 * base * height;
                    perimeter = side1 + side2 + side3;
                    printf("Luas Segitiga: %.2f\n", area);
                    printf("Keliling Segitiga: %.2f\n", perimeter);

                    puts("Apakah Anda ingin menghitung lagi segitiga? [Y/T]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 5:  // Jajaran Genjang
                clrscr();
                do {
                    double base, height, side1, side2, area, perimeter;
                    puts("Masukkan panjang alas:");
                    scanf("%lf", &base);
                    puts("Masukkan tinggi:");
                    scanf("%lf", &height);
                    puts("Masukkan panjang sisi pertama:");
                    scanf("%lf", &side1);
                    puts("Masukkan panjang sisi kedua:");
                    scanf("%lf", &side2);
                    area = base * height;
                    perimeter = 2 * (side1 + side2);
                    printf("Luas Jajaran Genjang: %.2f\n", area);
                    printf("Keliling Jajaran Genjang: %.2f\n", perimeter);

                    puts("Apakah Anda ingin menghitung lagi jajaran genjang? [Y/T]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 6:  // Belah Ketupat
                clrscr();
                do {
                    double diagonal1, diagonal2, side, area, perimeter;
                    puts("Masukkan panjang diagonal pertama:");
                    scanf("%lf", &diagonal1);
                    puts("Masukkan panjang diagonal kedua:");
                    scanf("%lf", &diagonal2);
                    puts("Masukkan panjang sisi:");
                    scanf("%lf", &side);
                    area = (diagonal1 * diagonal2) / 2;
                    perimeter = 4 * side;
                    printf("Luas Belah Ketupat: %.2f\n", area);
                    printf("Keliling Belah Ketupat: %.2f\n", perimeter);

                    puts("Apakah Anda ingin menghitung lagi belah ketupat? [Y/T]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 7:  // Layang-layang
                clrscr();
                do {
                    double diagonal1, diagonal2, side1, side2, area, perimeter;
                    puts("Masukkan panjang diagonal pertama:");
                    scanf("%lf", &diagonal1);
                    puts("Masukkan panjang diagonal kedua:");
                    scanf("%lf", &diagonal2);
                    puts("Masukkan panjang sisi pertama:");
                    scanf("%lf", &side1);
                    puts("Masukkan panjang sisi kedua:");
                    scanf("%lf", &side2);
                    area = (diagonal1 * diagonal2) / 2;
                    perimeter = 2 * (side1 + side2);
                    printf("Luas Layang-layang: %.2f\n", area);
                    printf("Keliling Layang-layang: %.2f\n", perimeter);

                    puts("Apakah Anda ingin menghitung lagi layang-layang? [Y/T]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 8:  // Trapesium
                clrscr();
                do {
                    double base1, base2, height, side1, side2, area, perimeter;
                    puts("Masukkan panjang alas pertama:");
                    scanf("%lf", &base1);
                    puts("Masukkan panjang alas kedua:");
                    scanf("%lf", &base2);
                    puts("Masukkan tinggi:");
                    scanf("%lf", &height);
                    puts("Masukkan panjang sisi pertama:");
                    scanf("%lf", &side1);
                    puts("Masukkan panjang sisi kedua:");
                    scanf("%lf", &side2);
                    area = 0.5 * (base1 + base2) * height;
                    perimeter = base1 + base2 + side1 + side2;
                    printf("Luas Trapesium: %.2f\n", area);
                    printf("Keliling Trapesium: %.2f\n", perimeter);

                    puts("Apakah Anda ingin menghitung lagi trapesium? [Y/T]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 0:
                clrscr();
                return;
            default:
                puts("Opsi tidak valid. Silakan pilih opsi yang valid.");
                break;
        }
    }
}

void twoDEng(){
	int twoDchoice;
    char sameCase;

    while (1) {
        puts("2D Calculator (Area & Perimeter)");
        puts("========================================");
        puts("1. Rectangle");
        puts("2. Square");
        puts("3. Circle");
        puts("4. Triangle");
        puts("5. Parallelogram");
        puts("6. Rhombus");
        puts("7. Kite");
        puts("8. Trapezoid");
        puts("0. Back");
        printf("Choose an option (0-8): ");
        scanf("%d", &twoDchoice);

        switch (twoDchoice) {
            case 1: // Rectangle
            	clrscr();
                do {
                    double length, width, area, perimeter;
                    puts("Enter the length:");
                    scanf("%lf", &length);
                    puts("Enter the width:");
                    scanf("%lf", &width);
                    area = length * width;
                    perimeter = 2 * (length + width);
                    printf("Rectangle Area: %.2f\n", area);
                    printf("Rectangle Perimeter: %.2f\n", perimeter);

                    puts("Do you want to calculate another rectangle? [Y/N]:");
                    getchar(); // Consume newline
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;

            case 2:  // Square
                clrscr();
				do {
                    double side, area, perimeter;
                    puts("Enter the side length:");
                    scanf("%lf", &side);
                    area = side * side;
                    perimeter = 4 * side;
                    printf("Square Area: %.2f\n", area);
                    printf("Square Perimeter: %.2f\n", perimeter);

                    puts("Do you want to calculate another square? [Y/N]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 3:  // Circle
                clrscr();
				do {
                    const double pi = 3.14159;
                    double radius, area, circumference;
                    puts("Enter the radius:");
                    scanf("%lf", &radius);
                    area = pi * radius * radius;
                    circumference = 2 * pi * radius;
                    printf("Circle Area: %.2f\n", area);
                    printf("Circle Perimeter (Circumference): %.2f\n", circumference);

                    puts("Do you want to calculate another circle? [Y/N]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 4:  // Triangle
                clrscr();
				do {
                    double base, height, side1, side2, side3, area, perimeter;
                    puts("Enter the base length:");
                    scanf("%lf", &base);
                    puts("Enter the height:");
                    scanf("%lf", &height);
                    puts("Enter the first side length:");
                    scanf("%lf", &side1);
                    puts("Enter the second side length:");
                    scanf("%lf", &side2);
                    puts("Enter the third side length:");
                    scanf("%lf", &side3);
                    area = 0.5 * base * height;
                    perimeter = side1 + side2 + side3;
                    printf("Triangle Area: %.2f\n", area);
                    printf("Triangle Perimeter: %.2f\n", perimeter);

                    puts("Do you want to calculate another triangle? [Y/N]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 5:  // Parallelogram
                clrscr();
				do {
                    double base, height, side1, side2, area, perimeter;
                    puts("Enter the base length:");
                    scanf("%lf", &base);
                    puts("Enter the height:");
                    scanf("%lf", &height);
                    puts("Enter the first side length:");
                    scanf("%lf", &side1);
                    puts("Enter the second side length:");
                    scanf("%lf", &side2);
                    area = base * height;
                    perimeter = 2 * (side1 + side2);
                    printf("Parallelogram Area: %.2f\n", area);
                    printf("Parallelogram Perimeter: %.2f\n", perimeter);

                    puts("Do you want to calculate another parallelogram? [Y/N]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 6:  // Rhombus
                clrscr();
				do {
                    double diagonal1, diagonal2, side, area, perimeter;
                    puts("Enter the first diagonal length:");
                    scanf("%lf", &diagonal1);
                    puts("Enter the second diagonal length:");
                    scanf("%lf", &diagonal2);
                    puts("Enter the side length:");
                    scanf("%lf", &side);
                    area = (diagonal1 * diagonal2) / 2;
                    perimeter = 4 * side;
                    printf("Rhombus Area: %.2f\n", area);
                    printf("Rhombus Perimeter: %.2f\n", perimeter);

                    puts("Do you want to calculate another rhombus? [Y/N]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 7:  // Kite
                clrscr();
				do {
                    double diagonal1, diagonal2, side1, side2, area, perimeter;
                    puts("Enter the first diagonal length:");
                    scanf("%lf", &diagonal1);
                    puts("Enter the second diagonal length:");
                    scanf("%lf", &diagonal2);
                    puts("Enter the first side length:");
                    scanf("%lf", &side1);
                    puts("Enter the second side length:");
                    scanf("%lf", &side2);
                    area = (diagonal1 * diagonal2) / 2;
                    perimeter = 2 * (side1 + side2);
                    printf("Kite Area: %.2f\n", area);
                    printf("Kite Perimeter: %.2f\n", perimeter);

                    puts("Do you want to calculate another kite? [Y/N]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 8:  // Trapezoid
                clrscr();
				do {
                    double base1, base2, height, side1, side2, area, perimeter;
                    puts("Enter the first base length:");
                    scanf("%lf", &base1);
                    puts("Enter the second base length:");
                    scanf("%lf", &base2);
                    puts("Enter the height:");
                    scanf("%lf", &height);
                    puts("Enter the first non-parallel side length:");
                    scanf("%lf", &side1);
                    puts("Enter the second non-parallel side length:");
                    scanf("%lf", &side2);
                    area = 0.5 * (base1 + base2) * height;
                    perimeter = base1 + base2 + side1 + side2;
                    printf("Trapezoid Area: %.2f\n", area);
                    printf("Trapezoid Perimeter: %.2f\n", perimeter);

                    puts("Do you want to calculate another trapezoid? [Y/N]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 0:
            	clrscr();
                return;
            default:
                puts("Invalid option. Please choose a valid option.");
                break;
        }
    }
}

void threeDInd(){
	int twoDchoice;
    char sameCase;

    while (1) {
        puts("Kalkulator 3D (Volume & Luas Permukaan)");
        puts("========================================");
        puts("1. Kubus");
        puts("2. Balok");
        puts("3. Silinder (Tabung)");
        puts("4. Prisma Segitiga");
        puts("5. Limas Segitiga");
        puts("6. Limas Segiempat");
        puts("7. Kerucut");
        puts("8. Bola");
        puts("0. Kembali");
        printf("Pilih opsi (0-8): ");
        scanf("%d", &twoDchoice);

        switch (twoDchoice) {
            case 1: // Kubus
                clrscr();
                do {
                	double side, volume, surArea;
                    puts("Masukkan panjang sisi:");
                    scanf("%lf", &side);
                    volume = side * side * side;
                    surArea = 6 * side * side;
                    printf("Volume Kubus: %.2f\n", volume);
                    printf("Luas Permukaan Kubus: %.2f\n", surArea);

                    puts("Apakah Anda ingin menghitung lagi persegi? [Y/T]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;

            case 2:  // Balok
                clrscr();
                do {
                    double length, width, height, volume, surArea;
                    puts("Masukkan panjang:");
                    scanf("%lf", &length);
                    puts("Masukkan lebar:");
                    scanf("%lf", &width);
                    puts("Masukkan tinggi:");
                    scanf("%lf", &height);
                    volume = length * width * height;
                    surArea = (2 * length * width) + (2 * length * height) + (2 * height * width);
                    printf("Volume Balok: %.2f\n", volume);
                    printf("Luas Permukaan Balok: %.2f\n", surArea);

                    puts("Apakah Anda ingin menghitung lagi persegi panjang? [Y/T]:");
                    getchar(); // Consume newline
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 3:  // Tabung
                clrscr();
                do {
                    const double pi = 3.14159;
                    double radius, height, volume, surArea;
                    puts("Masukkan jari-jari:");
                    scanf("%lf", &radius);
                    puts("Masukkan tinggi tabung:");
                    scanf("%lf", &height);
                    volume = pi * radius * radius * height;
                    surArea = 2 * pi * radius * (radius + height);
                    printf("Volume Tabung: %.2f\n", volume);
                    printf("Luas Permukaan Tabung: %.2f\n", surArea);

                    puts("Apakah Anda ingin menghitung lagi lingkaran? [Y/T]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 4:  // Prisma Segitiga
                clrscr();
                do {
                    double base, theight, side1, side2, side3, height, volume, surArea;
                    puts("Masukkan panjang alas:");
                    scanf("%lf", &base);
                    puts("Masukkan tinggi segitiga:");
                    scanf("%lf", &theight);
                    puts("Masukkan tinggi Prisma:");
                    scanf("%lf", &height);
                    puts("Masukkan panjang sisi pertama:");
                    scanf("%lf", &side1);
                    puts("Masukkan panjang sisi kedua:");
                    scanf("%lf", &side2);
                    puts("Masukkan panjang sisi ketiga:");
                    scanf("%lf", &side3);
                    volume = 0.5 * base * height * theight;
                    surArea = ((side1 + side2 + side3) * height) + (base * theight);
                    printf("Volume Prisma Segitiga: %.2f\n", volume);
                    printf("Luas Permukaan Prisma Segitiga: %.2f\n", surArea);

                    puts("Apakah Anda ingin menghitung lagi segitiga? [Y/T]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 5:  // Limas Segitiga
                clrscr();
                do {
                    double base, theight, height, area1, area2, area3, area4, volume, surArea;
                    puts("Masukkan panjang alas:");
                    scanf("%lf", &base);
                    puts("Masukkan tinggi Segitiga:");
                    scanf("%lf", &theight);
                    puts("Masukkan tinggi Limas:");
                    scanf("%lf", &height);
                    puts("Masukkan luas sisi pertama:");
                    scanf("%lf", &area1);
                    puts("Masukkan luas sisi kedua:");
                    scanf("%lf", &area2);
                    puts("Masukkan luas sisi ketiga:");
                    scanf("%lf", &area3);
                    puts("Masukkan luas sisi ke-empat:");
                    scanf("%lf", &area4);
                    volume = (base * height * theight)/6;
                    surArea = area1 + area2 + area3 + area4;
                    printf("Volume Limas Segitiga: %.2f\n", volume);
                    printf("Luas Permukaan Limas Segitiga: %.2f\n", surArea);

                    puts("Apakah Anda ingin menghitung lagi jajaran genjang? [Y/T]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 6:  // Limas Segiempat
                clrscr();
                do {
                    double bLength, bWidth, height, area1, area2, area3, area4, area5, volume, surArea;
                    puts("Masukkan panjang alas:");
                    scanf("%lf", &bLength);
                    puts("Masukkan lebar alas:");
                    scanf("%lf", &bWidth);
                    puts("Masukkan tinggi Limas:");
                    scanf("%lf", &height);
                    puts("Masukkan luas sisi pertama:");
                    scanf("%lf", &area1);
                    puts("Masukkan luas sisi kedua:");
                    scanf("%lf", &area2);
                    puts("Masukkan luas sisi ketiga:");
                    scanf("%lf", &area3);
                    puts("Masukkan luas sisi ke-empat:");
                    scanf("%lf", &area4);
                    puts("Masukkan luas sisi kelima:");
                    scanf("%lf", &area5);
                    volume = (bLength * height * bWidth)/3;
                    surArea = area1 + area2 + area3 + area4 + area5;
                    printf("Volume Limas Segiempat: %.2f\n", volume);
                    printf("Luas Permukaan Limas Segiempat: %.2f\n", surArea);

                    puts("Apakah Anda ingin menghitung lagi belah ketupat? [Y/T]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 7:  // Kerucut
                clrscr();
                do {
                    const double pi = 3.14159;
                    double radius, height, side, volume, surArea;
                    puts("Masukkan jari-jari:");
                    scanf("%lf", &radius);
                    puts("Masukkan tinggi kerucut:");
                    scanf("%lf", &height);
                    puts("Masukkan panjang sisi kerucut:");
                    scanf("%lf", &side);
                    volume = (pi * radius * radius * height) / 3;
                    surArea = (pi * radius * side) + (pi * radius * radius);
                    printf("Volume Kerucut: %.2f\n", volume);
                    printf("Luas Permukaan Kerucut: %.2f\n", surArea);

                    puts("Apakah Anda ingin menghitung lagi layang-layang? [Y/T]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 8:  // Bola
                clrscr();
                do {
                    const double pi = 3.14159;
                    double radius, volume, surArea;
                    puts("Masukkan jari-jari:");
                    scanf("%lf", &radius);
                    volume = 4 * (pi * radius * radius * radius) / 3;
                    surArea = 4 * pi * radius * radius;
                    printf("Volume Bola: %.2f\n", volume);
                    printf("Luas Permukaan Bola: %.2f\n", surArea);

                    puts("Apakah Anda ingin menghitung lagi trapesium? [Y/T]:");
                    getchar();
                    scanf("%c", &sameCase);
                } while (sameCase == 'Y' || sameCase == 'y');
                clrscr();
                break;
            
            case 0:
                clrscr();
                return;
            default:
                puts("Opsi tidak valid. Silakan pilih opsi yang valid.");
                break;
        }
    }
}

void threeDEng(){
	int threeDchoice;
char sameCase;

while (1) {
    puts("3D Calculator (Volume & Surface Area)");
    puts("========================================");
    puts("1. Cube");
    puts("2. Rectangular Prism");
    puts("3. Cylinder");
    puts("4. Triangular Prism");
    puts("5. Triangular Pyramid");
    puts("6. Square Pyramid");
    puts("7. Cone");
    puts("8. Sphere");
    puts("0. Back");
    printf("Choose an option (0-8): ");
    scanf("%d", &threeDchoice);

    switch (threeDchoice) {
        case 1: // Cube
            clrscr();
            do {
                double side, volume, surfaceArea;
                puts("Enter the side length:");
                scanf("%lf", &side);
                volume = side * side * side;
                surfaceArea = 6 * side * side;
                printf("Cube Volume: %.2f\n", volume);
                printf("Cube Surface Area: %.2f\n", surfaceArea);

                puts("Do you want to calculate again? [Y/N]:");
                getchar();
                scanf("%c", &sameCase);
            } while (sameCase == 'Y' || sameCase == 'y');
            clrscr();
            break;

        case 2: // Rectangular Prism
            clrscr();
            do {
                double length, width, height, volume, surfaceArea;
                puts("Enter the length:");
                scanf("%lf", &length);
                puts("Enter the width:");
                scanf("%lf", &width);
                puts("Enter the height:");
                scanf("%lf", &height);
                volume = length * width * height;
                surfaceArea = (2 * length * width) + (2 * length * height) + (2 * height * width);
                printf("Rectangular Prism Volume: %.2f\n", volume);
                printf("Rectangular Prism Surface Area: %.2f\n", surfaceArea);

                puts("Do you want to calculate again? [Y/N]:");
                getchar(); // Consume newline
                scanf("%c", &sameCase);
            } while (sameCase == 'Y' || sameCase == 'y');
            clrscr();
            break;

        case 3: // Cylinder
            clrscr();
            do {
                const double pi = 3.14159;
                double radius, height, volume, surfaceArea;
                puts("Enter the radius:");
                scanf("%lf", &radius);
                puts("Enter the height of the cylinder:");
                scanf("%lf", &height);
                volume = pi * radius * radius * height;
                surfaceArea = 2 * pi * radius * (radius + height);
                printf("Cylinder Volume: %.2f\n", volume);
                printf("Cylinder Surface Area: %.2f\n", surfaceArea);

                puts("Do you want to calculate again? [Y/N]:");
                getchar();
                scanf("%c", &sameCase);
            } while (sameCase == 'Y' || sameCase == 'y');
            clrscr();
            break;

        case 4: // Triangular Prism
            clrscr();
            do {
                double base, triangleHeight, prismHeight, side1, side2, side3, volume, surfaceArea;
                puts("Enter the base length of the triangle:");
                scanf("%lf", &base);
                puts("Enter the height of the triangle:");
                scanf("%lf", &triangleHeight);
                puts("Enter the height of the prism:");
                scanf("%lf", &prismHeight);
                puts("Enter the first side of the triangle:");
                scanf("%lf", &side1);
                puts("Enter the second side of the triangle:");
                scanf("%lf", &side2);
                puts("Enter the third side of the triangle:");
                scanf("%lf", &side3);

                volume = 0.5 * base * triangleHeight * prismHeight;
                surfaceArea = (base * triangleHeight) + (side1 + side2 + side3) * prismHeight;
                printf("Triangular Prism Volume: %.2f\n", volume);
                printf("Triangular Prism Surface Area: %.2f\n", surfaceArea);

                puts("Do you want to calculate again? [Y/N]:");
                getchar();
                scanf("%c", &sameCase);
            } while (sameCase == 'Y' || sameCase == 'y');
            clrscr();
            break;

        case 5: // Triangular Pyramid
            clrscr();
            do {
                double base, triangleHeight, pyramidHeight, sideArea1, sideArea2, sideArea3, sideArea4, volume, surfaceArea;
                puts("Enter the base length of the triangle:");
                scanf("%lf", &base);
                puts("Enter the height of the triangle:");
                scanf("%lf", &triangleHeight);
                puts("Enter the height of the pyramid:");
                scanf("%lf", &pyramidHeight);
                puts("Enter the area of the first triangular face:");
                scanf("%lf", &sideArea1);
                puts("Enter the area of the second triangular face:");
                scanf("%lf", &sideArea2);
                puts("Enter the area of the third triangular face:");
                scanf("%lf", &sideArea3);
                puts("Enter the area of the base:");
                scanf("%lf", &sideArea4);

                volume = (0.5 * base * triangleHeight * pyramidHeight) / 3;
                surfaceArea = sideArea1 + sideArea2 + sideArea3 + sideArea4;
                printf("Triangular Pyramid Volume: %.2f\n", volume);
                printf("Triangular Pyramid Surface Area: %.2f\n", surfaceArea);

                puts("Do you want to calculate again? [Y/N]:");
                getchar();
                scanf("%c", &sameCase);
            } while (sameCase == 'Y' || sameCase == 'y');
            clrscr();
            break;

        case 6: // Square Pyramid
            clrscr();
            do {
                double baseLength, baseWidth, height, sideArea1, sideArea2, sideArea3, sideArea4, baseArea, volume, surfaceArea;
                puts("Enter the base length:");
                scanf("%lf", &baseLength);
                puts("Enter the base width:");
                scanf("%lf", &baseWidth);
                puts("Enter the height of the pyramid:");
                scanf("%lf", &height);
                puts("Enter the area of the first triangular face:");
                scanf("%lf", &sideArea1);
                puts("Enter the area of the second triangular face:");
                scanf("%lf", &sideArea2);
                puts("Enter the area of the third triangular face:");
                scanf("%lf", &sideArea3);
                puts("Enter the area of the fourth triangular face:");
                scanf("%lf", &sideArea4);
                puts("Enter the area of the base:");
                scanf("%lf", &baseArea);

                volume = (baseLength * baseWidth * height) / 3;
                surfaceArea = sideArea1 + sideArea2 + sideArea3 + sideArea4 + baseArea;
                printf("Square Pyramid Volume: %.2f\n", volume);
                printf("Square Pyramid Surface Area: %.2f\n", surfaceArea);

                puts("Do you want to calculate again? [Y/N]:");
                getchar();
                scanf("%c", &sameCase);
            } while (sameCase == 'Y' || sameCase == 'y');
            clrscr();
            break;

        case 7: // Cone
            clrscr();
            do {
                const double pi = 3.14159;
                double radius, height, slantHeight, volume, surfaceArea;
                puts("Enter the radius:");
                scanf("%lf", &radius);
                puts("Enter the height of the cone:");
                scanf("%lf", &height);
                puts("Enter the slant height of the cone:");
                scanf("%lf", &slantHeight);
                volume = (pi * radius * radius * height) / 3;
                surfaceArea = (pi * radius * slantHeight) + (pi * radius * radius);
                printf("Cone Volume: %.2f\n", volume);
                printf("Cone Surface Area: %.2f\n", surfaceArea);

                puts("Do you want to calculate again? [Y/N]:");
                getchar();
                scanf("%c", &sameCase);
            } while (sameCase == 'Y' || sameCase == 'y');
            clrscr();
            break;

        case 8: // Sphere
            clrscr();
            do {
                const double pi = 3.14159;
                double radius, volume, surfaceArea;
                puts("Enter the radius:");
                scanf("%lf", &radius);
                volume = 4 * (pi * radius * radius * radius) / 3;
                surfaceArea = 4 * pi * radius * radius;
                printf("Sphere Volume: %.2f\n", volume);
                printf("Sphere Surface Area: %.2f\n", surfaceArea);

                puts("Do you want to calculate again? [Y/N]:");
                getchar();
                scanf("%c", &sameCase);
            } while (sameCase == 'Y' || sameCase == 'y');
            clrscr();
            break;

        case 0:
            clrscr();
            return;

        default:
            puts("Invalid option. Please choose a valid option.");
            break;
    	}
	}
}

void engMenu(){
	int choice;
	
    while (1) {
        puts("Math Solver");
        puts("=========================");
        puts("1. Scalar Calculator");
        puts("2. Matrix Calculator");
        puts("3. 2D Calculator");
        puts("4. 3D Calculator");
        puts("5. History");
        puts("0. Back");
        puts("Select an option (0-5)");
        printf(">>> ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                clrscr();
            	scalarEng();
                break;
            case 2:
                clrscr();
            	matrixEng();
                break;
            case 3:
                clrscr();
            	twoDEng();
                break;
            case 4:
                clrscr();
            	threeDEng();
                break;
			case 5:
            	clrscr();
            	historyMenuEng();
            	break;  
            case 0:
            	clrscr();
                return;
            default:
                puts("Invalid Input. Please select a valid option.");
                break;
        }
    }
}

void indMenu(){
	int choice;

while (1) {
    puts("Penyelesai Matematika");
    puts("=========================");
    puts("1. Kalkulator Skalar");
    puts("2. Kalkulator Matriks");
    puts("3. Kalkulator Bangun Datar");
    puts("4. Kalkulator Bangun Ruang");
    puts("5. Riwayat");
    puts("0. Kembali");
    puts("Pilih opsi (0-5)");
    printf(">>> ");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1:
            clrscr();
            scalarInd();
            break;
        case 2:
            clrscr();
            matrixInd();
            break;
        case 3:
            clrscr();
            twoDInd();
            break;
        case 4:
            clrscr();
            threeDInd();
            break;
        case 5:
            clrscr();
            historyMenuInd();
            break;   
        case 0:
            clrscr();
            return;
        default:
            puts("Masukan tidak valid. Silakan pilih opsi yang benar.");
            break;
    }
}

}

int main(){
	
	int langChoice, choice;
    char exit, cont;
	
	while (1) {
        puts("Choose Language (pilih bahasa)");
        puts("=========================");
        puts("1. English");
        puts("2. Bahasa Indonesia");
        puts("0. Exit");
        puts("Select an option (0-2)");
        printf(">>> ");
        scanf("%d", &langChoice);
        getchar();

        switch (langChoice) {
        	case 0:
                puts("Are you sure you want to leave this program? [Y/N]");
                scanf(" %c", &exit);
                getchar();
                if (exit == 'Y' || exit == 'y') {
                    puts("Exiting the program.");
                    return 0;
                } else if (exit == 'N' || exit == 'n') {
                    puts("Returning to the beginning.");
                    continue;
                } else {
                    puts("Invalid input");
                }
                break;
            
			case 1:
                clrscr();
            	engMenu();
                break;
        	
			case 2:
                clrscr();
            	indMenu();
                break;
            
			default:
                puts("Invalid Input. Please select a valid option.");
                break;
        }
    }
	
    return 0;
}
