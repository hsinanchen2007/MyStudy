/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 K 小的数对距离
 */

/*

https://leetcode.cn/problems/find-k-th-smallest-pair-distance/

719. 找出第 K 小的数对距离

困难
400
company
亚马逊

数对 (a,b) 由整数 a 和 b 组成，其数对距离定义为 a 和 b 的绝对差值。

给你一个整数数组 nums 和一个整数 k ，数对由 nums[i] 和 nums[j] 组成且满足 0 <= i < j < nums.length 。返回 所有数对距离中 第 k 小的数对距离。 

示例 1：

输入：nums = [1,3,1], k = 1
输出：0
解释：数对和对应的距离如下：
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
距离第 1 小的数对是 (1,1) ，距离为 0 。

示例 2：

输入：nums = [1,1,1], k = 2
输出：0

示例 3：

输入：nums = [1,6,1], k = 3
输出：5 

提示：

n == nums.length
2 <= n <= 104
0 <= nums[i] <= 106
1 <= k <= n * (n - 1) / 2

*/

// @lc code=start
class Solution100 {
    int get(vector<int>& nums, int mid) {
        int res = 0;
        for (int i = 0, j = 0; i < nums.size(); i ++ ) {
            while (nums[i] - nums[j] > mid) j ++ ;
            res += i - j;
        }
        return res;
    }
public:
    // 2023.2.19, from https://www.acwing.com/activity/content/code/content/975477/
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 1e6;
        while (l < r) {
            int mid = l + r >> 1;
            if (get(nums, mid) >= k) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};


class Solution99 {
public:
    // 2023.2.19, from https://github.com/wisdompeak/LeetCode/blob/master/Binary_Search/719.Find-K-th-Smallest-Pair-Distance/719.Find-K-th-Smallest-Pair-Distance.cpp
    /*
        719.Find-K-th-Smallest-Pair-Distance
        对于能够明显判断出上下界的题目，用二分法的思想往往非常巧妙。

        在本题中，将nums排序后，最大的差值是nums.back()-nums[0]；最小的差值必定存在于相邻的两个元素之间，也很容易算出来。
        于是相当于我们知道了差值的左边界left，右边界right，需要找一个居于中间的数mid，使得差值小于等于mid的pair数目正好是k个。

        对于二分法的外框架，容易知道，需要二分搜索的次数就是 log_2^(right-left)。对于给出的mid，如何得到差值小于等于mid的pair
        数目呢？也很简单，只要loop over 第一个数，那么第二个数的范围就可以通过upper_bound来确定。特别注意为什么是upper_bound.

        for (int i=0; i<nums.size(); i++)
        {
        auto pos=upper_bound(nums.begin(),nums.end(),nums[i]+mid); // 值大于nums[i]+mid的元素的指针
        count+= pos-1-(nums.begin()+i); // 值小于等于nums[i]+mid的元素的个数
        }
        用upper_bound()是 nlog(n)的复杂度。当然也可以通过双指针来做，就是o(n)的复杂度。

        PS:对于求Kth smallest的题目，用binary search by value的方法往往能有奇效。相似的题目有：

        668	Kth-Smallest-Number-in-Multiplication-Table
        373	Find K Pairs with Smallest Sums
        81	Search in Rotated Sorted Array II
        4	Median of Two Sorted Arrays    
    */
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int N=nums.size();
        
        int left=nums[1]-nums[0];
        for (int i = 0; i <= N-2; ++i)
            left = min(left, nums[i+1] - nums[i]);
        
        int right=nums[N-1]-nums[0];
        int mid;
        
        while (left<right)
        {
            mid=left+(right-left)/2;
            int count=0;
            for (int i=0; i<N; i++)
            {
                auto pos=upper_bound(nums.begin(),nums.end(), nums[i]+mid);
                count+= pos-1-(nums.begin()+i);
            }
            if (count<k)
                left=mid+1;
            else
                right=mid;
        }
        
        return left;
    }
};


class Solution98 {
public:
    // 2023.2.19, from https://walkccc.me/LeetCode/problems/0719/
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));

        int l = 0;
        int r = nums.back() - nums.front();

        while (l < r) {
        const int m = (l + r) / 2;
        if (pairDistancesNoGreaterThan(nums, m) >= k)
            r = m;
        else
            l = m + 1;
        }

        return l;
    }

private:
    int pairDistancesNoGreaterThan(const vector<int>& nums, int m) {
        int count = 0;
        int j = 1;
        // For each index i, find the first index j s.t. nums[j] > nums[i] + m,
        // So pairDistancesNoGreaterThan for index i will be j - i - 1
        for (int i = 0; i < nums.size(); ++i) {
        while (j < nums.size() && nums[j] <= nums[i] + m)
            ++j;
        count += j - i - 1;
        }
        return count;
    }
};


class Solution97 {
    int count(vector<int> &A, int M) {
        int cnt = 0;
        for (int i = 0; i < A.size(); ++i) cnt += upper_bound(begin(A), end(A), A[i] + M) - begin(A) - i - 1;
        return cnt;
    }
public:
    // OJ: https://leetcode.com/problems/find-k-th-smallest-pair-distance/
    // Author: github.com/lzl124631x
    // Time: O(NlogN + NlogNlogD) where D is the distance between the minimal distance and the maximal distance.
    // Space: O(1)
    int smallestDistancePair(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int L = INT_MAX, R = A.back() - A[0];
        for (int i = 1; i < A.size(); ++i) L = min(L, A[i] - A[i - 1]);
        while (L <= R) {
            int M = (L + R) / 2, cnt = count(A, M);
            if (cnt < k) L = M + 1;
            else R = M - 1;
        }
        return L;
    }
};


class Solution96 {
    int count(vector<int> &A, int M) {
        int cnt = 0, i = 0, j = 0, N = A.size();
        while (i < N) {
            while (j < N && A[j] - A[i] <= M) ++j;
            cnt += j - i - 1;
            ++i;
        }
        return cnt;
    }
public:
    // OJ: https://leetcode.com/problems/find-k-th-smallest-pair-distance/
    // Author: github.com/lzl124631x
    // Time: O(NlogN + NlogD) where D is the distance between the minimal distance and the maximal distance.
    // Space: O(1)
    /*
        We can reduce the time complexity of count function from O(NlogN) to O(N).
    */
    int smallestDistancePair(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int L = INT_MAX, R = A.back() - A[0];
        for (int i = 1; i < A.size(); ++i) L = min(L, A[i] - A[i - 1]);
        while (L <= R) {
            int M = (L + R) / 2, cnt = count(A, M);
            if (cnt < k) L = M + 1;
            else R = M - 1;
        }
        return L;
    }
};


class Solution95 {
public:
    // 2023.2.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/find-k-th-smallest-pair-distance.cpp
    // Time:  O(nlogn + nlogw), n = len(nums), w = max(nums) - min(nums)
    // Space: O(1)
    // Binary search with sliding window solution
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front() + 1;
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if (possible(mid, nums, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool possible(const int guess, const vector<int>& nums, const int k) {
        int count = 0, left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while ((nums[right] - nums[left]) > guess) {
                ++left;
            }
            count += right - left;
        }
        return count >= k;
    }
};


class Solution94 {
public:
    // 2023.2.19, from https://github.com/grandyang/leetcode/issues/719
    /*
        这道题给了我们一个数组，让我们找第k小的数对儿距离，数对儿距离就是任意两个数字之间的绝对值差。那么我们先来考虑最暴力的解法，
        是不是就是遍历任意两个数字，算出其绝对值差，然后将所有距离排序，取第k小的就行了。But，OJ 摇着头说图样图森破。但是我们可以
        在纯暴力搜索的基础上做些优化，从而让 OJ 说 YES。那么下面这种利用了桶排序的解法就是一种很好的优化，题目中给了数字的大小范围，
        不会超过一百万，所以我们就建立一百万个桶，然后还是遍历任意两个数字，将计算出的距离放到对应的桶中，这里桶不是存的具体距离，
        而是该距离出现的次数，桶本身的位置就是距离，所以我们才建立了一百万个桶。然后我们就可以从0开始遍历到一百万了，这样保证了我们
        先处理小距离，如果某个距离的出现次数大于等于k了，那么我们返回这个距离，否则就用k减去这个距离的出现次数，参见代码如下：    
    */
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size(), N = 1000000;
        vector<int> cnt(N, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ++cnt[abs(nums[i] - nums[j])];
            }
        }
        for (int i = 0; i < N; ++i) {
            if (cnt[i] >= k) return i;
            k -= cnt[i];
        }
        return -1;
    }
};


class Solution93 {
public:
    // 2023.2.19, from https://github.com/grandyang/leetcode/issues/719
    /*
        上面的解法虽然逃脱了 OJ 的魔掌，但也仅仅是险过，并不高效。我们来看一种基于二分搜索的解法。这道题使用的二分搜索法是博主归纳总结帖 
        LeetCode Binary Search Summary 二分搜索法小结 中的第四种，即二分法的判定条件不是简单的大小关系，而是可以抽离出子函数的情况，
        下面我们来看具体怎么弄。我们的目标是快速定位出第k小的距离，那么很适合用二分法来快速的缩小查找范围，然而最大的难点就是如何找到判定
        依据来折半查找，即如果确定搜索目标是在左半边还是右半边。做过 Kth Smallest Element in a Sorted Matrix 和 Kth Smallest Number 
        in Multiplication Table 这两道题的同学应该对这种搜索方式并不陌生。核心思想是二分确定一个中间数，然后找到所有小于等于这个中间数
        的距离个数，用其跟k比较来确定折半的方向。具体的操作是，我们首先要给数组排序，二分搜索的起始 left 为0，结束位置 right 为最大距离，
        即排序后的数字最后一个元素减去首元素。然后进入 while 循环，算出中间值 mid，此外我们还需要两个变量 cnt 和 start，其中 cnt 是记录
        小于等于 mid 的距离个数，start 是较小数字的位置，均初始化为0，然后我们遍历整个数组，先进行 while 循环，如果 start 未越界，并且
        当前数字减去 start 指向的数组之差大于 mid，说明此时距离太大了，我们增加减数大小，通过将 start 右移一个，那么 while 循环退出后，
        就有 i - start 个距离小于等于 mid，将其加入 cnt 中，举个栗子来说：

        1    2    3    3    5

        start          i

        mid = 2

        如果 start 在位置0，i在位置3，那么以 nums[i] 为较大数可以产生三个（i - start）小于等于 mid 的距离，[1 3], [2 3], [3 3]，这样当
        i遍历完所有的数字后，所有小于等于 mid 的距离的个数就求出来了，即 cnt。然后我们跟k比较，如果其小于k，那么 left 赋值为 mid+1，反之，
        则 right 赋值为 mid。最终返回 right 或 left 均可，参见代码如下：    
    */
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = nums.back() - nums[0];
        while (left < right) {
            int mid = left + (right - left) / 2, cnt = 0, start = 0;
            for (int i = 0; i < n; ++i) {
                while (start < n && nums[i] - nums[start] > mid) ++start;
                cnt += i - start;
            }
            if (cnt < k) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};


class Solution92 {
public:
    // 2023.2.19, from https://zxi.mytechroad.com/blog/?s=LeetCode+719.
    // Author: Huahua
    // Runtime: 9 ms
    // C++ / binary search
    int smallestDistancePair(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums.back() - nums.front();
        while (l <= r) {
            int cnt = 0;
            int j = 0;
            int m = l + (r - l) / 2;
            for (int i = 0; i < n; ++i) {
                while (j < n && nums[j] - nums[i] <= m) ++j;
                cnt += j - i - 1;
            }
            cnt >= k ? r = m - 1 : l = m + 1;
        }        
        return l;
    }
};


class Solution {
public:
    // 2023.2.19, from https://zxi.mytechroad.com/blog/?s=LeetCode+719.
    // Author: Huahua
    // Runtime: 549 ms
    // C++ / bucket sort w/ vector O(n^2)
    int smallestDistancePair(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        const int N = nums.back();
        vector<int> count(N + 1, 0);        
        const int n = nums.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
               ++count[nums[j] - nums[i]];
        for (int i = 0; i <= N; ++i) {
            k -= count[i];
            if (k <= 0) return i;
        }
        return 0;
    }
};


// @lc code=end

