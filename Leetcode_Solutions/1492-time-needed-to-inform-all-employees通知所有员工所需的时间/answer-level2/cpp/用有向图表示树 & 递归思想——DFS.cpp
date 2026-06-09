
## 思路
使用递归的思想，经理要通知到其底下所有人所需最少时间，就是经理直接通知的所有人当中通知自己属下花费时间最长的那个人的通知时间加上经理自己通知属下的时间；如果通知的那个人没有属下，则可以看成通知属下的时间为0，故这个条件作为递归基。
## 实现思路
利用所给的从属关系构建出一棵树，这棵树使用一个有向图表示，图中只收录父结点到子结点的边，子结点到父结点是没有边的，不难看出没有属下的底层员工的出度为0。图的边权即为通知时间，为了图的简洁此处省略边权的表示，而是直接使用informTime[s]作为s到其它点的边的权重。
至于为什么选择DFS而不是BFSm，因为为了求最长通知时间用递归思想会比较方便，而DFS就是用递归实现的。
## 代码
```
class Solution {
public:
    int dfs(vector<vector<int>>& G, vector<int>& informTime, int s) 
    //计算员工s（s为源点source之意）通知所有属下所需的时间
    {
        if(G[s].size() == 0)
            return 0;
        int res = 0;
        for(int i=0; i<G[s].size(); i++)        
            res = max(dfs(G, informTime, G[s][i]) + informTime[s], res);        
        return res;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> G(n); //反映等级的有向图
        for(int i=0; i<n; i++) //构建有向图，如果i有人manager[i]管，则从manager[i]到i引一条边
        {
            if(i == headID) continue; //如果是经理，则没人管
            G[manager[i]].push_back(i);
        }
        return dfs(G, informTime, headID); 
    }
};
```

