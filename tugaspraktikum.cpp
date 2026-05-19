#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract Base Class
class RekeningBank {
protected:
    string namaNasabah;
    double saldo;

public:
    // constructor
    RekeningBank(string nama, double saldoAwal) {
        namaNasabah = nama;
        saldo = saldoAwal;
    }

    // pure virtual function
    virtual void potongAdmin() = 0;

    // getter
    string getNama() {
        return namaNasabah;
    }

    double getSaldo() {
        return saldo;
    }

    // virtual destructor
    virtual ~RekeningBank() {}
};

// Rekening Syariah
class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        // tidak ada potongan admin
        cout << namaNasabah
             << " menggunakan Rekening Syariah (bebas biaya admin)"
             << endl;
    }
};

// Rekening Konvensional
class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        saldo -= 15000;

        cout << namaNasabah
             << " terkena biaya admin Rp 15.000"
             << endl;
    }
};

// Rekening Premium
class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {

        // jika saldo lebih dari 10 juta
        if (saldo > 10000000) {

            cout << namaNasabah
                 << " bebas biaya admin karena saldo di atas Rp 10.000.000"
                 << endl;

        } else {

            saldo -= 50000;

            cout << namaNasabah
                 << " terkena biaya admin Rp 50.000"
                 << endl;
        }
    }
};

int main() {

    // daftar rekening nasabah
    vector<RekeningBank*> daftarRekening;

    // menambahkan data nasabah
    daftarRekening.push_back(
        new RekeningSyariah("Ahmad", 5000000)
    );

    daftarRekening.push_back(
        new RekeningKonvensional("Budi", 5000000)
    );

    daftarRekening.push_back(
        new RekeningPremium("Citra", 15000000)
    );

    daftarRekening.push_back(
        new RekeningPremium("Dewi", 5000000)
    );

    // sebelum potong admin
    cout << "===== SALDO SEBELUM POTONG ADMIN ====="
         << endl;

    for (auto rekening : daftarRekening) {

        cout << rekening->getNama()
             << " : Rp "
             << rekening->getSaldo()
             << endl;
    }

    cout << endl;

    // proses potong admin
    cout << "===== PROSES POTONG ADMIN ====="
         << endl;

    for (auto rekening : daftarRekening) {

        rekening->potongAdmin();
    }

    // setelah potong admin
    cout << endl;

    cout << "===== SALDO SETELAH POTONG ADMIN ====="
         << endl;

    for (auto rekening : daftarRekening) {

        cout << rekening->getNama()
             << " : Rp "
             << rekening->getSaldo()
             << endl;
    }

    // hapus memory
    for (auto rekening : daftarRekening) {

        delete rekening;
    }

    return 0;
}

