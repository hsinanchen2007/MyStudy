做了一个gif(yeah!)这个gif是根据这道题的思路做的，首先将陆地放到queue中，然后遍历它的前后左右，如果是海洋就入队，并且将其做访问标记，防止重复访问（可能会导致层数增多？），然后直到队列为空，这时返回记录的depth，也就是访问了多少层，就是最长路径了。
![演示文稿1.gif](https://pic.leetcode-cn.com/32aa507a63ab95cf483581eeecbe84ca86cf431e085a7cabc72650b208bf2984-%E6%BC%94%E7%A4%BA%E6%96%87%E7%A8%BF1.gif)

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        Queue<int[] > q = new ArrayDeque();
        int N = grid.length;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                if(grid[i][j] == 1)
                    q.add(new int[]{i, j});
            }
        if(q.isEmpty() || q.size() == N * N)
            return -1;
        int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int depth = -1;
        while(!q.isEmpty()){
            depth++;
            int n = q.size();
            for(int i = 0; i < n; i++){
                int[] s = q.poll();
                int r = s[0];
                int c = s[1];
                for(int[] direction: directions){
                    int x = r + direction[0];
                    int y = c + direction[1];
                    if( x >= 0 && x < N && y >=0 && y < N && grid[x][y] == 0){
                        grid[x][y] = 2;
                        q.add(new int[]{x, y});
                    }
                }
            }
        }
        return depth;
    }
}
```