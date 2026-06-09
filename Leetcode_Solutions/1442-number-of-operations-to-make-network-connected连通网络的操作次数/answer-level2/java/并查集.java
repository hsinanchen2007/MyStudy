思路：这种连通性问题，比较容易想到使用并查集，并查集在写的时候，可以尽量封装起来，以凸显主干逻辑。并且路径压缩与按 `rank` 合并这两个优化技巧，选择其中一个即可。

+ 记录一个变量，表示多余的边；
+ 在合并的时候，返回是否合并成功。如果合并不成功，表示在一个连通分量里，这条边是多余的边（用于以后连接独立的连通分量）；
+ 如果多余的边不够剩余的连通分量个数，返回 -1；如果够用，每用一条边都可以减少一个连通分量的个数；
+ 否则多余的边数够用，返回连通分量 -1 即可（减去的这个 1 是最大的那个连通分量）。

**参考代码**：

```Java []
public class Solution {

    private class UnionFind {
        /**
         * 父亲结点标识数组
         */
        private int[] parent;
        /**
         * 连通分量个数
         */
        private int count;

        public UnionFind(int n) {
            count = n;
            parent = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        public int find(int x) {
            while (x != parent[x]) {
                // 路径压缩（隔代压缩）
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        /**
         * @param x
         * @param y
         * @return 是否合并成功，如果 x 和 y 本来就在一个连通分量里，返回 false
         */
        public boolean union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX == rootY) {
                return false;
            }

            parent[rootX] = rootY;
            count--;
            return true;
        }
    }

    public int makeConnected(int n, int[][] connections) {
        // 特判
        if (connections.length < n - 1) {
            return -1;
        }

        UnionFind unionFind = new UnionFind(n);

        // 多余的边的条数
        int cnt = 0;

        for (int[] connection : connections) {
            boolean success = unionFind.union(connection[0], connection[1]);
            if (!success) {
                cnt++;
            }
        }

        // 特判
        if (unionFind.count == 1) {
            return 0;
        }

        // 扣掉的 1 是当前结点数最大的连通分量
        if (cnt < unionFind.count - 1) {
            return -1;
        }
        return unionFind.count - 1;
    }
}
```