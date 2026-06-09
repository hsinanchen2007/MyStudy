```c++
class Solution {
public:
    vector<int>father;
    int find(int x){
        return x==father[x]?x:find(father[x]);
    }
    unordered_map<int,int>flower;
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>>G(N+1);
        vector<int>res(N,-1);
        father=vector<int>(N+1);
        for(int i=1;i<=N;i++)father[i]=i;   //并查集
        bool vis[N+1];
        fill(vis,vis+N+1,false);
        int n = paths.size();
        for(int i=0;i<n;i++){
            int xf = find(paths[i][0]),yf = find(paths[i][1]);
            if(xf != yf)father[max(xf,yf)] = father[min(xf,yf)];
            G[paths[i][0]].push_back(paths[i][1]);
            G[paths[i][1]].push_back(paths[i][0]);
        }
        queue<int>q;
        flower[2]=1,flower[4]=2,flower[8]=3,flower[16]=4;
        for(int i=1;i<=N;i++){
            if(i==find(i)){
                q.push(i);  //把每个连通分量的根节点进队
            }
        }
        while(!q.empty()){  //核心逻辑检查每个点的邻接点的颜色
            int p = q.front(),color=1,t=1;
            q.pop();
            if(vis[p])continue;
            vis[p]=1;
            for(auto &c : G[p]){
                if(res[c-1]!=-1)color|=1<<res[c-1];
                q.push(c);
            }
            int r = color ^ 31; //用异或找到最后一个0即没用过的花
            res[p-1] = flower[r & -r];  //用lowbit找到最后一个1即要种的花
            
        }
        return res;
    }
};
```