#include <iostream>
#include<fstream>
using namespace std;
class account{
private:
    string name,password,pass,fdet[5];
public:
    void create()
    {
        cout<<"Choose an  username: ";
        cin>>fdet[0];
        cout<<"Choose your password(please avoid using # in it): ";
        cin>>fdet[1];
        cout<<"Enter your phone number: ";
        cin>>fdet[2];
        cout<<"Enter your address: ";
        cin>>fdet[3];
        cout<<"Do you want to deposit some money(0 if no): ";
        cin>>fdet[4];
        fstream o;
        o.open(fdet[0]+".txt",ios::out);
        o<<fdet[0]+"#"+fdet[1]+"#"+fdet[2]+"#"+fdet[3]+"#"+fdet[4];
        o.close();
        for(int it=0;it<5;it++)
        {
            fdet[it].clear();    // clears string same as det[i]=""
        }
        cout<<"Account created succesfully!\n";
    }
    bool login()
    {
        cout<<"Enter your name: ";
        cin>>name;
        cout<<"Enter your password: ";
        cin>>password;
        fstream o;
        o.open(name+".txt",ios::in);
        char ch;
        int k=0;
        while(!o.eof())
        {
            o>>ch;
            if(ch=='#')
            {
                k++;
            }
            else{
                fdet[k]+=ch;
            }
        }
        o.close();
        //cout<<" # "<<password<<"@"<<det1[1]<<endl;
        pass=fdet[1];
        for(int it=0;it<5;it++)
        {
            fdet[it].clear();    // clears string same as det[i]=""
        }
        if(password==pass){
            cout<<"Correct credentials!\n";
            return true;
        }
        else{
            cout<<"Wrong credentials!\n";
            return false;
        }
    }
    void tasks()
    {
        char choice='y';
        fstream o;
        o.open(name+".txt",ios::in);
        char ch;
        int k=0,choi;
        while(!o.eof())
        {
            o>>ch;
            if(ch=='#')
            {
                k++;
            }
            else{
                fdet[k]+=ch;
            }
        }
        o.close();
        /*for(int it=0;it<5;it++)
        {
            cout<<fdet[it]<<"  ";
        }*/
        while(choice=='y')
        {
            cout<<"\n         MAIN MENU       \n";
            cout<<"1>Withdraw\n2>Deposit\n3>show balance\n4>Show details\n5>return to main menu\n"
                  "6>Return to login portal\n7>Exit program\n8>Money transfer\nEnter your choice:";
            cin>>choi;
            if(choi==1)
            {
                float am;
                cout<<"Enter how much you want to withdraw:";
                cin>>am;
                if(stof(fdet[4])<am)
                {
                    cout<<"Not enough balance\n";
                    cout<<"available balance is: "<<fdet[4]<<endl;
                }
                else{
                    float zz=stof(fdet[4])-am;
                    fdet[4]=to_string(zz);
                    cout<<"amounts rs "<<am<<" is withdrewn from your account\n";
                }
                cout<<"\nDo you wish to perform  more options('y' or 'n'):";
                cin>>choice;
            }
            else if(choi==2)
            {
                float am;
                cout<<"Enter how much you want to deposit:";
                cin>>am;
                float z=stof(fdet[4])+am;
                fdet[4]=to_string(z);
                cout<<"amounts rs "<<am<<" is deposited to your account\n";
                cout<<"\nDo you wish to perform  more options('y' or 'n'):";
                cin>>choice;
            }
            else if(choi==3)
            {
                cout<<"Available balance is:"<<fdet[4]<<endl;
                cout<<"\nDo you wish to perform  more options('y' or 'n'):";
                cin>>choice;
            }
            else if(choi==4)
            {
                cout<<"Name is : "<<fdet[0]<<"\n";
                cout<<"Phone number is: "<<fdet[2]<<"\n";
                cout<<"Adress : "<<fdet[3]<<"\n";
                cout<<"Available Balance is: "<<fdet[4]<<"\n";
                cout<<"\nDo you wish to perform  more options('y' or 'n'):";
                cin>>choice;
            }
            else if(choi==8)
            {
                float govi=transfer();
                fdet[4]=to_string(stof(fdet[4])-govi);
                cout<<"\nDo you wish to perform  more options('y' or 'n'):";
                cin>>choice;
            }
            else if(choi>8)
            {
                cout<<"Wrong input\nPlease try again\n";
                choice='y';
            }
            fstream b;
            b.open(fdet[0]+".txt",ios::out);
            b<<fdet[0]+"#"+fdet[1]+"#"+fdet[2]+"#"+fdet[3]+"#"+fdet[4];
            b.close();

            if(choi==5)
            {
                choice='y';
            }
            else if(choi==6)
            {
                choice='n';
            }
            else if(choi==7)
            {
                cout<<"\nThanks for choosing our bank😊.Hope you have a good day";
                exit(0);
            }
        }
        for(int it=0;it<5;it++)
        {
            fdet[it]="";
        }

    }
    float static transfer()
    {
        string det2[5];
        cout<<"Enter username of account for which you eant to transfer money: ";
        cin>>det2[0];
        fstream ac;
        char x;
        float vid;
        int in=0;
        ac.open(det2[0]+".txt",ios::in);
        det2[0]="";
        while(!ac.eof())
        {
            ac>>x;
            if(x=='#')
            {
                in++;
            }
            else{
                det2[in]=det2[in]+x;
            }
        }
        ac.close();
        cout<<"Enter how much you want to transfer: ";
        cin>>vid;
        cout<<"\nTransfering process started.........\n";
        //cout<<det2[0]+"#"+det2[1]+"#"+det2[2]+"#"+det2[3]+"#"+det2[4];
        det2[4]=to_string(stof(det2[4])+vid);
        ac.open(det2[0]+".txt",ios::out);
        ac<<det2[0]+"#"+det2[1]+"#"+det2[2]+"#"+det2[3]+"#"+det2[4];
        ac.close();
        cout<<"Amount transfered successsfullly\n";
        return vid;
    }
};
/*bool isexist(string a)
{
    fstream ab;
    ab.open(a+".txt",ios::app);
    char ch;
    while(!ab.eof())
    {
        ab>>ch;
        if(ch==NULL)
        {
            return false;
        }
        else{
            return true;
        }
    }
}*/
int main()
{
    account ob;
    int s=1;
    cout<<"\n                 Welcome to Near's Banking System\n";
    cout<<"*************************************************************************\n\n";
    while(s)
    {
        cout<<"\n\n1>Create account\n2>Login to existing account\n3>Exit\nEnter your choice: ";
        cin>>s;
        if(s==1)
        {
            cout<<"Welcome to account creation portal\n";
            ob.create();
        }
        else if(s==2)
        {
            cout<<"Welcome to login portal\n";
            bool x=ob.login();
            if(x)
            {
                ob.tasks();
            }
        }
        else if(s==3){
            s=0;
        }
        else{
            cout<<"Wrong input\n";
            s=4;
        }
    }
    cout<<"\nThanks for choosing our bank😊.Hope you have a good day";
    return 0;
}
