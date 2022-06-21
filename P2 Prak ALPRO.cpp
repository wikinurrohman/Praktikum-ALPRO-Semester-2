#include <iostream>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main() {
    // Game pokemon
    /*
    1
    2
    3
    4
    5
    6
    7
    */

    int panjangPeta = 20; // x
    int lebarPeta = 16; // y

    int posisiKarakterY = 15;
    int posisiKarakterX = 4;

    cout << "Karakter ada di y:" << posisiKarakterY << ", x:" << posisiKarakterX << "\n";

    int peta[lebarPeta][panjangPeta] = {
        {8,8,8,8,8,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {8,8,8,8,8,8,1,1,1,1,1,1,1,5,5,1,1,1,1,1},
        {8,8,8,1,1,1,1,1,1,1,1,1,1,5,5,1,1,1,1,1},
        {8,8,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,8,8,8,8,8,8,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,1,8,8,8,8,8,1,1,1,1,1,1,4,4,4,4,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,4,4,4,4,1,1,1},
        {1,1,1,5,5,1,1,1,1,1,4,4,4,4,4,4,4,1,1,1},
        {1,1,1,5,5,1,1,1,4,4,4,4,4,4,4,4,6,6,6,6},
        {1,1,5,5,1,1,1,1,4,4,4,4,4,4,4,4,4,1,1,1},
        {1,1,5,5,1,1,1,1,4,4,4,1,1,4,4,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,4,4,4,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,4,4,4,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1},
    };


    int arrowKey = 0;

    while(1) {
        // Input Keyboard
        cout << "===INFO DATA===\n";
        cout << "KEY_UP 72\n";
        cout << "KEY_DOWN 80\n";
        cout << "KEY_LEFT 75\n";
        cout << "KEY_RIGHT 77\n";
        cout << "\nMasukan arrow key : ";
        cin >> arrowKey;
        cout << "Arrow key yang dimasukan : " << arrowKey << "\n";

        // Aturan menggerakkan karakter ke atas
        if(arrowKey == 72 && (peta[posisiKarakterY-1][posisiKarakterX] == 1 || peta[posisiKarakterY-1][posisiKarakterX] == 4) && posisiKarakterY >= 0) {
            // Gerakkan karakter ke atas
            posisiKarakterY = posisiKarakterY-1;
        }

        // Aturan menggerakkan karakter ke bawah
        if(arrowKey == 80 && (peta[posisiKarakterY+1][posisiKarakterX] == 1 || peta[posisiKarakterY+1][posisiKarakterX] == 4) && posisiKarakterY < lebarPeta) {
            // Gerakkan karakter ke atas
            posisiKarakterY = posisiKarakterY+1;
        }

        // Aturan menggerakkan karakter ke kiri
        if(arrowKey == 75 && (peta[posisiKarakterY][posisiKarakterX-1] == 1 || peta[posisiKarakterY][posisiKarakterX-1] == 4) && posisiKarakterX >= 0) {
            // Gerakkan karakter ke atas
            posisiKarakterX = posisiKarakterX-1;
        }

        // Aturan menggerakkan karakter ke kanan
        if(arrowKey == 77 && (peta[posisiKarakterY][posisiKarakterX+1] == 1 || peta[posisiKarakterY][posisiKarakterX+1] == 4) && posisiKarakterX < panjangPeta) {
            // Gerakkan karakter ke atas
            posisiKarakterX = posisiKarakterX+1;
        }

        // Render grafik
        for(int y=0; y<lebarPeta; y++) {
            for(int x=0; x<panjangPeta; x++) {

                if(posisiKarakterX == x && posisiKarakterY == y) {
                    cout << 0 << " ";
                } else {
                    cout << peta[y][x] << " ";
                }
            }
            cout << "\n";
        }
    }


    return 0;
}
