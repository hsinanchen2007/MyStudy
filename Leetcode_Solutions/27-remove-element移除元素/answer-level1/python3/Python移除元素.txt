class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        
        num_length=len(nums)
        
        if num_length ==0:
            return 0
        
        if num_length<=1:
            for i in range(num_length):
                if nums[i]==val:
                    nums.pop(i)
        else:
            for i in range(num_length,0,-1):
            
                if nums[i-1]==val:
                
                    nums.pop(i-1)
        
        print(len(nums))
        
        return len(nums)