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

void changePass(int x) {
    string username, id, newUsername, password, pass, newPassword;
    cout << "Enter Previous Username & Password" << endl;
    cout << "Enter Username: ";
    getline(cin, username);
    cout << "Enter Password: ";
    getline(cin, password);
    system("clear");
    ifstream passChange("Owner.txt");
    while (passChange >> id >> pass) {
        if (username == id && password == pass) {
            cout << "Enter New Username & Password." << endl;
            cout << "Enter Username: ";
            getline(cin, newUsername);
            cout << "Enter Password: ";
            getline(cin, newPassword);
            system("clear");
            ofstream updated("Owner.txt");
            updated << newUsername << endl;
            updated << newPassword << endl;
            updated.close();
            cout << "\t\t\tUsername & Password Changed Successfully!!!" << endl;

        } else {
            cout << "Wrong Username or Password, Kindly Enter Correct Credentials" << endl;
            changePass(1);
        }
        passChange.close();

    }
}


void owner_regis() {
    string username, password;
    cout << "Change Username & Password" << endl;
    cout << "Enter Username: ";
    getline(cin, username);
    cout << "Enter Password: ";
    getline(cin, password);
    ofstream user_pass_change("Owner.txt");
    user_pass_change << username << endl;
    user_pass_change << password << endl;
    user_pass_change.close();
}

void owner(int x) {
    int passUpdate;
    string username, password, id, pass;
    ifstream owner_detail1("Owner.txt");
    while (owner_detail1 >> id >> pass) {
        if (id == "QWERTY" && pass == "1234") {
            cout << "\tEnter Your Username & Password !!! ( Default Username: QWERTY & Password: 1234 )\n\n";
        } else {
            cout << "\tEnter 0 TO Login Using Updated Username & Password or Enter 1 To Change Username & Password : ";
            cin >> passUpdate;
            cin.ignore();
            pass_updated = 1;
        }
    }
    if (passUpdate == 0) {
        cout << "Username:";
        getline(cin, username);
        cout << "Password:";
        getline(cin, password);
        ifstream owner_detail("Owner.txt");
        while (owner_detail >> id >> pass) {
            if (id == username && pass == password) {
                system("clear");
                acc_verification = 1;
                cout << "\t\t\tLogin successful !!!\n\n" << endl;
            } else {
                system("clear");
                cout << "\t\t\tWrong Username or Password." << endl;
                owner(1);
            }
        }
        if (acc_verification == 1 && pass_updated == 0) {
            owner_regis();
        }
    } else { changePass(1); }
}

void worker(int x) {
    string username, password, id1, pass1;
    cout << "\tEnter Your Username & Password\n\n";
    cout << "Username:";
    getline(cin, username);
    cout << "Password:";
    getline(cin, password);
    ifstream worker_detail("Worker.txt");
    while (!worker_detail.eof()) {
        worker_detail >> id1 >> pass1;
        if (username == id1 && password == pass1) {
            system("clear");
            cout << "\t\t\tLogin successful !!!" << endl;
            return;
        }
    }
    system("clear");
    cout << "\t\t\tWrong Username or Password." << endl;
    worker(1);

}





void customer(int x) {
    string  color, price, size,color1;
    int quantity, num, size1[100], quantity1[100];
    float priceOfLarge = 50 , priceOfSmall = 15 ,priceOfMedium = 35, totalBill=0;
    cout << left << setw(20) << "Sizes" << setw(20) << "Colors" << setw(23) << " Prices" << "Quantity\n"
         << endl;
    ifstream listInput("Listings.txt");
    while (listInput >> size >> color >> price >> quantity) {
        cout << left << setw(20) << size << setw(23) << color << setw(20) << price << quantity << " Pieces" << endl;
    }
    int numOfProducts;
    cout <<"\n\n\t\t\tSelect Products To Get The Total Price !!!";
    cout <<"\n\nEnter The Number of different Products You Want To purchase : ";
    cin >> numOfProducts;
    cin.ignore();
    for (int i=0; i<numOfProducts; i++){
        cout<<"Please enter the color you want for product : "<<i+1<<endl;
        cin>>color1;
        cout<<"Please enter the size of product : "<<i+1<<endl;
        cout<<"Press 1 for large size"<<endl;
        cout<<"Press 2 for medium size"<<endl;
        cout<<"press 3 for small size" <<endl;
        cin>>size1[i];
        cout<<"Please enter the quantity you want to purchase for this specific item : "<<endl;
        cin>>quantity1[i];
    }
    cout<<"Press '1' to generate bill or press '0' if you want to shop more ! "<<endl;
    cin>>num;
    if (num == 1) {
        for (int i = 0; i < numOfProducts; i++) {
            switch (size1[i]) {
                case 1:
                    totalBill = totalBill + quantity1[i] * priceOfLarge;
                    break;
                case 2:
                    totalBill = totalBill + quantity1[i] * priceOfMedium;
                    break;
                case 3:
                    totalBill = totalBill + quantity1[i] * priceOfSmall;
                    break;

            }
        }
        cout <<"Your total bill is : " << totalBill << "$" << endl;
        cout <<"Thank You for shopping at Textile Nexus"<<endl;
    }
}


void markAttendance(){
    static int namei=0;
    cout <<"\t\t\t<-- Attendance -->\n\n";
    cout <<"Enter Your Name : ";
    cin >> p1[namei].name;
    cout <<"Enter The Number of Days You Want To Mark Present : ";
    cin >> daysOfWork;
    cin.ignore();
    ofstream attendance_working_hours("att&wor_hour.txt", ios::app);
    attendance_working_hours << p1[namei].name << "\t";
    for(int i=0; i<daysOfWork; i++){
        cout <<"Enter The Working Hours of Day " << i+1 <<" : ";
        cin >> p1[i].workingHours;
        cin.ignore();
        attendance_working_hours << p1[i].workingHours <<"\t";
    }
    attendance_working_hours << endl;
    attendance_working_hours.close();
}
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
