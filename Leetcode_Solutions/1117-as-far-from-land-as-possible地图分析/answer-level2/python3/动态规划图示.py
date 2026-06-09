# 动态规划图示

演示两种简单情况，为了方便计算，将所有陆地的值设为$0$，海洋标记为$2N$，正常情况下海洋距离陆地的最远距离为$2N-2$（仅在地图某一角上存在唯一陆地）。

## 1.只有一块陆地时

![批注 2020-03-29 234050.png](https://pic.leetcode-cn.com/e7c3acba7d562dca600a9d5f660e6ffb0688320ad4abbe7ea8035415b4d03d2b-%E6%89%B9%E6%B3%A8%202020-03-29%20234050.png)

第一次：从左上到右下

$\large grid[i][j] = \min{(grid[i][j], grid[i-1][j]+1,grid[i][j-1]+1)}$

![批注 2020-03-29 234109.png](https://pic.leetcode-cn.com/ed0e0725ba98bec63875d5d257e4695bc330dad5cbe804a63102dfa443a52af6-%E6%89%B9%E6%B3%A8%202020-03-29%20234109.png)

第二次：从右下到左上

$\large grid[i][j] = \min{(grid[i][j], grid[i+1][j],grid[i][j+1])}$

![批注 2020-03-29 234123.png](https://pic.leetcode-cn.com/6f0d60a7765d8eadf05175741ecdc66adb106fba40cfb53bdafeee4d5d2e7206-%E6%89%B9%E6%B3%A8%202020-03-29%20234123.png)

在第二次迭代的过程中，紫色区域距离陆地的距离被间接地计算出来了

## 2.有两块陆地时

![批注 2020-03-29 234138.png](https://pic.leetcode-cn.com/afc496980a66493a79b1f20c914e799eb8c36a68c99c0311b8a441a88cdb101c-%E6%89%B9%E6%B3%A8%202020-03-29%20234138.png)

第一次：从左上到右下

$\large grid[i][j] = \min{(grid[i][j], grid[i-1][j]+1,grid[i][j-1]+1)}$

![批注 2020-03-29 234148.png](https://pic.leetcode-cn.com/f004a49bfc561d0086560f6ade305c8388e2ac8b4b17a35f052abe42122d0f19-%E6%89%B9%E6%B3%A8%202020-03-29%20234148.png)

第二次：从右下到左上

$\large grid[i][j] = \min{(grid[i][j], grid[i+1][j],grid[i][j+1])}$

![批注 2020-03-29 234200.png](https://pic.leetcode-cn.com/d8de5038b1eaf2745233a47154da6eac32a1ee38380f17adc1ee4f6b9e484bf8-%E6%89%B9%E6%B3%A8%202020-03-29%20234200.png)

## 代码

``` python
class Solution:
    def maxDistance(self, grid) -> int:
        N = len(grid)
        N2 = N * 2
        for row in grid:
            for i in range(N):
                row[i] = 0 if row[i] == 1 else N2
        for k in range(1, N2 - 1):
            for i in range(max(0, k - N + 1), min(k + 1, N)):
                j = k - i
                grid[i][j] = min(
                    grid[i][j],
                    min(grid[i - 1][j] if i else grid[i][j],
                        grid[i][j - 1] if j else grid[i][j]) + 1)
        for k in range(N2 - 3, -1, -1):
            for i in range(max(0, k - N + 1), min(k + 1, N)):
                j = k - i
                grid[i][j] = min(
                    grid[i][j],
                    min(grid[i + 1][j] if i < N - 1 else grid[i][j],
                        grid[i][j + 1] if j < N - 1 else grid[i][j]) + 1)

        ans = max(max(row) for row in grid)
        return ans if 0 < ans < N2 else -1
```
