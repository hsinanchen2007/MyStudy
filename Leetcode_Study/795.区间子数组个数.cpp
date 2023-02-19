/*
 * @lc app=leetcode.cn id=795 lang=cpp
 *
 * [795] 区间子数组个数
 */

/*

https://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum/

795. 区间子数组个数

中等
340
company
Facebook
company
亚马逊

给你一个整数数组 nums 和两个整数：left 及 right 。找出 nums 中连续、非空且其中最大元素在范围 [left, right] 内的子数组，
并返回满足条件的子数组的个数。

生成的测试用例保证结果符合 32-bit 整数范围。 

示例 1：

输入：nums = [2,1,4,3], left = 2, right = 3
输出：3
解释：满足条件的三个子数组：[2], [2, 1], [3]

示例 2：

输入：nums = [2,9,2,5,6], left = 2, right = 8
输出：7 

提示：

1 <= nums.length <= 105
0 <= nums[i] <= 109
0 <= left <= right <= 109

*/

// @lc code=start
class Solution100 {
public:
    // 2023.2.18, from https://www.acwing.com/activity/content/code/content/1157785/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/1157785/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int calc(vector<int>& A, int k) {
        int res = 0;
        for (int i = 0; i < A.size(); i ++ ) {
            if (A[i] > k) continue;
            int j = i + 1;
            while (j < A.size() && A[j] <= k) j ++ ;
            int k = j - i;
            res += (long long)k * (k + 1) / 2;  // modified with (long long) to pass LC AC
            i = j;
        }
        return res;
    }

    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        return calc(A, R) - calc(A, L - 1);
    }
};


class Solution99 {
public:
    // 2023.2.18, from https://walkccc.me/LeetCode/problems/0795/
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int ans = 0;
        int l = -1;
        int r = -1;

        for (int i = 0; i < A.size(); ++i) {
            if (A[i] > R)  // Handle reset value
                l = i;
            if (A[i] >= L)  // Handle reset and needed value
                r = i;
            ans += r - l;
        }

        return ans;
    }
};


class Solution98 {
public:
    // 2023.2.18, from https://github.com/wisdompeak/LeetCode/blob/master/Others/795.Number-of-Subarrays-with-Bounded-Maximum/795.Number-of-Subarrays-with-Bounded-Maximum_v1.cpp
    /*
        解法1：
        我们枚举每个数值范围在[L,R]之间的数nums[i]，考虑如果它是subarray的最大值，那么这样的subarray有几个？很显然，我们只需要找到
        j = prevGreater[i]以及k = nextGreater[i]，那么这样的subarray的左边界可以到达j+1，右边界可以到达k-1，那么这样的subarray
        的个数就是(i-j)*(k-i).

        这样的做法需要three pass，并且要注意这种情况:[8,5,5,5,5,8]，且[L,R]=[4,6]，那么每个5作为最大值的时候可能会把区间[5,5,5,5]
        考虑进去，造成重复计数。一个解决方法就是我们规定，如果一个区间内如果有多个最大值，我们约定最靠左边的那个是“真正的”最大值。因此
        j的计算应该改为j = previGreaterOrEqual[i].
    */
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) 
    {
        int n = nums.size();
        vector<int>prevGreaterOrEqual(n,-1);
        vector<int>nextGreater(n,n);

        stack<int>Stack;
        for (int i=0; i<n; i++)
        {
            while (!Stack.empty() && nums[Stack.top()] < nums[i])
            {
                nextGreater[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }

        while (!Stack.empty()) Stack.pop();
        for (int i=n-1; i>=0; i--)
        {
            while (!Stack.empty() && nums[Stack.top()] <= nums[i])
            {
                prevGreaterOrEqual[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }

        int ret = 0;
        for (int i=0; i<n; i++)
        {
            if (nums[i]>=left && nums[i]<=right)
            {
                ret += (i-prevGreaterOrEqual[i])*(nextGreater[i]-i);
            }            
        }
        return ret;
    }
};


class Solution97 {
public:
    // 2023.2.18, from https://github.com/wisdompeak/LeetCode/blob/master/Others/795.Number-of-Subarrays-with-Bounded-Maximum/795.Number-of-Subarrays-with-Bounded-Maximum_v2.cpp
    /*
        解法2：
        首先，我们需要观察到，这个数组被大于R的元素分割成了若干段。任何subarray不能包含大于R的元素。所以我们只需要在每个片段里考察。

        假设这个片段的起点位置是start。本题枚举的技巧是：如果A[i]作为subarray的最后一个，那么这个subarray的第一个元素可以取在哪里？
        显然我们只要找左边最接近的、数值落在[L,R]区间的那个位置lastLR，那么只要subarray包含它，就是一个合法的subarray。所以以A[i]
        为结尾的合法subarray的个数就是lastLR-start+1.

        最终的答案就是遍历A[i]，累加以其为结尾的subarray的个数。    
    */
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) 
    {
        long ret = 0;
        int start = -1, validMax = -1;
     
        for (int i = 0; i < A.size(); i++) 
        { 
            if (A[i] > R) 
            {                
                start = -1;
                validMax = -1;
            }
            else
            {
                if (start == -1)
                    start = i;
                if (A[i]<=R && A[i]>=L)
                    validMax = i;                                
                
                if (start!=-1 && validMax!=-1)
                    ret += (validMax-start+1);                
            }
        }
 
        return ret;
    }
};


class Solution96 {
public:
    // OJ: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    /*
        Solution 1. Two Pointers
        For simplicity, let's map A[i] in the following way:

        A[i] = 0 if A[i] < left
        A[i] = 1 if left <= A[i] <= right
        A[i] = 2 if A[i] > right
        Consider A = [2 0 1 1 0 0 0 1 2 0 1 0 1]. The subarray can't have any 2. So 2 separates A into several segments 
        and we just need to look within each segment.

        For the first segment, [0 1 1 0 0 0 1], let's consider the subarrays from left to right one by one:

        [0] is not a valid subarray
        [0 1] is a valid subarray. And we can also form a valid subarray [1] by just using the second element.
        [0 1 1] is a valid subarray. And its subarrays ending with the last 1 are also valid -- [1 1] and [1].
        [0 1 1 0] is a valid subarray. And its subarrays ending with the last 1 are also valid -- [1 1 0], [1, 0].
        ...
        We can see that we can scan each segment from left to right, and just log the index of last 1 as last. For the 
        current element A[i], there are last - start + 1 subarrays we can form starting from start where start is the index 
        of the first element of this segment.    
    */
    int numSubarrayBoundedMax(vector<int>& A, int left, int right) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] > right) continue;
            int last = -1, start = i;
            for (; i < N && A[i] <= right; ++i) {
                if (A[i] >= left && A[i] <= right) last = i;
                if (last != -1) ans += last - start + 1;
            }
        }
        return ans;
    }
};


class Solution95 {
public:
    // OJ: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    int numSubarrayBoundedMax(vector<int>& A, int left, int right) {
        int N = A.size(), ans = 0, start = -1, end = -1;
        for (int i = 0; i < N; ++i) {
            if (A[i] > right) {
                start = end = i;
                continue;
            }
            if (A[i] >= left) end = i;
            ans += (end - start);
        }
        return ans;
    }
};


class Solution94 {
public:
    // 2023.2.18, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/number-of-subarrays-with-bounded-maximum.cpp
    // Time:  O(n)
    // Space: O(1)
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        return count(A, R) - count(A, L - 1);
    }

private:
    int count(const vector<int>& A, int bound) const {
        int result = 0, curr = 0;
        for (const auto& i : A) {
            curr = (i <= bound) ? curr + 1 : 0;
            result += curr;
        }
        return result;
    }
};


class Solution93 {
public:
    // 2023.2.18, from https://github.com/grandyang/leetcode/issues/795
    /* TLE !! */
    /*
        这道题给了我们一个数组，又给了我们两个数字L和R，表示一个区间范围，让我们求有多少个这样的子数组，使得其最大值在[L, R]区间的
        范围内。既然是求子数组的问题，那么最直接，最暴力的方法就是遍历所有的子数组，然后维护一个当前的最大值，只要这个最大值在[L, R]
        区间的范围内，结果res自增1即可。但是这种最原始，最粗犷的暴力搜索法，OJ不答应。但是其实我们略作优化，就可以通过了。优化的方法
        是，首先，如果当前数字大于R了，那么其实后面就不用再遍历了，不管当前这个数字是不是最大值，它都已经大于R了，那么最大值可能会
        更大，所以没有必要再继续遍历下去了。同样的剪枝也要加在内层循环中加，当curMax大于R时，直接break掉内层循环即可，参见代码如下：    
    */
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int res = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            if (A[i] > R) continue;
            int curMax = INT_MIN;
            for (int j = i; j < n; ++j) {
                curMax = max(curMax, A[j]);
                if (curMax > R) break;
                if (curMax >= L) ++res;
            }
        }
        return res;
    }
};


class Solution92 {
public:
    // 2023.2.18, from https://github.com/grandyang/leetcode/issues/795
    /*
        虽然上面的方法做了剪枝后能通过OJ，但是我们能不能在线性的时间复杂度内完成呢。答案是肯定的，我们先来看一种官方解答贴中的方法，
        这种方法是用一个子函数来算出最大值在[-∞, x]范围内的子数组的个数，而这种区间只需要一个循环就够了，为啥呢？我们来看数组
        [2, 1, 4, 3]的最大值在[-∞, 4]范围内的子数组的个数。当遍历到2时，只有一个子数组[2]，遍历到1时，有三个子数组，[2], [1], [2,1]。
        当遍历到4时，有六个子数组，[2], [1], [4], [2,1], [1,4], [2,1,4]。当遍历到3时，有十个子数组。其实如果长度为n的数组的最大值
        在范围[-∞, x]内的话，其所有子数组都是符合题意的，而长度为n的数组共有n(n+1)/2个子数组，刚好是等差数列的求和公式。所以我们在
        遍历数组的时候，如果当前数组小于等于x，则cur自增1，然后将cur加到结果res中；如果大于x，则cur重置为0。这样我们可以正确求出最大值
        在[-∞, x]范围内的子数组的个数。而要求最大值在[L, R]范围内的子数组的个数，只需要用最大值在[-∞, R]范围内的子数组的个数，减去
        最大值在[-∞, L-1]范围内的子数组的个数即可，参见代码如下：    
    */
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        return count(A, R) - count(A, L - 1);
    }
    int count(vector<int>& A, int bound) {
        int res = 0, cur = 0;
        for (int x : A) {
            cur = (x <= bound) ? cur + 1 : 0;
            res += cur;
        }
        return res;
    }
};


class Solution91 {
public:
    // 2023.2.18, from https://github.com/grandyang/leetcode/issues/795
    /*
        下面这种解法也是线性时间复杂度的，跟上面解法的原理很类似，只不过没有写子函数而已。我们使用left和right来分别标记子数组的左右边界，
        使得其最大值在范围[L,R]内。那么当遍历到的数字大于等于L时，right赋值为当前位置i，那么每次res加上right - left，随着right的不停
        自增1，每次加上的right - left，实际上也是一个等差数列，跟上面解法中的子函数本质时一样的。当A[i]大于R的时候，left = i，那么此时
        A[i]肯定也大于等于L，于是rihgt=i，那么right - left为0，相当于上面的cur重置为0的操作，发现本质联系了吧，参见代码如下：    
    */
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int res = 0, left = -1, right = -1;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] > R) left = i;
            if (A[i] >= L) right = i;
            res += right - left;
        }
        return res;
    }
};


class Solution90 {
public:
    // 2023.2.18, from https://github.com/grandyang/leetcode/issues/795
    /*
        我们可以对上面的解法稍稍做下优化，在A[i] > R的时候，left和right都赋值为i，然后continue，这样省去了后面的用0来更新结果res的步骤，
        能提高一些运行效率，参见代码如下：    
    */
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int res = 0, left = -1, right = -1;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] > R) {
                left = right = i;
                continue;
            }
            if (A[i] >= L) right = i;
            res += right - left;
        }
        return res;
    }
};


class Solution89 {
public:
    // 2023.2.18, from https://zxi.mytechroad.com/blog/?s=LeetCode+795.
    // Author: Huahua
    // Running time: 42 ms
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        return count(A, R) - count(A, L - 1);
    }
private:
    // Count # of sub arrays whose max element is <= N
    int count(const vector<int>& A, int N) {
        int ans = 0;
        int cur = 0;
        for (int a: A) {
            if (a <= N) 
                ans += ++cur;
            else
                cur = 0;
        }
        return ans;
    }
};


class Solution {
public:
    // 2023.2.18, from https://zxi.mytechroad.com/blog/?s=LeetCode+795.
    // Author: Huahua
    // Running time: 38 ms
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int ans = 0;
        int left = -1;
        int right = -1;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] >= L) right = i;
            if (A[i] > R) left = i;      
            ans += (right - left);
        }
        return ans;
    }
};


// @lc code=end

