### 解题思路
1. 总体思路：距离最近的0，换个思路也就是从0开始遍历周围，遇到非0则加1。把原始矩阵中的1设成最大值，这道题的思路就转换成了，遍历每个节点周围大于自己的数，如有，则起始节点+1后赋值给周围的节点
2. 具体步骤：1）矩阵中值为0的作为起始点push到队列q，为1的设置成最大值INT_MAX
            2）遍历队列q的元素，即从起始点开始，向4个方向扩展生成目标节点。如果目标节点在矩阵范围内，而且大于起始点，则把起始点+1赋值给目标节点，该目标节点入队列。
            3）队列为空后，返回节点矩阵。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int l = matrix[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < l; j++) {
                if (matrix[i][j] == 0) {
                    q.push(make_pair(i, j));
                    continue;
                }
                matrix[i][j] = INT_MAX;
            }
        }

        vector<pair<int, int>> fx = { {0,1},{0,-1},{1,0},{-1,0} };
        while (!q.empty()) {
            int x1 = q.front().first;
            int y1 = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = x1 + fx[i].first;
                int y = y1 + fx[i].second;
                if (x >= 0 && x < r&&y >= 0 && y<l&&matrix[x][y]>matrix[x1][y1]) {
                    matrix[x][y]=(matrix[x1][y1]+1);
                    q.push({x,y});
                }
            }
        }
        return matrix;
    }
};
```