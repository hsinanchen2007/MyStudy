### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def rob(self, nums):
        len_nums=len(nums)
        if len_nums==0:
            return 0
        if len_nums==1:
            return nums[0]
        ans=[0 for i in range(len_nums)]
        ans[0]=nums[0]
        ans[1]=max(nums[0],nums[1])
        for i in range(2,len_nums):
            ans[i]=max(nums[i]+ans[i-2],ans[i-1])
        return ans[len_nums-1]
        
```