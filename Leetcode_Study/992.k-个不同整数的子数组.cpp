/*
 * @lc app=leetcode.cn id=992 lang=cpp
 *
 * [992] K 个不同整数的子数组
 */

/*

https://leetcode.cn/problems/subarrays-with-k-different-integers/

992. K 个不同整数的子数组

困难
421
company
亚马逊

给定一个正整数数组 nums和一个整数 k ，返回 num 中 「好子数组」 的数目。

如果 nums 的某个子数组中不同整数的个数恰好为 k，则称 nums 的这个连续、不一定不同的子数组为 「好子数组 」。

例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。
子数组 是数组的 连续 部分。

示例 1：

输入：nums = [1,2,1,2,3], k = 2
输出：7
解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].

示例 2：

输入：nums = [1,2,1,3,4], k = 3

输出：3
解释：恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].
 
提示：

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length

*/

// @lc code=start
class Solution100 {
public:
    // 2023.2.18, from https://www.acwing.com/activity/content/code/content/2013434/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/2013434/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> S1, S2;
        int res = 0;
        for (int i = 0, j1 = 0, j2 = 0, cnt1 = 0, cnt2 = 0; i < nums.size(); i ++ ) {
            if (!S1[nums[i]]) cnt1 ++ ;
            S1[nums[i]] ++ ;
            while (cnt1 > k) {
                S1[nums[j1]] -- ;
                if (!S1[nums[j1]]) cnt1 -- ;
                j1 ++ ;
            }

            if (!S2[nums[i]]) cnt2 ++ ;
            S2[nums[i]] ++ ;
            while (cnt2 >= k) {
                S2[nums[j2]] -- ;
                if (!S2[nums[j2]]) cnt2 -- ;
                j2 ++ ;
            }

            res += j2 - j1;
        }
        return res;
    }
};


class Solution99 {
public:
    // 2023.2.18, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/992.Subarrays-with-K-Different-Integers/992.Subarrays-with-K-Different-Integers_v1.cpp
    /*
        992.Subarrays-with-K-Different-Integers
        此题的解法非常巧妙.它代表了一类思想:求关于K的解,是否可以化成求at most K的解减去求at most K-1的解.本题恰好就是用到
        这个方法.我们需要写一个helper函数,计算数组A里面最多含有K个不同数字的subarray的个数.于是最终答案就是helper(K)-helper(K-1).

        对于这个helper函数,标准答案很显然就是用双指针和滑动窗口的方法.遍历右指针,考察对应的最大的滑窗是多少.于是在该右边界
        固定的条件下,满足题意的subarray的个数就是count+=右指针-左指针+1    
    */
    int subarraysWithKDistinct(vector<int>& A, int K) 
    {
        return atMostK(A,K) - atMostK(A,K-1);
    }
    
    int atMostK(vector<int>& A, int K)
    {
        unordered_map<int,int>Map;
        int count=0;
        int i = 0;
        
        for (int j=0; j<A.size(); j++)
        {
            Map[A[j]]++;
            
            while (Map.size()>K)
            {
                Map[A[i]]--;
                if (Map[A[i]]==0)
                    Map.erase(A[i]);
                i++;
            }            
            count+= j-i+1;
        }        
        return count;            
    }    
};


class Solution98 {
public:
    // 2023.2.18, from https://walkccc.me/LeetCode/problems/0992/
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return subarrayWithAtMostKDistinct(A, K) -
            subarrayWithAtMostKDistinct(A, K - 1);
    }

private:
    int subarrayWithAtMostKDistinct(vector<int>& A, int K) {
        int ans = 0;
        vector<int> count(A.size() + 1);

        for (int l = 0, r = 0; r < A.size(); ++r) {
            if (++count[A[r]] == 1)
                --K;
            while (K == -1)
                if (--count[A[l++]] == 0)
                    ++K;
            ans += r - l + 1;  // A[l..r], A[l + 1..r], ..., A[r]
        }

        return ans;
    }
};


class Solution97 {
public:
    // OJ: https://leetcode.com/problems/subarrays-with-k-different-integers/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(N)
    /*
        Solution 1. Sliding Window
        Use [i, j) as a sliding window to find the maximum window which contains no more than K unique elements.

        To achieve this, we use a map m to store the last position of each number in the current window.

        When m.size() > K, we should move forward i to shrink the window until it become valid again.

        When m.size() == K, [i, j) is the maximum window we are looking for.

        Within this maximum window [i, j), there is a minimum window [k, j) containing no more than K unique elements. 
        k is the minimal index in m.

        Now, the number of valid subarrays in this window is k - i + 1.

        Since k is monotonically increasing and must be no less than i, we can use k as a global pointer just like 
        i and j so that the overall time complexity of moving k is O(N).

        Whenever m.size() == K, we can move k forward until m[A[k] - '0'] == k, and add k - i + 1 to the answer.    
    */
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int ans = 0, i = 0, j = 0, k = 0, N = A.size();
        unordered_map<int, int> m;
        while (j < N) {
            m[A[j] - '0'] = j;
            ++j;
            while (m.size() > K) {
                int d = A[i++] - '0';
                if (m[d] < i) m.erase(d);
            }
            if (m.size() == K) {
                k = max(i, k);
                while (m[A[k] - '0'] != k) ++k;
                ans += k - i + 1;
            }
        }
        return ans;
    }
};


class Solution96 {
    // OJ: https://leetcode.com/problems/subarrays-with-k-different-integers/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(U) where U is the number of unique numbers in `A`
    /*
        Solution 2. Shrinkable Sliding Window
        Check out "C++ Maximum Sliding Window Cheatsheet Template!" which can help you solve all sliding window problems.

        We can turn this problem into two find maximum sliding window problem: one is to find a window with at most k different 
        integers, another is to find a window with at most k - 1 different integers.    
    */
    int atMost(vector<int> &A, int k) {
        int distinct = 0, i = 0, j = 0, N = A.size(), ans = 0;
        unordered_map<int, int> cnt;
        for (; j < N; ++j) {
            distinct += ++cnt[A[j]] == 1;
            while (distinct > k) distinct -= --cnt[A[i++]] == 0;
            ans += j - i;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& A, int k) {
        return atMost(A, k) - atMost(A, k - 1);
    }
};


class Solution95 {
public:
    // 2023.2.18, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/subarrays-with-k-different-integers.cpp
    // Time:  O(n)
    // Space: O(k)
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atMostK(A, K) - atMostK(A, K - 1);
    }

private:
    int atMostK(const vector<int>& A, int K) {
        int result = 0, left = 0;
        unordered_map<int, int> count;
        for (int right = 0; right < A.size(); ++right) {
            ++count[A[right]];
            while (count.size() > K) {
                if (!--count[A[left]]) {
                    count.erase(A[left]);
                }
                ++left;
            }
            result += right - left + 1;
        }
        return result;
    }
};


class Solution94 {
public:
    // 2023.2.18, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/subarrays-with-k-different-integers.cpp
    // Time:  O(n)
    // Space: O(k)
    int subarraysWithKDistinct(vector<int>& A, int K) {
        Window window1, window2;
        int result = 0, left1 = 0, left2 = 0;
        for (const auto& i : A) {
            window1.add(i);
            while (window1.size() > K) {
                window1.remove(A[left1]);
                ++left1;
            }
            window2.add(i);
            while (window2.size() >= K) {
                window2.remove(A[left2]);
                ++left2;
            }
            result += left2 - left1;
        }
        return result;
    }

private:
    class Window {
    public:
        void add(int x) {
            ++count_[x];
        }
        
        void remove(int x) {
            --count_[x];
            if (count_[x] == 0) {
                count_.erase(x);
            }
        }
        
        size_t size() const {
            return count_.size();
        }
    
    private:
        unordered_map<int, int> count_;
    };
};


class Solution93 {
public:
    // 2023.2.18, from https://github.com/grandyang/leetcode/issues/992
    /*
        这道题给了一个只有正整数的数组A，然后定义了一种好子数组，需要该子数组中不同的数字的个数正好为给定的正数K。这种玩子数组
        个数的题目，如果是求极值，大概率是要用动态规划做，不过这里是求满足某个条件的子数组的个数，还有一种比较常见的解法，就是
        滑动窗口 Sliding Window，这是一种非常重要的解题思路，也经常在面试中出现，所以务必需要掌握。LeetCode 中关于滑动窗口的
        题还蛮多的，可以参见下方的类似题目区域，列出了一堆堆。在不遍历所有子数组的情况下，求正好有K个不同的数字并不是很容易，
        这道题需要稍稍转换一下思维，比较好求的求最多有K个不同的数字的情况。若能分别求出最多有K个不同数字的子数组的个数，和最多有 
        K-1 个不同数字的子数组的个数，二者相减，就是正好有K个不同数字的子数组的个数。我们之前做过这样一道题目 Longest Substring
        with At Most K Distinct Characters，求最多有K个不同字符的最长子串，这里就是用的相同的滑动窗口的思路来做。

        由于要同时求K和 K-1 的情况，所以可以用个子函数来做。在 helper 函数中，使用一个 HashMap 来建立每个数字和其出现次数之间
        的映射，再用个变量 left 标记窗口的左边界。下面进行 for 循环，若当前的数字没出现过，则K自减1，因为此时子数组中多了一个
        不同的数字，然后该数字的映射值自增1。此时K值有可能小于0了，说明子数组中的不同数字过多了，需要移除一个，用个 while 循环，
        若K小于0则进行循环，此时左边界上的数字的映射值自减1，减小后若为0了，则说明该数字已经彻底被移出了滑动窗口，此时K应该自增1，
        同时左边界 left 自增1，表示向右移动一位。此时这个窗口的长度就代表了此时最多有k个不同数字的子数组的个数，将其加入结果 res，
        这样直至 for 循环退出后，就可以得到最终的结果了，参见代码如下：

        解法一：    
    */
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return helper(A, K) - helper(A, K - 1);
    }
    int helper(vector<int>& A, int K) {
        int n = A.size(), res = 0, left = 0;
        unordered_map<int, int> numCnt;
        for (int i = 0; i < n; ++i) {
            if (numCnt[A[i]] == 0) --K;
            ++numCnt[A[i]];
            while (K < 0) {
                if (--numCnt[A[left]] == 0) ++K;
                ++left;
            }
            res += i - left + 1;
        }
        return res;
    }
};


class Solution92 {
public:
    // 2023.2.18, from https://github.com/grandyang/leetcode/issues/992
    /*
        滑动窗口有多种写法，比如下面这种并不直接减小K，而是用 HashMap 中的映射个数来跟K比较，不过这样的话就一定要移除不在
        窗口内的映射才行，参见代码如下：

        解法二：    
    */
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return helper(A, K) - helper(A, K - 1);
    }
    int helper(vector<int>& A, int K) {
        int n = A.size(), res = 0, left = 0;
        unordered_map<int, int> numCnt;
        for (int i = 0; i < n; ++i) {
            ++numCnt[A[i]];
            while (numCnt.size() > K) {
                if (--numCnt[A[left]] == 0) numCnt.erase(A[left]);
                ++left;
            }
            res += i - left + 1;
        }
        return res;
    }
};


class Solution {
public:
    // 2023.2.18, from https://github.com/grandyang/leetcode/issues/992
    /*
        再来看另一种写法，这里建立的是数字和其下标之间的映射，而不是其出现的个数，不过整体的思路并没有啥太大的区别，参见代码如下：

        解法三：    
    */
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return helper(A, K) - helper(A, K - 1);
    }
    int helper(vector<int>& A, int K) {
        int n = A.size(), res = 0, left = 0;
        unordered_map<int, int> num2idx;
        for (int i = 0; i < n; ++i) {
            num2idx[A[i]] = i;
            while (num2idx.size() > K) {
                if (num2idx[A[left]] == left) num2idx.erase(A[left]);
                ++left;
            }
            res += i - left + 1;
        }
        return res;
    }
};


// @lc code=end

