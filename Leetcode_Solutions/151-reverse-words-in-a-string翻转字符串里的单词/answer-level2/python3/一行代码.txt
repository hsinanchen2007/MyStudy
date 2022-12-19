## 思路

人狠话不多。

## 代码

```python
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.strip().split()[::-1])
```

***复杂度分析***
- 时间复杂度：$O(N)$
- 空间复杂度：由于需要转化为数组进行操作，因此空间复杂度为 $O(N)$

更多题解可以访问我的LeetCode题解仓库：https://github.com/azl397985856/leetcode  。 目前已经接近30K star啦。


