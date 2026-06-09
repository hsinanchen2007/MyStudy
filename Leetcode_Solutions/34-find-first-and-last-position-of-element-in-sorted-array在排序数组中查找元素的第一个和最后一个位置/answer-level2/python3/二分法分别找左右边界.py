### 解题思路
1. 因为时间复杂度是 O(log n) 级别，因此想到二分查找。
2. 一般的二分查找是在有序数组找到给定值的索引，但是这个是要找到左右边界。
3. 因此，当`nums[mid] ==  target`时，不能直接返回，要分两种情况：
    1. 找左边界：判断`mid == 0 or nums[mid - 1] != target`，满足其中之一，就可以推定`mid`就是要找的左边界；否则，继续迭代，左边界在`mid`的左边。注意这里不能线性查找左边，而是继续迭代：`r = mid - 1`。
    2. 找右边界：判断`mid == len(nums) - 1 or nums[mid + 1] != target`，满足其中之一，就可以推定'mid'是右边界；否则，继续迭代：'l = mid + 1'。
4. 最后注意，`while`循环结束时，说明没找到，`return -1`。
> 开始做的时候就想到了这个思想，但是想把找走右边界合并到一起，一次`while`循环，无奈做不到。还是老老实实写两个函数。O(常数 * log n) 就是 O(log n) 级别。

### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        return [self.searchStart(nums, target), self.searchEnd(nums, target)]
        

    def searchStart(self, nums, target):
        if not nums:
            return -1

        l, r = 0, len(nums) - 1
        
        while l <= r:
            mid = l + ((r - l) >> 1)
            # 此时target在左边
            if nums[mid] > target:
                r = mid - 1
            # 此时target在右边
            elif nums[mid] < target:
                l = mid + 1
            # target == nums[mid]
            else:
                # 目标值的起始点
                if mid == 0 or nums[mid - 1] != target:
                    return mid
                else:
                    r = mid - 1
        return -1


    def searchEnd(self, nums, target):
        if not nums:
            return -1

        l, r = 0, len(nums) - 1
        while l <= r:
            mid = l + ((r - l) >> 1)
            # 此时target在左边
            if nums[mid] > target:
                r = mid - 1
            # 此时target在右边
            elif nums[mid] < target:
                l = mid + 1
            # target == nums[mid]
            else:
                # 目标值的终点
                if mid == len(nums) - 1 or nums[mid + 1] != target:
                    return mid
                else:
                    l = mid + 1
        
        return -1
```