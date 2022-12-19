/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

/*

https://leetcode.cn/problems/find-smallest-letter-greater-than-target/

744. 寻找比目标字母大的最小字母
给你一个排序后的字符列表 letters ，列表中只包含小写英文字母。另给出一个目标字母 target，请你寻找在这一有序列表里比目标字母大的最小字母。

在比较时，字母是依序循环出现的。举个例子：

如果目标字母 target = 'z' 并且字符列表为 letters = ['a', 'b']，则答案返回 'a'
 

示例 1：

输入: letters = ["c", "f", "j"]，target = "a"
输出: "c"

示例 2:

输入: letters = ["c","f","j"], target = "c"
输出: "f"

示例 3:

输入: letters = ["c","f","j"], target = "d"
输出: "f"
 

提示：

2 <= letters.length <= 104
letters[i] 是一个小写字母
letters 按非递减顺序排序
letters 最少包含两个不同的字母
target 是一个小写字母
通过次数91,201提交次数185,892

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.19, by Hsinan, use template first then adjust the code
    // refer CS-Notes/CyC2018
    // finalize with https://www.guozet.me/leetcode/Leetcode-744-Find-Smallest-Letter-Greater-Than-Target
    // Note that this question asked for the "NEXT" character of the target character in a sorted vector
    // so the consideration should be from left, not right, as once it existed while loop, right
    // pointer is actually at left pointer's left side, right pointer may actually point to target itself
    // but left pointer should be over target, which is the one "NEXT" we are looking for
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;

        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (letters[middle] > target) {
                right = middle - 1;
            } else if (letters[middle] < target) {
                left = middle + 1;
            } else {
                // if we do want to code with ""=="" condition here, need to update left
                // also, can NOT replace it with right! Why? "这一有序列表里比目标字母大的最小字母"
                // so if we do "right = middle -1", it may get the target character itself
                left = middle + 1;
            }
        }

        // refer from https://www.guozet.me/leetcode/Leetcode-744-Find-Smallest-Letter-Greater-Than-Target
        // so if the target is the last one, return letters[0] back
        int res = left % letters.size();

        return letters[res];
    }
};


class Solution99 {
public:
    // 2022.6.19, from https://www.guozet.me/leetcode/Leetcode-744-Find-Smallest-Letter-Greater-Than-Target
    // why should we do binary search?! This simply does what question asked for
    // Solution 1: Line Scan
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (const char c : letters)
            if (c > target) return c;
        return letters.front();
    }
};


class Solution98 {
public:
    // 2022.6.19, from https://www.guozet.me/leetcode/Leetcode-744-Find-Smallest-Letter-Greater-Than-Target
    // Binary Search Way
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size();
        while (left < right) {
            const int mid = left + (right - left) / 2;
            if (letters[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        int res = left % letters.size();
        return letters[res];
    }
};


class Solution97{
public:
    // 2022.6.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/find-smallest-letter-greater-than-target.cpp
    // Again, it reminds that "range" question and can use C++ STL's lower_bound/upper_bound on a sorted vector
    // Time:  O(logn)
    // Space: O(1)
    char nextGreatestLetter(vector<char>& letters, char target) {
        const auto cit = upper_bound(letters.cbegin(), letters.cend(), target);
        return cit != letters.cend() ? *cit : letters.front();
    }
};


class Solution96 {
public:
    // 2022.7.26, from https://www.guozet.me/leetcode/Leetcode-744-Find-Smallest-Letter-Greater-Than-Target#solution-1-line-scan
    // Solution 2: Binary Search
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size();
        while (left < right) {
        const int mid = left + (right - left) / 2;
        if (letters[mid] <= target)
            left = mid + 1;
        else
            right = mid;
        }
        int res = left % letters.size();
        return letters[res];
    }
};


class Solution95 {
public:
    // 2022.6.19, from AcWing https://www.acwing.com/video/2638/
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        while (left < right) {
            int middle = left + right >> 1;
            if (letters[middle] > target) right = middle;
            else left = middle + 1;
        }
        if (letters[right] > target) return letters[right];
        return letters[0];
    }
};


class Solution94 {
public:
    // 2022.7.26, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/744.%20Find%20Smallest%20Letter%20Greater%20Than%20Target
    // OJ: https://leetcode.com/problems/find-smallest-letter-greater-than-target/
    // Author: github.com/lzl124631x
    // Time: O(NlogN)
    // Space: O(1)
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto i = upper_bound(letters.begin(), letters.end(), target);
        return i == letters.end() ? letters[0] : *i;
    }
};


class Solution93 {
public:
    // 2022.7.26, from https://walkccc.me/LeetCode/problems/0744/
    // Time: O(logn)
    // Space: O(1)
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int r = letters.size();

        while (l < r) {
        const int m = (l + r) / 2;
        if (letters[m] > target)
            r = m;
        else
            l = m + 1;
        }

        return letters[l % letters.size()];
    }
};


class Solution92 {
public:
    // 2022.7.26, from https://github.com/grandyang/leetcode/issues/744
    /*
        这道题给了我们一堆有序的字母，然后又给了我们一个target字母，让我们求字母数组中第一个大于target的字母，数组是循环的，如果没有，
        那就返回第一个字母。像这种在有序数组中找数字，二分法简直不要太适合啊。题目中说了数组至少有两个元素，那么我们首先用数组的尾元素来
        跟target比较，如果target大于等于尾元素的话，直接返回数组的首元素即可。否则就利用二分法来做，这里是查找第一个大于目标值的数组，
        博主之前做过二分法的总结，参见这个帖子LeetCode Binary Search Summary 二分搜索法小结，参见代码如下：
    */
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (target >= letters.back()) return letters[0];
        int n = letters.size(), left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target) left = mid + 1;
            else right = mid;
        }
        return letters[right];
    }
};


class Solution {
public:
    // 2022.7.26, from https://github.com/grandyang/leetcode/issues/744
    /*
        我们也可以用STL自带的upper_bound函数来做，这个就是找第一个大于目标值的数字，如果返回end()，说明没找到，返回首元素即可，参见代码如下：
    */
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = upper_bound(letters.begin(), letters.end(), target);
        return it == letters.end() ? *letters.begin() : *it;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// 2022.8.15, not in top list

// @lc code=end

