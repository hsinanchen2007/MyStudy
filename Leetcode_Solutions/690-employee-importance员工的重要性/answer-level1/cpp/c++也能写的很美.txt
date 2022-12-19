标准的广搜
```
class Solution {
public:
    int getImportance(vector<Employee *> employees, int id) {
        vector<pair<int, vector<int>>> G(2000);
        for (auto e : employees) {
            for_each(e->subordinates.begin(), e->subordinates.end(), [](int &i) {i--;});
            G[e->id - 1] = make_pair(e->importance, e->subordinates);
        }
        int result = 0;
        queue<int> q;
        q.push(id - 1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            auto [val, adj] = G[u];
            result += val;
            for (auto v : adj)
                q.push(v);
        }
        return result;
    }
};
```