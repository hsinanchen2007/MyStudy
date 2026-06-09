### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        '''
        #1. dict
        dict={}
        for i in nums:
            dict[i] = dict.get(i,0)+1
            if dict[i]>=2:
                return True
        return False
        '''

        '''
        return len(list(set(nums)))!=len(nums)
        '''

        '''
        for i in range(1,len(sorted(nums))):
        #for i in range(len(nums)-1):
            if nums[i-1]==nums[i]:
            #if nums[i+1]==nums[i]:
                return True
        return False
        '''

        '''
        s = len(collections.Counter(nums))
        if s<len(nums):
            return True
        else:
            return False
        '''

        vis = set()
        for i in nums:
            if i in vis:
                return True
            vis.add(i)
        return False

```