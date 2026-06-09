```
class Solution {
public:
    bool valid(const vector<int>& e1, const vector<int>& e2) {
        return e1[0] < e2[0] && e1[1] < e2[1];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int N = envelopes.size();
        vector<vector<int> > g(N);
        vector<int> indegree(N, 0);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (valid(envelopes[i], envelopes[j])) {
                    g[i].push_back(j);
                    ++indegree[j];
                }
            }
        }
        vector<int> dfn(N, 0);
        queue<int> q;
        int res = 0;
        for (int i = 0; i < N; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
                dfn[i] = 1;
                res = 1;
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (auto j : g[i]) {
                dfn[j] = max(dfn[j], dfn[i] + 1);
                res = max(res, dfn[j]);
                if (--indegree[j] == 0) {
                    q.push(j);
                }
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/e70372cd307d344fe7bcdba0c3aad51e1f938e423d035f65b3e0d016c1311936-image.png)
