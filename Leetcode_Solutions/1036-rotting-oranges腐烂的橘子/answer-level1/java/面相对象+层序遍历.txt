### 解题思路
此处撰写解题思路
面相对象+层序遍历
### 代码

```java
class Solution {
     class Direction{
        private int col ;
        private int row;
        public Direction(int r ,int c){
            this.col = c;
            this.row = r;
        }
    }
    private int[][] directions={{1,0},{-1,0},{0,1},{0,-1}};
    private int res = 0;
    private int c ;
    private int r;
    public int orangesRotting(int[][] grid) {
        int count = 0;
        Queue<Direction> queue = new LinkedList<>();
        r = grid.length;
        c = grid[0].length;
        for (int i = 0 ; i < r ; i ++){
            for (int j = 0 ; j < grid[0].length ; j++){
                if (grid[i][j] == 2){
                    queue.add(new Direction(i,j));
                }
                if (grid[i][j] == 1){
                    count++;
                }
            }
        }
        while (count > 0 && !queue.isEmpty()){
            int size = queue.size();
            boolean flag = false;
             while (size > 0){
                Direction poll = queue.poll();
                for (int[] d : directions){
                    int row = d[0]+poll.row;
                    int col = d[1] + poll.col;
                    if (row < r && col < c && row >= 0 && col >= 0){
                        if( grid[row][col] == 1){
                            queue.add(new Direction(row,col));
                            count--;
                            grid[row][col] = 2;
                            flag = true;
                        }
                    }
                }
                size--;
            }
            if (flag){
                res++;
            }
        }
        if(res == 0 && count == 0){
            return res;
        }
        if(count != 0){
            return -1;
        }
        return res;
    }
}
```