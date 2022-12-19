### 解题思路
执行用时 :32 ms, 在所有 Python3 提交中击败了95.99%的用户
内存消耗 :13.8 MB, 在所有 Python3 提交中击败了5.26%的用户

1. 由复杂度要求，我们使用二分法，带入模板，几个关键值：
    left = 0, right = len(nums)
    if ...: right = mid
    else: left = mid + 1
补充...处的条件：
    右边界向左移动的情况是：nums[mid]处于下降趋势，即（1）nums[mid]<nums[mid-1]或（2）nums[mid]>nums[mid+1]
    如果用（1）作为...处的条件，则right应该为mid-1，不符合上述模板
    如果用（2）作为...处的条件，符合要求
2. 因为要比较nums[mid]和nums[mid+1]的值，为了不越界，我们计算nums[:-1]之间的峰值，然后返回这个峰值和nums[-1]之间较大值的索引。因此初始边界改为：
    left=0, right = len(nums)-1
3. 实际操作上，由题可知假设nums[-1]为负无穷，即不可能为峰值，可以免去最后这个判断。


### 代码

```python3
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1

        while left < right:
            mid = left + (right - left) // 2

            if nums[mid] > nums[mid+1]:
                right = mid
            else:
                left = mid + 1

        if nums[left] > nums[-1]:
            return left
        else:
            return len(nums) - 1
```