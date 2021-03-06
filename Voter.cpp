//#include <stdlib.h>
////#include <iostream>
//#include <string>

using namespace std;
#include "Voter.h"

//CONSTRUCTORS
Voter::Voter(){
	loggedIn = false;
}

Voter::Voter(string lastNameIn, string firstNameIn, string userIDIn, string passwordIn, int 		ageIn, int houseNumIn, string streetNameIn, string townNameIn, string stateIn, string zipCodeIn){
		lastName = lastNameIn;
		firstName = firstNameIn;
		userID = userIDIn;
		password = passwordIn;
		age = ageIn;
		houseNum = houseNumIn;
		streetName = streetNameIn;
		townName = townNameIn;
		
		if("ct" == strLowerCase(stateIn)){
			myState = CT;
		}
		else if("ma" == strLowerCase(stateIn)){
			myState = MA;
		}
		else if("me" == strLowerCase(stateIn)){
			myState = ME;
		}
		else if("nh" == strLowerCase(stateIn)){
			myState = NH;
		}
		else if("ny" == strLowerCase(stateIn)){
			myState = NY;
		}
		else if("pa" == strLowerCase(stateIn)){
			myState = PA;
		}
		else if("vt" == strLowerCase(stateIn)){
			myState = VT;
		}
		else if("ri" == strLowerCase(stateIn)){
			myState = RI;
		}	
		zipCode = zipCodeIn;
		amtDonated = 0.00;
		loggedIn = false;	
		
}

//GETTERS
string Voter::getUserID(){
	return userID;
}
string Voter::getPassword(){
	return password;
}
bool Voter::isLoggedIn(){
	return loggedIn;
	}

string Voter::getLastName(){
	return lastName;
}
string Voter::getFirstName(){
	return firstName;
}
int Voter::getAge(){
	return age;
}
int Voter::getHouseNum(){
	return houseNum;
}
string Voter::getStreetName(){
	return streetName;
}
string Voter::getTownName(){
	return townName;
}
string Voter::getState(){
	string state;	
	if(myState==0){
		state = "CT";
	}
	else if(myState==1){
		state = "MA";
	}
	else if(myState==2){
		state = "ME";
	}
	else if(myState == 3){
		state = "NH";
	}
	else if(myState == 4){
		state = "NY";
	}
	else if(myState==5){
		state = "PA";
	}
	else if(myState == 6){
		state = "VT";
	}
	else if(myState==7){
		state = "RI";
	}
	return state;
}
string Voter::getZipCode(){
	return zipCode;
}
float Voter::getAmtDonated(){
	return amtDonated;
}


//SETTERS
void Voter::setLoggedIn(bool setLog){
	loggedIn = setLog;
}

void Voter::setLastName(string lastNameIn){
	lastName = lastNameIn;
}
void Voter::setFirstName(string firstNameIn){
	firstName = firstNameIn;
}
void Voter::setUserID(string userIDIn){
	userID = userIDIn;
}
void Voter::setPassword(string passwordIn){
	password = passwordIn;
}
void Voter::setAge(int ageIn){
	age = ageIn;
}
void Voter::setHouseNum(int houseNumIn){
	houseNum = houseNumIn;
}
void Voter::setStreetName(string streetIn){
	streetName = streetIn;
}
void Voter::setTownName(string townIn){
	townName = townIn;
}
void Voter::setState(string stateIn){
	if("ct" == strLowerCase(stateIn)){
		myState = CT;
	}
	else if("ma" == strLowerCase(stateIn)){
		myState = MA;
	}
	else if("me" == strLowerCase(stateIn)){
		myState = ME;
	}
	else if("nh" == strLowerCase(stateIn)){
		myState = NH;
	}
	else if("ny" == strLowerCase(stateIn)){
		myState = NY;
	}
	else if("pa" == strLowerCase(stateIn)){
		myState = PA;
	}
	else if("vt" == strLowerCase(stateIn)){
		myState = VT;
	}
	else if("ri" == strLowerCase(stateIn)){
		myState = RI;
	}
}
	
void Voter::setZipCode(string zipIn){
	zipCode = zipIn;
}
void Voter::setAmtDonated(float amtDonatedIn){
	amtDonated = amtDonatedIn;
}
//METHODS
void Voter::updateVoter(){
	string state;
	bool isInput = true;
	char ch;
	int inCt = 0;
	//Checks Last Name for non-alpha chars
	while(isInput){
		inCt = 0;
		cout << "Last Name: ";
		//isInput = false;
		cin >> lastName;
		for(int i=0; i<lastName.length();i++){
			ch=lastName.at(i);			
			if (isalpha(ch)){
				inCt++;
			}
		}	
		if (inCt == lastName.length()){
			isInput = false;
		}
	}
	
	//Checks First name for non-alpha chars
	isInput = true;	
	while(isInput){	
		inCt = 0;			
		cout << "First Name: ";
		cin >> firstName;
		for(int i=0; i<firstName.length();i++){
			ch=firstName.at(i);
			if (isalpha(ch)){	
				inCt++;
			}
		}	
		if (inCt == firstName.length()){
			isInput = false;
		}	
	}	

	//checks age input
	isInput = true;
	string ageStr;
	while(isInput){
		inCt = 0;
		cout << "Age: ";		
		cin >> ageStr;
		istringstream (ageStr)>>age;
		for(int i=0; i<ageStr.length();i++){		
			ch=ageStr.at(i);
			if (isdigit(ch)){
				inCt++;		
			}
		}
		if ((age>=18) && inCt == ageStr.length()){
					isInput = false;
					//istringstream (ageStr)>>age;
		}		
	}

	//checks house number input
	isInput = true;
	string streetNumStr;
	while(isInput){
		inCt = 0;
		cout << "House Number: ";		
		cin >> streetNumStr;
		istringstream (streetNumStr)>>houseNum;
		for(int i=0; i<streetNumStr.length();i++){		
			ch=streetNumStr.at(i);
			if (isdigit(ch)){		
				inCt++;				
			}
		}
		if ((0<houseNum) && (inCt==streetNumStr.length())){
					isInput = false;
		}		
	}
	
	//Checks street name
	cout << "Street Name: ";
	getline(cin, streetName);
	getline(cin, streetName);

	//Checks town name
	cout << "Town: ";
	getline(cin, townName);
	
	//Checks state code
		
	isInput = true;
	while(isInput){
		cout << "Select a State: CT, MA, ME, NH, NY, PA, VT, RI: ";
		cin >> state;
		if( "ct" == strLowerCase(state) ||
				"ma" == strLowerCase(state) ||
				"me" == strLowerCase(state) ||
				"nh" == strLowerCase(state) ||
				"ny" == strLowerCase(state) ||
				"pa" == strLowerCase(state) ||	
				"vt" == strLowerCase(state) ||
				"ri" == strLowerCase(state)	){
			isInput = false;
			setState(state);
		} else {
			cout << "Invalid State Code. " ;
		}
	}

	//checks Zip Code input
	isInput = true;
	while(isInput){
		inCt = 0;
		cout << "Zip Code: ";		
		cin >> zipCode;
		for(int i=0; i<zipCode.length();i++){		
			ch=zipCode.at(i);
			if (isdigit(ch)){	
				inCt++;
			}
		}		
		if (inCt == 5){ isInput = false;}
	}
}

void Voter::changePassword(){
	string oldPW;
	string newPW;
	string newPW2;	
	char ch;
	bool isInput = true;
	int alphaCount=0; int numCount=0; int symbCount=0;
	cout << "Enter old password: ";
	cin >> oldPW;
	if (oldPW == password){
			
		
		//Checks password input
		while(isInput){
			cout << "Enter new password that is 6+ chars and includes at least one digit and symbol: ";
			cin >> newPW;
			alphaCount=0;numCount=0;symbCount=0;
			for(int i=0; i<newPW.length();i++){
				ch=newPW.at(i);			
				if (isalpha(ch)){
					alphaCount++;
				}
				else if(isdigit(ch)){
					numCount++;
				}
				else{
					symbCount++;
				}
			}
			if ((5<newPW.length()) && (1 <= numCount) && (1<=symbCount)){
				isInput = false;
			}			
		}
		
		cout << "Enter new password again: ";
		cin >> newPW2;
		if (newPW == newPW2){
			password = newPW;
			cout << "Password change successful" <<endl;
		}		
		else{
			cout << "New password inputs did not match. Please try again." <<endl;
		}
	}
	else{
		cout << "INVALID PASSWORD ENTRY" << endl;
	}
}

void Voter::viewVoter(){		
		cout << firstName << " " << lastName << ": age " << age << endl;
		cout << houseNum << " " << streetName << endl;
		cout << townName << ", " << getState() << ", " << zipCode << endl;
		cout.precision(2);
		cout << "Current Amount Donated: $"<< fixed << amtDonated  << endl;}

void Voter::donateMoney(){	
	float donation = 0.00;
	cout<<	"Enter Amount to Donate: $" ;
	cin >> donation;
	if (donation > 2700){
		cout << "Donation cannot exceed $2,700.00" << endl;
	}	
	else{
		amtDonated += donation;
		cout.precision(2);
		cout <<"$" <<fixed <<donation << " Donated" << endl;}
	}
void Voter::reportDonor(){
	cout.precision(2);
	cout << lastName << " $" << fixed << amtDonated << endl;
}

string Voter::strLowerCase(string input){
	for (int i=0; i<input.length(); i++){
		input[i] = tolower(input[i]);
	}
	return input;
}

