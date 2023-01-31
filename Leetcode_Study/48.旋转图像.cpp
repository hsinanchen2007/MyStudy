/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

/*

https://leetcode.cn/problems/rotate-image/

48. 旋转图像

中等
1.5K
company
亚马逊
company
思科 Cisco
company
彭博 Bloomberg
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]

示例 2：

输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]] 

提示：

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000

*/

// @lc code=start
class Solution100 {
public:
    // 2023.1.30, from https://walkccc.me/LeetCode/problems/0048/
    void rotate(vector<vector<int>>& matrix) {
        reverse(begin(matrix), end(matrix));
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = i + 1; j < matrix.size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};

class Solution99 {
public:
    // 作者：yxc
    // 链接：https://www.acwing.com/solution/content/123/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    /*
        算法
        (操作分解) O(n2)
        直接操作旋转 90∘
        比较困难，我们可以将它分解成两个操作：

        1. 先以左上-右下对角条线为轴做翻转；
        2. 再以中心的竖线为轴做翻转；

        时间复杂度：O(n2)
        额外空间：O(1)    
    */
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i ++ )
            for (int j = i + 1; j < n; j ++ )
                swap(matrix[i][j], matrix[j][i]);
        for (int i = 0; i < n; i ++ )
            for (int j = 0, k = n - 1;
                    j < k; j ++, k -- )
                swap(matrix[i][j], matrix[i][k]);
    }
};


class Solution98 {
public:
    // 2023.1.30, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/rotate-image.cpp
    // Time:  O(n^2)
    // Space: O(1)
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - 1 - i; ++j) {
                const auto tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1- j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};


class Solution {
public:
    // 2023.1.30, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/rotate-image.cpp
    // Time:  O(n^2)
    // Space: O(1)
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        // Anti-diagonal mirror.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
        // Horizontal mirror.
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }  
    }
};


// @lc code=end

