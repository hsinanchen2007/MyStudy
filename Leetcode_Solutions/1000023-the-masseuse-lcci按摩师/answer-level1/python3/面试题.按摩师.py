### 解题思路
- 动态规划（与台阶问题不同，台阶问题是站在台阶上，考虑前一步有两种可能性）
- 本题是在状态n有accept,reject两种选择，而不是一种；
- reject,accept = max(reject,accept),reject+num
- 当前reject的收益是以前accept或reject两种选择中的最大值，当前accept是以前reject的收益+现在的收益

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums:return 0
        reject,accept = 0,0
        for i,num in enumerate(nums):
           reject,accept = max(reject,accept),reject+num
        return max(reject,accept)
```