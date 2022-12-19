用数组构造一个栈，遇到')'后出栈，向数组前遍历，直到找到运算符，并把结果赋值给运算符的位置。然后重新入栈，一次类推。直到结束，数组第一个值就是结果。

    
bool parseBoolExpr(char * expression){
    char exp_stack[20001] = {0};
    char *exp_str = expression;
    int len = strlen(expression);
    int index = 0;
    int stack_len = 0;
    int find_f = 0;
    int find_t = 0;
for(;index < len; index++){
        find_f = 0;
        find_t = 0;
        if(exp_str[index] != ')'){
            exp_stack[stack_len] = exp_str[index];
            stack_len++;
        }else{
            for(int i = stack_len-1; i >=0 ;i--){
                
                if(exp_stack[i] == '!'){
                    if(exp_stack[i+2] == 't'){
                        exp_stack[i] = 'f';
                    }else{
                        exp_stack[i] = 't';
                    }
                    
                    //清零后续栈数组内容
                    for(int j = i+1; j <stack_len; j++){
                        exp_stack[j] = 0;
                    }
                    stack_len = i+1;
                    break;
                }
                if(exp_stack[i] == '|'){
                    if(find_t == 1){
                        exp_stack[i] = 't';
                    }else{
                        exp_stack[i] = 'f';
                    }
                    //清零后续栈数组内容
                    for(int j = i+1; j <stack_len; j++){
                        exp_stack[j] = 0;
                    }
                    stack_len = i+1;
                    break;
                }
                if(exp_stack[i] == '&'){
                    if(find_f == 1){
                        exp_stack[i] = 'f';
                    }else{
                        exp_stack[i] = 't';
                    }
                    
                    //清零后续栈数组内容
                    for(int j = i+1; j <stack_len; j++){
                        exp_stack[j] = 0;
                    }
                    stack_len = i+1;
                    break;
                }
                if(exp_stack[i] == 'f'){
                    find_f = 1;
                }
                if(exp_stack[i] == 't'){
                    find_t = 1;
                }
                //printf("stac %s, pop %c, len %d\r\n",exp_stack,exp_stack[i],i);
            }
        }
    }

    return exp_stack[0] == 'f'?0:1;
}