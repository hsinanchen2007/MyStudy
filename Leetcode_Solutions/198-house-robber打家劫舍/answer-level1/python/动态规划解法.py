### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        temp = [nums[0] , nums[1]]
        leng = len(nums)
        for i in range(2 , leng):
            temp.append(temp[i - 2] + nums[i])
            if i - 3 >= 0 and temp[i - 3] + nums[i] > temp[-1]:
                temp[-1] = temp[i - 3] + nums[i]
                
        return max(temp[-1] , temp[-2])

```