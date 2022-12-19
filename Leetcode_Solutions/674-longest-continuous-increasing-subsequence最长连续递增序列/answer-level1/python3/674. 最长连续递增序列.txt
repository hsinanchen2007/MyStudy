### 解题思路
此处撰写解题思路
从第一个元素开始循环，每次遇到比上一个大的则临时长度+1，如果临时长度大于最大长度则吧长度给最大值，如果当前小余上一个则临时长度重新从1开始
### 代码

```python3
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        maxLen   = 1
        tmpLen   = 1

        if(len(nums) == 0):
            return 0
        for i in range(1, len(nums)):    
            if nums[i] > nums[i-1]:
                tmpLen =  tmpLen + 1
                if tmpLen > maxLen:
                    maxLen = tmpLen
            else:
                tmpLen = 1
        return maxLen


```