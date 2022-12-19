代码如下：


class Solution:

    #主函数
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums=nums1+nums2
        length=len(nums)
        mid=0
        nums=self.quicksort(0,length-1,nums)
        if(length%2==1):
            mid=nums[int(length/2)]
        else:
            mid=(nums[int(length/2)]+nums[int(length/2)-1])/2
        return mid
        
    def quicksort(self,left,right,nums):
        if(left<right):
            nums,mid=self.partition(left,right,nums)
            if(left<mid):
                nums=self.quicksort(left,mid-1,nums)
            if(mid<right):
                nums=self.quicksort(mid+1,right,nums)
        return nums
    
    def partition(self,left,right,nums):
        key=nums[left]
        while(left<right):
            while(nums[right]>=key and left<right):
                right-=1
            nums[left]=nums[right]
            while(nums[left]<key and left<right):
                left+=1
            nums[right]=nums[left]
        nums[left]=key
        return nums,left