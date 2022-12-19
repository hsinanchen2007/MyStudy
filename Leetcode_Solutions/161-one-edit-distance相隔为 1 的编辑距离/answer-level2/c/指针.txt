思路长度大于2或者相等返回false, 否则循环一个字符串至末尾，判断不相等的字符串个数 ，注意遇到不相等时两个长度判断的处理

```
bool isOneEditDistance(char * s, char * t){
    if (strcmp(s, t) == 0) {
        return false;
    }
    int slen = strlen(s);
    int tlen = strlen(t);
    if (slen - tlen >= 2 || slen - tlen <= -2) {
        return false;
    }
    int flag = 0;
    while (*s != '\0') {
        if (*s != *t) {
            flag++;
            if(slen > tlen && flag == 1) {
                s++;
            } else if(slen < tlen && flag == 1) {
                t++;
            } else {
                s++;
                t++;
            }
            continue;
        }
        s++;
        t++;
    }
    if(flag > 1) {
        return false;
    }
    return true;
}
```
