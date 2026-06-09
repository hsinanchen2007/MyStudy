### 解题思路
单纯的数组统计

### 代码

```python3
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        res = []
        dic = collections.Counter(nums)
        for key,value in dic.items():
            if value == 2:
                res.append(key)
        
        for i in range(len(nums)):
            if (i+1) not in nums:
                res.append(i+1)
        
        return res
```