朴素算法：
```
int strStr(char * haystack, char * needle){
    int i =0,j=0;
    while (i<strlen(haystack)&&j<strlen(needle))
    {
        if (haystack[i]==needle[j])
        {
            i++;j++;
        }
        else
        {
            i=i-j+1;
            j=0;
        }
    }
    if (j==strlen(needle))
        return i-j;
    else
        return -1;
    
}
```
KMP算法，啧.....其实我下面这个有缺陷，多用了一个Char空间。
```
int strStr(char * haystack, char * needle){

    int i=0,j=-1;
    int *next = (int *)malloc(sizeof(int)*(strlen(needle)+1));//不加1数组访问越界警报！！heap-over-flow    
    next[0]=-1;
    while (i<strlen(needle))
    {
        if(j==-1||needle[i]==needle[j])
        {
            i++;j++;next[i]=j;
        }
        else
            j=next[j];
    }
    i=0;j=0;
    while (i<strlen(haystack)&&j<(signed int)strlen(needle))
    {
        if(j==-1||haystack[i]==needle[j])
        {
            ++i;++j;
        }
        else
            j=next[j];
    }
    if (j==strlen(needle))
        return i-j;
    else
        return -1;
}
```


