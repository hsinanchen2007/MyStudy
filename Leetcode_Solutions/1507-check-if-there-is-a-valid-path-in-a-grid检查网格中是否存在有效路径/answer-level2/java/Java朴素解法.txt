### 解题思路
这个题目就是很普通的dfs，其实就是稍微改变了一下形势罢了

### 代码

```java
class Solution {
    int[][] grid;
    int m;
    int n;
    Set<Integer> set1 = new HashSet<>();
    Set<Integer> set2 = new HashSet<>();
    Set<Integer> set3 = new HashSet<>();
    Set<Integer> set4 = new HashSet<>();

    public boolean hasValidPath(int[][] grid) {
        this.grid = grid;
        m = grid.length;
        if(m < 1) return false;
        n = grid[0].length;
        if(n < 1) return false;
        
        set1.add(1);
        set1.add(3);
        set1.add(4);

        set2.add(1);
        set2.add(5);
        set2.add(6);

        set3.add(2);
        set3.add(4);
        set3.add(6);

        set4.add(2);
        set4.add(3);
        set4.add(5);

        return dfs(0, 0, 0);
    }

    boolean dfs(int x, int y, int dir) {   // 进来的点 0原点 1上 2下 3左 4右
        if (x < 0 || x > m-1 || y > n-1 || y < 0) return false;
        if (dir == 1) {
            if (set1.contains(grid[x][y])) return false;
        } else if (dir == 2) {
            if (set2.contains(grid[x][y])) return false;
        } else if (dir == 3) {
            if (set3.contains(grid[x][y])) return false;
        } else if (dir == 4) {
            if (set4.contains(grid[x][y])) return false;
        }
        if (x == m - 1 && y == n - 1) return true;

        if (grid[x][y] == 1) {
            if (dir == 0 || dir == 3) {
                return dfs(x, y + 1, 3);
            } else if (dir == 4) {
                return dfs(x, y - 1, 4);
            }
        } else if (grid[x][y] == 2) {
            if (dir == 0 || dir == 1) {
                return dfs(x + 1, y, 1);
            } else if (dir == 2) {
                return dfs(x - 1, y, 2);
            }
        } else if (grid[x][y] == 3) {
            if (dir == 0 || dir == 3) {
                return dfs(x + 1, y, 1);
            } else if (dir == 2) {
                return dfs(x, y - 1, 4);
            }
        } else if (grid[x][y] == 4) {
            if (dir == 0 || dir == 4) {
                return dfs(x + 1, y, 1);
            } else if (dir == 2) {
                return dfs(x, y + 1, 3);
            }
        } else if (grid[x][y] == 5) {
            if (dir == 0 || dir == 3) {
                return dfs(x - 1, y, 2);
            } else if (dir == 1) {
                return dfs(x, y - 1, 4);
            }
        } else if (grid[x][y] == 6) {
            if (dir == 0 || dir == 1) {
                return dfs(x, y + 1, 3);
            } else if (dir == 4) {
                return dfs(x - 1, y, 2);
            }
        }
        return true;
    }
}
```