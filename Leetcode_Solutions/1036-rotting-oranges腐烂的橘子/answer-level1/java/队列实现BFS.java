### 解题思路
腐烂的橘子影响四周的新鲜橘子，受到影响的橘子又会继续影响其四周的新鲜橘子
=>有层次关系=>BFS
BFS范式：
=>申请队列，并初始化；
=>while(队列不为空)：
    x = 取出队头元素;
    if(x的周边元素满足某条件)
        满足条件的元素入队;
        状态更新;
本题：
=>关键点是每次入队列的时候，不仅要将当前橘子的坐标入队，还要将处理该橘子腐烂的时间time入队！！！！！    
### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {  
        int rows = grid.length;//行数
        int cols = grid[0].length;//列数

        int count = 0;//新鲜橘子的数量
        int time = 0;
        //用队列实现BFS
        Queue<int[]> queue = new LinkedList<int[]>();

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){//记录新鲜橘子数量
                    count++;
                }
                if(grid[i][j] == 2){
                    queue.offer(new int[]{i, j, time});//队列不仅记录坐标，还记录处理这个橘子的时间
                }
            }
        }

        int[][] dir = {{0,1},{0,-1},{-1,0},{1,0}};//上下左右
        while(queue.peek() != null){//队列不为空，peek()函数返回头部元素，若队列为空，则返回null
            int[] elem = queue.poll();//poll()函数取出队列头元素（从队列移除）
            int x = elem[0];
            int y = elem[1];
            time = elem[2];
            //判断该位置上下左右是否有新鲜橘子
            for(int k = 0; k < dir.length; k++){
                int newx = x + dir[k][0];
                int newy = y + dir[k][1];
                if(newx < rows && newy < cols && newx >= 0 && newy >= 0){//数组没有越界
                    if(grid[newx][newy] == 1){
                        queue.offer(new int[]{newx, newy, time + 1});//此处更新时间为time+1!!!!!!!
                        grid[newx][newy] = 2;//此处标记为腐烂橘子
                        count--;//新鲜橘子数目减一
                    }
                }
            }
        }

        if(count > 0){//还有新鲜橘子
            return -1;
        }
        return time;        
    }
}
```