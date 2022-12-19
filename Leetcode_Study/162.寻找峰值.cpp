/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

/*

https://leetcode.cn/problems/find-peak-element/

162. 寻找峰值
峰值元素是指其值严格大于左右相邻值的元素。

给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞ 。

你必须实现时间复杂度为 O(log n) 的算法来解决此问题。


示例 1：

输入：nums = [1,2,3,1]
输出：2
解释：3 是峰值元素，你的函数应该返回其索引 2。

示例 2：

输入：nums = [1,2,1,3,5,6,4]
输出：1 或 5 
解释：你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。
 

提示：

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
对于所有有效的 i 都有 nums[i] != nums[i + 1]
通过次数240,610提交次数486,015

*/

// @lc code=start
class Solution100 {
public:
    // 2022.7.10, by Hsinan, check the middle and see if it is higher than right side's element
    // then adjust left or right accordingly
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] >= nums[middle+1]) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }

        return right;
    }
};


class Solution99 {
public:
    // 2022.7.10, from 程序员吴师兄
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 寻找峰值(162):https://leetcode-cn.com/problems/find-peak-element/ 
    int findPeakElement(vector<int>& nums) {
        
        // left 为当前区间最左侧的元素，可以获取到
        int left = 0;

        // right 为当前区间最右侧的元素，可以获取到
        int right = nums.size() - 1;


        // 在 while 循环里面，left 不断的 ++，而 right 不断的 --
        // 当 left 和 right 相等， [ left , right ] 这个区间存在一个元素的时候
        // 这也意味着这个区间里面的元素找不到其它元素和它进行比较，也就无法得知这个元素是否严格大于它左右相邻值的元素了
        // 所以，当 left == right 时，跳出循环
        // 此时，while 循环的判断不可以使用等号
        while(left < right) {

            // left + (right - left) / 2 和 (left + right) / 2 的结果相同
            // 但是使用 left + (right - left) / 2 可以防止由于 left 、right 同时太大，导致相加的结果溢出的问题
            // 比如数据 int 的最大值为 2,147,483,647
            // 此时，left 为 2,147,483,640
            // 此时，right 为 2,147,483,646
            // 两者直接相加超过了 2,147,483,647，产生了溢出
            int mid = left + (right - left) / 2;

            // 题目告诉我们 nums[-1] = nums[n] = -∞ 
            // 这暗示我们只要数组中存在一个元素比它相邻的元素大，那么沿着它一定可以找到一个峰值
            // 就像爬山一样，较小的山高度是 100，前面的山高度是 200，在前面是一个深渊，那么高度为 200 的那座山就是山峰
            // 所以比较 nums[mid] 与 nums[mid + 1] 的值

            // 如果 nums[mid] > nums[mid + 1]
            // 所以，如果存在山峰，那么这一段是右侧下降的那一段，因此需要在左侧去寻找上升的那段 
            if (nums[mid] > nums[mid + 1]) {

                // 缩小区间，从 [ left , mid ] 里面去找
                right = mid;
            
            // 如果 nums[mid] < nums[mid + 1]
            // 所以，如果存在山峰，那么这一段是左侧上升的那一段，因此需要在右侧去寻找下降的那段         
            } else {

                // 缩小区间，从 [ mid + 1 , right ] 里面去找
                left = mid + 1;

            }
        }

        // 跳出循环，此时 left == right，返回这个下标即可
        return left;
    }
};


class Solution98 {
public:
    // 2022.7.10, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/find-peak-element.cpp
    // Time:  O(logn)
    // Space: O(1)
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
       
        return left;
    }
};


class Solution97 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/162.%20Find%20Peak%20Element
    // Solution 1. Binary Search (L <= R)
    // OJ: https://leetcode.com/problems/find-peak-element/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int findPeakElement(vector<int>& A) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            long M = (L + R) / 2, left = M == 0 ? LONG_MIN : A[M - 1], right = M == A.size() - 1 ? LONG_MIN : A[M + 1];
            if (A[M] > left && A[M] > right) return M;
            if (A[M] < left) R = M - 1;
            else L = M + 1;
        }
        return -1;
    }
};


class Solution96 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/162.%20Find%20Peak%20Element
    // Solution 2. Binary Search (L < R)
    // OJ: https://leetcode.com/problems/find-peak-element/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int findPeakElement(vector<int>& A) {
        int L = 0, R = A.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (A[M] > A[M + 1]) R = M;
            else L = M + 1;
        }
        return L;
    }
};


class Solution95 {
public:
    // 2022.7.25, from https://walkccc.me/LeetCode/problems/0162/
    // Time: O(logn)
    // Space: O(1)
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
        const int m = (l + r) / 2;
        if (nums[m] >= nums[m + 1])
            r = m;
        else
            l = m + 1;
        }

        return l;
    }
};


class Solution94 {
public:
    // 2022.7.10, from AcWing https://www.acwing.com/activity/content/code/content/411113/
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] > nums[mid + 1]) r = mid;
            else l = mid + 1;
        }
        return r;
    }

};


class Solution93 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/162
    /*
        这道题是求数组的一个峰值，如果这里用遍历整个数组找最大值肯定会出现 Time Limit Exceeded，但题目中说
        了这个峰值可以是局部的最大值，所以只需要找到第一个局部峰值就可以了。所谓峰值就是比周围两个数字都大的数字，
        那么只需要跟周围两个数字比较就可以了。既然要跟左右的数字比较，就得考虑越界的问题，题目中给了 
        nums[-1] = nums[n] = -∞，其实可以把这两个整型最小值直接加入到数组中，然后从第二个数字遍历到倒数第二个
        数字，这样就不会存在越界的可能了。由于题目中说了峰值一定存在，那么有一个很重要的 corner case 要注意，
        就是当原数组中只有一个数字，且是整型最小值的时候，我们如果还要首尾垫数字，就会形成一条水平线，从而没有
        峰值了，所以我们对于数组中只有一个数字的情况在开头直接判断一下即可，参见代码如下：

        C++ 解法一：
    */
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MIN);
        for (int i = 1; i < (int)nums.size() - 1; ++i) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i - 1;
        }
        return -1;
    }
};


class Solution92 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/162
    /*
        我们可以对上面的线性扫描的方法进行一些优化，可以省去首尾垫值的步骤。由于题目中说明了局部峰值一定存在，
        那么实际上可以从第二个数字开始往后遍历，如果第二个数字比第一个数字小，说明此时第一个数字就是一个局部峰值；
        否则就往后继续遍历，现在是个递增趋势，如果此时某个数字小于前面那个数字，说明前面数字就是一个局部峰值，
        返回位置即可。如果循环结束了，说明原数组是个递增数组，返回最后一个位置即可，参见代码如下：

        C++ 解法二：
    */
    int findPeakElement(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) return i - 1;
        }
        return nums.size() - 1;
    }
};


class Solution91 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/162
    /*
        由于题目中提示了要用对数级的时间复杂度，那么我们就要考虑使用类似于二分查找法来缩短时间，由于只是需要
        找到任意一个峰值，则在确定二分查找折半后中间那个元素后，和紧跟的那个元素比较下大小，如果大于，则说明
        峰值在前面，如果小于则在后面。这样就可以找到一个峰值了，代码如下：

        C++ 解法三：
    */
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


class Solution90 {
public:
    // 2022.8.2, by Hsinan, use max_element() to find max one in the given vector
    // then get its index by distance()
    int findPeakElement(vector<int>& nums) {
        auto top = max_element(nums.begin(), nums.end());
        return (top != nums.end() ? distance(nums.begin(), top) : -1);
    }
};


class Solution {
public:
    // 2022.9.3, from https://leetcode-solution.cn/book
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (mid + 1 < n && nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            } else if (mid - 1 >= 0 && nums[mid] < nums[mid - 1]) {
                h = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};


// @lc code=end

