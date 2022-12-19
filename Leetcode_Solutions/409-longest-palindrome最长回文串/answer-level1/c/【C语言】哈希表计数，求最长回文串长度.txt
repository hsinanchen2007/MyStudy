### 解题思路
哈希表计数
题目求的是最长回文串的长度
在回文串中，最多只有1个字符出现奇数次，其它字符都出现偶数次，这样才能首尾对称
最长回文串不止1个，把满足要求的字符进行首尾对称的排列组合，可得多个回文串，但是长度一定
最长回文串的长度等于（出现偶数次的字符的个数）之和+（出现奇数次的字符的个数-1）之和+flag
如果存在出现奇数次的字符，则可以把它放到中间，flag=1
如果不存在出现奇数次的字符，则flag=0
构造哈希映射：A-Z:0-25; a-z: 26-51

### 代码

```c

#define N 52
int longestPalindrome(char * s)
{
    if (s == NULL) {
        return NULL;
    }

    int len = strlen(s);
    int hash[N] = {0};

    int i = 0;
    while (s[i] != '\0') {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            hash[s[i] - 'A']++;
        } else {
            hash[s[i] - 'a' + 26]++;
        }
        i++;
    }

    int maxLen = 0;
    int hasOdd= 0;
    int j;
    for (j = 0; j < N; j++) {
        if (hash[j] & 0x1 == 1) {
            hasOdd = 1;
            maxLen += hash[j] - 1;
        } else {
            maxLen += hash[j];
        }
    }

    maxLen += hasOdd;
    
    return maxLen;
}
```