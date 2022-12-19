### 解题思路
与其他bfs不同的是，这里使用了一个无用的Integer MAXVALUE来区分bfs不同的层级。一遍过开心。

### 代码

```java
class Solution {
public int orangesRotting(int[][] grid) {
        Queue<Integer> rot = new LinkedList<>();
        int count = 0;
        int row = grid.length;
        int col = grid[0].length;
        for (int i = 0; i<row; i++){
            for (int j = 0; j < col; j++) {
                if (grid[i][j]==1) {
                    count++;
                }
                if (grid[i][j]==2) {
                    rot.offer(11*i+j);
                }
            }
        }
        if (count == 0) {
            return 0;
        }
        if (rot.size() == 0) {
            return -1;
        }
        rot.offer(Integer.MAX_VALUE);
        int res = 0;
        //TODO find a better way to indicate the level of BFS
        while (rot.size()!=1){
            Integer cmp = rot.poll();
            if (cmp==Integer.MAX_VALUE){
                res++;
                rot.offer(Integer.MAX_VALUE);
                continue;
            }
            int i = cmp/11;
            int j = cmp%11;
            if (i > 0 && grid[i - 1][j] == 1) {
                rot.offer(11*(i-1)+j);
                grid[i-1][j]=2;
                count--;
            }
            if (j > 0 && grid[i][j - 1] == 1) {
                rot.offer(11*i+j-1);
                grid[i][j-1]=2;
                count--;
            }
            if (i < row - 1 && grid[i + 1][j] == 1) {
                rot.offer((i + 1) * 11 + j);
                grid[i+1][j] = 2;
                count--;
            }
            if (j < col - 1 && grid[i][j + 1] == 1) {
                rot.offer(i * 11 + j + 1);
                grid[i][j+1] = 2;
                count--;
            }
        }
        if (count != 0) {
            return -1;
        }
        return res;
    }
}
```