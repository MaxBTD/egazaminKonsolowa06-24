int zliczaniePunktow(int liczbaKostek, int[] wylosLiczb){
    int wynik = 0;
    for(int i = 0; i < liczbaKostek; i++)
    {
        int sprawLiczb = wylosLiczb[i];
        int ileRazy = 1;
        if (i < 10)
        {
            for(int j = i + 1; j < liczbaKostek; j++)
            {
                if(sprawLiczb == wylosLiczb[j])
                {
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

string dalejGrac = "t";
Random random = new Random();
int liczbaKostek = 0;

while(liczbaKostek < 3 || liczbaKostek > 10)
{
    Console.WriteLine("Ile kostek chcerz rzucic?(3 - 10)");
    int.TryParse(Console.ReadLine(), out liczbaKostek);
}

while(dalejGrac == "t")
{
    dalejGrac = "";
    int[] wylosLiczb = new int[liczbaKostek];

    for(int i = 0; i < liczbaKostek; i++)
    {
        wylosLiczb[i] = random.Next(1, 7);
        Console.WriteLine($"Kostka nr {i + 1}: {wylosLiczb[i]}\n");
    }
    Console.WriteLine($"Liczba uzyskanych punktow: {zliczaniePunktow(liczbaKostek, wylosLiczb)}");
    while (dalejGrac != "t" && dalejGrac != "n")
    {
        Console.WriteLine("Jeszcze raz? (t/n) \n");
        dalejGrac = Console.ReadLine();
    }
}