1.求解两个字符串的最大公共前缀
2.递归求解其他字符串
3.当有多个数据（A,B,C）计算关系的时候，可以递归两两计算
```

char * longestPrefix(char *s, char *t) 
{
    if (s == NULL || t == NULL) {
       return NULL; 
    }
    
    int i = 0;
    int j = 0;
    for (; i < strlen(s) && j < strlen(t); ++i,++j) {
        if (s[i] != t[j]) {
            break;
        }
    }

    char *prefix = (char *)malloc(sizeof(char) * (i + 1));
    if (prefix == NULL) {
       return NULL; 
    }
    memset(prefix, 0, i + 1);
    memcpy(prefix, s, i);
    prefix[i] = '\0';
    printf("%s, %s, %s\r\n", s,t,prefix);
    
    free(s);
    s = NULL;
    free(t);
    t = NULL;
    return prefix;
}

char * longestCommonPrefix(char ** strs, int strsSize){
    if (strs == NULL) {
        return NULL;
    }
    if (strsSize <= 0) {
        return strdup(""); 
    }
    
    if (strsSize == 1) {
       return strdup(strs[0]); 
    }

    return longestPrefix(strdup(strs[0]), longestCommonPrefix(&strs[1], strsSize - 1));
    
}


```
