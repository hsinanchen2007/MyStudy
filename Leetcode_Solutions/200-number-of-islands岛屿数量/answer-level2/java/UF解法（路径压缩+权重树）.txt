## 并查集解法

```java
class UFSolution {
    private char[][] mGrid;
        private int mRows;
        private int mCols;

        public int numIslands(char[][] grid) {
            if (grid == null || grid.length <= 0) return 0;
            mRows = grid.length;
            mCols = grid[0].length;
            if(mCols <= 0) return 0;
            mGrid = grid;
            UF uf = new UF(mRows * mCols);
            int zeroCount = 0;
            for (int r = 0; r < mRows; r++)
                for (int c = 0; c < mCols; c++) {
                    if (mGrid[r][c] == '0') zeroCount++;
                    if (isIsland(r, c)) {
                        // left
                        if (isIsland(r, c - 1)) uf.union(xy2Index(r, c), xy2Index(r, c - 1));
                            // top
                        if (isIsland(r - 1, c)) uf.union(xy2Index(r, c), xy2Index(r - 1, c));
                            // right
//                        if (isIsland(r, c + 1)) uf.union(xy2Index(r, c), xy2Index(r, c + 1));
                            // bottom
//                        if (isIsland(r + 1, c)) uf.union(xy2Index(r, c), xy2Index(r + 1, c));
                    }
                }
            return uf.count() - zeroCount;
        }

        /**
         * Check if it is an island
         *
         * @param x
         * @param y
         * @return
         */
        private boolean isIsland(int x, int y) {
            boolean inArea = x >= 0 && x < mRows && y >= 0 && y < mCols;
            return inArea && mGrid[x][y] == '1';
        }

        private int xy2Index(int x, int y) {
            return x * mCols + y;
        }

        /**
 * 并查集
 * 加权、路径压缩优化
 */
public static class UF {
    private int[] roots;
    private int[] sz;  // size of component for roots (site indexed)
    private int count;

    public UF(int n) {
        count = n;
        roots = new int[count];
        sz = new int[count];
        for (int i = 0; i < n; i++) {
            roots[i] = i;
            sz[i] = 1;
        }
    }

    public void union(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot) return;
        if (sz[pRoot] < sz[qRoot]) {
            // connect p to q
            roots[pRoot] = qRoot;
            sz[qRoot] += sz[pRoot];
        } else {
            // connect q to p
            roots[qRoot] = pRoot;
            sz[pRoot] += sz[qRoot];
        }
        count--;
    }

    public int find(int p) {
        while (p != roots[p]) p = roots[p];
        int root = p;
        // path compression
        while (p != roots[p]) {
            int nextP = roots[p];
            roots[p] = root;
            p = nextP;
        }
        return root;
    }

    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    public int count() {
        return count;
    }
  }
}
```