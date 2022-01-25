#ifndef Doctor_H_INCLUDED
#define Doctor_H_INCLUDED
#include<string>
#include<iostream>
using namespace std;

//  Inheritance where Doctor class inherited parent class Individual
class Doctor: public Individual {
private:
    //  Private variable used by doctor class
    string healthcond, desire;

public:
    //  Default constructor method
    Doctor(){
    };

    //  Parameterized constructor method
    Doctor(string individual_ID, string individual_Name, string individual_Telephone, string individual_Email, string individual_HealthCond, string individual_Desire){
        //  Method overloading of setIndividual method form super class
        setIndividual(individual_ID, individual_Name, individual_Telephone, individual_Email);
        healthcond = individual_HealthCond;
		desire = individual_Desire;
    }

    //  Setter method to insert value into private variables
    void setDoctor(string individual_ID, string individual_Name, string individual_Telephone, string individual_Email, string individual_HealthCond, string individual_Desire){
        //  Method overloading of setIndividual method form super class
        setIndividual(individual_ID, individual_Name, individual_Telephone, individual_Email);
        healthcond = individual_HealthCond;
		desire = individual_Desire;
    }

    //  All the following are getter method to access private variables
    string getDoctorHealthCond(){
        return healthcond;
    };
	string getDoctorDesire(){
        return desire;
    };   
};

#endif
