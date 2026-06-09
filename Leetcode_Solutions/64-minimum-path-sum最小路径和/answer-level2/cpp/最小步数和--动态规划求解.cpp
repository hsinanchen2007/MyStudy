### 解题思路
动态规划：坐标型动态规划（有明确的坐标系，这一步的结果等于上一步跳过来的结果）
（1）state状态，求解最小和
（2）方程 f[i][j] = min(f[i][j-1], f[i-1][j]) + cur[i][j]
（3）初始化：[0][j]和[i][0]，累加即可
（4）答案：f[size - 1][[0].size-1]

### 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        vector<vector<int>> vec(grid.size(), vector<int>(grid[0].size()));
        //初始化[0][j]和[i][0]
        vec[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); i++) {
            vec[i][0] = vec[i - 1][0] + grid[i][0];
            cout<<i<<":"<<vec[i][0]<<endl;
        }
        cout<<"....................."<<endl;
        for (int j = 1; j < grid[0].size(); j++) {
            vec[0][j] = vec[0][j - 1] + grid[0][j];
            cout<<j<<":"<<vec[0][j]<<endl;
        }
        cout<<"....................."<<endl;
        // 状态转义函数 f[i][j] = min(f[i-1][j],f[i][j-1]) + 1;
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[0].size(); j++) {
                vec[i][j] = min(vec[i][j - 1], vec[i - 1][j]) + grid[i][j];
                cout<<"("<<i<<","<<j<<")"<<":"<<vec[i][j]<<endl;
            }
        }
        // 输出 f[grid.size()][grid[0].size()]
        
        return vec[grid.size() - 1][grid[0].size() - 1];
    }
};
```