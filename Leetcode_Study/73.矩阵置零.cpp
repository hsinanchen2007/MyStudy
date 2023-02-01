/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

/*

https://leetcode.cn/problems/set-matrix-zeroes/

73. 矩阵置零

中等
827
company
亚马逊
company
彭博 Bloomberg
company
微软 Microsoft
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

示例 1：

输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]

示例 2：

输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]] 

提示：

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 
进阶：

一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个仅使用常量空间的解决方案吗？

*/

// @lc code=start
class Solution100 {
public:
    // 2023.1.31, from https://walkccc.me/LeetCode/problems/0073/
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        bool shouldFillFirstRow = false;
        bool shouldFillFirstCol = false;

        for (int j = 0; j < n; ++j)
            if (matrix[0][j] == 0) {
                shouldFillFirstRow = true;
                break;
            }

        for (int i = 0; i < m; ++i)
            if (matrix[i][0] == 0) {
                shouldFillFirstCol = true;
                break;
            }

        // Store the information in the 1st row/col
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }

        // Fill 0s for the matrix except the 1st row/col
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        // Fill 0s for the 1st row if needed
        if (shouldFillFirstRow)
            for (int j = 0; j < n; ++j)
                matrix[0][j] = 0;

        // Fill 0s for the 1st col if needed
        if (shouldFillFirstCol)
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
    }
};


class Solution {
public:
    // 作者：风清云淡
    // 链接：https://leetcode.cn/leetbook/read/array-and-string/ciekh/?discussion=P792EH
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size();
        unordered_set<int>zero_row,zero_col;
        for(int i=0;i<rows;++i)
            for(int j=0;j<cols;++j)
                if(!matrix[i][j])
                {
                    zero_row.insert(i);
                    zero_col.insert(j);
                }
        for(auto i:zero_row)
            for(int j=0;j<cols;++j)
                matrix[i][j]=0;
        for(auto j:zero_col)
            for(int i=0;i<rows;++i)
                matrix[i][j]=0;
    }
};


// @lc code=end

