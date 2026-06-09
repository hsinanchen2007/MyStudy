```
class Solution {
    public int maxAreaOfIsland(int[][] grid) {

        int maxArea = 0;
        int area = 0;
        // 坐标队列
        Queue<Integer> i_loc = new LinkedList<>();
        Queue<Integer> j_loc = new LinkedList<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    i_loc.add(i);
                    j_loc.add(j);
                    grid[i][j] = 0;
                }
                while (!i_loc.isEmpty()) {
                    int iTemp = i_loc.poll();
                    int jTemp = j_loc.poll();
                    ++area;
                    // 上
                    if (iTemp > 0 && grid[iTemp - 1][jTemp] == 1){
                        i_loc.add(iTemp - 1);
                        j_loc.add(jTemp);
                        grid[iTemp - 1][jTemp] = 0;
                    }
                    // 下
                    if (iTemp < grid.length - 1 && grid[iTemp + 1][jTemp] == 1) {
                        i_loc.add(iTemp + 1);
                        j_loc.add(jTemp);
                        grid[iTemp + 1][jTemp] = 0;
                    }
                    // 左
                    if (jTemp > 0 && grid[iTemp][jTemp - 1] == 1) {
                        i_loc.add(iTemp);
                        j_loc.add(jTemp - 1);
                        grid[iTemp][jTemp - 1] = 0;
                    }
                    // 右
                    if (jTemp < grid[0].length - 1 && grid[iTemp][jTemp + 1] == 1) {
                        i_loc.add(iTemp);
                        j_loc.add(jTemp + 1);
                        grid[iTemp][jTemp + 1] = 0;
                    }
                }
                if (area > maxArea) maxArea = area;
                area = 0;
            }
        }
        
        return maxArea;
    }
}
```
