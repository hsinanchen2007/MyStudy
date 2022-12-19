### 解题思路
(i+2) < strlen(s)少了判断条件会踩内存，所以一定要加边界校验条件
如果是双数，则s[i+3]==#,否则s[i]为单数。最后2位如果是数字，一定是a-i中的。
### 代码

```c
char * freqAlphabets(char * s){
    char *sTemp = (char *)calloc(strlen(s), sizeof(char)+1); 
    int i = 0;
    int j = 0;
    for(i = 0;i < strlen(s);) {
        if((i+2) < strlen(s) && s[i + 2] == '#') {
            sTemp[j] = ((s[i] - '0') * 10 + s[i + 1] - '0') + 96;
            i = i + 3;
        } else {
            sTemp[j] = (s[i] - '0') + 96;
            i++;
        }
        j++;
    }
    for(i = 0; i <= strlen(sTemp); i++) {
        s[i] = sTemp[i];
    }

    return sTemp;
}

```