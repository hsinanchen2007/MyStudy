### 解题思路

此题的关键在于将问题转化为`排序问题`，这里将利用`反证法`对其进行证明：

设nums=[a,b,c]以代码中`def is_bigger`的方式进行排序，则`abc<bca`，反证：
```python
假设 abc>bca:
    abc>bca>bac>abc 矛盾
因此假设不成立
```
因此排序后的abc一定是a/b/c三者组合中最小的一个数字


### 代码

```python3
class Solution:
    def minNumber(self, nums: List[int]) -> str:
        """快排"""
        def is_bigger(x, y):
            a, b = x+y, y+x
            if b<a:
                return True
            return False
        def partition(left, right):
            pivot = nums[right]
            index = left
            for i in range(left, right):
                if is_bigger(pivot, nums[i]):  # nums[i]<pivot
                    nums[index], nums[i] = nums[i], nums[index]
                    index += 1
            nums[index], nums[right] = nums[right], nums[index]
            return index
        def quick_sort(left, right):
            if left>=right: return
            mid = partition(left, right)
            quick_sort(left, mid-1)
            quick_sort(mid+1, right)
        nums = [str(n) for n in nums]
        quick_sort(0, len(nums)-1)
        return "".join(nums)
```