```
    int n;//节点数
    int st[10010];//0表示还没搜过; -1表示以该点开始的dfs搜索完毕; 1 表示该点被当前轮的dfs搜索了
    int h[10010],e[10010],ne[10010],idx,deg[10010];
    void add(int a, int b){e[idx] = b, ne[idx] = h[a], h[a] = idx++;}
    bool dfs(int u){//判断是否有环
        if(st[u]==-1) return false;//对于已经搜索完毕了点 无需搜 
        if(st[u]==1) return true;//因为该点在当前轮搜到过 而现在又来了 第二次到达 说明存在环
        st[u] = 1;//当前轮开始访问
        for(int i = h[u]; i!=-1; i = ne[i]){//访问u的所有邻接点
            int j = e[i];
            if(dfs(j)) return true;
        }
        st[u] = -1;//以u为起点的dfs访问完毕
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        n = numCourses;
        memset(h,-1,sizeof(h));
        for(auto v : pre) add(v[1],v[0]),deg[v[0]]++;
        for(int i = 0; i < n; i++){
            if(dfs(i)) return false;//发现环  
        }
        return true;
    }
```
