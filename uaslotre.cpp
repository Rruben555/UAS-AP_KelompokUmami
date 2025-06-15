#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Variabel global
char board[4][5];         // Tampilan kotak: '*', 'O', atau 'X'
bool revealed[4][5];      // Apakah kotak sudah dibuka
int slot[4][5];           // Isi kotak: 0 = aman, 1 = bom
int count = 0;            // Jumlah kotak aman yang berhasil dibuka
bool gameOver = false;    // Status permainan


void generateBoard() {
    srand(static_cast<unsigned>(time(0)));

    // Inisialisasi semua kotak
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            board[i][j] = '*';
            revealed[i][j] = false;
            slot[i][j] = 0;
        }
    }

    int axisx1 = rand() % 5;
    int axisy1 = rand() % 4;
    int axisx2, axisy2;
    do {
        axisx2 = rand() % 5;
        axisy2 = rand() % 4;
    } while (axisx2 == axisx1 && axisy2 == axisy1);

    slot[axisy1][axisx1] = 1;
    slot[axisy2][axisx2] = 1;
}

// menampilkan papan game
void displayBoard() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cout << " " << board[i][j] << " ";
        }
        cout << endl;
    }
}

// memproses tebakan pemain
void guess(int y, int x) {
    if (x < 0 || x >= 5 || y < 0 || y >= 4) {
        cout << "Koordinat di luar jangkauan! Coba lagi."<<endl;
        return;
    }

    if (revealed[y][x]) {
        cout << "Kotak sudah dibuka sebelumnya!"<<endl;
        return;
    }

    revealed[y][x] = true;

    if (slot[y][x] == 1) {
        board[y][x] = 'X';
        gameOver = true;
        cout << "BOOM! Anda menemukan bom! Permainan berakhir."<<endl;
    }
    else {
        board[y][x] = 'O';
        cout << "Kotak Aman."<<endl;
        count++;
        if (count == 18) 
        cout << "Selamat Anda Menang!"<<endl;
    }
    
}


// mengecek apakah permainan sudah selesai
bool isGameOver() {
    if (gameOver || count == 18) return true;
    return false;
}

// Program utama
int main() {
    system("cls");
    int x, y;
    generateBoard();
    //cheat
    cout << "\nJawaban Lengkap (X = bom):\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (slot[i][j] == 1) cout << " X ";
            else if (revealed[i][j]) cout << " O ";
            else cout << " * ";
        }
        cout << endl;
    }

    cout << "Welcome to E-Lottery Gosok"<<endl;;
    displayBoard();

    while (!isGameOver()) {
        cout << "\nMasukkan tebakan anda (baris dan kolom): ";
        cin >> y >> x; // baris = y, kolom = x
        guess(y, x);
        displayBoard();
        cout<<count<<endl;
    }

    return 0;
}