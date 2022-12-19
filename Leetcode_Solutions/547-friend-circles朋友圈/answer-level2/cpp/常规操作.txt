### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int>fa;
    unordered_map<int,int>rank;
    int find(int x)
    {
        int t = x;
        while(x!=fa[x])
            x = fa[x];
        while(t!=x)
        {
            int z = fa[t];
            fa[t] = x;
            t = z;
        }
        return x;
    }
    void Union(int x,int y)
    {
        int fa_x = find(x);
        int fa_y = find(y);
        if(fa_x != fa_y)
        {
            int big = rank[fa_x]>=rank[fa_y] ? fa_x : fa_y;
            int small = big==fa_x ? fa_y : fa_x;
            fa[small] = big;
            rank[big]+= rank[small];
            rank.erase(small);
            
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty()) return 0;
        int N = M.size();
        fa.resize(N);
        for(int i=0;i<N;++i) 
        {
            fa[i] = i;
            rank[i] = 1;
        }
        for(int i=0;i<N;++i)
            for(int j=i+1;j<N;++j)
            {
                if(M[i][j])
                    Union(i,j);
            }
        return rank.size();
        
    }
};
```