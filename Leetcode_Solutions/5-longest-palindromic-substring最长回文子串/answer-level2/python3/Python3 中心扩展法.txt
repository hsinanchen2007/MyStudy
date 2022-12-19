### 解题思路
中心扩展法，参考官方题解。
expansion 函数返回 left right 位置，为非难以理解的长度

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        maxlen = 0
        l, r = 0, 0
        def __expansion__(left, right):
            while left >= 0 and right < n and s[left] == s[right]:
                left -= 1
                right += 1
            return [left+1, right-1]
        for i in range(n):
            left1, right1 = __expansion__(i, i)
            left2, right2 = __expansion__(i, i+1)
            (left, right) = (left1, right1) if right1-left1>right2-left2 else (left2, right2)
            if right-left > maxlen:
                maxlen = right-left
                l, r = left, right
        return s[l:r+1]
```