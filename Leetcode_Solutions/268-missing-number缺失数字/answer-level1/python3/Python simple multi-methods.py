### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        '''
        nums.sort()
        for i in range(len(nums)):
            if nums[i]!=i:
                return i
        return len(nums)
        '''

        '''
        nums.sort()
        if nums[-1]!=len(nums):
            return len(nums)
        elif nums[0]!=0:
            return 0
        for i in range(1,len(nums)):
            missnum = nums[i-1]+1
            if nums[i]!=missnum:
                return missnum
        '''

        '''
        numset=set(nums)
        n = len(nums)+1
        for num in range(n):
            if num not in numset:
                return num
        '''

        '''
        missnum = len(nums)
        for i,num in enumerate(nums):
            missnum^=i^num
        return missnum
        '''

        '''
        res = 0
        for i,num in enumerate(nums):
            res = res^i^num
        return res^len(nums)
        '''

        '''
        nums.sort()
        if nums[-1]!=len(nums):
            return len(nums)
        elif nums[0]!=0:
            return 0
        for i,num in enumerate(nums):
            if i!=num:
                return i
        '''
        
        '''
        res = len(nums)
        for i,num in enumerate(nums):
            res+=i-num
        return res
        '''

        '''
        #n = len(nums)
        #return n*(n+1)//2-sum(nums)
        #return int((len(nums)*(len(nums)+1))/2)-sum(nums)
        expectsum = len(nums)*(len(nums)+1)//2
        actualsum = sum(nums)
        return expectsum-actualsum
        '''

        '''
        s1,s2 = set(range(len(nums))),set(nums)
        return len(nums) if s1==s2 else list(s1-s2)[0]
        '''

        return (set(range(len(nums)+1))-set(nums)).pop()
```