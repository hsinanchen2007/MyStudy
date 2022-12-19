### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int>fa;
    int find(int x)
    {
        while(x!=fa[x])
            x = fa[x];
        return x;
    }
    bool Union(int x,int y)
    {
        int fa_x = find(x);
        int fa_y = find(y);
        if(fa_x!=fa_y)
        {
            fa[fa_x] = fa_y;
            return true;
        }
        return false;
        
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // 分两种情况：1.没有节点有两个父亲，说明成环了，与无向图的情况相同，去掉形成环的最后一条边
        // 2.有节点有两个父亲。删除的边必属其中之一。选定一条后去掉，若图有效，则结束；否则说明该去掉另一条
        if(edges.empty()) return vector<int>{};
        int n = edges.size();
        vector<int>degree(n+1,0);
        int a,b;
        int find = 0;
        for(auto i:edges)
        {
            degree[i[1]]++;
            if(degree[i[1]]==2)
            {
                a = i[0];
                b = i[1];
                find = 1;
                break;
            }   
        }
        
        // 初始化所有节点为单独的连通块
        fa.resize(n+1);
        for(int i=1;i<=n;++i) fa[i] = i;
        
        // 所有点入度均为1
        if(!find)
        {
            
            for(auto i:edges)
            {
                if(!Union(i[0],i[1])) return vector<int>{i[0],i[1]};
            }
        }
        
        // 出现某节点有两父亲的情况
        // 判定去掉所选边后,图是否有效
        
        for(auto i:edges)
        {
            if((i[0]==a) && (i[1]==b)) continue;
            // 去掉选定边仍连通，说明该去掉另一条
            if(!Union(i[0],i[1]))
            {
                for(int i=0;i<edges.size();++i)
                    if(edges[i][1]==b && edges[i][0]!=a) return vector<int>{edges[i][0],edges[i][1]};
            }
        }
        return vector<int>{a,b};
        
    }
};
```