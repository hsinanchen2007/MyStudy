### 解题思路
2019.3.10. 一面面试题 
没想到用 DP 求解，还是自己想的太复杂了。

2020.3.21 这一题居然是童老师动态规划篇习题，可惜我当时还没有学到这里，不然我就会做了。




一般对于有向无环图结构，如果想到了可以递归求解，都可以使用 DP 来进行求解。
参见习题 [241. 为运算表达式设计优先级](https://leetcode-cn.com/problems/different-ways-to-add-parentheses/)

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        # fp[i] 代表偷前 i 个房子所能达到的最大值
        # fp[i] = max(fp[i-2] + A[i], fp[i-1])
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        
        fp = [0]*n
        fp[0] = nums[0]
        fp[1] = max(fp[0], nums[1])

        for i in range(2, n):
            fp[i] = max(fp[i-1], fp[i-2]+nums[i])

        return fp[n-1]
            
```