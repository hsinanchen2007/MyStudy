本题中需要找到多余的一条边，这条边刚好使得树变成图。
所以我们可以把问题转化为求最小生成树。

最小生成树的算法有两个：prim算法和Kruskal算法。这里我选择了Kruskal算法。

Kruskal算法描述的是：选择不构成环的边，加入到边集合中，直到所有的结点都相连。

代码如下：

```c++
class Solution {
    int prev[1005];
public:
    int find(int n) {
        int x = n;
        while (prev[x] != x) x = prev[x];
        // while (prev[n] != x) {
        //     int t = prev[n];
        //     prev[n] = x;
        //     n = t;
        // }
        return x;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i = 0; i <= edges.size(); i++) {
            prev[i] = i;
        }
        for (int i = 0; i < edges.size(); i++) {
            int ni = find(edges[i][0]);
            int nj = find(edges[i][1]);
            
            if (ni != nj) {
                prev[ni] = nj;
            } else 
                return edges[i];
        }
        vector<int> ans;
        return ans;
    }
};
```



复杂度分析：
O(E*V), 其中E是边的数量，V是结点数量。

运行结果：
![image.png](https://pic.leetcode-cn.com/624048b0f9ac95f630bc6f55f5a8a25774efc82ae72f1c5f4be4f0be4eadb3e4-image.png)
