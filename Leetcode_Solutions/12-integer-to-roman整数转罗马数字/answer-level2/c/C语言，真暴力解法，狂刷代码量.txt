执行用时 :0 ms, 在所有 c 提交中击败了100.00%的用户
内存消耗 :7.8 MB, 在所有 c 提交中击败了77.90%的用户
```
char * intToRoman(int num) {
    int length = 0;
    
    int num_M = num / 1000;
    num -= 1000 * num_M;
    
    int num_CM = num / 900;
    num -= 900 * num_CM;
    
    int num_D = num / 500;
    num -= num_D * 500;
    
    int num_CD = num / 400;
    num -= num_CD * 400;
    
    int num_C = num / 100;
    num -= num_C * 100;
    
    int num_XC = num / 90;
    num -= num_XC * 90;
    
    int num_L = num / 50;
    num -= num_L * 50;
    
    int num_XL = num / 40;
    num -= num_XL * 40;
    
    int num_X = num / 10;
    num -= num_X * 10;
    
    int num_IX = num / 9;
    num -= num_IX * 9;
    
    int num_V = num / 5;
    num -= num_V * 5;
    
    int num_IV = num / 4;
    num -= num_IV * 4;
    
    int num_I = num;
    
    char *n = (char *)malloc(sizeof(char)*100);
    
    while ( num_M > 0){
        n[length] = 'M';
        length ++;
        num_M--;
    }
    
    while ( num_CM > 0){
        n[length] = 'C';
        n[length + 1] = 'M';
        length += 2;
        num_CM--;
    }
    
    while ( num_D > 0){
        n[length] = 'D';
        length ++;
        num_D--;
    }
    
    while ( num_CD > 0){
        n[length] = 'C';
        n[length + 1] = 'D';
        length += 2;
        num_CD--;
    }

    while ( num_C > 0){
        n[length] = 'C';
        length ++;
        num_C--;
    }
    
    while ( num_XC > 0){
        n[length] = 'X';
        n[length + 1] = 'C';
        length += 2;
        num_XC--;
    }
    
    while ( num_L > 0){
        n[length] = 'L';
        length ++;
        num_L--;
    }
    
    while ( num_XL > 0){
        n[length] = 'X';
        n[length + 1] = 'L';
        length += 2;
        num_XL--;
    }
    
    while ( num_X > 0){
        n[length] = 'X';
        length ++;
        num_X--;
    }
    
    while ( num_IX > 0){
        n[length] = 'I';
        n[length + 1] = 'X';
        length += 2;
        num_IX--;
    }
    
    while ( num_V > 0){
        n[length] = 'V';
        length ++;
        num_V--;
    }
    
    while ( num_IV > 0){
        n[length] = 'I';
        n[length + 1] = 'V';
        length += 2;
        num_IV--;
    }
    
    while ( num_I > 0){
        n[length] = 'I';
        length ++;
        num_I--;
    }
    n[length] = '\0';
    return n;
}
```
