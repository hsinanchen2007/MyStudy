/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

/*

https://leetcode.cn/problems/max-consecutive-ones-iii/

1004. 最大连续1的个数 III
给定一个二进制数组 nums 和一个整数 k，如果可以翻转最多 k 个 0 ，则返回 数组中连续 1 的最大个数 。
 

示例 1：

输入：nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释：[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。

示例 2：

输入：nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。
 

提示：

1 <= nums.length <= 105
nums[i] 不是 0 就是 1
0 <= k <= nums.length
通过次数100,770提交次数168,217

*/

// @lc code=start
class Solution100 {
public:
    // 2022.8.27, by Hsinan
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int maxRepeat = 0;
        int maxLength = 0;
        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] == 1) maxRepeat++;
            if (end - start + 1 - maxRepeat > k) {
                if (nums[start] == 1) maxRepeat--;
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};


class Solution99 {
public:
    // 2022.8.27, from https://www.acwing.com/activity/content/code/content/2046757/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/2046757/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 0, j = 0, cnt = 0; i < nums.size(); i ++ ) {
            if (!nums[i]) cnt ++ ;
            while (cnt > k) {
                if (!nums[j]) cnt -- ;
                j ++ ;
            }
            res = max(res, i - j + 1);
        }

        return res;
    }
};


class Solution98 {
public:
    // 2022.8.27, from https://github.com/grandyang/leetcode/issues/1004
    /*
        这道题是之前那道 Max Consecutive Ones II 的拓展，博主在之前的解法二中就预言了翻转k次的情况，
        果不其然，在五百多道题之后，该来的还是来了。不过不要紧，我们已经知道了该如何应对了，直接上滑动窗口 
        Sliding Window，用个变量 cnt 记录当前将0变为1的个数，在遍历数组的时候，若遇到了0，则 cnt 
        自增1。若此时 cnt 大于K了，说明该缩小窗口了，用个 while 循环，若左边界为0，移除之后，此时 cnt 
        应该自减1，left 自增1，每次用窗口大小更新结果 res 即可， 参见代码如下：

        解法一：
    */
    int longestOnes(vector<int>& A, int K) {
        int n = A.size(), left = 0, cnt = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 0) ++cnt;
            while (cnt > K) {
                if (A[left] == 0) --cnt;
                ++left;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};


class Solution97 {
public:
    // 2022.8.27, from https://github.com/grandyang/leetcode/issues/1004
    /*
        我们也可以写的更简洁一些，不用 while 循环，但是还是用的滑动窗口的思路，其中i表示左边界，j为右边界。
        在遍历的时候，若遇到0，则K自减1，若K小于0了，且 A[i] 为0，则K自增1，且i自增1，最后返回窗口的大小
        即可，参见代码如下：

        解法二：
    */
    int longestOnes(vector<int>& A, int K) {
        int n = A.size(), i = 0, j = 0;
        for (; j < n; ++j) {
            if (A[j] == 0) --K;
            if (K < 0 && A[i++] == 0) ++K;
        }
        return j - i;
    }
};


class Solution96 {
public:
    // 2022.8.27, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/max-consecutive-ones-iii.cpp
    // Time:  O(n)
    // Space: O(1)
    int longestOnes(vector<int>& A, int K) {
        int result = 0, i = 0;
        for (int j = 0; j < A.size(); ++j) {
            K -= (A[j] == 0) ? 1 : 0;
            while (K < 0) {
                K += (A[i] == 0) ? 1 : 0;
                ++i;
            }
            result = max(result, j - i + 1);
        }
        return result;
    }
};


class Solution95 {
public:
    // 2022.8.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1004.%20Max%20Consecutive%20Ones%20III
    // OJ: https://leetcode.com/problems/max-consecutive-ones-iii/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    // Shrinkable sliding window:
    int longestOnes(vector<int>& A, int k) {
        int i = 0, j = 0, cnt = 0, N = A.size(), ans = 0;
        while (j < N) {
            cnt += A[j++] == 0;
            while (cnt > k) cnt -= A[i++] == 0;
            ans = max(ans, j - i);
        }
        return ans;
    }
};


class Solution94 {
public:
    // 2022.8.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1004.%20Max%20Consecutive%20Ones%20III
    // OJ: https://leetcode.com/problems/max-consecutive-ones-iii/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    // Non-shrinkable sliding window:
    int longestOnes(vector<int>& A, int k) {
        int i = 0, j = 0, cnt = 0, N = A.size();
        while (j < N) {
            cnt += A[j++] == 0;
            if (cnt > k) cnt -= A[i++] == 0;
        }
        return j - i;
    }
};


class Solution93 {
public:
    // 2022.8.27, from https://walkccc.me/LeetCode/problems/1004/
    int longestOnes(vector<int>& A, int K) {
        int ans = 0;

        for (int l = 0, r = 0; r < A.size(); ++r) {
            if (A[r] == 0)
                --K;
            while (K < 0)
                if (A[l++] == 0)
                ++K;
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};


class Solution92 {
public:
    // 2022.8.27, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/1004.Max-Consecutive-Ones-III/1004.Max-Consecutive-Ones-III.cpp
    /*
        解法1：DP
        令dp[i][k]表示截止到第i个元素位置，我们行使了k次翻转权利的话，最长的连续1区间的长度。突破口
        就是第i个元素我们是否进行翻转：

        如果A[i]==1，那么我们不需要翻转，即dp[i][k] = dp[i-1][k]+1
        如果A[i]==0，那么我们需要翻转，即dp[i][k] = dp[i-1][k-1]+1，注意k不能超过题目规定的行使
        反转权利的上限K。 答案就是dp[x][K]中的最大值。以上方法的两层循环的时间复杂度是o(NK)，显然会超时。
    */
    int longestOnes(vector<int>& A, int K) 
    {
        int n = A.size();
        int count = 0;
        int i = 0;
        int ret = 0;
        for (int j=0; j<n; j++)
        {
            if (A[j]==1)
            {
                ret = max(ret, j-i+1);
                continue;
            }
                
            count++;
            while (count>K)
            {
                if (A[i]==0)
                    count--;
                i++;
            }
            ret = max(ret, j-i+1);
        }
        return ret;
    }
};


class Solution {
public:
    // 2022.8.27, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/1004.Max-Consecutive-Ones-III/1004.Max-Consecutive-Ones-III_v2.cpp
    /*
        解法2：双指针
        对于任何求subarray的问题，我们通常的做法就是固定左边界，探索右边界。假设我们固定左边界是i，
        那么要使右边界j最远，需要满足[i,j]最多有K个0。

        此时我们考虑左边界是i+1的情况。如果A[i+1]==1，那么此时[i+1,j]内的需要翻转元素的个数count
        依然是K，然而右边界j依然不能往右突破。我们只有不停地移动i，直到A[i]==0的时候，意味着第i个元素
        的不被允许翻转，所以区间内的翻转次数count-=1，因此右边界就又可以移动，直到找到下一个A[j]==0
        为止（此时count再次变为K）。

        所以两个指针都只会朝一个方向移动。这是快慢类型的双指针，时间复杂度就是o(N).
    */
    int longestOnes(vector<int>& A, int K) 
    {
        int n = A.size();
        int j = 0;
        int ret = 0;
        int count = 0;
        for (int i=0; i<n; i++)
        {
            while (j<n && (A[j]==1 || (A[j]==0 && count<K)))
            {
                if (A[j]==0) count++;                
                j++;                
            }
            ret = max(ret, j-i);
            if (A[i]==0) count--;
        }
        return ret;
        
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

