### 解题思路

并查集

### 代码

```cpp
struct Uft{
    vector<int> tr;
    Uft(int n):tr(n+1){
        for(int i=1;i<=n;i++)tr[i]=i;
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
    int sig[1001][2];
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        memset(sig,0,sizeof sig);
        Uft uf(edges.size());
        int in2=0,out3=0;
        for(auto &i:edges){
            if(++sig[i[0]][1]==3)out3=i[0];
            if(++sig[i[1]][0]==2)in2=i[1];
        }
        if(in2){
                vector<vector<int>> tp;
                for(auto &i:edges){
                    if(i[1]==in2)tp.push_back(i);
                    else uf.unite(i[0],i[1]);
                }
                if(uf.unite(tp[0][0],tp[0][1])==false)return tp.back();
                return tp.front();
        }else{
            for(auto &i:edges){
                if(uf.unite(i[0],i[1]))return i;
            }return {};
        }
    }
};
```