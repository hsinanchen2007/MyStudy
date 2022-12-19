


```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        rList = []
        if not len(nums):
            return rList
        for i in range(0,len(nums)-k+1):
            tmpList=nums[i:i+k]
            rList.append(max(tmpList))
        return rList

```