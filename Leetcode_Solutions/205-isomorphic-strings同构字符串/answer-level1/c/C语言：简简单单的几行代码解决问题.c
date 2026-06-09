方法一：每次查找当前字符第一次出现的索引值
```
bool isIsomorphic(char * s, char * t){
    int i = 0;
    while (s[i]) {
        if (find_fir(s,i) != find_fir(t,i)) return false;
        ++i;
    }
    return true;
}
int find_fir(char *s, int end)
{
    int i = 0;
    while (i < end) {
        if (s[i] == s[end]) return i;
        ++i;
    }
    return end;
}
```
方法二：用空间换时间，不断累加索引值
```
bool isIsomorphic(char * s, char * t){        
    int a[128]={0};
    int b[128]={0};
    for(int i = 0; s[i]; ++i) {
        a[s[i]] += i+1;
        b[t[i]] += i+1;
        if(a[s[i]] != b[t[i]]) return false;
    }
    return true;
}
```



