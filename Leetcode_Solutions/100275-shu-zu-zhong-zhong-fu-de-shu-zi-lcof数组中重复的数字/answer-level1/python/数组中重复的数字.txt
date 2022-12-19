### 解题思路
利用python字典

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        nums.sort()
        RepeatDic={}
        for num in nums:
            if num not in RepeatDic:
                RepeatDic[num]=1
            else:
                return num
```