### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        
        while val in nums:
            #nums.remove(val)
            nums.pop(nums.index(val))
        return len(nums)
        
        '''
        i = 0
        for num in nums:
        #for j in range(len(nums)):
            if num!=val:
            #if nums[j]!=val:
                nums[i] = num
                #nums[i]=nums[j]
                i+=1
        return i
        '''
        '''
        i = 0
        for _ in range(len(nums)):
            if nums[i]==val:
                del nums[i]
            else:
                i+=1
        return len(nums)
        '''
        '''
        i=0       
        while i<len(nums):
            if nums[i]==val:
                #nums.remove(nums[i])
                #nums.pop(i)
                del nums[i]
            else:
                i+=1
        return len(nums)
        '''
        
        '''
        j = nums.index(val) if val in nums else len(nums)
        for i in range(j+1,len(nums)):
            if nums[i]!=val:
                nums[j]=nums[i]
                j+=1
        return j
        '''
        '''
        for i in range(len(nums))[::-1]:
            if nums[i]==val:
                nums.pop(i)
        return len(nums)
        '''
```