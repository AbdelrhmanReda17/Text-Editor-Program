
#include "textlib.h"

fstream newfile,dataFile;

void temptxt(char name[])
{
    string line;
    dataFile.open(name, ios::in);
    newfile.open("savetext.txt", ios::out | ios::trunc);
    while(!dataFile.eof()&& !dataFile.fail())
    {
        getline(dataFile,line);
        newfile << line ;
        if(!dataFile.eof()) newfile << endl;

    }
    newfile.close();
    dataFile.close();
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
    sleep(1);
    system("CLS");
}

//---------------------------------------------
//              Second Choice Function
//---------------------------------------------

void second_choice(char name[])
{
    newfile.open("savetext.txt", ios::in);
    cout << "\n----------------------------"<<name<< "-------------------------------\n";
    while (!newfile.eof())
    {
        cout << (char)newfile.get();
    }
    cout <<"\n------------------------------------------------------------\n";
    newfile.close();
    sleep(1);
    system("CLS");

}

//---------------------------------------------
//              Third Choice Function
//---------------------------------------------

void third_choice()
{
        newfile.open("savetext.txt", ios::in | ios::out | ios::trunc);
        newfile.close();
        sleep(1);
        system("CLS");
}

//---------------------------------------------
//              Fourth Choice Function
//---------------------------------------------

void fourth_choice()
{
    fstream temp;
    string line;
    newfile.open("savetext.txt", ios::in | ios::out);
    temp.open("encrypt.txt", ios::out);
    while(!newfile.eof() && !newfile.fail())
    {
        getline(newfile,line);
        for(int i = 0 ; i < line.size() ; i++)
        {
            temp << char(line[i]+1) ;
        }
        if(!newfile.eof()) temp << endl;

    }
    temp.close();
    newfile.close();
    newfile.open("savetext.txt", ios::out | ios::trunc);
    temp.open("encrypt.txt", ios::in);
    while(!temp.eof())
    {
        getline(temp,line);
        for(int i = 0 ; i<line.size();i++)
        {
            newfile << char(line[i]) ;
        }
    if(!temp.eof()) newfile << endl;

    }
    temp.close();
    newfile.close();
    remove("encrypt.txt");
    sleep(1);
    system("CLS");

}

//---------------------------------------------
//              Fifth Choice Function
//---------------------------------------------
void fifth_choice()
{
    fstream temp;
    string line;
    newfile.open("savetext.txt", ios::in);
    temp.open("Decrypt.txt", ios::out);
    while(!newfile.eof())
    {
        getline(newfile,line);
        for(int i = 0 ; i<line.size();i++)
        {
            temp << char(line[i]-1) ;
        }
        if(!newfile.eof()) temp << endl;
    }
    temp.close();
    newfile.close();
    third_choice();

    newfile.open("savetext.txt", ios::out | ios::trunc);
    temp.open("Decrypt.txt", ios::in);
    while(!temp.eof())
    {
        getline(temp,line);
        for(int i = 0 ; i<line.size();i++)
        {
            newfile << char(line[i]) ;
        }
        if(!temp.eof()) newfile << endl;

    }
    temp.close();
    newfile.close();
    remove("Decrypt.txt");
    sleep(1);
    system("CLS");

}
//---------------------------------------------
//              Sixth Choice Function
//---------------------------------------------
void sixth_choice()
{
    string line;
    char Another[81];
    fstream anotherFile;
    cout << "Enter The Name of The Another File: ";
    cin >> Another;
    strcat(Another,".txt");
    anotherFile.open(Another, ios::in);
    newfile.open("savetext.txt", ios::app | ios::out);
    while(!anotherFile.eof() && !anotherFile.fail())
    {
        getline(anotherFile, line);
        newfile << line << endl;
    }
    newfile.close();
    anotherFile.close();
    cout << "The Two Files Are Merged Successfully, But The Changes Are Not Saved Yet! You Better Save It\n";
    sleep(3);
    system("CLS");
}
//---------------------------------------------
//              Seventh Choice Function
//---------------------------------------------
void seventh_choice()
{
    string tmp; int counter = 0;
    newfile.open("savetext.txt", ios::in);
    while(!newfile.fail() && !newfile.eof())
    {
        newfile >> tmp;
        counter++;
    }
    cout << "\nThe Number of words: " << counter << "\n\n";
    newfile.close();
    sleep(1);
    system("CLS");
}
//---------------------------------------------
//              eighth Choice Function
//---------------------------------------------
void eighth_choice()
{
    char tmp; int counter = 0;
    newfile.open("savetext.txt", ios::in);
    while(!newfile.fail() && !newfile.eof())
    {
        newfile.get(tmp);
        counter++;
    }
    cout << "\nThe Number of Characters: " << --counter << "\n\n";
    newfile.close();
    sleep(1);
    system("CLS");
}
//---------------------------------------------
//              ninth Choice Function
//---------------------------------------------
void ninth_choice()
{
    string tmp; int counter = 0;
    newfile.open("savetext.txt", ios::in);
    while(!newfile.fail() && !newfile.eof())
    {
        getline(newfile, tmp);
        counter++;
    }
    cout << "\nThe Number of Lines: " << counter << "\n\n";
    newfile.close();
    sleep(1);
    system("CLS");
}
//---------------------------------------------
//              Tenth Choice Function
//---------------------------------------------
inline void upper(string& s)
{
    for(int i =0; i < s.size(); i++)
        s[i] = toupper(s[i]);
}
void tenth_choice()
{
    string tmp1, tmp2; bool check = false;
    cout << "Enter The Word to look for: ";
    cin.ignore();
    getline(cin, tmp1);
    upper(tmp1);
    newfile.open("savetext.txt", ios::in);
    while(!newfile.fail() && !newfile.eof())
    {
        newfile >> tmp2;
        upper(tmp2);
        if(tmp1 == tmp2)
        {
            cout << "Word Was Found In The File!\n";
            check = true;
            break;
        }
    }
    if(!check)
        cout << "Word Was Not Found In The File!\n";
    sleep(1);
    system("CLS");
    newfile.close();
}
//---------------------------------------------
//              eleventh Choice Function
//---------------------------------------------

void eleventh_choice()
{
    int counter = 0;
    string desiredWord,word;
    vector<string> arr;
    cout << "enter a word you want to count" << endl;
    cin >> desiredWord;
    for (int i=0 ; i<desiredWord.size();i++)
    {
        desiredWord[i] = toupper(desiredWord[i]);
    }
    newfile.open("savetext.txt", ios::in);
    while (!newfile.eof() && newfile >> word)
    {
        for (int i=0 ; i<word.size();i++)
        {
            word[i] = toupper(word[i]);
        }
        arr.push_back(word);
        if (word == " ")
        {
            continue;
        }
    }
    newfile.close();
    for (string x : arr)
    {
        if (x == desiredWord)
        {
            counter++;
        }
    }
    cout << "The word " << desiredWord << " is repeated " << counter << " times" << endl;
}
//---------------------------------------------
//              twelfth Message Function
//---------------------------------------------
void twelfth_choice()
{
    fstream temp;
    string line;
    newfile.open("savetext.txt", ios::in);
    temp.open("Uppercase.txt", ios::out);
    while(!newfile.eof())
    {
        getline(newfile,line);
        for(int i = 0 ; i<line.size();i++)
        {
            temp << char(toupper(line[i])) ;
        }
        if(!newfile.eof()) temp << endl;
    }
    temp.close();
    newfile.close();
    remove("savetext.txt");
    newfile.open("savetext.txt", ios::out | ios::trunc);
    temp.open("Uppercase.txt", ios::in);
    while(!temp.eof())
    {
        getline(temp,line);
        newfile << line ;
        if(!temp.eof()) newfile << endl;

    }
    temp.close();
    newfile.close();
    remove("Uppercase.txt");
}
//---------------------------------------------
//              thirteenth Message Function
//---------------------------------------------
void thirteenth_choice()
{
    fstream temp;
    string line;
    newfile.open("savetext.txt", ios::in);
    temp.open("Lowercase.txt", ios::out);
    while(!newfile.eof())
    {
        getline(newfile,line);
        for(int i = 0 ; i<line.size();i++)
        {
            temp << char(tolower(line[i])) ;
        }
        if(!newfile.eof()) temp << endl;
    }
    temp.close();
    newfile.close();
    remove("savetext.txt");
    newfile.open("savetext.txt", ios::out | ios::trunc);
    temp.open("Lowercase.txt", ios::in);
    while(!temp.eof())
    {
        getline(temp,line);
        newfile << line ;
        if(!temp.eof()) newfile << endl;

    }
    temp.close();
    newfile.close();
    remove("Lowercase.txt");
}
//---------------------------------------------
//              fourteenth Message Function
//---------------------------------------------
void fourteenth_choice()
{
    string line;
    string text ="";
    fstream tmp;
    newfile.open("savetext.txt", ios::in | ios::out);

    tmp.open("save.txt", ios::in | ios::out | ios::trunc);
    while(getline(newfile,line))
    {
        for(int i = 0 ; i<line.size();i++)
        {
            line[i] = (tolower((char)line[i]));
        }
        for(int i = 0 ; i<line.size();i++)
        {
            line[0] = toupper(line[0]);
            if (line[i] == ' ')
            {
                line[i+1] = toupper(line[i+1]);
            }

        }
        tmp << line << endl;
    }
    tmp.close();
    newfile.close();
    newfile.open("savetext.txt", ios::out | ios::trunc);
    tmp.open("save.txt", ios::in);
    while(!tmp.eof())
    {
        getline(tmp,line);
        newfile << line ;
        if(!tmp.eof()) newfile << endl;
    }
    tmp.close();
    newfile.close();
    remove("save.txt");
}

//---------------------------------------------
//              Save Function
//---------------------------------------------

void save(char name [])
{
    string line;
    char newname[81];
    int choose;
    cout << "[1] Save The Changes in the Same file\n"
         << "[2] Save The Changes in Another File\n"
         << "=> ";
    cin >> choose;
    if (choose == 1)
    {
            dataFile.open(name, ios::out);
            newfile.open("savetext.txt", ios::in );
            while(!newfile.eof()&& !newfile.fail())
                {
                    getline(newfile,line);
                    dataFile << line ;
                    if(!newfile.eof()) dataFile << endl;
                }
            dataFile.close();
            newfile.close();
    }
    else if (choose == 2)
    {

        cout << "Enter The new Name: ";
        cin >> newname;

        dataFile.open(newname, ios::out);
        newfile.open("savetext.txt", ios::in );
        strcat(newname,".txt");
        while(!newfile.eof() && !newfile.fail())
            {
                getline(newfile,line);
                dataFile << line ;
                if(!newfile.eof()) dataFile << endl;
            }
            dataFile.close();
            newfile.close();

    }
    else
    {
        cout << "Wrong Choose !";
        return save(name);
    }
    if (choose == 1) cout << "The New Changes Is Saved in Same File [" << name << "]"<< endl;
    else if (choose == 2) cout << "The New Changes Is Saved to the File " << newname << endl;
    sleep(2);
    system("CLS");
}

void exit()
{
    cout << "See You Next Time ..." << endl;
    remove("savetext.txt");
}
//---------------------------------------------
//              Main Message Function
//---------------------------------------------

int mainmessage(char name[])
{
    string choosing;
    //int e;
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
            exit();
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
            sleep(1);
            system("CLS");
            second_choice(name);
        }
        else if (choosing == "3")
        {
            sleep(1);
            system("CLS");
            cout << "File Cleared.\n";
            third_choice();
        }
        else if (choosing == "4")
        {
            sleep(1);
            system("CLS");
            fourth_choice();
        }
        else if (choosing == "5")
        {
            sleep(1);
            system("CLS");
            fifth_choice();
        }
        else if (choosing == "6")
        {
            sleep(1);
            system("CLS");
            sixth_choice();
        }
        else if (choosing == "7")
        {
            sleep(1);
            system("CLS");
            seventh_choice();
        }
        else if (choosing == "8")
        {
            sleep(1);
            system("CLS");
            eighth_choice();
        }
        else if (choosing == "9")
        {
            sleep(1);
            system("CLS");
            ninth_choice();
        }
        else if (choosing == "10")
        {
            sleep(1);
            system("CLS");
            tenth_choice();
        }
        else if (choosing == "11")
        {
            sleep(1);
            system("CLS");
            eleventh_choice();
        }
        else if (choosing == "12")
        {
            sleep(1);
            system("CLS");
            twelfth_choice();
        }
        else if (choosing == "13")
        {
            sleep(1);
            system("CLS");
            thirteenth_choice();
        }
        else if (choosing == "14")
        {
            sleep(1);
            system("CLS");
            fourteenth_choice();
        }
        else if (choosing == "15")
        {
            save(name);
        }
        else
        {
            sleep(1);
            system("CLS");
            cout << "Wrong Choose !!" << endl;
            return mainmessage(name);
        }

    }

}
