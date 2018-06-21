#include <iostream>

int findLocalMin(int**, int, int, int, int);
void print2D(int**, int, int);

int main() {

    printf("Hello, World!\n");
    int ** arr = new int*[5];

    arr[0] = new int[5]{9, 9, 9, 9, 9};
    arr[1] = new int[5]{9, 9, 9, 9, 9};
    arr[2] = new int[5]{9, 9, 9, 9, 9};
    arr[3] = new int[5]{9, 9, 9, 9, 9};
    arr[4] = new int[5]{9, 9, 9, 9, 6};

    std::cout << "Local min: " << findLocalMin(arr, 0, 0, 5, 5) << "\n";
    return 0;
}


int findLocalMin(int** arr, int r, int c, int rowMax, int colMax){
   int num =  arr[r][c];
    bool boo = true;
    if (r+1 < rowMax && num >= arr[r+1][c]){
        num = findLocalMin(arr, r+1, c, rowMax, colMax);
    }else if(c + 1 < colMax && num >= arr[r][c+1]){
        num = findLocalMin(arr, r, c+1, rowMax, colMax);
    }

    return num;
}


void print2D(int** arr, int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            std::cout << arr[i][j];
            std::cout << ",";
        }
        std::cout << std::endl;
    }
}