#ifndef Database_H_INCLUDED
#define Database_H_INCLUDED
#include<string>
#include<iostream>
#include<windows.h>
#include<cstring>
#include<string>
#include "Individual.h"
#include "Doctor.h"
#include "Patient.h"
using namespace std;


//Class Database holds various functions for the system
class Database{
	protected: Doctor doctor [1000];
	
	public: 
	Database() {}
    
    void DisplayMenu() {
    //  Function to display main menu
    system("cls");
	cout << "********   Vaccine Administration Sys.   ********\n";
	cout << "\n\n   MAIN MENU";
	cout << "\n\n   Please enter menu option:";
	cout << "\n   [1] Add new record";
	cout << "\n   [2] Delete record";
	cout << "\n   [3] View entire record";
	cout << "\n   [4] Search record";
	cout << "\n   [0] Exit";
	cout << "\n\n   Option: ";
	}
        
    //Function to add record   
	void Add( Doctor doctor[10], int* doctorIndex, Patient patient[10], int* patientIndex){
    system("cls");
    cout << "\n\n********   Vaccine Administration Sys.   ********\n";
	cout << "\n\n   ADD NEW DOCTOR" << endl << endl;

    //  Variable to store category of registering individual selection for the new record
    char inputCategory;

	string inputID, inputName, inputTelephone, inputEmail, inputHealthCond, inputDesire, inputRepnric, inputRepname;
		
        cout << "   Select category of individual:" << endl;
        cout << "   [A] Doctor" << endl;
        cout << "   [D] Patient" << endl;   
        cout << "   Your selection: ";
        cin >> inputCategory;

    if(inputCategory == 'A' || inputCategory == 'a'){
    		system("cls");
            cout << "\n   ---------------------------------------------------------\n   ADD NEW DOCTOR RECORD\n   ---------------------------------------------------------" << endl << endl;
            cout << "   Please complete the individual details form." << endl << endl;
            // Prompt input from user for basic individual info
			cout << "   NRIC: ";
			cin >> inputID;
			cin.ignore();
			cout << "   Full Name: ";
			getline(cin,inputName);
			cout << "   Telephone: ";
			cin >> inputTelephone;
			cout << "   Email: ";
			cin >> inputEmail;	
            cout << "   Existent Health Issues/Allergy[yes/no]: ";
            cin >> inputHealthCond;
            cout << "   Desire For Vaccination[yes/no]: ";
            cin >> inputDesire;

            //  Insert data into patient object array using setter method
            doctor[*doctorIndex].setDoctor(inputID, inputName, inputTelephone, inputEmail, inputHealthCond, inputDesire);

            //  Add the count of occupied element within patient array
            *doctorIndex += 1;
            cout<<"\n\n   Data Added Successfully..."<<endl;
            cout<<"\n\n\n\n\n";
            system("PAUSE");            
        }
    else if(inputCategory == 'D' || inputCategory == 'd'){
    		system("cls");
            cout << "\n   ---------------------------------------------------------\n   ADD NEW PATIENT RECORD\n   ---------------------------------------------------------" << endl << endl;
            cout << "   Please complete the individual details form." << endl << endl;
            // Prompt input from user for basic individual info
			cout << "   NRIC: ";
			cin >> inputID;
			cin.ignore();
			cout << "   Full Name: ";
			getline(cin,inputName);
			cout << "   Telephone: ";
			cin >> inputTelephone;
			cout << "   Email: ";
			cin >> inputEmail;	
            cout << "   Existent Health Issues/Allergy[yes/no]: ";
            cin >> inputHealthCond;
            cout << "   Desire For Vaccination[yes/no]: ";
            cin >> inputDesire;
            cout << "   NRIC of Registering Representative: ";
            cin >> inputRepnric;
            cout << "   Name of Registering Representative: ";
            cin >> inputRepname;

            //  Insert data into patient object array using setter method
            patient[*patientIndex].setPatient(inputID, inputName, inputTelephone, inputEmail, inputHealthCond, inputDesire, inputRepnric, inputRepname);

            //  Add the count of occupied element within patient array
            *patientIndex += 1;
            cout<<"\n\n   Data Added Successfully..."<<endl;
            cout<<"\n\n\n\n\n";
            system("PAUSE");          
        }   
	}

	//Delete a record function
	void Delete(Doctor doctor[10], int* doctorIndex, Patient patient[10], int* patientIndex){
	system("cls");
	cout << "\n\n**********************   Vaccine Administration Sys   **********************\n";
	cout << "\n\n   DELETE DOCTOR RECORD[S]" << endl << endl;
	cout << "   Select category of individual:" << endl;
    cout << "   [A] Doctor" << endl;
    cout << "   [D] Patient" << endl;   
    cout << "   Your selection: ";
    char inputCategory;
    cin >> inputCategory;
	
	
	//Display entire record list to enable user to pick and delete according to NRIC
	if(inputCategory == 'A' || inputCategory == 'a'){
		system("cls");
		for(int i = 0; i < *doctorIndex; i++){
			cout << "\n   REF: " << i << endl;
	        cout << "   NRIC: " << doctor[i].getIndividualID() << endl;
	       	cout << "   Name: " << doctor[i].getIndividualName() << endl;
	        cout << "   Telephone: " << doctor[i].getIndividualTelephone() << endl;
	        cout << "   Email: " << doctor[i].getIndividualEmail() << endl;  
	        cout << "   Existent Health Issues/Allergy[yes/no]: " << doctor[i].getDoctorHealthCond() << endl;
	        cout << "   Desire For Vaccination[yes/no]: " << doctor[i].getDoctorDesire() << "\n" << endl;  
	    }
	
		if(*doctorIndex != 0 || *patientIndex!=0){
			int a, ref;
	        cout<<"\n\n   Enter REF of The Doctor To Be Deleted: ";
		    cin>>ref;
		    
			for (a = ref ; a < *doctorIndex; a++){
		   		doctor[a]= doctor[a + 1];				
		    }	
		    *doctorIndex-=1;	
	    	system("pause");
	    	system("cls");
			cout<<"\n\n   Doctor Data Deleted Successfully...\n"<<endl;	
			
			//Display entire doctor list again after successful deletion        
			for(int i = 0; i < *doctorIndex; i++){
				cout << "   REF: " << i << endl;
	       		cout << "   NRIC: " << doctor[i].getIndividualID() << endl;
	       		cout << "   Name: " << doctor[i].getIndividualName() << endl;
	       		cout << "   Telephone: " << doctor[i].getIndividualTelephone() << endl;
	       		cout << "   Email: " << doctor[i].getIndividualEmail() << endl;  
	        	cout << "   Existent Health Issues/Allergy[yes/no]: " << doctor[i].getDoctorHealthCond() << endl;
	        	cout << "   Desire For Vaccination[yes/no]: " << doctor[i].getDoctorDesire() << "\n" << endl;                           
	        }
			cout<<"\n\n\n\n\n";
	    }
	    // Display not found message
	    else{
	        cout << "\n   Record empty!\n" << endl;
	    }	
	}
	else if(inputCategory == 'D' || inputCategory == 'd'){
		system("cls");
		for(int i = 0; i < *patientIndex; i++){
			cout << "\n   REF: " << i << endl;
	        cout << "   NRIC: " << patient[i].getIndividualID() << endl;
	       	cout << "   Name: " << patient[i].getIndividualName() << endl;
	        cout << "   Telephone: " << patient[i].getIndividualTelephone() << endl;
	        cout << "   Email: " << patient[i].getIndividualEmail() << endl;  
	        cout << "   Existent Health Issues/Allergy[yes/no]: " << patient[i].getPatientHealthCond() << endl;
	        cout << "   Desire For Vaccination[yes/no]: " << patient[i].getPatientDesire() << "\n" << endl; 
			cout << "   Reg. Rep. NRIC: " << patient[i]. getPatientRepNRIC() << endl; 
			cout << "   Reg. Rep. Name: " << patient[i]. getPatientRepName() << "\n" << endl;   
	    }
	
		if(*patientIndex != 0 || *patientIndex!=0){
			int a, ref;
	        cout<<"\n\n   Enter REF of The Patient To Be Deleted: ";
		    cin>>ref;
		    
			for (a = ref ; a < *patientIndex; a++){
		   		patient[a]= patient[a + 1];				
		    }	
		    *patientIndex-=1;	
	    	system("pause");
	    	system("cls");
			cout<<"\n\n   Patient Data Deleted Successfully...\n"<<endl;	
			
			//Display entire patient list again after successful deletion        
			for(int i = 0; i < *patientIndex; i++){
				cout << "   REF: " << i << endl;
	       		cout << "   NRIC: " << patient[i].getIndividualID() << endl;
	       		cout << "   Name: " << patient[i].getIndividualName() << endl;
	       		cout << "   Telephone: " << patient[i].getIndividualTelephone() << endl;
	       		cout << "   Email: " << patient[i].getIndividualEmail() << endl;  
	        	cout << "   Existent Health Issues/Allergy[yes/no]: " << patient[i].getPatientHealthCond() << endl;
	        	cout << "   Desire For Vaccination[yes/no]: " << patient[i].getPatientDesire() << endl;   
				cout << "   Reg. Rep. NRIC: " << patient[i]. getPatientRepNRIC() << endl; 
				cout << "   Reg. Rep. Name: " << patient[i]. getPatientRepName() << "\n" << endl;                          
	        }
			cout<<"\n\n\n\n\n"; 
	    }
	    // Display not found message
	    else{
	        cout << "\n   Record empty!\n" << endl;
	    }
	}
}


	//  View all record function
	void View(Doctor doctor[10], int* doctorIndex, Patient patient[10], int* patientIndex){

    cout << "\n\n**********************   Vaccine Administration Sys   **********************\n";
	cout << "\n\n   VIEW DOCTOR RECORD[S]" << endl << endl;

 
    // Check if doctor record is empty or not by referring to the pointer of current occupied array element
		cout << "   Select category of individual:" << endl;
        cout << "   [A] Doctor" << endl;
        cout << "   [D] Patient" << endl;   
        cout << "   Your selection: ";
        char inputCategory;
        cin >> inputCategory;

    if(inputCategory == 'A' || inputCategory == 'a'){
	    if(*doctorIndex != 0){
	        //  This for loop will iterate and display every occupied elements within doctor array pointer
	        cout << endl << "   ----------------------------------------------------------------------------------" << endl;
	        cout << "   Record List:";
	        cout << endl << "   ----------------------------------------------------------------------------------" << endl << endl;
	
	        for(int i = 0; i < *doctorIndex; i++){
	        	cout << "   REF: " << i << endl;
	            cout << "   NRIC: " << doctor[i].getIndividualID() << endl;
	            cout << "   Name: " << doctor[i].getIndividualName() << endl;
	            cout << "   Telephone: " << doctor[i].getIndividualTelephone() << endl;
	            cout << "   Email: " << doctor[i].getIndividualEmail() << endl;  
	            cout << "   Existent Health Issues/Allergy[yes/no]: " << doctor[i].getDoctorHealthCond() << endl;
	            cout << "   Desire For Vaccination[yes/no]: " << doctor[i].getDoctorDesire() << "\n" << endl;                      
	        }
	    }
    // Display not found message
	    else{
	        cout << "\n   Record empty!\n" << endl;
	    }
	}
	else if(inputCategory == 'D' || inputCategory == 'd'){
		if(*patientIndex != 0){
	        //  This for loop will iterate and display every occupied elements within doctor array pointer
	        cout << endl << "   ----------------------------------------------------------------------------------" << endl;
	        cout << "   Record List For Patients:";
	        cout << endl << "   ----------------------------------------------------------------------------------" << endl << endl;
	
	        for(int i = 0; i < *patientIndex; i++){
	        	cout << "   REF: " << i << endl;
	            cout << "   NRIC: " << patient[i].getIndividualID() << endl;
	            cout << "   Name: " << patient[i].getIndividualName() << endl;
	            cout << "   Telephone: " << patient[i].getIndividualTelephone() << endl;
	            cout << "   Email: " << patient[i].getIndividualEmail() << endl;  
	            cout << "   Existent Health Issues/Allergy[yes/no]: " << patient[i].getPatientHealthCond() << endl;
	            cout << "   Desire For Vaccination[yes/no]: " << patient[i].getPatientDesire() << endl; 
				cout << "   Reg. Rep. NRIC: " << patient[i]. getPatientRepNRIC() << endl; 
				cout << "   Reg. Rep. Name: " << patient[i]. getPatientRepName() << "\n" << endl;                      
	        }
	    }
    // Display not found message
	    else{
	        cout << "\n   Record empty!\n" << endl;
	    }
	}
	}
	
		
	// Search record function
	void Search(Doctor doctor[10], int* doctorIndex, Patient patient[10], int* patientIndex){
    
    cout << "\n\n**********************   Vaccine Administration Sys   **********************\n";
	cout << "\n\n   SEARCH RECORD[S]" << endl << endl;
	cout << "   Select category of individual:" << endl;
	cout << "   [A] Doctor" << endl;
    cout << "   [D] Patient" << endl;   
    cout << "   Your selection: ";
    char inputCategory;
    cin >> inputCategory;

	
		if(inputCategory == 'A' || inputCategory == 'a'){
		if(*doctorIndex != 0){
	        cout << "\n\n   Search According To Desire To Be Vaccinated[yes/no]: ";
	        string k;
			cin>>k;  
			for(int i=0; i<*doctorIndex; i++)
		        {
			        if(k==doctor[i].getDoctorDesire())
			        {
			         	cout << "   REF: " << i << endl;
	       				cout << "   NRIC: " << doctor[i].getIndividualID() << endl;
	       				cout << "   Name: " << doctor[i].getIndividualName() << endl;
	       				cout << "   Telephone: " << doctor[i].getIndividualTelephone() << endl;
	       				cout << "   Email: " << doctor[i].getIndividualEmail() << endl;  
	        			cout << "   Existent Health Issues/Allergy[yes/no]: " << doctor[i].getDoctorHealthCond() << endl;
	        			cout << "   Desire For Vaccination[yes/no]: " << doctor[i].getDoctorDesire() << "\n" << endl;     
			        }
		        }                    
	        }
	    // Display not found message
	    else{
	        cout << "\n   Record empty!\n" << endl;
	    }
		}	    
	    else if(inputCategory == 'D' || inputCategory == 'd'){
	    	if(*patientIndex != 0){
	        cout << "\n\n   Search Patient According To Desire To Be Vaccinated[yes/no]: ";
	        string k;
			cin>>k;  
			for(int i=0; i<*patientIndex; i++)
		        {
			        if(k==patient[i].getPatientDesire())
			        {
			         	cout << "   REF: " << i << endl;
	       				cout << "   NRIC: " << patient[i].getIndividualID() << endl;
	       				cout << "   Name: " << patient[i].getIndividualName() << endl;
	       				cout << "   Telephone: " << patient[i].getIndividualTelephone() << endl;
	       				cout << "   Email: " << patient[i].getIndividualEmail() << endl;  
	        			cout << "   Existent Health Issues/Allergy[yes/no]: " << patient[i].getPatientHealthCond() << endl;
	        			cout << "   Desire For Vaccination[yes/no]: " << patient[i].getPatientDesire() << endl;   
						cout << "   Reg. Rep. NRIC: " << patient[i]. getPatientRepNRIC() << endl; 
						cout << "   Reg. Rep. Name: " << patient[i]. getPatientRepName() << "\n" << endl;   
			        }
		        }                    
	        }
	    // Display not found message
	    else{
	        cout << "\n   Record empty!\n" << endl;
	    }  	
		}
	}   
};
#endif
