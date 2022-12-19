### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        ans = 0
        tmp = [[0]*m for i in range(n)]
        for i in range(m):
            for j in range(n):
                a = i // 100 + i // 10 + i % 10
                b = j // 100 + j // 10 + j % 10
                tmp[j][i] = a + b
        def check(x=0, y =0):
            nonlocal ans, k
            if  x == len(tmp) or y == len(tmp[0]) or tmp[x][y] > k or tmp[x][y] == -1 :
                return ""
            ans += 1
            tmp[x][y] = -1
            #left
            check(x, y+1)
            #down#
            check(x+1, y)
        check()
        return ans
```