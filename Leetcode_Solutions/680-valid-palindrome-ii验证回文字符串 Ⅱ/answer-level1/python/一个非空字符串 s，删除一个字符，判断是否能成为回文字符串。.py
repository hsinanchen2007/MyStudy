### 解题思路
两个指针l,r分别是从前开始和从后开始。
如果s[l] != s[r]的时候，我们需要删除掉一个字符，就有两种情况。一种是删除左边的，一种是删除右边的。

### 代码

```python3
class Solution:
    def validPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while l < r:
            if s[l] != s[r]:
                case1, case2 = s[l:r], s[l+1:r+1] #切片左闭右开
                return case1 == case1[::-1] or case2 == case2[::-1]
            l, r = l+1, r-1
        return True
```