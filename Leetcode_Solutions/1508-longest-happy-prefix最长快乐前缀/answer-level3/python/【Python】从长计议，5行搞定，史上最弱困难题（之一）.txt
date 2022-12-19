大概思路，就是『从长计议』。其它也就没啥了。

```python
class Solution:
    def longestPrefix(self, s: str) -> str:
        for i in range(1, len(s)):
            j = len(s) - i
            if s[:j] == s[i:]:
                return s[i:]
        return ''
```

> 执行用时 : `1524 ms`, 在所有 Python3 提交中击败了`100.00%`的用户
> 内存消耗 : `14.1 MB`, 在所有 Python3 提交中击败了`100.00%`的用户

当然，这个超过1秒的答案，还有很大优化空间。现在只是胜在提交的人少。