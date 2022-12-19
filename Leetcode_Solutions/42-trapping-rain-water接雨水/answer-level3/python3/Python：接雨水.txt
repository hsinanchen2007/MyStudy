### 解题思路
装水计算体积，然后减去桶壁的体积
优化：
1、减少max和min的计算，特别是在循环中的使用
2、同样的算法，在C、C++等中运行好一点，Python本身的效果不太好

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n <= 2: return 0
        liquid = height[:]
        for i in range(1, n-1):
            liquid[i] = min(max(height[: i+1]), max(height[i: ]))
        return sum(liquid)-sum(height)
```