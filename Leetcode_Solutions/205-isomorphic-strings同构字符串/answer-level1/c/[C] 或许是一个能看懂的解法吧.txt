
代码的核心是sc(s count) 和 tc(t count)这两个参数。用来统计每个位置上的字符是不是第一次出现

对于abc, edd这个例子

- 位置1: a, e, 两个字母都是第一次出现，因此sc和tc = 1
- 位置2: b, d，两个字母都是第一次出现，因此sc和tc = 2
- 位置3: c, d, 第一个字母第一次出现,sc =3, 第二个字母出现第二次，tc=2

此时 sc != tc, 因此返回false

```c
bool isIsomorphic(char * s, char * t){
    int ss[128] = {0};
    int tt[128] = {0};
    int sc =0, tc = 0;
    for (int i = 0; s[i] != '\0'; i++){
        if ( ss[s[i]] == 0 ) ss[s[i]] = ++sc;
        if ( tt[t[i]] == 0 ) tt[t[i]] = ++tc;
        if ( ss[s[i]] != tt[t[i]] ) return false;
    }
    return true;
}
```