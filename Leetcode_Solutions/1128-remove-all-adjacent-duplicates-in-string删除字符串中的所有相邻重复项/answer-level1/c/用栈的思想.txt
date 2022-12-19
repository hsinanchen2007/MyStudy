执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户

内存消耗 :3 MB, 在所有 C 提交中击败了100.00%的用户

用栈的思想来处理
```
char * removeDuplicates(char * S){
    int write = -1;
    int read  = 0;
    char ch;    
    
    while(ch = S[read++]){
        if(write < 0){ //初始化
            write = 0;
	    S[0] = ch;
        }else{
	    if(S[write] == ch){ //出栈
	          write--;
	    }else{
	          S[++write] = ch; //进栈                                  
	    }  
        }                          
    }
    S[++write] = 0;
    return S;
}
```

