### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 1
        maj = nums[0]
        for i in range(1,len(nums)):
            if maj==nums[i]:
                count+=1
            else:
                count-=1
                if count==0:
                    maj=nums[i]
                    count=1
        return maj
```