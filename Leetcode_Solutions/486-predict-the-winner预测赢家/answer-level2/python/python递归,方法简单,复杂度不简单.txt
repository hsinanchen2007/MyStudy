### 解题思路
看到最多20个数就无脑递归了

### 代码

```python
class Solution(object):
    def PredictTheWinner(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        #一共只有20个数,考虑递归
        def getmax(nums):
            if len(nums)<2:
                return nums[0]
    
            if len(nums)==2:
                return max(nums)
            else:
                return max(nums[0]+sum(nums[1:])-getmax(nums[1:]),nums[-1]+sum(nums[:-1])-getmax(nums[:-1]))
        canget=getmax(nums)
        if canget>=sum(nums)*1.0/2:
            return True
        else:
            return False
```