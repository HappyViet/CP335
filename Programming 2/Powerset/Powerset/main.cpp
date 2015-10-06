//  main.cpp
//  Powerset
//
//  Created by Scott Ha on 10/3/15.
//  Copyright © 2015 Scott Ha. All rights reserved.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct powerSet{
    int sequenceSize;
    string sequenceString;
};

int main()
{
    vector<int> list;
    vector<powerSet> parallel;
    powerSet pikachu{ 0, ""};
    int input, elements;
    
    //Populate a list with the sequence
    cout << "Enter the number of elements in the sequence: ";
    cin >> elements;
    
    if ( elements > 1 )
    {
	   cout << "Enter the elements in the sequence: " << endl;
	   for ( int i = 0; i < elements; i++)
	   {
		  cin >> input;
		  list.push_back(input);
		  parallel.push_back(pikachu);
	   }
    }
    else
    {
	   cerr << "Elements must be greater than 1";
	   exit(1);
    }
    
    //Confirmation
    cout << "Input sequence" << endl;
    for ( int i = 0; i < list.size(); i++)
	   cout << list[i] << " ";
    cout << endl;
    
    int largestSequence = 0, chain = 1, lastChecked, windex = 0;
    string combo = "";
    parallel[list.size()-1].sequenceSize = 0;
    parallel[list.size()-1].sequenceString = list[list.size()-1];
    
    for ( int i = static_cast<int>(list.size()-2); i >= 0; i--)
    {
	   lastChecked = list[i];
	   combo += to_string(lastChecked);
	   combo += " ";
	   
	   for ( int j = i; j < list.size()-2; j++)
	   {
		  if (lastChecked < list[j+1])
		  {
			 chain++;
			 lastChecked = list[j+1];
			 combo += to_string(lastChecked);
			 combo += " ";
		  }
	   }
	   
	   if ( chain > largestSequence)
	   {
		  windex = i;
		  largestSequence = chain;
	   }
	   
	   parallel[i].sequenceSize = chain;
	   parallel[i].sequenceString = combo;
	   
	   chain = 1;
	   combo = "";
    }
    
    //Display results
    cout << "Longest increasing subsequence has length: " << parallel[windex].sequenceSize << endl;
    cout << "The longest increasing subsequence is: " << parallel[windex].sequenceString << endl;

    return 0;
}