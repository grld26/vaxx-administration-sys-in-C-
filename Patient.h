#ifndef Patient_H_INCLUDED
#define Patient_H_INCLUDED
#include<string>
#include<iostream>
using namespace std;

//  Inheritance where Patient class inherited parent class Individual
class Patient: public Individual {
private:
    //  Private variable used by patient class
    string healthcond, desire, repnric, repname;

public:
    //  Default constructor method
    Patient(){
    };

    //  Parameterized constructor method
    Patient(string individual_ID, string individual_Name, string individual_Telephone, string individual_Email, string individual_HealthCond, string individual_Desire, string individual_repnric, string individual_repname){
        //  Method overloading of setIndividual method form super class
        setIndividual(individual_ID, individual_Name, individual_Telephone, individual_Email);
        healthcond = individual_HealthCond;
		desire = individual_Desire;
		repnric = individual_repnric;
		repname = individual_repname;
    }

    //  Setter method to insert value into private variables
    void setPatient(string individual_ID, string individual_Name, string individual_Telephone, string individual_Email, string individual_HealthCond, string individual_Desire, string individual_repnric, string individual_repname){
        //  Method overloading of setIndividual method form super class
        setIndividual(individual_ID, individual_Name, individual_Telephone, individual_Email);
        healthcond = individual_HealthCond;
		desire = individual_Desire;
		repnric = individual_repnric;
		repname = individual_repname;
    }

    //  All the following are getter method to access private variables
    string getPatientHealthCond(){
        return healthcond;
    };
	string getPatientDesire(){
        return desire;
    }; 
	string getPatientRepNRIC(){
        return repnric;
    }; 
    string getPatientRepName(){
        return repname;
    }; 
};

#endif
