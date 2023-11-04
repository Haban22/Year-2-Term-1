#include <iostream>
#include <string>

using namespace std;

class PhoneBook
{
    private:
    // Private Variables
    string* names;
    string* phones;
    int phoneBooksize;
    public:
    // Member Functions
     void setSize(int pbs);
     void copyPB(const PhoneBook&);
     bool addEntry(string n ,string p);
     bool displayEntryAtIndex(int i);
     void displayEntryAtIndices(int* i);
     void displayAll();
     int* findByName(string n);
     int findByPhone(string p);
     bool updateNameAt(string n, int i);
     bool updatePhoneAt(string p, int i);
     void clear();
};

// Member functions declaration

bool isdigit(string &p)
{
    for(char d : p)
    {
        if (d < '0' || d > '9')
        {
            return false;
        }
    }
    return true;
}

void PhoneBook::setSize(int pbs)
{
    phoneBooksize = pbs;
    names = new string[phoneBooksize];
    phones = new string[phoneBooksize];
};

void PhoneBook::copyPB(const PhoneBook &pb)
{

}

bool PhoneBook::addEntry(string n, string p)
{
    for(int i = 0; i < phoneBooksize; i++)
    {
        if(!names[i].empty())
        {
            continue;
        }
        else
        {
            if(p.size() != 11)
            {
                cout << "Invalid phone number" << endl;
                return 0;
            }
            else if(!isdigit(p))
            {
                cout << "Invalid phone number" << endl;
                return 0;
            }
            else
            {
                names[i] = n;
                phones[i] = p;
                return 1;
                break;
            }
        }
    }
    return 0;
}

bool PhoneBook::displayEntryAtIndex(int i)
{
    if(i >= 0 && i < phoneBooksize)
    {
        cout << "Name: " << names[i] << endl << "Phone: " << phones[i];
        return true;
    }
    else
    {
        cout << "Invalid Index" << endl;
        return false;
    }
    return false;
}

void PhoneBook::displayAll()
{
    for(int i = 0; i < phoneBooksize; i++)
    {
        cout << "Name: " << names[i] << " Phone: " << phones[i] << endl;
    }
};

int main()
{
    int s, choice;
    PhoneBook pb1;
    bool loop = 1;
    string n,p;

    cout << "Enter the size of your phone book: ";
    cin >> s;

    cin.ignore();

    pb1.setSize(s);

    for(int i = 1; i <= s; i++)
    {
        cout << "Enter name " << i << ": ";
        getline(cin , n);
        cout << "Enter phone " << i << ": ";
        getline(cin , p);
        pb1.addEntry(n,p);
    }
    
    while(loop)
    {
        cout << "Enter your choice:\n" << "1- Display all phone book\n" << "2- Search for entry/entries by name\n" << "3- Search for entry/entries by phone"
        << "4- Find an entry by index\n" << "5- Update name by index\n" << "6- Update phone by index\n" 
        << "7- Copy phone book to another and display entries of the new phone book\n" << "8- Exit\n" << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            pb1.displayAll();
            break;
        case 2:
            
            break;
        case 3:

            break;
        case 4:
            int i;
            cout << "Enter index: ";
            cin >> i;
            pb1.displayEntryAtIndex(i);
            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:
            loop = 0;
            break;
        default:
            break;
        }
    }
    


    return 0;
};