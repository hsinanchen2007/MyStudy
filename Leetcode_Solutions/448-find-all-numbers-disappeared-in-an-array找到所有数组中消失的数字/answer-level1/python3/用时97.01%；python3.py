### 解题思路
巧用set：利用set运算求出缺失的元素，返回即可。

### 代码

```python3
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]: 
        if nums == []:
            return []
        return list(set(range(1,len(nums)+1)) - set(nums))
```