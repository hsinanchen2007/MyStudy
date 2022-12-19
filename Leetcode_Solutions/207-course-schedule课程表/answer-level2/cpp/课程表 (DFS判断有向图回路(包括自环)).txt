### 解题思路

### 代码

```cpp
class Solution 
{
public:
    vector<vector<int>> g;
    vector<int> vis,InStack;
    bool loop=false;

    bool canFinish(int num, vector<vector<int>>& proj) 
    {
        g=vector<vector<int>>(num);
        vis=vector<int>(num,0),InStack=vis;

        for(auto e:proj) g[e[0]].push_back(e[1]);

        for(int i=0;i<num;i++)
        {
            if(!vis[i])
            {
                DFS(i);
                if(loop) return false;
            }
        }

        return true;
    }

    void DFS(int pre)
    {
        vis[pre]=1;
        InStack[pre]=1;

        for(int next:g[pre])
        {
            if(!vis[next] && !InStack[next]) DFS(next);

            if(InStack[next])
            {
                loop=true;
                return;
            }  
        }

        InStack[pre]=0;
    }
};
```