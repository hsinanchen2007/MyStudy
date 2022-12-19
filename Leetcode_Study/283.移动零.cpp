/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

/*

https://leetcode.cn/problems/move-zeroes/

283. 移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。


示例 1:

输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]

示例 2:

输入: nums = [0]
输出: [0]
 

提示:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

进阶：你能尽量减少完成的操作次数吗？

通过次数768,285提交次数1,200,598

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.2, from 极客时间覃超算法训练營, very similar to LC 27
    void moveZeroes(vector<int>& nums) {
        int target = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[target] = nums[i];
                // if target and i is same, for example {1}, 
                // no need to assign 0 in nums
                if (target != i) {
                    nums[i] = 0;
                }
                // move to next target
                target++;
            }
        }
    }
};


class Solution99 {
public:
    // learned from LC 27 solution, use C++ STL
    // nums = {0, 0, 1, 2, 3, 0, 0, 4, 5}, answer = {1, 2, 3, 4, 5, 0, 0, 0, 0}
    void moveZeroes(vector<int>& nums) {
        // get original nums size
        int size = nums.size();

        // note that std::remove returns the number of valid elements
        // which means it will not count the value (0 here) 
        int distance = std::distance(nums.begin(), std::remove(nums.begin(), nums.end(), 0));

        // for this LC question, it needed to remain its original size
        for (int i = 0; i < size-distance; i++) {
            nums[size- 1 - i] = 0;
        }
    }
};


class Solution98 {
public:
    // 2022.6.5, from AcWing https://www.acwing.com/video/1657/
    // this one is similar to LC 26 and LC 27
    void moveZeroes(vector<int>& nums) {
        int k = 0;

        // use below to get value directly
        for (auto i : nums) {
            if (i != 0) nums[k++] = i;
        }

        // assign 0 to rest elements
        while (k < nums.size()) nums[k++] = 0;
    }
};


class Solution97 {
public:
    // 2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/move-zeroes.cpp
    // Time:  O(n)
    // Space: O(1)
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (auto& num : nums) {
            if (num) {
                swap(nums[pos++], num);
            }
        }
    }
};


class Solution96 {
public:
    // 2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/move-zeroes.cpp
    // Time:  O(n)
    // Space: O(1)
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (const auto& num : nums) {
            if (num) {
                nums[pos++] = num;
            }
        }
        fill(next(nums.begin(), pos), nums.end(), 0);
    }
};


class Solution95 {
public:
    // 2022.7.27, from https://ke.algomooc.com/detail/v_62c2fa52e4b0eca59c11dac6/3?from=p_6243bcc1e4b04e8d90291891&type=8&parent_pro_id=p_62c2fa48e4b00a4f37220114
    void moveZeroes(vector<int>& nums) {
        // 设置一个变量，用来指向经过一系列操作后数组中所有为 0 元素的第一个位置上
        // 一开始默认在索引为 0 的位置
        int slow = 0;

        // 从头到尾遍历数组
        // 遍历完毕之后，slow 指向了一个为 0 的元素，或者如果数组中不存在 0 ，就和 fast 一样，超过了数组的范围
        for (int fast = 0; fast < nums.size(); fast++) {

            // 在遍历过程中，如果发现访问的元素是非 0 元素
            // 说明 slow 不在正确的位置上，需要向后移动，寻找合适的位置
            if (nums[fast] != 0) {

                // 这个时候，原先 slow 的值需要被 fast 的值覆盖
                nums[slow] = nums[fast];

                // slow 需要向后移动，寻找合适的位置
                slow++;

            }
        }

        // 接下来，只需要把 slow 极其后面所有的元素都设置为 0 就行
        for (int i = slow; i < nums.size(); i++) {

            // 都设置为 0 
            nums[i] = 0;

        }
    }
};


class Solution94 {
public:
    // 2022.7.27, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0283.%E7%A7%BB%E5%8A%A8%E9%9B%B6.md
    /*
        做这道题目之前，大家可以做一做27.移除元素

        这道题目，使用暴力的解法，可以两层for循环，模拟数组删除元素（也就是向前覆盖）的过程。
        好了，我们说一说双指针法，大家如果对双指针还不熟悉，可以看我的这篇总结双指针法：总结篇！。

        双指针法在数组移除元素中，可以达到O(n)的时间复杂度，在27.移除元素里已经详细讲解了，那么本题和移除
        元素其实是一个套路。相当于对整个数组移除元素0，然后slowIndex之后都是移除元素0的冗余元素，把这些
        元素都赋值为0就可以了。

        如动画所示：

        移动零

        C++代码如下：
    */
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != 0) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        // 将slowIndex之后的冗余元素赋值为0
        for (int i = slowIndex; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};


class Solution93 {
public:
    // 2022.7.27, from https://walkccc.me/LeetCode/problems/0283/
    // Time: O(n)
    // Space: O(1)
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (const int num : nums)
        if (num != 0)
            nums[i++] = num;

        while (i < nums.size())
        nums[i++] = 0;
    }
};


class Solution92 {
public:
    // 2022.7.27, from https://www.guozet.me/leetcode/Leetcode-283-Move-Zeroes.html?h=movezeroes
    /*
        把非零数前移，要求不能改变非零数的相对应的位置关系，而且不能拷贝额外的数组，那么只能用替换法in-place来做，
        需要用两个指针，一个不停的向后扫，找到非零位置，然后和前面那个指针交换位置即可，参见下面的代码：
    */
    // Time complexity: O(n), Space complexity: O(1)
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        for (; right < nums.size(); ++right) {
        // If nums[i] != 0, then we can swap with the first zero....
        // nums[j] is zero....
        if (nums[right] != 0) swap(nums[right], nums[left++]);
        }
    }
};


class Solution91 {
public:
    // 2022.7.27, from https://github.com/MaskRay/LeetCode/blob/master/move-zeroes.cc
    void moveZeroes(vector<int> &a) {
        int i = 0;
        for (auto x: a)
        if (x)
            a[i++] = x;
        fill(a.begin()+i, a.end(), 0);
    }
};


class Solution90 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/283
    /*
        这道题让我们将一个给定数组中所有的0都移到后面，把非零数前移，要求不能改变非零数的相对应的位置关系，
        而且不能拷贝额外的数组，那么只能用替换法in-place来做，需要用两个指针，一个不停的向后扫，找到非零位置，
        然后和前面那个指针交换位置即可，参见下面的代码：

        解法一：
    */
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                swap(nums[i], nums[j++]);
            }
        }
    }
};


class Solution {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/283
    /*
        下面这种解法的思路跟上面的没啥区别，写法稍稍复杂了一点。。

        解法二：
    */
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right]) {
                swap(nums[left++], nums[right]);
            }
            ++right;
        }
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

