1. 贪心算法，进行铺设管道，最小生成树.
2. 我们假设村里面只有房间0有水，则所有的建造水井的成本即为房间i到房间0铺设的管道的成本，则该问题转变成了求所有节点（0~n）的图中的最小生成树问题。
3. 我们将所有的边进行合并，然后采用kruskal或者prim算法求最小生成树即可。 

```c++ []
lass Solution {
public:    
    static int find(vector<int> & f,int x){
        while(x != f[x]){
            x = f[x];
        }
        
        return x;
    }
    
    static bool uni(vector<int> &f,int x,int y){
        int x1 = find(f,x);
        int y1 = find(f,y);
        f[x1] = y1;
        
        return true;
    }
    
    static bool cmp(vector<int> & a,vector<int> & b){
        return a[2] < b[2];
    }
    
        
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<int> f(n+1,0);
        int ans = 0;
        
        for(int i = 0;i <= n; ++i){
            f[i] = i;
        }
        
        for(int i = 0;i < wells.size(); ++i){
            pipes.push_back(vector<int>({0,i+1,wells[i]}));
        }
        sort(pipes.begin(),pipes.end(),cmp);
        
        for(auto &v : pipes){
            if(find(f,v[0]) == find(f,v[1])){
                continue;
            }
            
            ans += v[2];
            uni(f,v[0],v[1]);
        }
        
        return ans;
    }
};
```
```java []

```
```python []

```
