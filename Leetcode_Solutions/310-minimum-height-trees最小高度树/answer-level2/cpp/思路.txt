### 解题思路
很像拓扑排序的变种算法
无向图需要注意的入度是1来判断 另外最后是留2个节点

### 代码

```cpp
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
      if(n == 0) return {};
      if(n == 1) return {0};
      if(n == 2) return {0, 1};

      vector<int> res;
      vector<int> indegree(n, 0);
      queue<int> q;

      for(int i = 0; i < edges.size(); i++){
        indegree[edges[i][0]]++;
        indegree[edges[i][1]]++;
      }

      for(int i = 0; i < n; i++){
        if(indegree[i] == 1)
          q.push(i);
      }

      while(n > 2){
        int size = q.size();
        n = n - size;
        for(int k = 0; k < size; k++){
          int tmp = q.front();
          q.pop();
          for(int i = 0; i < edges.size(); i++){
            if(edges[i][0] == tmp || edges[i][1] == tmp){
              indegree[edges[i][0]]--;
              indegree[edges[i][1]]--;
              if(indegree[edges[i][0]] == 1){
                q.push(edges[i][0]);
              }
              if(indegree[edges[i][1]] == 1){
                q.push(edges[i][1]);
              }
            }
          }
        }
      }

      while(!q.empty()){
        res.push_back(q.front());
        q.pop();
      }

      return res;
    }
};
```