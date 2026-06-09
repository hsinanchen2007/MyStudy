```
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mid = len(nums)//2
        nums_sorted = sorted(nums)
        head,tail = 0,0
    
        while tail < len(nums_sorted):
            if nums_sorted[tail] == nums_sorted[head]:
                if tail - head >= mid:
                    return nums_sorted[head]
                tail +=1
            else:
                head = tail
```
