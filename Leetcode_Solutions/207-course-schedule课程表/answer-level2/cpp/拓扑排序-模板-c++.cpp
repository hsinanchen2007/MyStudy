### 解题思路
所谓的边缘列表有点扯，实际就是记录每条边:[end, start]，将其转换成邻接表形式，再用一个队列记录入度，便是套模板了
具体看注释。。

### 代码

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(numCourses);  //邻接表
        vector<int> inDegree(numCourses, 0);//记录入度
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
            q.pop();
            for(int i = 0; i < G[u].size(); i++) {  //减一操作，同时为零入队
                int v = G[u][i];
                inDegree[v]--;
                if(inDegree[v] == 0) q.push(v);
            }
            G[u].clear();  //消除u的出边
            num++;
        }
        if(num == numCourses) return true;
        return false;
    }
};
```