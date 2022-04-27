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
fstream newfile;
string c;
char name[81];

//---------------------------------------------
//              MAIN Function
//---------------------------------------------
void temptxt()
{
    dataFile.open(name, ios::in);
    newfile.open("savetext.txt", ios::out | ios::trunc);
    while(!dataFile.eof())
    {
        getline(dataFile,c);
        for(int i = 0 ; i<c.size();i++)
        {
            newfile << char(c[i]) ;
        }
    }
    newfile.close();
    dataFile.close();

}
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
        dataFile.open(name,  fstream::in | fstream::out | fstream::trunc); // create a new file..
        dataFile.close();
    }
    else
    {
	  cout << "This File Already Exists\n";
        dataFile.close();
    }
    temptxt();
    sleep(1);
    system("CLS");
    mainmessage();
}

//---------------------------------------------
//              First Choice Function
//---------------------------------------------

void first_choice()
{
    newfile.open("savetext.txt", ios::app);
    char text;
    cout << "Please type your text and finish by Ctrl+Z : ";
	while (true)
	{
	    if(!cin) //CTRL+Z To close
            break;
        cin.get(text);
        newfile.put(text);

	}
    newfile.close();
}

//---------------------------------------------
//              Second Choice Function
//---------------------------------------------

void second_choice()
{
    newfile.open("savetext.txt", ios::in);
    cout << "\n----------------------------"<<name<< "-------------------------------\n";
    while (!newfile.eof())
    {
        cout << (char)newfile.get();
    }
    cout <<"\n------------------------------------------------------------\n";
    newfile.close();

}

//---------------------------------------------
//              Third Choice Function
//---------------------------------------------

void third_choice()
{
        newfile.open("savetext.txt", ios::in | ios::out | ios::trunc);
        newfile.close();

}

//---------------------------------------------
//              Fourth Choice Function
//---------------------------------------------

void fourth_choice()
{
    fstream temp;
    newfile.open("savetext.txt", ios::in | ios::out);
    temp.open("encrypt.txt", ios::out);
    while(!newfile.eof())
    {
        getline(newfile,c);
        for(int i = 0 ; i<c.size();i++)
        {
            temp << char(c[i]+1) ;
        }
    }
    temp.close();
    newfile.close();
    newfile.open("savetext.txt", ios::out | ios::trunc);
    temp.open("encrypt.txt", ios::in);
    while(!temp.eof())
    {
        getline(temp,c);
        for(int i = 0 ; i<c.size();i++)
        {
            newfile << char(c[i]) ;
        }
    }
    temp.close();
    newfile.close();
    remove("encrypt.txt");

}

//---------------------------------------------
//              Fourth Choice Function
//---------------------------------------------
void fifth_choice()
{
    fstream temp;
    newfile.open("savetext.txt", ios::in);
    temp.open("Decrypt.txt", ios::out);
    while(!newfile.eof())
    {
        getline(newfile,c);
        for(int i = 0 ; i<c.size();i++)
        {
            temp << char(c[i]-1) ;
        }
    }
    temp.close();
    newfile.close();
    third_choice();

    newfile.open("savetext.txt", ios::out | ios::trunc);
    temp.open("Decrypt.txt", ios::in);
    while(!temp.eof())
    {
        getline(temp,c);
        for(int i = 0 ; i<c.size();i++)
        {
            newfile << char(c[i]) ;
        }
    }
    temp.close();
    newfile.close();
    remove("Decrypt.txt");

}

//---------------------------------------------
//              eleventh Choice Function
//---------------------------------------------

void eleventh_choice()
{
    int counter = 0;
    string word, desiredWord;
    vector<string> arr;

    cout << "enter a word you want to count" << endl;
    cin >> desiredWord;
    for (int i=0 ; i<desiredWord.size();i++)
    {
        desiredWord[i] = toupper(desiredWord[i]);
    }
    newfile.open("savetext.txt", ios::in);
    //appends words of file while it is not the end of file.
    while (!newfile.eof() && newfile >> word)
    {
        for (int i=0 ; i<word.size();i++)
        {
            word[i] = toupper(word[i]);
        }
        //append words in vector "arr"
        arr.push_back(word);
        //ignores spaces
        if (word == " ")
        {
            continue;
        }
    }
    newfile.close();
    for (string x : arr)
    {
        //checks if desired word is in the vector
        if (x == desiredWord)
        {
            //therefore increments the counter of how many times the desired word is repeated in file
            counter++;
        }
    }
    cout << "The word " << desiredWord << " is repeated " << counter << " times" << endl;
}

//---------------------------------------------
//              Save Function
//---------------------------------------------

void save()
{
    int choose;
    cout << "[1] Save The Changes in the Same file\n"
         << "[2] Save The Changes in Another File\n"
         << "=> ";
    cin >> choose;
    if (choose == 1)
    {
            dataFile.open(name, ios::out);
            newfile.open("savetext.txt", ios::in );
            while(!newfile.eof())
            {
                getline(newfile,c);
                for(int i = 0 ; i<c.size();i++)
                {
                    dataFile << char(c[i]) ;
                }
            }
            dataFile.close();
            newfile.close();
            remove("savetext.txt");
    }
    else if (choose == 2)
    {
        char newname[81];
        cout << "Enter The new Name: ";
        cin >> newname;

        dataFile.open(newname, ios::out);
        newfile.open("savetext.txt", ios::in );
        while(!newfile.eof())
            {
                getline(newfile,c);
                for(int i = 0 ; i<c.size();i++)
                {
                    dataFile << char(c[i]) ;
                }
            }
            dataFile.close();
            newfile.close();
            remove("savetext.txt");

    }else
    {
        cout << "Wrong Choose !";
        return save();
    }

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
        else if (choosing == "11")
        {
            eleventh_choice();
        }
        else if (choosing == "15")
        {
            save();
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
