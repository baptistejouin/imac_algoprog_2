#include <iostream>

using namespace std;

struct Noeud
{
    int donnee;
    Noeud *suivant;
};

struct Liste
{
    Noeud *premier;
};

struct DynaTableau
{
    int *donnees, size, capacity;
};

void initialise(Liste *liste)
{
    liste->premier = nullptr;
}

bool est_vide(const Liste *liste)
{
    if (liste->premier == nullptr)
    {
        return true;
    }
    return false;
}

void ajoute(Liste *liste, int valeur)
{
    Noeud *currentNode = liste->premier;
    Noeud *newNode = new Noeud();

    if (!newNode)
    {
        std::cout << "Allocation failed" << std::endl;
        return;
    }

    newNode->donnee = valeur;

    if (est_vide(liste))
    {
        liste->premier = newNode;
        return;
    }

    while (currentNode->suivant != nullptr)
    {
        currentNode = currentNode->suivant;
    }

    currentNode->suivant = newNode;
}

void affiche(const Liste *liste)
{
    Noeud *currentNode = liste->premier;

    if (est_vide(liste))
    {
        std::cout << "Empty list !" << std::endl;
        return;
    }
    while (currentNode->suivant != nullptr)
    {
        std::cout << currentNode->donnee << ", " << std::endl;
        currentNode = currentNode->suivant;
    }
}

// Retourne le nième entier de la structure
int recupere(const Liste *liste, int n)
{
    Noeud *currentNode = liste->premier;

    for (size_t i = 0; i <= n; i++)
    {
        currentNode = currentNode->suivant;
    }

    return currentNode->donnee;
}

// Retourne l’index de valeur dans la structure ou -1 s’il n’existe pas
int cherche(const Liste *liste, int valeur)
{
    Noeud *currentNode = liste->premier;
    int index = 0;

    while (currentNode->donnee != valeur && currentNode->suivant != nullptr)
    {
        index++;
        currentNode = currentNode->suivant;
    }

    return currentNode->suivant == nullptr ? -1 : index;
}

// Dedéfini la nième valeur de la structure avec valeur
void stocke(Liste *liste, int n, int valeur)
{
    Noeud *currentNode = liste->premier;

    for (size_t i = 0; i <= n; i++)
    {
        currentNode = currentNode->suivant;
    }

    currentNode->donnee = valeur;
}

// TODO:
void ajoute(DynaTableau *tableau, int valeur)
{
}

// TODO:
void initialise(DynaTableau *tableau, int capacite)
{
    tableau->donnees = nullptr;
}

// TODO:
bool est_vide(const DynaTableau *liste)
{
    if (liste->donnees == nullptr)
    {
        return true;
    }
    return false;
}

// TODO:
void affiche(const DynaTableau *tableau)
{
}

// TODO:
int recupere(const DynaTableau *tableau, int n)
{
    return 0;
}

// TODO:
int cherche(const DynaTableau *tableau, int valeur)
{
    return -1;
}

// TODO:
void stocke(DynaTableau *tableau, int n, int valeur)
{
}

// Ajoute une valeur à la fin
// void pousse_file(Liste* liste, int valeur)
void pousse_file(Liste *liste, int valeur)
{
    ajoute(liste, valeur);
}

// Enlève la première valeur ajoutée et la retourne
// int retire_file(Liste* liste)
int retire_file(Liste *liste)
{
    Noeud *currentNode = liste->premier;

    if (est_vide(liste))
    {
        std::cout << "Empty list !" << std::endl;

        return -1;
    }

    if (liste->premier->suivant == nullptr)
    {
        int value = liste->premier->donnee;

        liste->premier = nullptr;

        return value;
    }

    Noeud *newPremier = liste->premier->suivant;

    delete liste->premier;

    liste->premier = newPremier;

    return currentNode->donnee;
}

// Ajoute une valeur au début de la structure
// void pousse_pile(Liste* liste, int valeur)
void pousse_pile(Liste *liste, int valeur)
{
    Noeud *newNode = new Noeud();

    if (!newNode)
    {
        std::cout << "Allocation failed" << std::endl;
        return;
    }

    newNode->donnee = valeur;

    newNode->suivant = liste->premier;

    liste->premier = newNode;
}

// Enlève la dernière valeur ajoutée et la retourne
// int retire_pile(Liste* liste)
int retire_pile(Liste *liste)
{
    Noeud *currentNode = liste->premier;

    while (currentNode->suivant->suivant != nullptr)
    {
        currentNode = currentNode->suivant;
    }

    int value = currentNode->suivant->donnee;

    delete currentNode->suivant;

    currentNode->suivant = nullptr;

    return value;
}

int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i = 1; i <= 7; i++)
    {
        ajoute(&liste, i * 7);
        ajoute(&tableau, i * 5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i = 1; i <= 7; i++)
    {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    std::cout << "retire_file :" << std::endl;

    int compteur = 10;
    while (!est_vide(&file) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while (!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
