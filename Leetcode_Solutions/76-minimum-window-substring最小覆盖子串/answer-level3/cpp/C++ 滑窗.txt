### 解题思路
滑窗

### 代码

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        int sizeS = s.size();
        int sizeT = t.size();
        unordered_map<char, int> need;
        unordered_map<char, int> have;
        string res = "";
        for (auto c : t) {
            need[c]++;
        }

        int curr = 0, start = 0, cnt = 0;
        while (curr < sizeS) {
            if (need.count(s[curr])) {
                have[s[curr]]++;
                if (have[s[curr]] == need[s[curr]]) {
                    cnt++;
                }
            }
           
            while (cnt == need.size()) {
                if (res.size() == 0 || curr - start + 1 < res.size()) {
                    res = s.substr(start, curr - start + 1);
                }

                if (need.count(s[start])) {
                    have[s[start]]--;
                    if (have[s[start]] < need[s[start]]) {
                        cnt--;
                    }
                }
                start++;
            }

            curr++;
        }

        return res;
    }
};
```