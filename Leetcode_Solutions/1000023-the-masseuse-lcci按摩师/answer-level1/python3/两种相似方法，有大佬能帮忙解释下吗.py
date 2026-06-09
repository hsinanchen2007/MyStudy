
### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        dp0, dp1 = 0, 0
        for num in nums:
            dp0, dp1 = max(dp0, dp1), dp0 + num
        return max(dp0, dp1)
```

```python3
class _Solution:
    def massage(self, nums: List[int]) -> int:
        dp0, dp1 = 0, 0
        for num in nums:
            dp0, dp1 = dp1, max(dp0+num, dp1)
        return max(dp0, dp1)
```

我觉得好神奇啊，有大佬能帮我解释下这两种方法的差别吗？
第一种是官方题解格式稍微改一下，第二种是其他大佬的