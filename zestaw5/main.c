#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

void zad0() {
    char buffer[1000];
    for(int i = 0; i < 1000; i++) {
        buffer[i] = 0;
    }
    fgets(buffer, sizeof(buffer), stdin);
    for (int i = 999; i >=0; i--) {
        if(buffer[i + 1] != '\0'){
            if(buffer[i] >= 97 && buffer[i] <= 122){
                printf("%c", toupper(buffer[i]));
            }else {
                printf("%c", buffer[i]);
            }
        }
    }
    printf("\n");
}

void zad1() {
    char s1[] = "kjhk";
    char s2[] = "zjhjkouihkjhi";
    for(int i = 0; i < sizeof(s1) / sizeof(char) - 1 && i < sizeof(s2) / sizeof(char) - 1; i++) {
        s1[i] = s2[i];
    }
    printf("%s\n", s1);
}

void zad2() {
    int num, count = 0;
    scanf("%d", &num);
    int help = num;
    while(help != 0) {
        help /= 10;
        count++;
    }
    help = pow(10, count - 1);
    
    while(num != 0) {
        int digit = num / help;
        num -= digit*help;
        help /= 10;
        switch (digit) {
            case 0:
                printf("zero ");
                break;
            case 1:
                printf("jeden ");
                break;
            case 2:
                printf("dwa ");
                break;
            case 3:
                printf("trzy ");
                break;
            case 4:
                printf("cztery ");
                break;
            case 5:
                printf("pięć ");
                break;
            case 6:
                printf("sześć ");
                break;
            case 7:
                printf("siedem ");
                break;
            case 8:
                printf("osiem ");
                break;
            case 9:
                printf("dziewięć ");
                break;
            default:
                break;
        }
    }
    printf("\n");
}

void zad3(){
    long num;
    int count = 0;
    scanf("%ld", &num);
    if(num == 0) {
        printf("1");
    }else{
        while(num != 0) {
            if(num % 2 == 0) {
                count++;
            }
            num /= 2;
        }
        printf("%d\n", count);
    }
}

int number(char letter){
    switch(toupper(letter)){
         case 'I':
            return 1;
         case 'V':
            return 5;
         case 'X':
            return 10;
         case 'L':
            return 50;
         case 'C':
            return 100;
         case 'D':
            return 500;
         case 'M':
            return 1000;
         case '\0':
            return 0;
         default:
            return -1;
    }
}

void zad4(){
    int num = 0;
    char buffer[50];
    for(int i = 0; i < 50; i++) {
        buffer[i] = 0;
    }
    fgets(buffer, sizeof(buffer), stdin);
    if((buffer[0] >= 65 && buffer[0] <= 90) || (buffer[0] >= 97 && buffer[0] <= 122)) {
        for(int i = 0; i < 48 && (buffer[i] != 10); i++) {
            if(50 - i > 2) {
                if(number(buffer[i]) < number(buffer[i + 2])){
                    printf("Niepoprawne wejście\n");
                    break;
                }
            }
            
            if(number(buffer[i]) >= number(buffer[i + 1])) {
                num += number(buffer[i]);
            }else {
                num += (number(buffer[i + 1]) - number(buffer[i]));
                i++;
            }
        }
        printf("%d\n", num);
    }else if(buffer[0] >= 48 && buffer[0] <= 57){
        num = atoi(buffer);
        while(num != 0){
            if (num >= 1000){
               printf("M");
               num -= 1000;
            }else if (num >= 900){
               printf("CM");
               num -= 900;
            }else if (num >= 500){
               printf("D");
               num -= 500;
            }else if (num >= 400){
               printf("CD");
               num -= 400;
            }else if (num >= 100){
               printf("C");
               num -= 100;
            }else if (num >= 90){
               printf("XC");
               num -= 90;
            }else if (num >= 50){
               printf("L");
               num -= 50;
            }else if (num >= 40){
               printf("XL");
               num -= 40;
            }else if (num >= 10){
               printf("X");
               num -= 10;
            }else if (num >= 9){
               printf("IX");
               num -= 9;
            }else if (num >= 5){
               printf("V");
               num -= 5;
            }else if (num >= 4){
               printf("IV");
               num -= 4;
            }else if (num >= 1){
               printf("I");
               num -= 1;
            }
        }
        printf("\n");
    }else {
        printf("Niepoprawne wejście\n");
    }
}

void zad5() {
    FILE* fr;
    char buffer[1000];
    if((fr = fopen("settlement.txt", "r")) == NULL) {
        printf("Błąd podczas otwarzenia pliku\n");
        return;
    }
    char help[10];
    double num = 0;
    int count = 0;
    while(fscanf(fr, "%[^\n]", buffer) != -1) {
        for (int i = 0; i < 1000 && buffer[i] != 10; i++) {
            if(buffer[i] == ' ') {
                int j = 0;
                while(buffer[i] != 10) {
                    help[j] = buffer[i];
                    j++;
                    i++;
                }
                count++;
                num += atof(help);
                break;
            }
        }
        fseek(fr, 1, SEEK_CUR);
    }
    fclose(fr);
    if((fr = fopen("bill.txt", "w")) == NULL) {
        printf("Błąd podczas otwarzenia pliku\n");
        return;
    }
    
    fprintf(fr, "%f", num / count);
    fclose(fr);
    
}

void zad6() {
    FILE* fr;
    char buffer[1000];
    if((fr = fopen("settlement.txt", "r")) == NULL) {
        printf("Błąd podczas otwarzenia pliku\n");
        return;
    }
    char help[10];
    double num = 0;
    int count = 0;
    while(fscanf(fr, "%[^\n]", buffer) != -1) {
        for (int i = 0; i < 1000; i++) {
            if(buffer[i] == ':') {
                int j = 0;
                i++;
                while(buffer[i] != 10) {
                    help[j] = buffer[i];
                    j++;
                    i++;
                }
                count++;
                num += atof(help);
                break;
            }
        }
        fseek(fr, 1, SEEK_CUR);
    }
    
    fclose(fr);
    if((fr = fopen("bill.txt", "w")) == NULL) {
        printf("Błąd podczas otwarzenia pliku\n");
        return;
    }
    
    if(count != 0)
        fprintf(fr, "%f", num / count);
    
    fclose(fr);
}

void zad7(){
    FILE* fr;
    char buffer[1000];
    if((fr = fopen("input.txt", "r")) == NULL) {
        printf("Błąd podczas otwarzenia pliku\n");
        return;
    }
    int count = 0, max = 0, min = 100000, numOfWords = 0;
    double average = 0;
    while(fscanf(fr, "%[^\" \"]", buffer) != -1) {
        count = 0;
        numOfWords++;
        for (int i = 0; i < 1000 && buffer[i] != 0; i++) {
            count++;
        }
        average += count;
        if(count > max) {
            max = count;
        }
        if(count < min) {
            min = count;
        }
        fseek(fr, 1, SEEK_CUR);
    }
    fclose(fr);
    if((fr = fopen("statistics.dat", "w")) == NULL) {
        printf("Błąd podczas otwarzenia pliku\n");
        return;
    }

    fprintf(fr, "max: %d, min: %d, average: %f, num of words: %d\n", max, min, average / numOfWords, numOfWords);
    fclose(fr);
}

int main(int argc, char** argv) {
//    zad0();
//    zad1();
//    zad2();
//    zad3();
//    zad4();
    
//    zad5();
//    zad6();
//    zad7();
    
//    -------------ZAD_8---------------
    
//    if(argc == 1) {
//        //zwylkłe wykonanie podprogramów z nazwami domyślnymi
//    }else if(argc == 2) {
//        zad5(*(argv + 1));
//        zad6(*(argv + 1));
//        zad7(*(argv + 1));
//    }else if(argc >= 3) {
//        zad5(*(argv + 1), *(argv + 2));
//        zad6(*(argv + 1), *(argv + 2));
//        zad7(*(argv + 1), *(argv + 2));
//    }
    
//    ---------------------------------
    
//    -------------ZAD_9---------------
//    FILE* fr;
//    char buffer[30][1000];
//    if((fr = fopen(*(argv + 1), "r")) == NULL) {
//        printf("Błąd podczas otwarzenia pliku\n");
//        return 0;
//    }
//    int j = 0;
//    while(fscanf(fr, "%[^\n]", buffer[j]) != -1) {
//        j++;
//        fseek(fr, 1, SEEK_CUR);
//    }
//
//    int N = atoi(*(argv + 2));
//    for (int i = j - N; N != 0; i++) {
//        N--;
//        printf("%s\n", buffer[i]);
//    }
//
//    fclose(fr);
    
//    ----------------------------------
    
//    -------------ZAD_10---------------
//    FILE* fr;
//    char buffer[30][1000];
//
//    if((fr = fopen(*(argv + 1), "r")) == NULL) {
//        printf("Błąd podczas otwarzenia pliku\n");
//        return 0;
//    }
//    int j = 0;
//    while(fscanf(fr, "%[^\n]", buffer[j]) != -1) {
//        j++;
//        fseek(fr, 1, SEEK_CUR);
//    }
//
//    int N = atoi(*(argv + 2)), help;
//    char ch;
//    while(1){
//        help = N;
//        for (int i = j - help; help != 0; i = j - help) {
//            help--;
//            printf("%s\n", buffer[i]);
//        }
//        scanf("%c", &ch);
//        if(ch == 27 || ch == 'q') {
//            break;
//        }
//        if(ch != 10) {
//            scanf("%c", &ch);
//        }
//
//        j -= N;
//    }
//    fclose(fr);
//    --------------------------------
    
    return 0;
}
