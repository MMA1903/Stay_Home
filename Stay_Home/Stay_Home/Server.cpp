#include"Server.h"

vector<Challenge*>Server::Challenges{};
vector<User*>Server::Users{};

vector<User*>Server::Users_helper{};


Server::Server()
{
    Server::Users;
    int file_user_opened = 0;
    string file_user_name = "";

    Server::Challenges;
    int file_ch_opened = 0;
    string file_ch_name = "";
}

void Server::make_Server(const string& file_user_name, const string& file_ch_name)
{
    if (file_user_opened == 1 && file_ch_opened == 1)
    {
        cout << "You are in Server" << endl;
    }
    else
    {
        string line_ch = "";
        string value_ch = "";

        string line_user = "";
        string value_user = "";

        int br_spaces_user = 0;
        int br_spaces_ch = 0;

        ifstream my_user_file(file_user_name);
        this->file_user_name = file_user_name;

        ifstream my_ch_file(file_ch_name);
        this->file_ch_name = file_ch_name;

        if (my_user_file.is_open() && my_ch_file.is_open())
        {
            int br = 0;
            while (getline(my_ch_file, line_ch))
            {
                Server::Challenges.push_back(new Challenge());

                string value_ch = "";
                int j = 0;

                for (auto x : line_ch)
                {
                    if (x == ' ')
                    {
                        if (j == 0)
                        {
                            Server::Challenges[br]->set_ch_name(value_ch);
                            j++;
                        }
                        else if (j == 1)
                        {
                            Server::Challenges[br]->set_ch_num(string_to_double(value_ch));
                            j++;
                        }
                        else if (j == 2)
                        {
                            Server::Challenges[br]->set_used(string_to_double(value_ch));
                            j++;
                        }
                        else if (j == 3)
                        {
                            Server::Challenges[br]->set_rating(string_to_double(value_ch));
                            j++;
                        }

                        value_ch = "";
                    }
                    else
                    {
                        value_ch = value_ch + x;
                    }
                }
                if (j == 0)
                {
                    Server::Challenges[br]->set_ch_name(value_ch);
                }
                else if (j == 1)
                {
                    Server::Challenges[br]->set_ch_num(string_to_double(value_ch));
                }
                else if (j == 2)
                {
                    Server::Challenges[br]->set_used(string_to_double(value_ch));
                }
                else if (j == 3)
                {
                    Server::Challenges[br]->set_rating(string_to_double(value_ch));
                }
                else
                {
                    Server::Challenges[br]->set_status(value_ch);
                }

                br++;
            }
            br = 0;
            while (getline(my_user_file, line_user))
            {
                Server::Users.push_back(new User());

                string value_user = "";
                int j = 0;

                for (auto x : line_user)
                {
                    if (x == ' ')
                    {
                        if (j == 0)
                        {
                            Server::Users[br]->set_id(string_to_double(value_user));
                            j++;
                        }
                        else if (j == 1)
                        {
                            Server::Users[br]->set_name(value_user);
                            j++;
                        }
                        else if (j == 2)
                        {
                            Server::Users[br]->set_age(value_user);
                            j++;
                        }
                        value_user = "";
                    }
                    else
                    {
                        value_user = value_user + x;
                    }
                }
                if (j == 0)
                {
                    Server::Users[br]->set_id(string_to_double(value_user));
                }
                else if (j == 1)
                {
                    Server::Users[br]->set_name(value_user);
                }
                else if (j == 2)
                {
                    Server::Users[br]->set_age(value_user);
                }
                else
                {
                    Server::Users[br]->set_email(value_user);

                }
                br++;
            }
            my_user_file.close();
            my_ch_file.close();
            cout << "Successfully opened : " << file_user_name << endl;
            cout << "Successfully opened : " << file_ch_name << endl;
            file_user_opened = 1;
            file_ch_opened = 1;
        }
        else
        {
            ofstream outfile_user(file_user_name);
            ofstream outfile_ch(file_ch_name);
            cout << "You create new Users " << file_user_name << endl;
            cout << "You create new Challenges " << file_ch_name << endl;
            outfile_user.close();
            outfile_ch.close();
            file_user_opened = 1;
            file_ch_opened = 1;
        }
    }
}

Server::~Server()
{
    this->file_user_opened = 0;
    this->file_ch_name = "";

    Server::Users.clear();

    this->file_ch_opened = 0;
    this->file_ch_name = "";

    Server::Challenges.clear();
}

void Server::print_user() const
{
    for (int i = 0; i < Server::Users.size(); i++)
    {
        this->Server::Users[i]->print();
    }
}

void Server::print_ch() const
{
    for (int i = 0; i < Server::Challenges.size(); i++)
    {
        this->Server::Challenges[i]->print();
    }
}

///////////////////////////////

void Server::save_as_command()
{
    if (file_user_opened == 1 && file_ch_opened == 1)
    {
        cout << ">User file name : ";
        getline(cin, file_user_name);

        cout << ">Challenge file name : ";
        getline(cin, file_ch_name);

        ofstream my_user_file(file_user_name);
        if (my_user_file.good())
        {
            for (int i = 0; i < Server::Users.size(); i++)
            {
                my_user_file << Server::Users[i]->get_id();
                my_user_file << " ";
                my_user_file << Server::Users[i]->get_name();
                my_user_file << " ";
                my_user_file << Server::Users[i]->get_age();
                my_user_file << " ";
                my_user_file << Server::Users[i]->get_email();
                my_user_file << "\n";
            }
            cout << "Users \"" << this->file_user_name << "\" successfully saved." << endl;
        }
        my_user_file.close();

        ofstream my_ch_file(file_ch_name);
        if (my_ch_file.good())
        {
            for (int i = 0; i < Server::Challenges.size(); i++)
            {
                my_ch_file << Server::Challenges[i]->get_ch_name();
                my_ch_file << " ";
                my_ch_file << Server::Challenges[i]->get_ch_num();
                my_ch_file << " ";
                my_ch_file << Server::Challenges[i]->get_used();
                my_ch_file << " ";
                my_ch_file << Server::Challenges[i]->get_rating();
                my_ch_file << " ";
                my_ch_file << Server::Challenges[i]->get_status();
                my_ch_file << "\n";
            }
            cout << "Challenges \"" << this->file_ch_name << "\" successfully saved." << endl;
        }
        my_ch_file.close();
    }
    else
    {
        cout << "Error : no Server opened." << endl;
    }



}

void Server::save_command()
{
    if (file_user_opened == 1 && file_ch_opened == 1)
    {
        ofstream my_user_file(this->file_user_name);
        if (my_user_file.good())
        {
            for (int i = 0; i < Server::Users.size(); i++)
            {
                my_user_file << Server::Users[i]->get_id();
                my_user_file << " ";
                my_user_file << Server::Users[i]->get_name();
                my_user_file << " ";
                my_user_file << Server::Users[i]->get_age();
                my_user_file << " ";
                my_user_file << Server::Users[i]->get_email();
                my_user_file << "\n";
            }
            cout << "Users \"" << this->file_user_name << "\" successfully saved." << endl;
        }
        my_user_file.close();

        ofstream my_ch_file(this->file_ch_name);
        if (my_ch_file.good())
        {
            for (int i = 0; i < Server::Challenges.size(); i++)
            {
                my_ch_file << Server::Challenges[i]->get_ch_name();
                my_ch_file << " ";
                my_ch_file << Server::Challenges[i]->get_ch_num();
                my_ch_file << " ";
                my_ch_file << Server::Challenges[i]->get_used();
                my_ch_file << " ";
                my_ch_file << Server::Challenges[i]->get_rating();
                my_ch_file << " ";
                my_ch_file << Server::Challenges[i]->get_status();
                my_ch_file << "\n";
            }
            cout << "Challenges \"" << this->file_ch_name << "\" successfully saved." << endl;
        }
        my_ch_file.close();
    }
    else
    {
        cout << "Error : no Server opened." << endl;
    }
}

void Server::close_command()
{
    if (file_user_opened == 1 && file_ch_opened == 1)
    {
        this->file_user_opened = 0;
        this->file_ch_opened = 0;
        this->~Server();
        cout << "Users \"" << this->file_user_name << "\" closed." << endl;
        cout << "Challenges \"" << this->file_ch_name << "\" closed." << endl;
        this->file_user_name = "";
        this->file_ch_name = "";
    }
    else
    {
        cout << "Error : no Server opened." << endl;
    }
}

void Server::registration_command()
{
    if (this->file_user_opened == 1 || this->file_ch_opened == 1)
    {
        string name;
        string age;
        string email;

        cout << ">Name : ";
        getline(cin, name);

        cout << ">Age : ";
        getline(cin, age);

        cout << ">E-mail : ";
        getline(cin, email);
        if (name == "")
        {
            cout << "Registration failed" << endl;
            cout << "You are not enter a name" << endl;
        }
        else
        {
            Server::Users.push_back(new User());

            Server::Users[Server::Users.size() - 1]->set_id(Server::Users.size());

            if (name != "")
            {
                Server::Users[Server::Users.size() - 1]->set_name(name);
            }
            if (age != "")
            {
                Server::Users[Server::Users.size() - 1]->set_age(age);
            }

            if (email != "")
            {
                Server::Users[Server::Users.size() - 1]->set_email(email);
            }
        }
    }
    else
    {
        cout << "Error : no Server opened." << endl;
    }
}

///////////////////////////////

void Server::list_command()
{
    if (this->file_user_opened == 1 || this->file_ch_opened == 1)
    {
        string list_by;
        cout << ">list by (newest , oldest , most_popular , r_most_popular): ";
        getline(cin, list_by);

        if (list_by == "r_most_popular")
        {
            Challenge helper;
            for (int i = 0; i < Server::Challenges.size(); i++)
            {
                for (int j = 0; j < Server::Challenges.size() - 1; j++)
                {
                    if (Server::Challenges[j]->get_used() > Server::Challenges[j + 1]->get_used())
                    {
                        helper.set_ch_name(Server::Challenges[j]->get_ch_name());
                        helper.set_ch_num(Server::Challenges[j]->get_ch_num());
                        helper.set_used(Server::Challenges[j]->get_used());
                        helper.set_rating(Server::Challenges[j]->get_rating());
                        helper.set_status(Server::Challenges[j]->get_status());


                        Server::Challenges[j]->set_ch_name(Server::Challenges[j + 1]->get_ch_name());
                        Server::Challenges[j]->set_ch_num(Server::Challenges[j + 1]->get_ch_num());
                        Server::Challenges[j]->set_used(Server::Challenges[j + 1]->get_used());
                        Server::Challenges[j]->set_rating(Server::Challenges[j + 1]->get_rating());
                        Server::Challenges[j]->set_status(Server::Challenges[j + 1]->get_status());


                        Server::Challenges[j + 1]->set_ch_name(helper.get_ch_name());
                        Server::Challenges[j + 1]->set_ch_num(helper.get_ch_num());
                        Server::Challenges[j + 1]->set_used(helper.get_used());
                        Server::Challenges[j + 1]->set_rating(helper.get_rating());
                        Server::Challenges[j + 1]->set_status(helper.get_status());
                    }
                }
            }
        }
        else if (list_by == "most_popular")
        {
            Challenge helper;
            for (int i = 0; i < Server::Challenges.size(); i++)
            {
                for (int j = 0; j < Server::Challenges.size() - 1; j++)
                {
                    if (Server::Challenges[j]->get_used() < Server::Challenges[j + 1]->get_used())
                    {
                        helper.set_ch_name(Server::Challenges[j]->get_ch_name());
                        helper.set_ch_num(Server::Challenges[j]->get_ch_num());
                        helper.set_used(Server::Challenges[j]->get_used());
                        helper.set_rating(Server::Challenges[j]->get_rating());
                        helper.set_status(Server::Challenges[j]->get_status());


                        Server::Challenges[j]->set_ch_name(Server::Challenges[j + 1]->get_ch_name());
                        Server::Challenges[j]->set_ch_num(Server::Challenges[j + 1]->get_ch_num());
                        Server::Challenges[j]->set_used(Server::Challenges[j + 1]->get_used());
                        Server::Challenges[j]->set_rating(Server::Challenges[j + 1]->get_rating());
                        Server::Challenges[j]->set_status(Server::Challenges[j + 1]->get_status());


                        Server::Challenges[j + 1]->set_ch_name(helper.get_ch_name());
                        Server::Challenges[j + 1]->set_ch_num(helper.get_ch_num());
                        Server::Challenges[j + 1]->set_used(helper.get_used());
                        Server::Challenges[j + 1]->set_rating(helper.get_rating());
                        Server::Challenges[j + 1]->set_status(helper.get_status());
                    }
                }
            }

        }
        else if (list_by == "oldest")
        {
            Challenge helper;
            for (int i = 0; i < Server::Challenges.size(); i++)
            {
                for (int j = 0; j < Server::Challenges.size() - 1; j++)
                {
                    if (Server::Challenges[j]->get_ch_num() > Server::Challenges[j + 1]->get_ch_num())
                    {
                        helper.set_ch_name(Server::Challenges[j]->get_ch_name());
                        helper.set_ch_num(Server::Challenges[j]->get_ch_num());
                        helper.set_used(Server::Challenges[j]->get_used());
                        helper.set_rating(Server::Challenges[j]->get_rating());
                        helper.set_status(Server::Challenges[j]->get_status());


                        Server::Challenges[j]->set_ch_name(Server::Challenges[j + 1]->get_ch_name());
                        Server::Challenges[j]->set_ch_num(Server::Challenges[j + 1]->get_ch_num());
                        Server::Challenges[j]->set_used(Server::Challenges[j + 1]->get_used());
                        Server::Challenges[j]->set_rating(Server::Challenges[j + 1]->get_rating());
                        Server::Challenges[j]->set_status(Server::Challenges[j + 1]->get_status());


                        Server::Challenges[j + 1]->set_ch_name(helper.get_ch_name());
                        Server::Challenges[j + 1]->set_ch_num(helper.get_ch_num());
                        Server::Challenges[j + 1]->set_used(helper.get_used());
                        Server::Challenges[j + 1]->set_rating(helper.get_rating());
                        Server::Challenges[j + 1]->set_status(helper.get_status());
                    }
                }
            }
        }
        else if (list_by == "newest")
        {
            Challenge helper;
            for (int i = 0; i < Server::Challenges.size(); i++)
            {
                for (int j = 0; j < Server::Challenges.size() - 1; j++)
                {
                    if (Server::Challenges[j]->get_ch_num() < Server::Challenges[j + 1]->get_ch_num())
                    {
                        helper.set_ch_name(Server::Challenges[j]->get_ch_name());
                        helper.set_ch_num(Server::Challenges[j]->get_ch_num());
                        helper.set_used(Server::Challenges[j]->get_used());
                        helper.set_rating(Server::Challenges[j]->get_rating());
                        helper.set_status(Server::Challenges[j]->get_status());


                        Server::Challenges[j]->set_ch_name(Server::Challenges[j + 1]->get_ch_name());
                        Server::Challenges[j]->set_ch_num(Server::Challenges[j + 1]->get_ch_num());
                        Server::Challenges[j]->set_used(Server::Challenges[j + 1]->get_used());
                        Server::Challenges[j]->set_rating(Server::Challenges[j + 1]->get_rating());
                        Server::Challenges[j]->set_status(Server::Challenges[j + 1]->get_status());


                        Server::Challenges[j + 1]->set_ch_name(helper.get_ch_name());
                        Server::Challenges[j + 1]->set_ch_num(helper.get_ch_num());
                        Server::Challenges[j + 1]->set_used(helper.get_used());
                        Server::Challenges[j + 1]->set_rating(helper.get_rating());
                        Server::Challenges[j + 1]->set_status(helper.get_status());
                    }
                }
            }
        }
        print_ch();
    }
    else
    {
        cout << "Error : no Server opened." << endl;
    }

}

void Server::challenge_command()
{
    if (this->file_user_opened == 1 || this->file_ch_opened == 1)
    {
        string in_ch;
        cout << ">Username: ";
        getline(cin, in_ch);

        string ch;
        cout << ">Challenge : ";
        getline(cin, ch);

        string out_ch;
        cout << ">Send to : ";
        getline(cin, out_ch);

        if (ch.at(0) == '#')
        {
            bool have_ch = false;
            int index = -1;
            for (int i = 0; i < Server::Challenges.size(); i++)
            {
                if (Server::Challenges[i]->get_ch_name() == ch)
                {
                    have_ch = true;
                    index = i;
                }
            }
            if (have_ch == false)
            {
                Server::Challenges.push_back(new Challenge());

                Server::Challenges[Server::Challenges.size() - 1]->set_ch_name(ch);
                Server::Challenges[Server::Challenges.size() - 1]->set_ch_num(Server::Challenges.size());

                string name_helper = "";
                for (int i = 0; i < out_ch.length(); i++)
                {
                    if (out_ch.at(i) == ' ')
                    {
                        Server::Users_helper.push_back(new User());
                        Server::Users_helper[Server::Users_helper.size() - 1]->set_id(Server::Challenges.size());
                        Server::Users_helper[Server::Users_helper.size() - 1]->set_name(name_helper);

                        name_helper = "";
                    }
                    else
                    {
                        name_helper = name_helper + out_ch.at(i);
                    }
                }
                Server::Users_helper.push_back(new User());
                Server::Users_helper[Server::Users_helper.size() - 1]->set_id(Server::Challenges.size());
                Server::Users_helper[Server::Users_helper.size() - 1]->set_name(name_helper);

            }
            else
            {
                Server::Challenges[index]->set_used(Server::Challenges[index]->get_used() + 1);
                if (1 < Server::Challenges[index]->get_used() && Server::Challenges[index]->get_used() < 11)
                {
                    Server::Challenges[index]->set_status("quite recently");
                }
                else if (10 < Server::Challenges[index]->get_used())
                {
                    Server::Challenges[index]->set_status("old");
                }

                string name_helper = "";
                for (int i = 0; i < out_ch.length(); i++)
                {
                    if (out_ch.at(i) == ' ')
                    {
                        Server::Users_helper.push_back(new User());
                        Server::Users_helper[Server::Users_helper.size() - 1]->set_id(Server::Challenges[index]->get_ch_num());
                        Server::Users_helper[Server::Users_helper.size() - 1]->set_name(name_helper);

                        name_helper = "";
                    }
                    else
                    {
                        name_helper = name_helper + out_ch.at(i);
                    }
                }
                Server::Users_helper.push_back(new User());
                Server::Users_helper[Server::Users_helper.size() - 1]->set_id(Server::Challenges[index]->get_ch_num());
                Server::Users_helper[Server::Users_helper.size() - 1]->set_name(name_helper);
            }
        }
        else
        {
            cout << "Challenge failed" << endl;
        }
    }
    else
    {
        cout << "Error : no Server opened." << endl;
    }

}

void Server::finish_command()
{

    if (this->file_user_opened == 1 || this->file_ch_opened == 1)
    {
        string ch;
        cout << ">Challenge: ";
        getline(cin, ch);

        string id;
        cout << ">User_id : ";
        getline(cin, id);

        string rating;
        cout << ">Rating : ";
        getline(cin, rating);

        int index_user = -1;
        int index_ch = -1;

        if (string_to_double(rating) > 10 || string_to_double(rating) < -5)
        {
            cout << "Your rating must be between (-5 and 10)" << endl;
            cout << "Try again" << endl;
        }
        else
        {
            for (int i = 0; i < Server::Users.size(); i++)
            {

                if (Server::Users[i]->get_id() == string_to_double(id))
                {
                    index_user = i;
                }
            }

            if (index_user == -1)
            {
                cout << "There is not user with this Id:" << id << endl;
            }

            for (int i = 0; i < Server::Challenges.size(); i++)
            {
                if (Server::Challenges[i]->get_ch_name() == ch)
                {
                    index_ch = i;
                }
            }

            if (index_ch == -1)
            {
                cout << "There is not " << ch << " Challenge" << endl;
            }

            if ((-1 < index_ch) && (-1 < index_user))
            {
                int index_user_helper = -1;

                for (int i = 0; i < Server::Users_helper.size(); i++)
                {
                    if (Server::Users[index_user]->get_name() == Server::Users_helper[i]->get_name() && Server::Challenges[index_ch]->get_ch_num() == Server::Users_helper[i]->get_id())
                    {
                        index_user_helper = i;
                        cout << index_user_helper << "<---index" << endl;
                    }
                }

                if (index_user_helper != -1)
                {
                    if (Server::Challenges[index_ch]->get_ch_num() == Server::Users_helper[index_user_helper]->get_id())
                    {
                        cout << index_user_helper << "<---index" << endl;
                        Server::Challenges[index_ch]->set_rating(((Server::Challenges[index_ch]->get_rating() + string_to_double(rating)) / Server::Challenges[index_ch]->get_used()));
                        delete Server::Users_helper[index_user_helper]; //ne se trie kakto trqbwa

                    }
                }
                else
                {
                    cout << "There is not challenged user with this Id:" << id << endl;
                }

            }
            else
            {
                cout << "There is not challenged user with this Id:" << id << endl;
            }
        }
    }

    else
    {
        cout << "Error : no Server opened." << endl;
    }
}


///////////////////////////////

void Server::profile_info_command()
{
    if (this->file_user_opened == 1 || this->file_ch_opened == 1)
    {
        string name;
        cout << ">Name : ";
        getline(cin, name);

        for (int i = 0; i < Server::Users.size(); i++)
        {
            if (this->Server::Users[i]->get_name() == name)
            {
                this->Server::Users[i]->print();
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Error : no Server opened." << endl;
    }

}

void Server::activate()
{
    file_user_opened = 0;
    file_ch_opened = 0;

    const string challenge_ = R"(^challenge$)";
    const string finish_ = R"(^finish$)";
    const string profile_info_ = R"(^profile_info$)";
    const string list_ = R"(^list$)";

    const string exit = R"(^exit$)";
    const string load = R"(^load (([^\"\s]+)|(\"([^\"]+)\")) (([^\"\s]+)|(\"([^\"]+)\"))$)";
    const string save = R"(^save$)";
    const string saveas = R"(^saveas$)";
    const string close = R"(^close$)";
    const string registration = R"(^registration$)";
    const string print_user = R"(^print_user$)";
    const string print_ch = R"(^print_ch$)";

    const sregex_iterator end;

    const regex challenge_pattern = regex(challenge_);
    const regex finish_pattern = regex(finish_);
    const regex profile_info_pattern = regex(profile_info_);
    const regex list_pattern = regex(list_);
    const regex exit_pattern = regex(exit);
    const regex load_pattern = regex(load);
    const regex save_pattern = regex(save);
    const regex saveas_attern = regex(saveas);
    const regex close_pattern = regex(close);
    const regex registration_pattern = regex(registration);
    const regex print_user_pattern = regex(print_user);
    const regex print_ch_pattern = regex(print_ch);

    sregex_iterator iter;

    string text;
    while (true)
    {
        cout << ">";
        getline(cin, text);

        if ((iter = sregex_iterator(text.begin(), text.end(), challenge_pattern)) != end)
        {
            this->challenge_command();
        }
        if ((iter = sregex_iterator(text.begin(), text.end(), finish_pattern)) != end)
        {
            this->finish_command();
        }
        if ((iter = sregex_iterator(text.begin(), text.end(), profile_info_pattern)) != end)
        {
            this->profile_info_command();
        }
        if ((iter = sregex_iterator(text.begin(), text.end(), list_pattern)) != end)
        {
            this->list_command();
        }
        else if ((iter = sregex_iterator(text.begin(), text.end(), exit_pattern)) != end)
        {
            cout << "exiting..." << endl;
            break;
        }
        else if ((iter = sregex_iterator(text.begin(), text.end(), load_pattern)) != end)
        {
            string file_user_name = string((*iter)[2]) + string((*iter)[4]);
            string file_ch_name = string((*iter)[4]) + string((*iter)[6]);
            this->make_Server(file_user_name, file_ch_name);
        }
        else if ((iter = sregex_iterator(text.begin(), text.end(), save_pattern)) != end)
        {
            this->save_command();
        }
        else if ((iter = sregex_iterator(text.begin(), text.end(), saveas_attern)) != end)
        {
            this->save_as_command();
        }
        else if ((iter = sregex_iterator(text.begin(), text.end(), close_pattern)) != end)
        {
            this->close_command();
        }
        else if ((iter = sregex_iterator(text.begin(), text.end(), registration_pattern)) != end)
        {
            this->registration_command();
        }
        else if ((iter = sregex_iterator(text.begin(), text.end(), print_user_pattern)) != end)
        {
            this->print_user();
        }
        else if ((iter = sregex_iterator(text.begin(), text.end(), print_ch_pattern)) != end)
        {
            this->print_ch();
        }
        else
        {
            cout << "Error : invalid command syntax." << endl;
        }
        cout << endl;
    }
}

double string_to_double(const string& str)
{
    bool is_string = false;
    int br_dots = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str.at(i) == '.')
        {
            br_dots++;
        }
        if ((('0' <= str.at(i) && str.at(i) <= '9') || str.at(i) == '.') && br_dots <= 1)
        {

        }
        else
        {
            is_string = true;
            break;
        }
    }

    if (is_string == true)
    {
        return 0;
    }
    else
    {
        return stod(str);
    }

}
