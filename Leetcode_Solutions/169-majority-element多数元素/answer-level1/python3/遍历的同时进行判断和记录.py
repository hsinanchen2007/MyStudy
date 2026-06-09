### 解题思路
遍历的同时进行判断和记录

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        val = nums[0]
        n = 0
        d = {}
        while nums:
            t = nums.pop()
            d.setdefault(t,0)
            d[t] += 1
            if d[t] > n:
                n = d[t]
                v = t
        return v
```