#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<iomanip>
#include<cstdio>
#include<stdlib.h>
#include "UserClass.h"
#include <stdio.h>
#include <cstring>
#include "Database.h"
using namespace std;

class SystemClass
{
	private:
		int i;
		UserClass userArr[100]; 
		UserClass user; 

		struct userAtt
		{
			long int id;
			string name;
			string pass;
			int age;
			string email;
		};

	public:
		SystemClass(){}
		void addUser();
		bool checkUserDetail(UserClass user);
		void logIn();
		void signUp();
		void logInSucc();
		void mainSystem();
		void openFile();
		void appendFile(int a);
};

void SystemClass::addUser()
{
	int select;
	UserClass addUser;
	addUser.setAll();
	userArr[i] = UserClass(addUser.getUser_id(), addUser.getUser_name(), addUser.getUser_age(),
	addUser.getUser_email(), addUser.getUser_pass());
	i++;
	appendFile(1);
}

bool SystemClass::checkUserDetail(UserClass user)
{
	int a=0;
	bool c=0, d=0;
	if(i==0){
		return false;
	}
	else{
		for(int a=0; a<i; a++){
			if(user.getUser_email() == userArr[a].getUser_email()){
                c = 1;
			}
			if(user.getUser_pass() == userArr[a].getUser_pass()){
				d = 1;
			}
		}

		if(c != 1){
				cout << "\nNo Email exists in Database.\n";
			}
        if(c == 1 && d != 1){
			cout << "\nWrong password.\n";
		}
	}

	system("PAUSE");

	if(i != 0 && c == 1 && d == 1)
        return true;
    else
        return false;
}

void SystemClass::logIn()
{
	system("cls");
	cout << "\nLOG IN" << endl;
	user.setUserEmail();
	user.setUserPass();
	while(checkUserDetail(user) == true){
		logInSucc();
	}
}

void SystemClass::signUp()
{
	system("cls");
	cout << "SIGN UP" << endl;
	addUser();
	mainSystem();
}

void SystemClass::openFile()
{
	i=0;
	userAtt userAtt[100];

	string user_id;
	string id, age;

	ifstream userF("userDetail.txt");

	if(!userF.is_open())
		cout << "ERROR: File Open\n";
	
	while(userF.good()){
		getline(userF, id, ',');
		getline(userF, userAtt[i].name, ',');
		getline(userF, userAtt[i].pass, ',');
		getline(userF, age, ',');
		getline(userF, userAtt[i].email);

		// convert string to int
		stringstream strTointID(id);
		strTointID >> userAtt[i].id;
		stringstream strTointAge(age);
		strTointAge >> userAtt[i].age;
		i++;
	}

	for(int m=0; m<i; m++){
		userArr[m] = UserClass(userAtt[m].id, userAtt[m].name, userAtt[m].age,
		userAtt[m].email, userAtt[m].pass);
	}
	
	userF.close();
}

void SystemClass::appendFile(int a)
{
	ofstream userF;
	if(a == 1){
		userF.open("userDetail.txt", ios::app);
		if(i>1){
			userF << "\n" << userArr[i-1].getUser_id() << "," << userArr[i-1].getUser_name() << ","
			<< userArr[i-1].getUser_pass() << "," << userArr[i-1].getUser_age() << ","
		    << userArr[i-1].getUser_email();
		}
		else{
			userF << userArr[i-1].getUser_id() << "," << userArr[i-1].getUser_name() << ","
			<< userArr[i-1].getUser_pass() << "," << userArr[i-1].getUser_age() << ","
			<< userArr[i-1].getUser_email();
		}
		userF.close();
	}
}

void SystemClass::logInSucc()
{
	  //  Innitialize object
	Database db;
	Doctor myDoctor[10];
	Patient myPatient[10];

    //  Pre-set data for doctor structure array
    Doctor A1("901112-13-0981", "Cristiano Ronaldo",  "011-9012120", "cr7@gmail.com", "no", "yes");
    Doctor A2("901022-13-0991", "Michael Jackson", "013-1812999", "mj@gmail.com", "no", "yes");
    Doctor A3("780209-13-0131", "Adam Levine", "016-1299991", "levine@hotmail.com", "no", "no");
    Doctor A4("910101-13-0279", "Peter Parker", "019-8910981", "pp@gmail.com", "yes", "no");
    Doctor A5("981109-13-0119", "Roberto Carlos", "012-1211095", "rcbanana@gmail.com", "yes", "yes");
    myDoctor[0] = A1;
    myDoctor[1] = A2;
    myDoctor[2] = A3;
    myDoctor[3] = A4;
    myDoctor[4] = A5;
    
    //Pre-set data for patients
    Patient D1("410112-13-0321", "Steve Rogers",  "011-9012120", "NIL", "yes", "yes", "910101-13-0279", "Peter Parker");
    Patient D2("390521-13-0191", "Alex Ferguson", "013-1812999", "NIL", "no", "yes", "981109-13-0119", "Roberto Carlos");
    myPatient[0] = D1;
    myPatient[1] = D2;
    
    //  Variable to indicated the occupied elements within patient and doctor object array
    int doctorIndex = 5;
    int patientIndex = 2;

    //  Variable to store status code for exit or continue main program
	char exitStatus = '0';

    //  Variable to store main menu option selected by user
	char option;

    //  Variable to store main menu option selected by user
	while (exitStatus == '0') {
        //  Call function to display main menu options
		db.DisplayMenu();

        //  Capture option from user input
		cin >> option;

		if(option == '1') {
            // Call add new individual function and passed related pointers as parameter
			db.Add(myDoctor, &doctorIndex, myPatient, &patientIndex);
		}
		else if(option == '2') {
            // Call delete individual records
            system("cls");
            db.Delete(myDoctor, &doctorIndex, myPatient, &patientIndex);
            system("pause");       
        }
		else if(option == '3') {
            // Call display all individual records
            system("cls");
            db.View(myDoctor, &doctorIndex, myPatient, &patientIndex);
            system("pause");       
        }
		else if(option == '4') {
            // Call search individual records
            system("cls");
            db.Search(myDoctor, &doctorIndex, myPatient, &patientIndex);
            system("pause");       
        }
	     else if(option == '0'){
            exitStatus = '1';
            cout << endl << "   ----------------------------------------------------------------------------------" << endl;
            cout << "   Exit program. Thank you.";
            cout << endl << "   ----------------------------------------------------------------------------------" << endl;
		}
	}
}

void SystemClass::mainSystem()
{
	system("cls");
	int select;
	openFile();
	cout << "\nSMART HEALTH CONSULTING SYSTEM" << endl;
	cout << "1. Log In" << endl;
	cout << "2. Sign Up" << endl;
	cout << "3. Exit" << endl;
	cout << "Please Enter: ";
	cin >> select;
	while(cin.fail()){
		cout << "\nPlease input integer!.\n";
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cin >> select;
	}
	switch(select){
		case 1:
			logIn();
			mainSystem();
			break;
		case 2:
			signUp();
			mainSystem();
			break;
		case 3:
			exit(0);
			break;
		default:
			mainSystem();
			break;
	}
	system("PAUSE");
}

int main()
{
	SystemClass system;
	system.mainSystem();
	return 0;
}
