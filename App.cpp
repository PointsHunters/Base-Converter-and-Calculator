#include <iostream>
#include <string>
using namespace std;

void help(){
    cout<<endl<<"For more information on a specific command, type 'help <command_name>'"<<endl<<endl;
    cout<<"converter    Converts a number's base to another base and displays it."<<endl;
    cout<<"calculator   Is doing very advanced math, like addition and substraction, between two numbers form any bases, same or different."<<endl;
    cout<<"help         Provides Help information for App commands."<<endl<<endl;
    cout<<"For more information on a specific command, type 'help <command_name>'"<<endl<<endl;
}

int app(){
    string text;
    cout<<"Type a command: ";
    cin>>text;
    if(text == "help"){
        help();
    }else if(text == "converter"){
        cout<<endl<<"-converter"<<endl;
    }else if(text == "calculator"){
        cout<<endl<<"-calculator"<<endl;
    }else if(text == "help converter"){
        cout<<endl<<"-help converter"<<endl;
    }else if(text == "help calculator"){
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