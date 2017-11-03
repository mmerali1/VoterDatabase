#include "Voter.h"

class VoterDatabase{
	public:
		//CONSTRUCTORS
		VoterDatabase(int maxVotersIn);
		VoterDatabase();
		
		//GETTERS
		
		//METHODS
		Voter voterLogin();
		void voterNew();
		void voterSave();
		void voterLoad(string filename);
		void voterReport();
		bool isInFile(string fileName);
		void voterLogoff(Voter voter);
		

	private:
		int maxVoters;
		Voter *voterArray;
		int arrCounter;
	
};
