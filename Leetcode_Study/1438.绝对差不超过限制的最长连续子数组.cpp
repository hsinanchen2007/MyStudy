/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 *
 * [1438] 绝对差不超过限制的最长连续子数组
 */

/*

https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

1438. 绝对差不超过限制的最长连续子数组
给你一个整数数组 nums ，和一个表示限制的整数 limit，请你返回最长连续子数组的长度，该子数组中的任意两个元素之间的绝对差必须
小于或者等于 limit 。

如果不存在满足条件的子数组，则返回 0 。
 

示例 1：

输入：nums = [8,2,4,7], limit = 4
输出：2 
解释：所有子数组如下：
[8] 最大绝对差 |8-8| = 0 <= 4.
[8,2] 最大绝对差 |8-2| = 6 > 4. 
[8,2,4] 最大绝对差 |8-2| = 6 > 4.
[8,2,4,7] 最大绝对差 |8-2| = 6 > 4.
[2] 最大绝对差 |2-2| = 0 <= 4.
[2,4] 最大绝对差 |2-4| = 2 <= 4.
[2,4,7] 最大绝对差 |2-7| = 5 > 4.
[4] 最大绝对差 |4-4| = 0 <= 4.
[4,7] 最大绝对差 |4-7| = 3 <= 4.
[7] 最大绝对差 |7-7| = 0 <= 4. 
因此，满足题意的最长子数组的长度为 2 。

示例 2：

输入：nums = [10,1,2,4,7,2], limit = 5
输出：4 
解释：满足题意的最长子数组是 [2,4,7,2]，其最大绝对差 |2-7| = 5 <= 5 。

示例 3：

输入：nums = [4,2,2,2,4,4,2,2], limit = 0
输出：3
 

提示：

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= limit <= 10^9
通过次数40,155提交次数81,853

*/

// @lc code=start
class Solution100 {
public:
    // 2022.8.19, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1438.%20Longest%20Continuous%20Subarray%20With%20Absolute%20Diff%20Less%20Than%20or%20Equal%20to%20Limit
    // OJ: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
    // Author: github.com/lzl124631x
    // Time: O(NlogN)
    // Space: O(N)
    /*
        Solution 1. Sliding Window
        Use a multiset<int> s to keep track of the values within the window. We keep extending the right-hand 
        side of the window indexed by j and add A[j] into s.

        Whenever we find that the difference between max value and min value in s is greater than k, we shrink 
        the window by moving the left-hand side of the window indexed by i. For every A[i] that we popped out 
        from the window, we erase it from s as well.

        In this way, we make sure the window is always valid. The maximum j - i is the answer.
    */
    int longestSubarray(vector<int>& A, int k) {
        multiset<int> s{ A[0] };
        int i = 0, j = 1, N = A.size(), ans = 1;
        while (j < N) {
            s.insert(A[j++]);
            while (*s.rbegin() - *s.begin() > k) s.erase(s.find(A[i++]));
            ans = max(ans, j - i);
        }
        return ans;
    }
};


class Solution99 {
public:
    // 2022.8.19, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1438.%20Longest%20Continuous%20Subarray%20With%20Absolute%20Diff%20Less%20Than%20or%20Equal%20to%20Limit
    // OJ: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(N)
    /*
        Solution 2. Monotonous Deque
        We use monotonous deques to keep track of the max/min values within the window. See 239. 
        Sliding Window Maximum (Hard) for the idea.
    */
    int longestSubarray(vector<int>& A, int k) {
        deque<int> mx{A[0]}, mn{A[0]};
        int N = A.size(), ans = 1, i = 0, j = 1;
        while (j < N) {
            while (j < N && mx.front() - mn.front() <= k) { 
                while (mx.size() && mx.back() < A[j]) mx.pop_back();
                mx.push_back(A[j]);
                while (mn.size() && mn.back() > A[j]) mn.pop_back();
                mn.push_back(A[j]);
                ++j;
                if (mx.front() - mn.front() <= k) ans = max(ans, j - i);
            }
            while (i < j && mx.front() - mn.front() > k) {
                if (A[i] == mx.front()) mx.pop_front();
                if (A[i] == mn.front()) mn.pop_front();
                ++i;
            }
        }
        return ans;
    }
};


class Solution98 {
public:
    // 2022.8.19, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1438.%20Longest%20Continuous%20Subarray%20With%20Absolute%20Diff%20Less%20Than%20or%20Equal%20to%20Limit
    // OJ: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(N)
    // Ref: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/discuss/609771/JavaC%2B%2BPython-Deques-O(N)
    /*
        Solution 3. Monotonous Deque
        Similar to Solution 2, but since we are looking for the maximum window, we don't shrink the window.

        If the window is valid, we only increment the right edge.

        Otherwise, we increment the left edge as well to shift the window as a whole.
    */
    int longestSubarray(vector<int>& A, int k) {
        deque<int> mx, mn;
        int i = 0, j = 0;
        for (; j < A.size(); ++j) {
            while (mx.size() && mx.back() < A[j]) mx.pop_back();
            while (mn.size() && mn.back() > A[j]) mn.pop_back();
            mx.push_back(A[j]);
            mn.push_back(A[j]);
            if (mx.front() - mn.front() > k) {
                if (A[i] == mx.front()) mx.pop_front();
                if (A[i] == mn.front()) mn.pop_front();
                ++i;
            }
        }
        return j - i;
    }
};


class Solution97 {
public:
    // 2022.8.19, from https://walkccc.me/LeetCode/problems/1438/

    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 1;
        deque<int> minQ;
        deque<int> maxQ;

        for (int l = 0, r = 0; r < nums.size(); ++r) {
        while (!minQ.empty() && minQ.back() > nums[r])
            minQ.pop_back();
        minQ.push_back(nums[r]);
        while (!maxQ.empty() && maxQ.back() < nums[r])
            maxQ.pop_back();
        maxQ.push_back(nums[r]);
        while (maxQ.front() - minQ.front() > limit) {
            if (minQ.front() == nums[l])
            minQ.pop_front();
            if (maxQ.front() == nums[l])
            maxQ.pop_front();
            ++l;
        }
        ans = max(ans, r - l + 1);
        }

        return ans;
    }
};


class Solution96 {
public:
    // 2022.8.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit.cpp
    // Time:  O(n)
    // Space: O(n)
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> max_dq, min_dq;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (!max_dq.empty() && nums[max_dq.back()] <= nums[right]) {
                max_dq.pop_back();
            }
            max_dq.emplace_back(right);
            while (!min_dq.empty() && nums[min_dq.back()] >= nums[right]) {
                min_dq.pop_back();
            }
            min_dq.emplace_back(right);
            if (nums[max_dq[0]] - nums[min_dq[0]] > limit) {
                if (max_dq[0] == left) {
                    max_dq.pop_front();
                }
                if (min_dq[0] == left) {
                    min_dq.pop_front();
                }
                ++left;  // advance left by one to not count in result
            }
        }
        return nums.size() - left;
    }
};


class Solution95 {
public:
    // 2022.8.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit.cpp
    // Time:  O(n)
    // Space: O(n)
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> max_dq, min_dq;
        int result = 0, left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (!max_dq.empty() && nums[max_dq.back()] <= nums[right]) {
                max_dq.pop_back();
            }
            max_dq.emplace_back(right);
            while (!min_dq.empty() && nums[min_dq.back()] >= nums[right]) {
                min_dq.pop_back();
            }
            min_dq.emplace_back(right);
            while (nums[max_dq[0]] - nums[min_dq[0]] > limit) {  // both always exist "right" element
                if (max_dq[0] == left) {
                    max_dq.pop_front();
                }
                if (min_dq[0] == left) {
                    min_dq.pop_front();
                }
                ++left;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};


class Solution94 {
public:
    // 2022.8.19, from https://github.com/wisdompeak/LeetCode/blob/master/Deque/1438.Longest-Continuous-Subarray-With-Absolute-Diff-Less-Than-or-Equal-to-Limit/1438.Longest-Continuous-Subarray-With-Absolute-Diff-Less-Than-or-Equal-to-Limit_deque.cpp
    /*
        解法1：Heap
        本题如果用multiset会非常好做。固定左端点i，不断试探右端点j能前进到哪里。[i,j]内的元素都放入一个multiset，
        自动就知道了最大值和最小值。如果满足mx-mn<=limit，则这段区间长度就合法。否则我们就移动一次左端点i，同时要
        更新这个set把nums[i]从中移出去。
    */
    int longestSubarray(vector<int>& nums, int limit) 
    {
        deque<int>qmax({0});
        deque<int>qmin({0});

        int j = 0;
        int ret = 1;
        int mx = nums[0], mn = nums[0];
        for (int i=0; i<nums.size() && j<nums.size(); i++)
        {
            while (mx-mn <= limit)
            {
                ret = max(ret, j-i+1);
                j++;
                if (j>=nums.size()) break;

                while (qmax.size()>0 && nums[j] >= nums[qmax.back()])                
                    qmax.pop_back();                
                qmax.push_back(j);
                mx = nums[qmax.front()];
                
                while (qmin.size()>0 && nums[j] <= nums[qmin.back()])                
                    qmin.pop_back();
                qmin.push_back(j);
                mn = nums[qmin.front()];
            }

            if (j>=nums.size()) break;

            if (qmax.size()>0 && qmax.front()<=i)
            {
                qmax.pop_front();
                mx = nums[qmax.front()];
            }
            if (qmin.size()>0 && qmin.front()<=i)
            {
                qmin.pop_front();
                mn = nums[qmin.front()];
            }
        }
        return ret;

    }
};


class Solution93 {
public:
    // 2022.8.19, from https://github.com/wisdompeak/LeetCode/blob/master/Deque/1438.Longest-Continuous-Subarray-With-Absolute-Diff-Less-Than-or-Equal-to-Limit/1438.Longest-Continuous-Subarray-With-Absolute-Diff-Less-Than-or-Equal-to-Limit_heap.cpp
    /*
        解法2：monotone deque
        multiset是o(NlogN)的解法，如果使用单调队列，可以优化到o(N)。

        我们不用multset来维护最大值和最小值，而是用一个deque来维护当前区间[i,j]的最大值，用另一个deque来维护当前区间[i,j]
        的最小值。其中用deque来维护一个滑动窗口的最大值，就是239.Sliding-Window-Maximum的做法。

        基本思想是：当将nums[j]加入队列时，如果发现它比队尾的元素还大，那么说明此时队尾元素可以抛弃，这是因为在未来相当一段时间
        内区间都会包含有j，所以最大值肯定轮不到是队尾的那个元素。这就提示我们维护的这个deque应该是单调递减的（因为新元素会把所有
        小的队尾元素都弹出）。每次我们要找当前区间的最大值，就只要看deque的队首元素就行。

        同理，我们维护一个单调递增的deque来获取当前区间的最小值，其中最小值也是deque的队首元素。

        注意，当j前进到区间[i,j]无法满足mx-mn<=limit时，j的前进就停止，我们要移动i。因此需要将nums[i]从这两个deque中移出。
        移出的操作就是看队首元素（的index）是否就是i，是的话把这个队首元素弹出就行。同时记得更新mx和mn。
    */
    int longestSubarray(vector<int>& nums, int limit) 
    {
        multiset<int>Set({nums[0]});
        int j = 0;
        int ret = 0;        
        
        for (int i=0; i<nums.size(); i++)
        {            
            while (*Set.rbegin()-*Set.begin()<=limit)
            {
                ret = max(ret, j-i+1);
                j++;
                if (j>=nums.size()) break;
                Set.insert(nums[j]);
            }

            if (j>=nums.size()) break;
            
            Set.erase(Set.find(nums[i]));     
        }
        
        return ret;
    }
};


class Solution92 {
public:
    // 2022.8.20, from https://github.com/liuyubobobo/Play-Leetcode/blob/master/1001-1500/1438-Longest-Continuous-Subarray-With-Absolute-Diff-Less-Than-or-Equal-to-Limit/cpp-1438/main.cpp
    // Sliding Window + Map
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
    int longestSubarray(vector<int>& nums, int limit) {

        map<int, int> tree;
        tree[nums[0]] ++;

        int res = 1;
        for(int l = 0, i = 1; i < nums.size(); i ++){
            tree[nums[i]] ++;

            if(abs(tree.rbegin()->first - tree.begin()->first) <= limit)
                res = max(res, i - l + 1);
            else{
                while(!tree.empty() && abs(tree.rbegin()->first - tree.begin()->first) > limit){
                    tree[nums[l]] --;
                    if(tree[nums[l]] == 0) tree.erase(nums[l]);
                    l ++;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    // 2022.8.20, from https://github.com/liuyubobobo/Play-Leetcode/blob/master/1001-1500/1438-Longest-Continuous-Subarray-With-Absolute-Diff-Less-Than-or-Equal-to-Limit/cpp-1438/main4.cpp
    // Sliding Window + Mono Queue
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    int longestSubarray(vector<int>& nums, int limit) {

        deque<int> inc = {0}, dec = {0};
        int res = 1;
        for(int l = 0, i = 1; i < nums.size(); i ++){
            while(!inc.empty() && nums[i] < nums[inc.back()]) inc.pop_back();
            inc.push_back(i);

            while(!dec.empty() && nums[i] > nums[dec.back()]) dec.pop_back();
            dec.push_back(i);

            if(abs(nums[inc.front()] - nums[dec.front()]) <= limit)
                res = max(res, i - l + 1);
            else{
                while(!inc.empty() && !dec.empty() && abs(nums[inc.front()] - nums[dec.front()]) > limit){
                    if(!inc.empty() && inc.front() == l) inc.pop_front();
                    if(!dec.empty() && dec.front() == l) dec.pop_front();
                    l ++;
                }
            }
        }
        return res;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

