![QQ图片20191115161914.png](https://pic.leetcode-cn.com/92dad2de9599fdd64a3d6aeb6a6e67c94830fe616649e5046cbcbd85e0d13800-QQ%E5%9B%BE%E7%89%8720191115161914.png)

```
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S==T) return 0;
        unordered_map<int,vector<int>> r;
        
        int n=routes.size();
        for(int i=0 ;i<n;++i)
        {
            for(int route : routes[i])
            {
                r[route].push_back(i);                
            }
        }

        vector<bool> visited_route(n,false);
        queue<int> q;
        q.push(S);

        int dis=0;
        while(!q.empty())
        {
            ++dis;
            int m=q.size();
            while(m--)
            {
                int f=q.front();
                q.pop();
                for(int i:r[f])
                {
                    if(visited_route[i])continue;
                    visited_route[i]=true;
                    for(int j:routes[i])
                    {
                        if(j==T)return dis;
                        q.push(j);
                    }
                }
            }
        }

        return -1;
    }
};
```
