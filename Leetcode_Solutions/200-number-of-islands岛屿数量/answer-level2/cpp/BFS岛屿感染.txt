class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    islandCount++;
                    Infect(grid, i, j);
                }
            }
        }
        return islandCount;
    }
    void Infect(vector<vector<char>>& grid, int rowIndex, int columnIndex)
    {
        if (rowIndex < 0 || rowIndex >= grid.size() || columnIndex < 0 || columnIndex >= grid[0].size()) {
            return;
        }
        if (grid[rowIndex][columnIndex] == '1') {
            grid[rowIndex][columnIndex] = '0';
            Infect(grid, rowIndex - 1, columnIndex);
            Infect(grid, rowIndex + 1, columnIndex);
            Infect(grid, rowIndex, columnIndex + 1);
            Infect(grid, rowIndex, columnIndex - 1); 
        }
    }
};