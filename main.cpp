#include <fstream>
#include <iostream>
#include <filesystem>
#include<iomanip>

#include"user.h"
#include"message.h"

using namespace std;
namespace fs = std::filesystem;

void demo_perms(fs::perms p)
{
    std::cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
        << ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
        << ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
        << endl;
}

int main()
{
    fstream usr_file = std::fstream("users.txt", ios::in | ios::out);
    fstream msg_file = std::fstream("messages.txt", ios::in | ios::out);

    if (!usr_file) 
        usr_file = fstream("users.txt", ios::in | ios::out | ios::trunc);

    if (!msg_file) 
        msg_file = fstream("messages.txt", ios::in | ios::out | ios::trunc);

    fs::permissions("users.txt", fs::perms::group_all | fs::perms::others_all, fs::perm_options::remove);
    fs::permissions("messages.txt", fs::perms::group_all | fs::perms::others_all, fs::perm_options::remove);
    cout << setw(28) << "users.txt permissions  ";
    demo_perms(fs::status("users.txt").permissions());
    cout << setw(28) << "messages.txt permissions  ";
    demo_perms(fs::status("messages.txt").permissions());

    cout << endl << "Users:" << endl;
    if (usr_file)
    {
		User obj_u1("Alex", "qwerty", "12345");
        User obj_u2("Dimooon", "wasd", "54321");
        User obj_u3("test_user", "test", "11111");

		usr_file << obj_u1 << endl;         // write
        usr_file << obj_u2 << endl;

		usr_file.seekg(0, ios_base::beg); // move to start

		usr_file >> obj_u3;                 // read
		cout << obj_u3 << endl;
        usr_file >> obj_u3;
        cout << obj_u3 << endl;
	}
	else
		cout << "Could not open file users.txt !" << endl;

    cout << endl << "Messages:" << endl;
    if (msg_file)
    {
		User obj_m1("Hello", "Alex", "Dimooon");
        User obj_m2("Hello_world", "gcc", "linux");
        User obj_m3("test_tessage", "test_user", "Me");

		msg_file << obj_m1 << endl;
        msg_file << obj_m2 << endl;
        msg_file << obj_m3 << endl;

		msg_file.seekg(0, ios_base::beg);

		msg_file >> obj_m3;
		cout << obj_m3 << endl;
        msg_file >> obj_m3;
        cout << obj_m3 << endl;
	}
	else
		cout << "Could not open file users.txt !" << endl;

    cout << endl;
}