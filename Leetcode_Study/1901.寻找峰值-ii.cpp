/*
 * @lc app=leetcode.cn id=1901 lang=cpp
 *
 * [1901] 寻找峰值 II
 */

/*

https://leetcode.cn/problems/find-a-peak-element-ii/

1901. 寻找峰值 II
一个 2D 网格中的 峰值 是指那些 严格大于 其相邻格子(上、下、左、右)的元素。

给你一个 从 0 开始编号 的 m x n 矩阵 mat ，其中任意两个相邻格子的值都 不相同 。找出 任意一个 峰值 mat[i][j] 并 返回其位置 [i,j] 。

你可以假设整个矩阵周边环绕着一圈值为 -1 的格子。

要求必须写出时间复杂度为 O(m log(n)) 或 O(n log(m)) 的算法

示例 1:

输入: mat = [[1,4],[3,2]]
输出: [0,1]
解释: 3 和 4 都是峰值，所以[1,0]和[0,1]都是可接受的答案。

示例 2:

输入: mat = [[10,20,15],[21,30,14],[7,16,32]]
输出: [1,1]
解释: 30 和 32 都是峰值，所以[1,1]和[2,2]都是可接受的答案。
 

提示：

m == mat.length
n == mat[i].length
1 <= m, n <= 500
1 <= mat[i][j] <= 105
任意两个相邻元素均不相等.
通过次数4,765提交次数8,104

*/

// @lc code=start
class Solution100 {
public:
    // 2022.8.7 from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1901.%20Find%20a%20Peak%20Element%20II
    // OJ: https://leetcode.com/problems/find-a-peak-element-ii/
    // Author: github.com/lzl124631x
    // Time: O(NlogM)
    // Space: O(1)
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int M = mat.size(), N = mat[0].size(), L = 0, R = M - 1;
        while (L < R) {
            int mid = (L + R + 1) / 2;
            int left = mid - 1 >= 0 ? *max_element(begin(mat[mid - 1]), end(mat[mid - 1])) : -1;
            int cur = *max_element(begin(mat[mid]), end(mat[mid]));
            if (cur > left) L = mid;
            else R = mid - 1;
        }
        return { L, int(max_element(begin(mat[L]), end(mat[L])) - begin(mat[L])) };
    }
};


class Solution99 {
public:
    // 2022.8.7, from https://github.com/wisdompeak/LeetCode/blob/master/Binary_Search/1901.Find-a-Peak-Element-II/1901.Find-a-Peak-Element-II.cpp
    /*
        本题的思路非常巧妙。我们搜一行max_mid，查看该行的最大值max_mid. 同时查看该行上一行的最大值max_upper，
        该行下一行的最大值max_lower。如果max_mid是三者中的最大，那么根据大小比较的传递性，max_mid肯定比它的上
        一格大，因为max_mid大于upper_mid，而upper_mid是上一行中的最大值。同理，max_mid也比它的下一个大。所以
        max_mid一定是一个峰值。

        如果max_upper是三者中的最大，那么我们就将峰值所在行的搜索范围调整为[low, mid-1];反之，如果max_lower
        是三者中的最大，那么我们就将峰值所在行的搜索范围调整为[mid+1,high].

        本题一定有解，所以当while (low<high)退出时，low所在行的最大值就一定是峰值。
    */
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int up = 0, low = m-1;
        while (up <= low)
        {
            int mid = up+(low-up)/2;
                        
            int upper_max = mid==0 ? -1 : *max_element(mat[mid-1].begin(), mat[mid-1].end());
            int mid_max = *max_element(mat[mid].begin(), mat[mid].end());
            int lower_max = mid==m-1 ? -1 : *max_element(mat[mid+1].begin(), mat[mid+1].end());
            
            int mx = max(upper_max, max(mid_max, lower_max));
            if (mx == mid_max)
                return {mid, int(max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin())};
            else if (mx == upper_max)
                low = mid - 1;
            else
                up = mid + 1;                        
        }
        
        return {-1, -1};
    }
};


class Solution98 {
public:
    // 2022.8.7, from https://walkccc.me/LeetCode/problems/1901/
    // Time: O(nlogm)
    // Space: O(1)
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l = 0;
        int r = mat.size() - 1;

        while (l < r) {
        const int m = (l + r) / 2;
        if (*max_element(begin(mat[m]), end(mat[m])) >=
            *max_element(begin(mat[m + 1]), end(mat[m + 1])))
            r = m;
        else
            l = m + 1;
        }

        return {l, getMaxIndex(mat[l])};
    }

private:
    int getMaxIndex(const vector<int>& A) {
        pair<int, int> res{0, A[0]};
        for (int i = 1; i < A.size(); ++i)
        if (A[i] > res.second)
            res = {i, A[i]};
        return res.first;
    }
};


class Solution97 {
public:
    // 2022.8.7, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/find-a-peak-element-ii.cpp
    // Time:  O(min(n, m) * log(max(n, m)))
    // Space: O(1)
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int left = 0, right = (max(size(mat), size(mat[0])) - 1) - 1;
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (check(mat, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        vector<int> result = {left, find_max(mat, left).first};
        if (!(size(mat) > size(mat[0]))) {
            reverse(begin(result), end(result));
        }
        return result;
    }

private:
    bool check(const vector<vector<int>>& mat, int x) {
        return find_max(mat, x).second > find_max(mat, x + 1).second;
    }
    
    pair<int, int> find_max(const vector<vector<int>>& mat, int x) {
        pair<int, int> result = {-1, -1};
        for (int j = 0; j < min(size(mat), size(mat[0])); ++j) {
            if (result.first == -1 || result.second < get_val(mat, x, j)) {
                result = {j, get_val(mat, x, j)};
            }
        }
        return result;
    }

    int get_val(const vector<vector<int>>& mat, int i, int j) {
        return (size(mat) > size(mat[0])) ? mat[i][j] : mat[j][i];
    }
};


class Solution96 {
    // 2022.8.7, from https://github.com/liuyubobobo/Play-Leetcode/blob/master/1501-2000/1901-Find-a-Peak-Element-II/cpp-1901/main.cpp
    /// Brute Force
    /// Time Complexity: O(m*n)
    /// Space Complexity: O(1)
private:
    const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;

public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++){
                int d = 0;
                for(; d < 4; d ++)
                    if(in_area(i + dirs[d][0], j + dirs[d][1]) && mat[i + dirs[d][0]][j + dirs[d][1]] >= mat[i][j])
                        break;
                if(d == 4) return {i, j};
            }
        return {-1, -1};
    }

private:
    bool in_area(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};


class Solution95 {
public:
    // 2022.8.7, from https://leetcode.cn/problems/find-a-peak-element-ii/comments/
    // 温柔一刀123
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size(), column = mat[0].size(), low = 0, high = row - 1, middle = 0, cIndex = 0;

        while (low <= high) {
            middle = (low + high) / 2;

            int upMax = -1;
            if (middle != 0) {
                upMax = getRowMax(mat, middle - 1, cIndex);
            }

            int downMax = -1;
            if (middle != row - 1) {
                downMax = getRowMax(mat, middle + 1, cIndex);
            }

            int rowMax = getRowMax(mat, middle, cIndex);
            if (rowMax >= upMax && rowMax >= downMax) {
                break;
            }
            else if (upMax > rowMax) {
                high = middle - 1;
            }
            else {
                low = middle + 1;
            }
        }

        return { middle, cIndex };
    }

    int getRowMax(vector<vector<int>>& mat, int r, int& c) {
        int rowMax = 0;

        for (int j = 0; j < (int)mat[0].size(); ++j) {
            if (mat[r][j] > rowMax) {
                rowMax = mat[r][j];
                c = j;
            }
        }

        return rowMax;
    }
};


class Solution94 {
public:
    // 2022.8.7, from https://leetcode.cn/problems/find-a-peak-element-ii/comments/
    // 子非鱼
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(),n = mat[0].size();
        int up = 0, down= m-1;
        while(up<=down){
            int mid = (up+down)/2;
            int maxUp = mid==0?-1:*max_element(mat[mid-1].begin(),mat[mid-1].end());
            int maxBottom = mid+1==m?-1:*max_element(mat[mid+1].begin(),mat[mid+1].end());
            auto it = max_element(mat[mid].begin(),mat[mid].end());
            if(*it>=max(maxUp,maxBottom)){
                return {mid,int(it-mat[mid].begin())};
            }else if(maxUp>=max(*it,maxBottom)){
                down = mid;
            }else{
                up = mid+1;
            }
        }
        return {};
    }
};


class Solution93 {
public:
    // 作者：HUST_DHC
    // 链接：https://leetcode.cn/problems/find-a-peak-element-ii/solution/er-fen-cha-zhao-er-wei-shu-zu-zhao-ji-zh-hz8j/
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    /*
        二分查找
        思路：将二维数组按行分(也可按列分),利用二分确定目标行,初始化up = 0, down = m-1,即行的上下界
        在mid = (up + down) / 2所在行与其相邻的两行中,判断三行中的最大值(可能不止一个)是否存在于mid行中,如果是,
        那么该行的最大值就是二维情况下的极值,因为有条件约束,相邻的元素不相等,如果该行的最大值上下两行相邻的元素大于它
        ,那么它就不可能为三行中的最大值,又由于相邻元素不等,因此它周围的元素都小于它
    */
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(),n = mat[0].size();
        int up = 0, down= m-1;
        while(up <= down){
            int mid = (up + down) / 2;
            int maxUp = mid == 0 ? -1 : *max_element(mat[mid - 1].begin(), mat[mid - 1].end());
            int maxBottom = mid + 1 == m ? -1 : *max_element(mat[mid + 1].begin(), mat[mid + 1].end());
            auto it = max_element(mat[mid].begin(), mat[mid].end());
            if(*it >= max(maxUp, maxBottom)) {
                return {mid, int(it - mat[mid].begin())};
            }else if(maxUp >= max(*it, maxBottom)) {
                down = mid;
            }else{
                up = mid + 1;
            }
        }
        return {};
    }
};


class Solution92 { // 模板一：经典二分法
public:
    // 作者：sui-xin-yuan
    // 链接：https://leetcode.cn/problems/find-a-peak-element-ii/solution/by-sui-xin-yuan-ct3m/
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    /*
        前言
        2022年3月25日，有新增学习模块诞生：学习计划广场→专项突破→二分查找，我打算和同学们一起在未来的日子里拿下
        二分查找模块的所有徽章：

        学习计划	学习天数	题目难度
        二分查找入门	12	简单16 中等7 困难0
        二分查找基础	20	简单0 中等39 困难1
        二分查找进阶	23	简单4 中等14 困难29
        本题为二分查找基础第 1717 天第 22 题。

        这里我们用蓝红二分法进行二分查找，不熟悉的同学可以先看 34. 蓝红二分法单模板秒杀二分查找 。

        补充了经典二分查找模板代码。
        六款二分查找模板，哪款才是你的菜？

        解题思路
        由于数组可能有多个峰值，很难进行明确的蓝红划分，这里我们要思考二分查找相比线性查找的优势是什么？
        ①选择点跨度更大更加随机化。
        ②时间复杂度更低。
        我们利用①进行随机点选择，利用②加速线性查找。
        虽然有多个峰值，我们仍然可以进行局部二分查找进行夹逼。

        方法一：二分查找【通过】
        从左到右：C++（模板一：经典二分法、模板六：蓝红二分法）
    */
    int m;
    int maxValIdxInRow(vector<vector<int>>& mat, int row) {
        return static_cast<int>(max_element(mat[row].begin(), mat[row].end()) - mat[row].begin()) ;
    }
    int check(vector<vector<int>>& mat, int row) {
        int col = maxValIdxInRow(mat, row);
        if (row<m-1 && mat[row][col] < mat[row+1][col]) {
            return 1; // 局部单调增
        } else if (row>0 && mat[row][col] < mat[row-1][col]) {
            return -1; // 局部单调减
        } else {
            return 0; // 找到峰值
        }
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        m = (int)mat.size();
        int up = 0, down = m-1; // row ∈ [0,m-1]
        while (up <= down) {
            int mid = up+(down-up)/2;
            int res = check(mat, mid);
            if (res == 0) { // 找到峰值，返回结果
                return {mid, maxValIdxInRow(mat, mid)};
            } else if (res == 1) {  // 局部单调增
                up = mid+1; // 移动 up 指针缩小查找区间进行夹逼
            } else { // 局部单调减
                down = mid-1; // 移动 down 指针缩小查找区间进行夹逼
            }
        }
        return {-1,-1};
    }
};


class Solution91 { // 模板一：经典二分法
public:
    // 作者：sui-xin-yuan
    // 链接：https://leetcode.cn/problems/find-a-peak-element-ii/solution/by-sui-xin-yuan-ct3m/
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    /*
        方法二：二分查找 + 缓存优化【通过】
        很显然，方法一还有优化空间，我们发现 maxValIdxInRowmaxValIdxInRow 被反复调用，我们很容易知道，
        每行的最大值是固定的，查过了就没必要再查了，这里构建 memomemo 缓存。

        从左到右：C++（模板一：经典二分法、模板六：蓝红二分法）
    */
    int m;
    vector<int>memo;
    int maxValIdxInRow(vector<vector<int>>& mat, int row) {
        return static_cast<int>(max_element(mat[row].begin(), mat[row].end()) - mat[row].begin()) ;
    }
    int check(vector<vector<int>>& mat, int row) {
        int& col = memo[row];
        if (col == -1) {
            col = maxValIdxInRow(mat, row);
        }
        if (row<m-1 && mat[row][col] < mat[row+1][col]) {
            return 1; // 局部单调增
        } else if (row>0 && mat[row][col] < mat[row-1][col]) {
            return -1; // 局部单调减
        } else {
            return 0; // 找到峰值
        }
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        m = (int)mat.size();
        memo.resize(m,-1);
        int up = 0, down = m-1; // row ∈ [0,m-1]
        while (up <= down) {
            int mid = up+(down-up)/2;
            int res = check(mat, mid);
            if (res == 0) { // 找到峰值，返回结果
                return {mid, memo[mid]};
            } else if (res == 1) {  // 局部单调增
                up = mid+1; // 移动 up 指针缩小查找区间进行夹逼
            } else { // 局部单调减
                down = mid-1; // 移动 down 指针缩小查找区间进行夹逼
            }
        }
        return {-1,-1};
    }
};


class Solution {
public:
    // 2022.8.7, by Hsinan
    // stupid way to find max number so it will be the one guarantee that
    // bigger than all other numbers around, time O(m*n)
    // use answer to hold two numbers for (x, y), update them accordingly
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> answer = {-1, -1};
        int max = -1;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] > max) {
                    answer[0] = i;
                    answer[1] = j;
                    max = mat[i][j];
                }
            }
        }
        return answer;
    }
};


/*

因为是找到一个顶峰元素即可，那么，与其想顶峰元素是怎么样，不如想一个充分条件，也就是， 满足此条件，则一定是顶峰元素。

以行遍历为例，就是：

如果一个元素是某一行的最大值，且不小于上下两行的最大值，则此元素一定是顶峰元素。
也就是：

若 mat[i][j] = max(mat[i])， 且mat[i][j] >= max(mat[i - 1]) ,且 mat[i][j] >= max(mat[i + 1])， 
则[i, j]就是顶峰元素。为什么呢？

mat[i][j]是此行的最大值，那么它肯定比左右元素要大。因为相邻元素都不同，而它不可能小于相邻元素。
同时，它也比上下元素要大，因为它不小于上下行的最大元素，肯定也不小于上下元素。同时又因为相邻元素不同，它只可能大于
上下元素。那么，原始问题就可以转化成，在由每行最大值构成的一维数组中，找到一个弱化的顶峰元素。这里弱化的意思是，
大于等于前后元素。

而对于一维数组arr，所有的元素值从前往后，差值总是上升下降交替进行的，有：

若arr[i] >= arr[i - 1] 且 arr[i] >= arr[i + 1]，那么i就是一个弱化的顶峰。
若arr[i] >= arr[i - 1] 且 arr[i] < arr[i + 1]，那么在i后方肯定有一个弱化的顶峰。因为此时arr[i + 1]已经比
arr[i]大了，若arr[i + 1]不是一个弱化的顶峰，就必须有arr[i + 2] > arr[i + 1]。同样的，继续往后，若前面都没有出现
弱化的顶峰，则每个元素都必须比前一个元素更大，而这样，最后一个元素就会是弱化的顶峰。所以要么中间至少出现一个，要么最后
一个元素是，总之一定有一个。
若arr[i] < arr[i - 1] 且 arr[i] >= arr[i + 1]，那么在i前方肯定有一个弱化的顶峰，理由同上一种情况，只是方向反过来。
若arr[i] < arr[i - 1] 且 arr[i] < arr[i + 1]，那么在i前方和后方肯定各有一个弱化的顶峰，相当于上两种情况的组合。
这样就可以用二分查找了，每次如果没有找到，肯定往左或往右继续遍历即可。

最终代码如下：

作者：tianhe1986
链接：https://leetcode.cn/problems/find-a-peak-element-ii/solution/yao-hao-hao-jiang-wei-shi-yao-er-fen-bu-vby3n/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution
{
    function findPeakGrid($mat) {
        // 什么样的元素可以成为顶峰元素呢
        // 如果一个元素是此行的最大元素，且大于等于上下两行的最大元素，就是一个顶峰元素
        // 所以就是相当于对于每行的最大值构成的数组，找一个弱化的顶峰元素
        // 一维数组找弱化顶峰元素怎么找呢
        // 一个数组里的元素总是上升，下降交替进行的
        // 对于一个元素，如果它不小于左右两边，则就是它
        // 否则，如果同时小于左右两边，则左右各有一个顶峰
        // 若小于左边，大于等于右边，则说明现在是下降阶段，左边有一个顶峰
        // 若大于等于左边，小于右边，则说明现在是上升阶段，右边有一个顶峰
        $n = count($mat);
        $low = 0;
        $high = $n - 1;
        while ($low <= $high) {
            $mid = ($low + $high) >> 1;
            // 当前行最大值
            $nowMax = max($mat[$mid]);
            // 上一行最大值
            $upMax = $mid > 0 ? max($mat[$mid - 1]) : -1;
            // 下一行最大值
            $downMax = $mid < $n - 1 ? max($mat[$mid + 1]) : -1;
            if ($nowMax >= $upMax) {
                if ($nowMax >= $downMax) { // 就是它
                    foreach ($mat[$mid] as $j => $value) {
                        if ($value == $nowMax) {
                            return [$mid, $j];
                        }
                    }
                } else { // 下面有顶峰，向下方遍历
                    $low = $mid + 1;
                }
            } else { // 直接取上方，因为上方肯定有顶峰
                $high = $mid - 1;
            }
        }
    }
}

*/

/*

https://leetcode.cn/problems/find-a-peak-element-ii/solution/by-stormsunshine-z135/

解法
思路和算法
这道题是「162. 寻找峰值」的进阶，要求在矩阵中寻找峰值。

对于 mm 行 nn 列的矩阵，题目要求寻找峰值的时间复杂度是 O(m \log n)O(mlogn) 或 O(n \log m)O(nlogm)，
因此需要使用二分查找的做法寻找峰值。考虑矩阵每一行的最大值，其中一定存在一个最大值是峰值。在矩阵的行下标范围
中执行二分查找，二分查找的次数是 O(\log m)O(logm)，对于矩阵的每一行可以在 O(n)O(n) 的时间内找到该行的
最大值所在列，即每次二分查找需要 O(n)O(n) 的时间，总时间复杂度是 O(n \log m)O(nlogm)。

考虑矩阵 \textit{mat}mat 中的两个相邻行下标 ii 和 jj，其中 0 \le i, j < m0≤i,j<m 且 j - i = 1j−i=1，
用 cc 表示 \textit{mat}[i]mat[i] 中的最大值所在列下标。由于 \textit{mat}[i][c] \ne \textit{mat}[j][c]mat[i][c] 

​
=mat[j][c]，因此 \textit{mat}[i][c]mat[i][c] 和 \textit{mat}[j][c]mat[j][c] 的大小关系是 
\textit{mat}[i][c] > \textit{mat}[j][c]mat[i][c]>mat[j][c] 或 \textit{mat}[i][c] < 
\textit{mat}[j][c]mat[i][c]<mat[j][c]。

当 \textit{mat}[i][c] > \textit{mat}[j][c]mat[i][c]>mat[j][c] 时，行下标范围 [0, i][0,i] 
中一定存在峰值；当 \textit{mat}[i][c] < \textit{mat}[j][c]mat[i][c]<mat[j][c] 时，行下标范围 
[j, m - 1][j,m−1] 中一定存在峰值。因此可以根据 \textit{mat}[i][c]mat[i][c] 和 \textit{mat}[j][c]
mat[j][c] 的大小关系判断可能存在峰值的行下标范围，并在更小的范围内查找峰值。

基于上述思路，可以使用二分查找的做法寻找峰值。

用 \textit{low}low 和 \textit{high}high 分别表示二分查找的行下标范围的下界和上界，初始时 \textit{low}low 
和 \textit{high}high 分别为数组的最小行下标和最大行下标。每次查找时，取 \textit{mid}mid 为 \textit{low}low 
和 \textit{high}high 的平均数向下取整，将 \textit{mat}[\textit{mid}]mat[mid] 中的最大值所在列下标记为 
\textit{maxIndex}maxIndex，比较 \textit{mat}[\textit{mid}][\textit{maxIndex}]mat[mid][maxIndex] 
和 \textit{mat}[\textit{mid} + 1][\textit{maxIndex}]mat[mid+1][maxIndex] 的大小关系（注意当 \textit{low} 
< \textit{high}low<high 时，\textit{mid} \le m - 2mid≤m−2，因此行下标 \textit{mid} + 1mid+1 不会超出
矩阵行下标范围），判断可能存在峰值的下标范围，调整查找的下标范围。

如果 \textit{mat}[\textit{mid}][\textit{maxIndex}] > \textit{mat}[\textit{mid} + 1][\textit{maxIndex}]
mat[mid][maxIndex]>mat[mid+1][maxIndex]，则行下标范围 [\textit{low}, \textit{mid}][low,mid] 中可能
存在峰值，在该行下标范围中继续查找。

如果 \textit{mat}[\textit{mid}][\textit{maxIndex}] < \textit{mat}[\textit{mid} + 1][\textit{maxIndex}]
mat[mid][maxIndex]<mat[mid+1][maxIndex]，则行下标范围 [\textit{mid} + 1, \textit{high}][mid+1,high] 
中可能存在峰值，在该行下标范围中继续查找。

当 \textit{low} = \textit{high}low=high 时，查找结束，此时 \textit{mat}[\textit{low}]mat[low] 的最大值
即为峰值，找到峰值并返回其位置。

证明
为了证明上述二分查找做法的正确性，对于 0 \le i, j < m0≤i,j<m 且 j - i = 1j−i=1，\textit{mat}[i][c]mat[i][c] 
是 \textit{mat}mat 的最大值，需要证明：当 \textit{mat}[i][c] > \textit{mat}[j][c]mat[i][c]>mat[j][c] 时，
行下标范围 [0, i][0,i] 中一定存在峰值；当 \textit{mat}[i][c] < \textit{mat}[j][c]mat[i][c]<mat[j][c] 时，
行下标范围 [j, m - 1][j,m−1] 中一定存在峰值。可以使用反证法证明。

当 \textit{mat}[i][c] > \textit{mat}[j][c]mat[i][c]>mat[j][c] 时，假设行下标范围 [0, i][0,i] 中不存在峰值。
由于 \textit{mat}[i][c]mat[i][c] 不是峰值，因此 \textit{mat}[i][c] < \textit{mat}[i - 1][c]mat[i][c]<
mat[i−1][c]，\textit{mat}[i - 1]mat[i−1] 的最大值一定大于 \textit{mat}[i]mat[i] 的最大值。从行下标 i - 1i−1 
向上遍历矩阵 \textit{mat}mat，对于每个行下标 kk，\textit{mat}[k]mat[k] 的最大值都不是峰值，因此每一行的最大值都小于
上一行同列的元素，每一行的最大值都小于上一行的最大值。遍历到 \textit{mat}[0]mat[0] 时，\textit{mat}[0]mat[0] 
的最大值严格大于其左边、右边和下边的相邻元素。由于矩阵中的元素都是正整数且矩阵周围的元素都是 -1−1，因此 \textit{mat}[0]mat[0] 
的最大值严格大于其所有的相邻元素，\textit{mat}[0]mat[0] 的最大值即为峰值。由此可以得到行下标范围 [0, i][0,i] 中一定
存在峰值。

当 \textit{mat}[i][c] < \textit{mat}[j][c]mat[i][c]<mat[j][c] 时，同理可知行下标范围 [j, m - 1][j,m−1] 
中一定存在峰值。

代码
Java

class Solution {
    public int[] findPeakGrid(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int low = 0, high = m - 1, maxIndex = 0;
        while (low < high) {
            int mid = low + (high - low) / 2;
            maxIndex = getMaxIndex(mat[mid]);
            if (mat[mid][maxIndex] > mat[mid + 1][maxIndex]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
		maxIndex = getMaxIndex(mat[low]);
        return new int[]{low, maxIndex};
    }
    
    public int getMaxIndex(int[] row) {
        int index = 0, maxNum = 0;
        int n = row.length;
        for (int i = 0; i < n; i++) {
            if (row[i] > maxNum) {
                maxNum = row[i];
                index = i;
            }
        }
        return index;
    }
}
复杂度分析
时间复杂度：O(n \log m)O(nlogm)，其中 mm 和 nn 分别是数组 \textit{mat}mat 的行数和列数。二分查找的次数是 
O(\log m)O(logm)，每次二分查找需要 O(n)O(n) 的时间，时间复杂度是 O(n \log m)O(nlogm)。

空间复杂度：O(1)O(1)。

作者：stormsunshine
链接：https://leetcode.cn/problems/find-a-peak-element-ii/solution/by-stormsunshine-z135/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/


/************************************************************************************************************/
/************************************************************************************************************/


// 2022.8.15, not in top list

// @lc code=end

