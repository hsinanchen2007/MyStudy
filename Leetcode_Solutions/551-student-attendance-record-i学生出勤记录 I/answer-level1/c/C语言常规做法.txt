先检查是否有一次以上缺勤，再检查是否有连续两次以上迟到。
```c
bool checkRecord(char * s){
    int i,a=0,length=0;
    while(s[length]!=0) length++;
    for(i=0;i<length;i++){
        if(s[i]=='A') a++;
        if(a>1) return 0;
    }
    for(i=0;i<length-2;i++){
        if(s[i]=='L'&&s[i+1]=='L'&&s[i+2]=='L') return 0;
    }
    return 1;
}
```