#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <cstring>

using namespace std;
int mainmessage();

fstream dataFile;
char name[81];

//---------------------------------------------
//              MAIN Function
//---------------------------------------------

int main()
{

	cout << "Please input a file name: ";
	cin >> name;
	dataFile.open(name, fstream::in | fstream::out);
	if (dataFile.fail())
    {
        cout << "File does not exist. Creating new file..";
        dataFile.open(name,  fstream::in | fstream::out | fstream::trunc);// create a new file..
        dataFile.close();
    }
    else
    {
	  cout << "This File Already Exists\n";
        dataFile.close();
    }
    sleep(1);
    system("CLS");
    mainmessage();
}

//---------------------------------------------
//              First Choice Function
//---------------------------------------------

void first_choice()
{
    dataFile.open(name, ios::app);
    char text;
    cout << "Please type your text and finish by Ctrl+Z : ";
	while (true)
	{
	    if(!cin) //CTRL+Z To close
            break;
        cin.get(text);
        dataFile.put(text);

	}
    dataFile.close();
}

//---------------------------------------------
//              Second Choice Function
//---------------------------------------------

void second_choice()
{
    dataFile.open(name, ios::in);
    cout << "----------------------------"<<name<< "-------------------------------";
    while (!dataFile.eof())
    {
        cout << (char)dataFile.get();
    }
    cout << endl <<"------------------------------------------------------------"<<endl;
    dataFile.close();
}

//---------------------------------------------
//              Third Choice Function
//---------------------------------------------

void third_choice()
{
    dataFile.open(name, ios::in | ios::out | ios::trunc);
    dataFile.close();
}

//---------------------------------------------
//              Fourth Choice Function
//---------------------------------------------

void fourth_choice()
{
    fstream newfile;
    char c;
    dataFile.open(name, ios::in);
    newfile.open("encrypt.txt", ios::out);
    while (dataFile >> noskipws >> c)
    {
            int temp = (1 + c);
            newfile << (char)temp;
    }
    newfile.close();
    dataFile.close();
    third_choice();

    dataFile.open(name, ios::out);
    newfile.open("encrypt.txt", ios::in);

    while (newfile >> noskipws >> c)
    {
        dataFile << (char)c;
    }
    newfile.close();
    dataFile.close();
    remove("encrypt.txt");

}

//---------------------------------------------
//              Fifth Choice Function
//---------------------------------------------
void fifth_choice()
{
    fstream newfile;
    char c;
    dataFile.open(name, ios::in);
    newfile.open("Decrypt.txt", ios::out);
    while (dataFile >> noskipws >> c)
    {
        int temp = (c - 1);
        newfile << (char)temp;
    }
    newfile.close();
    dataFile.close();
    third_choice();

    dataFile.open(name, ios::out);
    newfile.open("Decrypt.txt", ios::in);
    while (newfile >> noskipws >> c)
    {
        dataFile << (char)c;
    }
    newfile.close();
    dataFile.close();
    remove("Decrypt.txt");

}

//---------------------------------------------
//              Main Message Function
//---------------------------------------------

int mainmessage()
{
    string choosing;
    int e;
    while(true)
    {
          cout  << "[1] Add new text to the end of the file. \n"
                << "[2] Display the content of the file. \n"
                << "[3] Empty the file. \n"
                << "[4] Encrypt the file content. \n"
                << "[5] Decrypt the file content. \n"
                << "[6] Merge another file. \n"
                << "[7] Count the number of words in the file. \n"
                << "[8] Count the number of characters in the file. \n"
                << "[9] Count the number of lines in the file. \n"
                << "[10] Search for a word in the file. \n"
                << "[11] Count the number of times a word exists in the file. \n"
                << "[12] Turn the file content to upper case. \n"
                << "[13] Turn the file content to lower case. \n"
                << "[14] Turn file content to 1st caps (1st char of each word is capital). \n"
                << "[15] Save. \n"
                << "[16] Exit. \n";


         cin >> choosing;
        if(choosing == "16")
        {
            cout << "See You Next Time ..." << endl;
            break;
        }
        else if (choosing == "1")
        {
            first_choice();
            cin.clear();
            sleep(1);
            system("CLS");
        }
        else if (choosing == "2")
        {
            second_choice();
        }
        else if (choosing == "3")
        {
            cout << "File Cleared.\n";
            third_choice();
        }
        else if (choosing == "4")
        {
            fourth_choice();
        }
        else if (choosing == "5")
        {
            fifth_choice();
        }
        else
        {
            sleep(1);
            system("CLS");
            cout << "Wrong Choose !!" << endl;
            return mainmessage();
        }

    }

}
