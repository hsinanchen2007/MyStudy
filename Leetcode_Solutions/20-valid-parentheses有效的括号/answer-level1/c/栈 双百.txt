```


bool isValid(char * s){
    int len = strlen(s);
    int top = -1;
    char *stack = (char*)malloc(len*sizeof(char));
    for(int i = 0;i<len;i++){
        if(s[i]=='{'||s[i]=='['||s[i]=='('){
            stack[++top] = s[i];
        }
        else{ 
            if(top == -1) {
                stack[++top] = s[i];
                continue;
            }
            if(s[i]==']'){ 
                if(stack[top]=='['){
                    top--;
                }
                else{
                    stack[++top] = s[i];
                }
            }
            if(s[i]=='}'){
                if(stack[top]=='{'){
                    top--;
                }
                else{
                    stack[++top] = s[i];
                }
            }
            if(s[i]==')'){
                if(stack[top]=='('){
                    top--;
                }
                else{
                    stack[++top] = s[i];
                }
            }

        }
    }
    return top == -1;
}
```
