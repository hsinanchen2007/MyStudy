### 解题思路
取两个栈，sStack与tStack，进行如下操作：
（1）对于S字符串而言，当遇到字母时，将其入sStack，如果遇到#时出栈一个字符，注意栈为空时的操作；
（2）对于T字符串而言，进行与S字符串同样的操作即可；
最后添加'\0'结束符，比较字符串是否相等；
![123.PNG](https://pic.leetcode-cn.com/bd4076bfc64cbce90ac468e31445e9aad84d7242bc7384df51a963b27c411fe2-123.PNG)


### 代码

```c
bool backspaceCompare(char * S, char * T) {
    char *sStack = NULL;
    char *tStack = NULL;
    int slen = strlen(S);
    int tlen = strlen(T);
    sStack = (char *)malloc(sizeof(char) * (slen + 1));
    memset(sStack, '\0', sizeof(char) * (slen + 1));
    tStack = (char *)malloc(sizeof(char) * (tlen + 1));
    memset(tStack, '\0', sizeof(char) * (tlen + 1));
    int i, tops, topt;
    i = tops = topt = 0;
    while (i < slen || i < tlen) {
        if (i < slen) {
            if (S[i] != '#') {
                sStack[tops++] = S[i];
            } else {
                if (tops <= 0) {
                    // do nothing
                    tops = 0;
                } else {
                    tops--;
                }
            }
        }
        if (i < tlen) {
            if (T[i] != '#') {
                tStack[topt++] = T[i];
            } else {
                if (topt <= 0) {
                    // do nothing
                    topt = 0;
                } else {
                    topt--;
                }
            }
        }
        i++;
    }
    sStack[tops] = '\0';
    tStack[topt] = '\0';
    if (strcmp(sStack, tStack) == 0) {
        return true;
    }
    return false;
}
```