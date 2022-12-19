/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

/*

https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/

581. 最短无序连续子数组
给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

请你找出符合题意的 最短 子数组，并输出它的长度。
 

示例 1：

输入：nums = [2,6,4,8,10,9,15]
输出：5
解释：你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。

示例 2：

输入：nums = [1,2,3,4]
输出：0

示例 3：

输入：nums = [1]
输出：0
 

提示：

1 <= nums.length <= 104
-105 <= nums[i] <= 105
 

进阶：你可以设计一个时间复杂度为 O(n) 的解决方案吗？

通过次数152,224提交次数367,593

*/

// @lc code=start
class Solution100 {
public:
    // 2022.9.15, from https://www.acwing.com/activity/content/code/content/610635/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/610635/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int findUnsortedSubarray(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l + 1 < nums.size() && nums[l + 1] >= nums[l]) l ++ ;
        if (l == r) return 0;
        while (r - 1 >= 0 && nums[r - 1] <= nums[r]) r -- ;
        for (int i = l + 1; i < nums.size(); i ++ )
            while (l >= 0 && nums[l] > nums[i])
                l -- ;
        for (int i = r - 1; i >= 0; i -- )
            while (r < nums.size() && nums[r] < nums[i])
                r ++ ;
        return r - l - 1;

    }
};


class Solution99 {
public:
    // 2022.9.15, from https://github.com/grandyang/leetcode/issues/581
    // Time Limit Exceeded
    /*
        这道题给了一个数组，让求最短的无序连续子数组，使得对这个子数组排序后，整个数组就会变得有序。根据题目中
        的例子也不难分析出来是让找出数组中的无序的部分。博主最开始的想法就是要确定无序子数组的起始和结束位置，
        这样就能知道子数组的长度了。这里用一个变量 start 来记录起始位置，然后开始遍历数组，当发现某个数字比其
        前面的数字要小的时候，说明此时数组不再有序，要将此数字向前移动，移到其应该在的地方，用另一个变量j来记录
        移动到的位置，然后考虑要不要用这个位置来更新 start 的值，当 start 还是初始值-1时，肯定要更新，因为这
        是出现的第一个无序的地方，还有就是如果当前位置小于 start 也要更新，这说明此时的无序数组比之前的更长了。
        举个例子来说明，比如数组 [1,3,5,4,2]，第一个无序的地方是数字4，它移动到的正确位置是坐标2，此时 start 
        更新为2，然后下一个无序的地方是数字2，它的正确位置是坐标1，所以此时 start 应更新为1，这样每次用 
        i - start + 1 来更新结果 res 时才能得到正确的结果，参见代码如下（现在这个解法已经超时了）：

        解法一：
    */
    int findUnsortedSubarray(vector<int>& nums) {
        int res = 0, start = -1, n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                int j = i;
                while (j > 0 && nums[j] < nums[j - 1]) {
                    swap(nums[j], nums[j - 1]);
                    --j;
                }
                if (start == -1 || start > j) start = j;
                res = i - start + 1;
            }
        }
        return res;
    }
};


class Solution98 {
public:
    // 2022.9.15, from https://github.com/grandyang/leetcode/issues/581
    /*
        下面这种方法是用了一个辅助数组，新建一个跟原数组一摸一样的数组，然后排序。从数组起始位置开始，两个数组相互比较，
        当对应位置数字不同的时候停止，同理再从末尾开始，对应位置上比较，也是遇到不同的数字时停止，这样中间一段就是最短
        无序连续子数组了，参见代码如下：

        解法二：
    */
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n - 1;
        vector<int> t = nums;
        sort(t.begin(), t.end());
        while (i < n && nums[i] == t[i]) ++i;
        while (j > i && nums[j] == t[j]) --j;
        return j - i + 1;
    }
};


class Solution97 {
public:
    // 2022.9.15, from https://github.com/grandyang/leetcode/issues/581
    /*
        下面这种方法很叼啊，是 O(n) 的时间复杂度加上 O(1) 的空间复杂度，博主觉得这实际上是对上面的那种方法进行空间上的优化
        的结果，用两个变量 mx 和 mn 来代替上面的有序数组，我们仔细来分析发现，最小值 mn 初始化为数组的最后一个数字，最大值 
        mx 初始化为了第一个数字，然后从第二个数字开始遍历，mx 和 nums[i] 之间取较大值赋值给 mx，然后比较此时 mx 和 nums[i] 
        之间的大小关系，如果 mx 大于 nums[i]，就把i赋值给 end，那么想如果第一个数字小于第二个，mx 就会赋值为第二个数字，
        这时候 mx 和 nums[i] 就相等了，不进行任何操作，这 make sense，因为说明此时是有序的。mn 和 nums[n-1-i] 之间取
        较小值赋给 mn，然后比较此时 mn 和 nums[n-1-i] 之间的大小关系，如果 mn 小于 nums[n-1-i]，就把 n-1-i 赋值给 
        start，那么什么时候会进行赋值呢，是当倒数第二个数字大于最后一个数字，这样 mn 还是最后一个数字，而 nums[n-1-i] 
        就会大于 mn，这时更新 start。可以看出 start 是不断往前走的，end 是不断往后走的，整个遍历完成后，start 和 end 
        就分别指向了最短无序连续子数组的起始和结束位置，参见代码如下：

        解法三：
    */
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), start = -1, end = -2;
        int mn = nums[n - 1], mx = nums[0];
        for (int i = 1; i < n; ++i) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[n - 1 - i]);
            if (mx > nums[i]) end = i;
            if (mn < nums[n - 1 - i]) start = n - 1 - i;
        }
        return end - start + 1;
    }
};


class Solution96 {
public:
    // 2022.9.15, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/shortest-unsorted-continuous-subarray.cpp
    // Time:  O(n)
    // Space: O(1)
    int findUnsortedSubarray(vector<int>& nums) {
        const auto n = nums.size();
        auto left = -1, right = -2;
        auto max_from_left = nums[0], min_from_right = nums.back();
        for (int i = 1; i < n; ++i) {
            max_from_left = max(max_from_left, nums[i]);
            min_from_right = min(min_from_right, nums[n - 1 - i]);
            if (nums[i] < max_from_left) {
                right = i;
            }
            if (nums[n - 1 - i] > min_from_right) {
                left = n - 1 - i;
            }
        }
        return right - left + 1;
    }
};


class Solution95 {
public:
    // 2022.9.15, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/581.%20Shortest%20Unsorted%20Continuous%20Subarray
    // OJ: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    /*
        Solution 1. Greedy
        The goal is to:

        find the greatest index L such that A[L] <= min(A[L .. N-1]) and A[0 .. L] is non-decreasing
        find the smallest index R such that A[R] >= max(A[0 .. R-1]) and A[R .. N-1] is non-decreasing.
        Then, we need to sort A[L+1 .. R-1], R - L - 1 elements in total.
    */
    int findUnsortedSubarray(vector<int>& A) {
        int N = A.size(), L = N - 1, R = 0;
        for (int i = N - 2, mn = A.back(); i >= 0; --i) {
            mn = min(mn, A[i]);
            if (mn != A[i]) L = i - 1;
        }
        for (int i = 1, mx = A[0]; i < N; ++i) {
            mx = max(mx, A[i]);
            if (mx != A[i]) R = i + 1;
        }
        return max(0, R - L - 1);
    }
};


class Solution94 {
public:
    // 2022.9.15, from https://github.com/MaskRay/LeetCode/blob/master/shortest-unsorted-continuous-subarray.cc
    // Shortest Unsorted Continuous Subarray
    int findUnsortedSubarray(vector<int>& a) {
        vector<int> b = a;
        sort(b.begin(), b.end());
        int l = 0, r = a.size();
        while (l < r && a[l] == b[l]) l++;
        while (l < r && a[r-1] == b[r-1]) r--;
        return r-l;
    }
};


class Solution93 {
public:
    // 2022.9.15, from https://github.com/MaskRay/LeetCode/blob/master/shortest-unsorted-continuous-subarray.cc
    int findUnsortedSubarray(vector<int>& a) {
        int s = 0, l = 0, r = a.size();
        while (l+1 < a.size() && a[l] <= a[l+1]) l++;
        while (r > 1 && a[r-2] <= a[r-1]) r--;
        if (l+1 >= r) return 0;
        int mn = *min_element(&a[l], &a[r]),
            mx = *max_element(&a[l], &a[r]);
        while (l && mn < a[l-1]) l--;
        while (r < a.size() && a[r] < mx) r++;
        return r-l;
    }
};


class Solution92 {
public:
    // 2022.9.15, from https://walkccc.me/LeetCode/problems/0581/
    /*
        Time: O(n)
        Space: O(1)
    */
    int findUnsortedSubarray(vector<int>& nums) {
        const int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        bool meetDecrease = false;
        bool meetIncrease = false;

        for (int i = 1; i < n; ++i) {
        if (nums[i] < nums[i - 1])
            meetDecrease = true;
        if (meetDecrease)
            mini = min(mini, nums[i]);
        }

        for (int i = n - 2; i >= 0; --i) {
        if (nums[i] > nums[i + 1])
            meetIncrease = true;
        if (meetIncrease)
            maxi = max(maxi, nums[i]);
        }

        int l;
        for (l = 0; l < n; ++l)
        if (nums[l] > mini)
            break;

        int r;
        for (r = n - 1; r >= 0; --r)
        if (nums[r] < maxi)
            break;

        return l < r ? r - l + 1 : 0;
    }
};


class Solution {
public:
    // 2022.9.15, from https://github.com/wisdompeak/LeetCode/blob/master/Greedy/581.shortest-unsorted-continuous-subarray/581.shortest-unsorted-continuous-subarray.cpp
    /*
        581.shortest-unsorted-continuous-subarray
        本题的难点是如何设计不需要排序的o(n)算法。

        找出这样一个right_bound：位于该数左边的所有数的最大值，要比这个数大，这说明这个数在排序后需要变换位置。怎么找呢？
        将数组从左到右过一遍，实时保存最大值即可，不断刷新这个right_bound。

        同理，找到这样一个left_bound：位于该数右边的所有数的最小值，要比这个数小，这说明这个数在排序后需要变换位置。也是讲
        数组从右往左过一遍，实时保存最小值。

        最后当right_bound>left_bound时，结果就是 right_bound-left_bound+1
    */
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int curMax=INT_MIN;
        int right_bound=0;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]<curMax)
                right_bound=i;
            curMax=max(curMax,nums[i]);
        }
        
        int curMin=INT_MAX;
        int left_bound=nums.size()-1;
        for (int i=nums.size()-1; i>=0; i--)
        {
            if (nums[i]>curMin)
                left_bound=i;
            curMin=min(curMin,nums[i]);
        }        
        
        cout<<left_bound<<" "<<right_bound<<endl;
        
        return left_bound>=right_bound?0:right_bound-left_bound+1;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

