### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, set<int>> m;
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                m[i].insert(graph[i][j]);
            }
        }
        vector<int> vis(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++) {
            if (vis[i] == 1 || vis[i] == 2) {
                continue;
            }
            stack<int> s;
            vector<int> path;
            s.push(i);
            vis[i] = 1;
            int flag = 0;
            while (s.empty() == false) {
                int curr = s.top();
                s.pop();
                path.push_back(curr);
                int k = s.size();
                for (auto node : m[curr]) {
                    if (find(path.begin(), path.end(), node) != path.end()) {
                        flag = 1;
                        break;
                    }
                    if (vis[node] == 0 || vis[node] == 1) {
                        s.push(node);
                        vis[node] = 1;
                    }
                }
                if (flag == 1) {
                    while (s.size() > 0 ) {
                        vis[s.top()] = 0;
                        s.pop();
                    }
                    break;
                } 
                if (k == s.size() && flag == 0) {
                    if (k == 0) {
                        while (path.size() > 0) {
                            vis[path.back()] = 2;
                            path.pop_back();
                        }
                    } else {
                        while (m[path.back()].find(s.top()) == m[path.back()].end()) {
                            vis[path.back()] = 2;
                            path.pop_back();
                        }
                    }
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < graph.size(); i++) {
            if (vis[i] == 2) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
/*class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, int> outDegree;
        unordered_map<int, vector<int>> mReverse;
        for (int i = 0; i < graph.size(); i++) {
            outDegree[i] = graph[i].size();
            for (int j = 0; j < graph[i].size(); j++) {
                mReverse[graph[i][j]].push_back(i);
            }
        }
        vector<int> ans;
        vector<int> vis(graph.size(), 0);
        queue<int> q;
        for (int i = 0; i < graph.size(); i++) { // 寻找初始点
            if (outDegree[i] == 0) { // 出度为0
                q.push(i);
                ans.push_back(i);
                vis[i] = 1;
            }
        }
        while (q.empty() == false) {
            //int sz = q.size();
            //for (int i = 0; i < q.size(); i++) {
                int curr = q.front();
                q.pop();
                for (auto nxt : mReverse[curr]) {
                    if (outDegree[nxt] == 1) {
                        q.push(nxt);
                        ans.push_back(nxt);
                        vis[nxt] = 1;
                    } else {
                        outDegree[nxt]--;
                    }
                }
            //}
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};*/
```