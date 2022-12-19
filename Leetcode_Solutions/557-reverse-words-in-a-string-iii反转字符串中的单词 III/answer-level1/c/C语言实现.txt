

char * reverseWords(char * s){
    int start, end, i, j;
    i = 0;
    int curLen  = 0;
    char tmp;
    start = end = 0;
    if(s == NULL)
        return NULL;
    while(s[i] != '\0')
    {
        start = i;
        while((s[i] != ' ') && (s[i] != '\0'))
        {
            i++;
        }
        end = i -1;
        // i is space 
        //reverse start to end character now
        curLen = end - start + 1;
        //printf("current word len is %d %d %d\n", curLen, start ,s[end]);
        for( j = 0; j < (curLen/2); j++ )
        {
            tmp = s[end - j];
            s[end - j] = s[start + j];
            s[start + j] = tmp;
        }
        //printf("Break here %d %d %d\n", i, end);
        if(s[i] == '\0')
            break;
        i++;
    }
    return s;
}

```


char * reverseWords(char * s){
    int start, end, i, j;
    i = 0;
    int curLen  = 0;
    char tmp;
    start = end = 0;
    if(s == NULL)
        return NULL;
    while(s[i] != '\0')
    {
        start = i;
        while((s[i] != ' ') && (s[i] != '\0'))
        {
            i++;
        }
        end = i -1;
        // i is space 
        //reverse start to end character now
        curLen = end - start + 1;
        //printf("current word len is %d %d %d\n", curLen, start ,s[end]);
        for( j = 0; j < (curLen/2); j++ )
        {
            tmp = s[end - j];
            s[end - j] = s[start + j];
            s[start + j] = tmp;
        }
        //printf("Break here %d %d %d\n", i, end);
        if(s[i] == '\0')
            break;
        i++;
    }
    return s;
}


```
```


char * reverseWords(char * s){
    int start, end, i, j;
    i = 0;
    int curLen  = 0;
    char tmp;
    start = end = 0;
    if(s == NULL)
        return NULL;
    while(s[i] != '\0')
    {
        start = i;
        while((s[i] != ' ') && (s[i] != '\0'))
        {
            i++;
        }
        end = i -1;
        // i is space 
        //reverse start to end character now
        curLen = end - start + 1;
        //printf("current word len is %d %d %d\n", curLen, start ,s[end]);
        for( j = 0; j < (curLen/2); j++ )
        {
            tmp = s[end - j];
            s[end - j] = s[start + j];
            s[start + j] = tmp;
        }
        //printf("Break here %d %d %d\n", i, end);
        if(s[i] == '\0')
            break;
        i++;
    }
    return s;
}

```


char * reverseWords(char * s){
    int start, end, i, j;
    i = 0;
    int curLen  = 0;
    char tmp;
    start = end = 0;
    if(s == NULL)
        return NULL;
    while(s[i] != '\0')
    {
        start = i;
        while((s[i] != ' ') && (s[i] != '\0'))
        {
            i++;
        }
        end = i -1;
        // i is space 
        //reverse start to end character now
        curLen = end - start + 1;
        //printf("current word len is %d %d %d\n", curLen, start ,s[end]);
        for( j = 0; j < (curLen/2); j++ )
        {
            tmp = s[end - j];
            s[end - j] = s[start + j];
            s[start + j] = tmp;
        }
        //printf("Break here %d %d %d\n", i, end);
        if(s[i] == '\0')
            break;
        i++;
    }
    return s;
}


```

```
