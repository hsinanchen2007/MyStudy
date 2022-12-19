### 解题思路

### 代码

```cpp
class Solution {
public:
    bool isSimilar(string a, string b) {
        vector<int> pos;
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                pos.push_back(i);
                diff++;
                if (diff > 2) {
                    break;
                }
            }
        }
        if (pos.size() == 2 && a[pos[0]] == b[pos[1]] && a[pos[1]] == b[pos[0]]) {
            return true;
        }
        if (pos.size() == 0) {
            return true;
        }
        return false;
    };
public:
    int numSimilarGroups(vector<string>& A) {
        int groupNum = 0;
        if (A.size() == 0) {
            return 0;
        }
        unordered_map<int, vector<int>> m;
        if (A.size() < A[0].size() * A[0].size()) {
            for (int i = 0; i < A.size(); ++i) {
                for (int j = i - 1; j >= 0; --j) {
                    if (isSimilar(A[i], A[j]) == true) {
                        m[i].push_back(j);
                        m[j].push_back(i);
                    } 
                }
            }
        } else {
            unordered_map<string, set<int>> neighbors; // 关键1
            for (int i = 0; i < A.size(); ++i) {
                string str = A[i];
                for (int j = 0; j < A[0].size(); j++) {
                    for (int k = j; k < A[0].size(); k++) {
                        swap(str[j], str[k]);
                        neighbors[str].insert(i);
                        swap(str[j], str[k]);
                    }
                }
            }
            set<string> AA(A.begin(), A.end()); // 关键2
            for (int i = 0; i < AA.size(); i++) {
                for (auto idx : neighbors[A[i]]) {
                    m[i].push_back(idx);
                    m[idx].push_back(i);
                }
            }
        }
        vector<int> vis(A.size(), 0);
        for (int i = 0; i < A.size(); i++) {
            if (vis[i] == 1) {
                continue;
            }
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while (q.empty() == false) {
                int curr = q.front();
                q.pop();
                for (auto node : m[curr]) {
                    if (vis[node] == 1) {
                       continue;
                    }
                    q.push(node);
                    vis[node] = 1;
                }
            }
            groupNum++;
        } 
        return groupNum;
    }
};
```