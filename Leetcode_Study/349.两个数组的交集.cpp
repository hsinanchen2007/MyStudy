/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start

/*

https://leetcode.cn/problems/intersection-of-two-arrays/

349. 两个数组的交集
给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]

示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
 

提示：

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
通过次数324,265提交次数436,336

*/

class Solution100 {
public:
    // 2022.7.23, by Hsinan
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // sanity check
        if (nums1.size() == 0 || nums2.size() == 0) {
            return {};
        }

        // hash table
        std::unordered_map <int, int> lookup;

        // answer vector to return
        std::vector<int> answer;

        for (int i : nums1) {
            // only add unique one in nums1
            if (lookup[i] == 0) lookup[i] = 1;
        }
        for (int j : nums2) {
            // only update 1 in nums2 if lookup has 1 from previous nums1
            if (lookup[j] == 1) lookup[j] = lookup[j] + 1;
        }
        for (auto k : lookup) {
            // when lookup second is 2, that means this number existed in
            // both nums1 and nums2, if second is 1, that means it only existed
            // in nums1
            if (k.second == 2) answer.push_back(k.first);
        }

        return answer;
    }
};


class Solution99 {
public:
    // 2022.7.23
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // https://leetcode-cn.com/problems/intersection-of-two-arrays/
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // 首先对两个数组进行排序
        sort(nums1.begin(), nums1.end());

        sort(nums2.begin(), nums2.end());
       

        // 计算出两个数组的长度
        int length1 = nums1.size();

        int length2 = nums2.size();
        
    
        // 两个数组的交集结果数组长度必然是小于等于最短数组的长度
        vector<int> res ;

        // 设置三个索引指针

        // index 指向结果数组 res ，每当 index 指向的位置填充了元素就向后移动
        // int index = 0;
        
        // index1 指向数组 nums1 中的元素，将该元素和 index2 指向数组 nums2 中的元素进行比较
        int index1 = 0;
        
        // index2 指向数组 nums2 中的元素，将该元素和 index1 指向数组 nums1 中的元素进行比较
        int index2 = 0;

        // 移动 index1 和 index2 
        while (index1 < length1 && index2 < length2) {
            
            // 获取 index1 指向的元素值
            int num1 = nums1[index1];
            
            // 获取 index2 指向的元素值
            int num2 = nums2[index2];

            // num1 和 num2 的大小关系有三种

            // 1、num1 == num2
            if (num1 == num2) {

                // 由于输出结果中的每个元素一定是 【唯一】 的，所以要做一下判断
                // 如果 res 中的 index 在起始位置，说明还没有存放元素
                // 那么这个相等的元素可以存放到 res 中

                // 如果 res 中的 index 不在起始位置
                // 当它前面存放的元素并不是现在想要存放的元素
                // 那么这个相等的元素可以存放到 res 中
                if ( !res.size() || num1 != res.back()) {

                    // 存放到 res 中
                    res.push_back(num1);
                   
                }

                // 移动 index1 ，比较其它元素
                index1++;
               
                // 移动 index2 ，比较其它元素
                index2++;

            // 2、num1 < num2
            } else if (num1 < num2) {
                
                // 由于两个数组已经排序了，说明此时 num1 肯定会小于 nums2 数组中 num2 后面所有的数
                // 那 num1 肯定是无法在 nums2 中找到相等的元素
                // 移动 index1 ，比较其它元素
                index1++;

            // 3、num1 > num2
            } else {

                // 由于两个数组已经排序了，说明此时 num2 肯定会小于 nums1 数组中 num1 后面所有的数
                // 那 num2 肯定是无法在 nums1 中找到相等的元素
                // 移动 index2 ，比较其它元素
                index2++;

            }
        }

        // 最后返回结果数组中有值的那些元素就行
        return res;

    }
};


class Solution98 {
public:
    // 2022.7.23, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.md
    /*
        关于本题，我录制了讲解视频：学透哈希表，set使用有技巧！Leetcode：349. 两个数组的交集，看视频配合题解，事半功倍。
        这道题目，主要要学会使用一种哈希数据结构：unordered_set，这个数据结构可以解决很多类似的问题。
        注意题目特意说明：输出结果中的每个元素一定是唯一的，也就是说输出的结果的去重的， 同时可以不考虑输出结果的顺序
        这道题用暴力的解法时间复杂度是O(n^2)，那来看看使用哈希法进一步优化。

        那么用数组来做哈希表也是不错的选择，例如242. 有效的字母异位词
        但是要注意，使用数组来做哈希的题目，是因为题目都限制了数值的大小。
        而这道题目没有限制数值的大小，就无法使用数组来做哈希表了。
        而且如果哈希值比较少、特别分散、跨度非常大，使用数组就造成空间的极大浪费。

        此时就要使用另一种结构体了，set ，关于set，C++ 给提供了如下三种可用的数据结构：

        std::set
        std::multiset
        std::unordered_set
        std::set和std::multiset底层实现都是红黑树，std::unordered_set的底层实现是哈希表， 使用
        unordered_set 读写效率是最高的，并不需要对数据进行排序，而且还不要让数据重复，所以选择unordered_set。

        思路如图所示：

        拓展
        那有同学可能问了，遇到哈希问题我直接都用set不就得了，用什么数组啊。

        直接使用set 不仅占用空间比数组大，而且速度要比数组慢，set把数值映射到key上都要做hash计算的。

        不要小瞧 这个耗时，在数据量大的情况，差距是很明显的。

        后记
        本题后面 力扣改了 题目描述 和 后台测试数据，增添了 数值范围：

        1 <= nums1.length, nums2.length <= 1000
        0 <= nums1[i], nums2[i] <= 1000
        所以就可以 使用数组来做哈希表了， 因为数组都是 1000以内的。

        对应C++代码如下：
    */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
        int hash[1005] = {0}; // 默认数值为0
        for (int num : nums1) { // nums1中出现的字母在hash数组中做记录
            hash[num] = 1;
        }
        for (int num : nums2) { // nums2中出现话，result记录
            if (hash[num] == 1) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};


class Solution97 {
public:
    // 2022.7.23, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/349.%20Intersection%20of%20Two%20Arrays
    vector<int> intersection(vector<int>& A, vector<int>& B) {
        sort(begin(A), end(A));
        sort(begin(B), end(B));
        vector<int> ans;
        int i = 0, j = 0, M = A.size(), N = B.size();
        while (i < M && j < N) {
            if (A[i] < B[j]) ++i;
            else if (A[i] > B[j]) ++j;
            else {
                int n = A[i];
                while (i < M && A[i] == n) ++i;
                while (j < N && B[j] == n) ++j;
                ans.push_back(n);
            }
        }
        return ans;
    }
};


class Solution96 {
public:
    // 2022.7.23, from https://walkccc.me/LeetCode/problems/0349/
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> set{begin(nums1), end(nums1)};

        for (const int num : nums2)
        if (set.erase(num))
            ans.push_back(num);

        return ans;
    }
};


class Solution95 {
public:
    // 2022.7.23, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/intersection-of-two-arrays.cpp
    // Time:  O(mlogm + nlogn)
    // Space: O(m + n)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(begin(nums1), end(nums1)); sort(begin(nums2), end(nums2));
        set_intersection(cbegin(nums1), cend(nums1), cbegin(nums2), cend(nums2), back_inserter(result));
        result.erase(unique(begin(result), end(result)), end(result));
        return result;
    }
};


class Solution94 {
public:
    // 2022.7.23, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/intersection-of-two-arrays.cpp
    // Time:  O(max(m, n) * log(max(m, n)))
    // Space: O(1)
    // Two pointers solution.
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto it1 = nums1.cbegin(), it2 = nums2.cbegin();
        while (it1 != nums1.cend() && it2 != nums2.cend()) {
            if (*it1 < *it2) {
                ++it1;
            } else if (*it1 > *it2) {
                ++it2;
            } else {
                if (result.empty() || result.back() != *it1) {
                    result.emplace_back(*it1);
                }
                ++it1, ++it2;
            }
        }
        return result;
    }
};


class Solution93 {
public:
    // 2022.7.23, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/intersection-of-two-arrays.cpp
    // Time:  O(max(m, n) * log(max(m, n)))
    // Space: O(1)
    // Binary search solution.
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersection(nums2, nums1);
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        auto it = nums2.cbegin();
        for (const auto& i : nums1) {
            it = lower_bound(it, nums2.cend(), i);
            if (it != nums2.end() && *it == i) {
                result.emplace_back(*it);
                it = upper_bound(it, nums2.cend(), i);
            }
        }
        
        return result;
    }
};


class Solution92 {
public:
    // 2022.7.23, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/intersection-of-two-arrays.cpp
    // Time:  O(m + n)
    // Space: O(min(m, n))
    // Hash solution.
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersection(nums2, nums1);
        }

        unordered_set<int> lookup{nums1.cbegin(), nums1.cend()};

        vector<int> result;
        for (const auto& i : nums2) {
            if (lookup.count(i)) {
                result.emplace_back(i);
                lookup.erase(i);
            }
        }

        return result;
    }
};


class Solution91 {
public:
    // 2022.7.23, from AcWing 
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/487556/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> S;
        for (auto x: nums1) S.insert(x);
        vector<int> res;
        for (auto x: nums2)
            if (S.count(x)) {
                res.push_back(x);
                S.erase(x);
            }
        return res;
    }
};


class Solution90 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/349
    /*
        这道题让找两个数组交集的部分（不包含重复数字），难度不算大，我们可以用个 HashSet 把 nums1 都放进去，
        然后遍历 nums2 的元素，如果在 HashSet 中存在，说明是交集的部分，加入结果的 HashSet 中，最后再把结果
        转为 vector 的形式即可：

        解法一：
    */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end()), res;
        for (auto a : nums2) {
            if (st.count(a)) res.insert(a);
        }
        return vector<int>(res.begin(), res.end());
    }
};


class Solution89 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/349
    /*
        我们还可以使用两个指针来做，先给两个数组排序，然后用两个指针分别指向两个数组的开头，然后比较两个数组的大小，
        把小的数字的指针向后移，如果两个指针指的数字相等，那么看结果 res 是否为空，如果为空或者是最后一个数字和当
        前数字不等的话，将该数字加入结果 res 中，参见代码如下：

        解法二：
    */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) ++i;
            else if (nums1[i] > nums2[j]) ++j;
            else {
                if (res.empty() || res.back() != nums1[i]) {
                    res.push_back(nums1[i]);
                }
                ++i; ++j;
            }
        }
        return res;
    }
};


class Solution88 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/349
    /*
        我们还可以使用二分查找法来做，思路是将一个数组排序，然后遍历另一个数组，把遍历到的每个数字在排序号的数组中用
        二分查找法搜索，如果能找到则放入结果 set 中，这里我们用到了set的去重复的特性，最后我们将set转为vector即可：

        解法三：
    */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        sort(nums2.begin(), nums2.end());
        for (auto a : nums1) {
            if (binarySearch(nums2, a)) {
                res.insert(a);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
    bool binarySearch(vector<int> &nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return false;
    }
};


class Solution {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/349
    /*
        或者我们也可以使用STL的 set_intersection 函数来找出共同元素，很方便：

        解法四：
    */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), res;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
        return vector<int>(res.begin(), res.end());
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// 2022.8.15, not in top list

// @lc code=end

