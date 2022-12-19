```c
char * reverseOnlyLetters(char * S){
    char *save = S;
    char *start = S;
    char *end = S + strlen(S) - 1;
    char ch;
    while(start <= end)
    {
        if( isalpha(*start) && isalpha(*end) ) // 如果都是字符，交换他们
        {
            ch = *start;
            *start = *end;
            *end = ch;
            
            start++;
            end--;
        }
        else
        {
            if(!isalpha(*start))
                start++;
            if(!isalpha(*end))
                end--;
        }
    }
    return save;
}
```