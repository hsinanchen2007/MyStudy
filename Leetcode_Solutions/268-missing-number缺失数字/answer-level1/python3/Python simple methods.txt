### 解题思路
此处撰写解题思路

### 代码

```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        '''
        #1. dict
        dict={}
        for i,v in enumerate(sorted(nums)):
            dict[v] = i
            if i!=v:
                return i
        else:
            return i+1
        '''

        '''
        #2. set
        s1 = set(range(len(nums)))
        s2 = set(nums)
        return len(nums) if s1==s2 else list(s1-s2)[0]
        '''

        '''
        #2. set
        return (set(range(len(nums)+1))-set(nums)).pop()
        return int((len(nums)*(len(nums)+1))/2)-sum(nums)
        '''

        '''
        #3.^
        res = 0
        for i,v in enumerate(nums):
            res=res^i^v
        return res^len(nums)
        '''

        #4. sort()
        nums.sort()
        if nums[-1]!=len(nums):
            return len(nums)
        elif nums[0]!=0:
            return 0
        for i,v in enumerate(nums):
            if i!=v:
                return i

```
