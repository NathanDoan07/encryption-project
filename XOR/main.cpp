//
// Encryption project
// C++ program that will encrypt and decrypt a text file run from a CLI with a simple menu
// Team 4
// Author: Tu Vo, Nathan Doan
// Date: 02/16/2023
//


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to encrypt a string using XOR cipher
string xor_encrypt(string text, char key){
    string input = "";

    for (int i = 0; i < text.length(); i++)
    {
        input += text[i] ^ key;
    }

    return input;
}

// Function to decrypt a string using XOR cipher
string xor_decrypt(string text, char key){
    string output = "";

    for (int i = 0; i < text.length(); i++){
        output += text[i] ^ key;
    }

    return output;
}
string caesar_encrypt(string text, char key){
    string input = "";
    return input;
}
string caesar_decrypt(string text, char key){
    string output = "";
    return output;
}

int main() {
    // Display the menu options
    cout << "Choose an option (Enter 1 or 2):" << endl;
    cout << "1. Encrypt a file" << endl;
    cout << "2. Decrypt a file" << endl;

    int option;
    cin >> option;

    if (option == 1) {
        // Ask for the filename from the user
        string filename;
        cout << "Enter a filename to encrypt (End with .txt): ";
        cin >> filename;

        // Display encryption method options
        cout << "Choose an encryption method (Enter 1 or 2):" << endl;
        cout << "1. XOR Cypher method" << endl;
        cout << "2. Caesar Cypher method" << endl;

        int method;
        cin >> method;

        if (method == 1) {
            // Ask for the encryption key from the user
            char ekey;
            cout << "Enter the encryption key (single ASCII character): ";
            cin >> ekey;

            // Open the file
            ifstream fin(filename);

            if (!fin) {
                cout << "Can not open file!" << endl;
                return 1;
            }

            // Read the contents of the file into a string
            string content;
            fin.seekg(0, ios::end);
            content.resize(fin.tellg());
            fin.seekg(0, ios::beg);
            fin.read(&content[0], content.size());
            fin.close();

            // Encrypt the string using XOR cipher
            string encrypted = xor_encrypt(content, ekey);
            // Write to the file
            ofstream etext(filename);
            etext << encrypted;
            etext.close();

            cout << "Encrypt file successfully!" << endl;
        } else if (method == 2) {
            // Ask for the encryption key from the user
            int ekey;
            cout << "Enter the encryption key (integer 1-25): ";
            cin >> ekey;

            // Open the file
            ifstream fin(filename);

            if (!fin) {
                cout << "Can not open file!" << endl;
                return 1;
            }

            // Read the contents of the file into a string
            string content;
            fin.seekg(0, ios::end);
            content.resize(fin.tellg());
            fin.seekg(0, ios::beg);
            fin.read(&content[0], content.size());
            fin.close();

            // Encrypt the string using Caesar cipher
            string encrypted = caesar_encrypt(content, ekey);

            // Write to the file
            ofstream etext(filename);
            etext << encrypted;
            etext.close();

            cout << "Encrypt file successfully!" << endl;
        } else {
            cout << "Invalid method option, choose another option!" << endl;
            return 1;
        }
    } else if (option == 2) {
        // Ask for the filename from the user
        string filename;
        cout << "Enter a filename to decrypt(End with .txt): ";
        cin >> filename;

        // Display decryption method options
        cout << "Choose a decryption method (Enter 1 or 2):" << endl;
        cout << "1. XOR Cipher method" << endl;
        cout << "2. Caesar Cipher method" << endl;

        int method;
        cin >> method;

        if (method == 1) {
            // Ask for the encryption key from the user
            char ekey;
            cout << "Enter the encryption key(single ASCII character - it should be similar to the encryption key of encrypt algorithm): ";
            cin >> ekey;

            // Open the file
            ifstream fin(filename);

            if (!fin) {
                cout << "Can not open file!" << endl;
                return 1;
            }

            // Read the contents of the file into a string
            string content;
            fin.seekg(0, ios::end);
            content.resize(fin.tellg());
            fin.seekg(0, ios::beg);
            fin.read(&content[0], content.size());
            fin.close();

            // Decrypt the string using XOR cipher
            string decrypted = xor_decrypt(content, ekey);

            // Write to the file
            ofstream dtext(filename);
            dtext << decrypted;
            dtext.close();

            cout << "Decrypt file successfully!" << endl;
        } else if (method == 2) {
            // Ask for the encryption key from the user
            int ekey;
            cout << "Enter the encryption key (integer 1-25): ";
            cin >> ekey;

            // Open the file
            ifstream fin(filename);

            if (!fin) {
                cout << "Can not open file!" << endl;
                return 1;
            }

            // Read the contents of the file into a string
            string content;
            fin.seekg(0, ios::end);
            content.resize(fin.tellg());
            fin.seekg(0, ios::beg);
            fin.read(&content[0], content.size());
            fin.close();

            // Decrypt the string using Caesar cipher
            string decrypted = caesar_decrypt(content, ekey);

            // Write to the file
            ofstream dtext(filename);
            dtext << decrypted;
            dtext.close();

            cout << "Decrypt file successfully!" << endl;
        } else {
            cout << "Invalid method option, choose another option!" << endl;
            return 1;
        }
    } else {
        cout << "Invalid option, choose another option!" << endl;
        return 1;
    }

    return 0;

}
