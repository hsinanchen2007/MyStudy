**思路：**

由于不能调用 `MountainArray.get` 超过`100`次，而`mountain_arr.length()`最大为`10000`，所以要用二分查找来搜索我们要找的目标。给定的`mountainArr`是一个山脉数组，即数组元素按顺序，先单调递增，再单调递减。由于二分查找只作用于有序数列，所以我们先要找到山脉数组的峰顶：如果峰顶小于`target`，直接返回`-1`；如果峰顶等于`target`，直接返回峰顶的索引；如果峰顶大于`target`，那么以峰顶为界，先在上坡中二分查找目标，如果找不到，就在下坡中二分查找目标，都找不到就返回`-1`。

**代码：**

```python
# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        n = mountain_arr.length()
        self.memo = dict()
        # 获取索引处的元素值
        def getByIndex(index):
            if index not in self.memo:
                self.memo[index] = mountain_arr.get(index)
            return self.memo[index]
        # 查找峰值
        def findPeak(left, right):
            mid = (left + right) // 2
            mid_left = getByIndex(mid - 1)
            mid_num = getByIndex(mid)
            mid_right = getByIndex(mid + 1)
            if mid_left < mid_num and mid_num > mid_right:
                return mid
            if mid_left > mid_num > mid_right:
                return findPeak(left, mid)
            if mid_left < mid_num < mid_right:
                return findPeak(mid, right)
        # 上坡查找元素
        def findNum1(left, right):
            mid = (left + right) // 2
            mid_num = getByIndex(mid)
            if mid_num == target:
                return mid
            if mid_num > target:
                return findNum1(left, mid)
            if mid_num < target:
                if getByIndex(mid + 1) > target:
                    return -1
                return findNum1(mid, right)
        # 下坡查找元素
        def findNum2(left, right):
            mid = (left + right) // 2
            mid_num = getByIndex(mid)
            if mid_num == target:
                return mid
            if mid_num < target:
                if getByIndex(mid - 1) > target:
                    return -1
                return findNum2(left, mid)
            if mid_num > target:
                return findNum2(mid, right)
        # 和最小元素比较
        min_num1 = getByIndex(0)
        min_num2 = getByIndex(n - 1)
        min_num = min(min_num1, min_num2)
        if target < min_num:
            return -1
        # 和峰值比较
        peak = findPeak(0, n - 1)
        max_num = getByIndex(peak)
        if target == max_num:
            return peak
        if target > max_num:
            return -1
        # 上坡查找
        if target == min_num1:
            return 0
        if target > min_num1:
            res = findNum1(0, peak)
            if res != -1:
                return res
        # 下坡查找
        if target == min_num2:
            return n - 1
        if target > min_num2:
            res = findNum2(peak, n)
            if res != -1:
                return res
        return -1
```