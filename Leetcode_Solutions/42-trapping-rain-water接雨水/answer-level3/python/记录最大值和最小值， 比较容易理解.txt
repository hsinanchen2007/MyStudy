    将每一个位置想象成一个桶, 桶的左右边界分别为 往左看的最大值和往右看的最大值
    桶的理想容量为这两者中较小的那个
    实际容量为, 理想容量 - 桶底的高度


```python
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """

        
        if not height:
            return 0

        right_maxs = [0 for _ in range(len(height))]    # 右侧最大值
        right_maxs[-1] = height[-1]

        for i in range(len(height)-2, -1, -1):
            right_maxs[i] = max(height[i], right_maxs[i+1])

        ans = 0
        left_max = height[0]    # 左侧最大值
        for i in range(1, len(height)):
            limit = min(left_max, right_maxs[i])   # 理想容量
            space = limit - height[i]   # 实际容量
            if space > 0:
                ans += space
            left_max = max(left_max, height[i])
        return ans
```