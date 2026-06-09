
看了好多种方法，还是觉得双指针的最简单，做这个题的时候可以对比下题库里的题：11.盛最多水的容器
https://leetcode-cn.com/problems/container-with-most-water/
```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        # 双指针的解法
        n = len(height)
        if not n: return 0
        i, j, res = 0, n-1, 0
        max_i = height[i]
        max_j = height[j]
        while i < j:
            if height[i] <= height[j]:
                res += max_i - height[i] #最高的值减去此时的高度乘以宽度1，更新答案
                i += 1
                max_i = max(height[i], max_i)
            if height[i] > height[j]:
                res += max_j - height[j]
                j -= 1
                max_j = max(height[j], max_j)
        return res
```