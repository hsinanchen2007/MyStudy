```c
void reverseString(char* s, int sSize){
    short i,tmp;
    for(i=0;i<(sSize+1)/2;i++){
        tmp=s[i];
        s[i]=s[sSize-1-i];
        s[sSize-1-i]=tmp;
    }
}
```