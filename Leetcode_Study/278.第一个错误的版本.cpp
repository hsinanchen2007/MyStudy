/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

/*

https://leetcode.cn/problems/first-bad-version/

278. 第一个错误的版本
你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。

假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。

你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

 
示例 1：

输入：n = 5, bad = 4
输出：4
解释：
调用 isBadVersion(3) -> false 
调用 isBadVersion(5) -> true 
调用 isBadVersion(4) -> true
所以，4 是第一个错误的版本。

示例 2：

输入：n = 1, bad = 1
输出：1
 

提示：

1 <= bad <= n <= 231 - 1
通过次数345,957提交次数761,940

*/

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution100 {
public:
    // 2022.6.19, by Hsinan. Use Binary Search
    int firstBadVersion(int n) {
        // define left and right pointers, since the starting version is 1
        // so we use left = 1, and right is latest version n
        int left = 1, right = n;

        while (left <= right) {
            int middle = left + (right -left) / 2;
            if (isBadVersion(middle)) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return left;
    }
};


class Solution99 {
public:
    // 2022.6.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/single-element-in-a-sorted-array.cpp
    // Time:  O(logn)
    // Space: O(1)
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};


class Solution98 {
public:
    // 2022.6.19, from https://www.guozet.me/leetcode/Leetcode-278-First-Bad-Version.html?h=first%20bad
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            isBadVersion(mid) ? right = mid : left = mid + 1;
        }
        return left;
    }
};


class Solution97 {
public:
    // 2022.6.19, from AcWing https://www.acwing.com/video/1653/
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int middle = left + (long long)right >> 1;
            if (isBadVersion(middle)) right = middle;
            else left = middle + 1;
        }
        return right;
    }
};


class Solution96 {
public:
    // 2022.6.19, from https://ke.algomooc.com/detail/v_6281aa6ce4b01a4851ff6237/3?from=p_6281a4bbe4b01a4851ff5f23&type=6&parent_pro_id=
    int firstBadVersion(int n) {
        // 注意到题目的第一个版本下标为 1 ，所以边界情况为 [ 1 , n ]
        int left = 1 ;
        int right = n ;

        // 利用二分查找的方法，去定位出【第一个错误的版本】
        // 在 while 循环里面，left 不断的 ++，而 right 不断的 --
        // 当 left 和 right 相等， [ left , right ] 这个区间存在一个版本的时候
        // 这个版本就是【第一个错误的版本】
        // 所以，当 left == right 时，跳出循环
        // 此时，while 循环的判断不可以使用等号
        while (left < right) { 
            // left + (right - left) / 2 和 (left + right) / 2 的结果相同
            // 但是使用 left + (right - left) / 2 可以防止由于 left 、right 同时太大，导致相加的结果溢出的问题
            // 比如数据 int 的最大值为 2,147,483,647
            // 此时，left 为 2,147,483,640
            // 此时，right 为 2,147,483,646
            // 两者直接相加超过了 2,147,483,647，产生了溢出
            int mid = left + (right - left) / 2;

            // 调用系统函数，查看当前的版本是否是错误的版本
            // 1、如果当前版本为错误的版本，那么此时 mid 指向的版本有可能是【第一个错误的版本】
            // 因此，区间缩小为 [ left , mid ]
            if (isBadVersion(mid)) {

                // 再次注意，mid 指向的版本有可能是【第一个错误的版本】，因此，right 移动到 mid 的位置
                right = mid;

            // 2、如果当前版本为正确的版本，那么此时 mid 指向的版本绝对不可能是【第一个错误的版本】
            //  因此，区间缩小为 [ mid + 1 , right ]
            } else {
                
                // 再次注意，mid 指向的版本已经是正确的版本了
                // 意味着 [ left , mid ] 的所有版本都是正确的，错误的版本发生在 [ mid + 1 , right ] 这个区间里面
                left = mid + 1; 

            }
        }

        // 当 left 和 right 相等， [ left , right ] 这个区间存在一个版本的时候
        // 这个版本就是【第一个错误的版本】
        return left;
    }
};


class Solution95 {
public:
    // 2022.7.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/278.%20First%20Bad%20Version
    // OJ: https://leetcode.com/problems/first-bad-version/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    // Solution 1. Binary Search (L <= R)
    int firstBadVersion(int n) {
        int L = 1, R = n;
        while (L <= R) {
            int M = L + (R - L) / 2;
            if (isBadVersion(M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};


class Solution94 {
public:
    // 2022.7.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/278.%20First%20Bad%20Version
    // OJ: https://leetcode.com/problems/first-bad-version/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    // Solution 2. Binary Search (L < R)
    int firstBadVersion(int n) {
        int L = 1, R = n;
        while (L < R) {
            int M = L + (R - L) / 2;
            if (isBadVersion(M)) R = M;
            else L = M + 1;
        }
        return L;
    }
};


class Solution93 {
public:
    // 2022.7.27, from https://walkccc.me/LeetCode/problems/0278/
    // Time: O(logn)
    // Space: O(1)
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;

        while (l < r) {
            const int m = l + (r - l) / 2;
            if (isBadVersion(m))
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};


class Solution92 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/278
    /*
        话说这个叫李建超（音译）的哥们太赞了，自从 LeetCode 开始收费后，大多数的免费题都是这哥们出的，还写了所有的 
        test cases，32 个赞。这道题说是有一系列版本，其中有一个版本是坏的，而且后面跟着的全是坏的，给了一个 API 
        函数可以用来判定当前版本是否是坏的，让我们尽可能少的调用这个 API，找出第一个坏版本。那么这种搜索题最先开始
        考虑用二分查找法把，效率高嘛。由于这题很有规律，好版本和坏版本一定有个边界，那么用二分法来找这个边界，对 mid 
        值调用API函数，如果是坏版本，说明边界在左边，则把 mid 赋值给 right，如果是好版本，则说明边界在右边，则把 
        mid+1 赋给 left，最后返回 left 即可。需要注意的是，OJ 里有个坑，那就是如果 left 和 right 都特别大的话，
        那么 left+right 可能会溢出，这里处理方法就是变成 left + (right - left) / 2，很好的避免的溢出问题，
        参见代码如下：
    */
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};


class Solution {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/278
    /*
        如果习惯了二分搜索法从0开始找，可以用下面的方法：
    */
    int firstBadVersion(int n) {
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid + 1)) right = mid;
            else left = mid + 1;
        }
        return right + 1;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// 2022.8.15, not in top list

// @lc code=end

