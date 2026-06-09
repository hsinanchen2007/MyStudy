### 解题思路
创建每一位运动员成绩相对分数的排名(列表索引值)
按照原运动员位置,置放所排名次


### 代码

```python3
class Solution:
    def findRelativeRanks(self, nums: List[int]) -> List[str]:
        nus = sorted(nums)[::-1]
        nums = [str(nus.index(i)+1) for i in nums]
        n = len(nums)
        if n>0:
            nums[nums.index('1')] =  "Gold Medal"
        if n>1:    
            nums[nums.index('2')] =  "Silver Medal"
        if n>2:    
            nums[nums.index('3')] =  "Bronze Medal"
        return nums
```