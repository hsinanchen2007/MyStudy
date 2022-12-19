### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    public List<List<Integer>> pacificAtlantic(int[][] matrix) {
        List<List<Integer>> ret = new ArrayList<>();
        int height = matrix.length;
        if(height == 0){
            return ret;
        }
        int width = matrix[0].length;
        if(width == 0){
            return ret;
        }

        // 我的思路：找到与太平洋相连的点，再找到与大西洋相连的点，两者的交点即为想要的答案
        // mark1标记太平洋
        boolean[][] mark1 = new boolean[height][width];
        // mark2标记大西洋
        boolean[][] mark2 = new boolean[height][width];
        for(int col = 0; col < width; col++){
            dfs(new int[]{0, col}, matrix, mark1);
            dfs(new int[]{height-1, col}, matrix, mark2);
        }
        for(int row = 0; row < height; row++){
            dfs(new int[]{row, 0}, matrix, mark1);
            dfs(new int[]{row, width-1}, matrix, mark2);
        }
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(mark1[i][j] && mark2[i][j]){
                    List<Integer> list = new ArrayList<>();
                    list.add(i);
                    list.add(j);
                    ret.add(list);
                }
            }
        }
        return ret;
    }
    private void dfs(int[] point, int[][] matrix, boolean[][] mark){
        int height = matrix.length;
        int width = matrix[0].length;
        int oldValue = matrix[point[0]][point[1]];
        mark[point[0]][point[1]] = true;
        for(int[] direction : directions){
            int x = point[0] + direction[0];
            int y = point[1] + direction[1];
            if(x >= 0 && x < height && y >= 0 && y < width && !mark[x][y] && matrix[x][y] >= oldValue){
                dfs(new int[]{x, y}, matrix, mark);
            }
        }
    }
}
```