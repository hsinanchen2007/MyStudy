
#### 效率：
> Runtime: 16 ms, faster than 94.29% of Python online submissions for Find the Difference.
> Memory Usage: 11.9 MB, less than 9.76% of Python online submissions for Find the Difference.
#### 复杂度分析：
 - 时间复杂度: $O(N)$
 - 空间复杂度: $O(1)$
#### 代码：
```Python
class Solution(object):
    def findTheDifference(self, s: str, t: str) -> str:
        n = 0
        for c in s:
            n ^= ord(c)
        for c in t:
            n ^= ord(c)
        return ascii(n)
```