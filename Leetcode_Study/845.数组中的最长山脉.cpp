/*
 * @lc app=leetcode.cn id=845 lang=cpp
 *
 * [845] 数组中的最长山脉
 */

/*

https://leetcode.cn/problems/longest-mountain-in-array/

845. 数组中的最长山脉
中等
257
company
彭博 Bloomberg

把符合下列属性的数组 arr 称为 山脉数组 ：

arr.length >= 3
存在下标 i（0 < i < arr.length - 1），满足
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
给出一个整数数组 arr，返回最长山脉子数组的长度。如果不存在山脉子数组，返回 0 。

示例 1：

输入：arr = [2,1,4,7,3,2,5]
输出：5
解释：最长的山脉子数组是 [1,4,7,3,2]，长度为 5。

示例 2：

输入：arr = [2,2,2]
输出：0
解释：不存在山脉子数组。 

提示：

1 <= arr.length <= 104
0 <= arr[i] <= 104

进阶：

你可以仅用一趟扫描解决此问题吗？
你可以用 O(1) 空间解决此问题吗？

*/

// @lc code=start
class Solution100 {
public:
    // 2023.2.24, from https://leetcode.cn/problems/longest-mountain-in-array/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/1208074/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> l(n, 1), r(n, 1);
        for (int i = 1; i < n; i ++ )
            if (arr[i] > arr[i - 1])
                l[i] = l[i - 1] + 1;
        for (int i = n - 2; i >= 0; i -- )
            if (arr[i] > arr[i + 1])
                r[i] = r[i + 1] + 1;

        int res = 0;
        for (int i = 0; i < n; i ++ )
            if (l[i] > 1 && r[i] > 1)
                res = max(res, l[i] + r[i] - 1);
        return res;
    }
};


class Solution99 {
public:
    // 2023.2.24, from https://walkccc.me/LeetCode/problems/0845/
    // Time: O(n)
    // Space: O(1)
    int longestMountain(vector<int>& arr) {
        int ans = 0;

        for (int i = 0; i + 1 < arr.size();) {
        while (i + 1 < arr.size() && arr[i] == arr[i + 1])
            ++i;

        int increasing = 0;
        int decreasing = 0;

        while (i + 1 < arr.size() && arr[i] < arr[i + 1]) {
            ++increasing;
            ++i;
        }

        while (i + 1 < arr.size() && arr[i] > arr[i + 1]) {
            ++decreasing;
            ++i;
        }

        if (increasing > 0 && decreasing > 0)
            ans = max(ans, increasing + decreasing + 1);
        }

        return ans;
    }
};


class Solution98 {
public:
    // 2023.2.24, from https://github.com/grandyang/leetcode/issues/845
    /*
        这道题给了我们一个数组，然后定义了一种像山一样的子数组，就是先递增再递减的子数组，注意这里是强行递增或者递减的，
        并不存在相等的情况。那么实际上这道题就是让在数组中寻找一个位置，使得以此位置为终点的递增数组和以此位置为起点的递减
        数组的长度最大。而以某个位置为起点的递减数组，如果反个方向来看，其实就是就该位置为终点的递增数列，那么既然都是
        求最长的递增数列，我们可以分别用两个 dp 数组 up 和 down，其中 up[i] 表示以 i 位置为终点的最长递增数列的个数，
        down[i] 表示以 i 位置为起点的最长递减数列的个数，这样我们正向更新 up 数组，反向更新 down 数组即可。先反向更新
        好了 down 之后，在正向更新 up 数组的同时，也可以更新结果 res，当某个位置的 up[i] 和 down[i] 均大于0的时候，
        那么就可以用 up[i] + down[i] + 1 来更新结果 res 了，参见代码如下：

        解法一：    
    */
    int longestMountain(vector<int>& A) {
        int res = 0, n = A.size();
        vector<int> up(n), down(n);
        for (int i = n - 2; i >= 0; --i) {
            if (A[i] > A[i + 1]) down[i] = down[i + 1] + 1;
        }
        for (int i = 1; i < n; ++i) {
            if (A[i] > A[i - 1]) up[i] = up[i - 1] + 1;
            if (up[i] > 0 && down[i] > 0) res = max(res, up[i] + down[i] + 1);
        }
        return res;
    }
};


class Solution97 {
public:
    // 2023.2.24, from https://github.com/grandyang/leetcode/issues/845
    /*
        我们可以对空间进行优化，不必使用两个数组来记录所有位置的信息，而是只用两个变量 up 和 down 来分别记录以当前位置为
        终点的最长递增数列的长度，和以当前位置为终点的最长递减数列的长度。 我们从 i=1 的位置开始遍历，因为山必须要有上坡
        和下坡，所以 i=0 的位置永远不可能成为 peak。此时再看，如果当前位置跟前面的位置相等了，那么当前位置的 up 和 down 
        都要重置为0，从当前位置开始找新的山，和之前的应该断开。或者是当 down 不为0，说明此时是在下坡，如果当前位置大于之前
        的了，突然变上坡了，那么之前的累计也需要重置为0。然后当前位置再进行判断，若大于前一个位置，则是上坡，up 自增1，
        若小于前一个位置，是下坡，down 自增1。当 up 和 down 同时为正数，则用 up+down+1 来更新结果 res 即可，参见代码如下：

        解法二：    
    */
    int longestMountain(vector<int>& A) {
        int res = 0, up = 0, down = 0, n = A.size();
        for (int i = 1; i < n; ++i) {
            if ((down && A[i - 1] < A[i]) || (A[i - 1] == A[i])) {
                up = down = 0;
            }
            if (A[i - 1] < A[i]) ++up;
            if (A[i - 1] > A[i]) ++down;
            if (up > 0 && down > 0) res = max(res, up + down + 1);
        }
        return res;
    }
};


class Solution96 {
public:
    // 2023.2.24, from https://github.com/grandyang/leetcode/issues/845
    /*
        我们可以换一种思路，还是一次遍历就行，进行 while 循环，条件是 i < n-1，然后判断，当前数字大于等于下一个数字则跳过，
        因为我们希望首先上坡，当找到递增的起点i后，则再开始循环，找山顶 peak，找到了之后，再进行下坡，找到山脚j，这样如果i，
        peak，和j都不相同的话，说明找到了一个完整的山，用 j-i+1 来更新结果 res 即可，然后i从j开始继续遍历，参见代码如下：

        解法三：    
    */
    int longestMountain(vector<int>& A) {
        int res = 0, i = 0, n = A.size();
        while (i < n - 1) {
            while (i < n - 1 && A[i] >= A[i + 1]) ++i;
            int peak = i;
            while (peak < n - 1 && A[peak] < A[peak + 1]) ++peak;
            int j = peak;
            while (j < n - 1 && A[j] > A[j + 1]) ++j;
            if (i < peak && peak < j) res = max(res, j - i + 1);
            i = j;
        }
        return res;
    }
};


class Solution95 {
public:
    // 2023.2.24, from https://github.com/grandyang/leetcode/issues/845
    /*
        也可以再换种思路，首先来找山峰，peak 的范围是 [1, n-1]，因为首尾两个数字都不能做山峰，能做山峰的位置上的数必须大于其左右
        两边的数字，然后分别向左右两个方向遍历，这样就可以找到完整的山，用 right-left+1 来更新结果 res，参见代码如下：

        解法四：    
    */
    int longestMountain(vector<int>& A) {
        int res = 0, n = A.size();
        for (int i = 1; i < n - 1; ++i) {
            if (A[i - 1] < A[i] && A[i + 1] < A[i]) {
                int left = i - 1, right = i + 1;
                while (left > 0 && A[left - 1] < A[left]) --left;
                while (right < n - 1 && A[right] > A[right + 1]) ++right;
                res = max(res, right - left + 1);
            }
        }
        return res;
    }
};


class Solution94 {
public:
    // 2023.2.24, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/longest-mountain-in-array.cpp
    // Time:  O(n)
    // Space: O(1)
    int longestMountain(vector<int>& A) {
        int result = 0, up_len = 0, down_len = 0;
        for (int i = 1; i < A.size(); ++i) {
            if ((down_len && A[i - 1] < A[i]) ||
                A[i - 1] == A[i]) {
                up_len = down_len = 0;
            }
            up_len += A[i - 1] < A[i];
            down_len += A[i - 1] > A[i];
            if (up_len && down_len) {
                result= max(result, up_len + down_len + 1);
            }
        }
        return result;
    }
};


class Solution93 {
public:
    // 2023.2.24, from https://zxi.mytechroad.com/blog/?s=LeetCode+845.
    // Author: Huahua
    // Running time: 24 ms
    // Time complexity: O(n)
    // Space complexity: O(n)
    int longestMountain(vector<int>& A) {
        vector<int> inc(A.size());
        vector<int> dec(A.size());
        for (int i = 1; i < A.size(); ++i)
        if (A[i] > A[i - 1]) inc[i] = inc[i - 1] + 1;
        for (int i = A.size() - 2; i > 0; --i)
        if (A[i] > A[i + 1]) dec[i] = dec[i + 1] + 1;
        int ans = 0;
        for (int i = 0; i < A.size(); ++i)
        if (inc[i] && dec[i])
            ans = max(ans, inc[i] + dec[i] + 1);    
        return ans >= 3 ? ans : 0;
    }
};


class Solution92 {
public:
    // 2023.2.24, from https://zxi.mytechroad.com/blog/?s=LeetCode+845.
    // Author: Huahua
    // Running time: 24 ms
    // Time complexity: O(n)
    // Space complexity: O(1)
    int longestMountain(vector<int>& A) {
        int inc = 0;
        int dec = 0;
        int ans = 0;
        for (int i = 1; i < A.size(); ++i) {
        if (dec && A[i] > A[i - 1] || A[i] == A[i - 1]) 
            dec = inc = 0;
        inc += A[i] > A[i - 1];
        dec += A[i] < A[i - 1];
        if (inc && dec)
            ans = max(ans, inc + dec + 1);
        }
        return ans >= 3 ? ans : 0;
    }
};


class Solution {
public:
    // 作者：xzp
    // 链接：https://leetcode.cn/leetbook/read/sliding-window-and-two-pointers/rwarmt/?discussion=6PtiNz
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int l = 0 , r = 0 , ans = 0;
        while(r < n - 1){
            int flag = 0;
            l = r;
            if(arr[r] >= arr[r + 1]){
                r++;
                continue;
            }
            while(r < n - 1 && arr[r] < arr[r + 1]) r++;
            while(r < n - 1 && arr[r] > arr[r + 1]) {
                r++;
                flag = 1;
                ans = max(ans , r - l + 1) * flag;
            }
        }
        return ans;
    }
};


// @lc code=end

