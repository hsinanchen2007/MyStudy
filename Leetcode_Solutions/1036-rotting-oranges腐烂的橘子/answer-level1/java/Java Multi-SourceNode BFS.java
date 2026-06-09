### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        Queue<Integer> orange = new ArrayDeque<>();
        Map<Integer, Integer> time = new HashMap<>();
        int length1 = grid.length;
        int length2 = grid[0].length;
        int countOf0 = 0;
        int ans = -1;
        
        for(int i = 0; i < length1; i++) {
            for(int j = 0; j < length2; j++) {
                if(grid[i][j] == 2){
                    int cnode = i * length2 + j;
                    orange.add(cnode);
                    time.put(cnode, 0);
                    ans = 0;
                }
                else if(grid[i][j] == 0){
                    countOf0++;
                }
            }
        }
        
        if(countOf0 == length1 * length2) {
            return 0;
        }
        
        while(!orange.isEmpty()) {
            int cnode = orange.remove();
            int row = cnode / length2;
            int col = cnode % length2;
            if(row-1 >= 0 && grid[row-1][col] == 1) {
                grid[row-1][col] = 2;
                int ccnode = (row-1) * length2 + col;
                orange.add(ccnode);
                time.put(ccnode, time.get(cnode) + 1);
                ans = time.get(ccnode);
            }
            if(row+1 < length1 && grid[row+1][col] == 1) {
                grid[row+1][col] = 2;
                int ccnode = (row+1) * length2 + col;
                orange.add(ccnode);
                time.put(ccnode, time.get(cnode) + 1);
                ans = time.get(ccnode);
            }
            if(col-1 >= 0 && grid[row][col-1] == 1) {
                grid[row][col-1] = 2;
                int ccnode = row * length2 + col - 1;
                orange.add(ccnode);
                time.put(ccnode, time.get(cnode) + 1);
                ans = time.get(ccnode);
            }
            if(col+1 < length2 && grid[row][col+1] == 1) {
                grid[row][col+1] = 2;
                int ccnode = row * length2 + col + 1;
                orange.add(ccnode);
                time.put(ccnode, time.get(cnode) + 1);
                ans = time.get(ccnode);
            }
        }
        
        for(int[] row : grid) {
            for(int col : row){
                if(col == 1){
                    return -1;
                }
            }
        }
        
        return ans;
        
    }
}
```