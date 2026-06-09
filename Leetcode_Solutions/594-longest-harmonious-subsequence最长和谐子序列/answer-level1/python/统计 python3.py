### 解题思路
统计每个数字出现的频率，遍历所有key，如果key + 1也在统计中，将他们出现的次数相加，最后取最大即可

### 代码

```python3
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        c = collections.Counter(nums)
        res = 0
        for i in c.keys():
            if i+1 in c:
                res = max(res,c[i] + c[i+1])
        return res
```