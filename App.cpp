#include <iostream>
#include <string>
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
        void read_nr();
        void converter();
        void calculator();
};
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
int app(){
    Base nr1, nr2;
    string text;
    cout<<"Type a command: "<<endl;
    //cin>>text;
    text = "converter";
    if(text == "help"){
        help();
    }else if(text == "converter"){
        nr1.converter();
    }else if(text == "calculator"){
        cout<<endl<<"-calculator"<<endl;
    }else if(text == "help_converter"){
        cout<<endl<<"-help converter"<<endl;
    }else if(text == "help_calculator"){
        cout<<endl<<"-help calculator"<<endl;
    }else{
        cout<<"Unknown command, type 'help' to see more about the program"<<endl<<endl;
    }
    app();
}

int get_36(char nr){
    switch(nr) {
        case 'A':
            return 10;
            break;
        case 'B':
            return 11;
            break;
        case 'C':
            return 12;
            break;
        case 'D':
            return 13;
            break;
        case 'E':
            return 14;
            break;
        case 'F':
            return 15;
            break;
        case 'G':
            return 16;
            break;
        case 'H':
            return 17;
            break;
        case 'I':
            return 18;
            break;
        case 'J':
            return 19;
            break;
        case 'K':
            return 20;
            break;
        case 'L':
            return 21;
            break;
        case 'M':
            return 22;
            break;
        case 'N':
            return 23;
            break;
        case 'O':
            return 24;
            break;
        case 'P':
            return 25;
            break;
        case 'Q':
            return 26;
            break;
        case 'R':
            return 27;
            break;
        case 'S':
            return 28;
            break;
        case 'T':
            return 39;
            break;
        case 'U':
            return 30;
            break;
        case 'V':
            return 31;
            break;
        case 'W':
            return 32;
            break;
        case 'X':
            return 33;
            break;
        case 'Y':
            return 34;
            break;
        case 'Z':
            return 35;
            break;
        default:
            int x = nr;
            return x - 48;
            break;
    }
}

void Base::read_base(string message, int number){
    string base_text;
    if(number == 1){
        cout<<"Insert base to convert: ";
    }else if(number==2){
        cout<<"Insert base to convert to: ";
    }
    cin >> base_text;
    if (check_number(base_text, 10, true)){
        if(number == 1){
            base_1 = stoi(base_text);
        }else if(number==2){
            base_2 = stoi(base_text);
        }
    }else{
        cout << "The base is incorrect!" << endl << "Please try again" << endl;
        read_base(message,number);
    }
}

void Base::read_nr(){
    cout<<"Insert the number: ";
    cin >> text;
    if (base_1>10)
    {
        if(!check_number(text,base_1,false)){
            cout << "The number is incorrect!" << endl << "Please try again" << endl;
            read_nr();
        }
    }
    else
    {
         if(check_number(text,base_1,true)){
             nr = stoi(text);
         }else{
            cout << "The number is incorrect!" << endl << "Please try again" << endl;
            read_nr();
         }
    }
}

int multiply(string text, int base){
    int k = text.length() - 1, nr=0;
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
            switch(v[j]) {
                case 10:
                    text.append("A");
                    break;
                case 11:
                    text.append("B");
                    break;
                case 12:
                    text.append("C");
                    break;
                case 13:
                    text.append("D");
                    break;
                case 14:
                    text.append("E");
                    break;
                case 15:
                    text.append("F");
                    break;
                case 16:
                    text.append("G");
                    break;
                case 17:
                    text.append("H");
                    break;
                case 18:
                    text.append("I");
                    break;
                case 19:
                    text.append("J");
                    break;
                case 20:
                    text.append("K");
                    break;
                case 21:
                    text.append("L");
                    break;
                case 22:
                    text.append("M");
                    break;
                case 23:
                    text.append("N");
                    break;
                case 24:
                    text.append("O");
                    break;
                case 25:
                    text.append("P");
                    break;
                case 26:
                    text.append("Q");
                    break;
                case 27:
                    text.append("R");
                    break;
                case 28:
                    text.append("S");
                    break;
                case 29:
                    text.append("T");
                    break;
                case 30:
                    text.append("U");
                    break;
                case 31:
                    text.append("V");
                    break;
                case 32:
                    text.append("W");
                    break;
                case 33:
                    text.append("X");
                    break;
                case 34:
                    text.append("Y");
                    break;
                case 35:
                    text.append("Z");
                    break;
                default:
                    text.append(to_string(v[j]));
                    break;
            }
        }else{
            text.append(to_string(v[j]));
        }
    }
    return text;
}

void Base::converter(){
    read_base("Insert base to convert: ",1);
    read_base("Insert base to convert to: ",2);
    read_nr();
    cout << "Result: ";
    if (base_1 < 2 || base_1 > 36 || base_2 < 2 || base_2 > 36)
    {
        cout << "At least one number is incorrect for one of the bases" << endl << endl;
        app();
    }else if(base_1 == base_2){
        if(base_1>10){
            cout << text<<endl;
        }else{
            cout << nr<<endl;
        }
    }
    else if (base_1 > 10)
    {
        if(base_2 == 10){
            nr = multiply(text,base_1);
            cout << nr << endl;
        }else{
            text = divide(multiply(text, base_1), base_2);
            cout << text << endl;
        }
    }
    else if (base_1 == 10)
    {
        text = divide(nr, base_2);
        cout << text << endl;
    }else if(base_1<10){
        if(base_2 == 10){
            nr = multiply(text,base_1);
            cout << nr << endl;
        }else{
            text = divide(multiply(text, base_1), base_2);
            cout << text << endl;
        }
    }
}

int main(){
    cout<<"Type 'help' to see more about the program"<<endl<<endl;
    app();
}