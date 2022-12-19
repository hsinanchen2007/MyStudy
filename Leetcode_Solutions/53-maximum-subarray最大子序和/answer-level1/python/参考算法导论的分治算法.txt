## 思路：
- 最近正好看到了算法导论的分治算法那一章，第一个例题讲的就是这个，只不过他们返回的东西不一样，那个要返回数组，这个只要返回最大值就行了。
- 思路还是一样的。
- 将数组一分为二递归进去。
- 每一层递归做四件事：
    - 递归寻找从`mid`到`low`(就是你传进去的参数的最左边的那个下标)之间的最大子序和。
    - 递归寻找从`mid+1`到`high`(传进去的最右边的那个下标)之间的最大子序和。
    - 找完了左边的和右边的，还要找穿过中间的最大子序和。
        - 由于是穿过中间的最大子序和，也就是说这个子序至少要包含中间的`mid`和`mid+1`。
        - 因此一遍向左遍历，一遍向右遍历，找到最大的子序和之后把左右相加返回即可。
    - 将三者的子序和取最大的那个返回。

## 代码：
```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        return self.recursion(0, len(nums) - 1, nums)  # 开始递归
        
        
    def recursion(self, low: int, high: int, nums: List[int]) -> int:
        if low == high:  # 递归基线条件，当分到只有一个数组时，那么最大值就是这一个值。
            return nums[low]
        else:
            mid = (low + high) // 2  # 递归遍历一分为二
            left_sum = self.recursion(low, mid, nums)  # 递归进左边
            right_sum = self.recursion(mid + 1, high, nums)  # 递归进右边
            cro_sum = self.crossing(low, mid, high, nums)  # 寻找穿过中间的最大子序和
            return max(left_sum, right_sum, cro_sum)  # 返回三者的最大值
            
            
    def crossing(self, low: int, mid: int, high: int, nums: List[int]) -> int:
        left_sum = right_sum = float('-inf')
        max_low = mid
        max_high = mid + 1
        _sum = 0
        i = mid
        while i >= low:  # 找到左边的最大值
            _sum += nums[i]
            if _sum > left_sum:
                left_sum = _sum
                max_low = i
            i -= 1
        _sum = 0
        i = mid + 1
        while i <= high:  # 找到右边的最大值
            _sum += nums[i]
            if _sum > right_sum:
                right_sum = _sum
                max_high = i
            i += 1
        return left_sum + right_sum  # 把它们相加起来
```