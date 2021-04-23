#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long helpFunction(int arr[][10], int size) {
    long long deter = 0;
    if(size == 1){
        return arr[0][0];
    }else {
        for(int i = 0; i < size; i++) {
            if(arr[0][i] != 0) {
                int tempArr[10][10];
                for(int j = 1; j < size; j++) {
                    int move = 0;
                    for(int k = 0; k < size; k++) {
                        if(i != k) {
                            tempArr[j - 1][k - move] = arr[j][k];
                        }else
                            move = 1;
                    }
                }
                int sign = (i % 2 == 0) ? 1 : -1;
                
                deter += sign * arr[0][i] * helpFunction(tempArr, size - 1);
            }
        }
        return deter;
    }
}

struct Matrix{
    int** matrix;
    int size;
};

struct Matrix* createNew(){
    int size;
    srand(time(NULL));
    do{
        printf("Wprowadź rozmiar(max. 10):\n");
        scanf("%d", &size);
    }while(size == 0);
    
    struct Matrix* temp = malloc(sizeof(struct Matrix));
    temp->size = size;
    temp->matrix = malloc(size * sizeof(int*));
    for(int i = 0; i < size; i++) {
        *(temp->matrix + i) = malloc(size * sizeof(int));
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            temp->matrix[i][j] = rand() % 5;
        }
    }
    return temp;
}

long long Determinant(const struct Matrix obj){
    int temp[obj.size][10];
    
    for(int i = 0; i < obj.size; i++) {
        for(int j = 0; j < obj.size; j++) {
            temp[i][j] = obj.matrix[i][j];
        }
    }
    
    return helpFunction(temp, obj.size);
}

struct Matrix* Add(struct Matrix* m1, struct Matrix* m2){
    struct Matrix* temp = malloc(sizeof(struct Matrix));
    if(m1->size != m2->size) {
        printf("Operacja się nie powiodła. Zwrót pierwszego obiektu...\n");
        return m1;
    }else {
        temp->matrix = malloc(m1->size * sizeof(int*));
        temp->size = m1->size;
        for(int i = 0; i < temp->size; i++) {
            *(temp->matrix + i) = malloc(temp->size * sizeof(int));
        }
        for (int i = 0; i < temp->size; i++) {
            for (int j = 0; j < temp->size; j++) {
                temp->matrix[i][j] = m1->matrix[i][j] + m2->matrix[i][j];
            }
        }
    }
    return temp;
}

struct Matrix* Substract(struct Matrix* m1, struct Matrix* m2){
    struct Matrix* temp = malloc(sizeof(struct Matrix));
    if(m1->size != m2->size) {
        printf("Operacja się nie powiodła. Zwrót pierwszego obiektu...\n");
        return m1;
    }else {
        temp->matrix = malloc(m1->size * sizeof(int*));
        temp->size = m1->size;
        for(int i = 0; i < temp->size; i++) {
            *(temp->matrix + i) = malloc(temp->size * sizeof(int));
        }
        for (int i = 0; i < temp->size; i++) {
            for (int j = 0; j < temp->size; j++) {
                temp->matrix[i][j] = m1->matrix[i][j] - m2->matrix[i][j];
            }
        }
    }
    return temp;
}

struct Matrix* Multiply(struct Matrix* m1, struct Matrix* m2){
    struct Matrix* temp = malloc(sizeof(struct Matrix));
    if(m1->size != m2->size) {
        printf("Operacja się nie powiodła. Zwrót pierwszego obiektu...\n");
        return m1;
    }else {
        temp->matrix = malloc(m1->size * sizeof(int*));
        temp->size = m1->size;
        for(int i = 0; i < temp->size; i++) {
            *(temp->matrix + i) = malloc(temp->size * sizeof(int));
        }
        
        int result = 0;
        for (int i = 0; i < temp->size; i++) {
            for (int j = 0; j < temp->size; j++) {
                result = 0;
                for(int k = 0; k < temp->size; k++) {
                    result += m1->matrix[i][k] * m2->matrix[k][j];
                }
                temp->matrix[i][j] = result;
            }
        }
    }
    return temp;
}

void ScalarMult(struct Matrix* m, int scalar){
    for (int i = 0; i < m->size; i++) {
        for (int j = 0; j < m->size; j++) {
            m->matrix[i][j] = scalar * m->matrix[i][j];
        }
    }
}

void Compare(const struct Matrix* m1, const struct Matrix* m2){
    if(m1->size != m2->size) {
        printf("Macierze nie są równe\n");
    }else {
        for (int i = 0; i < m1->size; i++) {
            for (int j = 0; j < m1->size; j++) {
                if(m1->matrix[i][j] != m2->matrix[i][j]) {
                    printf("Macierze nie są równe\n");
                    return;
                }
            }
        }
    }
    printf("Macierze są równe\n");
}

void Transposition(struct Matrix* m){
    int temp;
    for (int i = 0; i < m->size; i++) {
        for (int j = i + 1; j < m->size; j++) {
            temp = m->matrix[i][j];
            m->matrix[i][j] = m->matrix[j][i];
            m->matrix[j][i] = temp;
        }
    }
}

int DiagonalSum(const struct Matrix* m){
    int temp = 0;
    for (int i = 0; i < m->size; i++) {
        temp += m->matrix[i][i];
    }
    return temp;
}

int isUpperTriangular(const struct Matrix* m, int isDisplay){
    if(m->size == 1) {
        if(m->matrix[0][0]){
            if(isDisplay)
                printf("Nie jest macierzą górną trójkątną\n");
            return 0;
        }else{
            if(isDisplay)
                printf("Jest macierzą górną trójkątną\n");
            return 1;
        }
    }
    for (int i = 1; i < m->size; i++) {
        for (int j = 0; j < i; j++) {
            if(m->matrix[i][j]) {
                if(isDisplay)
                    printf("Nie jest macierzą górną trójkątną\n");
                return 0;
            }
        }
    }
    if(isDisplay)
        printf("Jest macierzą górną trójkątną\n");
    return 1;
}

int isLowerTriangular(const struct Matrix* m, int isDisplay){
    if(m->size == 1) {
        if(m->matrix[0][0]){
            if(isDisplay)
                printf("Nie jest macierzą dolną trójkątną\n");
            return 0;
        }else{
            if(isDisplay)
                printf("Jest macierzą dolną trójkątną\n");
            return 1;
        }
        
    }
    for (int i = 0; i < m->size; i++) {
        for (int j = i + 1; j < m->size; j++) {
            if(m->matrix[i][j]) {
                if(isDisplay)
                    printf("Nie jest macierzą dolną trójkątną\n");
                return 0;
            }
        }
    }
    if(isDisplay)
        printf("Jest macierzą dolną trójkątną\n");
    return 1;
}

void isIdentical(const struct Matrix* m){
    if(isLowerTriangular(m, 0) && isUpperTriangular(m, 0)) {
        for (int i = 0; i < m->size; i++) {
            if(m->matrix[i][i] != 1) {
                printf("Nie jest macierzą identycznościową\n");
                return;
            }
        }
        printf("Jest macierzą identycznościową\n");
        return;
    }
    printf("Nie jest macierzą identycznościową\n");
}

void isSparse(const struct Matrix* m){
    int count = 0;
    for (int i = 0; i < m->size; i++) {
        for (int j = 0; j < m->size; j++) {
            if(m->matrix[i][j] == 0)
                count++;
        }
    }
    
    if(count > m->size / 2)
        printf("Macierz jest rzadka\n");
    else
        printf("Macierz nie jest rzadka\n");
}

void isSymmetric(const struct Matrix* m){
    for (int i = 0; i < m->size; i++) {
        for (int j = i + 1; j < m->size; j++) {
            if(m->matrix[i][j] != m->matrix[j][i]) {
                printf("Macierz nie jest symetryczna\n");
                return;
            }
            
        }
    }
    printf("Macierz jest symetryczna\n");
}


void Display(const struct Matrix* obj) {
    for(int i = 0; i < obj->size; i++) {
        for(int j = 0; j < obj->size; j++) {
            printf("%d ", obj->matrix[i][j]);
        }
        printf("\n");
    }
}

void DeleteMatrix(struct Matrix** obj) {
    for (int i = 0; i < (*obj)->size; i++) {
        free(*((*obj)->matrix + i));
    }
    free((*obj)->matrix);
    (*obj)->matrix = NULL;
    free(*obj);
    *obj = NULL;
}

int main() {
    struct Matrix* m1 = createNew();
    struct Matrix* m2 = createNew();
    struct Matrix* identical = malloc(sizeof(struct Matrix));
    identical->size = 3;
    identical->matrix = malloc(identical->size * sizeof(int*));
    for(int i = 0; i < identical->size; i++) {
        identical->matrix[i] = malloc(identical->size * sizeof(int));
        for(int j = 0; j < identical->size; j++) {
            if(i == j)
                identical->matrix[i][j] = 1;
            else
                identical->matrix[i][j] = 0;
        }
    }
    
    Display(m1);
    printf("\n");
    Display(m2);
    printf("\n");
    
    struct Matrix* m3 = Add(m1, m2);
    printf("Add\n");
    Display(m3);
    printf("\n");
    
    struct Matrix* m4 = Substract(m1, m2);
    printf("Substract\n");
    Display(m4);
    printf("\n");
    
    struct Matrix* m5 = Multiply(m1, m2);
    printf("Multiply\n");
    Display(m5);
    printf("\n");
    
    printf("Scalar multiplication\n");
    ScalarMult(m5, 5);
    Display(m5);
    printf("\n");
    
    printf("Compare matrices\n");
    Compare(m5, m5);
    Compare(m4, m5);
    printf("\n");
    
    printf("Determinant is %lld\n", Determinant(*m1));
    printf("\n");
    
    printf("Transposition\n");
    Display(m5);
    printf("\n");
    Transposition(m5);
    Display(m5);
    printf("\n");
    
    printf("Sum of diagonal elements\n");
    Display(m5);
    printf("\n");
    printf("Sum is %d\n\n", DiagonalSum(m5));
    
    printf("Is matrix identical\n");
    Display(m5);
    isIdentical(m5);
    printf("\nIs matrix identical\n");
    Display(identical);
    isIdentical(identical);
    printf("\n");
    
    printf("Is matrix upper triangular\n");
    Display(m5);
    isUpperTriangular(m5, 1);
    printf("\nIs matrix upper triangular\n");
    Display(identical);
    isUpperTriangular(identical, 1);
    printf("\n");
    
    printf("Is matrix lower triangular\n");
    Display(m5);
    isLowerTriangular(m5, 1);
    printf("\nIs matrix lower triangular\n");
    Display(identical);
    isLowerTriangular(identical, 1);
    printf("\n");
    
    printf("Is matrix symmetric\n");
    Display(m5);
    isSymmetric(m5);
    printf("\nIs matrix symmetric\n");
    Display(identical);
    isSymmetric(identical);
    printf("\n");
    
    
    DeleteMatrix(&m1);
    DeleteMatrix(&m2);
    DeleteMatrix(&m3);
    DeleteMatrix(&m4);
    DeleteMatrix(&m5);
    DeleteMatrix(&identical);
    return 0;
}
