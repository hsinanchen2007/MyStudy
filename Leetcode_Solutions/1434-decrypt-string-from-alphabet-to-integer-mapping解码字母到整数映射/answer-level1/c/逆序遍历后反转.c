```c
void reverseString2(char* s, int sSize)
{
    int i = 0;
    int j = sSize - 1;
    int tmp;
    while(i < j)
    {
        tmp  = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}

char* freqAlphabets(char* s)
{
    char  num = 0;
    int   len = strlen(s);
    char* t   = s + len - 1;

    char* ret = calloc(len + 1, sizeof(char));

    int   idx = 0;

    for(; t >= s; t--)
    {
        if(*t == '#')
        {
            num = (*(t - 2) - 0x30) * 10 + (*(t - 1) - 0x30) + 96;
            t   = t - 2;
        }
        else
        {
            num = *t + 0x30;
        }
        ret[idx++] = num;
    }
    reverseString2(ret, strlen(ret));
    return ret;
}
```