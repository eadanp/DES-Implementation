#include "des.h"

int main(){
    string masterKey;//64Bit key
    extern string message;
    int exit = 0;

    while(exit != 3){
        cout << "Welcome to the DES Encryptor/Decryptor Program!" << endl << endl;
        cout << "1. Encryption" << endl << "2. Decryption" << endl << "3. EXIT" << endl;
        cout << "Choose one of the following options (1-3): ";
        cin >> exit;

        if(exit == 1){
            //secret message input
            cout << endl << "Please enter your secret message: ";
            cin.ignore();
            getline(cin, message);
            //key input
            cout << endl << "Please enter your 8 characters secret key: ";
            cin >> masterKey;
            while(masterKey.length() != 8){
                cout << "Your Key is not 8 characters. Please re-enter your Key: ";
                cin >> masterKey;
            }       
            masterKey = ToBinary64(masterKey);

            cout << endl << "Message: " << message;
            EncryptionSubKeyGenerator(masterKey);
            message = ToBinary64(message);
            string cipherBinary = ECB();
            cout << endl << endl << "the cipher binary text is: " << endl << endl;
            Organize64(cipherBinary);
            cout << endl << "the cipher text is: " << BinToText(cipherBinary) << endl << endl;
        }
        else if(exit == 2){
           //secret message input
            cout << endl << "Please enter your binary cipher string: ";
            cin.ignore();
            getline(cin, message);

            //key input
            cout << endl << "Please enter your 8 characters secret key: ";
            cin >> masterKey;
            while(masterKey.length() != 8){
                cout << "Your Key is not 8 characters. Please re-enter your Key: ";
                cin >> masterKey;
            }       
            masterKey = ToBinary64(masterKey);
            

            cout << endl << "Encrypted Message: " << BinToText(message) << endl;
            string decrypted = Decryption64(masterKey);
	        cout<< endl << "Decrypted text: "<< BinToText(decrypted) << endl << endl;
        }
        else if(exit == 3){
            cout << endl << "Thank you for using our DES program!";
        }
        else {
            cout << endl << "Please enter a choice from 1-3." << endl << endl;
        }
    }
    
    
    return 0;
}