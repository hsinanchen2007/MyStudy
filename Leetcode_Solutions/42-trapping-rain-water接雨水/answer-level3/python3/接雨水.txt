### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        # author:狂奔的蜗牛
        ans = 0
        h1 = 0
        h2 = 0
        for i in range(len(height)):
            h1 = max(h1, height[i]) # 从左边开始，前i+1个元素的最大值
            h2 = max(h2, height[-i-1])  # 从右边开始，后i+1个元素的最大值
            ans = ans + h1 + h2 - height[i]  # 最大值的和减去当前值
        return  ans - len(height)*h1
```