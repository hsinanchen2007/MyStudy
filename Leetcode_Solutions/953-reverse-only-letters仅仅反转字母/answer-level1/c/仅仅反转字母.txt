```c
char * reverseOnlyLetters(char * s)
{
    int len = strlen(s), i, j = 0;
    char* stk = (char*)malloc(sizeof(char) * len);
    char* p = (char*)malloc(sizeof(char) * (len+1));
    int top = -1;
    for(i = 0 ; i < len; i++){
        if(isalpha(s[i])){
            stk[++top] = s[i];
        }
    }
    for(i = 0; i < len; i++){
        if(isalpha(s[i])){
            p[j++] = stk[top--];
        }
        else{
            p[j++] = s[i];
        }
    }
    p[j] = '\0';
    free(stk);
    return p;
}
```