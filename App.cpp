#include <iostream>      //it is a header file that declares a set of functions for standard Input/Output. It also defines I/O stream objects such as cin, cout, clog, etc.
#include <string>       //used to work with strings
#include <cctype>      //used for the method that removes empty spaces before the input
#include <algorithm>  // ⬆️
#include <math.h>    //used for math
using namespace std;
int h = 0, v[50];
char text_v[50];

//this is the class where we are storing the necessary data for our numbers
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
}nr1, nr2; //this is where we declare our objects

//This is the face of the program.
void introduction()
{
    //cout <<"Base Converter and Calculator";
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

void app(); //we declare the app() method here to be able to use it into the other methods

//Provides the user with helpful information about the program.
void help(){
    cout<<endl<<"Commands of the program:"<<endl<<endl;
    cout<<"converter\tConverts a number's base\n\t\tto another base and displays it."<<endl;
    cout<<"calculator\tIs doing very advanced math,\n\t\tlike addition and substraction,\n\t\tbetween two numbers form any bases,\n\t\tsame or different."<<endl;
    cout<<"help\t\tProvides Help information\n\t\tfor App commands."<<endl<<endl;
    // cout<<"For more information on a specific command, type 'help_<command_name>'"<<endl<<endl;
}

//This method is used to convert a (char) number into a (int) number and returns it.
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

//It checks if a string is a number compatible with the program.
bool check_number(string str, int base, bool state)
{
    for (int i = 0; i < str.length(); i++){
        if(state){
            if (isdigit(str[i]) == false)
                return false;
        }else{
            if (!((isdigit(str[i]) == true)||(isalpha(str[i]) == true)))
                return false;
        }
    }
    return true;
}

//This method checks if the given number is accurate to the base.
bool check_base(string str, int base){
    for (int i = 0; i < str.length(); i++){
        if(get_36(str[i])>=base){
            return false;
        }
    }
    return true;
}

//This method is reading the number.
void Base::read_nr(int state){
    if(state == 0) cout<<"Insert the number: ";
    else if(state == 1) cout<<"Insert number one: ";
    else if(state == 2) cout<<"Insert number two: ";
    cin >> text;
    text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());
    for_each(text.begin(), text.end(), [](char & c) {
        c = ::toupper(c);
    });
    if(!check_number(text,base_1,false)){
        cout << "The number is incorrect!" << endl << "Please try again" << endl;
        read_nr(state);
    }
    if(!check_base(text,base_1)){
        cout << "The inserted number does not match to base!" << endl << "Please try again" << endl;
        read_nr(state);
    }
    if(base_1<=10) nr = stoi(text);
}

//This method is reading the base.
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

//This method converts a number from any other base to base 10.
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

//This method converts a number from base 10 to any other base.
string divide(int nr, int base){
    string text="";
    h = 0;
    while(nr!=0){ v[h]=nr%base; nr=nr/base; h++; }
    for(int j=h-1;j>=0;j--){
        if(base>10){
            int i=0,cont=0;
            do{
                if(v[j] == i+10){ text += char(65+i); cont = 1; i++; break; } i++;
            }while(i != 26);
            if(!cont){ text.append(to_string(v[j])); }
        }else{ text.append(to_string(v[j])); }
    }
    return text;
}

//This method is the center of the convertion.
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

//This method is used to calculate basic operations between two numbers of the same base.
double calculator(){
    string op;
    int nr_1,nr_2;
    nr_1 = stoi(nr1.converter());
    nr_2 = stoi(nr2.converter());
    cout<<"Select the operation (type: +,- or *):";
    cin>>op;
    if(op == "+")
        return nr_1+nr_2;
    else if(op == "-")
        return nr_1-nr_2;
    else if(op == "*")
        return nr_1*nr_2;
    // else if(op == "/")
    //     return nr_1/nr_2;
    else{
        cout<<endl<<"Insert a valid character for operation!"<<endl<<endl;
        return calculator();
    }
}

//Main method where the magic happens.
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

            //This instruction keeps the method running.
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
            nr1.read_base("Insert base of the numbers: ",1);
            nr2.base_1 = nr1.base_1;
            nr1.base_2 = nr2.base_2 = 10;
            nr1.read_nr(1);
            nr2.read_nr(2);
            nr1.nr = calculator();
            nr1.base_2 = nr1.base_1;
            nr1.base_1 = 10;
            if(nr1.nr < 0){
                nr1.nr *= -1;
                nr = nr1.converter();
                cout << "Result: -"<<nr<<endl<<endl;
            }else{
                nr = nr1.converter();
                cout << "Result: "<<nr<<endl<<endl;
            }

            //This instruction keeps the method running.
            cout <<"Keep going? (y/n): "; cin>>keep_going;
            keep_going.erase(remove_if(keep_going.begin(), keep_going.end(), ::isspace), keep_going.end());
            for_each(keep_going.begin(), keep_going.end(), [](char & c) {
                c = ::tolower(c);
            });
            if(keep_going == "0" || keep_going == "n" || keep_going == "no") break;
        }
    }
    else
    {
        cout<<"Unknown command, type 'help' to see more about the program"<<endl<<endl;
    }
    app();
}

//Also main method, but not that cool like app() method.
int main(){
    introduction();
    app();
}