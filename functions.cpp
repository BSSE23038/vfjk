#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;
int daysOfWork;
int acc_verification = 0, pass_updated = 0;
struct Pieces {
    string size, color, price;
    int quantity;
};
struct Worker{
    string name;
    int workingHours;
};
Worker p1[1000];







void assign_Work() {
    int sml_Swt,mdm_Swt,lrg_Swt;
    int ttl_Sml_Swt=0,ttl_Mdm_Swt=0,ttl_Lrg_Swt=0;
    string sml_Clr,mdm_Clr,lrg_Clr;
    string name;
    int numb;
    ofstream assign_Own("assign.txt");        //making file of for storing work
    if(!assign_Own){
        cout<<"Error";
    }
    else {
        cout<<"Enter the number of your worker: ";
        cin>>numb;
        cin.ignore();
        for(int i=1;i<=numb;++i) {
            cout << "Enter the name of worker " << i << " : ";
            getline(cin,name);
            assign_Own<<name<< "\t";
            cout <<"\t\tEnter the work specification for "<<name<<" here: "<< endl;    //To center
            cout << "Enter the amount of sweater of Small  sizes: ";
            cin >> sml_Swt;
            assign_Own<<sml_Swt << "\t";
            ttl_Sml_Swt += sml_Swt;
            cin.ignore();
            cout << "Enter the colour for smaller size: ";
            cin >> sml_Clr;
            assign_Own<<sml_Clr<< "\t";
            cin.ignore();
            cout << "Enter the amount of sweater of Medium  sizes: ";
            cin >> mdm_Swt;
            assign_Own<<mdm_Swt<< "\t";
            ttl_Mdm_Swt += mdm_Swt;
            cin.ignore();
            cout << "Enter the colour for Medium size: ";
            cin >> mdm_Clr;
            assign_Own<<mdm_Clr << "\t";
            cin.ignore();
            cout << "Enter the amount of sweater of Large  sizes: ";
            cin >> lrg_Swt;
            assign_Own<<lrg_Swt << "\t";
            ttl_Lrg_Swt += lrg_Swt;
            cin.ignore();
            cout << "Enter the colour for Larger size: ";
            cin >> lrg_Clr;
            assign_Own<<lrg_Clr<<endl;
            cin.ignore();
            assign_Own.close();
            cout << endl;
            system("clear");
            if(i<numb){
                cout << "\t\t\tEnter the work for next worker : "<<endl;}
        }

        cout<<"\t\t\tYour Total entered work for All worker "<<endl;
        cout<<"Amount of smaller size = "<<ttl_Sml_Swt<<endl;
        cout<<"Amount of medium size = "<<ttl_Mdm_Swt<<endl;
        cout<<"Amount of larger size = "<<ttl_Lrg_Swt<<endl;
        cout<<endl;
    }
}
void worker_Task(){
    string name, nameFromFile, color1, color2, color3;
    int amount1, amount2, amount3;
    cout <<"Enter Your Name : ";
    getline(cin, name);
    system("clear");
    ifstream get_work("assign.txt");
    cout <<"\t\t\t<-- Here is Your Assigned Task -->\n\n";
    cout<<"Size"<<"\t\tAmount"<<"\t\tColour"<<endl;
    while(get_work >> nameFromFile){
        if(nameFromFile==name)
            while(get_work >> amount1 >> color1 >> amount2 >> color2 >> amount3 >> color3){
                cout <<"Small"<< "\t\t"<<amount1 <<"\t\t"<< color1 << endl;
                cout <<"Medium"<<"\t\t"<<amount2 <<"\t\t"<< color2 << endl;
                cout <<"Large"<<"\t\t"<< amount3 <<"\t\t"<< color3 << endl;
            }
    }

}
void watchAttendance(){
    string name, nameFromFile;
    int hours, count=0;
    cout <<"Enter The Name of Worker: ";
    getline(cin, name);
    ifstream check_hours("att&wor_hour.txt");
    while (check_hours >> nameFromFile){
        if(nameFromFile==name){
            while (check_hours >> hours){
                count+=1;
            }
            cout <<"The Total  Present Days of " << name <<" Are " << count << endl;
            return;
        }


    }
    cout <<"Name Doesn't Matched." << endl;
}
void working_hours(){
    string name, nameFromFile;
    int sum, hour;
    cout <<"Enter Your Name: ";
    getline(cin, name);
    system("clear");
    ifstream work_hour("att&wor_hour.txt");
    while (work_hour >> nameFromFile) {
        if (name == nameFromFile) {
            while(work_hour >> hour){
                sum+=hour;
            }
            cout << "\t\t\tYour Total Working Hours are " << sum << " ." << endl;
            return;
        }

    }
    cout <<"\t\t\tName Doesn't Matched!" << endl;

}
