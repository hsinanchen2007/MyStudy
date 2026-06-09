内存超过100%，用时超过96%

/////////////////////////////////////////////////
char * convert(char * s, int numRows){
    int bigInterval = (numRows - 1) * 2;
    int smallInterval = bigInterval;
    int temp;
    int len = strlen(s);
    char *retStr = (char *)malloc(sizeof(char) * strlen(s) + 1);
    int strIdx = 0;
    int maxIdx = numRows < len ? numRows : len;
    if (s == NULL || *s == '\0') {
        retStr[0] = '\0';
        return retStr;
    }
    if (numRows == 1 || len == 1) {
        memcpy(retStr, s, len);
        retStr[len] = '\0';
        return retStr;
        printf("%d\n",len);
    } 
    for (int i = 0; i < maxIdx; i++) {
        temp = i;
        retStr[strIdx++] = s[temp];
        while (temp + smallInterval < len) {
            if (smallInterval != bigInterval && smallInterval != 0) {
                retStr[strIdx++] = s[temp + smallInterval];
            }
            if (temp + bigInterval < len) { 
                retStr[strIdx++] = s[temp + bigInterval];
            } else {
                break;
            }
            temp += bigInterval;
        }
        smallInterval -= 2;
    }
    retStr[strlen(s)] = '\0';
    return retStr;
}