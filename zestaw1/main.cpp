//
//  main.cpp
//  zestaw1
//
//  Created by Alexey Valevich on 04/03/2021.
//

#include <iostream>
#include <list>

using namespace std;

int FindMax(int* arr, int n) {
    int max = *arr;
    for(int i = 1; i < n; i++) {
        if(*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

int* CreateArr(int n) {
    int* A = new int[n];
    for(int i = 0; i < n; i++) {
        *(A + i) = rand() % 11;
    }
    return A;
}

void ReverseArr(int* arr, int n) {
    for(int i = 0; i < n / 2; i++) {
        *(arr + i) = *(arr + i) ^ *(arr + (n - i - 1));
        *(arr + (n - i - 1)) = *(arr + (n - i - 1)) ^ *(arr + i);
        *(arr + i) = *(arr + i) ^ *(arr + (n - i - 1));
    }
}

void DisplayArr(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}
void ShiftByOne(int* arr, int n) {
    int temp = *arr;
    for(int i = 0; i < n - 1; i++) {
        *(arr + i) = *(arr + i + 1);
    }
    *(arr + n - 1) = temp;
}

void ShiftArr(int* arr, int n, int m) {
    m = m % n;
    for(int i = 0; i < m; i++) {
        ShiftByOne(arr, n);
    }
}

void BubbleSort(int* a, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(*(a + i) > *(a + j)) {
                int temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
}

void MergeArrays(int* a, int* b, int ASize, int BSize, int* result) {
    BubbleSort(a, ASize);
    BubbleSort(b, BSize);
    int it1 = 0, it2 = 0;
    for(int i = 0; i < ASize + BSize; i++) {
        if(*(a + it1) < *(b + it2) && it1 < ASize) {
            *(result + i) = *(a + it1);
            it1++;
        }else {
            *(result + i) = *(b + it2);
            it2++;
        }
    }
}

int* multOfPolynomial(int* a, int* b, int n, int m) { // n i m jako stopni wielomianów
    int* res = new int[n + m + 1];
    for(int i = 0; i < n + m + 1; i++) {
        *(res + i) = 0;
    }
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            *(res + i + j) += *(a + i) * *(b + j);
        }
    }
    return res;
}

void newton(){
    int N;
    cout << "Enter a number: " << endl;
    cin >> N;
    int** arr = new int*[N];
    for(int i = 0; i < N; i++) {
        *(arr + i) = new int[i + 1];
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i + 1; j++) {
            if(j == 1) {
                *(*(arr + i) + j) = i;
            }else if(j == 0) {
                *(*(arr + i) + j) = 1;
            }else if(i < j) {
                *(*(arr + i) + j) = 0;
            }else {
                long licznik = 1;
                for(int m = 1; m <= i; m++) {
                    licznik *= m;
                }
                long mianownik = 1;
                for(int m = 1; m <= j; m++) {
                    mianownik *= m;
                }
                long temp = 1;
                for(int m = 1; m <= i - j; m++) {
                    temp *= m;
                }
                mianownik *= temp;
                *(*(arr + i) + j) = licznik / mianownik;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - i; j++) {
            cout << " ";
        }
        DisplayArr(*(arr + i), i + 1);
    }
    for(int i = 0; i < N; i++) {
        delete [] *(arr + i);
    }
    delete [] arr;
}

int main(int argc, const char * argv[]) {
//    int n;
//    cin >> n;
//    int *A = CreateArr(n);
//    int* B = CreateArr(n);
//    int* result = multOfPolynomial(A, B, n - 1, n - 1);
//    DisplayArr(A, n);
//    DisplayArr(B, n);
//    DisplayArr(result, 2 * n - 1);
//    delete[] B;
//    delete[] A;
//    delete[] result;
    newton();
    return 0;
}

//---------------------------------------------------

