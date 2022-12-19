```c++
/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findEnd(vector<int> &nums, int begin) {
    for (size_t i = begin; i < nums.size() - 1; ++i) {
        if (nums[i] + 1 != nums[i + 1]) {
            return i;
        }
    }
    return nums.size() - 1;
}

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> answer;
        int begin = 0;
        while (begin < nums.size()) {
            int end = findEnd(nums, begin);
            if (begin == end) {
                string tmp = to_string(nums[begin]);
                answer.push_back(tmp);
            } else {
                string tmp =
                    to_string(nums[begin]) + "->" + to_string(nums[end]);
                answer.push_back(tmp);
            }
            begin = end + 1;
        }
        return answer;
    }
};

```
写一个 findEnd 传入 nums 和 起始的位置，返回不连续的位置  
判断一下，如果 begin == end 则 加入 nums[begin]  
begin != end 就 加入 nums[begin]) + "->" + to_string(nums[end])  
之后更新 begin 开始的位置为 end + 1  