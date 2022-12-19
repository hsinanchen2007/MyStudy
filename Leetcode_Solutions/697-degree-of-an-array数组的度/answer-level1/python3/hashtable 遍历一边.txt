### 解题思路
哈希表遍历一边，记录t[i][0]=次数，t[i][1]=第一次出现位置，t[i][2]=最后一次出现位置

### 代码

```python3
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        maxCount = 0
        counts = {}

        for i in range(len(nums)):
            if nums[i] in counts:
                t = counts[nums[i]]
                t[0] = t[0] + 1
                t[2] = i
                counts[nums[i]] = t
            else:
                t = [0] * 3
                t[0] = 1
                t[1] = i
                t[2] = i
                counts[nums[i]] = t
            maxCount = max(maxCount, counts[nums[i]][0])
        
        minLengh = float("inf")
        for _, v in counts.items():
            if v[0] == maxCount:
                lenth = v[2] - v[1]
                minLengh = min(minLengh, lenth)
        
        return minLengh + 1 

        
```