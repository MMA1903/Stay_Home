#pragma once
#include<iostream>
#include<cstring>
using namespace std;
class User
{
private:
    string name;
    double id;
    string age;
    string email;
public:
    friend class Server;

    User();


    void set_id(double id);

    void set_name(string name);

    void set_age(string age);

    void set_email(string email);



    const string get_name();

    double get_id() const;

    const string get_age();

    const string get_email();



    void print() const;
};
