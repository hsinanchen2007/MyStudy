```cpp
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int, int>> h;
        for (const auto& b: buildings) {
            h.push_back(make_pair(b[0], -b[2]));
            h.push_back(make_pair(b[1], b[2]));
        } 
        sort(h.begin(), h.end());
        int pre = 0, cur = 0;
        multiset<int> m;
        m.insert(0); // 防止为空，并且最后的时候可以加入（cur， 0）
        for (const auto& e: h) {
            if (e.second < 0) m.insert(-e.second);
            else
                m.erase(m.find(e.second));
            cur = *m.rbegin();
            if (pre != cur) {
                res.push_back({e.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};