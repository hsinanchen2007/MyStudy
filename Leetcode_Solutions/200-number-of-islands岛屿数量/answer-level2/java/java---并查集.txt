```
class Solution {
    // 并查集
    // 遍历一次得到所有的集合，然后再遍历一次得到集合的数量
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        int row = grid.length, col = grid[0].length;
        UnionFind uf = new UnionFind(row * col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                if (i > 0 && grid[i - 1][j] == '1') {
                    uf.union(i * col + j, (i - 1) * col + j);
                }
                if (i < row - 1 && grid[i + 1][j] == '1') {
                    uf.union(i * col + j, (i + 1) * col + j);
                }
                if (j > 0 && grid[i][j - 1] == '1') {
                    uf.union(i * col + j, i * col + j - 1);
                }
                if (j < col - 1 && grid[i][j + 1] == '1') {
                    uf.union(i * col + j, i * col + j + 1);
                }
            }
        }

        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    set.add(uf.find(i * col + j));
                }
            }
        }
        return set.size();
    }

    class UnionFind{
        int[] pre;

        UnionFind(int capacity) {
            pre = new int[capacity];
            for (int i = 0; i < capacity; i++) {
                pre[i] = i;
            }
        }
        
        int find(int x) {
            int son = x;
            while (x != pre[x]) {
                x = pre[x];
            }
            while (son != x) {
                int tmp = pre[son];
                pre[son] = x;
                son = tmp;
            }
            return x;
        }

        void union(int x, int y) {
            int root1 = find(x), root2 = find(y);
            if (root1 != root2) {
                pre[root1] = pre[root2];
            } 
        }
    }
}

```