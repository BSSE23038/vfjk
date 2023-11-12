#include <iostream>
#include "functions.h"
using namespace std;

int main ()
{
    int identity;
    cout <<"\t\t\t<-- Welcome To 'Textile Nexus' -->\n\n\n";            //Welcome notes
    cout <<"\tEnter Your Identity.\n";                                  //Asking for identity like owner,worker,etc
    cout<<"\t\t\n--> 1 For Owner\n--> 2 For Worker\n--> 3 For Customer\n";
    cin >> identity;
    cin.ignore();
    if(identity==1){
        int functions_of_owner;
        system("clear");                                                //To clear the system already presenting on screen
        cout <<"\t\t\t\t<-- Identity Successfully Matched --> \n" << endl;
        owner(identity);
        cout<<"--> Enter 1 To Assign Work To Workers with their Names.\n";      //Asking for functionality
        cout<<"--> Enter 2 To Add Pieces' Information.\n";
        cout<<"--> Enter 3 To Get Working Hours of Any Worker.\n";
        cout<<"--> Enter 4 To Calculate Salary of Any Worker.\n";
        cout<<"--> Enter 5 To Check Attendance of Any Worker.\n";
        cin >> functions_of_owner;
        cin.ignore();
        if(functions_of_owner==1){
            system("clear");
            assign_Work();
        }
        else if(functions_of_owner==2){
            system("clear");
            piecesInfo();
        }

        else if(functions_of_owner==3){
            system("clear");
            watchHours();
        }
        else if(functions_of_owner==4){
            system("clear");
            calculateSalary();
        }
        else if(functions_of_owner==5){
            system("clear");
            watchAttendance();
        }

    }
    else if(identity==2) {
        int functions_of_worker;
        system("clear");
        cout << "\t\t\t\tIdentity Successfully Matched.\n\n" << endl;
        worker(identity);
        cout << "--> Enter 1 To Mark Attendance : \n";
        cout << "--> Enter 2 To Check Your Work Task:\n";
        cout << "--> Enter 3 To Check Your Total Working Hours:\n";
        cin >> functions_of_worker;
        cin.ignore();
        if (functions_of_worker == 1) {
            system("clear");
            markAttendance();
        } else if (functions_of_worker == 2) {
            system("clear");
            worker_Task();
        }
        else if (functions_of_worker == 3) {
            system("clear");
            working_hours();
        }
    }
    else if(identity==3){
        system("clear");
        cout <<"\t\t\tAvailable Stock In Our Inventory !!!\n\n" << endl;
        customer(identity);
    }
    else if(identity<1||identity>3){
        cout <<"\t\t\t\tInvalid Identity." << endl;
        }
}
