#include<iostream>
using namespace std;

class UserClass
{
	private:
		string user_name;
		int user_age;
		string user_email;
		string user_pass;
		long int user_id;
    public:
		UserClass(){}
		UserClass(long int id,string name,int age,string email,string password);
	
		string getUser_name(){return user_name;}
		int getUser_age(){return user_age;}
		string getUser_email(){ return user_email;}
		string getUser_pass(){return user_pass;}
		long int getUser_id(){return user_id;}
	
		void setAll();
		void setUserEmail();
		void setUserPass();
		void checkInt(int x);
		
};

UserClass::UserClass(long int id,string name,int age,string email,string password)
{
	user_name = name;
	user_id = id;
	user_age = age;
	user_email = email;
	user_pass = password;
}

void UserClass::setAll()
{
	cout << "Please Enter Your Name: ";
	cin >> user_name;
	cout << "Please Enter ID(I/C No): ";
	cin >> user_id;
	cout << "Please Enter Your Age: ";
	checkInt(user_age);
	cout << "Please Enter Your Email: ";
	cin >> user_email;
	cout << "Please Enter Your Password: ";
	cin >> user_pass;
}

void UserClass::setUserPass()
{
	cout << "Please Enter Your Password: ";
	cin >> user_pass;
}

void UserClass::setUserEmail()
{
	cout << "Please Enter Your Email: ";
	cin >> user_email;
}

void UserClass::checkInt(int x)
{
	cin >> x;
	while(cin.fail()) {
        cout << "\nPlease input integer!\n";
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cin >> x;
    }
}
