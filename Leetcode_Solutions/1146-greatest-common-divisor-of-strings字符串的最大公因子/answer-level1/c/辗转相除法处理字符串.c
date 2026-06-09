### 解题思路
1、辗转相除法处理长度
2、根据结果，遍历处理字串

### 代码

```c
char * gcdOfStrings(char * str1, char * str2)
{
    int i, j, k, len1, len2, sub;
    char *p;
    char str[strlen(str2)], nostr[]={'\0'};

    p = nostr;
    len1 = strlen(str1);
    len2 = strlen(str2);

    if ((len1 % len2) == 0)
    {
        for(i=0; i<(len1/len2); i++)
        {
            for(j=0;j<len2-1;j++)
            {
                if (str1[i*len2+j] != str2[j])
                    break;
            }
            if (j<len2-1)
                break;
        }
        if (i == (len1 / len2))
            return str2;
    }
    else
    {
        sub = (len1 % len2);
        while(sub)
        {
            len1 = len2;
            len2 = sub;
            sub = (len1 % len2);
            if (sub == 1)
                return p;
        }
        sub = len2;     //长度的最大公约数；
        len2 = strlen(str2);
        len1 = strlen(str1);
        for(i=0; i<sub; i++)
        {
            str[i] = str2[i];
        }
        for (i=0; i<len2/sub; i++)
        {
            for (j=0; j<sub; j++)
                if (str[j] != str2[i*sub + j])
                    return p;
        }
        for (k=0; k<len1/sub; k++)
        {
            for (j=0; j<sub; j++)
                if (str[j] != str1[k*sub + j])
                    return p;
        }
        if ((i == (len2 / sub)) && (k == (len1 / sub)))
        {
            str[sub] = '\0';
            p = str;
            return p;
        }
        else    
            return p;
    }
    return p;
}
```