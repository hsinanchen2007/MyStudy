```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        k%=len(nums)
        #print(nums[-k:])
        #print(nums[:-k])
        nums[:]=nums[-k:]+nums[:-k]
        
        
        '''
        k%=len(nums)
        nums[:]=nums[::-1]
        nums[:k] = nums[:k][::-1]
        nums[k:] = nums[k:][::-1]
        '''

        '''
        for i in range(k):
            tmp = nums[-1]
            for j in range(len(nums)-1,0,-1):
                nums[j] = nums[j-1]
            nums[0] = tmp
        '''
```
