```
class Solution {
public:
    int uniquePaths(int m, int n) {
        // 1. 数学方法 -> 其实就是两种动作的组合问题：
        // 到达终点就是向右走m-1步，向下走n-1步，向右和向下两种动作的组合就是路径数
        // pathNum = C(m+n-2, m-1);
        // 溢出，就不考虑解决方案了
        //return multiply(m, m+n-2)/factorial(n-1);
        
        // 问题和子问题的的推关系：pathNum[i][j] = path[i-1][j] + path[i][j-1];
        // 两种方法：1、自顶向下——递归+备忘录优化
        //          2、自底向上——动态规划（迭代）
        
        /*
        // 递归+备忘录
        vector<vector<int>> pathNum(n, vector<int>(m, -1));
        return getPathNum(n-1, m-1, pathNum);
        */
        
        // 动态规划
        vector<vector<int>> pathNum(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || j == 0) pathNum[i][j] = 1;
                else pathNum[i][j] = pathNum[i-1][j] + pathNum[i][j-1];
            }
        }
        
        return pathNum[n-1][m-1];
    }
    
    int getPathNum(int i, int j, vector<vector<int>>& pathNum) {
        // 从 (0, 0) 到 (i, j) 的路径数
        if (i == 0 || j == 0) return 1;
        
        if (pathNum[i][j] != -1) return pathNum[i][j];
        
        
        pathNum[i][j] = getPathNum(i, j-1, pathNum) + getPathNum(i-1, j, pathNum);
        
        return pathNum[i][j];
    }
    
};
```
