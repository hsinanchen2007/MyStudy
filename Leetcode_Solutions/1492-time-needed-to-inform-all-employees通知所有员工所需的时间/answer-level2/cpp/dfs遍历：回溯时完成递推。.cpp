状态定义：dp[i]表示已i号节点为根的子树，完成消息传递所用的**最大**时间
状态初始化：dp[叶节点] = 0
状态转移:dp[父亲]=max(dp[儿子]+父亲的费用)
存储方式vector<int> es[N]表示邻接表，注意用之前要clear一下。
代码如下：
```
vector<int> es[100001];
vector<int> iT;
class Solution {
public:

    int dfs(int x){
        if(iT[x]==0) return 0;
        int res = 0;
        for(int i=0; i<es[x].size(); i++)
            res = max(res, dfs(es[x][i]));
        return res + iT[x];
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        //manager数组转邻接表
        iT.clear();
        for(int i=0; i<n; i++) es[i].clear();
        for(int i=0; i<n; i++) iT.push_back(informTime[i]);
        for (int i=0; i<manager.size(); i++)
            if(i!=headID)
                es[manager[i]].push_back(i);
        return dfs(headID);
        
    }
};
```


