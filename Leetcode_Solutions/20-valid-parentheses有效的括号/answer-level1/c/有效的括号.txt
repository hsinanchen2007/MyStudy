注意边界情况：'[' 或者 ''

```
bool isValid(char * s){
    int len = strlen(s), top = -1, i;
    char c;
    char stk[1+len];
    for( i=0 ; i<len ; i++){
        c = s[i];
        if(c == '(' || c=='{' || c=='[' ) stk[++top] = c;
        else if(c == ')'){
            if(top == -1) return false;
            if( stk[top--] == '(') continue;
            else return false;
        }
        else if(c == '}'){
            if(top == -1) return false;
            if( stk[top--] == '{') continue;
            else return false;
        }
        else if(c == ']'){
            if(top == -1) return false;
            if( stk[top--] == '[') continue;
            else return false;
        }
    }
    if(i == len && top == -1 ) return true;   // 记得保证栈最后为空。。
    else return false;
}
```
