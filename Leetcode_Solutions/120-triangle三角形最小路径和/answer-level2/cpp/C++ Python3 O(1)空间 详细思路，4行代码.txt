### 解题思路
动态规划的思路，路径长度最小包含最优子问题，即前一个路径最小加上当前最小值。

找到递推公式，两种思路，一种从上到下，即上面一行已知，求下面一行元素，将会发现下一行的两边元素不好处理；

反过来，已知下面一行元素，求上面一行元素，那么很容易发现递归方程统一为dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j]

另外初始状态就是最下面一行triangle[N-1]， N为行数

最终我们需遥返回最短路径，所有路径走完最终都是到达了顶点dp[0][0]， 返回这个即可。

### 另开一个二维数组，空间复杂度O(n)

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int N = triangle.size();
        vector<vector<int>> dp(N, vector<int>(N));
        dp[N-1] = triangle[N-1];//初始状态
        for(int i = N-2; i >=0; i--) {
            for(int j = 0; j < i+1; j++) {
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];//递推公式(状态转移方程)
            }
        }
        return dp[0][0];//最终状态
    }
};
```

### 就地排序版
空间复杂度O(1)

```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = triangle.size()-2; i >=0; i--) {
            for(int j = 0; j < triangle[i].size(); j++) {
                triangle[i][j] = min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j];
            }
        }
        return triangle[0][0];
    }
};
```

### Python3

```python3
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        for i in range(len(triangle)-2, -1, -1):
            for j in range(len(triangle[i])):
                triangle[i][j] = min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j]
        
        return triangle[0][0]
```