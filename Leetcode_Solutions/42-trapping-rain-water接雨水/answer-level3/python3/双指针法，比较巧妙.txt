### 解题思路
该题可以想到双指针，但不知道如何解决，则需要从问题入手，从整体无法解决，则可以考虑单个值能够存储的雨水

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        # 本题的核心在于整体考虑能接多少雨水不提合适，则先考虑每一个格子能装多少雨水
        # 贪心法--> 备忘录优化的方法--> 双指针法
        n = len(height)
        if n <= 2:
            return 0
        l_max = height[0]
        r_max = height[n-1]
        left = 1
        right = n-2
        rain = 0
        while left<=right:
            l_max = max(l_max, height[left])
            r_max = max(r_max, height[right])
            if l_max <= r_max:
                rain += l_max - height[left]
                left += 1
            else:
                rain += r_max - height[right]
                right -= 1
        return rain
```