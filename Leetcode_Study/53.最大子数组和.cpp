/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

/*

https://leetcode.cn/problems/maximum-subarray/

53. 最大子数组和
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。
 

示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

示例 2：

输入：nums = [1]
输出：1

示例 3：

输入：nums = [5,4,-1,7,8]
输出：23
 

提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。

通过次数1,148,767提交次数2,096,299

*/

// @lc code=start
class Solution100 {
public:
    // 2022.8.13, from https://www.acwing.com/activity/content/code/content/362176/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/362176/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    // DP 时间O(n)，空间 O(1)
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        for (int i = 0, last = 0; i < nums.size(); i ++ ) {
            last = nums[i] + max(last, 0);
            res = max(res, last);
        }
        return res;
    }
};

class Solution99 {
public:
    // 2022.8.13, from https://www.acwing.com/activity/content/code/content/362176/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/362176/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    // 分治 时间O(n)，空间 O(logn)
    struct Node {
        int sum, s, ls, rs;
    };

    Node build(vector<int>& nums, int l, int r) {
        if (l == r) {
            int v = max(nums[l], 0);
            return {nums[l], v, v, v};
        }

        int mid = (l + r) >> 1;
        auto L = build(nums, l, mid), R = build(nums, mid + 1, r);
        Node res;
        res.sum = L.sum + R.sum;
        res.s = max(max(L.s, R.s), L.rs + R.ls);
        res.ls = max(L.ls, L.sum + R.ls);
        res.rs = max(R.rs, R.sum + L.rs);
        return res;
    }

    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        for (auto x: nums) res = max(res, x);
        if (res < 0) return res;
        auto t = build(nums, 0, nums.size() - 1);
        return t.s;
    }
};


class Solution98 {
public:
    // 2022.8.13, from https://github.com/grandyang/leetcode/issues/53
    /*
        这道题让求最大子数组之和，并且要用两种方法来解，分别是 O(n) 的解法，还有用分治法 Divide and Conquer Approach，
        这个解法的时间复杂度是 O(nlgn)，那就先来看 O(n) 的解法，这个方法叫做卡达内算法 Kadane's Algorithm，卡卡和齐达
        内的合体？可以参见维基百科上的这个帖子，定义两个变量 res 和 curSum，其中 res 保存最终要返回的结果，即最大的子数组
        之和，curSum 初始值为0，每遍历一个数字 num，比较 curSum + num 和 num 中的较大值存入 curSum，然后再把 res 和 
        curSum 中的较大值存入 res，以此类推直到遍历完整个数组，可得到最大子数组的值存在 res 中，代码如下：
    */
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, curSum = 0;
        for (int num : nums) {
            curSum = max(curSum + num, num);
            res = max(res, curSum);
        }
        return res;
    }
};


class Solution97 {
public:
    // 2022.8.13, from https://github.com/grandyang/leetcode/issues/53
    /*
        题目还要求我们用分治法 Divide and Conquer Approach 来解，这个分治法的思想就类似于二分搜索法，需要把数组一分为二，
        分别找出左边和右边的最大子数组之和，然后还要从中间开始向左右分别扫描，求出的最大值分别和左右两边得出的最大值相比较取最
        大的那一个，代码如下：
    */
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        return helper(nums, 0, (int)nums.size() - 1);
    }
    int helper(vector<int>& nums, int left, int right) {
        if (left >= right) return nums[left];
        int mid = left + (right - left) / 2;
        int lmax = helper(nums, left, mid - 1);
        int rmax = helper(nums, mid + 1, right);
        int mmax = nums[mid], t = mmax;
        for (int i = mid - 1; i >= left; --i) {
            t += nums[i];
            mmax = max(mmax, t);
        }
        t = mmax;
        for (int i = mid + 1; i <= right; ++i) {
            t += nums[i];
            mmax = max(mmax, t);
        }
        return max(mmax, max(lmax, rmax));
    }
};


class Solution96 {
public:
    // 2022.8.13, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/maximum-subarray.cpp
    // Time:  O(n)
    // Space: O(1)
    int maxSubArray(vector<int>& nums) {
        int result = numeric_limits<int>::min();
        int curr = numeric_limits<int>::min();
        for (const auto &x : nums) {
            curr = (curr == numeric_limits<int>::min()) ? x : max(curr + x, x);
            result = max(result, curr);
        }
        return result;
    }
};


class Solution95 {
public:
    // 2022.8.13, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/53.%20Maximum%20Subarray
    // OJ: https://leetcode.com/problems/maximum-subarray/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    /*
        We can first get the rolling sum so that sum[i] = nums[0] + ... + nums[i]. With partial_sum 
        we can do that in place.

        Then this problem is almost the same as 121. Best Time to Buy and Sell Stock -- finding the 
        maximum sum[j] - sum[i] where j > i. The only difference is that the sub array can start at index 0, 
        so we also need to take sum[i] where 0 <= i < N into consideration. So the "minimum sum we've seen 
        so far" should be initialized as 0.
    */
    int maxSubArray(vector<int>& nums) {
        partial_sum(nums.begin(), nums.end(), nums.begin());
        int minSum = 0, ans = INT_MIN;
        for (int n : nums) {
            ans = max(ans, n - minSum);
            minSum = min(minSum, n);
        }
        return ans;
    }
};


class Solution94 {
public:
    // 2022.8.13, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/53.%20Maximum%20Subarray
    // OJ: https://leetcode.com/problems/maximum-subarray/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    int maxSubArray(vector<int>& A) {
        int mn = 0, sum = 0, ans = INT_MIN;
        for (int n : A) {
            sum += n;
            ans = max(ans, sum - mn);
            mn = min(mn, sum);
        }
        return ans;
    }
};


class Solution93 {
public:
    // 2022.8.13, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/53.%20Maximum%20Subarray
    // OJ: https://leetcode.com/problems/maximum-subarray/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(N)
    /*
        Let dp[i + 1] be the sum of maximum subarray ending with nums[i].

        dp[i + 1] = max{
                        dp[i] + A[i],   if dp[i] > 0
                        A[i]            if dp[i] <= 0
                    }
        Or

        dp[i + 1] = max(dp[i], 0) + A[i]
        Where 0 <= i < N. Note that we can set dp[0] = 0 so that the equation stay true for i = 0.

        The result is max{ dp[1], ..., dp[N] }.
    */
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, N = nums.size();
        vector<int> dp(N + 1, 0);
        for (int i = 0; i < N; ++i) ans = max(ans, dp[i + 1] = max(dp[i], 0) + nums[i]);
        return ans;
    }
};


class Solution92 {
public:
    // 2022.8.13, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/53.%20Maximum%20Subarray
    // OJ: https://leetcode.com/problems/maximum-subarray/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    /*
        We can optimize Solution 2 by storing dp in nums so that the space complexity is reduced from O(N) 
        to O(1).
    */
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += max(nums[i - 1], 0);
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};



class Solution91 {
public:
    // 2022.8.13, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/53.%20Maximum%20Subarray
    // OJ: https://leetcode.com/problems/maximum-subarray/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    /*
        What if we are not allowed th change the value in nums array?

        Since dp[i+1] is only dependent on dp[i], we can use O(1) space to store dp array -- 
        only store the last value.

        So we put the maximum subarray sum we've seen thus far into the cur variable. When we 
        need to update cur for the current nums[i], we can simply do cur = max(cur, 0) + n.
    */
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, cur = INT_MIN;
        for (int n : nums) {
            cur = max(cur, 0) + n;
            ans = max(ans, cur);
        }
        return ans;
    }
};


class Solution90 {
private:
    // 2022.8.13, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/53.%20Maximum%20Subarray
    // OJ: https://leetcode.com/problems/maximum-subarray/
    // Author: github.com/lzl124631x
    // Time: O(NlogN)
    // Space: O(logN)
    /*
        https://leetcode.com/problems/maximum-subarray/solution/
    */
    int crossSum(vector<int>& nums, int L, int R, int p) {
        if (L == R) return nums[L];
        int left = INT_MIN, right = INT_MIN, i, sum;
        for (i = p, sum = 0; i >= L; --i) left = max(left, sum += nums[i]);
        for (i = p + 1, sum = 0; i <= R; ++i) right = max(right, sum += nums[i]);
        return left + right;
    }
    
    int helper(vector<int>& nums, int L, int R) {
        if (L == R) return nums[L];
        int p = (L + R) / 2;
        int left = helper(nums, L, p);
        int right = helper(nums, p + 1, R);
        int cross = crossSum(nums, L, R, p);
        return max(left, max(right, cross));
    }
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};


class Solution89 {
public:
    // 2022.8.13, from https://walkccc.me/LeetCode/problems/0053/
    // Approach 1: Gready
    // Time: O(n)
    // Space: O(1)
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;

        for (const int num : nums) {
        sum += num;
        ans = max(ans, sum);
        sum = max(sum, 0);
        }

        return ans;
    }
};


struct T {
  int left;   // sum of the subarray w/ max sum (starting from the first num)
  int right;  // sum of the subarray w/ max sum (ending at the the last num)
  int mid;    // sum of the subarray w/ max sum
  int sum;    // sum of the whole array
};

class Solution88 {
public:
    // 2022.8.13, from https://walkccc.me/LeetCode/problems/0053/
    // Approach 2: Divide and Conquer
    // Time: O(nlog n)
    // Space: O(log n)
    int maxSubArray(vector<int>& nums) {
        return divideAndConquer(nums, 0, nums.size() - 1).mid;
    }

private:
    T divideAndConquer(const vector<int>& nums, int l, int r) {
        if (l == r)
        return {nums[l], nums[l], nums[l], nums[l]};

        const int m = (l + r) / 2;
        const T t1 = divideAndConquer(nums, l, m);
        const T t2 = divideAndConquer(nums, m + 1, r);

        const int left = max(t1.left, t1.sum + t2.left);
        const int right = max(t1.right + t2.sum, t2.right);
        const int mid = max({t1.right + t2.left, t1.mid, t2.mid});
        const int sum = t1.sum + t2.sum;
        return {left, right, mid, sum};
    }
};


class Solution87 {
public:
    // 2022.8.13, from https://walkccc.me/LeetCode/problems/0053/
    // Approach 3: DP
    // Time: O(n)
    // Space: O(n)
    int maxSubArray(vector<int>& nums) {
        // dp[i] := max sum subarray ending w/ nums[i]
        vector<int> dp(nums.size());

        for (int i = 0; i < nums.size(); ++i)
        if (i > 0 && dp[i - 1] > 0)
            dp[i] = dp[i - 1] + nums[i];
        else
            dp[i] = nums[i];

        return *max_element(begin(dp), end(dp));
    }
};


class Solution86 {
public:
    // 2022.8.13, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0053.%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C.md
    /*
        暴力解法的思路，第一层for 就是设置起始位置，第二层for循环遍历数组寻找最大值
        时间复杂度：O(n^2)
        空间复杂度：O(1)
    */
    // NOTE: This solution will NOT work now as of 2022.8.13, it will TLE
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) { // 设置起始位置
            count = 0;
            for (int j = i; j < nums.size(); j++) { // 每次从起始位置i开始遍历寻找最大值
                count += nums[j];
                result = count > result ? count : result;
            }
        }
        return result;
    }
};


class Solution85 {
public:
    // 2022.8.13, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0053.%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C.md
    /*
        贪心解法
        贪心贪的是哪里呢？

        如果 -2 1 在一起，计算起点的时候，一定是从1开始计算，因为负数只会拉低总和，这就是贪心贪的地方！
        局部最优：当前“连续和”为负数的时候立刻放弃，从下一个元素重新计算“连续和”，因为负数加上下一个元素 “连续和”只会越来越小。

        全局最优：选取最大“连续和”

        局部最优的情况下，并记录最大的“连续和”，可以推出全局最优。

        从代码角度上来讲：遍历nums，从头开始用count累积，如果count一旦加上nums[i]变为负数，那么就应该从nums[i+1]开始从0累积
        count了，因为已经变为负数的count，只会拖累总和。

        这相当于是暴力解法中的不断调整最大子序和区间的起始位置。

        那有同学问了，区间终止位置不用调整么？ 如何才能得到最大“连续和”呢？

        区间的终止位置，其实就是如果count取到最大值了，及时记录下来了。例如如下代码：

        if (count > result) result = count;
        这样相当于是用result记录最大子序和区间和（变相的算是调整了终止位置）。

        如动画所示：

        红色的起始位置就是贪心每次取count为正数的时候，开始一个区间的统计。

        那么不难写出如下C++代码（关键地方已经注释）

        时间复杂度：O(n)
        空间复杂度：O(1)

        当然题目没有说如果数组为空，应该返回什么，所以数组为空的话返回啥都可以了。

        不少同学认为 如果输入用例都是-1，或者 都是负数，这个贪心算法跑出来的结果是0， 这是又一次证明脑洞模拟不靠谱的经典案例，
        建议大家把代码运行一下试一试，就知道了，也会理解 为什么 result 要初始化为最小负数了。
    */
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result) { // 取区间累计的最大值（相当于不断确定最大子序终止位置）
                result = count;
            }
            if (count <= 0) count = 0; // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
        }
        return result;
    }
};


class Solution84 {
public:
    // 2022.8.13, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0053.%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C.md
    /*
        动态规划
        当然本题还可以用动态规划来做，当前「代码随想录」主要讲解贪心系列，后续到动态规划系列的时候会详细讲解本题的dp方法。

        那么先给出我的dp代码如下，有时间的录友可以提前做一做：

        时间复杂度：O(n)
        空间复杂度：O(n)

        总结
        本题的贪心思路其实并不好想，这也进一步验证了，别看贪心理论很直白，有时候看似是常识，但贪心的题目一点都不简单！
        后续将介绍的贪心题目都挺难的，哈哈，所以贪心很有意思，别小看贪心！
    */
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 0); // dp[i]表示包括i之前的最大连续子序列和
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 状态转移公式
            if (dp[i] > result) result = dp[i]; // result 保存dp[i]的最大值
        }
        return result;
    }
};


class Solution83 {
public:
    // 2022.8.13, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0053.%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C.md
    /*
        思路
        这道题之前我们在讲解贪心专题的时候用贪心算法解决过一次，贪心算法：最大子序和。
        这次我们用动态规划的思路再来分析一次。

        动规五部曲如下：

        1. 确定dp数组（dp table）以及下标的含义
            dp[i]：包括下标i之前的最大连续子序列和为dp[i]。

        2. 确定递推公式
            dp[i]只有两个方向可以推出来：

            dp[i - 1] + nums[i]，即：nums[i]加入当前连续子序列和
            nums[i]，即：从头开始计算当前连续子序列和
            一定是取最大的，所以dp[i] = max(dp[i - 1] + nums[i], nums[i]);

        3. dp数组如何初始化
            从递推公式可以看出来dp[i]是依赖于dp[i - 1]的状态，dp[0]就是递推公式的基础。

            dp[0]应该是多少呢?

            根据dp[i]的定义，很明显dp[0]应为nums[0]即dp[0] = nums[0]。

        4. 确定遍历顺序
            递推公式中dp[i]依赖于dp[i - 1]的状态，需要从前向后遍历。

        5. 举例推导dp数组
            以示例一为例，输入：nums = [-2,1,-3,4,-1,2,1,-5,4]，对应的dp状态如下：
            注意最后的结果可不是dp[nums.size() - 1]！ ，而是dp[6]。
            在回顾一下dp[i]的定义：包括下标i之前的最大连续子序列和为dp[i]。
            那么我们要找最大的连续子序列，就应该找每一个i为终点的连续最大子序列。
            所以在递推公式的时候，可以直接选出最大的dp[i]。

        以上动规五部曲分析完毕，完整代码如下：

        时间复杂度：O(n)
        空间复杂度：O(n)

        总结
        这道题目用贪心也很巧妙，但有一点绕，需要仔细想一想，如果想回顾一下贪心就看这里吧：贪心算法：最大子序和
        动规的解法还是很直接的。
    */
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 状态转移公式
            if (dp[i] > result) result = dp[i]; // result 保存dp[i]的最大值
        }
        return result;
    }
};


class Solution82 {
public:
    // 2022.8.13, from https://github.com/wisdompeak/LeetCode/blob/master/Dynamic_Programming/053.Maximum-Subarray/053.Maximum-Subarray.cpp
    /*
        本题是一道经典题，其算法类似动态规划，称之为Kadane算法。

        我们考虑每个以i截止的maximum subarray是什么？显然对于i而言，它只有两种选择：

        1. 这样的subarray里面，i是接在元素i-1后面。为了使得subarray最大，自然问题就转化为希望得到以i-1结尾的
            maximum subarray。
        2. 这样的subarray里面，i不是接在前一个元素之后。这就意味着自己是这个maximum subarray中的唯一一个元素。
        
        所以，我们定义dp[i]表示以元素i结尾的maximum subarray的和。那么dp[i]就是上面两种方案中取较大的值。
        因为我们并不知道全局最大的subarray的截止点在哪里，所以最终的答案就是所有dp[i]中的最大值。
    */
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();                
        vector<int>dp(n);
        dp[0] = nums[0];
        int ret = nums[0];
        
        for (int i=1; i<n; i++)
        {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);                
            ret = max(dp[i],ret);
        }
        
        return ret;        
    }
};


class Solution {
public:
    // 2022.8.13, from https://ke.algomooc.com/detail/v_628a513de4b09dda126bc4d2/3?from=p_6243bcc1e4b04e8d90291891&type=8&parent_pro_id=p_628a35d3e4b0812e179cf4bc
    int maxSubArray(vector<int>& nums) {
        // 因为后面会使用到 nums 的长度
        // 所以先进行判空操作
        // 如果数组 nums 为空，返回 0
        if(nums.size() == 0) return 0;

        // 获取数组的长度
        int n = nums.size();

        // 设置一个数组 dp，长度和数组 nums 长度一致
        // dp[0] 表示以第 0 个元素结尾的最大子数组的和
        // dp[1] 表示以第 1 个元素结尾的最大子数组的和
        // dp[i] 表示以第 i 个元素结尾的最大子数组的和
        vector<int> dp( n , 0 );

        // dp[0] 表示以第 0 个元素结尾的最大子数组的和
        // 初始化 dp[0]
        dp[0] = nums[0];

        // 变量 maxNum 表示数组 dp 中最大的那个值
        // 即 maxNum 表示最大的连续字段和
        int maxNum = dp[0];

        // 从 1 开始遍历数组 nums
        for(int i = 1 ; i < n ;i++){

            // 在遍历的过程中，去获取以第 i 个元素结尾的最大子数组的和
            // 如果以 nums[i-1]结尾的最大字段和为正数
            // 那么以第 i 个元素结尾的最大子数组的和就是自己本身加上以 nums[i-1]结尾的最大字段和
            if(dp[i-1] > 0){
                // dp[i-1] 是正数
                // 所以 dp[i] 的值为 nums[i] 加上 dp[i-1]
                // 因为 正数 + 变量 > 变量
                // dp[i -1] + nums[i] > nums[i]
                dp[i] = dp[i -1] + nums[i];

                // 否则 dp[i-1] 不是正数，为负数或者 0
            }else{
                // 那么 dp[i] 的值为 nums[i]
                // 因为 负数 + 变量 < 变量
                // dp[i -1] + nums[i] < nums[i]
                dp[i] = nums[i];
            }
            
            // 在更新 dp[i] 的过程中，更新 maxNum 的值
            // 如果此时 dp[i] 的值大于了 maxNum
            if(maxNum < dp[i]){
                // 那么 maxNum 更新为 dp[i]
                maxNum = dp[i];
            }
        }

        // 最后返回 maxNum
        return maxNum;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

