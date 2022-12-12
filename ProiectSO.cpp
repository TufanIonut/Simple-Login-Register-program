#include <iostream> 
#include <fstream> 
#include <string>

using namespace std;

bool eLogat()
{
    string username, parola;
    string un, par; 

    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> parola;

    ifstream read(username + ".txt"); 
    getline(read, un); 
    getline(read, par); 

    if (un == username && par == parola) 
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int alegere;

    cout << endl;
    cout << "Meniu Principal: " << endl;
    cout << "-------------------------------" << endl;
    cout << "1. Inregistrare" << endl;
    cout << "2. Logare" << endl;
    cout << endl;
    cout << "Alegerea dumneavoastra: ";
    cin >> alegere;

    if (alegere == 1)
    {
        string username, parola;

        cout << "Inregistrare: " << endl;
        cout << endl;
        cout << "Selectati un nume de utilizator: ";
        cin >> username;
        cout << "Selectati o parola: ";
        cin >> parola;

        ofstream file;
        file.open(username + ".txt");
        file << username << endl << parola;
        file.close();
        cout << "Bun venit " << username << "!" << endl;

    }
    else if (alegere == 2)
    {
        bool status = eLogat();

        if (!status)
        {
            system("clear");
            cout << endl;
            cout << "Logare invalida!" << endl;
            main();
            return 0;
        }
        else
        {
            cout << "Logarea a avut loc cu success!" << endl;
            cout << endl;

            int alegere2;

          
            cout << "Bine ati revenit!" << endl;
            cout << endl;
            cout << "Pagina Principala" << endl;
            for (int i = 0; i < 5; i++)
            {
                cout << "Aveti " << i << " mesaje necitite" << endl;
            }
 
            cout << endl;
            cout << "1. Deconectare" << endl;
            cout << "2. Revenire la meniul principal" << endl;
            cout << "Your choice: " << endl;
            cin >> alegere2;

            if (alegere2 == 1)
            {
                system("exit");  
            }
            else if (alegere2 == 2)
            {
                main();
            }
            return 1;
        }
    }
}