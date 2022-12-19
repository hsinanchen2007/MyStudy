/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

/*

https://leetcode.cn/problems/contains-duplicate-ii/

219. 存在重复元素 II
给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。
如果存在，返回 true ；否则，返回 false 。

 
示例 1：

输入：nums = [1,2,3,1], k = 3
输出：true

示例 2：

输入：nums = [1,0,1,1], k = 1
输出：true

示例 3：

输入：nums = [1,2,3,1,2,3], k = 2
输出：false
 

提示：

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
通过次数196,613提交次数442,627

*/

// @lc code=start
class Solution100 {
public:
    // 2022.8.16, by Hsinan
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int start = 0;
        // hash table for key and index values
        unordered_map<int, int> hashTbl;
        for (int end = 0; end < nums.size(); end++) {
            // check if the key is already existed in hash table or not
            if (hashTbl.find(nums[end]) != hashTbl.end()) {
                // if key is existed, check distance to end with k
                if (abs(hashTbl[nums[end]] - end) <= k) {
                    return true;
                }
            }
            // if key is not existed or over the k, add/update key with latest index
            hashTbl[nums[end]] = end;
        }
        return false;
    }
};


class Solution99 {
public:
    // 2022.8.16, from https://www.acwing.com/activity/content/code/content/432636/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/432636/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i ++ ) {
            int x = nums[i];
            if (hash.count(x) && i - hash[x] <= k) return true;
            hash[x] = i;
        }
        return false;
    }
};


class Solution98 {
public:
    // 2022.8.16, https://github.com/grandyang/leetcode/issues/219
    /*
        这道题是之前那道 Contains Duplicate 的延伸，不同之处在于那道题只要判断下数组中是否有重复值，
        而这道题限制了数组中只许有一组重复的数字，而且其坐标差不能超过k。首先需要一个 HashMap，来记录
        每个数字和其坐标的映射，然后需要一个变量d来记录第一次出现重复数字的坐标差。由于题目要求只能有一
        组重复的数字，所以在遇到重复数字时，首先判断d是否已经存了值，如果d已经有值了，说明之前有过了重复
        数字，则直接返回 false 即可。如果没有，则此时给d附上值。在网上看到有些解法在这里就直接判断d和k
        的关系然后返回结果了，其实这样是不对的。因为题目要求只能有一组重复数，就是说如果后面又出现了重复
        数，就没法继续判断了。所以正确的做法应该是扫描完整个数组后在判断，先看d有没有存入结果，如果没有，
        则说明没出现过重复数， 返回 false 即可。如果d有值，再跟k比较，返回对应的结果。OJ 的 test case 
        没有包含所有的情况，比如当 nums = [1, 2, 3, 1, 3], k = 3 时，实际上应该返回 false，但是
        有些返回 true 的算法也能通过 OJ，个人认为正确的解法应该如 评论区十二楼 所示，但是由于后来题目
        要求变了，那么就没啥歧义了，正确解法如下：
    */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) return true;
            else m[nums[i]] = i;
        }
        return false;
    }
};


class Solution97 {
public:
    // 2022.8.16, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/contains-duplicate-ii.cpp
    // Time:  O(n)
    // Space: O(n)
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < nums.size(); ++i) {
            if (lookup.find(nums[i]) == lookup.end()) {
                lookup[nums[i]] = i;
            } else {
                // If the value occurs before, check the difference.
                if (i - lookup[nums[i]] <= k) {
                    return true;
                }
                // Update the index of the value.
                lookup[nums[i]] = i;
            }
        }
        return false;
    }
};


class Solution96 {
public:
    // 2022.8.16, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/219.%20Contains%20Duplicate%20II
    // OJ: https://leetcode.com/problems/contains-duplicate-ii/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(N)
    bool containsNearbyDuplicate(vector<int>& A, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < A.size(); ++i) {
            if (m.count(A[i]) && i - m[A[i]] <= k) return true;
            m[A[i]] = i;
        }
        return false;
    }
};


class Solution95 {
public:
    // 2022.8.16, from https://walkccc.me/LeetCode/problems/0219/
    // Time: O(n)
    // Space: O(n)
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); ++i) {
        if (!seen.insert(nums[i]).second)
            return true;
        if (i >= k)
            seen.erase(nums[i - k]);
        }

        return false;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

