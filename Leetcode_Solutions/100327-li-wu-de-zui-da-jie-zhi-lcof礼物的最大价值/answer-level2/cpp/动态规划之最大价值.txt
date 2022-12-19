# 1. 思路
一看到这道题我想到的是最短路径和问题，和这道题非常相似。我试着以相同的思路来解这道题，发现这道题要更简单一点，简单的迭代更新每一层的数即可。为了避免边界判断，我还是习惯性的边界补0，尽管这可能会带来额外的一些内存开销。
迭代操作非常简单，因为路径只有两个方向的选择，将每个位置右边和下边紧邻的数两者较大的加到当前位置。
# 2. 代码
1. 二维数组边界补0
2. 从下向上，从右向左依次迭代，grid[i][j] += max(grid[i+1][j],grid[i][j+1])
```c++ []
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();
        for(auto& line : grid){
            line.insert(line.begin(), 0);
            line.push_back(0);
        }
        grid.insert(grid.begin(), vector<int>(column+2, 0));
        grid.push_back(vector<int>(column+2, 0));

        for(int i=row; i>0; i--){
            for(int j=column; j>0; j--){
                grid[i][j] += max(grid[i+1][j],grid[i][j+1]);
            }
        }
        return grid[1][1];
    }
};
```
# 3. 总结
典型的动态规划题，和最短路径和类似。