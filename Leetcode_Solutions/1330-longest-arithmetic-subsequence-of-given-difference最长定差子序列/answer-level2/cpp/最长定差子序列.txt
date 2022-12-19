```
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> m;
        int ret = 1;

        for (auto a : arr) {
            m[a] = m[a - difference] + 1;
            ret = max(ret, m[a]);
        }
        return ret;
    }    
};
```

