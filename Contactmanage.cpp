#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Contact 
{
    string name;
    string phoneNumber;
    string emailAddress;
};

vector<Contact> contacts; 

void addContact() 
{
    Contact newContact;
    cout << "Enter name: ";
    getline(cin, newContact.name);
    cout << "Enter phone number: ";
    getline(cin, newContact.phoneNumber);
    cout << "Enter email address: ";
    getline(cin, newContact.emailAddress);
    contacts.push_back(newContact);
    cout << "Contact added successfully!" << endl;
}


void viewContacts() 
{
    if (contacts.empty()) 
    {
        cout << "No contacts available." << endl;
    } else
     {
        cout << "Contact List:" << endl;
        for (size_t i = 0; i < contacts.size(); ++i) 
        {
            cout << "Name: " << contacts[i].name << endl;
            cout << "Phone: " << contacts[i].phoneNumber << endl;
            cout << "Email: " << contacts[i].emailAddress << endl << endl;
        }
    }
}


void editContact() {
    string searchName;
    cout << "Enter the name of the contact you want to edit: ";
    getline(cin, searchName);
    for (size_t i = 0; i < contacts.size(); ++i)
     {
        if (contacts[i].name == searchName) 
        {
            cout << "Enter new phone number: ";
            getline(cin, contacts[i].phoneNumber);
            cout << "Enter new email address: ";
            getline(cin, contacts[i].emailAddress);
            cout << "Contact updated successfully!" << endl;
            return;
        }
    }
    cout << "Contact not found." << endl;
}


void deleteContact() 
{
    string searchName;
    cout << "Enter the name of the contact you want to delete: ";
    getline(cin, searchName);
    for (auto it = contacts.begin(); it != contacts.end(); ++it) 
    {
        if (it->name == searchName) {
            it = contacts.erase(it);
            cout << "Contact deleted successfully!" << endl;
            return;
        }
    }
    cout << "Contact not found." << endl;
}


void saveContactsToFile(const string& filename) 
{
    ofstream outFile(filename);
    if (!outFile.is_open()) 
    {
        cerr << "Error: Unable to open the file " << filename << endl;
        return;
    }
    for (const auto& contact : contacts) 
    {
        outFile << contact.name << "," << contact.phoneNumber << "," << contact.emailAddress << endl;
    }
    outFile.close();
    cout << "Contacts saved to " << filename << endl;
}

int main() 
{
    string filename = "contacts.txt"; 

   
    ifstream inFile(filename);
    if (inFile.is_open()) 
    {
        string line;
        while (getline(inFile, line)) 
        {
            Contact contact;
            size_t pos = line.find(',');
            if (pos != string::npos) 
            {
                contact.name = line.substr(0, pos);
                line.erase(0, pos + 1);
                pos = line.find(',');
                if (pos != string::npos) 
                {
                    contact.phoneNumber = line.substr(0, pos);
                    line.erase(0, pos + 1);
                    contact.emailAddress = line;
                    contacts.push_back(contact);
                }
            }
        }
        inFile.close();
    }

    int choice;
    do {
        cout << "\nMenu:\n1. Add Contact\n2. View Contacts\n3. Edit Contact\n4. Delete Contact\n5. Save Contacts\n6. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); 
        switch (choice) 
        {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                editContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                saveContactsToFile(filename);
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
