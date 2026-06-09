- 先用dfs找1~target的路径存在path中。然后用bfs计算概率(这个过程只放path中的节点)
- 时间复杂度：$O(n+m)$
```c++
class Solution {
public:
    vector<vector<int>>G;
    vector<int> path;
    vector<bool>vis;
    bool flag=0;
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        G = vector<vector<int>>(n+1);
        vis = vector<bool>(n+1);
        int m = edges.size();
        if(!m && target==1)return 1;
        double res=1;
        //构造无向图
        for(int i=0;i<m;++i)G[edges[i][0]].push_back(edges[i][1]),G[edges[i][1]].push_back(edges[i][0]);   
        vis[1] = 1;
        dfs(1,target);  //找出1~target的路径存在path中
        int k = path.size(),p = 0;
        if(t<k)return 0;    //时间过短跳不到target
        if(t>k){
            /*如果时间充足但是到达target节点后还有时间，且与target相连的还有没到过的
            则都算到不了，这是个坑点*/
            if((target == 1 && G[1].size() != 0) || G[target].size() - 1 != 0)return 0; 
        }
        queue<int>q;
        q.push(1);
        while(!q.empty()){
            int len = G[q.front()].size();
            q.pop();
            if(p!=0)len--;      //算概率
            if(len)res*=len;
            if(p==k-1)break;
            q.push(path[p++]);
        }
        return 1/res;
    }
    void dfs(int u,int &target){
        if(flag == 1)return;
        if(u == target){
            flag = 1;
            return ;
        }
        int m = G[u].size();
        for(int i=0;i<m;++i){
            if(vis[G[u][i]] == 1)continue;
            vis[G[u][i]] = 1;
            path.push_back(G[u][i]);
            dfs(G[u][i], target);
            if(flag)break ;
            path.pop_back();
        }
    }
};
```