int strStr(char * haystack, char * needle){
    
    int i = 0;
    int j = 0;
    
    if(!haystack) return -1;
    if(!strlen(needle)) return 0;
    
    
    for(i = 0; needle[j] != '\0' && haystack[i] != '\0'; i++)
    {
        if(needle[j] == haystack[i])
        {
            j++;
            if(j == (strlen(needle)))
            {
                return (i - strlen(needle) + 1);
            }
        }
        else
        {
            i = i - j;
            j = 0;
        }
    }
    
    if(needle[j] != '\0')
        return -1;
    return;
}

