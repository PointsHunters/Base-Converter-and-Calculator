#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int nr_1=0, nr_2=0, i=0, j=0, v[50];
char text_v[50];
string text_nr_1, text_nr_2;

void help(){
    cout<<endl<<"For more information on a specific command, type 'help_<command_name>'"<<endl<<endl;
    cout<<"converter    Converts a number's base to another base and displays it."<<endl;
    cout<<"calculator   Is doing very advanced math, like addition and substraction, between two numbers form any bases, same or different."<<endl;
    cout<<"help         Provides Help information for App commands."<<endl<<endl;
    cout<<"For more information on a specific command, type 'help_<command_name>'"<<endl<<endl;
}

int get_16(char nr){
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
        default:
            int x=nr;
            return x-48;
            break;
    }
}

void read_nr(int base_1){
    cout<<"Insert the number: ";
    i=0;
    if(base_1 > 15){
        // while(*(text_nr_1 + i) != '\n'){
        //     cin>>*(text_nr_1 + i);
        //     cout<<endl<<i<<" "<<*(text_nr_1 + i);
        //     i++;
        // }
        cin>>text_nr_1;
    }else{
        cin>>nr_1;
    }
}

int multiply(int nr, int base_2, string text_nr){
    int k=nr.length()-1;
    for(i=0;i<nr.length();i++){
        text_v[k]=text_nr[i];
        k--;
    }
    nr=0;
    for(int j=0;j<text_nr.length();j++){
        nr = nr + get_16(text_v[j])*pow(base_2,j);
    }
    //afisare rezultat
    cout<<"\nRezultatul conversiei in baza 10 este: "<<nr;
}

int divide(int nr,int base){
    int aux=0,k=0;
    while(nr != 0){
        aux = aux * 10 + nr%base;
        nr /= base;
        k++;
    }
    nr = 0;
    while(k != 0){
        nr = nr * pow(10,k) + aux%10;
        aux /= 10;
        k++;
    }
    return nr;
}

int converter(){
    int base_1,base_2,nr;
    cout<<"Insert base to convert: "; cin>>base_1;
    cout<<"Insert base to convert to: "; cin>>base_2;
    read_nr(base_1);
    cout<<"Result: ";
    // for(char *k=text_nr_1;k<text_nr_1 + i;k++){
    //     cout<<*(k);
    // }
    if(base_1 > 15){
        //se converteste char-ul in baza 10
        nr = get_16(text_v);
    }

    if(base_1 == base_2){
        cout<<nr;
    }else if(base_1 == 10){
        cout<<divide(nr,base_2);
    }else if((base_1 != 10)&&(base_2 == 10)){
        cout<<multiply(nr,base_2);
    }else{
        cout<<divide(multiply(nr,base_1),base_2);
    }
}

int app(){
    string text;
    cout<<"Type a command: ";
    cin>>text;
    if(text == "help"){
        help();
    }else if(text == "converter"){
        converter();
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

int main(){
    cout<<"Type 'help' to see more about the program"<<endl<<endl;
    app();
}