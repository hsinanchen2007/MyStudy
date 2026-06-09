```
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strs == NULL) {
        return NULL;
    }
    if(strsSize == 0) {
        return "";
    }
    
    int index = 0;
    for(; index < strlen(strs[0]); index++) {
        for(int i = 1; i < strsSize; i++) {
            if((strs[i][index] == '\0') || (strs[i][index] != strs[0][index])) {
                strs[0][index] = '\0';
                break;
            }
        }

    }

    return strs[0];
}
```
