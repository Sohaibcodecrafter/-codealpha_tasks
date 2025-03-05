#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Customer{
public:
    string name,id;
    Customer(string n,string i)
    {
        name=n;
        id=i;
    }
};

class Account{
public:
    string accNo;
    double balance;
    Account(string a,double b)
    {
        accNo=a;
        balance=b;
    }
    void deposit(double amt)
    {
        if(amt>0)
        balance+=amt;
    }
    bool withdraw(double amt)
    {
        if(amt>0&&amt<=balance)
        {
            balance-=amt;
            return 1;
        }
        return 0;
    }
};

class Transaction{
public:
    string accNo,type;
    double amount;
    Transaction(string a,string t,double amt)
    {
        accNo=a;
        type=t;
        amount=amt;
    
}
};

class Bank{
    vector<Customer>customers;
    vector<Account>accounts;
    vector<Transaction>transactions;
public:
    void createCustomer(string n,string i)
    {
        customers.push_back(Customer(n,i));
    }
    void createAccount(string i,string a,double b)
    {
        accounts.push_back(Account(a,b));
    }
    Account*findAccount(string a)
    {
        for(auto&acc:accounts)
        if(acc.accNo==a)
        return&acc;
        return nullptr;
    }
    void deposit(string a,double amt)
    {
        Account*acc=findAccount(a);
        if(acc)
        {
            acc->deposit(amt);
            transactions.push_back(Transaction(a,"Deposit",amt));
        }
    }
    void withdraw(string a,double amt)
    {
        Account*acc=findAccount(a);
        if(acc&&acc->withdraw(amt))
        transactions.push_back(Transaction(a,"Withdraw",amt));
    }
    void transfer(string from,string to,double amt)
    {
        Account*a1=findAccount(from),*a2=findAccount(to);
        if(a1&&a2&&a1->withdraw(amt))
        {
            a2->deposit(amt);transactions.push_back(Transaction(from,"Transfer",amt));
        }
    }
    void viewAccount(string a)
    {
        Account*acc=findAccount(a);
        if(acc)
        cout<<"Balance:"<<acc->balance<<"\n";
        else 
        cout<<"Invalid account\n";}
};

int main(){
    Bank bank;
    int ch;
    string name,id,accNo,toAcc;
    double amt;
    do{
        cout<<"1.Create Customer\n2.Create Account\n3.Deposit\n4.Withdraw\n5.Transfer\n6.View Account\n7.Exit\n";
        cin>>ch;
        if(cin.fail()){cin.clear();cin.ignore();cout<<"Invalid input\n";continue;}
        switch(ch){
            case 1:
            cout<<"Name:";
            cin>>name;
            cout<<"ID:";
            cin>>id;
            bank.createCustomer(name,id);
            break;
            case 2:
            cout<<"Customer ID:";
            cin>>id;
            cout<<"Account No:";
            cin>>accNo;
            cout<<"Initial Balance:";
            cin>>amt;
            bank.createAccount(id,accNo,amt);
            break;
            case 3:
            cout<<"Account No:";
            cin>>accNo;
            cout<<"Amount:";
            cin>>amt;
            bank.deposit(accNo,amt);
            break;
            case 4:
            cout<<"Account No:";
            cin>>accNo;
            cout<<"Amount:";
            cin>>amt;
            bank.withdraw(accNo,amt);
            break;
            case 5:
            cout<<"From Account:";
            cin>>accNo;
            cout<<"To Account:";
            cin>>toAcc;
            cout<<"Amount:";
            cin>>amt;
            bank.transfer(accNo,toAcc,amt);
            break;
            case 6:
            cout<<"Account No:";
            cin>>accNo;
            bank.viewAccount(accNo);
            break;
            case 7:break;
            default:cout<<"Invalid choice\n";
        }
    }while(ch!=7);
    return 0;
}
