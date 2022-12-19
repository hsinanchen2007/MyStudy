变量sign作为标志，初始值为0，sign逢'L'加一，逢'R'减一，每当sign回到0，则平衡字符串数目增加一。
```c
int balancedStringSplit(char * s){
    short i=0,count=0,sign=0;
    while(s[i]){
        sign=s[i++]=='L'?sign+1:sign-1;
        if(sign==0) count++;
    }
    return count;
}
```