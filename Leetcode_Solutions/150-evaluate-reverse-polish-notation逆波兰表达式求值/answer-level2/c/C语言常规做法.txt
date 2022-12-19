用数组构成栈。需要特别注意注释中标有的坑。
```c
int charToInt(char* str){
    int i=str[0]=='-'?1:0,num=0;
    while(str[i])
        num=num*10+str[i++]-'0';
    return str[0]=='-'?-num:num;
}

int evalRPN(char ** tokens, int tokensSize){
    int i=1,stack_index=0;
    int stack[(tokensSize+1)/2];
    stack[0]=charToInt(tokens[0]);
    while(i<tokensSize)
        switch(tokens[i++][0]){
            case '+':
                stack[--stack_index]=stack[stack_index-1]+stack[stack_index];
                break;    
            case '*':
                stack[--stack_index]=stack[stack_index-1]*stack[stack_index];
                break;
            case '/':
                stack[--stack_index]=stack[stack_index-1]/stack[stack_index];
                break;
            case '-':
                if(tokens[i-1][1]==0){
                    stack[--stack_index]=stack[stack_index-1]-stack[stack_index];
                    break;
                }
            //为负数时，会误认为减号，因此需要if语句甄别，不是的话按顺序到default执行。
            default:
                stack[++stack_index]=charToInt(tokens[i-1]);
            }
    return stack[0];
}
```