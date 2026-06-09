### 解题思路
统计每个数字出现的次数并存入字典，再去找满足情况的最长组合长度

### 代码

```python3
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        countdict = {}
        for num in nums:
            if countdict.get(num) is None:
                countdict[num] = 1
            else:
                countdict[num] = countdict[num] + 1
        ret = 0
        for num in nums:
            if num+1 in countdict.keys():
                ret = max(countdict[num]+countdict[num+1],ret)
        return ret
        
```