# 暴力破解
```
char * maskPII(char * S){
    int len = strlen(S);
    char *result = (char *)malloc(len + 6);
    memset(result, 0, len + 6);
    char *email = strchr(S, '@');
    int numCount = 0;
    char nums[5];
    nums[4] = '\0';  
    for (int i = len - 1; i >= 0; i--) {
        S[i] = tolower(S[i]);
        if (S[i] >= '0' && S[i] <='9') {
            if (numCount < 4) {
                nums[3 - numCount] = S[i];
            }
            numCount++;
        }
    }
    if (email != NULL) {
        result[0] = S[0];
        char *password = "*****";
        strcpy(result + 1, password);
        result[6] = *(email - 1);
        strcpy(result + 7, email);
    }else {
        char *passnum;
        if (numCount == 10) {
            passnum = "***-***-";
        }
        if (numCount == 11) {
            passnum = "+*-***-***-";
        }
        if (numCount == 12) {
            passnum = "+**-***-***-";
        }
        if (numCount == 13) {
            passnum = "+***-***-***-";
        }
        strcpy(result, passnum);
        strcpy(result + strlen(passnum), nums);
    }
    return result;
}代码块
```
