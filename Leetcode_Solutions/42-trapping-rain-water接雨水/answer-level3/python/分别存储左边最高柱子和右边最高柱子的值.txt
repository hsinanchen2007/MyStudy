```python
class Solution:
    def trap(self, height: List[int]) -> int:
        # 每一个位置能接的水 = min（左边最高，右边最高）- 当前位置高度
        N = len(height)
        if N == 0:
            return 0
        left_max = 0
        right_max = max(height)
        result = 0
        for i in range(N):
            h = height[i]
            if h == right_max:
                right_max = max(height[i+1:]) if i+1 < N else 0
            floor = min(left_max, right_max)
            if h < floor:
                result += floor - h
            if h > left_max:
                left_max = h
        return result
```