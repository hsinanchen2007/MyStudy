/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

/*

https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/

1658. 将 x 减到 0 的最小操作数

中等
267
company
小米集团

给你一个整数数组 nums 和一个整数 x 。每一次操作时，你应当移除数组 nums 最左边或最右边的元素，然后从 x 中减去该元素的值。
请注意，需要 修改 数组以供接下来的操作使用。

如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 -1 。

示例 1：

输入：nums = [1,1,4,2,3], x = 5
输出：2
解释：最佳解决方案是移除后两个元素，将 x 减到 0 。

示例 2：

输入：nums = [5,6,7,8,9], x = 4
输出：-1

示例 3：

输入：nums = [3,2,20,1,1,3], x = 10
输出：5
解释：最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109

*/

// @lc code=start
class Solution100 {
public:
    // 作者：俊桑
    // 链接：https://leetcode.cn/leetbook/read/sliding-window-and-two-pointers/rl4f2t/?discussion=uF6dCQ
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int minOperations(vector<int>& nums, int x) {
        // get total and sanity check
        int sum = accumulate(cbegin(nums), cend(nums), 0);
        if(x > sum) return -1;

        // get target and left/right pointers for slidding window
        int target = sum - x; // 求得target的值
        sum = 0;
        int ans = -1;
        int left = 0, right = 0;

        // 使用滑动窗口寻找最大的序列
        for(; right < nums.size(); ++right){
            sum += nums[right];
            while(sum > target){
                sum -= nums[left];
                left++;
            }
            if(sum == target){
                ans = max(ans, right-left+1);
            }
        }
        // 如果没找到，则返回-1
        if(ans == -1) 
            return -1;
        else 
            return nums.size() - ans;
    }
};


class Solution99 {
public:
    // OJ: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    int minOperations(vector<int>& A, int x) {
        int N = A.size(), i = 0, j = N - 1, left = 0, right = 0, ans = N + 1;
        for (; i < N && left < x; ++i) left += A[i];
        if (left < x) return -1;
        if (left == x) ans = i;
        while (i > 0) {
            left -= A[--i];
            while (left + right < x) right += A[j--];
            if (left + right == x) ans = min(ans, i + N - 1 - j);
        }
        return ans == N + 1 ? -1 : ans;
    }
};


class Solution98 {
public:
    // 2023.2.9, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/minimum-operations-to-reduce-x-to-zero.cpp
    // Time:  O(n)
    // Space: O(1)
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(cbegin(nums), cend(nums), 0) - x;
        int result = -1;
        int curr = 0, left = 0;
        for (int right = 0; right < size(nums); ++right) {
            curr += nums[right];
            while (left < size(nums) && curr > target) {
                curr -= nums[left++];
            }
            if (curr == target) {
                result = max(result, right - left + 1);
            }
        }
        return result != -1 ? size(nums) - result : -1;
    }
};


class Solution97 {
public:
    // 2023.2.9, from https://github.com/wisdompeak/LeetCode/blob/master/Hash/1658.Minimum-Operations-to-Reduce-X-to-Zero/1658.Minimum-Operations-to-Reduce-X-to-Zero.cpp
    /*
        1658.Minimum-Operations-to-Reduce-X-to-Zero
        本题的题意是：在nums数组里找a个元素的前缀和，与b个元素的后缀和，使得他们的sum是x，问如果能找到的话，a+b最少是多少？

        比较直观的算法就是：从右往左遍历b的数目，给定了b，我们就要确定多少个元素的前缀和presum[a]，恰好等于x-sufsum[b]。显然，
        我们可以提前遍历数组来构建所有presum[i]->i的hash表。利用这个hash表就能用o(1)时间快速得到指定前缀和所对应的位置。只要
        这个位置i小于b，那么i和b就是一对合法的解。

        最终答案是遍历所有的b，找到i+(n-b)的最小值。
    */
    int minOperations(vector<int>& nums, int x) 
    {
        int n = nums.size();
        unordered_map<int,int>Map;
        int presum = 0;
        Map[0] = -1;
        for (int i=0; i<n; i++)
        {
            presum += nums[i];
            if (Map.find(presum)==Map.end())
                Map[presum] = i;
        }
        
        int ret = INT_MAX;
        if (Map.find(x)!=Map.end())
            ret = Map[x]+1;
        
        int sufsum = 0;
        for (int b = n-1; b>=0; b--)
        {
            sufsum += nums[b];
            int pre = x - sufsum;
            if (Map.find(pre)!=Map.end())
            {
                int a = Map[pre];
                if (a<b)
                {
                    ret = min(ret, a+1 + n-b);
                }
            }
        }
        
        return ret==INT_MAX ? -1: ret;        
    }
};


class Solution96 {
public:
    // 作者：程序喵大人
    // 链接：https://leetcode.cn/leetbook/read/sliding-window-and-two-pointers/rl4f2t/?discussion=cGg8nK
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        int target = sum - x;
        int size = nums.size();
        int left = 0;
        int right = 0;
        int cur = 0;
        int m = -1;
        while (left < size) {
            if (right < size) {
                cur += nums[right];
                ++right;
            }
            while (cur > target && left < size) {
                cur -= nums[left];
                ++left;
            }
            if (cur == target) {
                m = max(m, right - left);
            }
            if (right == size) {
                ++left;
            }
        }
        return m == -1 ? -1 : size - m;
    }
};


class Solution95 {
public:
    // Author: Huahua
    // Solution1: Prefix Sum + Hashtable
    // Time complexity: O(n)
    // Space complexity: O(n)
    int minOperations(vector<int>& nums, int x) {
        const int n = nums.size();
        vector<int> l(n), r(n);
        unordered_map<int, int> ml, mr;
        ml[0] = mr[0] = -1;
        for (int i = 0; i < n; ++i) {
        l[i] = nums[i] + (i > 0 ? l[i - 1] : 0);      
        r[i] = nums[n - i - 1] + (i > 0 ? r[i - 1]: 0);
        ml[l[i]] = mr[r[i]] = i;
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
        int s1 = x - l[i];
        auto it1 = mr.find(s1);
        if (it1 != mr.end()) ans = min(ans, i + 1 + it1->second + 1);
        int s2 = x - r[i];
        auto it2 = ml.find(s2);
        if (it2 != ml.end()) ans = min(ans, i + 1 + it2->second + 1);      
        }
        return ans > n ? -1 : ans;
    }
};


class Solution {
public:
    // Author: Huahua
    // Solution2: Sliding Window
    // Find the longest sliding window whose sum of elements equals sum(nums) – x
    // ans = n – window_size
    // 
    // Time complexity: O(n)
    // Space complexity: O(1)
    int minOperations(vector<int>& nums, int x) {
        const int n = nums.size();
        int target = accumulate(begin(nums), end(nums), 0) - x;    
        int ans = INT_MAX;
        for (int s = 0, l = 0, r = 0; r < n; ++r) {
        s += nums[r];
        while (s > target && l <= r) s -= nums[l++];
        if (s == target) ans = min(ans, n - (r - l + 1));
        }
        return ans > n ? -1 : ans;
    }
};


// @lc code=end

