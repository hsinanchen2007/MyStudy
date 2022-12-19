**每个2k个中翻转前k个**
```c
void reverse(char *s, int low, int high)
{
    int mid = (high - low + 1) / 2, i;
    char t;
    for(i = 0; i < mid; i++){
        t = s[low + i];
        s[low + i] = s[high - i];
        s[high - i] = t;
    }
}

char * reverseStr(char * s, int k)
{
    int len = strlen(s);
    int i, j;

    for(i = 0; i < len; i += 2 * k){
        j = fmin(i + k - 1, len - 1);
        reverse(s, i, j);
    }
    return s;
}
```