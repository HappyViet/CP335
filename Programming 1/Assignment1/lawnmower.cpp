//  main.cpp
//  Algorithms
//
//  Created by Scott Ha on 9/3/15.
//  Collaborated with Kenneth G. and Sam G.
//  Copyright (c) 2015 Scott Ha. All rights reserved.

#include <iostream>
#include <vector>

using namespace std;

int lawnmower(vector<char>&);
//lawnmower         - Cycles through the list using lawnmower algorithm to switch D to L and counts the swaps made
//vector<char>&     - The vector of D and L
//return int        - Returns the amount of swaps made

void display(vector<char>);
//display           - Cycles through the lift to display the values inside
//vector<char>&     - The vector of D and L

int main(int argc, const char * argv[]) {
    
    vector<char> list;
    int numOfDiscs, numOfSwaps;
    
    cout << "CPSC 335­x – Programming Assignment #1:\nThe alternating disks problem: lawnmower algorithm\nEnter the number of paired color disks: ";
    cin >> numOfDiscs;
    cout << "Initial configuration:\n";
    
    //Populate list with d and l
    if (numOfDiscs > 0)
    {
        for ( int i = 0; i < numOfDiscs; i++)
        {
            list.push_back('d');
            list.push_back('l');
        }
    }
    else
        cerr << "Amount of discs entered needs to be greater than 0.";
    
    //Display unordered list
    display(list);
    
    cout << "\nAfter moving darker ones to the left:\n";
    
    //Start clock
    auto start = std::chrono::high_resolution_clock::now();
    
    //Use algorithm
    numOfSwaps = lawnmower(list);
    
    //Stop clock
    auto end = chrono::high_resolution_clock::now();
    double elapsed = (chrono::duration_cast<chrono::microseconds>(end - start).count())/1E6;
    
    //Display ordered list
    display(list);
    
    cout << "\nRuntime of: " << elapsed << " seconds.";
    cout << "\nNumber of swaps is " << numOfSwaps << ".\n";
    
    return 0;
}

int lawnmower(vector<char>& list)
{
    int numOfSwaps = 0;
    
    for( int i = 0; i < (list.size()/2); i++)
    {
        if ( i % 2 == 0)
        {
            for ( int j = i; j < (list.size()-(1+i)); j++)
            {
                if (list[j] == 'd' && list[j+1] == 'l')
                {
                    swap(list[j], list[j+1]);
                    numOfSwaps++;
                }
            }
        }
        else
        {
            for ( int j = static_cast<int>(list.size()-(1+i)); j > i; j--)
            {
                if (list[j] == 'l' && list[j-1] == 'd')
                {
                    swap(list[j], list[j-1]);
                    numOfSwaps++;
                }
            }
        }
    }
    
    return numOfSwaps;
}

void display(vector<char> list)
{
    cout << "List of disks\n";
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }
}