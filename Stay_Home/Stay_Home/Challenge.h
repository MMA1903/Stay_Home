#pragma once
#include<iostream>
#include<cstring>
using namespace std;
class Challenge
{
private:
    string ch_name;
    int ch_num;
    int used;
    double rating;
    string status;
public:
    friend class Server;

    Challenge();


    void set_ch_name(string ch_name);

    void set_ch_num(int ch_num);

    void set_used(int used);

    void set_rating(double rating);

    void set_status(string status);



    const string get_ch_name();

    int get_ch_num() const;

    int get_used() const;

    double get_rating() const;

    const string get_status();



    void print() const;
};

#pragma once
