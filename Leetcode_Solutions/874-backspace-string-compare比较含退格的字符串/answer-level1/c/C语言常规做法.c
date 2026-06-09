利用双指针和栈在字符串S和T上原地修改，最后逐个元素比较。
```c
void convert(char* str){
    int i=str[0]=='#'?0:1,stack_index=0;
    while(str[i]){
        if(str[i++]=='#'){
            if(stack_index) stack_index--;
            else str[stack_index]=0;
        }
        else{
            if(str[stack_index]) stack_index++;
            str[stack_index]=str[i-1];
        }
    }
    str[stack_index+1]=0;
}

bool backspaceCompare(char * S, char * T){
    int i=0;
    convert(S);
    convert(T);
    while(S[i]){
        if(T[i]==0||S[i]!=T[i]) return 0;
        i++;
    }
    return T[i]==0;
}
```