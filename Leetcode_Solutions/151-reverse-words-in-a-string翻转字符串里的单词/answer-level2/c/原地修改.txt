```
void revert(char *l, char *r)
{
    char c;
    while(l<r)
    {
        c = *l;
        *l = *r;
        *r = c;
        l++;
        r--;
    }    
}

char * reverseWords(char * s){
    int l;
    char *start = NULL;
    char *end = NULL;
    char c;
    if(s == NULL)
        return NULL;
    
    l = strlen(s);
    revert(s, s+l-1);
    start = s;
    while((c = *start) != '\0')
    {
        if(c == ' ')
        {
            start++;
            continue;
        }
        end = start;
        while(*end != ' ' && *end != '\0')
            end++;
        revert(start, end-1);
        start = end;
    }
    start = s;
    end = s;
    while(*end != '\0')
    {
        while(*end==' ')
        {
            end++;            
        }
        while(*end != ' ' && *end != '\0')
        {
            *start++ = *end++;
        }
        if(*end == ' ')
        {
            *start++ = *end++;
        }
    }
    if(start>s && *(start-1) == ' ')
    {
        start--;
    }
    *start = '\0';
    return s;
}
```
解二
```
void revert(char *l, char *r)
{
    char c;
    while(l<r)
    {
        c = *l;
        *l = *r;
        *r = c;
        l++;
        r--;
    }    
}
char * reverseWords(char * s){
    int l;
    char *start = NULL;
    char *end = NULL;
    char c;
    if(s == NULL)
        return NULL;
    
    l = strlen(s);
    revert(s, s+l-1);
    start = s;
    end = s;
    while((c = *end) != '\0')
    {
        if(c == ' ')
        {
            end++;
            continue;
        }
        while(*end != ' ' && *end != '\0')
            end++;
        revert(start, end-1);
        start = end-1;
        while(*start == ' ')
            start--;
        start += 2;         
    }
    if(start>s)
    {
        start--; 
    }
    *start = '\0';
    return s;
}
```
