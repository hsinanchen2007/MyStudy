
简单的c++实现

```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> r;
        r.emplace_back(vector<int>());
        for(auto x : nums){
            int s = r.size();
            for(int i = 0; i < s; ++i){
                auto ri = r[i];
                ri.emplace_back(x);
                r.emplace_back(ri);
            }
        }
        return r;
    }
};
```
