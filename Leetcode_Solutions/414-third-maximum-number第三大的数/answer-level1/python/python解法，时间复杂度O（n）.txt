
```python []
class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 
        first = nums[0]
        second = float('-inf')
        third = float('-inf')
        for num in nums:
            if num > first:
                third = second
                second = first
                first = num
            elif num == first:
                continue
            elif num > second:
                third = second
                second = num
            elif num == second:
                continue
            elif num > third:
                third = num
            elif num <= third:
                continue
        # print(first,second,third)
        if third == float('-inf'): # third没有更新时
            return first
        return third      
          
```

