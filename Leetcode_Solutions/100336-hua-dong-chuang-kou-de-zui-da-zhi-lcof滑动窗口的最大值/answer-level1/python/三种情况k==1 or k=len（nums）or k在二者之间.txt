### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if not nums:
            return []
        i=0
        j=k
        add=max(nums[i:j])
        max_value=[]
        if j==len(nums):
            max_value.append(add)
            return max_value
        if k==1:
            return nums
        while j<len(nums)+1:
            max_value.append(add)  
            i,j=i+1,j+1
            add=max(nums[i:j])
        return max_value




```