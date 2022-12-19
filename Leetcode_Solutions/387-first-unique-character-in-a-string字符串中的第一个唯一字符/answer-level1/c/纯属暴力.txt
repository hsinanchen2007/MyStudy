### 解题思路
简单直接

### 代码

```c
int firstUniqChar(char * s)
{
    if (s == NULL || strlen(s) == 0) {
        return -1;
    }
    if (strlen(s) == 1) {
        return 0;
    }
    int sum;
    int rem = strlen(s);
    for (int i = 0; i < rem; i++) {
        sum = 0;
        for (int j = 0; j < rem; j++) {
            if (s[i] == s[j] && i != j) {
                sum++;
                break;
            }
        }
        if (sum == 0) {
            return i;
        }
    }
    return -1;
}
```