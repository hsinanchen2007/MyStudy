### 解题思路
拓扑排序，邻接表+入度数组+队列

### 代码

```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> G[numCourses];
        int inDegree[numCourses];
        for(int i=0;i<numCourses;i++)
            inDegree[i]=0;
        for(int i=0;i<prerequisites.size();i++){
            G[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        int num=0;
        queue<int> q;
        vector<int> res;
        for(int i=0;i<numCourses;i++)
            if(inDegree[i]==0)
                q.push(i);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            res.push_back(u);
            for(int i=0;i<G[u].size();i++){
                int v=G[u][i];
                inDegree[v]--;
                if(inDegree[v]==0)
                    q.push(v);
            }
            G[u].clear();
            num++;
        }
        if(num!=numCourses)
            res.clear();
        return res;
    }
};
```