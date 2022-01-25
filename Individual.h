#ifndef Individual_H_INCLUDED
#define Individual_H_INCLUDED
#include<string>
#include<iostream>
using namespace std;

class Individual {
    private:
        //  General variable for individual
        string id;
        string name;
        string phone;
		string email;
        
    public:
        //  Setter method to set value into private variable
        void setIndividual(string individual_ID, string individual_Name, string individual_Telephone, string individual_Email) {
            id = individual_ID;
            name = individual_Name;
            phone = individual_Telephone;
			email = individual_Email;     
        };

        //  All the following are getter method to access private variables
        string getIndividualID(){
            return id;
        };
        string getIndividualName(){
            return name;
        };
        string getIndividualTelephone(){
            return phone;
        };
		string getIndividualEmail(){
            return email;
        };    
};


#endif
