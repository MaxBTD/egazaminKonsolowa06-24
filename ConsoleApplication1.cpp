#include <iostream>
using namespace std;

int zliczaniePunktow(int liczbaKoste, int wylosLiczb[]);

int main()
{
    string dalejGrac = "t";
    srand(time(0));
    int liczbaKostek = 0;

    while (liczbaKostek < 3 || liczbaKostek > 10) {
        cout << "Ile kostek chcesz rzucic?(3 - 10)\n";
        cin >> liczbaKostek;
    }

    while (dalejGrac == "t") {
        dalejGrac = "";
        int wylosLiczb[10];

        for (int i = 0; i < liczbaKostek; i++) {
            int rzutKostka = 0;
            while (rzutKostka < 1 || rzutKostka > 6) {
                rzutKostka = rand();
            }
            wylosLiczb[i] = rzutKostka;
            cout << "Kostka nr " << i + 1 << ": " << rzutKostka << "\n";
        }

        cout << "Liczba uzyskanych punktow: " << zliczaniePunktow(liczbaKostek, wylosLiczb) << "\n";
        while (dalejGrac != "t" && dalejGrac != "n") {
            cout << "Jeszcze raz? (t/n) \n";
            cin >> dalejGrac;
        }
    }
}

int zliczaniePunktow(int liczbaKostek, int wylosLiczb[]) {
    int wynik = 0;
    for (int i = 0; i < liczbaKostek; i++) {
        int sprawLiczb = wylosLiczb[i];
        int ileRazy = 1;
        if (i < 10) {
            for (int j = i + 1; j < liczbaKostek; j++) {
                if (sprawLiczb == wylosLiczb[j]) {
                    ileRazy++;
                    wylosLiczb[j] = 0;
                }
            }
            if (ileRazy > 1)
                wynik += sprawLiczb * ileRazy;
        }
    }

    return wynik;
}