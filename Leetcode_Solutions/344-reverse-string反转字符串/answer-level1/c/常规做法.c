### 解题思路
不过为什么第一种方法56ms，第二种84ms，感觉是一样的呀

### 代码

```c
void reverseString(char* s, int sSize){
    if(sSize==0||sSize==1) return ;
    unsigned int i,j,m;
    i=0;m=sSize/2;j=sSize-1;
    while(i<j){
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;j--;
    }
}
```

void reverseString(char* s, int sSize){
    if(sSize==0&&sSize==1){
    unsigned int i,j,m;
    i=0;m=sSize/2;j=sSize-1;
    while(i<j){
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;j--;
    }
    }
}
