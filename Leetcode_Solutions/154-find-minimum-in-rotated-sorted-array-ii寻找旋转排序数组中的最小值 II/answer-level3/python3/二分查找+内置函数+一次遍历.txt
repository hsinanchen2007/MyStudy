执行用时 :44 ms, 在所有 Python3 提交中击败了96.25% 的用户。
内存消耗 :13.1 MB, 在所有 Python3 提交中击败了100.00%的用户。

二分查找：

```
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = (left+right) // 2
            if nums[mid] > nums[right]:
                left = mid + 1
            elif nums[mid] < nums[right]:
                right = mid
            else:
                right -= 1  #如果和右端元素相等，则左移一位即可。
        return nums[left]```


执行用时 :48 ms, 在所有 Python3 提交中击败了92.51% 的用户。
内存消耗 :13.1 MB, 在所有 Python3 提交中击败了100.00%的用户。

直接一次遍历。
```
class Solution:
    def findMin(self, nums: List[int]) -> int:
        a = nums[0]
        for i in range(1, len(nums)):
            if nums[i] < a:
                a = nums[i]
        return a
```

内置函数法（作弊法）

```
class Solution:
    def findMin(self, nums: List[int]) -> int:
        return min(nums)
```