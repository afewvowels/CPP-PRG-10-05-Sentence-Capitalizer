//
//  main.cpp
//  CPP-PRG-10-05-Sentence-Capitalizer
//
//  Created by Keith Smith on 11/1/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a function that accepts a pointer to a C-string as an argument and capitalizes
//  the first character of each sentence in the string. For instance, if the string argument is
//  "hello. my name is Joe. what is your name?" the function should manipulate
//  the string so that it contains "Hello. My name is Joe. What is your name?"
//  Demonstrate the function in a program that asks the user to input a string then passes
//  it to the function. The modified string should be displayed on the screen. Optional
//  Exercise: Write an overloaded version of this function that accepts a string class object
//  as its argument.

#include <iostream>

using namespace std;

char *getString(int *);
int *findStringLength(char *, int *);
char *truncateString(char *, int*);
char *capitalizeString(char *, int *);
void outputString(char *, char *, int *);

int main()
{
    char *chrArray = nullptr;
    char *chrArrayResized = nullptr;
    
    int *intArrInitialIndex = nullptr;
    intArrInitialIndex = new int;
    *intArrInitialIndex = 999;
    
    int *intArrResizeIndex = nullptr;
    
    chrArray = getString(intArrInitialIndex);
    
    intArrResizeIndex = findStringLength(chrArray, intArrInitialIndex);
    
    chrArrayResized = truncateString(chrArray, intArrResizeIndex);
    
    chrArrayResized = capitalizeString(chrArrayResized, intArrResizeIndex);
    
    outputString(chrArray, chrArrayResized, intArrResizeIndex);
    
    return 0;
}

char *getString(int *intIndex)
{
    char *chrArr = nullptr;
    chrArr = new char[*intIndex];
    
    cout << "Please enter a string value:\n";
    cin.getline(chrArr, *intIndex);
    
    return chrArr;
}

int *findStringLength(char *chrArr, int *intIndex)
{
    int *intArrIndexNew = nullptr;
    intArrIndexNew = new int;
    *intArrIndexNew = 0;
    
    for (int i = 0 ; i < *intIndex ; i++)
    {
        *intArrIndexNew += 1;
        
        if(chrArr[i] == '\0')
        {
            break;
        }
    }
    
    return intArrIndexNew;
}

char *truncateString(char *chrArrOriginal, int *intIndexShort)
{
    char *chrArrNew = nullptr;
    chrArrNew = new char[*intIndexShort];
    
    for (int i = 0 ; i < *intIndexShort ; i++)
    {
        chrArrNew[i] = chrArrOriginal[i];
    }
    
    return chrArrNew;
}

char *capitalizeString(char *chrArr, int *intIndex)
{
    if (isalpha(chrArr[0]))
    {
        chrArr[0] = toupper(chrArr[0]);
    }
    else if(!isalpha(chrArr[0]))
    {
        for (int i = 0 ; i < *intIndex ; i++)
        {
            if (isalpha(chrArr[i]))
            {
                chrArr[i] = toupper(chrArr[i]);
                break;
            }
        }
    }
    else
    {
        cout << "ERROR CAPITALIZING C-STRING ELEMENTS\n";
        exit(1);
    }
    
    for (int i = 0 ; i < *intIndex ; i++)
    {
        if(chrArr[i] == '.' && chrArr[i + 1] != ' ')
        {
            if (isalpha(chrArr[i + 1]))
            {
                chrArr[i + 1] = toupper(chrArr[i + 1]);
            }
            else if(!isalpha(chrArr[i + 1]))
            {
                for (int j = i + 1 ; j < *intIndex ; j++)
                {
                    if (isalpha(chrArr[j]))
                    {
                        chrArr[j] = toupper(chrArr[j]);
                        break;
                    }
                }
            }
            else
            {
                cout << "ERROR CAPITALIZING C-STRING ELEMENTS\n";
                exit(1);
            }
        }
        else if(chrArr[i] == '.' && chrArr[i + 1] == ' ')
        {
            cout << "ran" << endl;
            if (isalpha(chrArr[i + 2]))
            {
                chrArr[i + 2] = toupper(chrArr[i + 2]);
            }
            else if(!isalpha(chrArr[i + 2]))
            {
                for (int j = i + 2 ; j < *intIndex ; j++)
                {
                    if (isalpha(chrArr[j]))
                    {
                        chrArr[j] = toupper(chrArr[j]);
                        break;
                    }
                }
            }
            else
            {
                cout << "ERROR CAPITALIZING C-STRING ELEMENTS\n";
                exit(1);
            }
        }
    }
    
    return chrArr;
}

void outputString(char *chrArrOriginal, char *chrArrCapitalized, int *intIndex)
{
    cout << "Your original string was:\n";
    for (int i = 0 ; i < *intIndex ; i++)
    {
        cout << chrArrOriginal[i];
    }
    cout << endl;
    
    cout << "The capitalized version is:\n";
    for (int i = 0 ; i < *intIndex ; i++)
    {
        cout << chrArrCapitalized[i];
    }
    cout << endl;
}
