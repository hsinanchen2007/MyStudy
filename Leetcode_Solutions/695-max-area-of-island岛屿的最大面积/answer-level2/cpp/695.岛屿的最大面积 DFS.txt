这位老兄的讲解还可以，其实不用标注为2，只需要将1置位0就行了
https://leetcode-cn.com/problems/max-area-of-island/solution/fang-ge-lei-dfs-de-jian-dan-fang-fa-cjava-by-nette/

```
class Solution {
public:
    int backTrace(vector<vector<int>>& grid, int i, int j)
    {
        if (!(i >= 0 && i < grid.size() && j >=0 && j < grid[0].size())) {
            return 0;
        }

        if (grid[i][j] == 1) {
            grid[i][j] = 0;
            return 1 + backTrace(grid, i + 1, j) + backTrace(grid, i - 1, j) + backTrace(grid, i, j + 1) + backTrace(grid, i, j - 1);
        }

        return 0;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row, colu;
        int maxArea = 0;
        for (row = 0; row < grid.size(); row++) {
            for (colu = 0; colu < grid[0].size(); colu++) {
                maxArea = max(maxArea, backTrace(grid, row, colu));
            }
        }

        return maxArea;
    }
};
```
