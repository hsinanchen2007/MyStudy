> 参照 LeetCode 官方题解，语言改为Python3

## 算法
+ 设置一个slow代表慢指针。
+ 用快指针遍历nums。
+ 当快指针找到一个非0数后，交换快慢指针的数。

即，快指针从前向后寻找非0数，慢指针所在的数是要被修改的数。

## 代码
```python
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        slow = 0
        for fast in range(len(nums)):
            if nums[fast] != 0:
                nums[slow], nums[fast] = nums[fast], nums[slow]
                slow += 1
```
## 复杂度分析

+ 时间复杂度：$O(n)$。
 
  但是，操作是最优的。代码执行的总操作（数组写入）是非 0 元素的数量.

+ 空间复杂度：$O(1)$，

  只使用了常量空间。