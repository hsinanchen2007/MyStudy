### 解题思路
这里不能用遍历矩阵的方法，因为有的点是不可达的，移动不到那里

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        moves = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        res = 1
        checked = {(0, 0)}
        q = [(0, 0)]

        while q:
            x, y = q.pop()
            for i, j in moves:
                new_x = x + i
                new_y = y + j
                if 0 <= new_x < m and 0 <= new_y < n and (new_x, new_y) not in checked:
                    if sum(int(i) for i in str(new_x) + str(new_y)) <= k:
                        checked.add((new_x, new_y))
                        q.append((new_x, new_y))
                        res += 1
                        
        return res
                
```