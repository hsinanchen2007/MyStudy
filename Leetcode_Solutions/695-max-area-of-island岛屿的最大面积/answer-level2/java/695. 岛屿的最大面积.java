### 解题思路
队列+标记法。
- 遍历数组
- 将遇到的值为1的点入队列，是一个岛屿的第一个元素
- 当队列非空时
    - 逐一从队列里弹出队首元素
    - 当元素对应的点值为0时，表示已经被访问过了，啥也不做
    - 当元素对应的点值为1时，表示未被访问过，标记为0，当前岛屿面积+1；检查上下左右四个点是否为1，为1的入队列
    - 重复上述步骤，直到队列为空
    - 队列为空时，计数器的值即为当前岛屿的面积
- 继续查找下一个为1的点
- 遍历结束后可以获得所有岛屿的面积，最大的那个即为所求


### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {

        // 特殊处理
        if(grid.length<=0 || grid[0].length<=0){
            return 0;
        }

        int maxArea = 0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                // 不是1，啥也不做
                if(grid[i][j]!=1){
                    continue;
                }
                Queue<Location> queue = new LinkedList();
                // 把 grid[i][j]扔到队列里，初始化计数器为0
                queue.offer(new Location(i,j));
                int count = 0;
                // 当队列非空时，注意从队列里取元素出来
                // 若元素为0，则表示已经被访问过了，略
                // 若元素为1，则将其置为0，计数+1，并检查其上下左右4个点是否有值为1的，入队列
                // 直到队列空，得到的即为一个岛屿的面积
                while(!queue.isEmpty()){
                    Location current = queue.poll();
                    if(grid[current.x][current.y]==0){
                        continue;
                    }
                    grid[current.x][current.y] = 0;
                    count++;
                    // 上
                    if(valid(grid,current.x-1,current.y) && 1==grid[current.x-1][current.y]){
                        queue.offer(new Location(current.x-1,current.y));
                    }
                    // 下
                    if(valid(grid,current.x+1,current.y) && 1==grid[current.x+1][current.y]){
                        queue.offer(new Location(current.x+1,current.y));
                    }
                    // 左
                    if(valid(grid,current.x,current.y-1) && 1==grid[current.x][current.y-1]){
                        queue.offer(new Location(current.x,current.y-1));
                    }
                    // 右
                    if(valid(grid,current.x,current.y+1) && 1==grid[current.x][current.y+1]){
                        queue.offer(new Location(current.x,current.y+1));
                    }
                }
                // 所有岛屿里，取面积最大的
                maxArea = Math.max(maxArea,count);
            }
        }
        return maxArea;
    }

    private boolean valid(int[][] grid,int x,int y){
        if(x<0 || y<0){
            return false;
        }
        if(x >= grid.length){
            return false;
        }
        if(y >= grid[x].length){
            return false;
        }
        return true;
    }

    private class Location{
        Location(int x,int y){
            this.x=x;
            this.y=y;
        }
        public int x;
        public int y;
    }

}
```