![微信截图_20200314124229.png](https://pic.leetcode-cn.com/eef86dc0e3385e6b55c755d0809ca7532e4c0db8f2b6bcd947808bb1b1964457-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200314124229.png)

```
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for(auto &p : prerequisites){
            ++indegree[p[0]];
            adj[p[1]].push_back(p[0]);
        }

        queue<int> q;
        for(int i = 0; i < indegree.size(); ++i){
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            for(auto &i : adj[q.front()]){
                --indegree[i];
                if(indegree[i] == 0)
                    q.push(i);
            }
            adj.erase(q.front());
            q.pop();
        }
        return adj.empty();
    }
};
```


