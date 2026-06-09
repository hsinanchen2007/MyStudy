# BFS

可以用裴蜀定理做, 记录一下BFS的思路

定义两个水壶的状态`[xx, yy]`, 初始化水壶都是空的即`[0, 0]`
有一下集中状态转移方式:
1. 装满任意一个水壶 `[x, yy]` 和 `[y, xx]`
2. 倒掉任意一个水壶 `[0, yy]` 和 `[xx, 0]`
3. 如果一个水壶非空, 尝试把它里面的水倒入另外一个水壶里面

对于第3个情况, 例如当`yy > 0`时,尝试把`yy`中的水全部倒入`xx`或者倒入一部分,直到`xx`满了为止

代码如下
```python
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if z == x + y or z == x or z == y:
            return True
        visited = set()
        state = (0, 0)
        que = collections.deque()
        que.append(state)
        while que:
            xx, yy = que.popleft()
            visited.add((xx, yy))
            if xx + yy == z:
                return True
            if ((x, yy)) not in visited:
                que.append(((x, yy)))
            if ((xx, y)) not in visited:
                que.append((xx, y))
            if ((0, yy)) not in visited:
                que.append((0, yy))
            if ((xx, 0)) not in visited:
                que.append((xx, 0))
            if yy > 0:
                if x - xx <= yy:
                    # 把 xx 满上, yy 中为剩余的部分
                    nx, ny = x, yy - x + xx
                    if (nx, ny) not in visited:
                        que.append((nx, ny))
                else:
                    # 把 yy中的水全倒入x, 此时xx仍然没有满
                    if (xx + yy, 0) not in visited:
                        que.append((xx + yy, 0))
            if xx > 0:
                if y - yy <= xx:
                    nx, ny = xx - y + yy, y
                    if (nx, ny) not in visited:
                        que.append((nx, ny))
                else:
                    if (0, xx + yy) not in visited:
                        que.append((0, xx + yy))

        return False
```

# 裴蜀定理
