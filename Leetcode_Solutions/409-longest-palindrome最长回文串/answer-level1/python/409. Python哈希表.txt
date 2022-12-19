### 解题思路
这里只需要记录出现奇数词和出现偶数次的字符，只有一个字符能够出现奇数次。

### 代码

```python
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        if s == '':
            return 0
        ch_dict = {}
        for ch in s:
            ch_dict[ch] = ch_dict.get(ch, 0) + 1
        res = 0
        flag = 0
        for ch in ch_dict:
            if ch_dict[ch] % 2 == 0:
                res += ch_dict[ch]
            else:
                res += ch_dict[ch] - 1
                flag = 1
        return res + int(flag)
```