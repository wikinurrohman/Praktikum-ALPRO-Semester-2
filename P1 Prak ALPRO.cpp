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


//continue
#include <iostream>

using namespace std;

struct buyer_t {
    int id;
    string name;
    string SendDest;
    string buy;
};

int main() {
    system("cls");

    cout << "=====================================\n";
    cout << "*- Daftar Pembeli Sapi Qurban 2022 -*\n";
    cout << "=====================================\n\n";

    int CodeAnimal = 4;

    buyer_t buyer[] = {
        {1, "1. Jon", "Subang", "Sapi"},
        {2, "2. Naz", "Garut", "Sapi"},
        {3, "3. Dion", "Bandung", "Sapi"},
        {4, "4. Elba", "Kuningan", "Kambing"},
        {5, "5. Aziz", "Depok", "Sapi"},
        {6, "6. Shar", "Boyolali", "Sapi"},
        {7, "7. Jae", "Medan", "Sapi"},
    };

    for (int i = 0; i < 7; i++){
        if (buyer[i].id == CodeAnimal){
            cout << buyer[i].name << ", Beliau tidak beli Sapi, silahkan pisah!\n";
            continue;
        }

        cout << buyer[i].name << ", Beliau beli " << buyer[i].buy << " silahkan kirim ke " << buyer[i].SendDest << "\n";
    }    

}
