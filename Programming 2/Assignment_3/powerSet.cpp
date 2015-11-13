//Scott Ha
//CPSC 335
//Collaborated with Kenneth Gunderson and Sam Gutierrez

// Assignment 2: Longest increasing subsequence problem, power set algorithm
// XX YY ( YOU NEED TO COMPLETE YOUR NAME )
// Given a sequence of elements the program finds a subsequence of it in which the subsequence's
// elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible.
// The program reads the number of elements in the sequence, then the elements and outputs the sorted
// sequence and the running time.
// INPUT: a positive integer n and a list of n elements
// OUTPUT: a longest increasing subsequence of the initial sequence

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>

using namespace std;

void print_sequence(int, float*);
// function to print a sequence, given the number of elements the actual sequence stored as an array
void printPowerset(int, int*, int&, float*);
// function to generate the power set of {1, 2, ...first argument} and retrieve the best set
void checkSet(int[], int, int*, int&, float*);
// function to check the currentgly generated set stack of size k the current best set bestSet of size bestSize

int main() {
    
    int n, bestSize, i;
    float *A, *R;
    int *bestSet;
    
    // display the header
    cout << endl << "CPSC 335-x - Programming Assignment #2" << endl;
    cout << "Longest increasing subsequence problem, powerset algorithm" << endl;
    cout << "Enter the number of elements in the sequence" << endl;
    
    // read the number of elements
    cin >> n;
    // allocate space for the input sequence and array R
    A = new float[n];
    R = new float[n];
    // read the sequence
    
    cout << "Enter the elements in the sequence" << endl;
    for( i=0; i < n; i++){
        cin >> A[i];
    }
    // print the sequence
    cout << "Input sequence" << endl;
    print_sequence(n,A);
    
    // Start the chronograph to time the execution of the algorithm
    auto start = chrono::high_resolution_clock::now();
    // allocate space for the best set; initial its size is 0
    
    bestSet = new int[n+1];
    bestSize = 0;
    // calculate the best sequence
    printPowerset(n, bestSet, bestSize, A);
    // retrieve the indices for generating the subsequence
    for(i=0;i<bestSize;i++){
        // decrease each index by one since the indices of array A are in
        // the range 0..n-1 and not 1..n
        R[i]=A[bestSet[i+1]-1];
    }
    
    // End the chronograph to time the loop
    auto end = chrono::high_resolution_clock::now();
    
    // display the output
    cout << "The longest increasing subsequence has length " << endl;
    cout << bestSize << endl;
    cout << "The longest increasing subsequence is" << endl;
    
    print_sequence(bestSize, R);
    // print the elapsed time in seconds and fractions of seconds
    
    int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
    double seconds = microseconds / 1E6;
    
    cout << "elapsed time: " << seconds << " seconds" << endl;
    // de-allocate the dynamic memory space
    
    delete []A;
    delete []R;
    
    return EXIT_SUCCESS;
    
}

void print_sequence(int n, float *seq){
// function to print a sequence, given the number of elements the actual sequence stored as an array
// n represents the number of elements in the sequence
// seq represents the actual sequence
    for (int i=0; i < n; i++){
        cout << seq[i] << " ";
    }
    cout << endl;
}

void printPowerset (int n, int *bestSet, int &bestSize, float *A){
    // function to generate the power set of {1, .., n} and retrieve the best set
    // n represents the maximum value in the set
    // bestSet represents the set
    // bestSize is the size of the bestSet

    int *stack,k;
    // allocate space for the set

    stack = new int[n+1];
    stack[0]=0; /* 0 is not considered as part of the set */
    k = 0;

    while(1){
        if (stack[k]<n){
            stack[k+1] = stack[k] + 1;
            k++;
        }else{
            stack[k-1]++;
            k--;
        }
        if (k==0)
            break;
        checkSet(stack, k, bestSet, bestSize, A);
    }

    // deallocate space for the set
    delete [ ] stack;

    return;
}

void checkSet(int *stack, int k, int *bestSet, int &bestSize, float *A)
// function to check the currently generated set stack of size k against the current
// best set bestSet of size bestSize
{
    int i;
    // check that the indices in stack generate a subsequence of increasing order
    if (k <= 2) {
        // the set contains a single index so the subsequence is in increasing order
        if (k > bestSize) {
            bestSize = k;
            for (i=0; i<=bestSize; i++){
                bestSet[i] = stack[i];
            }
            return;
        }
    }else {
        // the set contains more than a single index so check that the subsequence is in order
        for(i=0;i<k-1;i++) {
            if (A[stack[i+1] - 1] > A[stack[i+2]-1]){
                return;
            }
        }
    }
    // we have an increasing so we compare it against the current best set
    if (k > bestSize) {
        bestSize = k;
        for (i=0; i<=bestSize; i++){
            bestSet[i] = stack[i];
        }
        return;
    }else
        return;
}
