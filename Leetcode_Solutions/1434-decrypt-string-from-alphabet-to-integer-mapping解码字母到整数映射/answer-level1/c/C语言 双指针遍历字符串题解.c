### 代码

```c
char * freqAlphabets(char * s){
    char* p;
    char* q;
    int x=0;
    p = q =s;
    while(1)
    {
        if(*p=='1'|| *p=='2')
        {
            p++;
            if(*p=='\0')
            {
                p--;
                *q = (int)*p + 48;
                q++;
                *q = '\0';
                break;  
            }
            p++;
            if(*p=='#')
            {
                p--;
                x = (int)*p-48;
                p--;
                x += ((int)*p-48) * 10;
                *q = x+96;
                q++;
                p +=2;
            }
            else
            {
                p = p-2;
                *q = (int)*p + 48;
                q++;
            }
        }
        else if(*p=='\0')
        {
            *q = '\0';
            break;
        }
        else
        {
            *q = (int)*p + 48;
            q++;
        }
        p++;
    }
    return s;
}
```