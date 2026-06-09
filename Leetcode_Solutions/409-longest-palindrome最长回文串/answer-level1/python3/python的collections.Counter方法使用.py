### 解题思路
用python的collections.Counter统计字符出现次数，统计奇数偶数次数，偶数直接加次数，奇数加次数减一，最后设置一个flag判定是否存在奇数的情况。
### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        odd = 0
        even = 0
        flag = 0
        if s == '':
            return odd
        c = collections.Counter(s)
        for i in c:
            if (c[i] % 2) == 0:
                even += c[i]
            else:
                odd += (c[i]-1)
                flag = 1
        if flag  == 1:
            return even+odd+1
        else:
            return even




```