方法1：4ms

```
int strStr(char * haystack, char * needle){
    int len1 = 0, len2 = 0;
    char *p = haystack;
    len1 = strlen(haystack);
    len2 = strlen(needle);
    if (len2 == 0)
        return 0;
    for (int i = 0; i <= len1 - len2; i++){
        if (strncmp(p + i, needle, len2) == 0)
            return i;
    }
    return -1;
}
```

4ms ~ 8ms
```
int strStr(char * haystack, char * needle){
    int len2 = strlen(needle);
    if (!len2)
        return 0;
    int len1 = strlen(haystack);

    for (int i = 0; i <= len1 - len2; i++){
        int j;
        if (haystack[i] == needle[0]){
            for (j = 0; j < len2; j++){
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == len2)
                return i;
        }
    }
    return -1;
}
```


方法2：4ms ~ 8ms
```
int strStr(char * haystack, char * needle){
    int len1 = strlen(haystack);
	int len2 = strlen(needle);
	int i = 0, j = 0;
	
	while (i < len1 && j < len2){
		if (haystack[i] == needle[j])
			i++, j++;
		else
			i = i - j + 1, j = 0;
	}
	return j == len2 ? i - j : -1;
}

```

方法3：我的这个方法竟然执行0ms,超过100%
```
int strStr(char * haystack, char * needle){
    int len2 = strlen(needle);
    if (!len2)
        return 0;
    int len1 = strlen(haystack);

    for (int i = 0; i <= len1 - len2; i++){
        if (haystack[i] == needle[0] && haystack[i + len2 - 1] == needle[len2 - 1]){
            int j;
            for (j = 1; j < len2; j++){
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == len2)
                return i;
        }
    }
    return -1;
}

```

方法4：大佬的KMP算法,4ms ~ 8ms
```
int *getNext(char *str){
    int len = strlen(str);
    int *next = (int*)malloc(sizeof(int) * len);
    next[0] = -1;
    int j = 0, k = -1;
    while (j < len - 1){
        if (k == -1 || str[j] == str[k]){
            if (str[++j] == str[++k])
                next[j] = next[k];
            else
                next[j] = k;
        }
        else
            k = next[k];
    }
    return next;
}
int strStr(char * haystack, char * needle){
    if (needle[0] == 0)
        return 0;
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    int i = 0, j = 0;
    int *next = getNext(needle);
    while (i < len1 && j < len2){
        if (j == -1 || haystack[i] == needle[j]){
            i++;
            j++;
        }
        else
            j = next[j];
    }
    return (j == len2) ? i - j : -1;
}

```




