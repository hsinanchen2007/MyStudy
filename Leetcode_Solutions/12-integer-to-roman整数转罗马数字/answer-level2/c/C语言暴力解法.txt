#define MAX_STR_LEN 100

char * intToRoman(int num){
    char *res = (char *)malloc(MAX_STR_LEN * sizeof(char));
    memset(res, '\0', MAX_STR_LEN * sizeof(char));

    int temp = num;
    int index = 0;
    char *nRes;
    if (temp/1000 > 0) {
        for (int i = 0; i < temp/1000; i++) {
            res[index++] = 'M';
        }
        nRes = intToRoman(temp%1000);
    }else if (temp/900 > 0){        
        res[index++] = 'C';
        res[index++] = 'M';
        nRes = intToRoman(temp%900);
    } else if(temp/500 > 0 ) {
        res[index++] = 'D';
        nRes = intToRoman(temp%500);
    } else if(temp/400 > 0 ) {
        res[index++] = 'C';
        res[index++] = 'D';
        nRes = intToRoman(temp%400);
    } else if(temp/100 > 0 ) {        
        for (int i = 0; i < temp/100; i++) {
            res[index++] = 'C';
        }
        nRes = intToRoman(temp%100);
    } else if(temp/90 > 0 ) {
        res[index++] = 'X';
        res[index++] = 'C';
        nRes = intToRoman(temp%90);
    } else if(temp/50 > 0 ) {
        res[index++] = 'L';
        nRes = intToRoman(temp%50);
    } else if(temp/40 > 0 ) {
        res[index++] = 'X';
        res[index++] = 'L';
        nRes = intToRoman(temp%40);
    } else if(temp/10 > 0 ) {
        for (int i = 0; i < temp/10; i++) {
            res[index++] = 'X';
        }
        nRes = intToRoman(temp%10);
    } else if(temp/9 > 0 ) {
        res[index++] = 'I';
        res[index++] = 'X';      
        nRes = intToRoman(temp%9);
    } else if(temp/5 > 0 ) {
        res[index++] = 'V';    
        nRes = intToRoman(temp%5);
    } else if(temp/4 > 0 ) {
        res[index++] = 'I';
        res[index++] = 'V';        
        nRes = intToRoman(temp%4);
    } else if(temp/1 > 0 ) {
        for (int i = 0; i < temp/1; i++) {
            res[index++] = 'I';
        }
        nRes = intToRoman(temp%1);
    }else{
        res[index++] = '\0';
    }

    for (int i = 0; i < strlen(nRes); i++) {
        res[index++] = nRes[i];
    }

    return res;
}