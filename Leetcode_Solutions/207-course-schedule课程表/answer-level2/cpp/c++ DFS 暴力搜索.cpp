### 解题思路
使用邻接表存有向图，对每个点进行一次DFS

### 代码

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //vector<set<int>> graph[numCourses];
        //邻接表
        vector<int> graph[numCourses];
        //构建邻接表
        for(int i=0;i<prerequisites.size();i++){
            int from = prerequisites[i][0];
            int to = prerequisites[i][1];
            graph[from].push_back(to);
        }
        //DFS
        int *visited = (int*)malloc(numCourses*sizeof(int));
        int flag = 0;
        memset(visited, 0, numCourses*sizeof(int));
        for(int i=0;i<numCourses;i++){
            memset(visited, 0, numCourses*sizeof(int));
            //if(graph[i].size()>0){
                visited[i]=1;
                DFS(graph, visited, &flag, i);
            //}
            if(flag) {
                return false;
            }
        }
        return true;
    }
    void DFS(vector<int> g[], int *visited, int *flag, int node){
        if(*flag){
            return;
        }
        for(int i=0;i<g[node].size();i++){
            if(0 == visited[g[node][i]]){
                visited[g[node][i]]=1;
                DFS(g, visited, flag, g[node][i]);
                visited[g[node][i]]=2;
            }
            if(1==visited[g[node][i]]){
                *flag = 1;
            }
        }
    }
};
```