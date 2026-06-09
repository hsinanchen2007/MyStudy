# 递归，前后两部分都为扰乱字符串
```
bool isSplitScramble(char * s1, char * s2, int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum = sum + s1[i] - s2[i];
    }
    if (sum != 0) {
        return false;
    }
    if (len == 1) {
        return true;
    }
    for (int i = 1; i < len; i++) {
        if (isSplitScramble(s1, s2, i) && isSplitScramble(s1 + i, s2 + i, len - i)) {
            return true;
        }
        if (isSplitScramble(s1, s2 + len - i, i) && isSplitScramble(s1 + i, s2, len - i)) {
            return true;
        }
    }
    return false;
}
bool isScramble(char * s1, char * s2){
    int len = strlen(s1);
    if (len != strlen(s2)) {
        return false;
    }
    return isSplitScramble(s1, s2, len);
}
```
