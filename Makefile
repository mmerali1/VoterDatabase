all:	Voter
	

Voter:	Lab3.o VoterDatabase.o Voter.o
	g++ Lab3.o VoterDatabase.o Voter.o -o Voter

Lab3.o:	Lab3.cpp Voter.h VoterDatabase.h
	g++ -c Lab3.cpp 

Voter.o:	Voter.cpp Voter.h
	g++ -c Voter.cpp 

VoterDatabase.o:	VoterDatabase.cpp VoterDatabase.h
	g++ -c VoterDatabase.cpp 

clean:	
	rm -f *.o Voter
