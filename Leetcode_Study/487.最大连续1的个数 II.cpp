/*

https://leetcode.cn/problems/max-consecutive-ones-ii/

487. 最大连续1的个数 II

中等
127
company
谷歌 Google
company
Zoom

给定一个二进制数组 nums ，如果最多可以翻转一个 0 ，则返回数组中连续 1 的最大个数。

示例 1：

输入：nums = [1,0,1,1,0]
输出：4
解释：翻转第一个 0 可以得到最长的连续 1。
     当翻转以后，最大连续 1 的个数为 4。

示例 2:

输入：nums = [1,0,1,1,0,1]
输出：4 

提示:

1 <= nums.length <= 105
nums[i] 不是 0 就是 1.
 

进阶：如果输入的数字是作为 无限流 逐个输入如何处理？换句话说，内存不能存储下所有从流中输入的数字。您可以有效地解决吗？

*/


class Solution100 {
public:
    // 2023.2.11, from https://github.com/grandyang/leetcode/issues/487
    /*
        这道题在之前那道题 Max Consecutive Ones 的基础上加了一个条件，说有一次将0翻转成1的机会，问此时最大连续1的个数，
        再看看 follow up 中的说明，很明显只遍历一次数组，那我们想，肯定需要用一个变量 cnt 来记录连续1的个数吧，那么当遇到
        了0的时候怎么处理呢，因为有一次0变1的机会，所以遇到0了还是要累加 cnt，然后此时需要用另外一个变量 cur 来保存当前 
        cnt 的值，然后 cnt 重置为0，以便于让 cnt 一直用来统计纯连续1的个数，然后我们每次都用用 cnt+cur 来更新结果 res，
        参见代码如下：    
    */
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cur = 0, cnt = 0;
        for (int num : nums) {
            ++cnt;
            if (num == 0) {
                cur = cnt;
                cnt = 0;
            } 
            res = max(res, cnt + cur);
        }
        return res;
    }
};


class Solution99 {
public:
    // 2023.2.11, from https://github.com/grandyang/leetcode/issues/487
    /*
        上面的方法有局限性，如果题目中说能翻转k次怎么办呢，最好用一个通解来处理这类问题。可以维护一个窗口 [left,right] 
        来容纳至少k个0。当遇到了0，就累加 zero 的个数，然后判断如果此时0的个数大于k，则右移左边界left，如果移除掉的 
        nums[left] 为0，那么 zero 自减1。如果不大于k，则用窗口中数字的个数来更新 res，参见代码如下：    
    */
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, zero = 0, left = 0, k = 1;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) ++zero;
            while (zero > k) {
                if (nums[left++] == 0) --zero;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};


class Solution98 {
public:
    // 2023.2.11, from https://github.com/grandyang/leetcode/issues/487
    /*
        上面那种方法对于 follow up 中的情况无法使用，因为 nums[left] 需要访问之前的数字。我们可以将遇到的0的位置全都保存下来，
        这样需要移动 left 的时候就知道移到哪里了：
    */
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, left = 0, k = 1;
        queue<int> q;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) q.push(right);
            if (q.size() > k) {
                left = q.front() + 1; q.pop();
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};


class Solution97 {
public:
    // 2023.2.11, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/max-consecutive-ones-ii.cpp
    // Time:  O(n)
    // Space: O(1)
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0, prev = 0, curr = 0;
        for (const auto& n : nums) {
            if (n == 0) {
                result = max(result, prev + curr + 1);
                prev = curr;
                curr = 0;
            } else {
                ++curr;
            }
        }
        return min(max(result, prev + curr + 1), static_cast<int>(nums.size()));
    }
};


class Solution96 {
public:
    // OJ: https://leetcode.com/problems/max-consecutive-ones-ii/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    // Shrinkable Sliding Window
    int findMaxConsecutiveOnes(vector<int>& A) {
        int zero = 0, i = 0, j = 0, N = A.size(), ans = 0;
        while (j < N) {
            zero += A[j++] == 0;
            while (zero > 1) zero -= A[i++] == 0;
            ans = max(ans, j - i);
        }
        return ans;
    }
};


class Solution95 {
public:
    // OJ: https://leetcode.com/problems/max-consecutive-ones-ii/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    // Non-shrinkable Sliding Window
    int findMaxConsecutiveOnes(vector<int>& A) {
        int zero = 0, i = 0, j = 0, N = A.size();
        while (j < N) {
            zero += A[j++] == 0;
            if (zero > 1) zero -= A[i++] == 0;
        }
        return j - i;
    }
};


class Solution94 {
public:
    // 2023.2.11, from https://walkccc.me/LeetCode/problems/0487/
    // Approach 1: Sliding Window
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int zeros = 0;

        for (int l = 0, r = 0; r < nums.size(); ++r) {
            if (nums[r] == 0)
                ++zeros;
            while (zeros == 2)
                if (nums[l++] == 0)
                    --zeros;
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};


class Solution93 {
public:
    // 2023.2.11, from https://walkccc.me/LeetCode/problems/0487/
    // Approach 2: Follow up: Generalize to k maxZeros
    int findMaxConsecutiveOnes(vector<int>& nums) {
        constexpr int maxZeros = 1;
        int ans = 0;
        queue<int> q;  // Store indices of zero

        for (int l = 0, r = 0; r < nums.size(); ++r) {
            if (nums[r] == 0)
                q.push(r);
            if (q.size() > maxZeros)
                l = q.front() + 1, q.pop();
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};


class Solution92 {
public:
    // 2023.2.11, from https://walkccc.me/LeetCode/problems/0487/
    // Approach 3: Follow up: maxZeros == 1
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int lastZeroIndex = -1;

        for (int l = 0, r = 0; r < nums.size(); ++r) {
        if (nums[r] == 0) {
            l = lastZeroIndex + 1;
            lastZeroIndex = r;
        }
        ans = max(ans, r - l + 1);
        }

        return ans;
    }
};


class Solution {
public:
    // 2023.2.11, from https://github.com/wisdompeak/LeetCode/blob/master/Dynamic_Programming/487.Max-Consecutive-Ones-II/487.Max-Consecutive-Ones-II.cpp
    /*
        487.Max Consecutive Ones II  
        类似于动态规划的思想，设计两个状态变量： count1记录当前从未使用反转权力、可以得到的连续1的个数；count2记录当前已经使用反转权力、
        可以得到的连续1的个数。

        如果nums[i]==1，那么count1和count2各自加1，没有问题。

        如果nums[i]==0，那么count1要置零；count2怎么办呢？事实上count2=count1+1既可。

        一路上追踪最大曾出现过的count2就是最后的答案。
    */
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int s0=0,s1=0;        
        
        int result=0;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]==0)
            {
                s1 = s0+1;
                s0 = 0;                
            }
            else
            {
                s0++;
                s1++;
            }
            result = max(result,s0);
            result = max(result,s1);
        }
        
        return result;
    }
};








