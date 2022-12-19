### 解题思路
核心思想就是用哈希存储每个字符串的出现次数。
在使用时，为了使回文字符串尽量长，要用尽偶数个字符串，且奇数个字符串用到剩下1个。
最后看如果还剩单个字符，则挑选一个使用，且最大长度+1。

### 代码
```c
int longestPalindrome(char * s)
{
    int *alpha = (int *)malloc(sizeof(int) * 58);
    memset(alpha, 0, sizeof(int) * 58);
    int sLen = strlen(s);
    int maxLen = 0;
    int oddNum = 0;

    for (int i = 0; i < sLen; i++) {
        alpha[s[i] - 'A']++;
    }

    for (int i = 0; i < 58; i++) {
        if (alpha[i] != 0) {
            if ((alpha[i] % 2) == 0) {
                maxLen += alpha[i];
                alpha[i] = 0; // 偶数个数的字符全部用完
            } else {
                oddNum++;
                if (alpha[i] > 1) {
                    maxLen += alpha[i] - 1;
                    alpha[i] = 1; // 奇数个数的字符用到只剩1个
                }
            }
        }
    }

    if (oddNum != 0) { // 若还有单个的字符串，则可以挑选一个来用
        maxLen++;
    }

    return maxLen;
}
```