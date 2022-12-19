### 解题思路
回文字符串的规律：若字母a出现在回文串中，那么a的个数要么为偶数，要么就为奇数。如果a的个数为奇数，那么回文串中其他字母个数必为偶数。（***即在回文串中最多仅有一个字母的的出现次数为奇数***）
建立数组来统计各个字母出现的次数。

### 代码

```python
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s)<2:
            return len(s)
        res = 0
        letters = [0] * 58 #注意此处，在ASCII表中，大写字母与小写字母并不是挨着的，中间还加有其他几个字符，所以数组大小不能为52。
        for i in s: #统计初始字符串中各个字母出现的次数
            letters[ord(i) - ord('A')] += 1
        flag = False# flag变量用于统计出现奇数次的字母
        for i in range(58):
            if letters[i] != 0:
                if letters[i] % 2 == 0:#出现偶数次，那么就把该字母的个数都加上
                    res += letters[i]
                else: #出现奇数次
                    if not flag: #flag为False，把该字母的个数都加上
                        res += letters[i]
                        flag = True
                    else: #flag为True，那么就应加上该字母的个数减一
                        res += letters[i] - 1
        return res
```