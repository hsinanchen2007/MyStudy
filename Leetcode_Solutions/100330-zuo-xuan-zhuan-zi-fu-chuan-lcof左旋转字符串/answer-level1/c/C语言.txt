### 解题思路
暴力

### 代码

```c
/* 左旋转字符串操作 */
char *reverseLeftWords(char *s, int n)
{
    if ((s == NULL) || (n == 0)) {
        return s;
    }

    int len = strlen(s);
    int index = 0;
    char *ans = malloc(sizeof(char) * (len + 1));  //strlen 不算结束符
    memset(ans, 0x0, sizeof(char) * (len + 1));

    for (int i = n; i < len; i++) {
        ans[index++] = s[i];
    }

    for (int j = 0; j < n; j++) {
        ans[index++] = s[j];
    }

    ans[index] = '\0';

    return ans;
}
```