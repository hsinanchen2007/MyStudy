### 解题思路
此处撰写解题思路

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0) return "";
    int i = 1,j=0,num=strlen(strs[0]);
    int n;
    char* str;
    while(i<strsSize){
        j=0;
        while(strs[0][j] == strs[i][j] && strs[0][j] != '\0'){
            j++;
        }
        if(num>j){
            num=j;
        }
        i++;
    }
    str = (char*)malloc(sizeof(char)*(num+1));
    for(n=0;n<num;n++){
        str[n] = strs[0][n];
    }
    str[n]='\0';
    return str;
}
```