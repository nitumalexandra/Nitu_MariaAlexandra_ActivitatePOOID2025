#include <iostream>
#include <cstring>
#include <fstream>
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

    Animal& operator=(const Animal& a) {
        if (this != &a) {
            delete[] nume;
            varsta = a.varsta;
            nume = new char[strlen(a.nume) + 1];
            strcpy_s(nume, strlen(a.nume) + 1, a.nume);
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

    const char* getNume() const { return nume; }
    int getVarsta() const { return varsta; }
    int getId() const { return id; }
    static int getNrAnimale() { return nrAnimale; }

    void setNume(const char* n) {
        delete[] nume;
        nume = new char[strlen(n) + 1];
        strcpy_s(nume, strlen(n) + 1, n);
    }

    void setVarsta(int v) { varsta = v; }

    friend void functie1(Animal&);

    void scrieInFisierText(const char* numeFisier) const {
        ofstream f(numeFisier, ios::app);
        f << nume << " " << varsta << " " << id << "\n";
        f.close();
    }
};

int Animal::nrAnimale = 0;

class AnimalSalbatic : public Animal {
private:
    char* habitat;
    bool periculos;

public:
    AnimalSalbatic() : Animal() {
        habitat = new char[strlen("Necunoscut") + 1];
        strcpy_s(habitat, strlen("Necunoscut") + 1, "Necunoscut");
        periculos = false;
    }

    AnimalSalbatic(const char* nume, int varsta, const char* hab, bool per)
        : Animal(nume, varsta) {
        habitat = new char[strlen(hab) + 1];
        strcpy_s(habitat, strlen(hab) + 1, hab);
        periculos = per;
    }

    AnimalSalbatic(const AnimalSalbatic& a) : Animal(a) {
        habitat = new char[strlen(a.habitat) + 1];
        strcpy_s(habitat, strlen(a.habitat) + 1, a.habitat);
        periculos = a.periculos;
    }

    AnimalSalbatic& operator=(const AnimalSalbatic& a) {
        if (this != &a) {
            Animal::operator=(a);
            delete[] habitat;

            habitat = new char[strlen(a.habitat) + 1];
            strcpy_s(habitat, strlen(a.habitat) + 1, a.habitat);
            periculos = a.periculos;
        }
        return *this;
    }

    ~AnimalSalbatic() {
        delete[] habitat;
    }

    const char* getHabitat() const { return habitat; }
    bool estePericulos() const { return periculos; }

    void setHabitat(const char* h) {
        delete[] habitat;
        habitat = new char[strlen(h) + 1];
        strcpy_s(habitat, strlen(h) + 1, h);
    }

    void setPericulos(bool p) { periculos = p; }

    friend ostream& operator<<(ostream& out, const AnimalSalbatic& a) {
        out << (Animal&)a << ", habitat " << a.habitat << ", periculos: " << a.periculos;
        return out;
    }
};


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

    Mamifer& operator=(const Mamifer& m) {
        if (this != &m) {
            delete[] specie;
            greutate = m.greutate;
            specie = new char[strlen(m.specie) + 1];
            strcpy_s(specie, strlen(m.specie) + 1, m.specie);
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

    const char* getSpecie() const { return specie; }
    float getGreutate() const { return greutate; }
    int getCod() const { return cod; }
    static int getNrMamifere() { return nrMamifere; }

    void setSpecie(const char* s) {
        delete[] specie;
        specie = new char[strlen(s) + 1];
        strcpy_s(specie, strlen(s) + 1, s);
    }

    void setGreutate(float g) { greutate = g; }

    friend void functie2(Mamifer&);

    void scrieInFisierBinar(const char* numeFisier) const {
        ofstream f(numeFisier, ios::binary | ios::app);

        int len = strlen(specie);
        f.write((char*)&len, sizeof(len));
        f.write(specie, len);

        f.write((char*)&greutate, sizeof(greutate));
        f.write((char*)&cod, sizeof(cod));

        f.close();
    }
};

int Mamifer::nrMamifere = 0;

class MamiferDomestic : public Mamifer {
private:
    char* numeStapan;
    bool vaccinant;

public:
    MamiferDomestic() : Mamifer() {
        numeStapan = new char[strlen("Anonim") + 1];
        strcpy_s(numeStapan, strlen("Anonim") + 1, "Anonim");
        vaccinant = false;
    }

    MamiferDomestic(const char* specie, float greutate, const char* stapan, bool vac)
        : Mamifer(specie, greutate) {
        numeStapan = new char[strlen(stapan) + 1];
        strcpy_s(numeStapan, strlen(stapan) + 1, stapan);
        vaccinant = vac;
    }

    MamiferDomestic(const MamiferDomestic& m) : Mamifer(m) {
        numeStapan = new char[strlen(m.numeStapan) + 1];
        strcpy_s(numeStapan, strlen(m.numeStapan) + 1, m.numeStapan);
        vaccinant = m.vaccinant;
    }

    MamiferDomestic& operator=(const MamiferDomestic& m) {
        if (this != &m) {
            Mamifer::operator=(m);
            delete[] numeStapan;

            numeStapan = new char[strlen(m.numeStapan) + 1];
            strcpy_s(numeStapan, strlen(m.numeStapan) + 1, m.numeStapan);
            vaccinant = m.vaccinant;
        }
        return *this;
    }

    ~MamiferDomestic() {
        delete[] numeStapan;
    }

    const char* getStapan() const { return numeStapan; }
    bool esteVaccinant() const { return vaccinant; }

    void setStapan(const char* s) {
        delete[] numeStapan;
        numeStapan = new char[strlen(s) + 1];
        strcpy_s(numeStapan, strlen(s) + 1, s);
    }

    void setVaccinant(bool v) { vaccinant = v; }

    friend ostream& operator<<(ostream& out, const MamiferDomestic& m) {
        out << (Mamifer&)m << ", stapan " << m.numeStapan << ", vaccinat: " << m.vaccinant;
        return out;
    }
};


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

    Medicament& operator=(const Medicament& md) {
        if (this != &md) {
            delete[] denumire;
            pret = md.pret;
            denumire = new char[strlen(md.denumire) + 1];
            strcpy_s(denumire, strlen(md.denumire) + 1, md.denumire);
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

    const char* getDenumire() const { return denumire; }
    float getPret() const { return pret; }
    int getCodProdus() const { return codProdus; }
    static int getNrMedicamente() { return nrMedicamente; }

    void setDenumire(const char* d) {
        delete[] denumire;
        denumire = new char[strlen(d) + 1];
        strcpy_s(denumire, strlen(d) + 1, d);
    }

    void setPret(float p) { pret = p; }

    static float calculeazaTVA(float p) { return p * 0.19f; }

    void scrieInFisierText(const char* numeFisier) const {
        ofstream f(numeFisier, ios::app);
        f << denumire << " " << pret << "\n";
        f.close();
    }
};



class CabinetVeterinar {
private:
    Animal pacient;
    Medicament* medicamente;
    int nrMedicamente;
    char* numeCabinet;

public:
    CabinetVeterinar() : pacient() {
        numeCabinet = new char[strlen("Cabinet") + 1];
        strcpy_s(numeCabinet, strlen("Cabinet") + 1, "Cabinet");
        medicamente = nullptr;
        nrMedicamente = 0;
    }

    CabinetVeterinar(const char* nume, const Animal& a, int n, Medicament* meds) : pacient(a) {
        numeCabinet = new char[strlen(nume) + 1];
        strcpy_s(numeCabinet, strlen(nume) + 1, nume);

        nrMedicamente = n;
        medicamente = new Medicament[n];
        for (int i = 0; i < n; i++)
            medicamente[i] = meds[i];
    }

    CabinetVeterinar(const CabinetVeterinar& c) : pacient(c.pacient) {
        numeCabinet = new char[strlen(c.numeCabinet) + 1];
        strcpy_s(numeCabinet, strlen(c.numeCabinet) + 1, c.numeCabinet);

        nrMedicamente = c.nrMedicamente;
        medicamente = new Medicament[nrMedicamente];
        for (int i = 0; i < nrMedicamente; i++)
            medicamente[i] = c.medicamente[i];
    }

    CabinetVeterinar& operator=(const CabinetVeterinar& c) {
        if (this != &c) {
            delete[] numeCabinet;
            delete[] medicamente;

            pacient = c.pacient;

            numeCabinet = new char[strlen(c.numeCabinet) + 1];
            strcpy_s(numeCabinet, strlen(c.numeCabinet) + 1, c.numeCabinet);

            nrMedicamente = c.nrMedicamente;
            medicamente = new Medicament[nrMedicamente];
            for (int i = 0; i < nrMedicamente; i++)
                medicamente[i] = c.medicamente[i];
        }
        return *this;
    }

    ~CabinetVeterinar() {
        delete[] numeCabinet;
        delete[] medicamente;
    }

    CabinetVeterinar& operator+=(const Medicament& m) {
        Medicament* nou = new Medicament[nrMedicamente + 1];
        for (int i = 0; i < nrMedicamente; i++)
            nou[i] = medicamente[i];
        nou[nrMedicamente] = m;

        delete[] medicamente;
        medicamente = nou;
        nrMedicamente++;

        return *this;
    }

    Medicament operator[](int index) {
        if (index >= 0 && index < nrMedicamente)
            return medicamente[index];
        return Medicament();
    }

    friend ostream& operator<<(ostream& out, const CabinetVeterinar& c) {
        out << "Cabinet: " << c.numeCabinet << endl;
        out << "Pacient: " << c.pacient.getNume()
            << ", varsta " << c.pacient.getVarsta() << endl;
        out << "Medicamente prescrise: " << c.nrMedicamente << endl;
        for (int i = 0; i < c.nrMedicamente; i++)
            out << " - " << c.medicamente[i].getDenumire()
            << " (" << c.medicamente[i].getPret() << " lei)" << endl;
        return out;
    }

    void scrieInFisierBinar(const char* numeFisier) const {
        ofstream f(numeFisier, ios::binary | ios::app);

        int len = strlen(numeCabinet);
        f.write((char*)&len, sizeof(len));
        f.write(numeCabinet, len);

        f.write((char*)&nrMedicamente, sizeof(nrMedicamente));

        for (int i = 0; i < nrMedicamente; i++) {
            int l = strlen(medicamente[i].getDenumire());
            f.write((char*)&l, sizeof(l));
            f.write(medicamente[i].getDenumire(), l);

            float p = medicamente[i].getPret();
            f.write((char*)&p, sizeof(p));
        }

        f.close();
    }
};

int Medicament::nrMedicamente = 0;



void functie1(Animal& a) { a.varsta += 2; }
void functie2(Mamifer& m) { m.greutate += 5; }




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

    cout << "TVA pentru 49.99 este: " << Medicament::calculeazaTVA(49.99f) << endl << endl;

    cout << endl << "CLASE DERIVATE:" << endl;

    AnimalSalbatic as1("Lup", 5, "Padure", true);
    AnimalSalbatic as2;

    MamiferDomestic mdDom1("Caine", 12.3f, "Ion", true);
    MamiferDomestic mdDom2;

    cout << "Animal salbatic 1: " << as1 << endl;
    cout << "Mamifer domestic 1: " << mdDom1 << endl;

    Animal* pa = &as1;
    Mamifer* pm = &mdDom1;

    cout << "Upcasting Animal*: " << *pa << endl;
    cout << "Upcasting Mamifer*: " << *pm << endl;

    a1.scrieInFisierText("animale.txt");
    md1.scrieInFisierText("medicamente.txt");

    m1.scrieInFisierBinar("mamifere.bin");

    int nA;
    cout << "Nr animale vector: ";
    cin >> nA;

    Animal* vectA = new Animal[nA];
    for (int i = 0; i < nA; i++) {
        char nume[50];
        int v;
        cout << "Nume animal " << i + 1 << ": ";
        cin >> nume;
        cout << "Varsta: ";
        cin >> v;
        vectA[i].setNume(nume);
        vectA[i].setVarsta(v);
    }

    cout << endl << "Afisare animale vector:" << endl;
    for (int i = 0; i < nA; i++) {
        cout << vectA[i] << endl;
    }


    int nM;
    cout << endl << "Nr mamifere vector: ";
    cin >> nM;

    Mamifer* vectM = new Mamifer[nM];
    for (int i = 0; i < nM; i++) {
        char specie[50];
        float g;
        cout << "Specie mamifer " << i + 1 << ": ";
        cin >> specie;
        cout << "Greutate: ";
        cin >> g;
        vectM[i].setSpecie(specie);
        vectM[i].setGreutate(g);
    }

    cout << endl << "Afisare mamifere vector:" << endl;
    for (int i = 0; i < nM; i++) {
        cout << vectM[i] << endl;
    }


    int nD;
    cout << endl << "Nr medicamente vector: ";
    cin >> nD;

    Medicament* vectD = new Medicament[nD];
    for (int i = 0; i < nD; i++) {
        char den[50];
        float p;
        cout << "Denumire medicament " << i + 1 << ": ";
        cin >> den;
        cout << "Pret: ";
        cin >> p;
        vectD[i].setDenumire(den);
        vectD[i].setPret(p);
    }

    cout << endl << "Afisare medicamente vector:" << endl;
    for (int i = 0; i < nD; i++) {
        cout << vectD[i] << endl;
    }



    int r, c;
    cout << endl << "Nr linii matrice animale: ";
    cin >> r;
    cout << "Nr coloane matrice animale: ";
    cin >> c;

    Animal** matrice = new Animal * [r];
    for (int i = 0; i < r; i++)
        matrice[i] = new Animal[c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char nume[50];
            int v;
            cout << "Matrice animal [" << i << "][" << j << "] nume: ";
            cin >> nume;
            cout << "Varsta: ";
            cin >> v;
            matrice[i][j].setNume(nume);
            matrice[i][j].setVarsta(v);
        }
    }

    cout << endl << "Afisare matrice animale:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << matrice[i][j] << " | ";
        }
        cout << endl;
    }

    for (int i = 0; i < r; i++)
        delete[] matrice[i];
    delete[] matrice;



    delete[] vectA;
    delete[] vectM;
    delete[] vectD;

    cout << endl << "CABINET VETERINAR:" << endl;

    Medicament lista[2] = { Medicament("Antibiotic", 40), Medicament("Calciu", 20) };

    CabinetVeterinar cab("VetPlus", a2, 2, lista);

    cout << cab << endl;

    cout << "Adaug un medicament nou..." << endl;
    Medicament mNou("Vitamine", 35);
    cab += mNou;

    cout << cab << endl;

    cab.scrieInFisierBinar("cabinet.bin");

    cout << "Acces medicamentul 1: " << cab[1] << endl ;

    return 0;
}
