### 解题思路
    la la la 打卡学习 ~ ~ ~ 
    解析就在代码中
### 代码
```cpp
class Solution {
public:
    vector<int> parents;
    vector<int> rank;

    //带路径压缩的查找
    int find(int x){
        if(x != parents[x]) //如果不是根节点，让父节点等于父节点的父节点
            parents[x] = find(parents[x]);
        return parents[x];  //返回父节点的值
    }

    //按秩合并x,y所在的集合
    void Union(int x,int y){
        //秩小的集合 合并到 秩大的集合
        if(rank[x] > rank[y]) parents[y] = x;
        else if(rank[y] > rank[x]) parents[x] = y;

        //秩相等时，随意将一个集合合并到另一个集合，并将合并之后的秩更新（加1）
        else{
            parents[x] = y;
            ++rank[y];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int m = edges.size();
        parents = vector<int>(m+1);
        rank = vector<int>(m+1);

        //初始化parents 和 rank数组
        for(auto edge : edges){
            parents[edge[0]] = edge[0],parents[edge[1]] = edge[1];
            rank[edge[0]] = rank[edge[1]] = 0;
        }
        //判断每条边的两个顶点是否属于同一集合
        for(vector<int> edge : edges){
            int x = find(edge[0]),y = find(edge[1]);
            if(x == y) return edge;
            else Union(x,y);
        }
        return {-1,-1};
    }
};
```