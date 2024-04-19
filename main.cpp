#include <fstream>
#include <iostream>
#include <filesystem>

#include"user.h"
#include"message.h"

using namespace std;

int main()
{
    fstream usr_file = std::fstream("users.txt", ios::in | ios::out);
    fstream msg_file = std::fstream("messages.txt", ios::in | ios::out);

    if (!usr_file) 
        usr_file = fstream("users.txt", ios::in | ios::out | ios::trunc);

    if (!msg_file) 
        msg_file = fstream("messages.txt", ios::in | ios::out | ios::trunc);

    cout << "Users:" << endl;
    if (usr_file)
    {
		User obj1("Alex", "qwerty", "12345");
        User obj2("Dimooon", "wasd", "54321");
        User obj3("test_user", "test", "11111");

		usr_file << obj1 << endl;         // write
        usr_file << obj2 << endl;

		usr_file.seekg(0, ios_base::beg); // move to start

		usr_file >> obj3;                 // read
		cout << obj3 << endl;
        usr_file >> obj3;
        cout << obj3 << endl;
	}
	else
		cout << "Could not open file users.txt !" << endl;

    cout << endl << "Messages:" << endl;
    if (msg_file)
    {
		User obj1("Hello Dimon", "Alex", "Dimooon");
        User obj2("Hello world", "gcc", "linux");
        User obj3("test_tessage", "test_user", "Me");

		msg_file << obj1 << endl;
        msg_file << obj2 << endl;

		msg_file.seekg(0, ios_base::beg);

		msg_file >> obj3;
		cout << obj3 << endl;
        msg_file >> obj3;
        cout << obj3 << endl;
	}
	else
		cout << "Could not open file users.txt !" << endl;

}