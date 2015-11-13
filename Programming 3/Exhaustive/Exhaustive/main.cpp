//  main.cpp
//  Exhaustive
//
//  Created by Scott Ha on 10/29/15.
//  Copyright © 2015 Scott Ha. All rights reserved.

// input: a positive integer n and a list P of n distinct points representing vertices of a Euclidean graph
// output: a list of n points from P representing a Hamiltonian cycle of minimum total weight for the graph.

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

void generate_perm(int, int*, int, vector<int> &);

int main() {
    int n;
    int *A;
    
    vector<int> B;
    cout << "Enter the range of the values to be permuted (n > 0)" << endl;
    cin >> n;
    A = new int[n];
    
    // populate the array A with the values in the range 0 .. n­1
    for(int i=0; i<n; i++)
	   A[i] = i;
    
    generate_perm(n,A, n,B);
    
    for( int i = 0; i < B.size(); i++)
	   cout << B[i] << endl;
    
    delete [] A;
}

void generate_perm(int n, int *A, int sizeA, vector<int> & B) {
    if (n == 1)
    {
	   string temp ="";
	   for(int i=0; i< sizeA; i++)
		  temp += to_string(A[i]);
	   B.push_back(atoi(temp.c_str()));
    }
    else
    {
	   for(int i = 0 ; i < (n-1); i++)
	   {
		  generate_perm(n-1, A, sizeA, B);
		  if (n%2 == 0)
		  {
			 swap(A[i], A[n-1]);
		  }
		  else
		  {
			 swap(A[0], A[n-1]);
		  }
	   }
    generate_perm(n-1, A, sizeA, B);
    }
}