# strchr是计算机编程语言的一个函数，原型为extern char *strchr(const char *s,char c)，可以查找字符串s中首次出现字符c的位置。（百度百科）

```
int numJewelsInStones(char * J, char * S){
    int i,num=0;
    for(i=0;S[i]!='\0';i++){
        if(strchr(J,S[i])) //若S[i]在J中则返回一个S[i]所在位置的指针
            num++;
    }
    
    return num;
}
```

