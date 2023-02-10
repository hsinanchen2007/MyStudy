/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

/*

https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/

80. 删除有序数组中的重复项 II

中等
760
company
字节跳动
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

说明：

为什么返回数值是整数，但输出的答案是数组呢？

请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

示例 1：

输入：nums = [1,1,1,2,2,3]
输出：5, nums = [1,1,2,2,3]
解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。 不需要考虑数组中超出新长度后面的元素。

示例 2：

输入：nums = [0,0,1,1,1,1,2,3,3]
输出：7, nums = [0,0,1,1,2,3,3]
解释：函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。 不需要考虑数组中超出新长度后面的元素。 

提示：

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums 已按升序排列

*/

// @lc code=start
class Solution100 {
public:
    // 2023.2.2, from https://walkccc.me/LeetCode/problems/0080/
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();

        int i = 0;
        for (const int num : nums)
            if (i < 2 || num > nums[i - 2])
                nums[i++] = num;

        return i;
    }
};


class Solution99 {
public:
    // 2023.2.9, from https://www.acwing.com/activity/content/code/content/370453/
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (auto x: nums)
            if (k < 2 || (nums[k - 1] != x || nums[k - 2] != x))
                nums[k ++ ] = x;
        return k;
    }
};


class Solution98 {
public:
    // 2023.2.9, from https://github.com/grandyang/leetcode/issues/80
    /*
        这道题是之前那道 Remove Duplicates from Sorted Array 的拓展，这里允许最多重复的次数是两次，那么可以用一个变量 
        cnt 来记录还允许有几次重复，cnt 初始化为1，如果出现过一次重复，则 cnt 递减1，那么下次再出现重复，快指针直接前进
        一步，如果这时候不是重复的，则 cnt 恢复1，由于整个数组是有序的，所以一旦出现不重复的数，则一定比这个数大，此数之
        后不会再有重复项。理清了上面的思路，则代码很好写了：    
    */
    int removeDuplicates(vector<int>& nums) {
        int pre = 0, cur = 1, cnt = 1, n = nums.size();
        while (cur < n) {
            if (nums[pre] == nums[cur] && cnt == 0) ++cur;
            else {
                if (nums[pre] == nums[cur]) --cnt;
                else cnt = 1;
                nums[++pre] = nums[cur++];
            }
        }
        return nums.empty() ? 0 : pre + 1;
    }
};


class Solution97 {
public:
    // 2023.2.9, from https://github.com/grandyang/leetcode/issues/80
    /*
        这里其实也可以用类似于 Remove Duplicates from Sorted Array 中的解法三的模版，由于这里最多允许两次重复，那么当前的
        数字 num 只要跟上上个覆盖位置的数字 nusm[i-2] 比较，若 num 较大，则绝不会出现第三个重复数字（前提是数组是有序的），
        这样的话根本不需要管 nums[i-1] 是否重复，只要将重复个数控制在2个以内就可以了，参见代码如下：    
    */
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int num : nums) {
            if (i < 2 || num > nums[i - 2]) {
                nums[i++] = num;
            }
        }
        return i;
    }
};


class Solution96 {
public:
    // 2023.2.9, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/remove-duplicates-from-sorted-array-ii.cpp
    // Time:  O(n)
    // Space: O(1)
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        const int k = 2; // At most k duplicated.

        int left = 0;
        int right = 1;

        while (right < nums.size()) {
            if (nums[left] != nums[right] ||
                (left - k + 1 < 0 || nums[left] != nums[left - k + 1])) {
                ++left;
                nums[left] = nums[right];
            }
            ++right;
        }

        return left + 1; 
    }
};


class Solution95 {
public:
    // OJ: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    int removeDuplicates(vector<int>& A) {
        int j = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (j - 2 < 0 || A[j - 2] != A[i]) A[j++] = A[i];
        }
        return j;
    }
};


class Solution94 {
public:
    // 2023.2.9, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/080.Remove-Duplicates-from-Sorted-Array-II/80.Remove%20Duplicates%20from%20Sorted%20Array%20II.cpp
    /*
        080.Remove-Duplicates-from-Sorted-Array-II
        要实现in-place的功能，利用快慢指针。right指针判定合格的，就拷贝到left指针上去。

        注意：初始值left=1，right=2。保证有不超过两个重复的判断条件是

        if (nums[right]==nums[left] && nums[right]==nums[left-1])
            right++;
        else
        {
            left++;
            nums[left]=nums[right];
            right++;
        }
        分析：因为所有合格的元素都已经移到了左指针上，所以每次考察右指针的新元素时，需要和左指针进行比较。    
    */
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.size()==0) return 0;
        if (nums.size()==1) return 1;
        
        int i=1;
        for (int j=0; j<nums.size(); j++)
        {
            if (j==0 || j==1) 
                continue;
            else if (nums[j]==nums[i] && nums[j]==nums[i-1])
                continue;
            else
            {
                i++;
                nums[i]=nums[j];
            }
        }
        
        return i+1;
        
    }
};


class Solution93 {
public:
    // 2023.2.9, from https://github.com/azl397985856/leetcode/blob/master/problems/80.remove-duplicates-from-sorted-array-ii.md
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int k = 2;
        for (int num : nums) {
            if (i < k || num != nums[i - k]) {
                nums[i] = num;
                i++;
            }
        }
        return i;
    }
};


class Solution {
public:
    // 2023.2.9, from https://zxi.mytechroad.com/blog/?s=LeetCode+80.
    // Author: Huahua
    // Time complexity: O(n)
    // Space complexity: O(1)
    int removeDuplicates(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 2) return n;
    
        int index = 1;
        int len = 1;
        int last = nums[0];
    
        while (index < n) {
            int count = 1;
            while (index < n && nums[index] == last) {
                ++count;
                ++index;
            }
    
            if (count >= 2) nums[len++] = last;        
    
            if (index < n) {
                last = nums[index++];
                nums[len++] = last;
            }
        }
    
        return len;
    }
};


// @lc code=end

