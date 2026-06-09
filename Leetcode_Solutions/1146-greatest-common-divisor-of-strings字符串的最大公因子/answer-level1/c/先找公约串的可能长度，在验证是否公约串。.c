bool isGcdOfStrings(char * str, char *gcdStr){
    int i = 0;
    while (i < strlen(str)) {
        if (strstr(str+i, gcdStr) == NULL) {
            return false;
        }
        i = i + strlen(gcdStr);
    }
    return true;
}

char * gcdOfStrings(char * str1, char * str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int lenMin = len1;
    char *strMin = str1;
    int lenMax = len2;
    char *strMax = str2;    
    char * gcdStr = (char *)malloc((len1 + 1) * sizeof(char));
    memset(gcdStr, 0, len1 + 1);
    /*字符串必须为子串关系*/
    if (strstr(str1, str2) == NULL && strstr(str2, str1) == NULL) {
        return gcdStr;
    }
    /*用端串的N分之一进行判断否是为最多公约串*/
    if (len1 > len2) {
        lenMin = len2;
        strMin = str2;
        lenMax = len1;
        strMax = str1;
    }
    int gcdMax = 0;
    for (int i = 1; i <= lenMin; i++) {
        if (lenMin % i == 0){
            gcdMax = lenMin / i;
            if (lenMax % gcdMax == 0){
                /*找到可能的最大公约串*/
                strncpy(gcdStr, strMin, gcdMax);
                /*判断是否最大公约串*/
                if (isGcdOfStrings(strMin,gcdStr) && isGcdOfStrings(strMax,gcdStr)) {
                    return gcdStr;
                }
                memset(gcdStr, 0, len1 + 1);
            }
        }
    }
    return gcdStr;
}