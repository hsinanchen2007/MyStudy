### 解题思路
写的代码有些复杂，根本思路是 
1） 首先创建一个和grid一样大小的record，保证访问过的节点不会再被访问；
2） 开始遍历每个节点，若这个节点没有被访问过，而且值为1，则进入findLand函数；
3） 这里会将Number+1, 然后将这个节点设为1， 接着会对这四个方向依次遍历 （深度优先）
4) 最后返回number , 和max比较

### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        int max = 0;
        vector<vector<int> > record(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                int number = 0;
                if (record[i][j] == 0 && grid[i][j] == 1) {
                    findLand(grid, i, j, record, number);
                    //record[i][j] = 1;
                    //number ++;
                }
                if (number > max) {
                    max = number;
                }
            }
        }
        return max;
    }

    void findLand(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& record, int& number) {
        record[i][j] = 1; 
        number ++;
        if (i - 1 >= 0 && record[i-1][j] == 0 && grid[i-1][j] == 1) {
            findLand(grid, i - 1, j, record, number);
        }
        if (j - 1 >= 0 && record[i][j -1] == 0 && grid[i][j-1] == 1){
            findLand(grid, i, j - 1, record, number);
        }
        if (i + 1 < grid.size() && record[i+1][j] == 0 && grid[i+1][j] == 1) {
            findLand(grid, i + 1, j, record, number);
        }
        if (j + 1 < grid[0].size() && record[i][j+1] == 0 && grid[i][j+1] == 1) {
            findLand(grid, i, j + 1, record, number);
        }
    }
};
```