### 解题思路
    此处撰写解题思路

### 代码

```c
int balancedStringSplit(char * s)
{
    if (!s) {
        return 0;
    }
    int idx = 0;
    int ret = 0;
    int cnt = 0;
    while (s[idx] != '\0') {
        if (cnt == 0) {
            ret++;
        }
        if (s[idx] == 'L') {
            cnt++;
        } else {
            cnt--;
        }
        idx++;
    }
    return ret;
}
```