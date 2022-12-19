class Solution:
    def findMin(self, nums: List[int]) -> int:
        L=len(nums)
        l=0
        r=L-1
        
        if not nums:
            return ""
        elif L==1:
            return nums[0]
        
        while l<r:
            mid=l+(r-l)//2
            if mid==0:
                if nums[mid]>nums[mid+1]:
                    return nums[mid+1]
                    break
                else:
                    return nums[mid]
                    break
            elif nums[mid]>nums[r]:
                if mid>=1 and nums[mid-1]<nums[mid] and nums[mid]>nums[mid+1]:
                    return nums[mid+1]
                    break
                else:
                    l+=1
            else:
                if mid>=1 and nums[mid-1]>nums[mid] and nums[mid]<nums[mid+1]:
                    return nums[mid]
                    break
                else:
                    r-=1