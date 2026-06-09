可以将给定字符串反转，从而成为一个最长子串问题。

在记录最长子串时，由于$aacdecaa$翻转过来后会判定$aac$成为最长回文串，所以在记录时要首先判断是不是回文串。

整道题目的代码如下：

```python
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        s2 = s[::-1]
        length = len(s)
        res_list = [[0 for j in range(length + 1)] for i in range(length + 1)]
        res = 0
        res_s = ""

        for i in range(1, length + 1):
            for j in range(1, length + 1):
                if s[i - 1] == s2[j - 1]:
                    res_list[i][j] = res_list[i-1][j-1] + 1
                    if res_list[i][j] > res:
                        temp_s = s[i-res_list[i][j]:i]
                        if temp_s == temp_s[::-1]:
                            res = res_list[i][j]
                            res_s = temp_s

        return res_s
```

