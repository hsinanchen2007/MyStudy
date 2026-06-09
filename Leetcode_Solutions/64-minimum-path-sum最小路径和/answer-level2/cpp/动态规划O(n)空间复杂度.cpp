### 解题思路
**动态规划**
用数组D[i][j]存放由左上角到D[i][j]的最短路径值，
因为只能向下和向右移动一步，所以D[i][j]的值只和
D[i][j-1] (注意边界)、D[i-1][j]的值有关。

先计算第一行的D[0][j],再由第一行的值可以获得下一
行的值，直到获得D[m-1][n-1]的值，即为题解。

之后可以对空间复杂度进行优化，使用一维数组保存最短路径。

(写得不好，见谅。)

### 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();

        //动态规划(使用二维数组)
        // vector<vector<int>> D(m,vector<int> (n,0));
        // D[0][0] = grid[0][0];
        // for (int i=1 ; i<n ; i++) {
        //     D[0][i] = grid[0][i] + D[0][i-1];
        // }
        // for (int i=1 ; i<m ; i++) {
        //     D[i][0] = grid[i][0] + D[i-1][0];
        //     for (int j=1 ; j<n ;j++) {
        //         D[i][j] = min(D[i][j-1]+grid[i][j], D[i-1][j]+grid[i][j]);
        //     }
        // }
        // return D[m-1][n-1];

        //动态规划(使用一位数组)
        vector<int> D(n,0);
        D[0] = grid[0][0];
        for (int i=1 ; i<n ; i++) D[i] = grid[0][i] + D[i-1];
        for (int i=1 ; i<m ; i++) {
            D[0] += grid[i][0];
            for (int j=1 ; j<n ; j++) {
                D[j] = min(D[j]+grid[i][j],D[j-1]+grid[i][j]);
            }
        }
        return D[n-1];
    }
};
```