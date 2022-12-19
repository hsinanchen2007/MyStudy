### 思路

##### 解法一

**BFS**

```
每次水壶都有三个操作：加满水、清空水、相互倒。
```

##### Python3代码

```python
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        # solution one: BFS
        from collections import deque
        queue = deque([[0, 0]])
        visited = set([(0, 0)])

        while queue:
            cur_x, cur_y = queue.pop()
            if z in [cur_x, cur_y, cur_x + cur_y]:
                return True
            for item in [
                # x 加满水，y 加满水
                (x, cur_y), (cur_x, y),
                # x 清空水，y 清空水
                (0, cur_y), (cur_x, 0),
                # 把 x 壶的水灌进 y 壶，直至灌满或倒空
                (cur_x + cur_y - y, y) if cur_x + cur_y >= y else (0, cur_x + cur_y),
                # 把 X 壶的水灌进 Y 壶，直至灌满或倒空
                (x, cur_x + cur_y - x) if cur_x + cur_y >= x else (cur_x + cur_y, 0)]:
                if item not in visited:
                    queue.appendleft(item)  # 从队列左边加入元素
                    visited.add(item)
        return False
```

##### 解法二

**裴蜀定理**

```
能否找到整数 a，b 使得方程 ax + by = z 有解。
有整数解时，当且仅当 z 是 a 和 b 的最大公约数 d 的倍数。
```

##### Python3代码

```python
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        # solution two: 裴蜀定理
        import math
        if x + y < z:
            return False
        if x == z or y == z or x + y == z:
            return True
        return z % math.gcd(x, y) == 0
```

### GitHub链接

[Python](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/0365-Water-and-Jug-Problem/0365.py)

### 参考

[暴力 + 数学](https://leetcode-cn.com/problems/water-and-jug-problem/solution/bao-li-shu-xue-by-powcai/)