思路

* 把两个slots的起始和结束时间点放一起排序，并且记录每个时间点是start还是end
* 上车的思想，用一个计数标记，遇到开始就+1，遇到结束就-1
* 如果计数为2，表示两个区间开始重合，每次判断上一次的时间点是否是2，如果是则必定上一个时间点到当前时间点是重合区间


```
class Solution {
public:
    static bool compair(pair<int, bool>& a, pair<int, bool>& b) {
        return a.first < b.first;
    }

    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        vector<pair<int, bool>> timestamps;
        for (vector<int>& slot : slots1) {
            timestamps.push_back({slot[0], true});
            timestamps.push_back({slot[1], false});
        }
        for (vector<int>& slot : slots2) {
            timestamps.push_back({slot[0], true});
            timestamps.push_back({slot[1], false});
        }
        sort(timestamps.begin(), timestamps.end(), compair);
        int cur = 0, tmp = 0;
        for (int i = 0; i < timestamps.size(); ++i) {
            pair<int, bool> t = timestamps[i];
            if (cur == 2 && t.first - tmp >= duration) {
                return {tmp, min(t.first, tmp + duration)};
            }
            cur += t.second ? 1 : -1;
            if (cur == 2) tmp = t.first;
        }
        return {};
    }
};
```
