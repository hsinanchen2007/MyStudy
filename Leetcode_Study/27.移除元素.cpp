/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

/*

https://leetcode.cn/problems/remove-element/

27. 移除元素
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。


说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
int len = removeElement(nums, val);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
 

示例 1：

输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2]
解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。
例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。

示例 2：

输入：nums = [0,1,2,2,3,0,4,2], val = 2
输出：5, nums = [0,1,4,0,3]
解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。注意这五个元素可为任意顺序。
你不需要考虑数组中超出新长度后面的元素。
 

提示：

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
通过次数721,208提交次数1,212,986

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.2, very similar to LC 283
    // nums = {0, 2, 3, 4, 5, 5, 2, 2}, val = 2
    // answer = {0, 3, 4, 5, 5}, return 5
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                // assign not val's values to current index
                nums[index] = nums[i];
                // after assigning value, move index to next
                index++;
            }
        }
        // note that in the nums, we still have such values
        // {0, 3, 4, 5, 5, 2, 2}, return size 5, so we know
        // if we print out the elements in this nums, we will
        // only print {0, 3, 4, 5, 5}, no 2 there
        // this matches the required condition (same order) 
        // and valid size of this question, there is no need
        // to overwrite the rest values in nums
        return index;
    }
};


class Solution99 {
public:
    // 2022.6.2, from Leetcode 題目詳解, lvyilong316@163.com
    // use C++ STL, return distance as number of valid size, and use remove 
    // to remove the specified value from nums
    int removeElement(vector<int>& nums, int val) {
        return std::distance(nums.begin(), std::remove(nums.begin(), nums.end(), val));
    }
};


class Solution98 {
public:
    // 2022.6.4, from AcWing https://www.acwing.com/video/1349/
    // very similar to LC 26 as well
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};


class Solution97 {
public:
    // 2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/remove-element.cpp
    // Time:  O(n)
    // Space: O(1)
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] != val) {
                ++left;
            } else {
                swap(nums[left],  nums[--right]);
            }
        }
        return right;
    }
};


class Solution96 {
public:
    // 2022.7.24, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.md
    /*
       本题B站视频讲解
      
       有的同学可能说了，多余的元素，删掉不就得了。
      
       要知道数组的元素在内存地址中是连续的，不能单独删除数组中的某个元素，只能覆盖。
      
       数组的基础知识可以看这里程序员算法面试中，必须掌握的数组理论知识。
      
       暴力解法
       这个题目暴力的解法就是两层for循环，一个for循环遍历数组元素 ，第二个for循环更新数组。
      
       删除过程如下：
      
       27.移除元素-暴力解法
      
       很明显暴力解法的时间复杂度是O(n^2)，这道题目暴力解法在leetcode上是可以过的。
      
    */
    // 代码如下：
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(1)
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
                size--; // 此时数组的大小-1
            }
        }
        return size;

    }
};


class Solution95 {
public:
    // 2022.7.24, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.md
    /*
       双指针法
       时间复杂度：O(n)
       空间复杂度：O(1)
       
       双指针法（快慢指针法）： 通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。

       定义快慢指针
      
       快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组
       慢指针：指向更新 新数组下标的位置
       很多同学这道题目做的很懵，就是不理解 快慢指针究竟都是什么含义，所以一定要明确含义，后面的思路就更容易理解了。
      
       删除过程如下：
      
       27.移除元素-双指针法
      
       很多同学不了解
      
       双指针法（快慢指针法）在数组和链表的操作中是非常常见的，很多考察数组、链表、字符串等操作的面试题，都使用双指针法。
       后续都会一一介绍到，本题代码如下：
    */
    //
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};


class Solution94 {
public:
    // 2022.7.24, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.md
    /*
       相向双指针方法，基于元素顺序可以改变的题目描述改变了元素相对位置，确保了移动最少元素
       时间复杂度：O(n)
       空间复杂度：O(1)
    
       相关题目推荐
       26.删除排序数组中的重复项
       283.移动零
       844.比较含退格的字符串
       977.有序数组的平方
    */
    //
    int removeElement(vector<int>& nums, int val) {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        while (leftIndex <= rightIndex) {
            // 找左边等于val的元素
            while (leftIndex <= rightIndex && nums[leftIndex] != val){
                ++leftIndex;
            }
            // 找右边不等于val的元素
            while (leftIndex <= rightIndex && nums[rightIndex] == val) {
                -- rightIndex;
            }
            // 将右边不等于val的元素覆盖左边等于val的元素
            if (leftIndex < rightIndex) {
                nums[leftIndex++] = nums[rightIndex--];
            }
        }
        return leftIndex;   // leftIndex一定指向了最终数组末尾的下一个元素
    }
};


class Solution93 {
public:
    // 2022.7.28, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/27.%20Remove%20Element
    // OJ: https://leetcode.com/problems/remove-element/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    int removeElement(vector<int>& A, int val) {
        int j = 0, N = A.size();
        for (int i = 0; i < N; ++i) {
            if (A[i] != val) A[j++] = A[i];
        }
        return j;
    }
};


class Solution92 {
public:
    // 2022.7.28, from https://walkccc.me/LeetCode/problems/0027/
    int removeElement(vector<int>& nums, int val) {
        int i = 0;

        for (const int num : nums)
        if (num != val)
            nums[i++] = num;

        return i;
    }
};


class Solution91 {
public:
    // 2022.7.28, from https://github.com/MaskRay/LeetCode/blob/master/remove-element.cc
    int removeElement(vector<int> &a, int val) {
        int i = 0, j = 0;
        for (; i < a.size(); i++)
        if (a[i] != val)
            a[j++] = a[i];
        return j;
    }
};


class Solution {
public:
    // 2022.7.28, from https://github.com/grandyang/leetcode/issues/27
    /*
        这道题让我们移除一个数组中和给定值相同的数字，并返回新的数组的长度。是一道比较容易的题，只需要一个变量用来计数，
        然后遍历原数组，如果当前的值和给定值不同，就把当前值覆盖计数变量的位置，并将计数变量加1。代码如下：
    */
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) nums[res++] = nums[i];
        }
        return res;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// 2022.8.15, not in top list

// @lc code=end

