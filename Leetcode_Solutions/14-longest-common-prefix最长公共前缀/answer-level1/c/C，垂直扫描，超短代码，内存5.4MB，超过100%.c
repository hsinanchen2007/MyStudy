```
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0) return "";  //如果字符串数组为空，直接返回""
    for(int i=0;i<strlen(strs[0]);i++){   //i表示列，strlen(strs[0])表示第一个字符串长度
        for(int j=1;j<strsSize;j++){    //j表示行
            if(strs[0][i]!=strs[j][i]){ //如果比较字符串的第i列不同，该列结束，直接跳出
                strs[0][i]='\0';
                break;
            }
        }
    }
    return strs[0];
}
```
