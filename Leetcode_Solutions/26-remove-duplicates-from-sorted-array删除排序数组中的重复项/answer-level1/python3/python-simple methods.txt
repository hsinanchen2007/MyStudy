### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        #set
        '''
        nums[:]=sorted(list(set(nums)))
        return len(nums)
        '''
        #delete/pop method
        #正序：
        
        if len(nums)<=1: return len(nums)
        i = 0
        for _ in range(len(nums)-1):
            if nums[i]==nums[i+1]:
                del nums[i]
            else:
                i+=1
        return len(nums)
        
        #逆序
        '''
        if len(nums)<=1: return len(nums)
        for i in range(len(nums))[::-1]:
            if i-1!=-1:
                if nums[i-1]==nums[i]:
                    #del nums[i]
                    nums.pop(i)
        return len(nums)
        '''
        #double pointers
        #正序：
        '''
        if not nums: return 0
        i = 0
        for j in range(1,len(nums)):
            if nums[i]!=nums[j]:
                i+=1
                nums[i] = nums[j]
        return i+1
        '''
        '''
        if len(nums)==0: return 0
        i = 0
        for num in nums:
            if nums[i]!=num:
                i+=1
                nums[i]=num
        return i+1
        '''
        '''
        if not nums: return 0
        i = 1
        for j in range(1,len(nums)):
            if nums[j]!=nums[j-1]:
                nums[i]=nums[j]
                i+=1
        return i
        '''
        #while-loop
        '''
        pre,cur = 0,1
        while cur<len(nums):
            if nums[pre]==nums[cur]:
                del nums[cur]
            else:
                pre+=1
                cur+=1
        return len(nums)
        '''
        '''
        if len(nums)<=1: return len(nums)
        i = 0
        while i<len(nums):
            if nums[i] in nums[:i]:
                del nums[i]
                continue
            else:
                i+=1
        return len(nums)
        '''

```