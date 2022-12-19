### 解题思路


### 代码

```c
char * removeOuterParentheses(char * S){
    int cnt = 0,k = 0;
    for(int i = 0;i < strlen(S);i++){
        if(S[i] == '('){
            if(cnt != 0) S[k++] = S[i];
            cnt ++;
        }
        if(S[i] == ')'){
            cnt--;
            if(cnt != 0) S[k++] = S[i];
        }
    }
    S[k] = '\0';
    return S;
}
```