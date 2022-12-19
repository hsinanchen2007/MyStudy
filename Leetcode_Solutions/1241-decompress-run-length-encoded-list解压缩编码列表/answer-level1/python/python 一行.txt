代码
```
class Solution(object):
    def decompressRLElist(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        return reduce(lambda x,y:x+y,[[nums[i+1]]*nums[i] for i in range(0,len(nums),2)])
```
