#include <iostream>
#include <vector>
#include <string>
#include <fstream>

//To count the number of inversions in a given array, or the number of pairs(i,j) array
//indices with i < j and A[i] > A[j]

std::vector<int> readIntToArray(std::string name);
std::vector<int> merge(std::vector<int>A, std::vector<int>B, long&);
std::vector<int> mergeSort(std::vector<int> array, int start, int end, long&);

long getInversions(std::vector<int> array);

int main() {

    std::vector<int> array = readIntToArray("IntegerArray.txt");
    long inversions = getInversions(array);
    std::cout << inversions;
}

long getInversions(std::vector <int> arr){
    long inversions = 0;
    std::vector<int> array = mergeSort(arr, 0, arr.size(), inversions);
    return inversions;
}


//Putting the merge in merge sort
std::vector<int> merge(std::vector<int>A, std::vector<int>B, long &inversions){

    //merged vector to return
    std::vector<int> final;

    //size of A and B
    int aSize = A.size();
    int bSize = B.size();

    //Ints to keep track of how many from A and B have been
    //pushed to final vector
    int aIt = 0;
    int bIt = 0;


    //Keep sorting while there are still values in A or B
    while( aIt < aSize && bIt < bSize){
        if(A[aIt] < B[bIt]){
            final.push_back(A[aIt]);
            aIt++;
        }else if(A[aIt] > B[bIt]){
            final.push_back(B[bIt]);
            inversions += aSize - aIt;
            bIt++;

        }else{  //I could delete this and add a =>, in retrospect
            final.push_back(A[aIt]);
            final.push_back(B[bIt]);
            aIt++;
            bIt++;
        }
    }

    //if end is reached for A and B add the remaining values on to the end.
    //This works b/c the ones that ones out first had the lowest values.
    if( aIt < aSize){
        for(aIt; aIt < aSize; aIt++){
            final.push_back(A[aIt]);
        }
    } else if(bIt < bSize){
        for(bIt; bIt < bSize; bIt++){
            final.push_back(B[bIt]);
        }
    }

    return final;

}


std::vector<int> mergeSort(std::vector<int> array, int start, int end, long &inversions){

    std::vector<int> A;
    std::vector<int> B;

    //Base case
    if(end - start < 2){
        return array;
    }

    for(int a = start; a < end/2; a++){     //Lower half array
        A.push_back(array[a]);
    }
    for(int a = end/2; a < end; a++){       //Upper half array
        B.push_back(array[a]);
    }


    A = mergeSort(A, 0, A.size(), inversions);
    B = mergeSort(B, 0, B.size(), inversions);

    return merge(A,B, inversions);
}


//read array of ints in from file delimited by lines
std::vector<int> readIntToArray(std::string name) {

    std::ifstream in(name);
    std::string meow;
    std::vector<int> array;

    if(in){

        while(std::getline(in, meow)){
            array.push_back(std::atoi(meow.c_str()));
        }

        in.close();
        return array;
    }

}
