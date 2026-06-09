思路参考自其他解与评论区解法
```
class Solution {
public:
    struct Cmp {
        bool operator() (const vector<int>& v1, const vector<int>& v2) const {
            if (v1[1] == v2[1])
                return v1[0] > v2[0];
            return v1[1] < v2[1];
        }
    };
    int intersectionK(vector<vector<int>>& intervals, int K) {
        // sort by right asc first, and by left desc
        sort(intervals.begin(), intervals.end(), Cmp());
        int S = intervals.size();
        set<int> selected;
        int res = 0;
        int i = 0;
        for (int i = 0; i < S; ++i) {
            int left = intervals[i][0];
            int right = intervals[i][1];
            int count = 0;
            for (auto it = selected.rbegin(); it != selected.rend() && (*it) >= left; ++it)
                ++count;
            res += K - count;
            while (K > count) {
                if (selected.find(right) == selected.end()) {
                    selected.insert(right);
                    ++count;
                    if (selected.size() > K) // only need K elements
                        selected.erase(selected.begin());
                }
                --right;
            }
        }
        return res;
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        return intersectionK(intervals, 2);
    }
};
```
