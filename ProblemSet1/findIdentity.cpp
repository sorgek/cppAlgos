#include <iostream>

//You are given a sorted (from smallest to largest) array A of n distinct integers which can be positive, negative,
// or zero. You want to decide whether or not there is an index i such that A[i] = i. Design the fastest
// algorithm that you can for solving this problem.

//solved for Olog2(n)

bool identity(int* arr, int );
bool findIdentity(int*, int, int);

int main() {

    int arr[16] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    bool id = identity(arr, 16);
    if(id){
        std::cout << "true" << std::endl;
    }else {
        std::cout << "false" << std::endl;
    }
    return 0;
}


//return false if obvious
bool identity(int* arr, int end){       //run time O(2)
    if(arr[end -1] < 0 || arr[0] >= end){
        return false;
    }else{  //else call recursive check
        return findIdentity(arr, 0, 16);
    }
}


//recursively compare mid to value at arr[mid]
bool findIdentity(int* arr, int start, int end){    //run time log2(n)

    int mid = start + (end-start) / 2;
    std::cout << mid <<",";
    if(arr[mid] == mid){
        return true;
    }else if(mid <= 0 || mid >= end-1){
        return false;
    }else if (arr[mid] > mid){
        return findIdentity(arr, start, mid);
    }else {
        return findIdentity(arr, mid, end);
    }

}

