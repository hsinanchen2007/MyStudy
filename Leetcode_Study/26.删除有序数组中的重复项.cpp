/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

/*

https://leetcode.cn/problems/remove-duplicates-from-sorted-array/

26. 删除有序数组中的重复项
给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
元素的 相对顺序 应该保持 一致 。

由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。更规范地说，如果在删除重复项之后有 
k 个元素，那么 nums 的前 k 个元素应该保存最终结果。

将最终结果插入 nums 的前 k 个位置后返回 k 。

不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

判题标准:

系统会用下面的代码来测试你的题解:

int[] nums = [...]; // 输入数组
int[] expectedNums = [...]; // 长度正确的期望答案

int k = removeDuplicates(nums); // 调用

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
如果所有断言都通过，那么您的题解将被 通过。
 

示例 1：

输入：nums = [1,1,2]
输出：2, nums = [1,2,_]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。

示例 2：

输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]
解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。
 

提示：

0 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums 已按 升序 排列
通过次数1,133,649提交次数2,094,788

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.1, from LG solution
    int removeDuplicates(vector<int>& nums) {
        int target = 0;
        for (int i = 1; i < nums.size(); i++) {
            // target starts from 0, i starts from 1
            // if they are not same, assign number if ++target != i
            // otherwise i++ to next one if they are same
            if (nums[target] != nums[i]) {
                // tricky here, ++target, not target++
                // perform ++ first and check if it is same as i or not
                // actually even if we still assign the number, it is OK
                if (++target != i) {
                    nums[target] = nums[i];
                }
            }
        }
        return (target + 1);
    }
};


class Solution99 {
public:
    // 2022.6.4, from AcWing https://www.acwing.com/video/1348/
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            // example {1, 2, 2, 2, 3, 4, 5}
            //   i = 0, nums[0] = nums[0], k = 1
            //   i = 1, nums[1] = nums[1], k = 2;
            //   i = 2, nums[2] and nums[1] are same, skip
            //   i = 3, nums[3] and nums[2] are same, skip
            //   i = 4, nums[2] = nums[4], k = 3
            //   i = 5, nums[3] = nums[5], k = 4
            //   i = 6, nums[4] = nums[6], k = 5
            // return 5
            // tricky is below if condition
            if (!i || nums[i] != nums[i - 1]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};


class Solution98 {
public:
    // 2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/remove-duplicates-from-sorted-array.cpp
    // Time:  O(n)
    // Space: O(1)
    int removeDuplicates(vector<int>& nums) {
        int last = -1;
        for (const auto& num : nums) {
            if (last == -1 || nums[last] != num) {
                nums[++last] = num;
            }
        }
        return last + 1;
    }
    
};


class Solution97 {
public:
    // 2022.7.28, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/26.%20Remove%20Duplicates%20from%20Sorted%20Array
    // OJ: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    int removeDuplicates(vector<int>& A) {
        int j = 0;
        for (int n : A) {
            if (j - 1 < 0 || A[j - 1] != n) A[j++] = n;
        }
        return j;
    }
};


class Solution96 {
public:
    // 2022.7.28, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/26.%20Remove%20Duplicates%20from%20Sorted%20Array
    // OJ: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    int removeDuplicates(vector<int>& A) {
        int i = 0, j = 0, N = A.size();
        while (i < N) {
            A[j++] = A[i++];
            while (i < N && A[i] == A[i - 1]) ++i;
        }
        return j;
    }
};


class Solution95 {
public:
    // 2022.7.28, from https://walkccc.me/LeetCode/problems/0026/
    // Time: O(n)
    // Space: O(1)
    int removeDuplicates(vector<int>& nums) {
        int i = 0;

        for (const int num : nums)
        if (i < 1 || num > nums[i - 1])
            nums[i++] = num;

        return i;
    }
};


class Solution94 {
public:
    // 2022.7.28, from https://www.guozet.me/leetcode/Leetcode-26-Remove-Duplicates-From-Sorted-Array.html?h=removedupli
    int removeDuplicates(vector<int>& nums) { return distance(nums.begin(), unique(nums.begin(), nums.end())); }
};


class Solution93 {
public:
    // 2022.7.28, from https://www.guozet.me/leetcode/Leetcode-26-Remove-Duplicates-From-Sorted-Array.html?h=removedupli
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int index = 0;
        for (int i = 0; i < nums.size(); ++i) {
        if (nums[index] != nums[i])
            nums[++index] = nums[i];
        }
        return index + 1;
    }
};


class Solution92 {
public:
    // 2022.7.28, from https://github.com/grandyang/leetcode/issues/26
    /*
        这道题要我们从有序数组中去除重复项，和之前那道 Remove Duplicates from Sorted List 的题很类似，
        但是要简单一些，因为毕竟数组的值可以通过下标直接访问，而链表不行。那么这道题的解题思路是使用快慢指针
        来记录遍历的坐标，最开始时两个指针都指向第一个数字，如果两个指针指的数字相同，则快指针向前走一步，
        如果不同，则两个指针都向前走一步，这样当快指针走完整个数组后，慢指针当前的坐标加1就是数组中不同数字
        的个数，代码如下：

        解法一：
    */
    int removeDuplicates(vector<int>& nums) {
        int pre = 0, cur = 0, n = nums.size();
        while (cur < n) {
            if (nums[pre] == nums[cur]) ++cur;
            else nums[++pre] = nums[cur++];
        }
        return nums.empty() ? 0 : (pre + 1);
    }
};


class Solution91 {
public:
    // 2022.7.28, from https://github.com/grandyang/leetcode/issues/26
    /*
        我们也可以用 for 循环来写，这里的j就是上面解法中的 pre，i就是 cur，所以本质上都是一样的，参见代码如下：

        解法二：
    */
    int removeDuplicates(vector<int>& nums) {
        int j = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != nums[j]) nums[++j] = nums[i];
        }
        return nums.empty() ? 0 : (j + 1);
    }
};


class Solution {
public:
    // 2022.7.28, from https://github.com/grandyang/leetcode/issues/26
    /*
        这里也可以换一种写法，用变量i表示当前覆盖到到位置，由于不能有重复数字，则只需要用当前数字 num 跟上一个
        覆盖到到数字 nums[i-1] 做个比较，只要 num 大，则一定不会有重复（前提是数组必须有序），参见代码如下：

        解法三：
    */
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int num : nums) {
            if (i < 1 || num > nums[i - 1]) {
                nums[i++] = num;
            }
        }
        return i;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

