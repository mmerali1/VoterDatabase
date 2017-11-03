#include <stdlib.h>
#include <iostream>
#include <string>
#include "VoterDatabase.h"
#include <sstream>

using namespace std;

string stringLowerCase(string input);

int main(int argc, char *argv[]){
		
	int num1;
	string command;	
	bool endProg = false;
	Voter voterIn;
	if (argc > 1) {
		istringstream buf(argv[1]); 
    buf >> num1; 
  	cout << "argv[1] as an int: " << num1 << endl;
  }
	if (2 > argc || argc > 3){
		istringstream (argv[1]) >>num1;
		
		if (!((0 < num1)&&(num1 < 1000))){
			exit(0);
		}
	}
	VoterDatabase voterDB(num1);
	if (argc == 3){
			voterDB.voterLoad(argv[2]);
	}
	
	while (!endProg){
		cout << "\nEnter a command.\nChoose from 'Login' 'New' 'Save' 'Load' 'Report' 'Quit'" 				 << endl;
		cin >> command;
		if (stringLowerCase(command) == "login"){				
			
			voterIn = voterDB.voterLogin();
			while (voterIn.isLoggedIn()){
				cout<<"\nEnter a command.\nChoose from 'Update' 'Passwd' 'View' 'Donate' 'Report' 'Logout'"<< endl;
				cin >> command;				

				//update
				if (stringLowerCase(command) == "update"){
					voterIn.updateVoter();
				}				
				//change pw
				else if (stringLowerCase(command) == "passwd"){
					voterIn.changePassword();
				}
				//viewvpter
				else if (stringLowerCase(command) == "view"){
					voterIn.viewVoter();
				}
				//donate
				else if (stringLowerCase(command) == "donate"){
					voterIn.donateMoney();
				}				
				//report
				else if (stringLowerCase(command) == "report"){
					voterIn.reportDonor();
				}				
				//logout
				else if (stringLowerCase(command) == "logout"){
					voterIn.setLoggedIn(false);
					voterDB.voterLogoff(voterIn);
				}
				else{
					cout << "INVALID ENTRY" << endl;
				}			
			}


		}

		else if (stringLowerCase(command) == "new"){
			voterDB.voterNew();			
			}

		else if (stringLowerCase(command) == "save"){
			voterDB.voterSave();
			
			}

		else if (stringLowerCase(command) == "load"){
			string filename;
			cout << "Enter file name: ";
			cin >> filename;
			voterDB.voterLoad(filename);
			
			}

		else if (stringLowerCase(command) == "report"){
			cout << "\nVOTER REPORT:" << endl;			
			voterDB.voterReport();
			
			}

		else if (stringLowerCase(command) == "quit"){
			cout << "QUIT: Would you like to save the voter's information (Y/N)? ";
			cin >> command;
			if (command =="Y" || command == "y"){
				voterDB.voterSave();
			}else{
				cout << "Not saving data. Goodbye!" << endl;
			}
			endProg = true;
		}
		
	else{ 
			cout<<"INVALID ENTRY\n";
		}	
	}
};

string stringLowerCase(string input){
	for (int i=0; i<input.length(); i++){
		input[i] = tolower(input[i]);
	}
	return input;
}



