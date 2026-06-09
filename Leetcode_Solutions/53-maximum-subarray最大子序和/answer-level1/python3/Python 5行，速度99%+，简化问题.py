###核心问题

核心问题：滚动加总是不是整数
1. One-pass  时间复杂度是O(N)
2. 是整数，就继续加总，因为整数就是增加的基础
3. 是负数，就可以开始新的滚动加总了。
4. 每一步都比较一下max
5. 没有使用max()函数，好像能快点？

![99.JPG](https://pic.leetcode-cn.com/08c13ce7f58dce923c2729c339aca7d26440fd93e6b8f696dc66d3c1cf7f613c-99.JPG)

###代码
```Python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_, sum_ = nums[0], nums[0]
        for n in nums[1:]:
            sum_ = sum_ + n if sum_ >= 0 else n
            max_ = max_if max_ > sum_ else sum_ #比max快点?
        return max_
```