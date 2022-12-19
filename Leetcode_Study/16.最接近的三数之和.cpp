/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

/* 

https://leetcode.cn/problems/3sum-closest/

16. 最接近的三数之和
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。
 

示例 1：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。

示例 2：

输入：nums = [0,0,0], target = 1
输出：0
 

提示：

3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104
通过次数361,677提交次数793,387

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.12, from AcWing https://www.acwing.com/video/1333/
    int threeSumClosest(vector<int>& nums, int target) {
        // sort the given vector so we can use two pointers
        sort(nums.begin(), nums.end());

        // we want to save the smallest diff within res to return
        std::pair<int, int> res(INT_MAX, INT_MAX);

        // first iteration for i
        for (int i = 0; i < nums.size(); i++) {
            // second iteration for j and k
            // again, j starts from (i + 1)
            // again, k starts from (nums.size() -1)
            for (int j = i + 1, k = nums.size() - 1; j < k; j++) {
                while (k - 1 > j && nums[i] + nums[j] + nums[k - 1] >= target) k--;

                // check current sum
                int sum = nums[i] + nums[j] + nums[k];

                // the answer is asking the sum of closest one, not diff
                // so below one's first will be its diff, and second will be sum
                // compare the initial res and get the smallest diff from pair
                res = std::min(res, std::make_pair(std::abs(sum - target), sum));

                // here, target is larger than sum
                if (k - 1 > j) {
                    sum = nums[i] + nums[j] + nums[k - 1];
                    res = std::min(res, std::make_pair(std::abs(target - sum), sum));
                }
            }
        }

        return res.second;
    }
};


class Solution99 {
public:
    // 2022.6.12, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/3sum-closest.cpp
    // Time:  O(n^2)
    // Space: O(1)
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int result = 0, min_diff = numeric_limits<int>::max();
        for (int i = size(nums) - 1; i >= 2; --i) {
            if (i + 1 < size(nums) && nums[i] == nums[i + 1]) {
                continue;
            }
            int left = 0, right = i - 1;
            while (left < right) {
                const auto& total = nums[left] + nums[right] + nums[i];
                if (total < target) {
                    ++left;
                } else if (total > target) {
                    --right;
                } else {
                    return target;
                }
                if (abs(total - target) < min_diff) {
                    min_diff = abs(total - target);
                    result = total;
                }
            }
        }
        return result;
    }
};


class Solution98 {
public:
    // 2022.6.12, from https://www.guozet.me/leetcode/Leetcode-16-3Sum-Closest.html
    // the solution is better and easier to understand
    int threeSumClosest(vector<int>& nums, int target) {
        // initialize a closest value from first three elements
        int closest = nums[0] + nums[1] + nums[2];

        // initialize a diff based on closest and target 
        int diff = std::abs(closest - target);

        // sort the given vector so we can use two pointers
        sort(nums.begin(), nums.end());

        // iterate all elements
        for (int i = 0; i < nums.size() -2; i++) {
            // define two pointers
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                // get current sum and diff
                int sum = nums[i] + nums[left] + nums[right];
                int newDiff = std::abs(sum - target);

                // update sum and diff if needed
                if (newDiff < diff) {
                    diff = newDiff;
                    closest = sum;
                }

                // otherwise next one
                if (sum < target) { 
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closest;
    }
};


class Solution97 {
public:
    // 2022.6.14, from https://ke.algomooc.com/detail/v_626e73e2e4b01a4851f98e6f/3?from=p_6243bcc1e4b04e8d90291891&type=8&parent_pro_id=p_6268b1aae4b01c509aa8e2b8
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 最接近的三数之和(16)：https://leetcode-cn.com/problems/3sum-closest/submissions/
    int threeSumClosest(vector<int>& nums, int target) {
        // 题目假定每组输入只存在恰好一个解，所以不需要处理边界情况
        int ans = nums[0] + nums[1] + nums[2];

        // 先将数组进行排序操作，从小到大
        sort(nums.begin(), nums.end());

        // 开始遍历整个数组
        // 在遍历的过程中，观察设置的三个位置的元素之后的大小
        // num[i] 为从左到右观察过去的元素
        // left 为从 i 到 len - 1 的元素
        // right 为从 len - 1 向左移动到 i 的元素
        for (int i = 0; i < nums.size() ; i++) {

            // left 为从 i 到 len - 1 的元素，向右移动
            int left = i + 1;

            // right 为从 len - 1 向左移动到 i 的元素，向左移动
            int right = nums.size() - 1;

            // left 和 right 不断的向内移动
            while (left < right) {
                
                // 计算这三者之和
                int sum = nums[i] + nums[left] + nums[right];

                // 寻找出更接近于 target 的那个和
                if (abs(target - sum) < abs(target - ans)) {
                     ans = sum;
                }
                   
                // 如果三者之和小于 target ，那么说明需要找更大的数
                if (sum < target) {
                    // left 向右移动
                    left++;

                // 如果三者之和大于 target ，那么说明需要找更小的数
                } else if (sum > target) {
                    // right 向左移动
                    right--;
                } else {
                    return ans;
                }
            }
        }     
        // 返回结果   
        return ans;
    }


    /*
        // 2022.6.17, from https://www.guozet.me/leetcode/Leetcode-Interview-Amazon-OA2-2Sum-Closest.html
        // Looks like Amazon interview question

        // 2Sum Closest
        int twoSumClosest(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            int diff = INT_MAX, res;
            int i = 0, j = nums.size() - 1;
            while (i < j) {
                int sum = nums[i] + nums[j];
                if (abs(sum - target) < diff) {
                res = sum;
                diff = abs(sum - target);
                }
                if (sum < target)
                i++;
                else if (sum > target)
                j--;
                else
                break;
            }
            return res;
        }

    */
};


class Solution96 {
public:
    // 2022.7.28, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/16.%203Sum%20Closest
    // OJ: https://leetcode.com/problems/3sum-closest/
    // Author: github.com/lzl124631x
    // Time: O(N^2)
    // Space: O(1)
    int threeSumClosest(vector<int>& A, int target) {
        sort(begin(A), end(A));
        int N = A.size(), ans = A[0] + A[1] + A[2];
        for (int i = 0; i < N - 2; ++i) {
            int L = i + 1, R = N - 1;
            while (L < R) {
                long sum = A[L] + A[R] + A[i];
                if (abs(sum - target) < abs(ans - target)) ans = sum;
                if (sum == target) return target;
                if (sum > target) --R;
                else ++L;
            }
        }
        return ans;
    }
};


class Solution95 {
public:
    // 2022.7.28, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/016.3Sum-Closest/16.3Sum_Closest.cpp
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        
        int temp = INT_MAX;
        int result;
        
        for (int a=0; a<nums.size(); a++)
        {
            int left = a+1;
            int right = nums.size()-1;
            int sum = target - nums[a];
            
            while (left<right)
            {
                if (temp > abs(nums[left]+nums[right]-sum))
                {
                    temp = abs(nums[left]+nums[right]-sum);
                    result = nums[a]+nums[left]+nums[right];
                }
                if (nums[left]+nums[right]==sum)
                    return target;
                else if (nums[left]+nums[right]>sum)
                    right--;
                else if (nums[left]+nums[right]<sum)    
                    left++;
            }
            
        }
        
        return result;
        
    }
};


class Solution94 {
public:
    // 2022.7.28, from https://walkccc.me/LeetCode/problems/0016/
    // Time: O(n^2)
    // Space: O(∣ans∣)
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];

        sort(begin(nums), end(nums));

        for (int i = 0; i + 2 < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        // choose nums[i] as the first num in the triplet,
        // and search the remaining nums in [i + 1, n - 1]
        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r) {
            const int sum = nums[i] + nums[l] + nums[r];
            if (sum == target)
            return sum;
            if (abs(sum - target) < abs(ans - target))
            ans = sum;
            if (sum < target)
            ++l;
            else
            --r;
        }
        }

        return ans;
    }
};


class Solution93 {
public:
    // 2022.7.28, from https://github.com/grandyang/leetcode/issues/16
    /*
        这道题让我们求最接近给定值的三数之和，是在之前那道 3Sum 的基础上又增加了些许难度，那么这道题让返回这个
        最接近于给定值的值，即要保证当前三数和跟给定值之间的差的绝对值最小，所以需要定义一个变量 diff 用来记录
        差的绝对值，然后还是要先将数组排个序，然后开始遍历数组，思路跟那道三数之和很相似，都是先确定一个数，然后
        用两个指针 left 和 right 来滑动寻找另外两个数，每确定两个数，求出此三数之和，然后算和给定值的差的绝对
        值存在 newDiff 中，然后和 diff 比较并更新 diff 和结果 closest 即可，代码如下：

        解法一：
    */
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        int diff = abs(closest - target);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int newDiff = abs(sum - target);
                if (diff > newDiff) {
                    diff = newDiff;
                    closest = sum;
                }
                if (sum < target) ++left;
                else --right;
            }
        }
        return closest;
    }
};


class Solution {
public:
    // 2022.7.28, from https://github.com/grandyang/leetcode/issues/16
    /*
        我们还可以稍稍进行一下优化，每次判断一下，当 nums[i]*3 > target 的时候，就可以直接比较 closest 
        和 nums[i] + nums[i+1] + nums[i+2] 的值，返回较小的那个，因为数组已经排过序了，后面的数字只会
        越来越大，就不必再往后比较了，参见代码如下：

        解法二：
    */
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        int diff = abs(closest - target);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            // Note, original code has a bug here
            if (nums[i] * 3 > target) {
                int total = nums[i] + nums[i + 1] + nums[i + 2];
                if (abs(total-target) < diff) { 
                    return total;
                } else {
                    return closest;
                }
            }
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int newDiff = abs(sum - target);
                if (diff > newDiff) {
                    diff = newDiff;
                    closest = sum;
                }
                if (sum < target) ++left;
                else --right;
            }
        }
        return closest;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// 2022.8.15, not in top list

// @lc code=end

