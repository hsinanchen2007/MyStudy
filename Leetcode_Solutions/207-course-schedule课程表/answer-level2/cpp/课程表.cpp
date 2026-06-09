
1）深度优先遍历~
首先我们能够构建出图，然后根据图中节点之间的依赖关系，进行dfs运算。实际运算中，我们是默认将该节点设置为正在访问的状态-1，然后对其相连节点的子图进行判断。如果每个子图都可以满足依赖关系，那么该大图就是可以满足依赖关系的，因此就可成功访问，置为1。最后选择对某个节点进行dfs操作即可。

```
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph(numCourses,vector<int>(0));
        for(auto prq:prerequisites){
            graph[prq[1]].push_back(prq[0]);
        }
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!helper(graph,visited,i)) return false;
        }
        return true;
    }
    bool helper(vector<vector<int> >& graph,vector<int>& visited,int i){
        if(visited[i]==-1) return false;
        if(visited[i]==1) return true;
        visited[i]=-1;
        for(auto a:graph[i]){
            if(!helper(graph,visited,a)) return false;
        }
        visited[i]=1;
        return true;
    }
};
```

2）广度优先遍历
因为课程之间存在相互依赖关系，因此我们构建图，然后根据入度关系进行处理。
```
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph(numCourses,vector<int>());
        vector<int> in(numCourses,0);
        for(auto pre:prerequisites){
            graph[pre[1]].push_back(pre[0]);
            ++in[pre[0]];
        }
        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(in[i]==0) q.push(i);
        }
        while(!q.empty()){
            int size=q.size();
            while(size-->0){
                auto temp=q.front();
                q.pop();
                for(auto itm:graph[temp]){
                    --in[itm];
                    if(in[itm]==0) q.push(itm);
                }
            }
        }
        for(auto itm:in){
            if(itm!=0) return false;
        }
        return true;
    }
};
```
