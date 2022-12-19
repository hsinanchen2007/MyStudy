```
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> input(n); // 入节点列表
        vector<int> output(n, 0); // 出度
        vector<int> res; // 出度为0则加入结果集
        for(int i=0;i<n;i++) {
            if(graph[i].empty()) res.push_back(i);
            else {
                output[i] = graph[i].size();
                for(int j: graph[i]) input[j].push_back(i);
            }
        }
        for(int i=0;i<res.size();i++) {
            for(int j: input[res[i]]) {
                if(--output[j]==0) res.push_back(j);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
```
