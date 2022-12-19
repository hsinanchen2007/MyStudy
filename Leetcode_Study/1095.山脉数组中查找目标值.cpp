/*
 * @lc app=leetcode.cn id=1095 lang=cpp
 *
 * [1095] 山脉数组中查找目标值
 */

/*

https://leetcode.cn/problems/find-in-mountain-array/

1095. 山脉数组中查找目标值
（这是一个 交互式问题 ）

给你一个 山脉数组 mountainArr，请你返回能够使得 mountainArr.get(index) 等于 target 最小 的下标 index 值。
如果不存在这样的下标 index，就请返回 -1。
 

何为山脉数组？如果数组 A 是一个山脉数组的话，那它满足如下条件：

首先，A.length >= 3

其次，在 0 < i < A.length - 1 条件下，存在 i 使得：

A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
 

你将 不能直接访问该山脉数组，必须通过 MountainArray 接口来获取数据：

MountainArray.get(k) - 会返回数组中索引为k 的元素（下标从 0 开始）
MountainArray.length() - 会返回该数组的长度
 

注意：

对 MountainArray.get 发起超过 100 次调用的提交将被视为错误答案。此外，任何试图规避判题系统的解决方案都将会导致比赛
资格被取消。

为了帮助大家更好地理解交互式问题，我们准备了一个样例 “答案”：https://leetcode-cn.com/playground/RKhe3ave，请
注意这 不是一个正确答案。
 

示例 1：

输入：array = [1,2,3,4,5,3,1], target = 3
输出：2
解释：3 在数组中出现了两次，下标分别为 2 和 5，我们返回最小的下标 2。

示例 2：

输入：array = [0,1,2,4,2,1], target = 3
输出：-1

解释：3 在数组中没有出现，返回 -1。
 

提示：

3 <= mountain_arr.length() <= 10000
0 <= target <= 10^9
0 <= mountain_arr.get(index) <= 10^9
通过次数24,656提交次数65,629

*/

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution100 {
public:
    // 2022.9.9, from https://www.acwing.com/activity/content/code/content/2199092/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/2199092/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n - 1;

        while (l < r) {
            int mid = l + r >> 1;
            if (mountainArr.get(mid) > mountainArr.get(mid + 1)) r = mid;
            else l = mid + 1;
        }

        int M = r;
        l = 0, r = M;
        while (l < r) {
            int mid = l + r >> 1;
            if (mountainArr.get(mid) >= target) r = mid;
            else l = mid + 1;
        }
        if (mountainArr.get(r) == target) return r;

        l = M + 1, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (mountainArr.get(mid) <= target) r = mid;
            else l = mid + 1;
        }

        if (mountainArr.get(r) == target) return r;
        return -1;
    }
};


class Solution99 {
public:
    // 2022.9.9, from https://github.com/grandyang/leetcode/issues/1095
    /*
        这道题给了一个山形数组 Mountain Array，关于山形数组的题目，之前也出现过，比如 Longest Mountain in Array 
        和 Peak Index in a Mountain Array。所谓的山形数组，就是先上升后下降的数组，注意这里是严格的上升和下降。题目
        中说这个山形数组不能直接访问元素，而是需要调用 get()，数组的长度需要调用 length()，要求尽可能的少调用这些函数，
        而且还说了假如调用了超过了 100 次的 get 函数，OJ 会自动判为错的解法。这完全是断了直接遍历一遍数组的这条路啊，
        毕竟这是一道 Hard 题，要给予足够的尊重才行。既然不能暴力搜索，更高效的搜索方法可以用二分搜索，但前提条件是数组
        必须是有序的，这里的数组是先上升再下降的，没法直接用二分搜索来找目标值。不过假如我们能够将上升和下降的部分分割开
        来，就可以分别调用二分搜索法啦，临界点就是峰值啦。所以首先要用二分法求个峰值，你可能有个疑问，前面不是说了二分法
        不能在山形数组中查找目标值吗，怎么这里却可以用来查找峰值呢？嗯，是个好问题，这其实是个特殊情况，一般来说二分法查
        找的目标值是固定不变的，而这里查找峰值时不是用一个固定的目标值，而是再求出 mid 后，跟其紧挨的下一个位置比较，假
        如小于下个位置的值，则说明峰值在后面，此时 left 更新为 mid+1，否则 right 更新为 mid，最后的峰值就保存在 left 
        中。用类似的方法的题目还有 Find Minimum in Rotated Sorted Array。找到了峰值之后，就可以将数组分为两段分别
        进行二分查找了，这里可以写两个 while 循环分别查找，也可以放到一个子函数中，不过由于前半段是上升的，后半段是下降
        的，二者的更新方法正好相反，可以用一个 flag 控制一下。最后假如左半段返回是 -1，则返回右半段的结果即可，参见代码
        如下：
    */
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length(), left = 0, right = n - 1, peak = -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) left = mid + 1;
            else right = mid;
        }
        peak = left;
        if (mountainArr.get(peak) == target) return peak;
        int idx1 = helper(target, mountainArr, 0, peak - 1, true);
        int idx2 = helper(target, mountainArr, peak + 1, n - 1, false);
        return idx1 == -1 ? idx2 : idx1;
    }
    int helper(int target, MountainArray &mountainArr, int left, int right, bool isAsc) {
        while (left < right) {
            int mid = left + (right - left) / 2, cur = mountainArr.get(mid);
            if (cur == target) return mid;
            else if (cur < target) {
                if (isAsc) left = mid + 1;
                else right = mid;
            } else {
                if (isAsc) right = mid;
                else left = mid + 1;
            }
        }
        return mountainArr.get(right) == target ? right : -1;
    }
};


class Solution98 {
public:
    // 2022.9.9, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/find-in-mountain-array.cpp
    // Time:  O(logn)
    // Space: O(1)
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = binarySearch(mountainArr, 0, mountainArr.length()-1,
                                [&](int x) { return mountainArr.get(x) >= mountainArr.get(x + 1); });
        int left = binarySearch(mountainArr, 0, peak,
                             [&](int x) { return mountainArr.get(x) >= target; });
        if (left <= peak && mountainArr.get(left) == target) {
            return left;
        }
        int right = binarySearch(mountainArr, peak, mountainArr.length() - 1,
                                 [&](int x) { return mountainArr.get(x) <= target; });
        if (right <= mountainArr.length() - 1 && mountainArr.get(right) == target) {
            return right;
        }
        return -1;
    }
    
private:
    int binarySearch(MountainArray &A, int left, int right,
                     const function<bool(int)>& check) {
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};


class Solution97 {
    // 2022.9.9, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1095.%20Find%20in%20Mountain%20Array
    // OJ: https://leetcode.com/problems/find-in-mountain-array/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int binarySearch(int target, MountainArray &A, int L, int R, int dir) {
        while (L <= R) {
            int M = (L + R) / 2, val = A.get(M);
            if (val == target) return M;
            bool left = (dir == 1 && val < target) || (dir == -1 && val > target);
            if (left) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
    int findTop(MountainArray &A, int N) {
        int L = 0, R = N - 1;
        while (L <= R) {
            int M = (L + R) / 2, left = M - 1 >= 0 ? A.get(M - 1) : INT_MIN, val = A.get(M), right = M + 1 < N ? A.get(M + 1) : INT_MIN;
            if (val > left && val > right) return M;
            else if (val < left) R = M - 1;
            else L = M + 1;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &A) {
        int N = A.length(), top = findTop(A, N);
        int a = binarySearch(target, A, 0, top, 1);
        int b = binarySearch(target, A, top + 1, N - 1, -1);
        return a != -1 ? a : b;
    }
};


class Solution {
public:
    // 2022.9.9, from https://walkccc.me/LeetCode/problems/1095/
    // Time: O(logn)
    // Space: O(1)
    int findInMountainArray(int target, MountainArray& mountainArr) {
        const int n = mountainArr.length();
        const int peakIndex = peakIndexInMountainArray(mountainArr, 0, n - 1);

        const int leftIndex = searchLeft(mountainArr, target, 0, peakIndex);
        if (mountainArr.get(leftIndex) == target)
        return leftIndex;

        const int rightIndex =
            searchRight(mountainArr, target, peakIndex + 1, n - 1);
        if (mountainArr.get(rightIndex) == target)
        return rightIndex;

        return -1;
    }

private:
    // 852. Peak Index in a Mountain Array
    int peakIndexInMountainArray(MountainArray& A, int l, int r) {
        while (l < r) {
        const int m = (l + r) / 2;
        if (A.get(m) < A.get(m + 1))
            l = m + 1;
        else
            r = m;
        }
        return l;
    }

    int searchLeft(MountainArray& A, int target, int l, int r) {
        while (l < r) {
        const int m = (l + r) / 2;
        if (A.get(m) < target)
            l = m + 1;
        else
            r = m;
        }
        return l;
    }

    int searchRight(MountainArray& A, int target, int l, int r) {
        while (l < r) {
        const int m = (l + r) / 2;
        if (A.get(m) > target)
            l = m + 1;
        else
            r = m;
        }
        return l;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/



// @lc code=end

