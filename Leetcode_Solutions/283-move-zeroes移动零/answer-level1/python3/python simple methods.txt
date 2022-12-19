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
        #1. sort
        nums.sort(key=bool,reverse=True)
        '''

        '''
        #1. append 0, remove 0
        for i in nums:
            if i==0:
                nums.append(0)
                nums.remove(0)
        '''
        '''
        #2. count
        for i in range(nums.count(0)):
            nums.remove(0)
            nums.append(0)
        '''

        '''
        #3. double pointer-1
        i,j = 0,0
        while j<len(nums) and i<len(nums):
            if nums[i]!=0:
                i+=1
                j+=1
                continue
            if nums[j]!=0:
                nums[i]=nums[j]
                nums[j]=0
                i+=1
            j+=1
        '''

        '''
        #3. double pointer-2
        slow = 0
        for fast in range(len(nums)):
            if nums[fast]!=0:
                nums[slow],nums[fast] = nums[fast],nums[slow]
                slow+=1
        '''

        '''
        #3. double pointer-3
        slow,fast = 0,0
        while fast!=len(nums):
            if nums[fast]!=0:
                nums[slow] = nums[fast]
                slow+=1
            fast+=1
        nums[slow:] = [0 for i in range(len(nums[slow:]))]
        '''

        #4. yield
        def gen(nums):
            for i in nums:
                if i!=0:
                    yield i
        i = 0
        for i,n in enumerate(gen(nums)):
            nums[i] = n
        for i in range(i+1,len(nums)):
            nums[i] = 0
        
```