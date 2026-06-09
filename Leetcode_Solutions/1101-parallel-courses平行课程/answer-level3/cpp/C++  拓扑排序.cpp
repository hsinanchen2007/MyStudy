一开始用unordered_map，60+ms；改成 vector 40ms

```
class Solution {
public:

    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<vector<int>> g(N);
        vector<int> inDegree(N, 0);
        for (vector<int>& rel : relations) {
            g[rel[0]-1].push_back(rel[1]-1);
            inDegree[rel[1]-1]++;
        }
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        int level = 0, cnt = 0;
        while (!q.empty()) {
            int sz = q.size();
            level++;
            cnt += sz;
            for (int i = 0; i < sz; ++i) {
                int cur = q.front(); q.pop();
                for (int dest : g[cur]) {
                    inDegree[dest]--;
                    if (inDegree[dest] == 0) {
                        q.push(dest);
                    }
                }
            }
        }
        return cnt != N ? -1 : level;
    }
};


```
