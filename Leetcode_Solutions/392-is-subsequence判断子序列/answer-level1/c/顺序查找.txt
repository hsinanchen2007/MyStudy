### 解题思路
空字符判断
顺序查找

### 代码

```c
bool isSubsequence(char * s, char * t){
    if(s[0] == '\0')
        return true;
    else if(t[0] == '\0')
        return false;
    int si = 0;
    int ti = 0;
    for(; t[ti] != '\0'; ti++){
        if(t[ti] == s[si])
            si++;
        if(s[si] == '\0')
            return true;
    }
    return false;
}
```