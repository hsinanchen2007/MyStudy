### 解题思路
递归处理。
1. 首先判断极端情况， 空的pattern， 那么s只能是空字符串。
2. 空的s 匹配，那么 pattern 一定是空，或者(a*)(b*)(c*) 之类的情况。
3. 都不为空. 关注pattern 的可能性。
    1) pattern 为字母，那么必须 p[pflag] == s[sflag] 才能成功。
    2）pattern 为 '.', 那么当前字母一定匹配成功。 source, pattern 都前置一位。
    3）pattern 为 星号 最复杂。也分为3种情况
       1> 完全不匹配， 即 a(X*) = a 的情况
       2> 匹配一次，   即 a(X*) = aX 的情况
       3> 匹配多次，   即 a(X*) = aXX 的情况

### 代码

```c
bool dtsMatch(char *s, char *p, int sflag, int pflag) {
    if (pflag < 0) {
        if (sflag < 0) {
            return true;
        }
        return false;
    }
    if (sflag < 0) {
        if (pflag == 0) {
            return false;
        }
        //pflag >= 1
        if (p[pflag] != '*') {
            return false;
        }
        // mX* =  m
        return dtsMatch(s, p, sflag, pflag - 2);
    }
    // sflag >= 0, pflag >= 0    
    if (s[sflag] == p[pflag]) {
        return dtsMatch(s, p, sflag - 1, pflag - 1);
    }
    if (p[pflag] == '.') {
        return dtsMatch(s, p, sflag - 1, pflag - 1);
    }
    if (p[pflag] == '*') {
        //match zero
        if (dtsMatch(s, p, sflag, pflag - 2)) {
            return true;
        }
        // must match 1 or more
        if (p[pflag - 1] == '.' || p[pflag - 1] == s[sflag]) {
            // match 1
            if (dtsMatch(s, p, sflag - 1, pflag - 2)) {
                return true ;
            }
            // match more
            return dtsMatch(s, p, sflag - 1, pflag);
        }
        return false;        
    }
    return false;
    
}
bool isMatch(char * s, char * p) {
    int slen = strlen(s);
    int plen = strlen(p);
    //printf("dtsmatch %d,%d\n", slen,plen);
    return dtsMatch(s, p, slen - 1, plen - 1);
}
```