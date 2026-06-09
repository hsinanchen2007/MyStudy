### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {

        //先计算grid中有多少个2，让他们入队
        //计算grid中有多少个1，记录新鲜橘子的个数，腐烂一个就--，看最后新鲜橘子数目是否为0
        //为0，就return-1，不为零，就return 腐烂的轮数

        //新建腐烂橘子的队列
        Queue<int[]> queue = new LinkedList<>();
        //记录grid的行和列长度
        int row = grid.length;
        int col = grid[0].length;
        //初始化新鲜橘子的数目
        int number = 0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    //找到1，新鲜橘子数目加一
                    number++;
                }else if(grid[i][j]==2){
                    //找到2，把腐烂橘子入队列
                    queue.add(new int[]{i,j});
                }
            }
        }

        //初始化分钟数为0
        int minute = 0;
        //当还有新鲜橘子，且队列不为空的时候，对队列里的元素依次进行BFS遍历
        while(number>0&&(!queue.isEmpty())){
            minute++;
            //每一轮循环之前，要记录当时的队列长度，即循环的次数，不能用n<queue.size,因为后续的过程中会对队列进行变化，其size会发生改变，所以得用一个变量记录下来初始队列的长度
            int size = queue.size();
            for(int n=0;n<size;n++){
                //依次出队列，queue.poll()是移除队头并返回
                int[] orange = queue.poll();//orange是只有两个元素的数组
                //x,y 记录腐烂橘子的位置，然后在上下左右进行遍历查找是否有新鲜橘子
                int x = orange[0];
                int y = orange[1];
                if(x-1>=0&&grid[x-1][y]==1){
                    number--;
                    grid[x-1][y] = 2;
                    queue.add(new int[]{x-1,y});
                }
                if(x+1<row&&grid[x+1][y]==1){
                    number--;
                    grid[x+1][y] = 2;
                    queue.add(new int[]{x+1,y});
                }
                if(y-1>=0&&grid[x][y-1]==1){
                    number--;
                    grid[x][y-1] = 2;
                    queue.add(new int[]{x,y-1});
                }
                if(y+1<col&&grid[x][y+1]==1){
                    number--;
                    grid[x][y+1] = 2;
                    queue.add(new int[]{x, y+1});
                }
            }
        }
        //最后当遍历完之后进行判断，看是否还有新鲜橘子，若有，说明不能完全腐烂，返回-1；若无，则返回腐烂的时间
        if(number==0){
            return minute;
        }else{
            return -1;
        }




    }
}
```