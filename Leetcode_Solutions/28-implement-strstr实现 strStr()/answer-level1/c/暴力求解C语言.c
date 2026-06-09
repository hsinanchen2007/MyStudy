
```
   int cmp(char * str1, char * str2, int lenth1)
    {
        int i = 0;
        while(i<lenth1)
        {
            if(str1[i] != str2[i])
                return -1;
            i++;
        }
        
        return 1;
    }
int strStr(char * haystack, char * needle){
    
    if(NULL == needle)
        return 0;
    if((NULL !=needle) && (0 == strlen(needle)))
        return 0;
    if(NULL == haystack)
        return 0 ;
    int lenth1 = strlen(haystack);
    int lenth2 = strlen(needle);
    char *tmp = (char *)calloc(lenth2, sizeof(char));    
 
    for(int i=0;i<lenth1-lenth2+1;i++)
    {
        memcpy(tmp, &haystack[i], lenth2);
        if(1 == cmp(tmp, needle, lenth2))
            return i;
    }
    free(tmp);
    return -1;

}
```
