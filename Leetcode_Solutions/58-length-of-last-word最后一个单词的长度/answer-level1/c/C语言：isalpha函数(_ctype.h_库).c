```
int lengthOfLastWord(char * s){
    int i, flag = 0, len = 0;
    for (i = strlen(s) - 1; i >= 0; i--){
        if (isalpha(s[i])){
            flag = 1;
            len++;
        }
        if (flag && !isalpha(s[i]))
            break;
    }
    return len;
}
```
