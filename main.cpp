/*
FCAI – Programming 1 – 2022 - Assignment 4
Program Name: CS112-203-2nd–S1,2-20210255-20210376-20210436-A4-TextEditorApp.cpp
Program Description: Text Editor Application
Last Modification Date: 12 / 5 / 2022.
Author1 and ID and Group: Abdelrhman Reda Mohamed- 20210255- GROUP A
Author2 and ID and Group: Mahmoud Mamdouh Abdelaziz-20210376- GROUP A
Author3 and ID and Group: Nourhan Elsayed Hassan Ibrahim-20210436- GROUP A
Teaching Assistant: Eng. Nesma & Eng. Yousra
Purpose: Applying a variety edits on desired text files
 */

#include "textlib.h"
#include "textlib.cpp"
//---------------------------------------------
//              MAIN Function
//---------------------------------------------

int main()
{
    fstream newfile,dataFile;
    char name[81];
	cout << "Please input a file name: ";
	cin >> name;
    strcat(name,".txt");
	dataFile.open(name, fstream::in | fstream::out);
	if (dataFile.fail())
    {
        cout << "File does not exist. Creating new file..";
        dataFile.open(name,  fstream::in | fstream::out | fstream::trunc); // create a new file..
        dataFile.close();
    }
    else
    {
        cout << "This File Already Exists\n";
        dataFile.close();
    }
    temptxt(name);
    sleep(1);
    system("CLS");
    mainmessage(name);
}
