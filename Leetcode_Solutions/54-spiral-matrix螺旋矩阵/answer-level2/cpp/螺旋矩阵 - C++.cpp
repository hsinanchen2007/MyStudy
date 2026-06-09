```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;
        
        int M = matrix.size();                      // 行数
        int N = matrix[0].size();                   // 列数
        int left=0, right=N-1, up=0, down=M-1;      // 边界
        
        while (true) {
            // 遍历上边界
            for (int i=left; i <= right; i++)
                res.push_back(matrix[up][i]);
            // 重置上边界
            if (++up > down) break;
            // 遍历右边界
            for (int i=up; i <= down; i++)
                res.push_back(matrix[i][right]);
            // 重置右边界
            if (--right < left) break;
            // 遍历下边界
            for (int i=right; i >= left; i--)
                res.push_back(matrix[down][i]);
            // 重置下边界
            if (--down < up) break;
            // 遍历左边界
            for (int i=down; i >= up; i--)
                res.push_back(matrix[i][left]);
            // 重置左边界
            if (++left > right) break;
        }
        return res;
    }
};
```
