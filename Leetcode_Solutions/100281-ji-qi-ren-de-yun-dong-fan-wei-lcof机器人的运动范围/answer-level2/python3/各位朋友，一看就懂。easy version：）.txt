### 解题思路
：）

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        row, col = m - 1, n - 1
        momo = [[False for _ in range(n)] for _ in range(m)]
        temp = [(0,0)]
        momo[0][0] = True
        count = 0 
        while temp:
            count += 1
            x_temp, y_temp = temp.pop(0)
            for dire in [[1,0],[-1,0],[0,1],[0,-1]]:
                xx = x_temp + dire[0]
                yy = y_temp + dire[1]
                if 0 <= xx <= row and 0 <= yy <= col and self.judge(xx, yy) <= k and not momo[xx][yy]:
                    temp.append((xx, yy))
                    momo[xx][yy] = True           
        return count

    def judge(self, xx, yy):
        ans = 0
        while xx:
            ans += xx % 10
            xx //= 10
        while yy:
            ans += yy % 10
            yy //= 10
        return ans
```