# 核心思想
暴力破解，先数边长sideLen为1的小正方形有几个，然后数边长为2的小正方形，...，最后数边长min(m, n)的小正方形有几个。**以每个小正方形左上角的坐标(x, y)为基点**。

当小正方形边长为sideLen时，基点所需要遍历的坐标范围是x = [0, m-(sideLen-1)]，y = [0, n-(sideLen-1)]。checkSquare为校验函数，其目的是校验基点为(x, y)时，边长为sideLen的正方形是否存在。
```
class Solution {
public:
    bool checkSquare(int x, int y, int sideLen, vector<vector<int>>& matrix) {
        if (sideLen == 1) {
            return matrix[x][y] == 1;
        }
        for (int i = 0; i < sideLen; i++) {
            for (int j = 0; j < sideLen; j++) {
                if (x+i >= matrix.size() || y+j >= matrix[0].size()) {
                    return false;
                }
                if (matrix[x + i][y + j] != 1) {
                    return false;
                }
            }
        }
        return true;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        int maxSideLen = min(m, n);
        for (int sideLen = 1; sideLen <= maxSideLen; sideLen++) {
            for (int x = 0; x < m-(sideLen-1); x++) {
                for (int y = 0; y < n-(sideLen-1); y++) {
                    if (checkSquare(x, y, sideLen, matrix)) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};
```