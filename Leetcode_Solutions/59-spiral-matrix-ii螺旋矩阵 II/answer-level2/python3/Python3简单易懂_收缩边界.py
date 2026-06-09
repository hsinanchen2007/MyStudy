### 解题思路
关键就是跟踪好左右上下四个边界l, r, t, b
循环退出条件: count > n*n

### 代码

```python3
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        l, r, t, b = 0, n - 1, 0, n - 1
        M = [ [0 for _ in range(n)] for _ in range(n)]
        count, end = 1, n*n
        while count <= end:
            for i in range(l, r + 1): # 0 ~ 2
                # print("aa", t, i, count)
                M[t][i] = count
                count += 1
            t = t + 1

            for i in range(t, b + 1):  # 1 ~ 2
                # print("bb", i, r, count)
                M[i][r] = count
                count += 1
            r = r - 1
            for i in range(r, l - 1, -1):  # 1 ~ 0
                # print("cc", b, i, count)
                M[b][i] = count 
                count += 1
            b = b - 1

            for i in range(b, t - 1, -1): # 1 ~ 1
                # print("dd", i, l, count)
                M[i][l] = count 
                count += 1
               
            l = l + 1
        return M
    

```