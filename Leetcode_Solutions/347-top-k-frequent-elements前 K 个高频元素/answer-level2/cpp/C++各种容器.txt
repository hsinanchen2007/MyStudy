```
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (const auto &i : nums) {
            ++m[i];
        }
        vector<pair<int, int>> tmp;
        for (auto& i : m)
            tmp.push_back(i);

        sort(tmp.begin(), tmp.end(), 
                  [=](pair<int, int>& a, pair<int, int>& b) { return a.second > b.second; });
        vector<int> res;
        auto it = tmp.cbegin();
        for (int i = 0; i < k; ++i) {
            res.push_back(it->first);
            ++it;
        }
        return res;
    }
};