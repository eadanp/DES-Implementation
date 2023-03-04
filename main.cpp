#include "des.h"

int main(){
    string masterKey;//64Bit key
    extern string message;
    //secret message input
    cout << "Please enter your secret message:" << endl;
    getline(cin, message);

    //key input
    while(masterKey.length() != 64){
        cout << "Please enter your secret key:" << endl;
        cin >> masterKey;
        if(masterKey.length() != 64){
            cout << "Your Key is not 64Bits. Please re-enter your Key." << endl;
        }
    }

    cout << endl << "Message: " << message;
    SubKeyGenerator(masterKey);
    message = ToBinary64(message);
    string cipherBinary = ECB();
    cout << endl << endl << "the cipher binary text is: " << endl;
    Organize64(cipherBinary);
    cout << endl << "the cipher text is: " << BinToText(cipherBinary);
    //string decrypted = Decryption64(cipherBinary);
	//cout<< endl << "Decrypted text:"<<BinToText(decrypted) <<endl;
    return 0;
}