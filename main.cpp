#include <iostream>
#include <vector>

using namespace std;

class film
{
public:
    film(std::string denumire, string gen, string regizor, float rating);
    film(const film&);
    film();

    std::string getDenumire();
    void setDenumire(std::string);
    std::string getGen();
    void setGen(std::string);
    std::string getRegizor();
    void setRegizor(std::string);
    float getRating();
    void setRating(float);

    friend istream& operator>>(istream&, film&);
    friend ostream& operator<<(ostream&, film&);

    bool operator==(film&);
    bool operator>(film&);
    bool operator<(film&);
    bool operator>=(int);
    bool operator<(int);

    friend class cinema;
private:
    string denumire;
    string gen;
    string regizor;
    float rating;
};

class cinema
{
public:
    string getDenumire();
    void setDenumire(string);
    unsigned int getPret_bilet();
    void setPret_bilet(unsigned int);

    friend istream& operator>>(istream&, cinema&);
    friend ostream& operator<<(ostream&, cinema&);

    cinema operator+(int);
    cinema operator-(int);

    void adauga_film(film& f);
    void sortare_filme();
    void afiseaza_film();
private:
    string denumire;
    unsigned int pret_bilet;
    vector<film> filme_cinema;
};

void cinema::adauga_film(film& f)
{
    filme_cinema.push_back(f);
}

void cinema::sortare_filme()
{
    if(filme_cinema[0].rating > filme_cinema[1].rating)
        swap(filme_cinema[0], filme_cinema[1]);
    if(filme_cinema[0].rating > filme_cinema[2].rating)
        swap(filme_cinema[0], filme_cinema[2]);
    if(filme_cinema[1].rating > filme_cinema[2].rating)
        swap(filme_cinema[1], filme_cinema[2]);
}

void cinema::afiseaza_film()
{
    cout <<"\n";
    cout << "Toate filmele sunt(aranjate dupa rating):"<<"\n";
    cout << filme_cinema[0];
    cout << filme_cinema[1];
    cout << filme_cinema[2];
}

film::film(std::string denumire, string gen, string regizor, float rating)
{
    this->denumire = denumire;
    this->gen = gen;
    this->regizor = regizor;
    this->rating = rating;
}

film::film(const film& film)
{
    denumire = film.denumire;
    gen = film.gen;
    regizor = film.regizor;
    rating = film.rating;
}

film::film(){}

std::string film::getDenumire()
{
    return this->denumire;
}

void film::setDenumire(std::string denumire)
{
    this->denumire = denumire;
}

std::string film::getGen()
{
    return this->gen;
}

void film::setGen(std::string gen)
{
    this->gen = gen;
}

std::string film::getRegizor()
{
    return this->regizor;
}

void film::setRegizor(std::string regizor)
{
    this->regizor = regizor;
}

float film::getRating()
{
    return this->rating;
}

void film::setRating(float rating)
{
    this->rating = rating;
}

string cinema::getDenumire()
{
    return this->denumire;
}

void cinema::setDenumire(string denumire)
{
    this->denumire = denumire;
}

unsigned int cinema::getPret_bilet()
{
    return this->pret_bilet;
}

void cinema::setPret_bilet(unsigned int pret_bilet)
{
    this->pret_bilet = pret_bilet;
}

istream& operator>>(istream& in, film& f)
{
    in>>f.denumire>>f.gen>>f.regizor>>f.rating;
    return in;
}

ostream& operator<<(ostream& out, film& f)
{
    out<<f.denumire<<' '<<f.gen<<' '<<f.regizor<<' '<<f.rating<<"\n";
    return out;
}

istream& operator>>(istream& in, cinema& c)
{
    in>>c.denumire;
    return in;
}

ostream& operator<<(ostream& out, cinema& c)
{
    out<<c.pret_bilet<<"\n";
    return out;
}

bool film::operator==(film& f2)
{
    return (this->denumire == f2.denumire && this->gen == f2.gen && this->regizor == f2.regizor && this->rating == f2.rating);
}

bool film::operator>(film& f2)
{
    return (this->rating > f2.rating);
}

bool film::operator<(film& f2)
{
    return (this->rating < f2.rating);
}

bool film::operator>=(int x)
{
    return(this->rating >= 8);
}

bool film::operator<(int x)
{
    return(this->rating < 8);
}

cinema cinema::operator+(int x)
{
    cinema a;
    a.pret_bilet = 30;
    return a;
}

cinema cinema::operator-(int x)
{
    cinema a;
    a.pret_bilet = 20;
    return a;
}

int main()
{
    film f1, f2, f3;
    cinema c1;
    cin>>f1>>f2;
    cout<<f1<<f2;

    if(f1 >= 8) // daca rating >= 8, pret_bilet = 30
        {
            c1 = c1 + 10;
            cout << f1 << "este un film cu incasari mari.\n";
            cout << "pretul biletului este "<< c1;
        }
    else if(f1 < 8) // daca rating < 8, pret_bilet = 20
    {
        c1 = c1 - 10;
        cout << f1 << "este un film cu incasari mici.\n";
        cout << "pretul biletului este "<< c1;
    }

    cout<<"\n";
    if(f1 == f2)
        cout<<"Primele doua filme sunt la fel.";
    else if(f1>f2)
        cout<<"Primul film este mai bun, conform IMDB.";
    else if(f1<f2)
        cout<<"Al doilea film este mai bun, conform IMDB.";

    f3 = film("Titanic", "romance", "James_Cameron", 7.9);
    cout << "\n";
    cout << "Pentru filmul 3:" << "\n";
    cout << "Numele filmului: " << f3.getDenumire() << "\n";
    cout << "Genul filmului: " << f3.getGen() << "\n";
    cout << "Regizorul filmului: " << f3.getRegizor() << "\n";
    cout << "Nota filmului pe IMDB: " << f3.getRating() << "\n";

    c1.adauga_film(f1);
    c1.adauga_film(f2);
    c1.adauga_film(f3);
    c1.sortare_filme();
    c1.afiseaza_film();
}
