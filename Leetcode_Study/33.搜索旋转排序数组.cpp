/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

/*

https://leetcode.cn/problems/search-in-rotated-sorted-array/

33. 搜索旋转排序数组
整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], 
nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， 
[0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
 

示例 1：

输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4

示例 2：

输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1

示例 3：

输入：nums = [1], target = 0
输出：-1
 

提示：

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums 中的每个值都 独一无二
题目数据保证 nums 在预先未知的某个下标上进行了旋转
-104 <= target <= 104
通过次数588,883提交次数1,346,951

*/

// @lc code=start
class Solution100 {
public:
    // 2022.7.30, by Hsinan
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] == target) { 
                return middle; 
            }
            // below condition needed to be >=, as if case is like [3, 1] target 1,
            // the left and middle values are same at index 0
            if (nums[middle] >= nums[left]) {
                // left to middle is sorted
                if (nums[middle] > target && nums[left] <= target) {
                    // left <= target < middle
                    right = middle - 1;
                } else {
                    // middle < target <= right
                    left = middle + 1;
                }
            } else {
                // middle to right is sorted
                if (nums[middle] < target && nums[right] >= target) {
                    // middle < target <= right
                    left = middle + 1;
                } else {
                    // left <= target < middle
                    right = middle - 1;
                }
            }
        }
        return -1;
    }
};


class Solution99 {
public:
    // 2022.7.30, from https://walkccc.me/LeetCode/problems/0033/
    // Time: O(logn)
    // Space: O(1)
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            const int m = (l + r) / 2;
            if (nums[m] == target)
                return m;
            if (nums[l] <= nums[m]) {  // nums[l..m] are sorted
                if (nums[l] <= target && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else {  // nums[m..n - 1] are sorted
                if (nums[m] < target && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }

        return -1;
    }
};


class Solution98 {
public:
    // 2022.7.30, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/search-in-rotated-sorted-array.cpp
    // Time:  O(logn)
    // Space: O(1)
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if ((nums[mid] >= nums[left] && nums[left] <= target && target < nums[mid]) ||
                       (nums[mid] < nums[left] && !(nums[mid] < target && target <= nums[right]))) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};


class Solution97 {
public:
    // 2022.7.30, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/search-in-rotated-sorted-array.cpp
    // Time:  O(logn)
    // Space: O(1)
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if ((nums[left] <= nums[mid] && nums[left] <= target && target < nums[mid]) ||
                       (nums[left] > nums[mid] && !(nums[mid] < target && target <= nums[right - 1]))) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};


class Solution96 {
public:
    // 2022.7.30, from AcWing
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/355022/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }

        if (target >= nums[0]) l = 0;
        else l = r + 1, r = nums.size() - 1;

        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        if (nums[r] == target) return r;
        return -1;
    }
};


class Solution95 {
public:
    // 2022.7.30, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/33.%20Search%20in%20Rotated%20Sorted%20Array
    /*
        Use the solution to 153. Find Minimum in Rotated Sorted Array (Medium).
        We first find the pivot point, then we can do a normal binary search on [0, pivot - 1] or [pivot, N - 1].
    */
    // OJ: https://leetcode.com/problems/search-in-rotated-sorted-array/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int L = 0, R = nums.size() - 1, pivot;
        while (L < R) {
            int M = L + (R - L) / 2;
            if (nums[M] < nums[R]) R = M;
            else L = M + 1;
        }
        pivot = L;
        if (pivot && target >= nums[0] && target <= nums[pivot - 1]) L = 0, R = pivot - 1;
        else L = pivot, R = nums.size() - 1;
        while (L <= R) {
            int M = L + (R - L) / 2;
            if (nums[M] == target) return M;
            if (target > nums[M]) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
};


class Solution94 {
public:
    // 2022.7.30, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/33.%20Search%20in%20Rotated%20Sorted%20Array
    /*
        Similar to the Solution 1, but we shift the M by pivot to find the real mid point (need to % N).
    */
    // OJ: https://leetcode.com/problems/search-in-rotated-sorted-array/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    // https://discuss.leetcode.com/topic/3538/concise-o-log-n-binary-search-solution
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int N = nums.size(), L = 0, R = N - 1, pivot;
        while (L < R) {
            int M = L + (R - L) / 2;
            if (nums[M] < nums[R]) R = M;
            else L = M + 1;
        }
        pivot = L;
        L = 0, R = N - 1;
        while (L <= R) {
            int M = L + (R - L) / 2;
            int MM = (M + pivot) % N;
            if (nums[MM] == target) return MM;
            if (target > nums[MM]) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
};


class Solution93 {
public:
    // 2022.7.30, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/33.%20Search%20in%20Rotated%20Sorted%20Array
    /*
        Let L = 0, R = N - 1, M = (L + R) / 2.

        If A[M] == target, return M
        If A[M] > A[R], the min point in the array is to the right of A[M], we then compare target with A[M] or A[L] to 
        see if we should move L or R.
        If A[M] <= A[R], the min point in the array is to the left of A[M], we can then compare target with A[M] or A[R] 
        to see if we should move L or R.
    */
    // OJ: https://leetcode.com/problems/search-in-rotated-sorted-array/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int search(vector<int>& A, int target) {
        if (A.empty()) return -1;
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if (A[M] > A[R]) {
                if (target > A[M]) L = M + 1;
                else if (target >= A[L]) R = M - 1;
                else L = M + 1;
            } else {
                if (target > A[M]) {
                    if (target <= A[R]) L = M + 1;
                    else R = M - 1;
                } else R = M - 1;
            }
        }
        return -1;
    }
};


class Solution92 {
public:
    // 2022.7.30, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/33.%20Search%20in%20Rotated%20Sorted%20Array
    // OJ: https://leetcode.com/problems/search-in-rotated-sorted-array/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if ((A[M] > A[R] && (target > A[M] || target < A[L]))
               || (A[M] <= A[R] && (target > A[M] && target <= A[R]))) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
};


class Solution91 {
public:
    // 2022.7.30, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/33.%20Search%20in%20Rotated%20Sorted%20Array
    // OJ: https://leetcode.com/problems/search-in-rotated-sorted-array/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if (A[0] <= A[M]) {
                if (A[M] < target || target < A[0]) L = M + 1;
                else R = M - 1;
            } else {
                if (target < A[M] || target >= A[0]) R = M - 1;
                else L = M + 1;
            }
        }
        return -1;
    }
};


class Solution90 {
public:
    // 2022.7.30, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/33.%20Search%20in%20Rotated%20Sorted%20Array
    // OJ: https://leetcode.com/problems/search-in-rotated-sorted-array/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if ((A[0] <= A[M] && (A[M] < target || target < A[0]))
               || (A[0] > A[M] && target > A[M] && target < A[0])) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
};


class Solution89 {
public:
    // 2022.7.30, from https://github.com/grandyang/leetcode/issues/33
    /*
        这道题让在旋转数组中搜索一个给定值，若存在返回坐标，若不存在返回 -1。我们还是考虑二分搜索法，
        但是这道题的难点在于不知道原数组在哪旋转了，还是用题目中给的例子来分析，对于数组 [0 1 2 4 5 6 7] 
        共有下列七种旋转方法（红色表示中点之前或者之后一定为有序的）：

        0　　1　　2　　4　　5　　6　　7

        7　　0　　1　　2　　4　　5　　6

        6　　7　　0　　1　　2　　4　　5

        5　　6　　7   0　　1　　2　　4

        4　　5　　6　　7 　　0　　1　　2

        2　　4　　5　　6 　　7　　0　　1

        1　　2　　4　　5 　　6　　7　　0

        二分搜索法的关键在于获得了中间数后，判断下面要搜索左半段还是右半段，观察上面红色的数字都是升序的
        （Github 中可能无法显示颜色，参见博客园上的帖子），可以得出出规律，如果中间的数小于最右边的数，
        则右半段是有序的，若中间数大于最右边数，则左半段是有序的，我们只要在有序的半段里用首尾两个数组来
        判断目标值是否在这一区域内，这样就可以确定保留哪半边了，代码如下：

        解法一：
    */
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            } else {
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};


class Solution {
public:
    // 2022.7.30, from https://github.com/grandyang/leetcode/issues/33
    /*
        看了上面的解法，你可能会产生个疑问，为啥非得用中间的数字跟最右边的比较呢？难道跟最左边的数字比较不行吗，
        当中间的数字大于最左边的数字时，左半段也是有序的啊，如下所示（蓝色表示中点之前一定为有序的）：

        0　　1　　2　　4 　　5　　6　　7

        7　　0　　1　　2　　4　　5　　6

        6　　7　　0　　1　　2　　4　　5

        5　　6　　7　　0　　1　　2　　4

        4　　5　　6　　7 　　0　　1　　2

        2　　4　　5　　6 　　7　　0　　1

        1　　2　　4　　5 　　6　　7　　0

        貌似也可以做，但是有一个问题，那就是在二分搜索中，nums[mid] 和 nums[left] 还有可能相等的，
        当数组中只有两个数字的时候，比如 [3, 1]，那该去取那一边呢？由于只有两个数字且 nums[mid] 
        不等于 target，target 只有可能在右半边出现。最好的方法就是让其无法进入左半段，就需要左半段
        是有序的，而且由于一定无法同时满足 nums[left] <= target && nums[mid] > target，因为 
        nums[left] 和 nums[mid] 相等，同一个数怎么可能同时大于等于 target，又小于 target。
        由于这个条件不满足，则直接进入右半段继续搜索即可，所以等于的情况要加到 nums[mid] > nums[left] 
        的情况中，变成大于等于，参见代码如下：

        解法二：
    */
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            } else {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

