题目描述有点问题, 但推测揣摩一下基本知道意思了. 
方法1: 用BFS的方法将所有陆地依次传染给海洋, 使得海洋变成陆地, 传染到不能传染时的最后步数(层数)即结果(x方向和y方向移动的总长度)
方法2: 动态规划, 正向和反向二维扫描地推求结果

动态规划方法:
```
class Solution {
public:

    int rowNum;
    int colNum;
    vector<vector<int>> minDis;

    int maxDistance(vector<vector<int>>& grid)
    {
        rowNum = grid.size();
        if (rowNum == 0) {
            return -1;
        }
        colNum = grid[0].size();
        if (colNum == 0) {
            return -1;
        }

        minDis.assign(rowNum, vector<int>(colNum, INT_MAX));   // minDis数组代表每个点离各个陆地的距离中的最小值, 初始为INT_MAX

        int farstDis = 0;
        int landNum = 0;
        for (int x = 0; x < rowNum; x++) {
            for (int y = 0; y < colNum; y++) {
                if (grid[x][y] == 1) {
                    landNum++;
                    minDis[x][y] = 0;   // 每个陆地距离陆地的最近距离必然为0
                }
            }
        }
        if (landNum == 0 || landNum == rowNum * colNum) {  // 没有陆地或全是陆地
            return  -1;
        }

        for (int x = 0; x < rowNum; x++) {
            for (int y = 0; y < colNum; y++) {    // 正向扫描, 总是跟当前位置偏小的位置去比(比当前位置大的位置在下面的反向扫描里比)
                if (x >= 1 && minDis[x - 1][y] != INT_MAX) {
                    minDis[x][y] = min(minDis[x][y], minDis[x - 1][y] + 1);
                }
                if (y >= 1 && minDis[x][y - 1] != INT_MAX) {
                    minDis[x][y] = min(minDis[x][y], minDis[x][y - 1] + 1);
                }
            }
        }

        for (int x = rowNum - 1; x >= 0; x--) {
            for (int y = colNum - 1; y >= 0; y--) {   // 反向扫描, 看还有没有可能刷新每个点的最小值
                if (x <= rowNum - 2 && minDis[x + 1][y] != INT_MAX) {
                    minDis[x][y] = min(minDis[x][y], minDis[x + 1][y] + 1);
                }
                if (y <= colNum - 2 && minDis[x][y + 1] != INT_MAX) {
                    minDis[x][y] = min(minDis[x][y], minDis[x][y + 1] + 1);
                }

                farstDis = max(farstDis, minDis[x][y]);  // 在所有的最小距离里找最大值, 最大值即最早要返回的结果.
            }
        }
        return ((farstDis == 0 || farstDis == INT_MAX) ? -1 : farstDis);
    }
};
```
