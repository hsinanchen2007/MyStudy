### 解题思路
有点Kruskal算法的意思

### 代码

```cpp
class Solution {
public:
    int find(int n,int *dis){
        int i=n;
        while(dis[i]!=i){
            i=dis[i];
        }
        int j;
        while(n!=i){
            j=dis[n];
            dis[n]=i;
            n=j;
        }
        return i;
    }
    int judge(vector<int> v,int *dis)
    {
        int x=find(v[0],dis);
        int y=find(v[1],dis);
        if(x!=y){
            dis[y]=x;return 0;
        } 
        return 1;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> res;
        int dis[n+1];
        for(int i=1;i<=n;i++) dis[i]=i;
        for(int i=0;i<n;i++){
            if(judge(edges[i],dis)) res=edges[i];
        }
        return res;
    }
};
```