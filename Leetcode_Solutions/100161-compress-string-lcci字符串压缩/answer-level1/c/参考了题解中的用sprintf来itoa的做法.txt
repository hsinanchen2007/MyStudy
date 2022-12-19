```
char* compressString(char* S){
    int len = strlen(S);
    if (len < 3) {
        return S;
    }
    char * retS = (char *)malloc(sizeof(char) * len * 2);
    memset(retS, 0, len * 2);
    char c = S[0];
    int cLen = 1;
    for (int i = 1; i < len; i++) {
         if (c == S[i]) {
             cLen++;
         }else {
            retS[strlen(retS)] = c;
            char string[50];
            sprintf(string, "%d", cLen);
            strncat(retS, string, cLen);
            c = S[i];
            cLen = 1;
         }
    }    
    retS[strlen(retS)] = c;
    char string[50];
    sprintf(string, "%d", cLen);
    strncat(retS, string, cLen);
    return strlen(retS) < strlen(S) ? retS : S;
}
```
