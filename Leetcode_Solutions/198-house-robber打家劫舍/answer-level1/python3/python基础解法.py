### 解题思路
动态规划最需要做的就是定义动态转移
f(k) = max(f(k-2) + A(k), f(k-1))

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        pre, cur = 0, 0
        for i in nums:
            pre, cur = cur, max(pre + i, cur)
        return cur
```