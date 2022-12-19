执行用时 : 196 ms, 在Image Smoother的C++提交中击败了98.60% 的用户
内存消耗 : 18.9 MB, 在Image Smoother的C++提交中击败了35.45% 的用户

```c++
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        
        int row = M.size();
        if (row == 0) return {};
        int col = M[0].size();
        if (col == 0) return {};
        
        vector<vector<int>> sum(row + 1, vector<int>(col + 1, 0));
        
        for (int j = 0; j < col;  j++) sum[1][j + 1] = sum[1][j] + M[0][j];
        for (int i = 1; i < row;  i++)
        {
            int t = 0;
            for (int j = 0;  j < col;  j++)
            {  
                t = t + M[i][j];
                sum[i + 1][j + 1] = sum[i][j + 1] + t;
            }
        }
        
        for (int i = 0;  i < row;  i++)
            for (int j = 0;  j < col;  j++)
            {
                int x1 = j - 1;
                if (x1 < 0) x1 = 0;
                int y1 = i - 1;
                if (y1 < 0) y1 = 0;
                int x2 = j + 1;
                if (x2 >= col) x2 = col - 1;
                int y2 = i + 1;
                if (y2 >= row) y2 = row - 1;
                int n = (y2 - y1 + 1) * (x2 - x1 + 1);
                int t = sum[y2 + 1][x2 + 1] - sum[y2 + 1][x1] - sum[y1][x2 + 1] + sum[y1][x1];
                M[i][j] = t / n;
            }
        
        return M; 
    }
};