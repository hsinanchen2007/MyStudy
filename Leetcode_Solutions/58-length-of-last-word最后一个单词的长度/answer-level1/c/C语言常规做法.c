```c
int lengthOfLastWord(char * s){
    short i=0,count=0;
    while(s[i]!=0) i++;
    if(i==0) return 0;
    i--;
    while(s[i]==' '){
        i--;
        if(i<0) return 0;
    }
    while(s[i]!=' '){
        count++;
        i--;
        if(i<0) return count;
    }
    return count;
}
```