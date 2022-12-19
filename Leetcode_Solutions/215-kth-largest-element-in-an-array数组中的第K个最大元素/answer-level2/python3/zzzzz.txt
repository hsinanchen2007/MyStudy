```
class Solution(object):
    def findKthLargest(self, nums, k):
        return self.partation(nums, len(nums) - k, 0, len(nums) - 1)

    def partation(self, nums, k, low, high):
        # #选择一个合适的比较基准
        mid = (low+high)//2
        if max([nums[low],nums[high]])>=nums[mid]>=min([nums[low],nums[high]]):
            nums[low],nums[mid]=nums[mid],nums[low]
        elif max([nums[mid],nums[low]])>=nums[high]>=min([nums[mid],nums[low]]):
            nums[low],nums[high]=nums[high],nums[low]

        bound = nums[low]
        left = low
        right = high

        #  双指针，快速排序，交换不符合条件的数据
        while left < right:
            
            #必须先从后往前
            while left < right and nums[right] >= bound:
                right -= 1

            nums[left], nums[right] = nums[right], nums[left]
            while left < right and nums[left] <= bound:
                left += 1

            nums[left], nums[right] = nums[right], nums[left]

        if left == k:
            return bound
        elif left > k:
            return self.partation(nums, k, low, left - 1)
        else:
            return self.partation(nums, k, left + 1, high)


```
