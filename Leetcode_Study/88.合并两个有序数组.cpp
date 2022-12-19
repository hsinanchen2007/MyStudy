/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

/* 

https://leetcode.cn/problems/merge-sorted-array/

88. 合并两个有序数组
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个
元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
 

示例 1：

输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。

示例 2：

输入：nums1 = [1], m = 1, nums2 = [], n = 0
输出：[1]
解释：需要合并 [1] 和 [] 。
合并结果是 [1] 。

示例 3：

输入：nums1 = [0], m = 0, nums2 = [1], n = 1
输出：[1]
解释：需要合并的数组是 [] 和 [1] 。
合并结果是 [1] 。
注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。
 

提示：

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
 

进阶：你可以设计实现一个时间复杂度为 O(m + n) 的算法解决此问题吗？

通过次数675,801提交次数1,291,196

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.2, from 极客时间李煜东算法训练营2021版二期
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // two pointers to trace the current one in the array
        int i = 0, j = 0;

        // hold the result temporary
        vector<int> result;

        // iterate array
        while (i < m || j < n) {
            // most tricky statement below
            // 1. when j from nums2 is already end, put all rest elements
            //    into result from nums1
            // 2. when i is still within range, and nums1[i] is smaller than
            //    nums2[j], put this element into result
            // think only from one side, and put rest to another side
            if ((j >= n) || (i < m && nums1[i] <= nums2[j])) {
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }

        // put numbers back to nums1
        for (int k = 0; k < m + n; k++) nums1[k] = result[k];
    }
};


class Solution99 {
public:
    // 2022.6.2, from 极客时间李煜东算法训练营2021版二期
    // good example to resolve it by reverse way, and no extra defined
    // variable
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // two pointers, i and j pointed to last elements
        int i = m - 1;
        int j = n - 1;

        // reverse as nums1 has n empty from end, and the sorted elements
        // are located at first m elements in nums1
        for (int k  = m + n -1; k >= 0; k--) {
            // similar to above tricky condition part
            // 1. when j is less than 0, all elements from nums1[i] can be 
            //    copied into the nums1
            // 2. when i is still within range, and element from nums1[i] is
            //    larger than nums2[j] 
            if ((j < 0) || (i >= 0 && nums1[i] >= nums2[j])) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
        }
    }
};


class Solution98 {
public:
    // 2022.6.5, from AcWing https://www.acwing.com/video/1432/
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // we know nums1 has enough space to keep both nums1 and nums2
        // so add largest one from nums1 or nums2 to the end of nums1
        int k = m + n -1;
        int i = m - 1;
        int j = n - 1;

        // add largest one to the end of nums1
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // only need to deal with rest of nums2, as if nums1 still has
        // some left, they are already placed at right index location
        // from the beginning as this is a sorted array
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};


class Solution97 {
public:
    // 2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/merge-sorted-array.cpp
    // Time:  O(n)
    // Space: O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n;
        while (m > 0 && n > 0) {
            if (nums1[m - 1] > nums2[n - 1]) {
                nums1[i - 1] = nums1[m - 1];
                --m;
            } else {
                nums1[i - 1] = nums2[n - 1];
                --n;
            }
            --i;
        }

        while (n > 0) {
            nums1[i - 1] = nums2[n - 1];
            --n;
            --i;
        }
    }
}; 


class Solution96 {
public:
    // 2022.6.14, from https://ke.algomooc.com/detail/v_626e7fbbe4b01c509aaaf53f/3?from=p_6243bcc1e4b04e8d90291891&type=8&parent_pro_id=p_626e7eeee4b01c509aaaf51e
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com/555.html
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 合并两个有序数组( LeetCode 88 ):https://leetcode-cn.com/problems/merge-sorted-array/
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 索引从有序数组 nums1 有效元素的末端开始
        // 数组的下标索引从零开始计数
        // 索引   0    1     2
        // 数组 [ 1 ,  2  ,  3 ]
        int i = m - 1;

        // 索引从有序数组 nums2 的末端开始
        int j = n - 1;

        // 从有序数组 nums1 最末端的位置开始保存元素
        int cur = nums1.size() - 1;

        // 通过循环把 num2 的元素都移动到 num1 中
        while ( j >= 0  ) {

            // 比较 num1 和 num2 中当前的元素大小

            // 如果 num1 中的索引位置为 i 的元素大于 num2 中索引位置为 j 的元素
            // 为了防止越界 i 必须是大于等于 0 
            if( i >=0 && nums1[i] > nums2[j] ) {

             // 把 num1 中的索引位置为 i 的元素复制到索引为 cur 的位置
             // 此时 cur 的元素已经确定下来
             nums1[cur] = nums1[i];
            
             // 接下来去确定 cur 前面一个元素应该放什么数字
             cur--;
             // 此时，索引 i 需要向前移动
             i--;
             // 否则，如果 num1 中的索引位置为 i 的元素小于或者等于 num2 中索引位置为 j 的元素
            } else {
             
             // 把 num2 中的索引位置为 j 的元素复制到索引为 cur 的位置
             nums1[cur] = nums2[j];
             // 接下来去确定 cur 前面一个元素应该放什么数字
             cur--;
             // 此时，索引 j 需要向前移动
             j--;
            }
        }
    }
};


class Solution95 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/88.%20Merge%20Sorted%20Array
    // OJ: https://leetcode.com/problems/merge-sorted-array/
    // Author: github.com/lzl124631x
    // Time: O(M + N)
    // Space: O(1)
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        for (int i = m - 1, j = n - 1, k = m + n - 1; k >= 0; --k) {
            if (j < 0 || (i >= 0 && A[i] > B[j])) A[k] = A[i--];
            else A[k] = B[j--];
        }
    }
};


class Solution94 {
public:
    // 2022.7.25, from https://walkccc.me/LeetCode/problems/0088/
    // Time: O(m + n)
    // Space: O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // nums1's index (actual nums)
        int j = n - 1;      // nums2's index
        int k = m + n - 1;  // nums1's index (next filled position)

        while (j >= 0)
        if (i >= 0 && nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
};


class Solution93 {
public:
    // 2022.7.25, from https://www.guozet.me/leetcode/Leetcode-88-Merge-Sorted-Array.html?h=merge
    // Time complexity: O(m + n) Space complexity: O(m + n)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        vector<int> temp = nums1;

        int p = 0, q = 0;
        for (int i = 0; i < m + n; ++i) nums1[i] = q < n && temp[p] >= nums2[q] || p == m ? nums2[q++] : temp[p++];
    }
};


class Solution92 {
public:
    // 2022.7.25, from https://www.guozet.me/leetcode/Leetcode-88-Merge-Sorted-Array.html?h=merge
    // Fill nums1 from back to front Time complexity: O(m + n) Space complexity: O(1) in-place
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m - 1, q = n - 1, tail = m + n - 1;
        while (q >= 0) nums1[tail--] = (p >= 0 && nums1[p] >= nums2[q]) ? nums1[p--] : nums2[q--];
    }
};


class Solution91 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/88
    /*
        混合插入有序数组，由于两个数组都是有序的，所有只要按顺序比较大小即可。题目中说了 nums1 数组有足够大的空间，
        说明不用 resize 数组，又给了m和n，那就知道了混合之后的数组的大小，这样就从 nums1 和 nums2 数组的末尾开始
        一个一个比较，把较大的数，按顺序从后往前加入混合之后的数组末尾。需要三个变量 i，j，k，分别指向 nums1，nums2，
        和混合数组的末尾。进行 while 循环，如果i和j都大于0，再看如果 nums1[i] > nums2[j]，说明要先把 nums1[i] 
        加入混合数组的末尾，加入后k和i都要自减1；反之就把 nums2[j] 加入混合数组的末尾，加入后k和j都要自减1。循环结
        束后，有可能i或者j还大于等于0，若j大于0，那么还需要继续循环，将 nums2 中的数字继续拷入 nums1。若是i
        大于等于0，那么就不用管，因为混合数组本身就放在 nums1 中，参见代码如下：

        解法一： 
    */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while (j >= 0) nums1[k--] = nums2[j--];
    }
};


class Solution {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/88
    /*
        我们还可以写的更简洁一些，将两个 while 循环融合到一起，只要加上 i>=0 且 nums1[i] > nums2[j] 的判断条件，
        就可以从 nums1 中取数，否则就一直从 nums2 中取数，参见代码如下:

        解法二：
    */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            nums1[k--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
        }
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

