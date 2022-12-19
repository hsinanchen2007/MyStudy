### 解题思路
wocao 脑筋急转弯吗？
思路：倒序遍历从n-2开始。如果当前i元素比i+1大，继续倒序遍历。否则将当前元素之后的元素列表倒序，然后从i+1开始找第一个比i大的元素交换
列表的range(i+1,n)部分倒序，应该使用双指针交换元素实现，保证空间复杂度O(1)

### 代码

```python
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        def rev(start, nums):
            if not nums:
                return []
            end = len(nums)-1
            while start < end:
                nums[start], nums[end] = nums[end], nums[start]
                end -= 1
                start += 1
            return nums

        if not nums:
            return []
        n = len(nums)
        if n == 1:
            return nums
        for i in range(n-2, -1, -1):
            if nums[i] >= nums[i+1]:
                continue
            else:
                nums = rev(i+1, nums) #range(i+1, n)列表倒序
                for j in range(i+1, n): #找到从i+1开始第一个比i位置元素大的数字，swap
                    if nums[i] < nums[j]:
                        nums[i], nums[j] = nums[j], nums[i]
                        return nums
        return nums.reverse() #如果列表递减则返回倒序。

```