### 解题思路
令最长前缀为第一个字符串，然后不断和之后的字符串比较，不断截断得到所有字符串的前缀。

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
    int i=0,j=0;
    if(strsSize==0) {
        return "";
    }
    if(strsSize==1) {
        return *strs;
    }
    char *ans=strs[0];
    for(i=1;i<strsSize;i++){
        for(j=0;ans[j]!='\0'&&strs[i][j]!=0;j++){
            if(ans[j]!=strs[i][j]) break;
        }
        ans[j]='\0';
        if(ans==NULL) return "";
    }
    return ans;
    
}



```