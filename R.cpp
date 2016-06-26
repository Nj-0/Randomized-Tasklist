#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<string> HiPri,MedPri,LoPri;

int prioritize(string task,string pri)
{
	if      (pri=="1")    LoPri.push_back(task);
	else if (pri=="2")    MedPri.push_back(task);
	else if (pri=="3")    HiPri.push_back(task);
	else              	 {cout <<" Priority should be from 1-3"; return 1;}
	return 0;
}

int main(){
	int randex;
	srand((int)time(0));
	string Temp,t;
	stringstream seperator;

	 time_t ti = time(0);   // get time now
    struct tm * now = localtime( & ti );
	//=======================================================================================================RETRIEVE
	ifstream input("Tasklist.txt");
	while(getline(input, Temp)){
		getline(input, t);
		int x=prioritize(Temp,t);
		if (x) {input.close();exit(1);}}
	input.close();
	//=======================================================================================================RANDOMIZER
        cout << endl << "\tTask generator: You have to do the previous Task for at least an hour before generating a new one.\n\n\t\t\t\t\tThe time now is "<<  __TIMESTAMP__ <<endl<<endl<<endl<<endl;
        randex=rand()%HiPri.size();
		if (HiPri.size()>=6)
		{//Task=HiPri[rand()%HiPri.size();
		cout << "\t\t\t\t\t\tThe chosen TASK is :\n\n\n\t\t\t\t\t\t\t"<<HiPri[randex] << endl;}
	//=======================================================================================================SELECT
	while (1)   {
		char choice;
		cin >> choice;

		if(choice == '1'){ //==================================================================================INSERT
			cout << "Please enter : ";
			cin>> Temp>>t;
			prioritize(Temp,t);}

		else if (choice == '2'){//==============================================================================LIST
			cout << "Listing Tasks. " << endl;
				for(int i = 0; i<HiPri.size(); i++)		cout <<"Hi Priority\t"<< HiPri[i]<<endl;
				for(int i = 0; i<MedPri.size(); i++)	cout <<"Me Priority\t"<< MedPri[i]<<endl;
				for(int i = 0; i<LoPri.size(); i++)		cout <<"Lo Priority\t"<< LoPri[i]<<endl;}
		else if(choice == '0'){ //===============================================================================EXIT/STORE
			ofstream f("Tasklist.txt");
			if(f.is_open())
				for(int i = 0; i<HiPri.size(); i++)		f << HiPri[i]<<" 3"<<endl;
				for(int i = 0; i<MedPri.size(); i++)	f << MedPri[i]<<" 2"<<endl;
				for(int i = 0; i<LoPri.size(); i++)		f << LoPri[i]<<" 1"<<endl;
				f.close();
				break;}
		else//=======================================================================================================HELP
		   {cout << "1. Enter \" <Task> <Priority(1-5)> \" ." << endl;
			cout << "2. List." << endl;
			cout << "0. Exit." << endl;}

	}}
