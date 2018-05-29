#include <iostream>
#include <math.h>
#include <vector>
#include <memory>

//You are given as input an unsorted array of n distinct numbers, where n is a power of 2.
//Give an algorithm that identifies the second-largest number in the array, and that uses
// at most n + log2(n) comparisons.

int* findLargest(int arr[], int, int, int);
int secondLargest(int *, int);


int main() {
    int arr[16] = {122, 5 , 88, 3, 7, 5, 8, 99, 111, 11, 999, 43, 55, 66, 77, 100};
    int max = secondLargest(arr, 16);
    std::cout << max;
    return 0;
}

int secondLargest(int *arr, int numElements){       //log2(n)  run time
    int iterations = (int)log2(numElements)+1;

    //recursively find largest element and comparison list
    int* compare = findLargest(arr, 0, numElements, iterations);

    int max = compare[0];
    int second = compare[1];

    //iterate over comparison list for 2nd smalles element
    for(int i = 2; i < iterations; i++){
        if(compare[i] > second){
            second = compare[i];
        }
    }

    delete[] compare;
    return second;
}


int* findLargest(int arr[], int start, int end, int iterations){    // n - 1 run time

    if(end-start <= 2){
        //Store length in 0 and highest element in 1
        int* compare = new int[iterations] ;

        if(arr[start] > arr[end-1]) {
            compare[0]= arr[start];
            compare[1] = arr[end-1];
        }else{
            compare[1]= arr[start];
            compare[0] = arr[end-1];
        }
        return compare;

    }else{
        //Recursively find largest element of sub array
        int* A = findLargest( arr, start, start + (end-start)/2, iterations);
        int* B = findLargest( arr, start + (end-start)/2, end, iterations);

        //Push new smaller of max in A / B to the back of the array of the higher
        if(A[0] > B[0]){
            A[(int)std::log2(end-start)]=B[0];
            delete[] B;
            return A;
        }else{

            B[(int)std::log2(end-start)]=A[0];
            delete[] A;
            return B;
        }
    }
}


/*
void printArray(int* arr, int size){
    for(int i = 0;  i < size; i ++){
        std::cout << arr[i] <<",";
    }std::cout << std::endl;
}
*/


/*

std::vector<int> vectorsecondlarges(int *arr, int start, int end){
    if(end-start <= 2){
        std::vector<int> compare;
        std::cout << "pushing back " << arr[end-1]  << "and" << arr[start] << std::endl;
        if(arr[start] > arr[end-1]) {

            compare.push_back(arr[start]);
            compare.push_back(arr[end-1]);
        }else{
            compare.push_back(arr[end-1]);
            compare.push_back(arr[start]);

        }
        return compare;
    }else{
        std::vector<int> A = vectorsecondlarges(arr, start, start + (end - start) / 2);
        std::vector<int> B = vectorsecondlarges(arr, start + (end - start) / 2, end);

        if(A[0] > B[0]){
            A.push_back(B[0]);
            return A;
        }else{
            B.push_back(A[0]);
            return B;
        }

    }
}


int vectorsecondlargest(int *arr, int start, int end){       //log2(n)  run time
    std::vector<int> compare = vectorsecondlarges(arr, start, end);

    int max = compare[0];
    int second = compare[1];

    for(int i = 2; i < compare.size(); i++){
        if(compare[i] > second){
            second = compare[i];
        }
    }
    return second;
}


int vectorMain() {
    int arr[16] = {122, 5 , 88, 3, 7, 5, 8, 99, 111, 11, 12, 43, 55, 66, 77, 100};
    int max = vectorsecondlargest(arr, 0, 16);
    std::cout << max;
    return 0;
}*/
