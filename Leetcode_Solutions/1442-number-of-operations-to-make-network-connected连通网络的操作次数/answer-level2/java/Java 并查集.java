```java
class Solution {
        public int makeConnected(int n, int[][] connections) {
        if (connections.length < n - 1) {
            return -1;
        }
        UnionFind unionFind = new UnionFind(n);
        unionFind.init();
        for (int[] item : connections) {
            unionFind.union(item[0], item[1]);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            // 找到了一个连通分支
            if (unionFind.find(i) == i) {
                count++;
            }
        }
        return count - 1;
    }
    class UnionFind {
        public int[] parents;
        public UnionFind(int n) {
            this.parents = new int[n];
        }
        public void init() {
            for (int i = 0; i < parents.length; i++) {
                parents[i] = i;
            }
        }
        public int find(int x) {
            while (x != parents[x]) {
                parents[x] = parents[parents[x]];
                x = parents[x];
            }
            return x;
        }
        public int union(int x, int y) {
            int ux = find(x);
            int uy = find(y);
            if (ux == uy) {
                return 0;
            }
            parents[ux] = uy;
            return 1;
        }
    }
}
```