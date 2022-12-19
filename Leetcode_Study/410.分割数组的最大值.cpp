/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

/*

https://leetcode.cn/problems/split-array-largest-sum/

410. 分割数组的最大值
给定一个非负整数数组 nums 和一个整数 m ，你需要将这个数组分成 m 个非空的连续子数组。

设计一个算法使得这 m 个子数组各自和的最大值最小。
 

示例 1：

输入：nums = [7,2,5,10,8], m = 2
输出：18
解释：
一共有四种方法将 nums 分割为 2 个子数组。 
其中最好的方式是将其分为 [7,2,5] 和 [10,8] 。
因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。

示例 2：

输入：nums = [1,2,3,4,5], m = 2
输出：9

示例 3：

输入：nums = [1,4,4], m = 3
输出：4
 

提示：

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= m <= min(50, nums.length)
通过次数56,820提交次数96,566

*/

// @lc code=start
class Solution100 {
public:
    // 2022.9.3, from https://www.acwing.com/activity/content/code/content/531636/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/531636/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    bool check(vector<int>& nums, int m, int mid) {
        int sum = 0, cnt = 0;
        for (auto x: nums) {
            if (x > mid) return false;
            if (sum + x > mid) {
                cnt ++ ;
                sum = x;
            } else {
                sum += x;
            }
        }
        if (sum) cnt ++ ;
        return cnt <= m;
    }

    int splitArray(vector<int>& nums, int m) {
        int l = 0, r = INT_MAX;
        while (l < r) {
            int mid = (long long)l + r >> 1;
            if (check(nums, m, mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};


class Solution99 {
public:
    // 2022.9.3, from https://github.com/grandyang/leetcode/issues/410
    /*
        这道题给了我们一个非负数的数组 nums 和一个整数m，让把数组分割成m个非空的连续子数组，
        让最小化m个子数组中的最大值。开始以为要用博弈论中的最小最大化算法，可是想了半天发现并
        不会做，于是后面决定采用无脑暴力破解，在 nums 中取出所有的m个子数组的情况都找一遍最
        大值，为了加快求子数组和的运算，还建立了累计和数组，可以还是 TLE 了，所以博主就没有
        办法了，只能上网参考大神们的解法，发现大家普遍使用了二分搜索法来做，感觉特别巧妙，原来
        二分搜索法还能这么用，厉害了我的哥。首先来分析，如果m和数组 nums 的个数相等，那么每
        个数组都是一个子数组，所以返回 nums 中最大的数字即可，如果m为1，那么整个 nums 数组
        就是一个子数组，返回 nums 所有数字之和，所以对于其他有效的m值，返回的值必定在上面两
        个值之间，所以可以用二分搜索法来做。用一个例子来分析，nums = [1, 2, 3, 4, 5], 
        m = 3，将 left 设为数组中的最大值5，right 设为数字之和 15，然后算出中间数为 10，
        接下来要做的是找出和最大且小于等于 10 的子数组的个数，[1, 2, 3, 4], [5]，可以看到
        无法分为3组，说明 mid 偏大，所以让 right=mid，然后再次进行二分查找，算出 mid=7，
        再次找出和最大且小于等于7的子数组的个数，[1,2,3], [4], [5]，成功的找出了三组，说明 
        mid 还可以进一步降低，让 right=mid，再次进行二分查找，算出 mid=6，再次找出和最大且
        小于等于6的子数组的个数，[1,2,3], [4], [5]，成功的找出了三组，尝试着继续降低 mid，
        让 right=mid，再次进行二分查找，算出 mid=5，再次找出和最大且小于等于5的子数组的个数，
        [1,2], [3], [4], [5]，发现有4组，此时的 mid 太小了，应该增大 mid，让 left=mid+1，
        此时 left=6，right=6，循环退出了，返回 right 即可，参见代码如下：
    */
    int splitArray(vector<int>& nums, int m) {
        long left = 0, right = 0;
        for (int i = 0; i < nums.size(); ++i) {
            left = max(left, (long)nums[i]);
            right += nums[i];
        }
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (can_split(nums, m, mid)) right = mid;
            else left = mid + 1;
        }
        return right;
    }
    bool can_split(vector<int>& nums, long m, long sum) {
        long cnt = 1, curSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            curSum += nums[i];
            if (curSum > sum) {
                curSum = nums[i];
                ++cnt;
                if (cnt > m) return false;
            }
        }
        return true;
    }
};


class Solution98 {
public:
    // 2022.9.3, from https://github.com/grandyang/leetcode/issues/410
    /*
        上面的解法相对来说比较难想，在热心网友 perthblank 的提醒下，再来看一种 DP 的解法，相对来说，
        这种方法应该更容易理解一些。建立一个二维数组 dp，其中 dp[i][j] 表示将数组中前j个数字分成i组
        所能得到的最小的各个子数组中最大值，初始化为整型最大值，如果无法分为i组，那么还是保持为整型最大
        值。为了能快速的算出子数组之和，还是要建立累计和数组，难点就是在于推导状态转移方程了。来分析一下
        ，如果前j个数字要分成i组，那么i的范围是什么，由于只有j个数字，如果每个数字都是单独的一组，那么
        最多有j组；如果将整个数组看为一个整体，那么最少有1组，所以i的范围是[1, j]，所以要遍历这中间所有
        的情况，假如中间任意一个位置k，dp[i-1][k] 表示数组中前k个数字分成 i-1 组所能得到的最小的各
        个子数组中最大值，而 sums[j]-sums[k] 就是后面的数字之和，取二者之间的较大值，然后和 dp[i][j] 
        原有值进行对比，更新 dp[i][j] 为二者之中的较小值，这样k在 [1, j] 的范围内扫过一遍，dp[i][j] 
        就能更新到最小值，最终返回 dp[m][n] 即可，博主认为这道题所用的思想应该是之前那道题 Reverse 
        Pairs 中解法二中总结的分割重现关系 (Partition Recurrence Relation)，由此看来很多问题的本质
        都是一样，但是披上华丽的外衣，难免会让人有些眼花缭乱了，参见代码如下：
    */
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<long> sums(n + 1);
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, LONG_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = i - 1; k < j; ++k) {
                    long val = max(dp[i - 1][k], sums[j] - sums[k]);
                    dp[i][j] = min(dp[i][j], val);
                }
            }
        }
        return dp[m][n];
    }
};


class Solution97 {
public:
    // 2022.9.3, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/split-array-largest-sum.cpp
    // Time:  O(nlogs), s is the sum of nums
    // Space: O(1)
    int splitArray(vector<int>& nums, int m) {
        int64_t left = *max_element(cbegin(nums), cend(nums));
        int64_t right = accumulate(cbegin(nums), cend(nums), 0LL);
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (check(nums, m, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool check(vector<int>& nums, int m, int64_t total) {
        int cnt = 1;
        int64_t curr_sum = 0;
        for (const auto& num : nums) {
            curr_sum += num;
            if (curr_sum > total) {
                curr_sum = num;
                ++cnt;
            }
        }
        return cnt <= m;
    }
};


class Solution96 {
public:
    // 2022.9.3, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/410.%20Split%20Array%20Largest%20Sum
    // OJ: https://leetcode.com/problems/split-array-largest-sum/
    // Author: github.com/lzl124631x
    // Time: O(N * log(S)) where S is sum of nums.
    // Space: O(1)
    // Ref: https://discuss.leetcode.com/topic/61324/clear-explanation-8ms-binary-search-java
    /*
        Solution 3. Binary Answer
        The answer is between the maximum element and the sum of all the elements.

        Let maxSum be the minimum subarray sum allowed. The greater this maxSum is, the more likely 
        we can split A into m parts with maxSum as the maximum subarray sum -- let's call this valid.

        There is a breakpoint that if maxSum is less than this value, we have to split A into more 
        than m parts -- let's call this invalid.

        We can use binary search to find the minimum valid maxSum.
    */
    int splitArray(vector<int>& A, int m) {
        long sum = accumulate(begin(A), end(A), 0L);
        if (m == 1) return sum;
        long L = *max_element(begin(A), end(A)), R = sum, N = A.size();
        auto valid = [&](int maxSum) {
            int cnt = 1, i = 0 ;
            for (int sum = 0; i < N && cnt <= m; ++i) {
                sum += A[i];
                if (sum > maxSum) {
                    sum = A[i];
                    ++cnt;
                }
            }
            return i == N && cnt <= m;
        };
        while (L <= R) {
            long M = L + (R - L) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};


class Solution95 {
public:
    // 2022.9.3, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/410.%20Split%20Array%20Largest%20Sum
    // OJ: https://leetcode.com/problems/split-array-largest-sum/
    // Author: github.com/lzl124631x
    // Time: O(N^2 * M)
    // Space: O(N)
    /*
        Solution 2. DP + Space Optimization
        Given the dp dependency, we can just use 1D dp array.
    */
    int splitArray(vector<int>& A, int m) {
        int N = A.size();
        vector<int> dp(N + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < N; ++i) dp[i + 1] = dp[i] + A[i];
        for (int i = 2; i <= m; ++i) {
            for (int j = N - 1; j >= 0; --j) {
                for (int k = j, sum = 0; k >= i - 1; --k) {
                    sum += A[k];
                    dp[j + 1] = min(dp[j + 1], max(sum, dp[k]));
                    if (sum >= dp[k]) break; // If `sum` is already no less than `dp[i-1][k]`, going left won't get smaller split sum. Break directly
                }
            }
        }
        return dp[N];
    }
};


class Solution94 {
public:
    // 2022.9.3, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/410.%20Split%20Array%20Largest%20Sum
    // OJ: https://leetcode.com/problems/split-array-largest-sum/
    // Author: github.com/lzl124631x
    // Time: O(N^2 * M)
    // Space: O(NM)
    /*
        Solution 1. Bottom-up DP
        Let dp[i][j+1] be the answer to the subproblem with i subarrays within A[0..j].

        Let sum[i][j] be the sum of numbers in A[i..j].

        For dp[i][j+1], we can try using A[k..j] as the last subarray. This last subarray has sum sum[k][j], 
        and the A[0..(k-1)] elements have minimum split sum dp[i-1][k]. So, if we try different i - 1 <= k <= j, 
        dp[i][j] is the minimum of max(dp[i-1][k], sum[k][j]).

        dp[i][j+1] = min( max(dp[i-1][k], sum[k][j]) | i - 1 <= k <= j )
        The trivial case is as follows.

        dp[1][j+1] = sum[0][j]
        We can compute sum values on the fly instead of precomputing all sum values which takes O(N^2) space.
    */
    int splitArray(vector<int>& A, int m) {
        int N = A.size();
        vector<vector<int>> dp(m + 1, vector<int>(N + 1, INT_MAX));
        dp[1][0] = 0;
        for (int i = 0; i < N; ++i) dp[1][i + 1] = dp[1][i] + A[i];
        for (int i = 2; i <= m; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = j, sum = 0; k >= i - 1; --k) {
                    sum += A[k];
                    dp[i][j + 1] = min(dp[i][j + 1], max(sum, dp[i - 1][k]));
                    if (sum >= dp[i - 1][k]) break; // If `sum` is already no less than `dp[i-1][k]`, going left won't get smaller split sum. Break directly
                }
            }
        }
        return dp[m][N];
    }
};


class Solution93 {
public:
    // 2022.9.3, from https://walkccc.me/LeetCode/problems/0410/
    // Time: O(mn^2)
    // Space: O(mn)
    // Approach 1: Top-down
    int splitArray(vector<int>& nums, int m) {
        const int n = nums.size();
        // dp[i][k] := min of largest sum to split first i nums into k groups
        dp.resize(n + 1, vector<int>(m + 1, INT_MAX));
        prefix.resize(n + 1);

        partial_sum(begin(nums), end(nums), begin(prefix) + 1);
        return splitArray(nums, n, m);
    }

private:
    vector<vector<int>> dp;
    vector<int> prefix;

    int splitArray(const vector<int>& nums, int i, int k) {
        if (k == 1)
        return prefix[i];
        if (dp[i][k] < INT_MAX)
        return dp[i][k];

        // try all possible partitions
        for (int j = k - 1; j < i; ++j)
        dp[i][k] =
            min(dp[i][k], max(splitArray(nums, j, k - 1), prefix[i] - prefix[j]));

        return dp[i][k];
    }
};


class Solution92 {
public:
    // 2022.9.3, from https://walkccc.me/LeetCode/problems/0410/
    // Time: O(mn^2)
    // Space: O(mn)
    // Approach 2: Bottom-up
    int splitArray(vector<int>& nums, int m) {
        const int n = nums.size();
        // dp[i][k] := min of largest sum to split first i nums into k groups
        vector<vector<long>> dp(n + 1, vector<long>(m + 1, INT_MAX));
        vector<long> prefix(n + 1);

        partial_sum(begin(nums), end(nums), begin(prefix) + 1);

        for (int i = 1; i <= n; ++i)
        dp[i][1] = prefix[i];

        for (int k = 2; k <= m; ++k)
        for (int i = k; i <= n; ++i)
            for (int j = k - 1; j < i; ++j)
            dp[i][k] = min(dp[i][k], max(dp[j][k - 1], prefix[i] - prefix[j]));

        return dp[n][m];
    }
};


class Solution91 {
public:
    // 2022.9.3, from https://walkccc.me/LeetCode/problems/0410/
    // Time: O(nlog(Σ∣nums∣))
    // Space: O(1)
    // Approach 3: Binary Search
    int splitArray(vector<int>& nums, int m) {
        int l = *max_element(begin(nums), end(nums));
        int r = accumulate(begin(nums), end(nums), 0) + 1;

        while (l < r) {
        const int mid = (l + r) / 2;
        if (numGroups(nums, mid) > m)
            l = mid + 1;
        else
            r = mid;
        }

        return l;
    }

private:
    int numGroups(const vector<int>& nums, int maxSumInGroup) {
        int groupCount = 1;
        int sumInGroup = 0;

        for (const int num : nums)
        if (sumInGroup + num <= maxSumInGroup) {
            sumInGroup += num;
        } else {
            ++groupCount;
            sumInGroup = num;
        }

        return groupCount;
    }
};


class Solution90 {
public:
    // 2022.9.3, from https://github.com/wisdompeak/LeetCode/blob/master/Dynamic_Programming/410.Split-Array-Largest-Sum/410.Split%20Array%20Largest%20Sum_Binary.cpp
    /*
        解法1: DP
        大多数的数组问题都可以用动态规划解决。

        设计dp[i][k]表示元素1~i分成k份的最佳方案，即最大子区段的最小可能值。

        如何设计转移方程呢？无非就是考虑dp[i][k]和这些前态的关系：dp[i-？][k], dp[i][k-？]。
        可以发现，dp[i][k]和dp[i-1][k-1]有直接关系。遍历所有将前j个元素（j最小就是k-1）分成k-1份的方案，
        加上最后一份（就是 sum[i]-sum[j]）的影响。

        所以转移方程是： dp[i][k]=min{j} ( max(dp[j][k-1],sum[i]-sum[j]) )

        注意的细节是，sum[i]的计算可能会溢出。sum[i]-sum[j]可以转化为 dp[i][1]-dp[j][1].
    */
    int splitArray(vector<int>& nums, int m) 
    {
        long left = 0, right = INT_MAX;
        
        while (left<right)
        {
            int mid = left+(right-left)/2;
            if (checkOK(nums, m, mid))
                right = mid;
            else
                left = mid+1;
        }
        
        return left;
    }
    
    bool checkOK(vector<int>& nums, int m, long val)
    {
        int count = 0;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i] > val) return false;
            
            int j = i;
            long sum = 0;
            while (j<nums.size() && sum+(long)nums[j]<=val)
            {
                sum += (long)nums[j];
                j++;
            }
            count++;
            i = j-1;
        }
        
        return count <= m;
    }
};


class Solution {
public:
    // 2022.9.3, from https://github.com/wisdompeak/LeetCode/blob/master/Dynamic_Programming/410.Split-Array-Largest-Sum/410.Split%20Array%20Largest%20Sum_dp.cpp
    /*
        解法2: Binary Search
        进行k的二分搜索，k就是代表nums分成m份后最大自区段的和。 分析：k的最小值是nums里的最大值；k的最大值
        是数组元素的总和；对于任一个mid，另写函数用贪心法判断是否满足要求。满足要求的话，就继续缩小k来尝试。

        如何判断k是否可行呢？两个判据：

        如果任何nums[i]>k，则不可行。
        尽可能地合并元素，使得任何子区段的和都不超过k，并在遍历的过程中记录这些子区段的数目，超过m的话就说明
        不可行。
        
        此题和 1011. Capacity To Ship Packages Within D Days 几乎一模一样。
    */
    int splitArray(vector<int>& nums, int m) 
    {
        int N = nums.size();
        auto dp = vector<vector<long>>(N+1,vector<long>(m+1, INT_MAX));
        nums.insert(nums.begin(),0);
        
        dp[0][0] = 0;
        
        for (int i=1; i<=N; i++)
            for (int k=1; k<=min(m,i); k++)
            {
                long sum = 0;
                for (int j=i; j>=k; j--)
                {
                    sum += nums[j];
                    dp[i][k] = min(dp[i][k], max(dp[j-1][k-1], sum));
                }
            }
        
        return dp[N][m];
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

