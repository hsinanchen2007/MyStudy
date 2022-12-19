### 解题思路
位运算

### 代码
# 吸取某位大神的精彩片段
```python3
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        l = 1 << n
        res = []
        for i in range(l):
            cur = []
            for j in range(n):
                if i >> j & 1:
                    cur.append(nums[j])
            cur = sorted(cur)
            if cur not in res:
                res.append(cur)
        return res 
```