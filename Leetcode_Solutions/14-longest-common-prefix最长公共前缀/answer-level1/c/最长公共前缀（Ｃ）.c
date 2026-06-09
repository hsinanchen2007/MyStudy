
**首先将第一个字符串作为ans，然后依次与后面的每一个字符串比较并更新ans，若某一趟途中ans为空，即没有公共前缀，直接返回。这样，最后得到的ans即为所求。**

```c
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0)
        return "";
    char *ans = strs[0];
    int i, j;
    for(i = 1; i < strsSize; i++){
        j = 0;
        for(; ans[j] != '\0' && strs[i][j] != '\0'; j++){
            if(ans[j] != strs[i][j]){
                break;
            }
        }
        ans[j] = '\0';
        if(ans == NULL){
            return "";
        }
    }
    return ans;

}
```