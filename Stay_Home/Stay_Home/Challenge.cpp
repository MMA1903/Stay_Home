#include"Challenge.h"
#include<iostream>
#include<cstring>
Challenge::Challenge()
{
    this->ch_name = "#";

    this->ch_num = 0;

    this->used = 1;

    this->rating = 0;

    this->status = "new";
}

void Challenge::set_ch_name(string ch_name)
{
    this->ch_name = ch_name;
}

void Challenge::set_ch_num(int ch_num)
{
    this->ch_num = ch_num;
}

void Challenge::set_used(int used)
{
    this->used = used;
}

void Challenge::set_rating(double rating)
{
    this->rating = rating;
}

void Challenge::set_status(string status)
{
    this->status = status;
}



const string Challenge::get_ch_name()
{
    return this->ch_name;
}

int Challenge::get_ch_num() const
{
    return this->ch_num;
}

int Challenge::get_used() const
{
    return this->used;
}

double Challenge::get_rating() const
{
    return this->rating;
}

const string Challenge::get_status()
{
    return this->status;
}


void Challenge::print() const
{
    cout << "Challenge number" << "[" << this->ch_num << "]" << endl
        << "Challenge name:" << this->ch_name << endl
        << "Used " << "(" << this->used << ")" << " times" << endl
        << "Rating:" << this->rating << endl
        << "Status:" << this->status << endl;
}
