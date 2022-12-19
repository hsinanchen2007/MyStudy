### 解题思路

这是一道动态规划的题目，递归方程是`opt[j][i] = opt[j-1][i] + opt[j][i-1];`

最开始提交的代码如下，用的是容器分配二维数组`vector<vector<int>> opt(m, vector<int>(n,1));`

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> opt(m, vector<int>(n,1));

        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                opt[i][j] = opt[i-1][j] + opt[i][j-1];
            }
        }

        return opt  [m-1][n-1];

    }
};
```

最后AC的速度是8ms，我以为挺快的，结果垫底。然后看了下别人直接定义了一个100x100的二维数组，我把原来的代码修改之后（如下），果然只需要0ms。


```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int opt[100][100];
        for ( int i = 0 ;i <m; i++){
            opt[0][i] = 1;
        }
        for(int j = 0; j < n; j++){
            opt[j][0] = 1;

        }
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                opt[j][i] = opt[j-1][i] + opt[j][i-1];
            }
        }
        return opt[n-1][m-1];
    

    }
};
```

这个提速是建立在题目说明中，m和n最大是100的基础上。