//  main.cpp
//  EndToBeginning
//
//  Created by Scott Ha on 10/6/15.
//  Collaborated with Sam Gutierrez and Kenneth Gunderson
//  Copyright © 2015 Scott Ha. All rights reserved.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void end ( int, int *, int * );
//end			- Takes a list of numbers a lists the largest sequence numbers
//int			- The size of the list
//int *			- The list of numbers
//int *			- A parallel list to store the amount of possible subsequences

int main()
{
    //Declare default variables
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
    
    //Allocate memory for two arrays
    numList = new int[num];
    parallel = new int[num];
    
    //Ask for elements
    cout << "Enter the elements in the sequence: ";
    for (int i = 0; i < num; i++)
    {
	   cin >> numList[i];
	   parallel[i] = 0;
    }
    
    //Confirm list
    cout << "Input sequence: " << endl;
    for (int i = 0; i < num; i++)
	   cout << numList[i] << " ";
    
    //Start clock
    auto start = chrono::high_resolution_clock::now();
    
    //EndToBeginning algorithm
    end( num, numList, parallel );
    
    //Stop clock
    auto end = chrono::high_resolution_clock::now();
    double elapsed = (chrono::duration_cast<chrono::microseconds>(end - start).count())/1E6;
    cout << "Runtime: " << elapsed << " seconds.";
    
    //Deallocate memory
    delete parallel;
    delete numList;
    
    cout << endl;
    return 0;
}

void end( int num, int * numList, int * parallel )
{
    //Automatically set the last index to 0 because nothing can follow it
    parallel[num-1] = 0;
    
    //Default variable
    int largest = 0;
    
    //Comb through the number list starting from the second to last position
    for ( int i = num-2; i >= 0; i-- )
    {
	   //The starting number of subsequences will be 0
	   parallel[i] = 0;
	   
	   //Flow through the chunk behind the position
	   for ( int j = i+1; j < num; j++ )
		  //Check if the number in the chunk is smaller than the front value
		  if ( numList[i] < numList[j] )
			 //If the number is smaller, see if we are able to add the subsequences onto it
			 if ( parallel[i] <= parallel[j] )
				parallel[i] = parallel[j]+1;
	   
	   //Keep track of the largest possible subsequence list
	   if ( parallel[i] > largest )
		  largest = parallel[i];
    }
    
    //Begin displaying results, starting with the number
    cout << "\nThe longest increasing subsequence has length: " << largest+1 << endl;
    
    //Default variable
    string sequence = "";
    
    //Comb through the subsequence list to find the numbers that we can tack on
    for ( int i = 0; i < num; i++ )
    {
	   //If we find a matching number, this number can be added on and we decrement one
	   if ( largest == parallel[i] )
	   {
		  sequence += to_string(numList[i]) + " ";
		  largest--;
	   }
    }
    cout << "The longest increasing subsequence is: \n" << sequence << endl;
}