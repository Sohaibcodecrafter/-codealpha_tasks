#include<iostream>
#include<fstream>
using namespace std;

void registerUser(){
    string username,password;
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;
    ofstream file(username+".txt");
    file<<username<<endl<<password;
    file.close();
    cout<<"Registration successful!\n";
}

bool loginUser(){
    string username,password,un,pw;
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;
    ifstream file(username+".txt");
    if(file){
        getline(file,un);
        getline(file,pw);
        if(un==username&&pw==password){
            cout<<"Login successful!\n";
            return true;
        }
    }
    cout<<"Invalid credentials!\n";
    return false;
}

int main(){
    int choice;
    while(true){
        cout<<"1. Register\n2. Login\n3. Exit\nEnter choice: ";
        cin>>choice;
        if(choice==1)registerUser();
        else if(choice==2)loginUser();
        else if(choice==3)break;
        else cout<<"Invalid choice!\n";
    }
    return 0;
}
