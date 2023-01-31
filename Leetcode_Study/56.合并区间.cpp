/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

/*

https://leetcode.cn/problems/merge-intervals/

56. 合并区间

中等
1.8K
company
亚马逊
company
彭博 Bloomberg
company
Facebook
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 
一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。 

提示：

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

*/

// @lc code=start
class Solution100 {
public:
    // 2023.1.30, from https://www.acwing.com/activity/content/code/content/362233/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/362233/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;

        sort(intervals.begin(), intervals.end());
        int l = intervals[0][0], r = intervals[0][1];
        for (int i = 1; i < intervals.size(); i ++ ) {
            if (intervals[i][0] > r) {
                res.push_back({l, r});
                l = intervals[i][0], r = intervals[i][1];
            } else r = max(r, intervals[i][1]);
        }

        res.push_back({l, r});
        return res;
    }
};


class Solution99 {
public:
    // 2023.1.30, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/merge-intervals.cpp
    // Time:  O(nlogn)
    // Space: O(1)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        vector<vector<int>> result;
        for (const auto& interval : intervals) {
            if (empty(result) || interval[0] > result.back()[1]) { 
                result.emplace_back(interval);
            } else {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};


class Solution {
public:
    // 2023.1.30, from https://walkccc.me/LeetCode/problems/0056/
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(begin(intervals), end(intervals));

        for (const vector<int>& interval : intervals)
            if (ans.empty() || ans.back()[1] < interval[0])
                ans.push_back(interval);
            else
                ans.back()[1] = max(ans.back()[1], interval[1]);

        return ans;
    }
};


// @lc code=end

