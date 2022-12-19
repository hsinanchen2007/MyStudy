```
class Solution(object):
    def findKthLargest(self, nums, k):
        return self.partation(nums, len(nums) - k, 0, len(nums) - 1)
    def pivot_median(self,arr):
	    n = len(arr)
	    while n > 5:
		    cols = n//5
		    m = []
		    for i in range(0, cols):
			    s = sorted(arr[5*i:(5*i+5)])
			    m.append(s[2])
		    arr = m
		    n = len(arr)
	    arr.sort()
	    return arr[n//2]

    def partation(self, nums, k, low, high):
        
        pivot = self.pivot_median(nums[low:high+1])
        
        pivotIndex = low + nums[low:high+1].index(pivot)
        
        nums[low] , nums[pivotIndex] = nums[pivotIndex],nums[low]
        
        left = low
        right = high

        #  双指针，快速排序，交换不符合条件的数据
        while left < right:
            while left < right and nums[right] >= pivot:
                right -= 1

            nums[left], nums[right] = nums[right], nums[left]
            while left < right and nums[left] <= pivot:
                left += 1

            nums[left], nums[right] = nums[right], nums[left]

        if left == k:
            return pivot
        elif left > k:
            return self.partation(nums, k, low, left - 1)
        else:
            return self.partation(nums, k, left + 1, high)


```
