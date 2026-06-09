### 解题思路
此处撰写解题思路
重点在于扣数字转字符串的细节！
### 代码

```c
char* compressString(char* S)
{
    int slen=0, zSlen, i, j, k=0;
    char *p;
    int count;
    char a[10];

    while(*(S+i))
    {
        slen++;
        i++;
    }
    if (slen < 2)
        return S;
    char zS[slen*2];
    j = 0;
    i = 1;
    count = 1;
    while(*(S+i))
    {
        if (S[i-1] == S[i])
        {
            count++;
            i++;
        }
        else
        {
            zS[j] = S[i-1];
            sprintf(a, "%d", count);
            a[strlen(a)] = '\0';
            for(k=0;k<strlen(a);k++)
                zS[j+1+k] = a[k];
            j = j + strlen(a)+1;
            count = 1;
            i++;
        }
        if(i >= slen)
        {
            zS[j] = S[i-1];
            sprintf(a, "%d", count);
            a[strlen(a)] = '\0';
            for(k=0;k<strlen(a);k++)
                zS[j+1+k] = a[k];
            j = j+strlen(a)+1;
        }
    }
    zSlen = j-1;
    zS[j] = '\0';
    p = zS;
    if (zSlen+1 < slen)
        return p;
    else
        return S;
}
```