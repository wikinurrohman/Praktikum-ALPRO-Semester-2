//Wiki Nurrohman, 1217050140, Teknik Informatika G
//break
#include <iostream>

using namespace std;

struct registrant_t {
    int id;
    string name;
    string SendDest;
    string cow;
};

int main() {
    system("cls");

    cout << "=======================================================\n";
    cout << "*- Pemenang Give Away Sapi Khusus Wilayah Jawa Barat -*\n";
    cout << "=======================================================\n\n";

    registrant_t registrant[] = {
        {1, "Jon", "Subang", "Sapi"},
        {2, "Naz", "Garut", "Sapi"},
        {3, "Dion", "Bandung", "Sapi"},
        {4, "Elba", "Kuningan", "Sapi"},
        {5, "Aziz", "Depok", "Sapi"},
        {6, "Shar", "Boyolali", "Sapi"},
        {7, "Jae", "Medan", "Sapi"}
    };

    int idGiveAwaySapi = 6;

    for (int i = 0; i < 7; i++){
        if (registrant[i].id == idGiveAwaySapi){
            cout << registrant[i].name << ", Beliau tidak dapat Sapi karena diluar wilayah Jawa Barat\n";
            break;
        }

        cout << registrant[i].name << ", Beliau dapat " << registrant[i].cow << " silahkan kirim ke " << registrant[i].SendDest << "\n";
    }

}
