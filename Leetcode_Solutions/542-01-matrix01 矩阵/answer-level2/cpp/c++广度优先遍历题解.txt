写了一个简单粗暴的算法，整体比较简单，就是对矩阵中每个为1的元素进行bfs广度优先搜索，搜索的时候记录搜索的深度，这样搜到第一个零的时候直接返回当前深度，结束搜索，visit数组用一维数组代替，二维数组不知道多少行多少列。

该算法虽然过了，但是总干觉比较暴力，求更加简洁高效算法。

```
#include <queue>

using namespace std;

#define NDIR 4

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> res(matrix);
        int i = 0, j = 0;
        
        for (i = 0; i < rows; i++) {
            for (j = 0; j < matrix[i].size(); j++) {
                memset(visit, 0, sizeof(visit));
                if (matrix[i][j] == 1) {
                    res[i][j] = bfs(matrix, i, j, cols);
                } else {
                    res[i][j] = 0;
                }
            }
        }
        
        return res;
    }
private:
    int bfs(vector<vector<int>> &matrix, int x, int y, int cols) {
        queue<int> que;
        int i = 0;
        int tx = 0, ty = 0, depth = 0;
        
        que.push(x);
        que.push(y);
        que.push(0);
        
        while (!que.empty()) {
            x = que.front();
            que.pop();
            y = que.front();
            que.pop();
            depth = que.front();
            que.pop();
            
            for (i = 0; i < NDIR; i++) {
                tx = x + dirs[i][0];
                ty = y + dirs[i][1];
                
                if (tx < 0 || tx >= matrix.size() || ty < 0 || ty >= matrix[tx].size() || visit[tx * cols + ty])
                    continue;
                
                if (matrix[tx][ty] == 0)
                    return depth + 1;
                
                visit[tx * cols + ty] = true;
                que.push(tx);
                que.push(ty);
                que.push(depth + 1);
            }
        }
        
        return 0;
    }
    int dirs[NDIR][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool visit[10001];
};
```


[格式化的代码链接](http://www.iaccepted.net/algorithm/leetcode/211.html)