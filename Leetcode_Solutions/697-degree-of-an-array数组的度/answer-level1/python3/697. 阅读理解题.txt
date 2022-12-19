### 解题思路
1. 用dict记录nums中每个元素出现的位置
2. 度为出现位置最多的，计算其len，得到数组的度
3. 找出出现次数最多的元素，计算 最后一个index-第一个index+1（subsequence的长度），min取出最小的，即为最短连续子数组

### 代码

```python3
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        nums_dict = {}

        # 用dict记录nums中每个元素出现的位置
        for idx, item in enumerate(nums):
            if item in nums_dict.keys():
                nums_dict[item].append(idx)
            else:
                nums_dict[item] = [idx]

        # 度为出现位置最多的，计算其len，得到数组的度
        degree = 0
        for i in nums_dict:
            degree = max(degree, len(nums_dict[i]))
        
        # 找出出现次数最多的元素，计算 最后一个index-第一个index+1（subsequence的长度），min取出最小的，即为最短连续子数组
        sub = len(nums)
        for i in nums_dict:
            if len(nums_dict[i]) == degree:
                sub = min(sub, nums_dict[i][-1]-nums_dict[i][0]+1)
        
        return sub
            
```