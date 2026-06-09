```
char * removeOuterParentheses(char * S){
    int i, count = 0, j = 0;
    for(i = 0; S[i]!='\0'; i++){
        if(S[i] == '('){
            count++;
            if(count>1)
                S[j++] = '(';
        }
        else{
            count--;
            if(count>0)
                S[j++] = ')';
        }
    }
    S[j] = '\0';      // 这行也记得要！
    return S;
}
```
