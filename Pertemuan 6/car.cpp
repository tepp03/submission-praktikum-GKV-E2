#include <iostream>
using namespace std;

// Kelas Kendaraan sebagai dasar
class Kendaraan {
protected:
    string merk;
    int tahunProduksi;

public:
    Kendaraan(string merkKendaraan, int tahun) {
        merk = merkKendaraan;
        tahunProduksi = tahun;
    }

    virtual void tampilkanInfo() {
        cout << "Merk: " << merk << endl;
        cout << "Tahun Produksi: " << tahunProduksi << endl;
    }
};

// Kelas Mobil sebagai turunan dari Kendaraan
class Mobil : public Kendaraan {
private:
    int jumlahPintu;

public:
    Mobil(string merkMobil, int tahun, int pintu)
        : Kendaraan(merkMobil, tahun) {
        jumlahPintu = pintu;
    }

    void tampilkanInfo() override {
        cout << "Informasi Mobil:" << endl;
        Kendaraan::tampilkanInfo();
        cout << "Jumlah Pintu: " << jumlahPintu << endl;
    }
};

// Fungsi utama
int main() {
    Mobil kendaraan1("Toyota", 2015, 4);
    kendaraan1.tampilkanInfo();

    cout << endl;

    Mobil kendaraan2("Honda", 2020, 2);
    kendaraan2.tampilkanInfo();

    return 0;
}

