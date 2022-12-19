用栈的思想，但不用实际创建栈，将原S串当成栈使用，两个下标一个write一个read指针即可。top字符为write下标的前一位，read出的字符和top一样则将write退1，否则压栈。

- 执行用时 :4 ms, 在所有C提交中击败了97.37% 的用户
- 内存消耗 :8.2 MB, 在所有C提交中击败了100.00%的用户
```

char * removeDuplicates(char * S){
    int write=0;
    int read=0;
    char top, ch;    
    
    while(ch = S[read++]){
        if(0 == write){ // empty string
            top = 0;
        }else{
            top = S[write-1];
        }
        
        if(ch == top){ //delete top character
           write--;
        }else{ // write current character to top
            S[write++] = ch;                                  
        }                              
    }
    S[write] = 0;
    
    return S;
}
```