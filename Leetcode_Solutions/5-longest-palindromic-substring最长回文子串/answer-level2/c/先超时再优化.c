先超时，再试着自己优化立个flag
```
int isPalindrome(char *s, int i, int j)
{
    while(i <= j)
    {
        if(s[i] != s[j])
            return -1;
        i++;
        j--;
    }
    return 0;
}

char *longestPalindrome(char *s)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int recoder = 0;
    int left = 0;
    int right = 0;
    //char * longest = (char *)calloc()
    for(i = 0; i < strlen(s); i++)
    {
        for(j = i + 1; j < strlen(s); j++)
        {
            if(0 == isPalindrome(s, i, j))//检查i到j是否回文
            {
                if((j - i) > recoder)
                {
                    left = i;
                    right = j;
                    recoder = j - i;
                }
            }
        }
    }
    char *ret = (char *)calloc(recoder + 2, sizeof(char));
    for(i = 0; i < recoder + 1 ; i++)
    {
        ret[i] = s[left + i];
    }
    
    //printf("%s", ret);
    return ret;
}
```
