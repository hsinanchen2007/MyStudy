### 解题思路
CPP算法笔记模板

### 代码

```cpp
class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> G[numCourses];
        int Indegree[numCourses];
        memset(Indegree,0,sizeof(Indegree));
        //建图
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            Indegree[v]++;
            G[u].push_back(v);
        }
        //收入所有入度为0的点
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(Indegree[i]==0){
                q.push(i);
            }
        }
        //拓扑排序
        int num=0;//记录修的课的个数
        while(!q.empty()){
            int u=q.front();
            q.pop();
            num++;
            //修掉u这门课
            for(int j=0;j<G[u].size();j++){
                int v=G[u][j];
                Indegree[v]--;
                if(Indegree[v]==0){
                    q.push(v);
                }
            }
            if(num>numCourses)return false;//存在环，失败
        }

        return num==numCourses;
    }
};
```