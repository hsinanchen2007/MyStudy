#### 方法 1：动态规划

**直觉**

机器人只可以向下和向右移动，因此第一行的格子只能从左边的格子移动到，第一列的格子只能从上方的格子移动到。

<![image.png](https://pic.leetcode-cn.com/57f8df29748c18fcd95903e52500d1c39517cf5ba6c6d2f79e42236edc60a95d-image.png),![image.png](https://pic.leetcode-cn.com/38f3fa01cfa668932aa607b770b8c91dcbb8d80246cb753b179860e58c17f59f-image.png),![image.png](https://pic.leetcode-cn.com/c0b4a348a11cd897003c773926ae2ce8a229a63d55328f54664037ab6f78529c-image.png),![image.png](https://pic.leetcode-cn.com/400a83e7ee46fd08331df82f83cb825d91d523f942ae6c75b8eba90f884f9521-image.png)>

对于剩下的格子，可以从左边或者上方的格子移动到。

<![image.png](https://pic.leetcode-cn.com/2c59e0a4351f6ace179e6c275e1b35b2798ac3f51b6d95e8e5b4369651054b4f-image.png),![image.png](https://pic.leetcode-cn.com/54492c5e6f4031d62b09076117477a7c67b4352b4cf90bde2ce7dca3799cb406-image.png),![image.png](https://pic.leetcode-cn.com/49b1ed1cdc3b510bc37f683cb765a64cf2ff595ee2fd203287c162b550fcf879-image.png),![image.png](https://pic.leetcode-cn.com/27f26d316edd9f9fe06e062edf5f4e63dab6c735c2ac49df042708ed93dc60f3-image.png)>

如果格子上有障碍，那么我们不考虑包含这个格子的任何路径。我们从左至右、从上至下的遍历整个数组，那么在到达某个顶点之前我们就已经获得了到达前驱节点的方案数，这就变成了一个`动态规划`问题。我们只需要一个 `obstacleGrid` 数组作为 DP 数组。

`注意：` 根据题目描述，包含障碍物的格点有权值 `1`，我们依此来判断是否包含在路径中，然后我们可以用这个空间来存储到达这个格点的方案数。

**算法**

1. 如果第一个格点 `obstacleGrid[0,0]` 是 `1`，说明有障碍物，那么机器人不能做任何移动，我们返回结果 `0`。
2. 否则，如果 `obstacleGrid[0,0]` 是 `0`，我们初始化这个值为 `1` 然后继续算法。
3. 遍历第一行，如果有一个格点初始值为 `1` ，说明当前节点有障碍物，没有路径可以通过，设值为 `0` ；否则设这个值是前一个节点的值 `obstacleGrid[i,j] = obstacleGrid[i,j-1]`。
4. 遍历第一列，如果有一个格点初始值为 `1` ，说明当前节点有障碍物，没有路径可以通过，设值为 `0` ；否则设这个值是前一个节点的值 `obstacleGrid[i,j] = obstacleGrid[i-1,j]`。
5. 现在，从 `obstacleGrid[1,1]` 开始遍历整个数组，如果某个格点初始不包含任何障碍物，就把值赋为上方和左侧两个格点方案数之和 `obstacleGrid[i,j] = obstacleGrid[i-1,j] + obstacleGrid[i,j-1]`。
6. 如果这个点有障碍物，设值为 `0` ，这可以保证不会对后面的路径产生贡献。

<![image.png](https://pic.leetcode-cn.com/8aafa0b433830e1c1e26e5478ffed7d9c3f1f46ab0f666bdc95380a81a0fd59d-image.png),![image.png](https://pic.leetcode-cn.com/658959ac92cc80677ea961014100a4c1dfafe89f8eb6b1597e2c917bcefdf048-image.png),![image.png](https://pic.leetcode-cn.com/474355c01af1cf38ab5d677aef57dd517135714f0010e1a5749b4610ddaac4fa-image.png),![image.png](https://pic.leetcode-cn.com/4c97db48c3766d25ec8a3aad91020ed11b292e75306e5e9e5c7714731d93b705-image.png),![image.png](https://pic.leetcode-cn.com/acde4637f2e3ba2dfca062d2e5342647a3144aad62aa392710bb8babc8635a9b-image.png),![image.png](https://pic.leetcode-cn.com/f3a1b115bfd901e00bcb7f8d7612ff7697a5df6546c71da7431a2ca77a619f65-image.png),![image.png](https://pic.leetcode-cn.com/d55803ba6c81170a05ae11fe1cbc288ed527cb5fbdb079552639fc4c0941e57e-image.png),![image.png](https://pic.leetcode-cn.com/667f5142f47d976541bb9b3083708415323b36c26796141a2c35bc5d6c2664ac-image.png),![image.png](https://pic.leetcode-cn.com/234e10fdf3fdeac41f9eb201e011cc8dff264b255cd62a856053b0d966a77e7d-image.png),![image.png](https://pic.leetcode-cn.com/9e83181d6cbcb98a0ea3238c71109c4f38d684bd7dae27a4c5107e1967865a6c-image.png),![image.png](https://pic.leetcode-cn.com/e7e84f90c63fb5f27445eb4390ce342fce6de028b0e2ffa93e15c84219099569-image.png),![image.png](https://pic.leetcode-cn.com/0c44e0debdf09994498cda7cbd2fa46fd34d7304e81dcdcdc3e67413d88b0a66-image.png),![image.png](https://pic.leetcode-cn.com/a0de11361998341eb5228f171be1b6e900dad72229c1ca8bd80afd68011e307e-image.png),![image.png](https://pic.leetcode-cn.com/2df459cf39a003dcdd649a0cf151481d17d51b2e2c0cf6ca2f2a307ed83c04d9-image.png),![image.png](https://pic.leetcode-cn.com/de9bb9595862d7fa6cb178dd8d2bdab6f102e7e74e8c8c8506c3779672247e63-image.png),![image.png](https://pic.leetcode-cn.com/856d2b04c18e4d7a198a0cc1d0097ca50bc5eb2fda731bbb42f1fdbb03bbee65-image.png),![image.png](https://pic.leetcode-cn.com/0f2e86ce483a8fbf962a3d46227f9788f1516c5e57ee3c4b83d7ae1f1f6353e1-image.png),![image.png](https://pic.leetcode-cn.com/7e22c732defc3c0d4ff2fdb8abb5252b83e910f063bba340de8ae4cf6ecc14f0-image.png)>

```Java []
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {

        int R = obstacleGrid.length;
        int C = obstacleGrid[0].length;

        // If the starting cell has an obstacle, then simply return as there would be
        // no paths to the destination.
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        // Number of ways of reaching the starting cell = 1.
        obstacleGrid[0][0] = 1;

        // Filling the values for the first column
        for (int i = 1; i < R; i++) {
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) ? 1 : 0;
        }

        // Filling the values for the first row
        for (int i = 1; i < C; i++) {
            obstacleGrid[0][i] = (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) ? 1 : 0;
        }

        // Starting from cell(1,1) fill up the values
        // No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
        // i.e. From above and left.
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                } else {
                    obstacleGrid[i][j] = 0;
                }
            }
        }

        // Return value stored in rightmost bottommost cell. That is the destination.
        return obstacleGrid[R - 1][C - 1];
    }
}
```

```Python []
class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """

        m = len(obstacleGrid)
        n = len(obstacleGrid[0])

        # If the starting cell has an obstacle, then simply return as there would be
        # no paths to the destination.
        if obstacleGrid[0][0] == 1:
            return 0

        # Number of ways of reaching the starting cell = 1.
        obstacleGrid[0][0] = 1

        # Filling the values for the first column
        for i in range(1,m):
            obstacleGrid[i][0] = int(obstacleGrid[i][0] == 0 and obstacleGrid[i-1][0] == 1)

        # Filling the values for the first row        
        for j in range(1, n):
            obstacleGrid[0][j] = int(obstacleGrid[0][j] == 0 and obstacleGrid[0][j-1] == 1)

        # Starting from cell(1,1) fill up the values
        # No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
        # i.e. From above and left.
        for i in range(1,m):
            for j in range(1,n):
                if obstacleGrid[i][j] == 0:
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1]
                else:
                    obstacleGrid[i][j] = 0

        # Return value stored in rightmost bottommost cell. That is the destination.            
        return obstacleGrid[m-1][n-1]
```
**复杂度分析**

* 时间复杂度 ： $O(M \times N)$ 。长方形网格的大小是 $M \times N$，而访问每个格点恰好一次。
* 空间复杂度 ： $O(1)$。我们利用 `obstacleGrid` 作为 DP 数组，因此不需要额外的空间。
