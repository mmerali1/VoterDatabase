#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <string>

using namespace std;


class Voter{

  public:
		//CONSTRUCTORS
		Voter();
		Voter(string lastNameIn, string firstNameIn, string userIDIn, string passwordIn, int ageIn, int houseNumIn, string streetNameIn, string townNameIn, string stateIn, string zipCodeIn);
		
		//GETTERS
		string getUserID();
		string getPassword();
		bool isLoggedIn();
		string getLastName();
		string getFirstName();
		int getAge();
		int getHouseNum();
		string getStreetName();
		string getTownName();
		string getState();
		string getZipCode();
		float getAmtDonated();


		//SETTERS
		void setLoggedIn(bool setLog);
		void setLastName(string lastNameIn);
		void setFirstName(string firstNameIn);
		void setUserID(string userIDIn);
		void setPassword(string passwordIn);
		void setAge(int ageIn);
		void setHouseNum(int houseNumIn);
		void setStreetName(string streetIn);
		void setTownName(string townIn);
		void setState(string stateIn);
		void setZipCode(string zipIn);
		void setAmtDonated(float amtDonatedIn);

		//METHODS
		void updateVoter();
		void changePassword();
		void viewVoter();
		void donateMoney();
		void reportDonor();
		string strLowerCase(string input);

		//CHECK METHODS
		
			
  private:
		string lastName;
		string firstName;
		string userID;
		string password;
		int age;
		int houseNum;
		string streetName;
		string townName;
		enum State {CT, MA, ME, NH, NY, PA, VT, RI};
		State myState;
		string zipCode;
		float amtDonated;
		bool loggedIn;



};
