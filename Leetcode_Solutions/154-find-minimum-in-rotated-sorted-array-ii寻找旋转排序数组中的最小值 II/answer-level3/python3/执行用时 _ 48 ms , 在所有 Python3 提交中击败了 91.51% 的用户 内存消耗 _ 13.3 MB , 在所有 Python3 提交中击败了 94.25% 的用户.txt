class Solution:
    def findMin(self, nums: List[int]) -> int:
        L=len(nums)
        l=0
        r=L-1
        
        if L==0:
            return ""
        elif L==1:
            return nums[0]
        elif L==2:
            if nums[0]>=nums[1]:
                return nums[1]
            else:
                return nums[0]
        while l<r:
            mid=l+(r-l)//2
            if nums[mid]>nums[r]:
                if mid>=1 and nums[mid-1]<=nums[mid] and nums[mid]>nums[mid+1]:
                    return nums[mid+1]
                    break
                else:
                    l+=1
            else:
                if mid>=1 and nums[mid-1]>nums[mid] and nums[mid]<=nums[mid+1]:
                    return nums[mid]
                    break
                else:
                    r-=1
        return nums[l]   