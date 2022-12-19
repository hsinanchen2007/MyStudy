C实现，20行以内
```
bool matchStar(int c, char * s, char * p);
bool isMatch(char * s, char * p){
    if (s[0] == '\0' && p[0] == '\0')
        return true;
    if (p[0] == '\0')
        return false;
    if (p[1] == '*')
        return matchStar(p[0], s, p+2);
    if (*s!='\0' && (p[0]=='.' || p[0]==*s))
        return isMatch(s+1,p+1);
    return false;
}
bool matchStar(int c, char * s, char * p){
    do {
        if (isMatch(s, p))
            return true;
    } while (*s != '\0' && (*s++ == c || c == '.'));   
    return false;    
}
```

正则表达式的实现是个经典问题，这个题目是正则表达式实现的的简化版本。
《代码之美》的第一章里，Golang的创始人Rob Pike对这个问题的“完全体”有个有个极其优雅的实现，值得仔细品味。
