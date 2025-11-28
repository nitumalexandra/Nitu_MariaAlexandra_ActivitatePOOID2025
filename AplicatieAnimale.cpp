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
        nume = new char[strlen("Necunoscut")+1];
        strcpy_s(nume, strlen("Necunoscut")+1, "Necunoscut");
    }

    Animal(const char* n) : id(nrAnimale++) {
        varsta = 0;
        nume = new char[strlen(n)+1];
        strcpy_s(nume, strlen(n)+1, n);
    }

    Animal(const char* n, int v) : id(nrAnimale++) {
        varsta = v;
        nume = new char[strlen(n)+1];
        strcpy_s(nume, strlen(n)+1, n);
    }

    Animal(const Animal& a) : id(a.id) {
        varsta = a.varsta;
        nume = new char[strlen(a.nume)+1];
        strcpy_s(nume, strlen(a.nume)+1, a.nume);
    }

    Animal& operator=(const Animal& a) {
        if (this != &a) {
            delete[] nume;
            varsta = a.varsta;
            nume = new char[strlen(a.nume)+1];
            strcpy_s(nume, strlen(a.nume)+1, a.nume);
        }
        return *this;
    }

    Animal operator+(int x) {
        Animal temp(*this);
        temp.varsta += x;
        return temp;
    }

    bool operator==(const Animal& a) {
        return strcmp(nume, a.nume) == 0;
    }

    friend ostream& operator<<(ostream& out, const Animal& a) {
        out << a.nume << " (" << a.varsta << " ani)";
        return out;
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
        nume = new char[strlen(n)+1];
        strcpy_s(nume, strlen(n)+1, n);
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
        specie = new char[strlen("Necunoscuta")+1];
        strcpy_s(specie, strlen("Necunoscuta")+1, "Necunoscuta");
    }

    Mamifer(const char* s) : cod(nrMamifere++) {
        greutate = 0;
        specie = new char[strlen(s)+1];
        strcpy_s(specie, strlen(s)+1, s);
    }

    Mamifer(const char* s, float g) : cod(nrMamifere++) {
        greutate = g;
        specie = new char[strlen(s)+1];
        strcpy_s(specie, strlen(s)+1, s);
    }

    Mamifer(const Mamifer& m) : cod(m.cod) {
        greutate = m.greutate;
        specie = new char[strlen(m.specie)+1];
        strcpy_s(specie, strlen(m.specie)+1, m.specie);
    }

    Mamifer& operator=(const Mamifer& m) {
        if (this != &m) {
            delete[] specie;
            greutate = m.greutate;
            specie = new char[strlen(m.specie)+1];
            strcpy_s(specie, strlen(m.specie)+1, m.specie);
        }
        return *this;
    }

    Mamifer operator+(float g) {
        Mamifer temp(*this);
        temp.greutate += g;
        return temp;
    }

    bool operator==(const Mamifer& m) {
        return strcmp(specie, m.specie) == 0;
    }

    friend ostream& operator<<(ostream& out, const Mamifer& m) {
        out << m.specie << " (" << m.greutate << " kg)";
        return out;
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
        specie = new char[strlen(s)+1];
        strcpy_s(specie, strlen(s)+1, s);
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
        denumire = new char[strlen("Generic")+1];
        strcpy_s(denumire, strlen("Generic")+1, "Generic");
    }

    Medicament(const char* d) : codProdus(nrMedicamente++) {
        pret = 0;
        denumire = new char[strlen(d)+1];
        strcpy_s(denumire, strlen(d)+1, d);
    }

    Medicament(const char* d, float p) : codProdus(nrMedicamente++) {
        pret = p;
        denumire = new char[strlen(d)+1];
        strcpy_s(denumire, strlen(d)+1, d);
    }

    Medicament(const Medicament& md) : codProdus(md.codProdus) {
        pret = md.pret;
        denumire = new char[strlen(md.denumire)+1];
        strcpy_s(denumire, strlen(md.denumire)+1, md.denumire);
    }

    Medicament& operator=(const Medicament& md) {
        if (this != &md) {
            delete[] denumire;
            pret = md.pret;
            denumire = new char[strlen(md.denumire)+1];
            strcpy_s(denumire, strlen(md.denumire)+1, md.denumire);
        }
        return *this;
    }

    Medicament operator+(float p) {
        Medicament temp(*this);
        temp.pret += p;
        return temp;
    }

    bool operator==(const Medicament& md) {
        return strcmp(denumire, md.denumire) == 0;
    }

    friend ostream& operator<<(ostream& out, const Medicament& md) {
        out << md.denumire << " (" << md.pret << " lei)";
        return out;
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
        denumire = new char[strlen(d)+1];
        strcpy_s(denumire, strlen(d)+1, d);
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

    cout << "ANIMALE:" << endl;

    Animal a1;
    Animal a2("Pisica");
    functie1(a2);
    Animal a3("Caine", 4);

    Animal a4 = a2;
    Animal a5;
    a5 = a3;
    Animal a6 = a1 + 3;
    bool eqA = (a2 == a4);

    cout << "Animal 1: " << a1.getNume() << ", varsta " << a1.getVarsta() << ", id " << a1.getId() << endl;
    cout << "Animal 2: " << a2.getNume() << ", varsta " << a2.getVarsta() << ", id " << a2.getId() << endl;
    cout << "Animal 3: " << a3.getNume() << ", varsta " << a3.getVarsta() << ", id " << a3.getId() << endl;

    cout << "Copia Animal 2 -> Animal 4: " << a4.getNume() << ", varsta " << a4.getVarsta() << ", id " << a4.getId() << endl;
    cout << "Animal 5 = Animal 3: " << a5.getNume() << ", varsta " << a5.getVarsta() << ", id " << a5.getId() << endl;
    cout << "Animal 6 = Animal 1 + 3 ani: " << a6.getNume() << ", varsta " << a6.getVarsta() << ", id " << a6.getId() << endl;

    cout << "Animal 2 = Animal 4: " << eqA << endl;
    cout << "Total animale create: " << Animal::getNrAnimale() << endl << endl;

    cout << "MAMIFERE:" << endl;

    Mamifer m1;
    Mamifer m2("Urs");
    Mamifer m3("Delfin", 180.5f);
    functie2(m3);

    Mamifer m4 = m2;
    Mamifer m5;
    m5 = m3;
    Mamifer m6 = m3 + 10;
    bool eqM = (m2 == m4);

    cout << "Mamifer 1: " << m1.getSpecie() << ", greutate " << m1.getGreutate() << ", cod " << m1.getCod() << endl;
    cout << "Mamifer 2: " << m2.getSpecie() << ", greutate " << m2.getGreutate() << ", cod " << m2.getCod() << endl;
    cout << "Mamifer 3: " << m3.getSpecie() << ", greutate " << m3.getGreutate() << ", cod " << m3.getCod() << endl;

    cout << "Copia Mamifer 2 -> Mamifer 4: " << m4.getSpecie() << ", greutate " << m4.getGreutate() << ", cod " << m4.getCod() << endl;
    cout << "Mamifer 5 = Mamifer 3: " << m5.getSpecie() << ", greutate " << m5.getGreutate() << ", cod " << m5.getCod() << endl;
    cout << "Mamifer 6 = Mamifer 3 + 10 kg: " << m6.getSpecie() << ", greutate " << m6.getGreutate() << ", cod " << m6.getCod() << endl;

    cout << "Mamifer 2 = Mamifer 4: " << eqM << endl;
    cout << "Total mamifere create: " << Mamifer::getNrMamifere() << endl << endl;



    cout << "MEDICAMENTE:" << endl;

    Medicament md1;
    Medicament md2("Antibiotic");
    Medicament md3("Antiparazitar", 49.99f);

    Medicament md4 = md2;
    Medicament md5;
    md5 = md3;
    Medicament md6 = md3 + 20;
    bool eqMd = (md2 == md4);

    cout << "Medicament 1: " << md1.getDenumire() << ", pret " << md1.getPret() << endl;
    cout << "Medicament 2: " << md2.getDenumire() << ", pret " << md2.getPret() << endl;
    cout << "Medicament 3: " << md3.getDenumire() << ", pret " << md3.getPret() << endl;

    cout << "Copia Medicament 2 -> Medicament 4: " << md4.getDenumire() << ", pret " << md4.getPret() << endl;
    cout << "Medicament 5 = Medicament 3: " << md5.getDenumire() << ", pret " << md5.getPret() << endl;
    cout << "Medicament 6 = Medicament 3 + 20 lei: " << md6.getDenumire() << ", pret " << md6.getPret() << endl;

    cout << "Medicament 2 = Medicament 4: " << eqMd << endl;
    cout << "Total medicamente create: " << Medicament::getNrMedicamente() << endl;

    cout << "TVA pentru 49.99 este: " << Medicament::calculeazaTVA(49.99f) << endl;

    return 0;
}
