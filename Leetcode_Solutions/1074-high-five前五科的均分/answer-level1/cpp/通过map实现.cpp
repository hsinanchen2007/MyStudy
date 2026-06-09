
```
static const auto _ = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, vector<int> > scoreTab;
        vector<vector<int>> res;
        if (items.size() == 0) return res;
        for (int i = 0; i < items.size(); i++) {
            scoreTab[items[i][0]].push_back(items[i][1]);
        }

        for (auto it = scoreTab.begin(); it != scoreTab.end(); it++) {
            sort(((*it).second).begin(), ((*it).second).end(), std::greater<int>());
            int sum = accumulate(((*it).second).begin(), ((*it).second).begin() + 5, 0);  
            res.push_back({(*it).first, sum / 5});
        }
        return res;
    }
};
```
