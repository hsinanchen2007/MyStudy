
思路见其它题解，头尾双指针向中间收敛，用了两个小trick缩减代码行数：max和min函数取代判断；True=1，False=0

```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        cap, i, j = 0, 0, len(height) - 1
        while i < j:
            cap = max(cap, (j - i) * min(height[i], height[j]))
            i, j = i + (height[i] <= height[j]), j - (height[i] >= height[j])
        return cap
```
