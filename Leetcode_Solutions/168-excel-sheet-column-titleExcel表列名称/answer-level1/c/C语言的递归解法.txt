我就是懒的写两个循环

```c
void cTitle(int n, int *i, char *s)
{
    if (n == 0)  return;
    else
    {
        cTitle( --n / 26, i, s);
        s[ (*i)++ ] = (n) % 26 + 'A';
    }
}

char *convertToTitle(int n)
{
    int i = 0;
    char *s = ( char * )malloc(sizeof(char)*20);
    ctt(n, &i, s);
    s[ i ] = '\0';
    return s;
}
```

