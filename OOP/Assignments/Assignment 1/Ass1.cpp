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
     bool addEntry(string n ,string p);
     bool displayEntryAtIndex(int i);
     void displayEntryAtIndices(int* i);
     void displayAll();
     int* findByName(string n);
     int findByPhone(string p);
     bool updateNameAt(string n, int i);
     bool updatePhoneAt(string p, int i);
     void copyPB(const PhoneBook&);
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

void PhoneBook::displayEntryAtIndices(int *i)
{
    for(int j = 0; j <= phoneBooksize; j++)
    {
        if(i[j] == 1)
        {
            cout << "Name: " << names[j] << " Phone: " << phones[j] << endl;
        }
    }
}

void PhoneBook::displayAll()
{
    for(int i = 0; i < phoneBooksize; i++)
    {
        cout << "Name: " << names[i] << " Phone: " << phones[i] << endl;
    }
}

int *PhoneBook::findByName(string n)
{
    int* arr = new int [phoneBooksize];
    for(int i = 0; i < phoneBooksize; i++)
    {
        if(n == names[i])
        {
            arr[i] = 1;
        }
        else if(n != names[i])
        {
            for(int j = 0; j <= n.size(); j++)
            {
                if(names[i][j] == n[j])
                {
                    arr[i] = 1;
                    continue;
                }
                else
                {
                    arr[i] = 0;
                    break;
                }

            }
        }
        
    }

    return arr;
}

int PhoneBook::findByPhone(string p)
{
    for(int i; i < phoneBooksize; i++)
    {
        if(phones[i] == p)
        {
            cout << phones[i] << endl;
        }
        else
        {
            cout << "phone number not found";
        }
    }
    return 0;
}

bool PhoneBook::updateNameAt(string n, int i)
{
    if(i >= 0 && i < phoneBooksize)
    {
        names[i] = n;
        return true;
    }
    else
    {
        cout << "Index out of range" << endl;
        return false;
    }
    return false;
}

bool PhoneBook::updatePhoneAt(string p, int i)
{
    if(i >= 0 && i < phoneBooksize)
    {
        phones[i] = p;
        return true;
    }
    else
    {
        cout << "Index out of range" << endl;
        return false;
    }
    return false;
}

void PhoneBook::copyPB(const PhoneBook &pb)
{

    delete[] names;
    delete[] phones;

    names = new string[phoneBooksize];
    phones = new string[phoneBooksize];


    for(int i = 0; i < phoneBooksize; i++)
    {
        names[i] = pb.names[i];
        phones[i] = pb.phones[i];
    }

    phoneBooksize = pb.phoneBooksize;
}

void PhoneBook::clear()
{
    delete[] names;
    delete[] phones;
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
        string input = "";
        int index = 0;

        cout << "Enter your choice:\n" << "1- Display all phone book\n" << "2- Search for entry/entries by name\n" << "3- Search for entry/entries by phone"
        << "4- Find an entry by index\n" << "5- Update name by index\n" << "6- Update phone by index\n" 
        << "7- Copy phone book to another and display entries of the new phone book\n" << "8- Exit\n" << "Choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice)
        {
        case 1:
            pb1.displayAll();
            break;
        case 2:
            cout << "Enter name: ";
            getline(cin , input);
            pb1.findByName(input);
            break;
        case 3:
            cout << "Enter phone: ";
            getline(cin , input);
            pb1.findByPhone(input);
            break;
        case 4:
            int *inArr = new int[s];
            break;
        case 5:
            cout << "Enter new name: ";
            getline(cin , input);
            cin.ignore();
            cout << "Enter index: ";
            cin >> index;
            cin.ignore();
            pb1.updateNameAt(input , index);
            break;
        case 6:
            cout << "Enter new phone: ";
            getline(cin , input);
            cout << "Enter index: ";
            cin >> index;
            cin.ignore();
            pb1.updatePhoneAt(input , index);
            break;
        case 7:
            PhoneBook pb2;
            pb1.copyPB(pb2);
            pb2.displayAll();
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