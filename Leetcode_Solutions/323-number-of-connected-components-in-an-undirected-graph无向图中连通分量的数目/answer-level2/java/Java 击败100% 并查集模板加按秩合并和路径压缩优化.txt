并查集模板题, 加上了按秩合并和路径压缩优化
学习并查集可以看labuladong这篇:
https://github.com/labuladong/fucking-algorithm/blob/master/%E7%AE%97%E6%B3%95%E6%80%9D%E7%BB%B4%E7%B3%BB%E5%88%97/UnionFind%E7%AE%97%E6%B3%95%E8%AF%A6%E8%A7%A3.md
```
class Solution {
    private int[] parent; // 父节点
    private int[] rank; // 秩
    public int countComponents(int n, int[][] edges) {
        parent = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
        for(int i = 0; i < edges.length; i++){
            union(edges[i][0], edges[i][1]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(i == parent[i]) ans++;
        }
        return ans;
    }

    private void union(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px != py){  // 按秩合并
            if(rank[px] > rank[py]){
                parent[py] = px;
                rank[px] += rank[py];
            }else{
                parent[px] = py;
                rank[py] += rank[px];
            }
        }
    }

    private int find(int x){
        while(x != parent[x]){ 
            parent[x] = parent[parent[x]]; //路径压缩
            x = parent[x];
        }
        return x;
    }
}
```
