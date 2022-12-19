/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

/*

https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/

167. 两数之和 II - 输入有序数组
给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和
等于目标数 target 的两个数。如果设这两个数分别是 
numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。

以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。

你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。

你所设计的解决方案必须只使用常量级的额外空间。

 
示例 1：

输入：numbers = [2,7,11,15], target = 9
输出：[1,2]
解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。

示例 2：

输入：numbers = [2,3,4], target = 6
输出：[1,3]
解释：2 与 4 之和等于目标数 6 。因此 index1 = 1, index2 = 3 。返回 [1, 3] 。

示例 3：

输入：numbers = [-1,0], target = -1
输出：[1,2]
解释：-1 与 0 之和等于目标数 -1 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
 

提示：

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers 按 非递减顺序 排列
-1000 <= target <= 1000
仅存在一个有效答案
通过次数443,728提交次数756,637

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.17, by Hsinan. Use two pointers as this is an already sorted array
    // Compared with LC 1, we can use two pointers from front and back to check the
    // sum value, increase front is too small, reduce back if too large
    vector<int> twoSum(vector<int>& numbers, int target) {
        // define answer vector to return 
        vector<int> answer;

        // sanity check for invalid given vector or only two elements
        if (numbers.size() < 2) return answer;
        if (numbers.size() == 2 && numbers[0] + numbers[1] == target) {
            answer.push_back(1);
            answer.push_back(2);
            return answer;
        }

        // define two pointers
        int front = 0;
        int back = numbers.size() - 1;

        // while front < back pointer condition
        while (front < back) {
            if (numbers[front] + numbers[back] > target) {
                // back is too big, reduce
                back--;
                continue;
            } else if (numbers[front] + numbers[back] < target) {
                // front is too small, increase
                front++;
                continue;
            } if (numbers[front] + numbers[back] == target) {
                // find answer, plus index and return
                answer.push_back(front + 1);
                answer.push_back(back + 1);
                return answer;
            }
        }

        // if here, no answer
        return answer;
    }
};


class Solution99 {
public:
    // 2022.6.17, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/two-sum-ii-input-array-is-sorted.cpp
    // Time:  O(n)
    // Space: O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while (left != right) {
            const auto sum = numbers[left] + numbers[right];
            if (sum > target) {
                --right;
            } else if (sum < target) {
                ++left;
            } else {
                return {left + 1, right + 1};
            }
        }

        return {0, 0};
    }
};


class Solution98 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/blob/master/leetcode/167.%20Two%20Sum%20II%20-%20Input%20array%20is%20sorted/s1.cpp
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] > target) --j;
            else if (nums[i] + nums[j] < target) ++i;
            else return { i + 1, j + 1 };
        }
        return {};
    }
};


class Solution97 {
public:
    // 2022.7.25, from https://walkccc.me/LeetCode/problems/0167/
    // Time: O(n)
    // Space: O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        while (numbers[l] + numbers[r] != target)
        if (numbers[l] + numbers[r] < target)
            ++l;
        else
            --r;

        return {l + 1, r + 1};
    }
};


class Solution96 {
public:
    // 2022.7.25, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/two-sum-ii-input-array-is-sorted.cpp
    // Time:  O(n)
    // Space: O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while (left != right) {
            const auto sum = numbers[left] + numbers[right];
            if (sum > target) {
                --right;
            } else if (sum < target) {
                ++left;
            } else {
                return {left + 1, right + 1};
            }
        }

        return {0, 0};
    }
};


class Solution95 {
public:
    // 2022.6.17, from AcWing https://www.acwing.com/video/1545/
    vector<int> twoSum(vector<int>& numbers, int target) {
        // below for condition is a trick from AcWing code
        for (int i = 0, j = numbers.size() - 1; i < j; i++) {
            while (i < j && numbers[i] + numbers[j] > target) j--;
            if (numbers[i] + numbers[j] == target) return {i + 1, j + 1};
        }
        return {};
    }
};


class Solution94 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/167
    /*
        这又是一道Two Sum的衍生题，作为LeetCode开山之题，我们务必要把Two Sum及其所有的衍生题都拿下，
        这道题其实应该更容易一些，因为给定的数组是有序的，而且题目中限定了一定会有解，我最开始想到的方法是
        二分法来搜索，因为一定有解，而且数组是有序的，那么第一个数字肯定要小于目标值target，那么我们每次
        用二分法来搜索target - numbers[i]即可，代码如下：

        解法一：
    */
    // O(nlgn)
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int t = target - numbers[i], left = i + 1, right = numbers.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] == t) return {i + 1, mid + 1};
                else if (numbers[mid] < t) left = mid + 1;
                else right = mid;
            }
        }
        return {};
    }
};


class Solution {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/167
    /*
        但是上面那种方法并不efficient，时间复杂度是O(nlgn)，我们再来看一种O(n)的解法，我们只需要两个指针，
        一个指向开头，一个指向末尾，然后向中间遍历，如果指向的两个数相加正好等于target的话，直接返回两个指针
        的位置即可，若小于target，左指针右移一位，若大于target，右指针左移一位，以此类推直至两个指针相遇停止，
        参见代码如下：

        解法二：
    */
    // O(n)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) return {l + 1, r + 1};
            else if (sum < target) ++l;
            else --r;
        }
        return {};
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// 2022.8.15, not in top list

// @lc code=end

