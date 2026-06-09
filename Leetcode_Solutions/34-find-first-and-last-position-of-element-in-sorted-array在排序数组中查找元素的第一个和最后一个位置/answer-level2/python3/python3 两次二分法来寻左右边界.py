第一步：在[0,lenght-1]范围内找左边界left.如果left不存在,那么left=-1
第二步：(1) 如果left不存在,那么右边界肯定不存在,right=-1;
        (2) 如果left存在，那么右边界肯定存在，在[left,length-1]范围内寻找右边界right.
时间复杂度小于等于o(nlogn+nlogn)，空间复杂度为o(1).
```
class Solution:
    def find_left_boundary(self, start, end, nums, target):
        if start > end:
            return -1
        mid = (start + end) // 2
        # 第一步：判断是否满足左边界条件，满足则return左边界
        if (mid == 0 and nums[mid]==target) or (nums[mid]==target and nums[mid-1]!=target):
            return mid
        # 第二步：二分递归。注意mid+1和mid-1
        if nums[mid] >= target:# 注意是>=
            return self.find_left_boundary(start, mid - 1, nums, target)
        else:
            return self.find_left_boundary(mid + 1, end, nums, target)

    def find_right_boundary(self, start, end, nums, target):
        if start > end:
            return -1

        mid = (start + end) // 2
        # 第一步：判断是否是右边界，满足则return右边界
        if (mid==len(nums)-1 and nums[mid]==target) or (nums[mid+1] > target and nums[mid] == target):
            return mid
        # 第二步：二分递归
        if nums[mid] > target: # 注意是 >
            return self.find_right_boundary(start, mid-1, nums, target)
        else:
            return self.find_right_boundary(mid+1, end, nums, target)

    def searchRange(self, nums, target):
        length = len(nums)
        if length < 1:
            return [-1, -1]

        if target < nums[0] or target > nums[-1]:
            return [-1, -1]

        left = self.find_left_boundary(0, length - 1, nums, target)
        # 如果没有左边界，肯定也没有右边界！
        # 如果存在左边界，那么右边界从[left,end]范围继续二分查找。
        right = self.find_right_boundary(left, length - 1, nums, target) if left != -1 else -1
        return [left, right]

```

