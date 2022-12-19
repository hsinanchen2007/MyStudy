C语言重构字符串，双百通过
char * reorganizeString(char * S){
    int len = strlen(S);
    char *outStr = (char *)malloc(sizeof(char)*(500 + 1)); 
    int num[26] = {0};
    int maxIndex = -1;
    int max = -1;
    for (int i = 0; i < len; i++) {
        num[S[i] - 'a']++;
        if (num[S[i] - 'a'] > (len + 1)/2) {
            outStr[0] = '\0';
            break;
        }
        if (max < num[S[i] - 'a']) {
            max = num[S[i] - 'a'];
            maxIndex = S[i] - 'a';
        }
    }
    int delta = 0;
    if(outStr[0] != '\0') {
        for (int j = 0; j < max; j++) {
            outStr[2 * j + delta] = 'a' + maxIndex;
        }
        delta += max * 2;
        for (int i = 0; i < 26; i++) {
            if ((i != maxIndex) && (num[i] != 0)) {
                for (int j = 0; j < num[i]; j++) {
                    if (2 * j + delta > len) {
                        delta -= len;
                        outStr[2 * j + delta] = 'a' + i;
                        //printf("0 %d, %c\n", 2 * j + delta, outStr[2 * j + delta]);
                    } else if (2 * j + delta == len) {
                        delta = delta - len + 1;
                        outStr[2 * j + delta] = 'a' + i;
                        //printf("1 %d, %c\n", 2 * j + delta, outStr[2 * j + delta]);
                    } else {
                        outStr[2 * j + delta] = 'a' + i;
                        //printf("2 %d, %c\n", 2 * j + delta, outStr[2 * j + delta]);
                    }
                    
                }
                delta += num[i] * 2;
            }
        }
        
        outStr[len] = '\0';
    }
    return outStr;
}
