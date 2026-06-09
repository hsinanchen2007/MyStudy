![image.png](https://pic.leetcode-cn.com/2278dcf571696418f164419e50fc94cc21c53ee1dc16ef8d4455f5a6f5ec160a-image.png)

并查集：用来检测一个图里面是不是包含有环，在Kruskal算法（最小生成树）里面有非常重要的作用。

PS: rank用来解决极端情况，减少树的高度。

```
public class Disjoint {
    private int[] rank;   // 节点的高度
    private int[] parent; // 节点的父节点

    public int[] findRedundantConnection(int[][] edges) {
        if (edges == null || edges.length == 0) {
            return null;
        }

        this.initial(edges.length);

        for (int[] edge : edges) {
            if (!unionRoot(edge[0] - 1, edge[1] - 1)) {
                return edge;
            }
        }

        return new int[2];
    }

    private void initial(int len) {
        this.rank = new int[len];
        this.parent = new int[len];

        for (int i = 0; i < len; i++) {
            parent[i] = -1;
        }
    }

    private int findRoot(int val) {
        int valRoot = val;

        while (parent[valRoot] != -1) {
            valRoot = parent[valRoot];
        }

        return valRoot;
    }

    private boolean unionRoot(int x, int y) {
        int xRoot = findRoot(x);
        int yRoot = findRoot(y);

        if (xRoot == yRoot) {
            return false;
        } else {
            if (rank[xRoot] > rank[yRoot]) {
                parent[yRoot] = xRoot;
            } else if (rank[yRoot] > rank[xRoot]) {
                parent[xRoot] = yRoot;
            } else {
                parent[xRoot] = yRoot;
                rank[xRoot]++;
            }

            return true;
        }
    }
}
```
