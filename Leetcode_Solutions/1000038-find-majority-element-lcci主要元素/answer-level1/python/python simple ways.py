### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if len(nums)==1: return nums[0]
        dict={}
        for i in nums:
            dict[i] = dict.get(i,0)+1
        maxdict = max(zip(dict.values(),dict.keys()))
        if maxdict[0]==1: return -1
        elif maxdict[0]!=1: return maxdict[1]
```