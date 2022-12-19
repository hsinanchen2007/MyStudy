### 代码

```cpp
struct UFTree{
    vector<int> tr;
    UFTree(int n):tr(n+1){
        for(int i=0;i<=n;i++)tr[i]=i;
    }
    int find(int x){
        if(tr[x]==x)return x;
        return tr[x]=find(tr[x]);
    }
    bool unite(int x,int y){
        int a=find(x),b=find(y);
        if(a==b)return true;
        tr[a]=b;
        return false;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UFTree uf(edges.size());
        for(auto &i:edges){
            if(uf.unite(i[0],i[1]))return i;
        }
        return {};
    }
};
```