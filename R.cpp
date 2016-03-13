#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	cout <<endl<<"\tTask generator: You have to do the previous Task for at least an hour before generating a new one"<<endl<<endl<<endl<<endl;
    vector<string> Tasks;
    int randex;
    srand((int)time(0));
    string Task;
    //=======================================================================================================RETRIEVE
    ifstream input("Tasklist.txt");

    while(getline(input, Task))
        Tasks.push_back(Task);
                input.close();
    //=======================================================================================================


    while (1)
    {
        //=======================================================================================================RANDOMIZER
        if (Tasks.size()!=0)
        {randex=rand()%Tasks.size();
        cout << "\t\t\t\t\t\tThe chosen TASK is :\n\n\n\t\t\t\t\t\t\t"<<Tasks[randex] << endl;}
        //=======================================================================================================SELECT

        char choice;
        cin >> choice;

        if(choice == '1'){ //=======================================================================================================INSERT
            cout << "Please enter : ";
            cin>> Task;
            Tasks.push_back(Task);
            cout << "Listing Tasks. " << endl;
            for(int i = 0; i < Tasks.size(); i++)
                cout << "Task # " << i + 1 << ": " << Tasks[i] << endl;}

        else if(choice == '0'){ //=======================================================================================================EXIT/STORE
            ofstream f("Tasklist.txt");

            if(f.is_open())
                for(int i = 0; i<Tasks.size(); i++)
                    f << Tasks[i]<<endl;
                f.close();
                break;}
        else//=======================================================================================================HELP
            cout << "1. Enter a Task " << endl;
            cout << "0. Exit." << endl;

    }}
