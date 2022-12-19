### 解题思路
刚开始的时候把问题想复杂了,按照图的算法来做,使用BFS来计算无权图任何两点之间的距离,总复杂度为O(n^3)

但是这其实是一道树的题目,**而且题目中明明用大字体写明了这是一棵无向树啊**

**既然是树, 怎么少的了递归解法**


### 代码

```cpp
using PII = pair<int,int>;

class Solution {
public:
    // BFS解决无权图任何两点间的最路径问题
    int dij(const vector<vector<int>> &g, int st){
        int n = g.size();
        int max_length = -1;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(st);
        visited[st] = true;
        while(!q.empty()){
            int len = q.size();
            max_length++;
            for(int i = 0; i < len; i++){
                int cur = q.front();
                q.pop();
                for(const int &next: g[cur]){
                    if(!visited[next]){
                        visited[next] = true;
                        q.push(next);
                        detected.insert(PII{cur, next});
                    }
                }
            }
        }
        return max_length;
    }

    // 树嘛,递归
    // dfs返回cur节点为根节点的子树的最大路径长度(最长路径上的节点数)
    int dfs(const vector<vector<int>> &g, int cur, int pre,int &ans){
        vector<int> childs;
        for(const int &next: g[cur]){
            if(next != pre) childs.push_back(dfs(g, next, cur, ans));
        }
        if(childs.empty()) return 1;
        if(childs.size() == 1){
            ans = max(ans, childs[0]);
            return childs[0]+1;
        }
        sort(childs.begin(), childs.end());
        int k = childs.size()-1, t = k-1;
        ans = max(ans, childs[k]+childs[t]);
        return childs[k]+1;
    }

    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        if(n == 1) return 0;
        vector<int> indegree(n, 0);
        vector<vector<int>> maps(n, vector<int>());
        for(const auto &line: edges){
            indegree[line[0]]++;
            indegree[line[1]]++;
            maps[line[0]].push_back(line[1]);
            maps[line[1]].push_back(line[0]);
        }
        // queue<int> q;
        // for(int i = 0; i < n; i++){
        //     if(indegree[i] == 1) q.push(i);
        // }
        // int max_length = 0;
        // while(!q.empty()){
        //     int st = q.front();
        //     q.pop();
        //     max_length = max(max_length, dij(maps, st));
        // }

        int max_length = 0;
        int k = dfs(maps, 0, -1, max_length);
        return max(max_length, k-1);
    }
};
```