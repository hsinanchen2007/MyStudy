### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return self.quick_sort(nums,0,len(nums)-1)

    def quick_sort(self,nums,start,end):
        # 定义两个游标
        # left至左向右移动
        left = start
        # right至右往左移动
        right = end

        # 递归的退出条件
        if left > right:
            return
        mid = nums[start]

        while left < right:
            # 如果left和right未重合，并且right指向的元素不比基准值小，则right向左移动
            while left <right and nums[right] >= mid:
                right -= 1
            # 将right指向的元素放到left的位置上
            nums[left] = nums[right]
            # 如果left与right未重合，并且left指向的元素比基准值小，则left向右移动
            while left < right and nums[left] < mid:
                left += 1
            # 将left指向的元素放到right的位置
            nums[right] = nums[left]
            # 此时推出循环之后，right与left重合，此时所指的位置为基准元素的正确位置
        # 将基准元素放到改位置

        nums[left] = mid
        # 对基准元素左边的子序列进行快速排序
        self.quick_sort(nums,start,left -1)
        # 对基准元素右边的子序列进行快速排序
        self.quick_sort(nums,left + 1,end )
        return nums


                
```