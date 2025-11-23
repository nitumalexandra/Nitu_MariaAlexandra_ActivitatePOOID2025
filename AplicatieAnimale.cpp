#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Animal {
public:
    const int id;
    static int nrAnimale;
    char* nume;
    int varsta;

    Animal() : id(nrAnimale++) {
        this->varsta = 0;
        this->nume = new char[strlen("Necunoscut") + 1];
        strcpy_s(this->nume, strlen("Necunoscut") + 1, "Necunoscut");
    }

    Animal(const char* nume) : id(nrAnimale++) {
        this->varsta = 0;
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
    }

    Animal(const char* nume, int varsta) : id(nrAnimale++) {
        this->varsta = varsta;
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
    }

    ~Animal() {
        delete[] nume;
    }

    static void afisareNrAnimale() {
        cout << nrAnimale << endl;
    }
};

int Animal::nrAnimale = 0;

class Mamifer {
public:
    const int cod;
    static int nrMamifere;
    char* specie;
    float greutate;

    Mamifer() : cod(nrMamifere++) {
        this->greutate = 0;
        this->specie = new char[strlen("Necunoscuta") + 1];
        strcpy_s(this->specie, strlen("Necunoscuta") + 1, "Necunoscuta");
    }

    Mamifer(const char* specie) : cod(nrMamifere++) {
        this->greutate = 0;
        this->specie = new char[strlen(specie) + 1];
        strcpy_s(this->specie, strlen(specie) + 1, specie);
    }

    Mamifer(const char* specie, float greutate) : cod(nrMamifere++) {
        this->greutate = greutate;
        this->specie = new char[strlen(specie) + 1];
        strcpy_s(this->specie, strlen(specie) + 1, specie);
    }

    ~Mamifer() {
        delete[] specie;
    }

    static void afisareNrMamifere() {
        cout << nrMamifere << endl;
    }
};

int Mamifer::nrMamifere = 0;

class Medicament {
public:
    const int codProdus;
    static int nrMedicamente;
    char* denumire;
    float pret;

    Medicament() : codProdus(nrMedicamente++) {
        this->pret = 0;
        this->denumire = new char[strlen("Generic") + 1];
        strcpy_s(this->denumire, strlen("Generic") + 1, "Generic");
    }

    Medicament(const char* denumire) : codProdus(nrMedicamente++) {
        this->pret = 0;
        this->denumire = new char[strlen(denumire) + 1];
        strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
    }

    Medicament(const char* denumire, float pret) : codProdus(nrMedicamente++) {
        this->pret = pret;
        this->denumire = new char[strlen(denumire) + 1];
        strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
    }

    ~Medicament() {
        delete[] denumire;
    }

    static float calculeazaTVA(float pret) {
        return pret * 0.19f;
    }
};

int Medicament::nrMedicamente = 0;

int main() {
    Animal a1;
    Animal a2("Pisica");
    Animal a3("Caine", 4);
    cout << "Numar animale create: ";
    Animal::afisareNrAnimale();

    Mamifer m1;
    Mamifer m2("Urs");
    Mamifer m3("Delfin", 180.5f);
    cout << "Numar mamifere create: ";
    Mamifer::afisareNrMamifere();

    Medicament md1;
    Medicament md2("Antibiotic");
    Medicament md3("Antiparazitar", 49.99f);
    cout << "TVA pentru medicamentul de 49.99 lei: "
        << Medicament::calculeazaTVA(49.99f) << endl;
    
    return 0;
}
