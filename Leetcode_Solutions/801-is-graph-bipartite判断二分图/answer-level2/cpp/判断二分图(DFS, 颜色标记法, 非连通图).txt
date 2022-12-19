### 解题思路

### 代码

```cpp
class Solution {
public:
    int white=0,red=1,bule=2;
    vector<int> color;
    bool can;

    bool isBipartite(vector<vector<int>>& graph) 
    {
        color=vector<int>(graph.size(),white);

        for(int i=0;i<graph.size();i++)
        {
            if(!graph[i].empty() && color[i]==white) 
            {
                can=true;
                DFS(graph,i,red);
                if(!can) return false;
            }
        } 

        return true;
    }

    void DFS(vector<vector<int>>& graph,int pre,int col)
    {
        color[pre]=col;

        for(int next:graph[pre])
        {
            if(color[next]==color[pre]) can=false;
            if(color[next]==white)
            {
                if(col==red) DFS(graph,next,bule);
                else DFS(graph,next,red);
            }
        }
    }
};
```