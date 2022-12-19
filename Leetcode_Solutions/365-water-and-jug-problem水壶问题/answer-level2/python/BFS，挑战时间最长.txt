### 解题思路
广度优先的思想来写的
![image.png](https://pic.leetcode-cn.com/6140b63005e2e8073e0d2b0db07241b78fd79a43bb9e02b35e44bf3aaababbb9-image.png)

### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        stack = [(0, 0)]
        self.seen = set()
        self.seen.add((0,0))
        while stack:
            remain_x, remain_y = stack.pop()
            if remain_x == z or remain_y == z or remain_x + remain_y == z:
                return True
            
            # 把 X 壶灌满。
            if (x, remain_y) not in self.seen:
                self.seen.add((x, remain_y))
                stack.append((x, remain_y))
            # 把 Y 壶灌满。
            if (remain_x, y) not in self.seen:
                self.seen.add((remain_x, y))
                stack.append((remain_x, y))
            # 把 X 壶倒空。
            if (0, remain_y) not in self.seen:
                self.seen.add((0, remain_y))
                stack.append((0, remain_y))
            # 把 Y 壶倒空。
            if (remain_x, 0) not in self.seen:
                self.seen.add((remain_x, 0))
                stack.append((remain_x, 0))
            # 把 X 壶的水灌进 Y 壶，直至灌满或倒空。
            if (remain_x - min(remain_x, y - remain_y), remain_y + min(remain_x, y - remain_y)) not in self.seen:
                self.seen.add((remain_x - min(remain_x, y - remain_y), remain_y + min(remain_x, y - remain_y)))
                stack.append((remain_x - min(remain_x, y - remain_y), remain_y + min(remain_x, y - remain_y)))
            # 把 Y 壶的水灌进 X 壶，直至灌满或倒空。
            if (remain_x + min(remain_y, x - remain_x), remain_y - min(remain_y, x - remain_x))not in self.seen:
                self.seen.add((remain_x + min(remain_y, x - remain_x), remain_y - min(remain_y, x - remain_x)))
                stack.append((remain_x + min(remain_y, x - remain_x), remain_y - min(remain_y, x - remain_x)))
        return False
```