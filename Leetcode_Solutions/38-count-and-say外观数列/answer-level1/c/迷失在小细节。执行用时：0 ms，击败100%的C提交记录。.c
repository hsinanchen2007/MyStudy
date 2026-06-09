如下：


```
char s[5000] = {0};
char s1[5000] = {0};

char * countAndSay(int n){

    int i = 0;
    int j = 0;
    int k = 0;
    char count;

    memset(s, 0, 5000);
    memset(s1, 0, 5000);
    
    s[0] = '1';
    
    while(i < n-1)
    {
        j = 0;
        k = 0;
        count = 1;
        int len = strlen(s);
        while(j < len)
        {
            if(s[j] == s[j+1])
            {
                count++;
            }
            else
            {
                s1[k] = count + '0';
                s1[k+1] = s[j];
                count = 1;
                k = k+2;
            }
            j++;
        }
        s1[k] = '\0';
        memcpy(s, s1, strlen(s1));
        i++;
    }
    
    return s;
}
```

