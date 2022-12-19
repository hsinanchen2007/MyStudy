对于每一组 u-->v 的描述，我们都令 v 的入度+1,然后我们只要扫一遍把入度是0的点dfs一遍即可。
判断是否能完成只需看是否所有点的入度是否都小于0即可。
```c++ []
class Solution {
public:
    
    int h[100000],to[100000],next[100000],d[100000],cnt;
        void add(int u,int v){
        to[++cnt] = v; next[cnt] = h[u]; h[u] = cnt;
    }
    void dfs(int u){
        for(int e = h[u]; e; e = next[e]){
            d[to[e]]--;
            if(d[to[e]] == 0) dfs(to[e]);
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {    
        memset(d,0,sizeof d);
        for(int i = 0; i < prerequisites.size(); i++)
            add(prerequisites[i][0],prerequisites[i][1]),
            d[prerequisites[i][1]]++;
        for(int i = 0 ; i < numCourses; i++){
            if(d[i] == 0) dfs(i);
        }
        for(int i = 0; i < numCourses; i++)
            if(d[i] > 0) return false;
        return true;
    }

};
