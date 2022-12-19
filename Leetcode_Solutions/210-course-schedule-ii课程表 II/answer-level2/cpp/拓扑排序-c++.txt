### 解题思路
和I的做法几乎一致，只是多了个存储罢了。
还有就是，题目并没有说清楚，可以不存在拓扑序列的，此时应该输出空数组。

### 代码

```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(numCourses);  //邻接表
        vector<int> inDegree(numCourses, 0);//记录入度
        vector<int> ans;
        //初始化
        int s,e;
        for(int i = 0; i < prerequisites.size(); i++) {
            e = prerequisites[i][0];
            s = prerequisites[i][1];
            G[s].push_back(e);
            inDegree[e]++;
        }
        int num = 0; //判断有无环（也就是可否学完课程）
        queue<int> q;
        //所有入度为0的入队
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) q.push(i);
        }
        //核心算法--不断出队，对出队结点的所连结点入度减一，同时为零入队
        while(!q.empty()) {
            int u = q.front();
            ans.push_back(u);  //添加
            q.pop();
            for(int i = 0; i < G[u].size(); i++) {  //减一操作，同时为零入队
                int v = G[u][i];
                inDegree[v]--;
                if(inDegree[v] == 0) q.push(v);
            }
            G[u].clear();  //消除u的出边
            num++;
        }
        if(num == numCourses) return ans;  //存拓扑序列
        //不存在
        ans.clear();
        return ans;
        
    }
};
```