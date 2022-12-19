### 解题思路
学习结果里面的内存最佳方法。

**本题关键思路**：暴力解决。从左到右遍历一遍，把每一个格子的左max和右max找到，只要格子高小于左max和右max的最小值就能装水。

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        sum = 0
        maxleft, maxright = 0, 0
        for i in range(1, len(height) - 1):
            # 直接算数组以当前指针为分界点的左max和右max
            maxleft = max(maxleft, height[i - 1])
            maxright = max(height[i + 1:len(height)])
            # 如果左max和右max的min大于当前指针的高，就能装水
            if min(maxleft, maxright) - height[i] > 0:
                sum += min(maxleft, maxright) - height[i]
        return sum
```