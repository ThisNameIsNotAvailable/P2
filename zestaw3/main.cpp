//
//  main.cpp
//  zestaw3
//
//  Created by Alexey Valevich on 15/03/2021.
//

#include <iostream>

using namespace std;


void display(u_int16_t num){
    int MAX = UINT16_MAX + 1;
    MAX >>= 1;
    while(true) {
        if(num & MAX) {
            cout << "1";
        }else {
            cout << "0";
        }
        if(MAX == 1) {
            break;
        }
        MAX >>= 1;
    }
    cout << endl;
}

uint16_t Complement(uint16_t num) {
    int MAX = UINT16_MAX + 1;
    uint16_t result = 0;
    while(true) {
        if(!(num & MAX)) {
            result += MAX;
        }
        if(MAX == 1) {
            break;
        }
        MAX >>= 1;
    }
    return result;
}

uint16_t Intersection(uint16_t num1, uint16_t num2) {
    uint16_t result = 0;
    int MAX = UINT16_MAX + 1;
    while(true) {
        if((num1 & MAX) && (num2 & MAX)) {
            result += MAX;
        }
        
        if(MAX == 1) {
            break;
        }
        MAX >>= 1;
    }
    return result;
}

uint16_t Difference(uint16_t num1, uint16_t num2) {
    uint16_t result = 0;
    int MAX = UINT16_MAX + 1;
    while(true) {
        if((num1 & MAX) && !(num2 & MAX)) {
            result += MAX;
        }
        
        if(MAX == 1) {
            break;
        }
        MAX >>= 1;
    }
    return result;
}

uint16_t Sum(uint16_t num1, uint16_t num2) {
    uint16_t result = 0;
    int MAX = UINT16_MAX + 1;
    while(true) {
        if((num1 & MAX) | (num2 & MAX)) {
            result += MAX;
        }
        
        if(MAX == 1) {
            break;
        }
        MAX >>= 1;
    }
    return result;
}

uint16_t SymmetricDifference(uint16_t num1, uint16_t num2) {
    uint16_t result = 0;
    int MAX = UINT16_MAX + 1;
    while(true) {
        if((num1 & MAX) ^ (num2 & MAX)) {
            result += MAX;
        }
        
        if(MAX == 1) {
            break;
        }
        MAX >>= 1;
    }
    return result;
}

bool isFound(uint16_t num, uint8_t n) {
    if(n <= 0 || n > 16) {
        return false;
    }
    
    int temp = 1<<(16 - n);
    return num & temp;
}

void AddElement(uint16_t& num, int n) {
    if(n <= 0 || n > 16) {
        cout << "Nieprawidłowy indeks" << endl;
    }
    
    if(!isFound(num, n)) {
        num += 1<<(16 - n);
    }
}

void DeleteElement(uint16_t& num, int n) {
    if(n <= 0 || n > 16) {
        cout << "Nieprawidłowy indeks" << endl;
    }
    
    if(isFound(num, n)) {
        num -= 1<<(16 - n);
    }
}

void PowerOfSet(uint16_t num) {
    int MAX = UINT16_MAX + 1;
    int result = 0;
    while(true) {
        if(num & MAX) {
            result++;
        }
        
        if(MAX == 1) {
            break;
        }
        MAX >>= 1;
    }
    cout << result << endl;
}

int main(int argc, const char * argv[]) {
    uint16_t a = 653;
    uint16_t b = 123;
    int n = 10;
    
    display(a);
    display(b);
    cout << endl;
    
    cout << "Dopełnienie " << endl;
    display(a);
    cout << "do" << endl << "1111111111111111" << endl;
    display(Complement(a));
    cout << endl;
    
    cout << "Precięcie " << endl;
    display(a);
    cout << "oraz " << endl;
    display(b);
    display(Intersection(a, b));
    cout << endl;
    
    cout << "Różnica " << endl;
    display(a);
    cout << "minus " << endl;
    display(b);
    display(Difference(a, b));
    cout << endl;
    
    cout << "Suma zbióru " << endl;
    display(a);
    cout << "oraz " << endl;
    display(b);
    display(Sum(a, b));
    cout << endl;
    
    cout << "Różnica symetryczna pomiędzy " << endl;
    display(a);
    cout << "oraz " << endl;
    display(b);
    display(SymmetricDifference(a, b));
    cout << endl;
    
    cout << "Czy zbiór " << endl;
    display(a);
    cout << "zawiera element #" << n << endl;
    cout << isFound(a, n) << endl;
    n = 16;
    cout << "#" << n << "?" << endl;
    cout << isFound(a, n) << endl;
    
    cout << "Dodawanie elementu #10" << endl;
    AddElement(a, 10);
    display(a);
    cout << endl;
    
    cout << "Usuwanie elementu #10" << endl;
    DeleteElement(a, 10);
    display(a);
    cout << endl;
    
    cout << "Moc zbioru  ";
    display(a);
    cout << "jest równa ";
    PowerOfSet(a);
    
    return 0;
}
