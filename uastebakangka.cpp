#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    system("cls");
    srand(static_cast<unsigned>(time(0)));

    int angka = rand() % 100 + 1;
    int n;
    bool con = false;

    while (con == false) {

    cout << "Tebak angka: ";
    cin >> n;

    if (n > angka) cout << "Angka terlalu besar. Coba lagi.";

    else if (n < angka) cout << "Angka terlalu kecil. Coba lagi.";

    else {
        con = true;
        cout << "Selamat! Anda Benar!";
    }
    cout<<endl<<endl;
    }
}