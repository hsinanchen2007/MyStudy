
1. 求出长度len
2. 按照子串可能重复的长度repeatLength做第一层遍历，子串的长度最长为len/2
3. 以repeatLength切割比较字符串，如果有不同，则继续下一个repeatLength, 如果每段都相同则返回true
4. 如果repeatLength遍历完了都没有返回，说明应该返回false

```
bool repeatedSubstringPattern(char * s){
    int repeatLength = 1;
    int len;
    int i;
    char curr;
    bool inc = false;

    len = strlen(s);
    if(len == 1) {
        return false;
    }

    for(repeatLength = 1; repeatLength <= len / 2; repeatLength++) {
        inc = false;
        if(len % repeatLength != 0) {
            continue;
        }
        for(i = 0; i < len - repeatLength; i += repeatLength ) {
            if(memcmp(&s[i], &s[i+repeatLength], repeatLength)) {
                inc = true;
                break;
            }
        }

        if(inc) {
            continue;
        }

        return true;
    }

    return false;
}
```
