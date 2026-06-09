找一个合理的角点，如左下，或者右上。这样子沿一条边增长，沿另外一条边减小。
并且比较阴的其实是，第一点，如果想不到需要考虑给你一个空的矩阵，就槽糕。
另外，还有一点，就是while大循环后边不要忘记也有一个， return false啦哈哈哈。

```
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 考虑极端情形。
        if (matrix.size() == 0){
            return false;
        }
        
        // 我认为这道题主要是给你机会让你认识到vector二维数组如何handle。
        int nrows = matrix.size();
        int ncols = matrix[0].size();

        int row = 0;
        int col = ncols-1;

        while(row<nrows && col >= 0){
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target)
                row++;
            else if(matrix[row][col] > target)
                col--;
        }
        return false;
    }
};
```
