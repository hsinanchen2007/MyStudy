### 解题思路
双指针
### 代码

```c
char * reverseVowels(char * s){
    char *ps = s, *pe = s + strlen(s) - 1;
    char temp;
    while (ps < pe)
    {
        if (*ps == 'a' || *ps == 'e' || *ps == 'i' || *ps == 'o' || *ps == 'u' ||
            *ps == 'A' || *ps == 'E' || *ps == 'I' || *ps == 'O' || *ps == 'U')
        {
            if (*pe == 'a' || *pe == 'e' || *pe == 'i' || *pe == 'o' || *pe == 'u' ||
                *pe == 'A' || *pe == 'E' || *pe == 'I' || *pe == 'O' || *pe == 'U')
            {
                temp = *ps;
                *ps = *pe;
                *pe = temp;
                ps++;
                pe--;
            }
            else pe--;
        }
        else if (*pe == 'a' || *pe == 'e' || *pe == 'i' || *pe == 'o' || *pe == 'u' ||
                 *pe == 'A' || *pe == 'E' || *pe == 'I' || *pe == 'O' || *pe == 'U') ps++;
        else
        {
            ps++;
            pe--;
        }
    }
    return s;
}
```