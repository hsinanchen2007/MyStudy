遍历字符串，遇到空格的时候翻转前面的字符串.
时间复杂度O(n), 空间复杂度O(n)
```c
char * reverseWords(char * s){
    int len = strlen(s)+1;
    char *r = malloc(len);
    int index = 0;
    char *start = s;
    char *end;
    if(len == 1)
        return s;
    
    if(len == 2)
        return s;

    for(int i = 0; i < len; i++, s++)
    {
        if( (*s == ' ') || (*s == '\0') )
        {
            for (end = s-1; end >= start; end--)
            {
                r[index++] = *end;
            }
            r[index++] = (*s == ' ') ? ' ': '\0';
            start = s+1 ;
        }
    }
    return r;
}
```