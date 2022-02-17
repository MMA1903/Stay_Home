#pragma once
#include"User.h"
#include"Challenge.h"


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <regex>
using namespace std;
class Server
{
    static vector<User*> Users;
    static vector<Challenge*> Challenges;

    static vector<User*> Users_helper;

    int file_user_opened;
    string file_user_name;

    int file_ch_opened;
    string file_ch_name;

public:
    Server();

    void make_Server(const string& file_user_name, const string& file_ch_name);

    ~Server();

    void print_user() const;

    void print_ch() const;

    ///////////////////////////////

    void save_command();

    void save_as_command();

    void close_command();

    void registration_command();

    void list_command();

    void challenge_command();

    void finish_command();

    void profile_info_command();

    void activate();
};
double string_to_double(const string& str);
