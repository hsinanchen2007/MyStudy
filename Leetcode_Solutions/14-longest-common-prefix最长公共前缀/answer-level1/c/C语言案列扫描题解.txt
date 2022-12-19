### 解题思路
案列扫描，将第一个字符数组作为标准，扫描后续字符串。不需要另外新建存储字符串，找到符合要求的最长的字符串，然后加‘\0’，返回结果的输出即符合要求。

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
    int index=0,j=0;
    char *a=strs[0];
    if(strsSize==0) return "";
    while(1){
        for(j=0;j<strsSize;j++)
            if (strs[j][index]!=strs[0][index]||strs[j][index]==0) break;
        if (j==strsSize) 
            index++;
        else break;
    }
    a[index]='\0';
    return a;
}

```