原矩阵：
![image.png](https://pic.leetcode-cn.com/d15f874be003537c61c9565d8ab23cdd9710103574a561366f9c9e6ab9fc7d07-image.png)

dp矩阵（比原矩阵宽高均大1）：
![image.png](https://pic.leetcode-cn.com/b8b362ef013936d825ab0b5d245843a3a341aa276843896b29a5ca27595ca706-image.png)

两个矩阵组合大概是这样的：
![image.png](https://pic.leetcode-cn.com/6b728769b24aead12d1001df0428d0316a06d54e533453836af775a00ddee86b-image.png)

第一步：
![image.png](https://pic.leetcode-cn.com/d923264e97f1c96dbba5718bbba86ff35a608c5da6f60f23f5a31717db02e37d-image.png)

第二步、和第三步：
![image.png](https://pic.leetcode-cn.com/3254581d147f03274c78c2f0468f9c8083f2b029a56bde07b0bd161ceb342690-image.png)


以此类推，将左、左上角、上的计算结果保存到右下角去，继续运算
![image.png](https://pic.leetcode-cn.com/ba772819ab28f09e8f49a0ce7c9fb982f7b987c92e3ac239c775347f0def5b93-image.png)

倒数第二步：
![image.png](https://pic.leetcode-cn.com/85cfa9b08feba266f5beca546c2a0824e4100cc5282e71ce62fd0d6523f5ff02-image.png)

最后一步：
![image.png](https://pic.leetcode-cn.com/145abb42be0557c7d1225ebeb52135934cb9f90e545612fff760a7963b614c63-image.png)

测试用例的最大边长为2，面积为 2*2 = 4

代码如下：

```
class Solution:
    def maximalSquare(self, matrix: list) -> int:
        if not matrix:
            return 0
        rows = len(matrix)
        cols = len(matrix[0])
        # 宽高均比matrix大1的矩形
        dp = [[0]*(cols+1) for _ in range(rows+1)]
        ms = 0
        # 这里从大矩形的第二行、第二列开始（原矩形的第一行、第一列）
        for x in range(1, rows+1):
            for y in range(1, cols+1):
                # dp[x][y]表示以(x,y)为右下角且只包含1的最大正方形边长
                # 如果右下角为 1
                if matrix[x-1][y-1] == '1':
                    dp[x][y] = min(dp[x-1][y], dp[x][y-1], dp[x-1][y-1]) + 1
                    # 保存最大边长
                    ms = max(dp[x][y], ms)
        return ms*ms
```
