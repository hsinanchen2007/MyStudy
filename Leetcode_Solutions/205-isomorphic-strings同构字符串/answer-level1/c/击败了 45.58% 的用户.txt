### 解题思路

### 代码

```c
bool isIsomorphic(char * s, char * t){
    char ss[128] = "\0";
    char st[128] = "\0";
    int i = 0;
    int cs = 0, ct = 0;
    while (s[i] != '\0' && t[i] != '\0')
    {
        if (ss[s[i]] == 0) ss[s[i]] = ++cs;
        if (st[t[i]] == 0) st[t[i]] = ++ct;
        if (ss[s[i]] != st[t[i]]) return false;
        i++;
    }
    return true;
}
```