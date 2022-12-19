使用BFS算法，计算当前脏橘子的上下左右四个方向有没有新鲜橘子，如果有就加入队列，这个想法很容易想到，但是这样会出现一个问题，就是不能分清楚哪些橘子应该是这一轮正在感染的，哪些橘子应该是下一轮去感染别的橘子的。我在这里卡了很久，最后看了别人的题解，得出了答案
思路是这样的：每一轮感染之前都计算一下队列里面的脏橘子个数，假设为k，用局部变量保存起来，以免之后在感染别的橘子时队列长度变化影响了之前统计的橘子数目，然后用循环遍历出这一轮去感染别的橘子的脏橘子数目，总共遍历k次，因为上一轮被感染的橘子有k个，这一轮就轮到这k个橘子去感染别的橘子，那么之后的橘子再加入队列时不会受到影响，因为我们在一开始就记录了应该弹出队列的橘子个数应该是k个。
```
class Solution {
    public int orangesRotting(int[][] grid) {
        int res = 0;
        int cnt = 0;
        int[][] position = {{-1,0},{0,1}, {1,0}, {0, -1}};
        Queue<int[]> queue = new LinkedList<int[]>();
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                if(grid[i][j] == 2)
                    queue.offer(new int[]{i, j});
                else if(grid[i][j] == 1)
                    cnt++;
            }
        }
        if((queue.isEmpty() && cnt != 0))
            return -1;
        if(!queue.isEmpty() && cnt == 0)
            return 0;
        while(!queue.isEmpty()){
            if(cnt == 0){return res;}
            res++;
            //每一轮都要将当前队列的所有脏橘子污染别的橘子
            int n = queue.size();
            for(int index = 0; index < n; index++){
                int[] bad = queue.poll();
                for(int i = 0; i < 4; i++){
                    int newPos_X = bad[0] + position[i][0];
                    int newPos_Y = bad[1] + position[i][1];
                    if((newPos_X >= 0 && newPos_X < grid.length) && (newPos_Y >= 0 && newPos_Y < grid[0].length)){
                        if(grid[newPos_X][newPos_Y] == 1){
                            grid[newPos_X][newPos_Y] = 2;
                            cnt--;
                            queue.offer(new int[]{newPos_X, newPos_Y});
                        }
                    }
                }
            }
        }
        return cnt == 0 ? res : -1;
    }
}
```
