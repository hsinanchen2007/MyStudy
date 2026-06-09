最长公共字串，就相当于木桶效应一样，最短的决定结果

```
char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) {
        char *ret = (char *)malloc(1);
        ret[0] = '\0';
        return ret;
    }
    if (strsSize == 1) return strs[0];
    int i = 0, j, is = 1, tmp;
    for (; is; ++i) {
        tmp = strs[0][i];
        for (j = 0; j  < strsSize; ++j) 
            if ((!strs[j][i]) || (strs[j][i] != tmp)) 
                {   is = 0;     break;  }
    }
    strs[0][i-1] = '\0';
    return strs[0];
}
```
