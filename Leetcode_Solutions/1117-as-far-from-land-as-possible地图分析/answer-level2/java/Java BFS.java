### 解题思路
1. 首先建立队列，遍历地图记录陆地所在点
2. 然后记录此时队列的长度，遍历队列中的点，向其上下左右的海洋区域扩张，每生成一块陆地都放入队列中。
3. 直至到队列为空，结束遍历。
4. 查找地图中最高的数值并返回。

### UpDate
参考其他题解[🌊简单Java, 秒懂图的BFS～](https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/jian-dan-java-miao-dong-tu-de-bfs-by-sweetiee/)
本次删去扩张遍历中判断方向的四个if，改为用数组控制方向，
把声明点位置提出队列循环，提前声明，不用再次遍历数组找最大值，直接调用最后一次赋值陆地点


![TIM图片20200403001744.png](https://pic.leetcode-cn.com/508e14732775fd6eeeec2efd0532308844eb8ef80b5d3129295ccd5a093b60d5-TIM%E5%9B%BE%E7%89%8720200403001744.png)

### 代码

```java  [group1-Java]
public class Land{
    int x;
    int y;
    Land(int x,int y) {
        this.x = x; 
        this.y = y;
    }
}
class Solution {
    private static int[] direct_x =new int[]{-1,+1,0,0};//上下左右
    private static int[] direct_y =new int[]{0,0,-1,+1};
    public int maxDistance(int[][] grid) {
        int m = grid.length;//地图高
        int n = grid[0].length;//地图长
        Queue<Land> queue = new LinkedList<>();//队列
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //记录陆地
                if(grid[i][j]==1){
                    queue.add(new Land(i,j));
                }
            }
        }
        if(queue.isEmpty()||queue.size()==m*n)return -1;
        //队列非空循环
        Land land = null;
        while(!queue.isEmpty()){
            int size = queue.size();
            for(int i=0;i<size;i++){
                land = queue.poll();
                for(int d=0;d<4;d++){
                    int newX=land.x+direct_x[d];
                    int newY=land.y+direct_y[d];
                    //下标越界，非海洋区域
                    if(newX < 0 || newY < 0 || newX >= m || newY >= n || grid[newX][newY] != 0){
                        continue;
                    }
                    grid[newX][newY] = grid[land.x][land.y]+1;
                    queue.add(new Land(newX,newY));
                }
            }
        }
        return grid[land.x][land.y]-1;

    }
}
```