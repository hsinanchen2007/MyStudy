bool isValid(char * s){
    int i = 0;
    DataType c;
    DataType top;
    SeqStack MyStack; 
    SeqStackInit(&MyStack);

    if(s != NULL){   //判断s为空返回true
        if(strlen(s) == 0)
            return true;
    }
    SeqStacPush(&MyStack,*(s + i));   //将第一个括号压入栈中
    i ++;
    while(*(s +i) != '\0'){
        SeqStackGetTop(MyStack,&top);  //取出栈顶的括号
        if((*(s +i) == top+1) || (*(s +i) == top+2)){  //判断是否匹配，因为只有三种括号，直接用ASCII码判断
            if(SeqStackPop(&MyStack,&c) != 1)  //如果匹配，就把栈顶的括号给弹出
                return false;
        }
        else
            SeqStacPush(&MyStack,*(s + i));  //如果不匹配，就压如栈中
        i ++;
    }

    if(SeqStackLength(MyStack) == 0){  //如果把字符串遍历完毕，栈为空，证明所有括号全部匹配上
        return true;
    }
        
    else{
        return false;
    }
        
}
```