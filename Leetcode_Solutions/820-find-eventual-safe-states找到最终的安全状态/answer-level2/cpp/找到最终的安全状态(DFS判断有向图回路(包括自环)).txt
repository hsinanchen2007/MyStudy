### 解题思路

### 代码

```cpp
class Solution 
{
public:
    vector<int> vis,InStack,res;

    vector<int> eventualSafeNodes(vector<vector<int>>& g) 
    {
        int n=g.size();
        vis=vector<int>(n,0),InStack=vis;

        for(int i=0;i<n;i++)
            if(!vis[i]) 
                DFS(i,g);
    
        for(int i=0;i<n;i++)
            if(!InStack[i]) 
                res.push_back(i);
        
        return res;
    }

    void DFS(int pre,vector<vector<int>>& g)
    {
        vis[pre]=1;
        InStack[pre]=1;

        for(int next:g[pre])
        {
            if(!vis[next] && !InStack[next]) DFS(next,g);
            if(InStack[next]) return;
        }

        InStack[pre]=0;
    }
};
```