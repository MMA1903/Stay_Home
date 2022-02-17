#include"User.h"
User::User()
{
    this->name = "Unknown";

    this->age = "Unknown";

    this->id = 0;

    this->email = "Unknown";
}

void User::set_name(string name)
{
    this->name = name;
}

void User::set_id(double id)
{
    this->id = id;
}

void User::set_age(string age)
{
    this->age = age;
}

void User::set_email(string email)
{
    this->email = email;
}

const string User::get_name()
{
    return this->name;
}

double User::get_id() const
{
    return this->id;
}

const string User::get_age()
{
    return this->age;
}

const string User::get_email()
{
    return this->email;
}

void User::print() const
{
    cout << "id" << "[" << this->id << "]" << endl
        << "Name:" << this->name << endl
        << "Age:" << this->age << endl
        << "E-mail:" << this->email << endl;
}
