```C 
int strStr(char * haystack, char * needle)
{
    if (needle == NULL || (strlen(needle) == 0))
        return 0;

    int i = 0 ;
    int j = 0 ;
    int needle_length = strlen(needle);
    int haystack_length = strlen(haystack);

    if (needle_length > haystack_length)
        return -1;
    
    for (i = 0 ; i <= (haystack_length - needle_length); i++)
    {
        if (haystack[i] == *needle)
        {
            for (j = 0 ; j < needle_length; j++)
            {
                if (haystack[i +j] != needle[j])
                    break;
            }
            if (j == (needle_length))
                return i;
        }
    }
    
    return -1;
}
```
