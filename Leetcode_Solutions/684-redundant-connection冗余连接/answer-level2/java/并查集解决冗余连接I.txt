此题使用并查集比较容易解决。

对于同一棵树的所有节点来说，都拥有共同的祖先节点。  
因此，判断冗余连接的条件即为，判断新加入的边，两个节点是否有共同的祖先。  
（1）如果有共同的祖先，则说明这条边是冗余的边；  
（2）如果没有共同的祖先，则说明这两条边并未加入树中，因此进行合并操作。  
循环边的记录，获取最后出现的冗余边，就是答案。

```
    public static class UnionFind {
        int[] parent;
        int[] rank;

        public UnionFind(int total) {
            parent = new int[total];
            rank = new int[total];

            for (int i = 0; i < total; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        public int find(int x) {
            while (x != parent[x]) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        public void unionElements(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);

            if (pRoot == qRoot) {
                return;
            }

            if (rank[pRoot] < rank[qRoot]) {
                parent[pRoot] = qRoot;
            } else if (rank[pRoot] > rank[qRoot]) {
                parent[qRoot] = pRoot;
            } else {
                parent[pRoot] = qRoot;
                rank[qRoot] += 1;
            }
        }
    }

    public int[] findRedundantConnection(int[][] edges) {
        int[] res = new int[2];
        UnionFind unionFind = new UnionFind(edges.length);

        // 第一条边肯定未记录至树中，可直接合并节点
        unionFind.unionElements(edges[0][0] - 1, edges[0][1] - 1);
        for (int i = 1; i < edges.length; i++) {
            if (unionFind.find(edges[i][0] - 1) == unionFind.find(edges[i][1] - 1)) {
                res[0] = edges[i][0];
                res[1] = edges[i][1];
            } else {
                unionFind.unionElements(edges[i][0] - 1, edges[i][1] - 1);
            }
        }
        return res;
    }
```
