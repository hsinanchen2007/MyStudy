### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def twoSum(self, nums, target):
        lens = len(nums)
        for i in range(lens):
            rest = nums[i+1:]
            res = target-nums[i] #将剩余元素列出来
            if res in rest :
                return i,(rest.index(res))+i+1 
`'''第一次写，日后改进'''