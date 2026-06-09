```
class Solution:
    def hIndex(self, nums):
        # 首先要明确，h 不一定 是来自数组中的元素！
        # 如：[0,1,4,5,6,7,8],h最大为4，因为在数组中至少可以找到4个大于或等于4的数字
        # h+1则不成立，因为数组中不存在5个大于或等于5的数字；h-1一定成立，因为必定存在3个大于或等于3的数字
        # 于是h是临界值，表示最大的符合要求的值，[0,h]条件成立，[h+1,n]条件不成立，n表示元素总数
        # 二分法求解
        l = 0
        r = len(nums) # 右边界为n
        while l < r:
            mid = l + r + 1 >> 1
            if self.check(nums, mid):  # h = mid 时是否至少存在h个元素大于mid
                l = mid
            else:
                r = mid - 1
        return l

    def check(self, nums, h):
        count = 0
        for num in nums:
            if num >= h:
                count += 1
        if count >= h:
            return True
        return False
```
