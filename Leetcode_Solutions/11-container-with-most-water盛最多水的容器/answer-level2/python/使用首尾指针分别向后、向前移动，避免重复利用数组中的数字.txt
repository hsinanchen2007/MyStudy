### 解题思路
通过首尾指针计算“容器”的长度，指针所指元素中的较小值作为“容器”的高度，每次计算新面积后与当前最大面积比较。
当首尾指针相差为1时，本轮后循环结束。

### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        pos1 = 0
        pos2 = len(height) - 1
        resArea = 0
        stop = False
        while not stop:
            if pos2 - pos1 == 1:
                stop = True
            if height[pos1] <= height[pos2]:
                tempArea = height[pos1] * (pos2 - pos1)
                pos1 += 1
            else:
                tempArea = height[pos2] * (pos2 - pos1)
                pos2 -= 1
            resArea = max(resArea, tempArea)
        return resArea

```