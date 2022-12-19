### 解题思路

拓扑排序：

1. 需要检测环；
2. 需要判断入度为0的定点个数不超过1个，所以应用BFS而不是DFS。

### 代码

```cpp
class Solution {
private:
    vector<unordered_set<int>> graph;
    vector<int> indegree;
    vector<int> res;
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        graph.resize(n + 1);
        indegree.resize(n + 1);
        
        // init graph
        unordered_set<int> dict;
        for(auto& seq: seqs) {
            if(seq.size() == 0)
                continue;
            for(int num: seq) {
                if(num <= 0 || num > n)
                    return false;
                dict.insert(num);
            }
            if(seq.size() > 1) {
                int len = seq.size();
                for(int i=0; i<len-1; i++) {
                    if(graph[seq[i]].count(seq[i+1]) == 0) {
                        graph[seq[i]].insert(seq[i+1]);
                        indegree[seq[i+1]]++;
                    }
                }
            }
        }
        
        if(dict.size() < n)
            return false;
        
        // topo sort
        queue<int> Q;
        vector<int> res;
        for(int i=1; i<=n; i++) {
           if(indegree[i] == 0)
               Q.push(i);
        }
        while(!Q.empty()) {
            int n = Q.size();
            if(n > 1)
                return false;
            int u = Q.front();
            res.push_back(u);
            Q.pop();
            for(int v: graph[u]) {
                if(--indegree[v] == 0)
                    Q.push(v);
            }
        }
        
        if(res.size() != org.size())
            return false;
        for(int i=0; i<n; i++) {
            if(res[i] != org[i])
                return false;
        }
        
        return true;
    }
    
};
```