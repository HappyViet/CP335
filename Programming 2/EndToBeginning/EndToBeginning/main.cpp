//
//  main.cpp
//  EndToBeginning
//
//  Created by Scott Ha on 10/6/15.
//  Copyright © 2015 Scott Ha. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int endToBeginning ( int, int *, int *, string *);
//Algorithm

void debugOutput( int, int *, string *);
//For debugging

void presentOutput( int, string);
//For presenting

int main()
{
    int num, *numList, *parallel;

    //Ask for number of elements
    cout << "Enter the number of elements in the sequence: ";
    cin >> num;
    
    //Error check
    if (num < 1)
    {
	   cerr << "Number of elements must be greater than 0.";
	   exit(1);
    }
    
    //Allocate memory for three arrays
    numList = new int[num];
    parallel = new int[num];
    string *output = new string[num];
    
    //Ask for elements
    cout << "Enter the elements in the sequence: ";
    for (int i = 0; i < num; i++)
    {
	   cin >> numList[i];
	   parallel[i] = 0;
    }
    
    //Confirm list
    cout << "Input sequence";
    for (int i = 0; i < num; i++)
	   cout << numList[i];
    
    int index = endToBeginning(num, numList, parallel, output);
    //cout << endl;
    //debugOutput(num, parallel, output);
    presentOutput(parallel[index], output[index]);
    
    //Deallocate memory
    delete parallel;
    delete output;
    delete numList;
    
    cout << endl;
    return 0;
}

int endToBeginning ( int num, int * numList, int * parallel, string * output)
{
    //Allocated variables for checking
    int count = 1, check, max = 0;
    int location = num;
    string sequence = "";
    
    //Begin at the last position
    for (int i = num-1; i >= 0; i--)
    {
	   //Set this number to the beginning of this chunk
	   check = numList[i];
	   
	   //Add this number to a sequence string
	   sequence = to_string(check);
	   sequence += " ";
	   
	   //Iterate through the chunk to compare
	   for ( int j = i; j < num; j++ )
	   {
		  //If a number bigger than the one being checked is found
		  if (check < numList[j])
		  {
			 count++;
			 check = numList[j];
			 sequence += to_string(check);
			 sequence += " ";
		  }
	   }
	   
	   //After iterating through the chunk, check
	   if (count > max)
	   {
		  max = count;
		  location = i;
	   }
	   
	   //Save this data
	   parallel[i] = count;
	   output[i] = sequence;
	   
	   //Reset the temporary variables
	   sequence = "";
	   count = 1;
    }
    
    return location;
}

void debugOutput( int num, int *parallel, string *output)
{
    for ( int i = 0; i < num; i++)
    {
	   cout << "Index: [" << i << "]\n"
		  << "Sequence length: " << parallel[i]
		  << "\nOutput string: " << output[i] << endl;
	   cout << endl;
    }
}

void presentOutput( int winningNum, string winningString)
{
    cout << "The largest sequence length is " << winningNum << ".\n"
	   << "Output string: " << winningString;
}