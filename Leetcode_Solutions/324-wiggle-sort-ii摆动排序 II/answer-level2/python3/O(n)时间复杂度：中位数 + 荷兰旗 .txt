```
class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n < 2:return nums
        mid = (0 + n-1) // 2 # 中位数索引
        

        # 快速排序中的一次划分
        def partition(begin,end):
            left,right = begin,end
            while left < right:
                while left < right and nums[left] < nums[right]:right -= 1
                if left < right:
                    nums[left],nums[right] = nums[right],nums[left]
                    left += 1
                while left < right and nums[left] < nums[right]: left += 1
                if left < right:
                    nums[left],nums[right] = nums[right],nums[left]
                    right -= 1
            return left

        # 找到中位数对应的数值
        left,right = 0, n-1
        while True:
            pivot = partition(left,right)
            if pivot == mid:break
            elif pivot > mid:right = pivot - 1
            else:left = pivot + 1

        # 三路划分(荷兰旗)
        midNum = nums[mid]
        left,curr,right = 0, 0, n-1
        while curr < right:
            if nums[curr] < midNum:
                nums[left],nums[curr] = nums[curr],nums[left]
                left += 1
                curr += 1
            elif nums[curr] > midNum:
                nums[curr],nums[right] = nums[right],nums[curr]
                right -= 1
            else:
                curr += 1

        # 交叉合并
        small,big ,_nums = mid,n-1,nums[:]
        for i in range(n):
            if i%2 == 0:
                nums[i] = _nums[small]
                small -= 1
            else:#big
                nums[i] = _nums[big]
                big -= 1
```
