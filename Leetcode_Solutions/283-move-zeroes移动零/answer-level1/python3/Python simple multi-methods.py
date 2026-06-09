### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        '''
        for i in nums[:]:
            if i==0:
                nums.append(0)
                nums.remove(0)
        '''
        
        '''
        for i in range(nums.count(0)):
            nums.remove(0)
            nums.append(0)
        '''

        '''
        i,j = 0,0
        while j<len(nums) and i<len(nums):
            if nums[i]!=0:
                i+=1
                j+=1
                continue
            if nums[j]!=0:
                nums[i] = nums[j]
                nums[j] = 0
                i+=1
            j+=1
        '''

        '''
        i = j = 0
        for i in range(len(nums)):
            if nums[i]!=0:
                nums[j],nums[i] = nums[i],nums[j]
                j+=1
        '''
        '''
        nums.sort(key=bool,reverse=True)
        '''
        def gen(nums):
            for x in nums:
                if x!=0:
                    yield x
        i = 0
        for i,n in enumerate(gen(nums)):
            nums[i] = n
        for i in range(i+1,len(nums)):
            nums[i] = 0
```