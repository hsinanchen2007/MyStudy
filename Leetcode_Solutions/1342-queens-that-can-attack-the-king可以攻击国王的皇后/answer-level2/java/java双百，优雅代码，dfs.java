### 解题思路
很简单的dfs，刚看到的时候以为是bfs呢，bfs方向不会控制

### 代码

```java
class Solution {
    
    private boolean isInArea(int[][] grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[0].length)
            return false;
        return true;
    }
    
    public List<List<Integer>> queensAttacktheKing(int[][] queens, int[] king) {
        List<List<Integer>> ans = new ArrayList<>();
        int[][] dicts = new int[][]{{1, 1}, {-1, 1}, {-1, -1}, {1, -1}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int[][] chess = new int[8][8];
        for (int[] queen : queens) {
            chess[queen[0]][queen[1]] = 1;
        }

        for (int[] dict : dicts) {
            queensAttacktheKingDFS(chess, dict, king[0], king[1], ans);
        }
        return ans;
    }

    public void queensAttacktheKingDFS(int[][] chess, int[] dict, int x, int y, List<List<Integer>> ans) {
        int newx = x + dict[0];
        int newy = y + dict[1];
        if (!isInArea(chess, newx, newy))
            return;
        if (chess[newx][newy] == 1) {
            List<Integer> list = new ArrayList<>();
            list.add(newx);
            list.add(newy);
            ans.add(list);
            return;
        }
        queensAttacktheKingDFS(chess, dict, newx, newy, ans);
    }
  
}
```