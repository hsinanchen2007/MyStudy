找到每一个0的位置，从0向前查找，如果前面有数可以跳过0就可以。如果某一0前面的数跳不过0，则无法到达最后一个元素，如果0都能被跳过，则能得到最后一个元素。

```
from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        '''
        从数组的第一个元素开始跳步，步长限制在元素的值以内，判断能否到达最后一个元素,可以利用动态规划的思想
        '''
        def back_jump(index_zero:int) -> bool:
            for i in range(index_zero):
                if nums[i] > (index_zero-i):
                    return True
            return False

        def back_last_ele():
            for i in range(len(nums)-1):
                if nums[i] >= (len(nums)-1-i):
                    return True
            return False



        if 0 not in nums:
            return True
        
        if nums == [0]:
            return True
        #从0向前查找，如果前面有数可以跳过0就可以，如果所有的0前面的数都跳不过0，则无法到达最后一个元素
        for i in range(len(nums)-1):
            if nums[i] == 0:
                if not back_jump(i):
                    return False
            
        #最后一个元素只要达到就行，不用跳过
        return back_last_ele()
```
