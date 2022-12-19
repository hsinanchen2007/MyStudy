### 解题思路


### 代码

```cpp
class Solution {
public:
    string lastSubstring(string s) {
        s += '.';
        int n = s.length();
        int l = 0;
        int r = 1;
        int k = 0;
        while (l < n && r < n && k < n) {
            if (s[(l + k) % n] == s[(r + k) % n]) k++;
            else {
                if (s[(l + k) % n] > s[(r + k) % n]) r = r + k + 1;
                else l = l + k + 1;
                if (l == r) r++;
                k = 0;
            }
        }
        int p = min(l ,r);
        return s.substr(p, n - p - 1);
    }
    /*string lastSubstring(string s) {
        int len = s.size();
        if (len == 0) {
            return "";
        }
        vector<int> rank;
        for (int i = 0; i < len; i++) {
            rank.push_back(i);
        }
        unordered_map<int, int> mark;
        queue<vector<int>> q;
        q.push(rank);
        int layer = 0;
        while (q.empty() == false) {
            int k = q.size();
            vector<int> remains;
            for (int i = 0; i < k; i++) {
                vector<int> curr = q.front();
                q.pop();
                if (curr.size() == 1) {
                    mark[curr[0]] = 1;
                    continue;
                }
                map<char, vector<int>> m;
                for (auto idx : curr) {
                    if (idx + layer < len) {
                        m[s[idx + layer]].push_back(idx);
                    } else {
                        q.push(vector<int>{idx});
                        remains.push_back(idx);
                    }
                }
                for (auto it = m.begin(); it != m.end(); it++) {
                    q.push(it->second);
                    for (auto idx : it->second) {
                        remains.push_back(idx);
                    }
                }
            }
            layer++;
            int i = 0;
            int j = 0;
            while (i < len) {
                if (mark[rank[i]] == 1) {
                    i++;
                    continue;
                } 
                rank[i] = remains[j];
                i++;
                j++;
                if (j >= remains.size()) {
                    break;
                }
            }
        }
        return s.substr(rank[len - 1]);
    };*/
};
```