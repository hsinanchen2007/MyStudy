/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

/*

https://leetcode.cn/problems/minimum-size-subarray-sum/

209. 长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 

示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
示例 2：

输入：target = 4, nums = [1,4,4]
输出：1
示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
 

提示：

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 105
 

进阶：

如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。
通过次数397,997提交次数822,781

*/

// @lc code=start
class Solution100 {
public:
    // 2022.8.20, by Hsinan
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int sum = 0;
        int ans = numeric_limits<int>::max();
        for (int end = 0; end < nums.size(); end++) {
            sum += nums[end];
            // below while is a key that we may need to adjust start multiple times
            // within one end change
            while (sum >= target) {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
        }
        return (ans == numeric_limits<int>::max() ? 0 : ans);
    }
};


class Solution99 {
public:
    // 2022.8.20, from https://www.acwing.com/activity/content/code/content/426319/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/426319/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX;
        for (int i = 0, j = 0, sum = 0; i < nums.size(); i ++ ) {
            sum += nums[i];
            while (sum - nums[j] >= s) sum -= nums[j ++ ];
            if (sum >= s) res = min(res, i - j + 1);
        }
        if (res == INT_MAX) res = 0;
        return res;
    }
};


class Solution98 {
public:
    // 2022.8.20, from https://github.com/grandyang/leetcode/issues/209
    /*
        这道题给定了我们一个数字，让求子数组之和大于等于给定值的最小长度，注意这里是大于等于，不是等于。跟之前那道 
        Maximum Subarray 有些类似，并且题目中要求实现 O(n) 和 O(nlgn) 两种解法，那么先来看 O(n) 的解法，需
        要定义两个指针 left 和 right，分别记录子数组的左右的边界位置，然后让 right 向右移，直到子数组和大于等于
        给定值或者 right 达到数组末尾，此时更新最短距离，并且将 left 像右移一位，然后再 sum 中减去移去的值，然
        后重复上面的步骤，直到 right 到达末尾，且 left 到达临界位置，即要么到达边界，要么再往右移动，和就会小于
        给定值。代码如下：
    */
    // O(n)
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int left = 0, right = 0, sum = 0, len = nums.size(), res = len + 1;
        while (right < len) {
            while (sum < s && right < len) {
                sum += nums[right++];
            }
            while (sum >= s) {
                res = min(res, right - left);
                sum -= nums[left++];
            }
        }
        return res == len + 1 ? 0 : res;
    }
};


class Solution97 {
public:
    // 2022.8.20, from https://github.com/grandyang/leetcode/issues/209
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX, left = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (left <= i && sum >= s) {
                res = min(res, i - left + 1);
                sum -= nums[left++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};


class Solution96 {
public:
    // 2022.8.20, from https://github.com/grandyang/leetcode/issues/209
    /*
        下面再来看看 O(nlgn) 的解法，这个解法要用到二分查找法，思路是，建立一个比原数组长一位的 sums 数组，
        其中 sums[i] 表示 nums 数组中 [0, i - 1] 的和，然后对于 sums 中每一个值 sums[i]，用二分查找法
        找到子数组的右边界位置，使该子数组之和大于 sums[i] + s，然后更新最短长度的距离即可。代码如下：
    */
    // O(nlgn)
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size(), sums[len + 1], res = len + 1;
        for (int i = 1; i < len + 1; ++i) sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 0; i < len + 1; ++i) {
            int right = searchRight(i + 1, len, sums[i] + s, sums);
            if (right == len + 1) break;
            if (res > right - i) res = right - i;
        }
        return res == len + 1 ? 0 : res;
    }
    int searchRight(int left, int right, int key, int sums[]) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (sums[mid] >= key) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};


class Solution95 {
public:
    // 2022.8.20, from https://github.com/grandyang/leetcode/issues/209
    /*
        我们也可以不用为二分查找法专门写一个函数，直接嵌套在 for 循环中即可，参加代码如下：
    */
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX, n = nums.size();
        vector<int> sums(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 0; i < n; ++i) {
            int left = i + 1, right = n, t = sums[i] + s;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (sums[mid] < t) left = mid + 1;
                else right = mid - 1;
            }
            if (left == n + 1) break;
            res = min(res, left - i);
        }
        return res == INT_MAX ? 0 : res;
    }
};


class Solution94 {
public:
    // 2022.8.20, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/minimum-size-subarray-sum.cpp
    // Time:  O(n)
    // Space: O(1)
    // Sliding window solution.
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = -1, sum = 0, min_size = numeric_limits<int>::max();
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (sum >= s) {
                min_size = min(min_size, i - start);
                sum -= nums[++start];
            }
        }
        if (min_size == numeric_limits<int>::max()) {
            return 0;
        }
        return min_size;
    }
};


class Solution93 {
public:
    // 2022.8.20, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/minimum-size-subarray-sum.cpp
    // Time:  O(nlogn)
    // Space: O(n)
    // Binary search solution.
    int minSubArrayLen(int s, vector<int>& nums) {
        int min_size = numeric_limits<int>::max();
        vector<int> sum_from_start(nums.size() + 1);
        partial_sum(nums.cbegin(), nums.cend(), sum_from_start.begin() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            const auto& end_it = lower_bound(sum_from_start.cbegin() + i,
                                             sum_from_start.cend(),
                                             sum_from_start[i] + s);
            if (end_it != sum_from_start.cend()) {
                int end = static_cast<int>(end_it - sum_from_start.cbegin());
                min_size = min(min_size, end - i);
            }
        }
        if (min_size == numeric_limits<int>::max()) {
            return 0;
        }
        return min_size;
    }
};


class Solution92 {
public:
    // 2022.8.20, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/209.%20Minimum%20Size%20Subarray%20Sum
    // OJ: https://leetcode.com/problems/minimum-size-subarray-sum/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    // Solution 1. Sliding Window
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, i = 0, j = 0, N = nums.size(), ans = INT_MAX;
        while (j < N) {
            while (j < N && sum < s) sum += nums[j++];
            if (sum < s) break;
            while (i < j && sum >= s) sum -= nums[i++];
            ans = min(ans, j - i + 1);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};


class Solution91 {
public:
    // 2022.8.20, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/209.%20Minimum%20Size%20Subarray%20Sum
    // OJ: https://leetcode.com/problems/minimum-size-subarray-sum/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    // Solution 2. Sliding Window
    int minSubArrayLen(int target, vector<int>& A) {
        int sum = 0, N = A.size(), i = 0, j = 0, ans = INT_MAX;
        while (j < N) {
            sum += A[j++];
            while (sum >= target) {
                ans = min(ans, j - i);
                sum -= A[i++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};


class Solution90 {
public:
    // 2022.8.20, from https://walkccc.me/LeetCode/problems/0209/
    // Time: O(n)
    // Space: O(1)
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = INT_MAX;
        int sum = 0;

        for (int l = 0, r = 0; r < nums.size(); ++r) {
        sum += nums[r];
        while (sum >= s) {
            ans = min(ans, r - l + 1);
            sum -= nums[l++];
        }
        }

        return ans < INT_MAX ? ans : 0;
    }
};


class Solution89 {
public:
    // 2022.8.20, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/209.Minimum-Size-Subarray-Sum/209.Minimum%20Size%20Subarray%20Sum.cpp
    /*
        基本思路：因为题意保证所有数组元素都是正数，可以用双指针定界。当双指针之间子数组和大于sum时，记录Len并left++；
        否则right++。实际编程中，用for循环来控制右指针的思路比较清晰，左指针仅当固定了一个右指针的前提下进行移动；相对
        而言，用while来控制双指针比较容易出错。细节：注意在什么条件下更新len。
    */
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int i=0;
        int j=0;
        int sum=0;
        int len=INT_MAX;
        
        for (int j=0; j<nums.size(); j++)
        {
            sum+=nums[j];
            
            if (sum<s)
                continue;
            else
            {
                while (sum>=s)
                {
                    len=min(len,j-i+1);
                    sum-=nums[i];
                    i++;
                }
            }
        }
        
        if (len==INT_MAX)
            len=0;
        
        return len;
    }
};


class Solution88 {
public:
    // 2022.8.20, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.md
    /*
        暴力解法
        这道题目暴力解法当然是 两个for循环，然后不断的寻找符合条件的子序列，时间复杂度很明显是O(n^2)。
    */
    // Below code will TLE (Time Limit Exceeded) at LC as of 2022.8.20
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX; // 最终的结果
        int sum = 0; // 子序列的数值之和
        int subLength = 0; // 子序列的长度
        for (int i = 0; i < nums.size(); i++) { // 设置子序列起点为i
            sum = 0;
            for (int j = i; j < nums.size(); j++) { // 设置子序列终止位置为j
                sum += nums[j];
                if (sum >= s) { // 一旦发现子序列和超过了s，更新result
                    subLength = j - i + 1; // 取子序列的长度
                    result = result < subLength ? result : subLength;
                    break; // 因为我们是找符合条件最短的子序列，所以一旦符合条件就break
                }
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};


class Solution87 {
public:
    // 2022.8.20, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.md
    /*
        滑动窗口
        接下来就开始介绍数组操作中另一个重要的方法：滑动窗口。

        所谓滑动窗口，就是不断的调节子序列的起始位置和终止位置，从而得出我们要想的结果。
        在暴力解法中，是一个for循环滑动窗口的起始位置，一个for循环为滑动窗口的终止位置，用两个for循环 
        完成了一个不断搜索区间的过程。

        那么滑动窗口如何用一个for循环来完成这个操作呢。

        首先要思考 如果用一个for循环，那么应该表示 滑动窗口的起始位置，还是终止位置。
        如果只用一个for循环来表示 滑动窗口的起始位置，那么如何遍历剩下的终止位置？
        此时难免再次陷入 暴力解法的怪圈。

        所以 只用一个for循环，那么这个循环的索引，一定是表示 滑动窗口的终止位置。
        那么问题来了， 滑动窗口的起始位置如何移动呢？

        这里还是以题目中的示例来举例，s=7， 数组是 2，3，1，2，4，3，来看一下查找的过程：

        209.长度最小的子数组

        最后找到 4，3 是最短距离。
        其实从动画中可以发现滑动窗口也可以理解为双指针法的一种！只不过这种解法更像是一个窗口的移动，所以叫做滑动窗口更适合一些。

        在本题中实现滑动窗口，主要确定如下三点：

        窗口内是什么？
        如何移动窗口的起始位置？
        如何移动窗口的结束位置？
        窗口就是 满足其和 ≥ s 的长度最小的 连续 子数组。

        窗口的起始位置如何移动：如果当前窗口的值大于s了，窗口就要向前移动了（也就是该缩小了）。

        窗口的结束位置如何移动：窗口的结束位置就是遍历数组的指针，也就是for循环里的索引。

        解题的关键在于 窗口的起始位置如何移动，如图所示：

        leetcode_209

        可以发现滑动窗口的精妙之处在于根据当前子序列和大小的情况，不断调节子序列的起始位置。从而将O(n^2)暴力解法降为O(n)。

        C++代码如下：

        时间复杂度：O(n)
        空间复杂度：O(1)
        一些录友会疑惑为什么时间复杂度是O(n)。

        不要以为for里放一个while就以为是O(n^2)啊， 主要是看每一个元素被操作的次数，每个元素在滑动窗后进来操作一次，出去操作一次，
        每个元素都是被操作两次，所以时间复杂度是 2 × n 也就是O(n)。
    */
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0; // 滑动窗口数值之和
        int i = 0; // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= s) {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};


class Solution {
public:
    // 2022.8.20, from https://ke.algomooc.com/detail/v_62bc4653e4b0a51feef9213f/3?from=p_6243bcc1e4b04e8d90291891&type=8&parent_pro_id=p_62b96d90e4b00a4f371ee3ad
    int minSubArrayLen(int target, vector<int>& nums) {
        // 滑动窗口的左端
        int left = 0;

        // 滑动窗口中所有元素的和
        int sum = 0;

        // 记录滑动窗口的长度，并且不断更新获取最小的那个
        // 一开始，result 可以初始化为一个超过数组长度的值
        // 这样的目的是为了最后返回结果的时候判断 result 有没有被更新
        // 如果没有被更新，并且滑动窗口的长度不可能为 result，因为超过了数组的长度
        // 那就代表不存在符合条件的子数组，需要返回 0 
        // 比如 target = 11, nums = [1,1,1,1,1,1,1,1]
        // 先设置 result = 9，执行完后续代码，result 依旧为 9
        // 代表 nums 里面找不到一个子数组和大于等于 11 ，需要返回 0
        int result = nums.size() + 1;
        
        // 滑动窗口的右端从 0 开始，这样，当 nums 为空时，可以直接跳出 for 循环
        for (int right = 0; right < nums.size(); right++) {

            // 滑动窗口中加入了 nums[right] 这个元素
            // 滑动窗口元素和需要发生变化
            sum += nums[right];

            // 变化之后需要判断一下，如果滑动窗口的元素和大于等于了 target
            // 那么这个时候就需要不断的向右移动 left，缩小滑动窗口的长度
            while (sum >= target) {
                
                // 在获取到一个满足要求的子数组时，更新 result 的值
                result = min(result, right - left + 1);

                // 把 nums[left] 移除滑动窗口
                sum -= nums[left];

                // 即 left 向右移动
                left++;

            }
        }

        // 返回结果
        return result == nums.size() + 1 ? 0 : result;

    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

