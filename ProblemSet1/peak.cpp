#include <iostream>


int peak(int*, int, int);

int main() {

    int arr[16] = { 2,16,15,14,13,12, 11, 10, 9 , 8, 7, 6, 5, 4, 3, 2};
    int mode = peak(arr, 0, 16);
    std::cout << arr[mode] << std::endl;
    std::cout << calls << std::endl;
    return 0;
}

int peak(int* arr, int start, int end){
    int mid = start + (end-start) / 2;
    if(mid == 0){
        mid= 1;
    }
    if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
        return mid;
    }else{
        if(arr[mid-1] > arr[mid]){
            return peak(arr, start, mid );
        }else{
            return peak(arr, mid, end);
        }
    }

}