#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<string> Tasks;
    while (1)
    {
        cout << "1. Enter a Task " << endl;
        cout << "2. List all Tasks. " << endl;
        cout << "0. Exit." << endl;
        //cout << "4. Delete a Task. " << endl;

        char choice;
        cin >> choice;

        if(choice == '1'){
            cout << "Please enter : ";
            string Task;
            cin>> Task;
            Tasks.push_back(Task);}

        else if(choice == '2'){
            cout << "You chose option #2." << endl; //Add Stuff Here
            cout << "Listing Tasks. " << endl;
            for(int i = 0; i < Tasks.size(); i++)
                cout << "Task # " << i + 1 << ": " << Tasks[i] << endl;}

        else if(choice == '0')
            break;

    }}
