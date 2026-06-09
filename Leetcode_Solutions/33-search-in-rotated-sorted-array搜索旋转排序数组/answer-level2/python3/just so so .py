```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # you题意可知
        # 根据nums 二分找到最小值
        # 然后换分区间后，在不同二分找到目标值(根据最右一个数，进行划分区域)

        if not nums: return -1
        def minSearch(nums):
            left, right = 0 ,len(nums) - 1
            while(left < right):
                mid = left + (right - left)//2
                if nums[mid] < nums[right]:
                    right = mid 
                else:
                    left = mid + 1
            return left  

        def bSearch(nums, key):
            left, right = 0, len(nums)-1
            while(left <= right):
                mid = left + (right-left)//2 
                if key == nums[mid]:
                    return mid
                if key > nums[mid]:
                    left = mid + 1
                else:
                    right = mid - 1
            return -1

        mi = minSearch(nums)
        print(mi)
        if nums[mi]==target:
            return mi 
        if  nums[-1] == target:
            return len(nums) - 1
        elif nums[-1] >= target:
            idx = bSearch(nums[mi+1:], target)
            if idx == -1:
                 return -1
            else:
                return 1 + idx + mi
        else:
            return bSearch(nums[:mi], target)


                


```
