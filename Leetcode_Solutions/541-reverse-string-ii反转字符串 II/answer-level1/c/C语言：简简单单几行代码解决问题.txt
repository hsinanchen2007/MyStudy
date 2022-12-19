

```
char * reverseStr(char * s, int k){
    int len = strlen(s);
    for (int i = 0; i < len; i+=k*2) { 
        if (i+k <= len) overturn(s, i, i+k);
        else            overturn(s, i, len);
    }
    return s;
}

void overturn(char * str, int fast, int last)
{
    int i = fast;
    int j = last - 1;
    while (i < j) {
        str[i]   ^= str[j];
        str[j]   ^= str[i];
        str[i++] ^= str[j--];
    }
}
```
