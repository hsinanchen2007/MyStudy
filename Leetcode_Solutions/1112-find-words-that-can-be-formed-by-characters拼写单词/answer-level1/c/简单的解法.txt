有些费内存

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    char **p = NULL;
    char *q = NULL;
    char *m = NULL;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int k = 0;
    int sum = 0;
    int total = 0;
    b = wordsSize;
    p = (char**)malloc(1000);
    q = (char*)malloc(100);
    m = (char*)malloc(100);
    memset(p,0x00,1000);
    memset(q,0x00,100);
    p = words;
    q = chars;
    int i  = 0;
    d = strlen(q);
    while(   i < b )
    {
        c= 0;
        sum = 0;
        c = strlen (*p);
        memset(m,0x00,100);
        strcpy(m,q);
        for (int j = 0; j<c;j++)
        {
            int k = 0;
            do
            {
                if((*p)[j] == m[k])
                {
                    sum++;
                   m[k] = 0;
                    break;
                }
                k++;
            }
            while(k < d );

        }
        if( sum == c)
        {
            total = total + sum;
        }
        p++;
        i++;
    }
    return total;
}
```