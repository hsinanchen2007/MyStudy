```
class Solution {
    public int countCornerRectangles(int[][] grid) {
        int rs = 0;
        for(int r = 0; r < grid.length; ++ r) {
            for(int c = 0; c < grid[0].length; ++ c) {
                if(grid[r][c] == 0)
                    continue;
                // left = (r,c)
                // right = (r, cc)
                for(int rc = c + 1; rc < grid[0].length; ++ rc) {
                    if(grid[r][rc] == 0)
                        continue;
                    // right = (r, cc)
                    for(int dr = r + 1; dr < grid.length; ++ dr) {
                        if(grid[dr][c] == 0 || grid[dr][rc] == 0)
                            continue;
                        // down = (dr, c)
                        rs ++;
                    }
                }
            }
        }
        return rs;
    }
}
```
