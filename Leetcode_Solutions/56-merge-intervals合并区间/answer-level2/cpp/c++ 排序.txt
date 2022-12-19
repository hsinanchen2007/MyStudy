先根据左边界排序，再用右边界和下一个的左边界相比。

`#define MAX(a, b) (a) > (b) ? (a) : (b)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &l, const vector<int> &r) {
            return l[0] < r[0];
        });

        vector<vector<int>> result;
        vector<int> onePair(2, 0);

        if (intervals.size() == 0) {
            return result;
        }

        for (int i = 0; i < intervals.size(); ++i) {
            if (i == 0) {
                onePair[0] = intervals[i][0];
                onePair[1] = intervals[i][1];
                continue;
            }

            // 得到一个区间
            if (onePair[1] < intervals[i][0]) {
                result.emplace_back(onePair);
                onePair[0] = intervals[i][0];
                onePair[1] = intervals[i][1];
            } else {
                onePair[1] = MAX(intervals[i][1], onePair[1]);
            }
        }
        result.emplace_back(onePair);

        return result;
    }
};`
