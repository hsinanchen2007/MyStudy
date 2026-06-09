### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def decompressRLElist(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        maxi=len(nums)/2
        numlist=[]
        for i in range(0,maxi):
            a=nums[2*i]
            b=nums[2*i+1]
            for k in range(0,a):
                numlist.append(b)
        return numlist

nums=[1,2,3,4]
solution=Solution()
print(solution.decompressRLElist(nums))


```