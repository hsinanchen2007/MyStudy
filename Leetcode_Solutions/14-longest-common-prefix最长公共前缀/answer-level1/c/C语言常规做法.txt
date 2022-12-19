将strs[0]字符串作为基准，通过遍历的方式比较字符串数组中每个字符串的前面组成，并不断延长，直到不符合“公共”要求为止。
```c
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0) return "";
    int index=0,j;
    while(1){
        for(j=0;j<strsSize;j++)
            if (strs[j][index]!=strs[0][index]||strs[j][index]==0) break;
        if (j==strsSize) index++;
        else break;
    }
    char s[index+1];
    for (j=0;j<index;j++)
        s[j]=strs[0][j];   
    s[index]=0;
    char* str=s;
    return str;
}
```