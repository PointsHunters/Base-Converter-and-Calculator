#include <iostream>
#include <string>
#include <cctype>    //pentru comanda care elimina spatiile din fata 
#include <algorithm> // ⬆️
#include <math.h>
using namespace std;
int h = 0, v[50];
char text_v[50];

class Base
{
    public:
        int nr = 0;
        string text;
        int base_1;
        int base_2;
        void read_base(string message, int number);
        void read_nr(int state);
        string converter();
}nr1, nr2;


void app();

void help(){
    cout<<endl<<"For more information on a specific command, type 'help_<command_name>'"<<endl<<endl;
    cout<<"converter    Converts a number's base to another base and displays it."<<endl;
    cout<<"calculator   Is doing very advanced math, like addition and substraction, between two numbers form any bases, same or different."<<endl;
    cout<<"help         Provides Help information for App commands."<<endl<<endl;
    cout<<"For more information on a specific command, type 'help_<command_name>'"<<endl<<endl;
}

bool check_number(string str, int base, bool state)
{
    for (int i = 0; i < str.length(); i++){
        if(state){
            if (base != 2){
                if (isdigit(str[i]) == false)
                    return false;
            }else{
                if (!((isdigit(str[i]) == true) && (str[i] == '1' || str[i] == '0')))
                    return false;
            }
        }else{
            if (!((isdigit(str[i]) == true)||(isalpha(str[i]) == true)))
                return false;
        }
    }
    
    return true;
}

void introduction()
{
    //cout << "\t**Base Converter and Calculator**" << endl <<endl;
    cout << "888888b.    .d8888b.   .d8888b.      .d8888b.  "<<endl;
    cout << "888  '88b  d88P  Y88b d88P  '88b    d88P  Y88b "<<endl;
    cout << "888  .88P  888    888 Y88b. d88P    888    888 "<<endl;
    cout << "8888888K.  888         'Y8888P'     888        "<<endl;
    cout << "888  'Y88b 888        .d88P88K.d88P 888        "<<endl;
    cout << "888    888 888    888 888'  Y888P'  888    888 "<<endl;
    cout << "888   d88P Y88b  d88P Y88b .d8888b  Y88b  d88P "<<endl;
    cout << "8888888P'   'Y8888P'   'Y8888P' Y88b 'Y8888P'  "<<endl<<endl;
    cout << "Type 'help' to see more about the program" << endl <<endl;
}

int get_36(char nr){
    int i = 0;
    do{
        if(nr == char(65 + i)){
            return i + 10;
        }
        i++;
    }while(i + 10 != 36);
    int x = nr;
    return x - 48;
}

void Base::read_base(string message, int number){
    string base_text;
    cout<<message;
    cin >> base_text;
    if (check_number(base_text, 10, true)){
        if(number == 1){
            base_1 = stoi(base_text);
        }else if(number==2){
            base_2 = stoi(base_text);
        }
    }else{
        cout << "The base is incorrect! It should be a number between 2 and 36." << endl << "Please try again" << endl;
        read_base(message,number);
    }
}

void Base::read_nr(int state){
    if(state == 0) cout<<"Insert the number: ";
    else if(state == 1) cout<<"Insert number one: ";
    else if(state == 2) cout<<"Insert number two: ";
    cin >> text;
    if (base_1 > 10)
    {
        if(!check_number(text,base_1,false)){
            cout << "The number is incorrect!" << endl << "Please try again" << endl;
            read_nr(state);
        }
    }
    else
    {
         if(check_number(text,base_1,true)){
             nr = stoi(text);
         }else{
            cout << "The number is incorrect!" << endl << "Please try again" << endl;
            read_nr(state);
         }
    }
}

int multiply(string text, int base){
    int k = text.length() - 1, nr = 0;
    char text_v[50] = {0};
    for (int i = 0; i < text.length(); i++)
    {
        text_v[k] = text[i];
        k--;
    }
    for (int j = 0; j < text.length(); j++)
    {
        nr = nr + get_36(text_v[j]) * pow(base, j);
    }
    return nr;
}

string divide(int nr, int base){
    string text="";
    h = 0;
    while(nr!=0){
        v[h]=nr%base;
        nr=nr/base;
        h++;
    }
    for(int j=h-1;j>=0;j--){
        if(base>10){
            int i=0,cont=0;
            do{
                if(v[j] == i+10){
                    text += char(65+i);
                    cont = 1;
                    i++;
                    break;
                }
                i++;
            }while(i+10 != 36);
            if(!cont){
                text.append(to_string(v[j]));
            }
        }else{
            text.append(to_string(v[j]));
        }
    }
    return text;
}

string Base::converter(){
    if (base_1 < 2 || base_1 > 36 || base_2 < 2 || base_2 > 36)
    {
        cout << "At least one number is incorrect for one of the bases" << endl << endl;
        app();
    }else if(base_1 == base_2){
        if(base_1>10){
            return text;
        }else{
            return to_string(nr);
        }
    }
    else if (base_1 > 10)
    {
        if(base_2 == 10){
            nr = multiply(text,base_1);
            return to_string(nr);
        }else{
            text = divide(multiply(text, base_1), base_2);
            return text;
        }
    }
    else if (base_1 == 10)
    {
        text = divide(nr, base_2);
        return text;
    }else if(base_1<10){
        if(base_2 == 10){
            nr = multiply(text,base_1);
            return to_string(nr);
        }else{
            text = divide(multiply(text, base_1), base_2);
            return text;
        }
    }
    return 0;
}

int calculator(){
    string op;
    int nr_1,nr_2;
    nr_1 = stoi(nr1.converter());
    nr_2 = stoi(nr2.converter());
    cout<<"Select the operation (type: +,-,* or /):";
    cin>>op;
    if(op == "+")
        return nr_1+nr_2;
    else if(op == "-")
        return nr_1-nr_2;
    else if(op == "*")
        return nr_1*nr_2;
    else if(op == "/")
        return nr_1/nr_2;
    else
        calculator();
        return 0;
}

void app(){
    string text,nr,keep_going;
    cout<<"Type a command: ";
    cin>>text;
    // text = "converter";
    text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());
    for_each(text.begin(), text.end(), [](char & c) {
        c = ::tolower(c);
    });
    if (text == "help" || text == "h"){
        help();
    }
    else if (text == "converter" || text == "convert" || text == "conv")
    {
        while(true)
        {
            nr1.read_base("Insert base to convert: ",1);
            nr1.read_base("Insert base to convert to: ",2); nr1.read_nr(0);
            nr = nr1.converter();

            cout << "Result: "<<nr<<endl<<endl;

            cout <<"Keep going? (y/n): "; cin>>keep_going;
            keep_going.erase(remove_if(keep_going.begin(), keep_going.end(), ::isspace), keep_going.end());
            for_each(keep_going.begin(), keep_going.end(), [](char & c) {
                c = ::tolower(c);
            });
            if(keep_going == "0" || keep_going == "n" || keep_going == "no") break;
        }
    }
    else if (text == "calculator" || text == "calculate" || text == "calc")
    {
        while(true)
        {
            int aux;
            nr1.read_base("Insert base of the numbers: ",1);
            nr2.base_1 = nr1.base_1;
            nr1.base_2 = nr2.base_2 = 10;
            nr1.read_nr(1);
            nr2.read_nr(2);
            nr1.nr = calculator();
            nr1.base_2 = nr1.base_1;
            nr1.base_1 = 10;
            nr = nr1.converter();
            cout << "Result: "<<nr<<endl<<endl;
        
            cout <<"Keep going? (y/n): "; cin>>keep_going;
            keep_going.erase(remove_if(keep_going.begin(), keep_going.end(), ::isspace), keep_going.end());
            for_each(keep_going.begin(), keep_going.end(), [](char & c) {
                c = ::tolower(c);
            });
            if(keep_going == "0" || keep_going == "n" || keep_going == "no") break;
        }
    }
    else if (text == "help_converter")
    {
        cout<<endl<<"-help converter"<<endl<<endl;
    }
    else if (text == "help_calculator")
    {
        cout<<endl<<"-help calculator"<<endl<<endl;
    }
    else
    {
        cout<<"Unknown command, type 'help' to see more about the program"<<endl<<endl;
    }
    app();
}

int main(){
    introduction();
    app();
}
