
### 代码

```c
char * convert(char * s, int numRows){
    int len = strlen(s);
    if(numRows == 1)
    {
        return s;
    }
    int** a = (int**)malloc(sizeof(int*)*1000);
    int i=0,j=0,n=0,m=0;
    while(1)
    {
        int* b = (int*)malloc(sizeof(int)*numRows);
        for(i=0;i<numRows;i++)
        {
            if(j==len)
            {
                b[i] = -1;
                continue;
            }
            b[i] = (int)s[j];
            j++;
        }
        a[n] = b;
        n++;
        if(j == len)
            break;
        m = numRows-2;
        while(m!=0)
        {
            int* c = (int*)malloc(sizeof(int)*numRows);
            for(i=0;i<numRows;i++)
            {
                if(j == len)
                {
                    c[i] = -1;
                    continue;
                }
                if(i == m)
                {
                    c[i] = (int)s[j];
                    m--;
                    j++;
                }
                else
                {
                    c[i] = -1;
                }
            }
            a[n] = c;
            n++;
            if(j == len)
                break;
        }
        if(j == len)
            break;
    }
    m = 0;
    for(i=0;i<numRows;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[j][i] != -1)
            {
                s[m] = a[j][i];
                m++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        free(a[i]);
    }
    free(a);
    return s;
}
```