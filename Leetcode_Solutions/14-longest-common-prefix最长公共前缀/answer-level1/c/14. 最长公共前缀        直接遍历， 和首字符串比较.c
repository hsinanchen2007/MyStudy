### 解题思路


### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){

    int k =0,i;
    /*注意输入为野指针时，返回这种空串，*/
    if(strsSize == 0)
        return "";
    /*循环直到字符串结束*/
    while(strs[0] != NULL && strs[0][k] != '\0'){
        /*将每个字符串都和第一个比一下*/
        for(i=0;i<strsSize;i++){
            /*考虑每个字符串这会是不是结束了*/
            if(strs[i][k]!='\0' && strs[i][k] == strs[0][k])
                continue;
            strs[0][k] = '\0';
            return strs[0];
        }
        k++;
    }
    strs[0][k] = '\0';

    return strs[0];
}
```