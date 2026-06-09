### 解题思路
构造新字符串，每次增加复制一次字符串A，判断B是否为A的字串，直到多复制2次A之后如果B仍然不是A的子串，那么返回-1

### 代码

```c
int repeatedStringMatch(char * A, char * B){
    int lenA = strlen(A);
    int lenB = strlen(B);
    int max = lenB / lenA + 2;
    char newStr[max * lenA + 1];
    memset(newStr, 0, sizeof(newStr));
    for (int i = 0; i < max; i++) {
        strcat(newStr, A);
        char *tmp = NULL;
        if (strlen(newStr) >= strlen(B)) {
            tmp = strstr(newStr, B);
        }
        if (tmp == NULL) {
            continue;
        } else {
            return i + 1;
        }
    }
    return -1;
}
```