### 解题思路

### 代码

```cpp
class Solution {
public:
    int findTheLongestSubstring(string s) {
        set<char> y{'a', 'e', 'i','o','u'};
        map<char, int> m;
        unordered_map<int, vector<int>> um;
        for (int i = 0; i < s.size(); i++) {
            if (y.find(s[i]) != y.end()) {
                m[s[i]]++;
            }
            bitset<5> b;
            for (auto p : m) {
                if ((p.second & 1) == 1) {
                    b[p.first - 'a'] = 1;
                }
            }
            um[b.to_ulong()].push_back(i);
        }
        int ans = 0;
        for (auto it = um.begin(); it != um.end(); it++) {
            int k;
            if (it->first == 0) {
                k = it->second.back() + 1;
            } else {
                k = it->second.back() - it->second[0];
            }
            ans = max(k, ans);
        }
        return ans;
    }
};
```