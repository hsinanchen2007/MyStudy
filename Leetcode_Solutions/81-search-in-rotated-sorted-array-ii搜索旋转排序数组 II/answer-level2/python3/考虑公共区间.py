### 解题思路
此处撰写解题思路：
小弟有个想法：鉴于nums翻转前后的高度对称性，可以考虑将nums与nums.sort()做一个匹配，寻找公共区间，当然公共区间存在多个，如果target落在公共区间内，问题得解

### 代码

```python
import math
class Solution(object):
    def search(self, nums, target):
        leng=len(nums)
        numscopy=nums[:]
        numscopy.sort()
        if(numscopy==nums and target in nums):
            return True
        elif(numscopy!=nums and target in nums):
            anchora=self.findequalsegment(nums,numscopy)+1
            anchorb=self.findequalsegment(numscopy,nums)+1
           
            if(target in numscopy[:anchora] or  nums[:anchorb]):
                return True
        return False
    def findequalsegment(self,nums,numscopy):
        count=0
        flag=False
        for j in range(len(numscopy)-1):
            if(nums[-1]==numscopy[j] and nums[-1]!=numscopy[j+1]):
                count=j
        return count
        
            

``