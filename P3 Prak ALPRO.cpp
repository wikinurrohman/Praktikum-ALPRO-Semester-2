#include <iostream>
using namespace std;

struct makanan {
	string nama;
	string rasa;
	int gula;
};

struct manusia {
	string nama;
	string jenisKelamin;
	string olahraga [3];
    int usia;
    int TB, BB;
    int tingkatGula;

	printGula() {
		cout << "Tingkat gula pada " << nama << " saat ini adalah " << tingkatGula << "\n";
		cout << "Kurangngi mengkonsumsi tinggi gula!!!\n\n";
	}

	makan (makanan objekMakanan) {
		tingkatGula = tingkatGula + objekMakanan.gula;
		cout << "Saya baru saja mengkonsumsi " << objekMakanan.nama << " dan sekarang saya merasa pusing dan ngantuk." << "\n";
		printGula();
	}
};

int main() {
    system("cls");
	makanan makanan1;
	makanan1.nama = "kopi";
	makanan1.rasa = "pahit";
	makanan1.gula = 100;

	makanan makanan2;
	makanan2.nama = "nasi putih";
	makanan2.rasa = "hambar";
	makanan2.gula = 250;

	makanan makanan3;
	makanan3.nama = "yoghurt";
	makanan3.rasa = "asam";
	makanan3.gula = 320;

	makanan makanan4;
	makanan4.nama = "roti";
	makanan4.rasa = "gurih";
	makanan4.gula = 50;

	makanan makanan5;
	makanan5.nama = "salad";
	makanan5.rasa = "manis";
	makanan5.gula = 270;

	manusia m1;
	m1.usia = 75;
	m1.nama = "Domm";
	m1.TB = 175;
	m1.BB = 60;
	m1.jenisKelamin = "Pria";
	m1.olahraga[0] = "Berenang";
	m1.olahraga[1] = "Bersepedah";
	m1.olahraga[2] = "Lari maraton";
	m1.tingkatGula = 2500;

	manusia m2;
	m2.usia = 60;
	m2.nama = "Acee";
	m2.TB = 165;
	m2.BB = 50;
	m2.jenisKelamin = "Wanita";
	m2.olahraga[0] = "Jalan Santai";
	m2.olahraga[1] = "Aerobik";
	m2.olahraga[2] = "Basket";
	m2.tingkatGula = 2000;

	cout << "===Tingkat gula pada Domm===\n";
	m1.makan(makanan1);
	m1.makan(makanan2);
	m1.makan(makanan3);
	m1.makan(makanan4);
	cout << "\n\n===Tingkat gula pada Acee===\n";
	m2.makan(makanan1);
	m2.makan(makanan2);
	m2.makan(makanan3);
	m2.makan(makanan5);
	cout << endl;

	cout << "Nama saya adalah " << m2.nama << " berusia " << m2.usia << "\n";

	for (int i = 0; i < 10; i++){
		if (m1.olahraga[i] != " "){
			cout << "Olahraga Ke-" << i + 1 << " " << m1.olahraga[i] << "\n";
		}
	}

	return 0;
}
