### 解题思路
1. 快速排序
2. 归并排序

### 代码

```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
    #     self.quick_sort(nums, 0, len(nums)-1)
    #     return nums
    
    # def quick_sort(self, li, start, end):
    #     # 分治 一分为二
    #     if start >= end:
    #         return
    #     # 定义两个游标，分别指向0和末尾位置
    #     left = start
    #     right = end
    #     # 把0位置的数据，认为是中间值
    #     mid = li[left]
    #     while left < right:
    #         # 让右边游标往左移动，目的是找到小于mid的值，放到left游标位置
    #         while left < right and li[right] >= mid:
    #             right -= 1
    #         # 让左边游标往右移动，目的是找到大于mid的值，放到right游标位置
    #         while left < right and li[left] < mid:
    #             left += 1
    #         # 原地交换两个数
    #         li[right], li[left] = li[left], li[right]

    #     # 递归处理左边的数据
    #     self.quick_sort(li, start, left)
    #     # 递归处理右边的数据
    #     self.quick_sort(li, left+1, end)

        if len(nums)<=1:
            return nums
        
        mid = len(nums) >> 1
        left = self.sortArray(nums[:mid])
        right = self.sortArray(nums[mid:])

        l, r = 0, 0
        result = []
        while l < len(left) and r < len(right):
            if left[l] < right[r]:
                result.append(left[l])
                l += 1
            else:
                result.append(right[r])
                r += 1
        result += left[l:]
        result += right[r:]
        return result


```