### 解题思路
此处撰写解题思路

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
    int i,j,m;
    char **p=strs;
    if(strsSize==0) return "";
    for(i=1,m=strlen(p[0]);i<strsSize;i++){
        j=0;
        while(*(p[0]+j)==*(p[i]+j)&&*(p[0]+j)!='\0'){
            j++;
        }
        if(m>j) m=j;
    }
    if(m==0) return "";
    p[0][m]='\0';
    return strs[0];
}
```