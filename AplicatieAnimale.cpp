#include <iostream>
#include <cstring>
using namespace std;

class Animal {
private:
    const int id;
    static int nrAnimale;
    char* nume;
    int varsta;

public:
    Animal() : id(nrAnimale++) {
        varsta = 0;
        nume = new char[strlen("Necunoscut") + 1];
        strcpy_s(nume, strlen("Necunoscut") + 1, "Necunoscut");
    }

    Animal(const char* n) : id(nrAnimale++) {
        varsta = 0;
        nume = new char[strlen(n) + 1];
        strcpy_s(nume, strlen(n) + 1, n);
    }

    Animal(const char* n, int v) : id(nrAnimale++) {
        varsta = v;
        nume = new char[strlen(n) + 1];
        strcpy_s(nume, strlen(n) + 1, n);
    }

    Animal(const Animal& a) : id(a.id) {
        varsta = a.varsta;
        nume = new char[strlen(a.nume) + 1];
        strcpy_s(nume, strlen(a.nume) + 1, a.nume);
    }

    ~Animal() {
        delete[] nume;
    }

    const char* getNume() { return nume; }
    int getVarsta() { return varsta; }
    int getId() { return id; }
    static int getNrAnimale() { return nrAnimale; }

    void setNume(const char* n) {
        delete[] nume;
        nume = new char[strlen(n) + 1];
        strcpy_s(nume, strlen(n) + 1, n);
    }

    void setVarsta(int v) { varsta = v; }

    friend void functie1(Animal&);
};

int Animal::nrAnimale = 0;



class Mamifer {
private:
    const int cod;
    static int nrMamifere;
    char* specie;
    float greutate;

public:
    Mamifer() : cod(nrMamifere++) {
        greutate = 0;
        specie = new char[strlen("Necunoscuta") + 1];
        strcpy_s(specie, strlen("Necunoscuta") + 1, "Necunoscuta");
    }

    Mamifer(const char* s) : cod(nrMamifere++) {
        greutate = 0;
        specie = new char[strlen(s) + 1];
        strcpy_s(specie, strlen(s) + 1, s);
    }

    Mamifer(const char* s, float g) : cod(nrMamifere++) {
        greutate = g;
        specie = new char[strlen(s) + 1];
        strcpy_s(specie, strlen(s) + 1, s);
    }

    Mamifer(const Mamifer& m) : cod(m.cod) {
        greutate = m.greutate;
        specie = new char[strlen(m.specie) + 1];
        strcpy_s(specie, strlen(m.specie) + 1, m.specie);
    }

    ~Mamifer() {
        delete[] specie;
    }

    const char* getSpecie() { return specie; }
    float getGreutate() { return greutate; }
    int getCod() { return cod; }
    static int getNrMamifere() { return nrMamifere; }

    void setSpecie(const char* s) {
        delete[] specie;
        specie = new char[strlen(s) + 1];
        strcpy_s(specie, strlen(s) + 1, s);
    }

    void setGreutate(float g) { greutate = g; }

    friend void functie2(Mamifer&);
};

int Mamifer::nrMamifere = 0;



class Medicament {
private:
    const int codProdus;
    static int nrMedicamente;
    char* denumire;
    float pret;

public:
    Medicament() : codProdus(nrMedicamente++) {
        pret = 0;
        denumire = new char[strlen("Generic") + 1];
        strcpy_s(denumire, strlen("Generic") + 1, "Generic");
    }

    Medicament(const char* d) : codProdus(nrMedicamente++) {
        pret = 0;
        denumire = new char[strlen(d) + 1];
        strcpy_s(denumire, strlen(d) + 1, d);
    }

    Medicament(const char* d, float p) : codProdus(nrMedicamente++) {
        pret = p;
        denumire = new char[strlen(d) + 1];
        strcpy_s(denumire, strlen(d) + 1, d);
    }

    Medicament(const Medicament& md) : codProdus(md.codProdus) {
        pret = md.pret;
        denumire = new char[strlen(md.denumire) + 1];
        strcpy_s(denumire, strlen(md.denumire) + 1, md.denumire);
    }

    ~Medicament() {
        delete[] denumire;
    }

    const char* getDenumire() { return denumire; }
    float getPret() { return pret; }
    int getCodProdus() { return codProdus; }
    static int getNrMedicamente() { return nrMedicamente; }

    void setDenumire(const char* d) {
        delete[] denumire;
        denumire = new char[strlen(d) + 1];
        strcpy_s(denumire, strlen(d) + 1, d);
    }

    void setPret(float p) { pret = p; }

    static float calculeazaTVA(float p) { return p * 0.19f; }
};

int Medicament::nrMedicamente = 0;



void functie1(Animal& a) {
    a.varsta += 2;
}

void functie2(Mamifer& m) {
    m.greutate += 5;
}



int main() {
    Animal a1;
    Animal a2("Pisica");
    Animal a3("Caine", 4);

    functie1(a2);

    cout << "Animal 1: " << a1.getNume() << ", varsta " << a1.getVarsta() << ", id " << a1.getId() << endl;
    cout << "Animal 2: " << a2.getNume() << ", varsta " << a2.getVarsta() << ", id " << a2.getId() << endl;
    cout << "Animal 3: " << a3.getNume() << ", varsta " << a3.getVarsta() << ", id " << a3.getId() << endl;

    cout << "Total animale: " << Animal::getNrAnimale() << endl << endl;

    Mamifer m1;
    Mamifer m2("Urs");
    Mamifer m3("Delfin", 180.5f);

    functie2(m3);

    cout << "Mamifer 1: " << m1.getSpecie() << ", greutate " << m1.getGreutate() << ", cod " << m1.getCod() << endl;
    cout << "Mamifer 2: " << m2.getSpecie() << ", greutate " << m2.getGreutate() << ", cod " << m2.getCod() << endl;
    cout << "Mamifer 3: " << m3.getSpecie() << ", greutate " << m3.getGreutate() << ", cod " << m3.getCod() << endl;

    cout << "Total mamifere: " << Mamifer::getNrMamifere() << endl << endl;

    Medicament md1;
    Medicament md2("Antibiotic");
    Medicament md3("Antiparazitar", 49.99f);

    cout << "Medicament 1: " << md1.getDenumire() << ", pret " << md1.getPret() << endl;
    cout << "Medicament 2: " << md2.getDenumire() << ", pret " << md2.getPret() << endl;
    cout << "Medicament 3: " << md3.getDenumire() << ", pret " << md3.getPret() << endl;

    cout << "Total medicamente: " << Medicament::getNrMedicamente() << endl;

    cout << "TVA pentru 49.99 este: " << Medicament::calculeazaTVA(49.99f) << endl;

    return 0;
}
