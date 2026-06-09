```
char * reverseWords(char * s){
    int length = strlen(s);
    if(length == 0) {
        return "";
    }
    char * res = (char *)malloc((length * 10) * sizeof(char));
    memset(res, 0, (length * 10) * sizeof(char));
    res[length - 1] = '\0';
    char **temp = (char**)malloc(length * sizeof(char *));
    int tempNum = 0;
    char *p = s;
    while(*p != '\0') {
        if(*p != ' ') {
            char *q = p;
            p++;
            while(*p != ' ' && *p != '\0') {
                p++;
            }
            temp[tempNum]= (char *) malloc((p - q + 1) * sizeof(char));
            memset(temp[tempNum], 0, (p - q + 1) * sizeof(char));
            temp[tempNum][p - q] = '\0';
            memcpy(temp[tempNum], q, p - q);
            tempNum++;     
        }
        if(*p != '\0') {
            p++;
        }
    }
    for(int i = tempNum - 1; i >= 0; i--) {
        if(i == tempNum - 1) {
            memcpy(res, temp[i], strlen(temp[i]));
            if(tempNum != 1) {
                strcat(res, " ");
            }
        } else {
            strcat(res, temp[i]);
            if(i != 0) {
                strcat(res, " ");   // res 分配的空间不够大，所以需要大一点。
            }
        }   
    }
    
    
    return res;
    
}
```
