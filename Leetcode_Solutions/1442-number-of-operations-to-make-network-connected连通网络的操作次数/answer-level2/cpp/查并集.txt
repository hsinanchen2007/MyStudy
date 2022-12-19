### 解题思路
已知n个点必须要n-1个线完成连接,使用查并集,得到不会造成圈的线的个数(有效连线),使用n-1减去有效连线得到最少需要移动几个线,即最少操作次数.
此处附上B站某UP讲解查并集视频:https://www.bilibili.com/video/av38498175
### 代码

```cpp
class Solution {
public:
    int find(int p, int parent[])
    {
        int p_root = p;
        while(parent[p_root] != -1){
            p_root = parent[p_root];
        }
        return p_root;
    }
    bool union_vertices(int p,int q,int parent[],int rank[]){
        int x = find(p,parent);
        int y = find(q,parent);
        if(x == y)
            return false;
        else{
            if(rank[x] > rank[y])
                parent[x] = y;
            else if(rank[y] > rank[x])
                parent[y] = x;
            else{
                rank[y] +=1;
                parent[y] = x;
            }
            return true;
        }
        
    }
    void init(int parent[],int rank[],int n){
        for(int i = 0;i<n;i++)
        {
            parent[i] = -1;
            rank[i] = 0;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size() < n-1) return -1;
       int parent[n] = {-1};
       int rank[n] = {0};
       int count = 0;
       init(parent,rank,n);
       for(auto c : connections)
       {
           if(union_vertices(c[0],c[1],parent,rank) == true)
                count++;
       }
       return n-count-1;
    }
};
```