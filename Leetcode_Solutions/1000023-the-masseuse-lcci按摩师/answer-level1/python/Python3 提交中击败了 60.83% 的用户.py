### 解题思路
此处撰写解题思路
用pre_max标注为之前的最大值，特别要注意的是 最后一定要将pre_max 和最后的那位比较下
### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums :
            return 0
        if len(nums) == 1:
            return nums[0]
        pre_max = 0
        for i in range(1,len(nums)):
            nums[i] += pre_max
            pre_max = max(pre_max,nums[i-1])
        res = max(pre_max, nums[-1])
        return res
                
```