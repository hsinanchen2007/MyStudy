
一种不好的解法：

```c
#define STR_MAX_LEN 100
char ** commonChars(char ** A, int ASize, int* returnSize){
    char** ret = malloc(sizeof(char*)*STR_MAX_LEN);
    int retCnt = 0;
    char* base = A[0];
    int len = strlen(base);

    for (int i = 0; i < len; i++) {
        int j = 1;
        for( ; j < ASize; j++) {
            char* tmpStr = A[j];
            int tmpLen = strlen(tmpStr);
            int k = 0;
            for( ; k < tmpLen; k++) {
                if(tmpStr[k] == base[i]) {
                    tmpStr[k] = '*';
                    break;
                }
            }
            if(k == tmpLen) {
                break;
            }
        }
        if(j == ASize) {
            char* newChar = malloc(sizeof(char)*2);
            newChar[0] = base[i];
            newChar[1] = '\0';
            ret[retCnt++] = newChar;
        }
    }
    *returnSize = retCnt;
    return ret;
}
```
