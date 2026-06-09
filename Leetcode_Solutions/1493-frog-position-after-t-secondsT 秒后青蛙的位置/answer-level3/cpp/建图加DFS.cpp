
```
class Solution {
public:
    
    vector<vector<int> > table;
    int vis[101];    
    bool flag;
    int target;
    double ans;
    double frogPosition(int n, vector<vector<int>>& edges, int t, int targets) {
        table.resize(n);
        memset(vis,0,101*4);
        flag=false;
        target=targets;
        for(auto i:edges)
        {
            table[i[0]-1].push_back(i[1]-1);
            table[i[1]-1].push_back(i[0]-1);
        }
        dfs(0,1,t);
        return ans;
    }
    void dfs(int root,double sum,int t)
    {
        if(flag)return;
        if(!t){if(root+1==target){flag=true;ans=sum;}return;}//到达目标时间判定
        vis[root]=1;
        double val=table[root].size();
        if(root!=0)val--;//下一个节点的概率等于 1/子节点数,子节点数等于边数减去父节点
        if(!val){if(root+1==target){flag=true;ans=sum;}return;}//叶子节点判定
        for(auto i:table[root]){if(!vis[i])dfs(i,sum/val,t-1);}   
    }
};
```
