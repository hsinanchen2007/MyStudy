char * gcdOfStrings(char * str1, char * str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char * re = (char *)malloc(sizeof(char)*1001);
    int flag1 = 0;
    int flag2 = 0;
    for (int i = 0; i < len1; i++){
        re[i] = str1[i];
    }
    int minLen;
    if (len1 > len2){
        minLen = len2;
    } else {
        minLen = len1;
    }
    for (int i = minLen; i >= 1; i--){
        flag1 = 0;
        flag2 = 0;
        if (len1 % i == 0 && len2 % i == 0) {
            for (int j = 0; j < len1; j++){
                if (str1[j] != re[j % i]){
                    flag1 = 1;
                    break;
                }
            }
            for (int j = 0; j < len2; j++){
                if (str2[j] != re[j % i]){
                    flag2 = 1;
                    break;
                }
            }
            if (flag1 == 0 && flag2 == 0){
                re[i] = '\0';
                return re;
            }
        }

    }
    re[0] = '\0';
    return re;

}