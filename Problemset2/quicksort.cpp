#include <iostream>
#include <fstream>
#include <cassert>

int * readIntToArray(std::string name);
int partition(int * arr, int start, int end);
int quickSort(int* arr,  int start, int max);

//Quick sort algorithm that returns the number of comparisons made

int main() {
    int* arr = readIntToArray("quicksortdata.txt");

    int comparisons = quickSort(arr, 0, 10000);
    std::cout << "Number of comparisons: " << comparisons << "\n";
    for(int i = 0; i < 10000; i++){
        assert(arr[i] == i + 1);
    }
    return 0;
}

int partition(int * arr, int start, int end){
    //find index of median of start, mid, end
    //2-3 comparisons

    int a = arr[start];
    int b = arr[end -1];
    int c = arr[(end - start -1 ) / 2 + start];
    int pivot;

    if(a >= b){ //a > b
        if(a <= c){ // c > a > b
            pivot = start;
        }else{ //a > c ? b
            if( b >= c){ //a > b > c
                pivot = end -1;
            }else{ // a > c > b
                pivot = (end - start -1 ) / 2 + start;
            }
        }
    }else if( b >= c){ // b > c ? a
        if( a >= c){ // b > a > c
            pivot = start;
        }else { //c > b > a
            pivot = (end - start -1) / 2 + start;
        }
    }else{ // c > b > a
        pivot = end - 1;
    }

    //partition
    int pivotVal = arr[pivot];
    arr[pivot] = arr[start];
    arr[start] = pivotVal;

    int i = start + 1;
    int temp;
    for(int j = start + 1; j < end; j++){
        if(arr[j] <= pivotVal){
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
        }
    }

    arr[start] = arr[i - 1];
    arr[i -1] = pivotVal;

    //return position of pivot
    return i-1;
}


int quickSort(int* arr,  int start, int max){
    if(max - start <= 1){
        return 0;
    }
    else{
        int mid = partition(arr, start, max);
        return max - start - 1 + quickSort(arr, start, mid) + quickSort(arr, mid + 1, max);
    }
}

//read array of ints in from file delimited by commas
int * readIntToArray(std::string name) {

    std::ifstream in(name);
    std::string meow;
    int counter = 0;

    if(in){

        while(std::getline(in, meow)){
            counter++;
        }
        in.clear();
        in.seekg(0, std::ios::beg);
        int *arr = new int[counter];
        counter = 0;

        while(std::getline(in, meow)){
            arr[counter++] = std::atoi(meow.c_str());
        }
        in.close();
        return arr;
    }
    return nullptr;

}