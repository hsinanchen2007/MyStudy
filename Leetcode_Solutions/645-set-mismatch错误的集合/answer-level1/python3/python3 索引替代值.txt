### 解题思路
【一个很重要的解题思路】
用索引替代值
已经用了很多次啦

### 代码

```python3
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        ans = [0] * len(nums)
        for i in nums:
            ans[i-1] += 1
        return [ans.index(2)+1, ans.index(0)+1]
```