/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

/*

https://leetcode.cn/problems/contains-duplicate-iii/

220. 存在重复元素 III

困难
677
company
亚马逊

给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <= t ，
同时又满足 abs(i - j) <= k 。

如果存在则返回 true，不存在返回 false。 

示例 1：

输入：nums = [1,2,3,1], k = 3, t = 0
输出：true

示例 2：

输入：nums = [1,0,1,1], k = 1, t = 2
输出：true

示例 3：

输入：nums = [1,5,9,1,5,9], k = 2, t = 3
输出：false 

提示：

0 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
0 <= k <= 104
0 <= t <= 231 - 1

*/

// @lc code=start
class Solution100 {
public:
    // 2023.2.20, from https://www.acwing.com/activity/content/code/content/432652/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/432652/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。        
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        typedef long long LL;
        multiset<LL> S;
        S.insert(1e18), S.insert(-1e18);
        for (int i = 0, j = 0; i < nums.size(); i ++ ) {
            if (i - j > k) S.erase(S.find(nums[j ++ ]));
            int x = nums[i];
            auto it = S.lower_bound(x);
            if (*it - x <= t) return true;
            -- it;
            if (x - *it <= t) return true;
            S.insert(x);
        }
        return false;
    }
};


class Solution99 {
public:
    // 2023.2.20, from https://walkccc.me/LeetCode/problems/0220/
    /*
        Approach 1: Ordered Set
        Time: O(nlogk)
        Space: O(k)    
    */
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window;

        for (int i = 0; i < nums.size(); ++i) {
            const auto it = window.lower_bound(static_cast<long>(nums[i]) - t);
            if (it != cend(window) && *it - nums[i] <= t)
                return true;
            window.insert(nums[i]);
            if (i >= k)
                window.erase(nums[i - k]);
        }

        return false;
    }
};


class Solution98 {
public:
    // 2023.2.20, from https://walkccc.me/LeetCode/problems/0220/
    /*
        Approach 2: Bucket
        Time: O(n)
        Space: O((max(nums)−min(nums))/t)→O(k)    
    */
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.empty() || k <= 0 || t < 0)
        return false;

        const long min = *min_element(begin(nums), end(nums));
        const long diff = t + 1L;  // In case of t = 0
        // Use long because corner case INT_MAX - (-1) will overflow
        unordered_map<long, long> bucket;

        for (int i = 0; i < nums.size(); ++i) {
            const long num = nums[i];
            const long key = getKey(num, min, diff);
            if (bucket.count(key))  // Current bucket
                return true;
            if (bucket.count(key - 1) &&
                num - bucket[key - 1] < diff)  // Left adjacent bucket
                return true;
            if (bucket.count(key + 1) &&
                bucket[key + 1] - num < diff)  // Right adjacent bucket
                return true;
            bucket[key] = num;
            if (i >= k)
                bucket.erase(getKey(nums[i - k], min, diff));
        }

        return false;
    }

private:
    int getKey(long num, long min, long diff) {
        return (num - min) / diff;
    }
};


class Solution97 {
public:
    // OJ: https://leetcode.com/problems/contains-duplicate-iii/
    // Author: github.com/lzl124631x
    // Time: O(NlogK)
    // Space: O(K)
    bool containsNearbyAlmostDuplicate(vector<int>& A, int k, int t) {
        if (t < 0) return false;
        multiset<long> s;
        for (int i = 0; i < A.size(); ++i) {
            if (i > k) s.erase(s.find(A[i - k - 1]));
            if (s.lower_bound((long)A[i] - t) != s.upper_bound((long)A[i] + t)) return true;
            s.insert(A[i]);
        }
        return false;
    }
};


class Solution96 {
public:
    // OJ: https://leetcode.com/problems/contains-duplicate-iii/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(K)
    // Ref: https://leetcode.com/problems/contains-duplicate-iii/discuss/61645/AC-O(N)-solution-in-Java-using-buckets-with-explanation
    bool containsNearbyAlmostDuplicate(vector<int>& A, int k, int t) {
        if (A.size() < 2 || k < 1 || t < 0) return false;
        unordered_map<long, long> m;
        for (int i = 0; i < A.size(); ++i) {
            if (i > k) m.erase(((long)A[i - k - 1] - INT_MIN) / ((long)t + 1));
            long n = (long)A[i] - INT_MIN, id = n / ((long)t + 1);
            if (m.count(id) || (m.count(id - 1) && A[i] - m[id - 1] <= t) || (m.count(id + 1) && m[id + 1] - A[i] <= t)) return true; 
            m[id] = A[i];
        }
        return false;
    }
};


class Solution95 {
public:
    // 2023.2.20, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/contains-duplicate-iii.cpp
    // Time:  O(nlogk)
    // Space: O(k)
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 0 || t < 0) {
            return false;
        }
        
        queue<int64_t> window;
        multiset<int64_t> bst;
        for (int i = 0; i < nums.size(); ++i) {
            // Only keep at most k elements.
            if (bst.size() > k) {
                int num = window.front();
                window.pop();
                bst.erase(bst.find(num));
            }
            // Every search costs time: O(logk).
            const auto it = bst.lower_bound(static_cast<int64_t>(nums[i]) - t);
            if (it == bst.cend() || (*it - nums[i]) > t) {
                // Not found.
                window.emplace(nums[i]);
                bst.emplace(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};


class Solution94 {
public:
    // 2023.2.20, from https://github.com/grandyang/leetcode/issues/220
    /*
        这道题跟之前两道Contains Duplicate 包含重复值和Contains Duplicate II 包含重复值之二的关联并不是很大，前两道起码跟重复值有关，
        这道题的焦点不是在重复值上面，反而是关注与不同的值之间的关系，这里有两个限制条件，两个数字的坐标差不能大于k，值差不能大于t。这道题
        如果用brute force会超时，所以我们只能另辟蹊径。这里我们使用map数据结构来解,用来记录数字和其下标之间的映射。 这里需要两个指针i和j，
        刚开始i和j都指向0，然后i开始向右走遍历数组，如果i和j之差大于k，且m中有nums[j]，则删除并j加一。这样保证了m中所有的数的下标之差都
        不大于k，然后我们用map数据结构的lower_bound()函数来找一个特定范围，就是大于或等于nums[i] - t的地方，所有小于这个阈值的数和nums[i]
        的差的绝对值会大于t (可自行带数检验)。然后检测后面的所有的数字，如果数的差的绝对值小于等于t，则返回true。最后遍历完整个数组返回
        false。代码如下：    
    */
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - j > k) m.erase(nums[j++]);
            auto a = m.lower_bound((long long)nums[i] - t);
            if (a != m.end() && abs(a->first - nums[i]) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }
}; 


class Solution93 {
public:
    // 2023.2.20, from https://zxi.mytechroad.com/blog/?s=LeetCode+220.
    // Author: Huahua, running time: 12 ms
    /*
        Solution: Sliding Window + Multiset (OrderedSet)
        Maintaining a sliding window of sorted numbers of k + 1. After the i-th number was inserted into the sliding window, 
        check whether its left and right neighbors satisfy abs(nums[i] – neighbor) <= t

        Time complexity: O(nlogk)
        Space complexity: O(k)    
    */
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k)
                s.erase(s.find(nums[i - k - 1]));
                    
            auto it = s.insert(nums[i]);
            if (it != begin(s) && *it - *prev(it) <= t)
                return true;
            if (next(it) != end(s) && *next(it) - *it <= t)
                return true;
        }
        return false;
    }
};


class Solution {
public:
    // 作者：xzp
    // 链接：https://leetcode.cn/leetbook/read/sliding-window-and-two-pointers/rumvrr/?discussion=xHPzO3
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<int> rec;
        for(int i = 0 ; i < n ; i++){
            auto iter = rec.lower_bound(max(nums[i] , INT_MIN + t) - t);//找到第一个大于等于nums[i]-t的元素
            if(iter != rec.end() && *iter <= min(nums[i] , INT_MAX - t) + t){
                return true;
            }
            rec.insert(nums[i]);
            if(i >= k) {
                rec.erase(nums[i - k]);
            }
        }
        return false;
    }
};


// @lc code=end

