/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

/*

https://leetcode.cn/problems/peak-index-in-a-mountain-array/

852. 山脉数组的峰顶索引
符合下列属性的数组 arr 称为 山脉数组 ：
arr.length >= 3
存在 i（0 < i < arr.length - 1）使得：
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
给你由整数组成的山脉数组 arr ，返回任何满足 arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... 
> arr[arr.length - 1] 的下标 i 。
 

示例 1：

输入：arr = [0,1,0]
输出：1

示例 2：

输入：arr = [0,2,1,0]
输出：1

示例 3：

输入：arr = [0,10,5,2]
输出：1

示例 4：

输入：arr = [3,4,5,1]
输出：2

示例 5：

输入：arr = [24,69,100,99,79,78,67,36,26,19]
输出：2
 

提示：

3 <= arr.length <= 104
0 <= arr[i] <= 106
题目数据保证 arr 是一个山脉数组
 

进阶：很容易想到时间复杂度 O(n) 的解决方案，你可以设计一个 O(log(n)) 的解决方案吗？

通过次数122,715提交次数177,460

*/

// @lc code=start
class Solution100 {
public:
    // 2022.9.8, by Hsinan
    int peakIndexInMountainArray(vector<int>& arr) {
        auto item = max_element(arr.begin(), arr.end());
        if (item != arr.end()) {
            return std::distance(arr.begin(), item);
        } else {
            return -1;
        }
    }
};


class Solution99 {
public:
    // 2022.9.8, by Hsinan
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (arr[middle] > arr[middle + 1]) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        return left;
    }
};


class Solution98 {
public:
    // 2022.9.8, from https://www.acwing.com/activity/content/code/content/1231956/
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1, r = arr.size() - 2;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (arr[mid] > arr[mid - 1]) l = mid;
            else r = mid - 1;
        }
        return r;
    }
};


class Solution97 {
public:
    // 2022.9.8, from https://github.com/grandyang/leetcode/issues/852
    /*
        这道题定义了一种山形的数组，说是有一个最高点，然后向两边各自降低，让我们找出山峰的位置。其实这道题跟之前那道 
        Find Peak Element 非常的类似，只不过那道题有很多局部峰值，而这里道题只有一个全局峰值。题目中限定了山峰一定
        存在，即一定有一个最高点，反应在数组中就是最大值，那么问题就转换为了求数组中最大值的位置，最简单直接的方法就
        是遍历数组找出最大值的位置即可，这里使用了 STL 的内置函数 max_element() 来一行解题，参见代码如下：
        解法一：
    */
    int peakIndexInMountainArray(vector<int>& A) {
		return max_element(A.begin(), A.end()) - A.begin();
    }
};


class Solution96 {
public:
    // 2022.9.8, from https://github.com/grandyang/leetcode/issues/852
    /*
        由于题目中限定了山峰一定存在，所以我们也可以直接直接来找第一个下降的位置，即 A[i] > A[i+1] 的地方，那么i位置一定
        就是山峰了，注意i的遍历范围要去掉首尾两个数字，参见代码如下：
        解法二：
    */
    int peakIndexInMountainArray(vector<int>& A) {
		for (int i = 1; i < (int)A.size() - 1; ++i) {
			if (A[i] > A[i + 1]) return i;
		}
		return 0;
    }
};


class Solution95 {
public:
    // 2022.9.8, from https://github.com/grandyang/leetcode/issues/852
    /*
        上面两种解法都是线性的时间复杂度，能不能更快一点呢？那么就只有使用二分搜索法来加快搜索速度了，其实这是博主的总结帖 
        LeetCode Binary Search Summary 二分搜索法小结 中的第五类情况，跟前的稍有不同的是 right 的初始化，之前的情况
        博主基本上都是用数组长度初始化 right 的，但是这里要用数组长度减1来初始化 right，因为要跟紧邻的右边的数字比较，
        这样初始化 right 的意义在于 mid+1 就不会越界了，参见代码如下：
        解法三：
    */
    int peakIndexInMountainArray(vector<int>& A) {
		int n = A.size(), left = 0, right = n - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (A[mid] < A[mid + 1]) left = mid + 1;
			else right = mid;
		}
        return right;
    }
};


class Solution94 {
public:
    // 2022.9.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/peak-index-in-a-mountain-array.cpp
    // Time:  O(logn)
    // Space: O(1)
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = size(arr) - 1;
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};


class Solution93 {
public:
    // 2022.9.8, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/852.%20Peak%20Index%20in%20a%20Mountain%20Array
    // OJ: https://leetcode.com/problems/peak-index-in-a-mountain-array/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    // Solution 1. Linear Search
    int peakIndexInMountainArray(vector<int>& A) {
        int i = 1;
        while (i < A.size() && A[i] > A[i - 1]) ++i;
        return i - 1;
    }
};


class Solution92 {
public:
    // 2022.9.8, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/852.%20Peak%20Index%20in%20a%20Mountain%20Array
    // OJ: https://leetcode.com/problems/peak-index-in-a-mountain-array/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    // Solution 2. Binary Search
    int peakIndexInMountainArray(vector<int>& A) {
        int L = 1, R = A.size() - 2;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] > A[M - 1]) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};


class Solution {
public:
    // 2022.9.8, from https://walkccc.me/LeetCode/problems/0852/
    // Time: O(logn)
    // Space: O(1)
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size() - 1;

        while (l < r) {
        const int m = (l + r) / 2;
        if (arr[m] < arr[m + 1])
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

