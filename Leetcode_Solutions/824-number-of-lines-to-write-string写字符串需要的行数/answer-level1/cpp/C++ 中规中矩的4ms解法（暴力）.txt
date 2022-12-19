```cpp
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> res;
        res.emplace_back(1);
        res.emplace_back(0);
        for (auto s : S) {
            int w = widths[s - 'a'];
            if (w + res[1] > 100) {
                ++res[0];
                res[1] = 0;
            }
            res[1] += w;
        }
        return res;
    }
};
```