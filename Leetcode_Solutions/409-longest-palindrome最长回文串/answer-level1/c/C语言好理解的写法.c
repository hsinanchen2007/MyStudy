### 解题思路
偶数的字母数+大于2的奇数字母数-1 + （奇数的一个字母数）

### 代码

```c
int longestPalindrome(char * s)
{
    int i, j;
    int sum = 0;
    int n[127] = {0};
    int len = strlen(s);
    if (s == NULL ||len == 0) {
        return 0;
    }
    for (i = 0; i < len; i++) {
        n[s[i]]++;
    }
    for (i = 0; i < 127; i++) {
        if (n[i] % 2 == 0) {
            sum = sum + n[i];
        } else if (n[i] % 2 != 0 && n[i] > 2) {
            sum = sum + n[i] - 1;
        }
    }
    for (i = 0 ; i < 127; i++) {
        if (n[i] == 1 || (n[i] % 2 != 0)) {
            sum = sum + 1;
            break;
        } 
    }
    return sum;
}
```