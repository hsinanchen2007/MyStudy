/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

/*

https://leetcode.cn/problems/search-a-2d-matrix/

74. 搜索二维矩阵
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
 

示例 1：

输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true

示例 2：

输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
通过次数248,883提交次数521,017

*/

// @lc code=start
class Solution100 {
public:
    // 2022.7.10, by Hsinan. Convert m*n 2D array into one, sort then use 
    // C++ STL's find to see if the given target existed in the matrix or not
    // this is a solution without using binary search
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> all;

        // convert 2D arrary into one vector
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                all.push_back(matrix[i][j]);
            }
        }

        // sort and find the target
        sort(all.begin(), all.end());
        auto answer = std::find(all.begin(), all.end(), target);

        // return
        return (answer == all.end()? false : true);
    }
};


class Solution99 {
public:
    // 2022.7.10, from 程序员吴师兄
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 搜索二维矩阵（ LeetCode 74 ）: https://leetcode-cn.com/problems/search-a-2d-matrix/ 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 从数组的最左下角位置开始去搜索整个二维数组
        // 1、当发现当前遍历的元素大于 target 时，意味着这个元素后面的所有元素也都大于 target
        // 那么就不用去搜索这一行了
        // 2、当发现当前遍历的元素小于 target 时，意味着这个元素上面的所有元素也都小于 target
        // 那么就不用去搜索这一列了

        // 初始化 i 和 j 为数组左下角元素
        // 最后一行
        int i = matrix.size() - 1;

        // 第 0 列
        int j = 0;

        // 从数组的左下角开始出发，只要 i 和 j 没有越界继续判断
        while(i >= 0 && j < matrix[0].size()){
            
            // 当发现当前遍历的元素大于 target 时，意味着这个元素后面的所有元素也都大于 target
            if(matrix[i][j] > target){

                // 行索引向上移动一格（即 i-- ），即消去矩阵第 i 行元素
                i--;
            
            // 当发现当前遍历的元素小于 target 时，意味着这个元素上面的所有元素也都小于 target
            }else if(matrix[i][j] < target){

                //列索引向右移动一格（即 j++ ），即消去矩阵第 j 列元素
                j++;

            // 否则，说明找到目标值
            }else{

                // 直接返回 ture
                return true;
            }     
        }

        // 遍历了整个二维数组，没有找到目标值，返回 false
        return false;
    }
};


class Solution98 {
public:
    // 2022.7.10, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/search-a-2d-matrix.cpp
    // Time:  O(logm + logn)
    // Space: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        // Treat matrix as 1D array.
        const int m = matrix.size();
        const int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;

        // Find min of left s.t.  matrix[left / n][left % n] >= target
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid / n][mid % n] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // Check if matrix[left / n][left % n] equals to target.
        if (left != m * n && matrix[left / n][left % n] == target) {
            return true;
        }

        return false;
    }
};


class Solution97 {
public:
    // 2022.7.10, from AcWing
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/370359/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int n = matrix.size(), m = matrix[0].size();

        int l = 0, r = n * m - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (matrix[mid / m][mid % m] >= target) r = mid;
            else l = mid + 1;
        }

        return matrix[r / m][r % m] == target;
    }
};


class Solution96 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/74.%20Search%20a%202D%20Matrix
    // OJ: https://leetcode.com/problems/search-a-2d-matrix/
    // Author: github.com/lzl124631x
    // Time: O(log(MN))
    // Space: O(1)
    bool searchMatrix(vector<vector<int>>& A, int target) {
        if (A.empty() || A[0].empty()) return false;
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M][0] == target) return true;
            if (A[M][0] < target) L = M + 1;
            else R = M - 1;
        }
        if (R == -1) return false;
        int row = R;
        L = 0, R = A[0].size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[row][M] == target) return true;
            if (A[row][M] < target) L = M + 1;
            else R = M - 1;
        }
        return false;
    }
};


class Solution95 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/74.%20Search%20a%202D%20Matrix
    // OJ: https://leetcode.com/problems/search-a-2d-matrix/
    // Author: github.com/lzl124631x
    // Time: O(log(MN))
    // Space: O(1)
    // L <= R template:
    bool searchMatrix(vector<vector<int>>& A, int target) {
        int M = A.size(), N = A[0].size(), L = 0, R = M * N - 1;
        while (L <= R) {
            int M = (L + R) / 2, i = M / N, j = M % N;
            if (A[i][j] == target) return true;
            if (A[i][j] < target) L = M + 1;
            else R = M - 1;
        }
        return false;
    }

    /*
    // L < R template:
    class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& A, int target) {
            int M = A.size(), N = A[0].size(), L = 0, R = M * N - 1;
            while (L < R) {
                int M = (L + R) / 2, i = M / N, j = M % N;
                if (A[i][j] < target) L = M + 1;
                else R = M;
            }
            return A[L / N][L % N] == target;
        }
    };
    */
};


class Solution94 {
public:
    // 2.220.7.25, from https://walkccc.me/LeetCode/problems/0074/
    // Time: O(mnlogmn)
    // Space: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
        return false;

        const int m = matrix.size();
        const int n = matrix[0].size();
        int l = 0;
        int r = m * n;

        while (l < r) {
        const int mid = (l + r) / 2;
        const int i = mid / n;
        const int j = mid % n;
        if (matrix[i][j] == target)
            return true;
        if (matrix[i][j] < target)
            l = mid + 1;
        else
            r = mid;
        }

        return false;
    }
};


class Solution93 {
public:
    // 2022.7.25, from https://www.guozet.me/leetcode/Leetcode-74-Search-a-2D-Matrix.html?h=searchmatrix
    // Time complexity: O(log(row*col)), Space complexity: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        const int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = row * col;

        // Binary Search: No repeat elements.
        while (left < right) {
            int mid = left + (right - left) / 2;
            int mid_val = matrix[mid / col][mid % col];
            if (mid_val == target) return true;
            else if ( mid_val < target) left = mid + 1;
            else right = mid;
        }
        return false;
    }
};


class Solution92 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/74
    /*
        这道题要求搜索一个二维矩阵，由于给的矩阵是有序的，所以很自然的想到要用二分查找法，可以在第一列上先用
        一次二分查找法找到目标值所在的行的位置，然后在该行上再用一次二分查找法来找是否存在目标值。对于第一个
        二分查找，由于第一列的数中可能没有 target 值，该如何查找呢，是博主之前的总结帖 LeetCode Binary 
        Search Summary 二分搜索法小结 中的哪一类呢？如果是查找第一个不小于目标值的数，当 target 在第一列
        时，会返回 target 所在的行，但若 target 不在的话，有可能会返回下一行，不好统一。所以可以查找第一个
        大于目标值的数，也就是总结帖中的第三类，这样只要回退一个，就一定是 target 所在的行。但需要注意的一点
        是，如果返回的是0，就不能回退了，以免越界，记得要判断一下。找到了 target 所在的行数，就可以再次使用
        二分搜索，此时就是总结帖中的第一类了，查找和 target 值相同的数，也是最简单的一类，分分钟搞定即可，
        参见代码如下：

        解法一：
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int left = 0, right = matrix.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (matrix[mid][0] == target) return true;
            if (matrix[mid][0] < target) left = mid + 1;
            else right = mid;
        }
        int tmp = (right > 0) ? (right - 1) : right;
        left = 0;
        right = matrix[tmp].size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (matrix[tmp][mid] == target) return true;
            if (matrix[tmp][mid] < target) left = mid + 1;
            else right = mid;
        }
        return false;
    }
};


class Solution91 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/74
    /*
        当然这道题也可以使用一次二分查找法，如果我们按S型遍历该二维数组，可以得到一个有序的一维数组，
        只需要用一次二分查找法，而关键就在于坐标的转换，如何把二维坐标和一维坐标转换是关键点，把一个
        长度为n的一维数组转化为 mn 的二维数组 (mn = n)后，那么原一维数组中下标为i的元素将出现在二维数
        组中的 [i/n][i%n] 的位置，有了这一点，代码很好写出来了：

        解法二：
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n;
        while (left < right) {
            int mid = (left + right) / 2;
            if (matrix[mid / n][mid % n] == target) return true;
            if (matrix[mid / n][mid % n] < target) left = mid + 1;
            else right = mid;
        }
        return false;
    }
};


class Solution90 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/74
    /*
        这道题其实也可以不用二分搜索法，直接使用双指针也是可以的，i指向0，j指向列数，这样第一个被验证
        的数就是二维数组右上角的数字，假如这个数字等于 target，直接返回 true；若大于 target，说明要
        减小数字，则列数j自减1；若小于 target，说明要增加数字，行数i自增1。若 while 循环退出了还是
        没找到 target，直接返回 false 即可，参见代码如下：

        解法三：
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int i = 0, j = (int)matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) --j;
            else ++i;
        }   
        return false;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


class Solution89 {
public:
    // 2022.8.2, by Hsinan
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int row = 0; row < matrix.size(); row++) {
            if (binary_search(matrix[row].begin(), matrix[row].end(), target)) return true;
        }
        return false;
    }
};


class Solution {
public:
    // 2022.8.2, by Hsinan
    // lower_bound() will find the first value <= target
    // while upper_bound() will find the first value > target
    // so when we use this way to find target, better use lower_bound()
    // and we can use (*iterator == target) to do final check
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int row = 0; row < matrix.size(); row++) {
            auto lower = lower_bound(matrix[row].begin(), matrix[row].end(), target);
            if ((lower != matrix[row].end()) && (*lower == target)) {
                return true;
            }
        }
        return false;
    }
};

// @lc code=end

