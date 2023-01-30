/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

/*

https://leetcode.cn/problems/sort-an-array/

912. 排序数组

中等
765
company
微软 Microsoft
company
谷歌 Google
company
字节跳动
给你一个整数数组 nums，请你将该数组升序排列。

示例 1：

输入：nums = [5,2,3,1]
输出：[1,2,3,5]

示例 2：

输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5] 

提示：

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104

*/

// @lc code=start
class Solution100 {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size(), &nums);
        return nums;
    }
private:
    void mergeSort(int start, int end, vector<int> *nums) {
        if (end - start <= 1) {
            return;
        }
        const auto& mid = start + (end - start) / 2;
        mergeSort(start, mid, nums);
        mergeSort(mid, end, nums);
        vector<int> tmp;
        for (int left = start, right = mid; left < mid; ++left) {
            while (right < end && (*nums)[right] < (*nums)[left]) {
                tmp.emplace_back((*nums)[right++]);
            }
            tmp.emplace_back((*nums)[left]);
        }
        copy(tmp.cbegin(), tmp.cend(), nums->begin() + start);
    }
};


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(0, nums.size(), &nums);
        return nums;
    }

private:
    void quickSort(int start, int end, vector<int> *nums) {
        if (end - start <= 1) {
            return;
        }
        const auto& mid = start + (end - start) / 2;
        nth_element(nums->begin() + start,
                    nums->begin() + mid,
                    nums->begin() + end);
        quickSort(start, mid, nums);
        quickSort(mid, end, nums);
    }
};


// @lc code=end

