/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */

/*

https://leetcode.cn/problems/longest-turbulent-subarray/

978. 最长湍流子数组

中等
216
company
亚马逊
company
微软 Microsoft
company
优步 Uber

给定一个整数数组 arr ，返回 arr 的 最大湍流子数组的长度 。

如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是 湍流子数组 。
更正式地来说，当 arr 的子数组 A[i], A[i+1], ..., A[j] 满足仅满足下列条件时，我们称其为湍流子数组：

若 i <= k < j ：
当 k 为奇数时， A[k] > A[k+1]，且
当 k 为偶数时，A[k] < A[k+1]；
或 若 i <= k < j ：
当 k 为偶数时，A[k] > A[k+1] ，且
当 k 为奇数时， A[k] < A[k+1]。
 
示例 1：

输入：arr = [9,4,2,10,7,8,8,1,9]
输出：5
解释：arr[1] > arr[2] < arr[3] > arr[4] < arr[5]

示例 2：

输入：arr = [4,8,12,16]
输出：2

示例 3：

输入：arr = [100]
输出：1 

提示：

1 <= arr.length <= 4 * 104
0 <= arr[i] <= 109

*/

// @lc code=start
class Solution100 {
public:
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/1423782/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 1;
        for (int i = 1, up = 1, down = 1; i < arr.size(); i ++ ) {
            if (arr[i] > arr[i - 1]) {
                up = down + 1;
                down = 1;
            } else if (arr[i] < arr[i - 1]) {
                down = up + 1;
                up = 1;
            } else {
                down = up = 1;
            }
            res = max(res, max(up, down));
        }
        return res;
    }
};


class Solution99 {
public:
    // 2023.2.11, from https://github.com/grandyang/leetcode/issues/978
    /*
        这道题给了一个数组，定义一种湍流子数组，即数字增减交替，就是先增大再减小再增大等交替进行，或者是先减小再增大再减小等
        交替进行的。现在让找出最长的湍流子数组，并返回长度。首先最无脑的暴力搜索就是遍历所有的子数组，并判断是否是湍流数组，
        这样太不高效了，有点不尊重 OJ 的感觉，估计不会给过。毕竟是道 Medium 题，总得给点面子吧，那就来想一下，我们并不知道湍
        流子数组的起点在哪，也不知道它到底是先增大还是先减小，这样的话其实每个位置都有可能是一个湍流数组的起点或终点，就按终点
        来考虑，每个位置都代表一种状态，而且这道题又是求极值的问题，那么该什么方法是不是就呼之欲出了，来～大声地告诉博主，
        用什么方法？对了，就是动态规划 Dynamic Programming，首先来想怎么定义 dp 数组，要求的是湍流子数组的长度，那么 dp 值
        代表的含义应该也是长度。又因为每个位置都可能是个湍流子数组的终点，并且末尾数字可能是下降或者上升，有两种状态，可以用
        一个二维 dp 数组，也可以用两个一维数组 dec 和 inc 来表示，这里 dec[i] 表示湍流数组的长度，同时其末尾是数字是 arr[i] 
        且是下降的，同理，inc[i] 表示湍流数组的长度，同时其末尾是数字是 arr[i] 且是上升的。数组定义好了，下面是就是找状态转移
        方程了，其实也不难，当前状态跟前一个状态息息相关，首先要比较当前数字和前一个数字的大小关系，若前一个数字大于当前数字，
        则表示下降的关系，则可以更新 dec[i] 为 inc[i-1] + 1，反之，若前一个数字小于当前数字，则表示上升的关系，则可以更新 
        inc[i] 为 dec[i-1] + 1。每次更新完一个位置，从 dec[i] 和 inc[i] 中找出最大的位置，用来更新结果 res 即可，参见代码如下：    
    */
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 1, n = arr.size();
		vector<int> dec(n, 1), inc(n, 1);
		for (int i = 1; i < n; ++i) {
			if (arr[i - 1] > arr[i]) {
				dec[i] = inc[i - 1] + 1;			
			} else if (arr[i - 1] < arr[i]) {
				inc[i] = dec[i - 1] + 1;
			}
            res = max(res, max(dec[i], inc[i]));
		}
		return res;
    }
};


class Solution98 {
public:
    // 2023.2.11, from https://github.com/grandyang/leetcode/issues/978
    /*
        我们可以进一步的更新空间复杂度，因为当前状态仅仅依赖前一个状态，所以没有必要保留所有位置的状态，就只有两个变量就可以了，
        不过要注意的是别忘了及时的将 inc 或 dec 重置为1，当相邻的两个数字相同时，两者还要同时重置1，参见代码如下：    
    */
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 1, n = arr.size(), inc = 1, dec = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] < arr[i - 1]) {
                dec = inc + 1;
                inc = 1;
            } else if (arr[i] > arr[i - 1]) {
                inc = dec + 1;
                dec = 1;
            } else {
                inc = 1;
                dec = 1;
            }
            res = max(res, max(inc, dec));
        }
        return res;
    }
};


class Solution97 {
public:
    // 2023.2.11, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/longest-turbulent-subarray.cpp
    // Time:  O(n)
    // Space: O(1)
    int maxTurbulenceSize(vector<int>& A) {
        static const auto& cmp = [](int a, int b) {
            return a != b ? (a < b ? 1 : -1) : 0;
        };

        int result = 1;
        int start = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (i == A.size() - 1 ||
               cmp(A[i - 1], A[i]) * cmp(A[i], A[i + 1]) != -1) {
                result = max(result, i - start + 1);
                start = i;
            }
        }
        return result;
    }
};


class Solution96 {
public:
    // OJ: https://leetcode.com/problems/longest-turbulent-subarray/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    /*
        Solution 1. DP

        Let inc[i] and dec[i] be the length of the longest turbulent subarray ending at A[i] in A[0..i].
        inc[0] = dec[0] = 1. The answer is the maximum value among all inc[i] and dec[i].

        If A[i] == A[i - 1], we set inc[i] = dec[i] = 1.
        If A[i] > A[i - 1], inc[i] = dec[i-1] + 1 and dec[i] = 1.
        If A[i] < A[i - 1], dec[i] = inc[i-1] + 1 and inc[i] = 1.    
    */
    int maxTurbulenceSize(vector<int>& A) {
        int inc = 1, dec = 1, N = A.size(), ans = 1;
        for (int i = 1; i < N; ++i) {
            if (A[i] == A[i - 1]) inc = dec = 1;
            else if (A[i] > A[i - 1]) {
                inc = dec + 1;
                dec = 1;
            } else {
                dec = inc + 1;
                inc = 1;
            }
            ans = max({ ans, inc, dec });
        }
        return ans;
    }
};


class Solution95 {
public:
    // OJ: https://leetcode.com/problems/longest-turbulent-subarray/solution/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    /*
        Solution 2. DP
        Turn the array to sequence of 1, -1, or 0. If A[i] > A[i-1], B[i-1] = 1. If A[i] < A[i-1], B[i-1] = -1. 
        If A[i] == A[i-1], B[i-1] = 0.

        Now, we need to find the longest subarray with alternating -1 and 1 values.    
    */
    int maxTurbulenceSize(vector<int>& A) {
        int sign = 0, N = A.size(), len = 1, ans = 1;
        for (int i = 1; i < N; ++i) {
            int newSign = A[i] == A[i - 1] ? 0 : (A[i] > A[i - 1] ? 1 : -1);
            if (newSign) {
                if (i == 1 || newSign * sign == -1) ++len;
                else len = 2;
                ans = max(ans, len);
            } else len = 1;
            sign = newSign;
        }
        return ans;
    }
};


class Solution94 {
public:
    // 2023.2.11, from https://walkccc.me/LeetCode/problems/0978/
    int maxTurbulenceSize(vector<int>& A) {
        int ans = 1;
        int increasing = 1;
        int decreasing = 1;

        for (int i = 1; i < A.size(); ++i) {
        if (A[i] > A[i - 1]) {
            increasing = decreasing + 1;
            decreasing = 1;
        } else if (A[i] < A[i - 1]) {
            decreasing = increasing + 1;
            increasing = 1;
        } else {
            increasing = 1;
            decreasing = 1;
        }
        ans = max({ans, increasing, decreasing});
        }

        return ans;
    }
};


class Solution93 {
public:
    // 2023.2.11, from https://github.com/wisdompeak/LeetCode/blob/master/Others/978.Longest-Turbulent-Subarray/978.Longest-Turbulent-Subarray.cpp
    /*
        978.Longest-Turbulent-Subarray
        将原始数组的相邻两个元素做差，如果为正就标记1，如果为负就标记-1，如果相等就标记0. 那么我们就能得到一个长度为n-1的序列q。
        显然，我们需要找q中最长的一段subarray，并且元素是1和-1间隔的。一个等价的判断就是q中的相邻元素的乘积是-1.

        假设我们从i开始作为起点，那么subarray能变长的条件就是q[i]*q[i+1]==-1，这样我们就递增i，直至可以找到最后一个满足条件的
        位置i'，那么q[i:i']就是一段最长的+/-1相间的序列。注意，q是差分元素，所以实际在nums里，subarray长度就是i'-i+2.
    */
    int maxTurbulenceSize(vector<int>& A) 
    {
        int N = A.size();
        vector<int>q(N,0);
        for (int i=0; i<A.size()-1; i++)
        {
            if (A[i]>A[i+1])
                q[i] = -1;
            else if (A[i]<A[i+1])
                q[i] = 1;
        }
               
        int count = 1;        
        int i = 0;
        while (i<q.size())
        {
            if (q[i]==0) 
            {
                i++;
                continue;
            }
            
            int start = i;
            while (i+1<q.size() && q[i]*q[i+1]==-1)            
                i++;
            
            count = max(count, i-start+1+1);
            i++;
        }
        
        return count;
    }
};


class Solution {
public:
    // Author: Huahua, running time: 120 ms
    int maxTurbulenceSize(vector<int>& A) {
        vector<int> up(A.size(), 1);
        vector<int> down(A.size(), 1);
        int ans = 1;
        for (int i = 1; i < A.size(); ++i) {
        if (A[i] > A[i - 1]) up[i] = down[i - 1] + 1;
        if (A[i] < A[i - 1]) down[i] = up[i - 1] + 1;
        ans = max(ans, max(up[i], down[i]));      
        }
        return ans;
    }
};


// @lc code=end

