### 解题思路
此处撰写解题思路
二维表格的广度优先遍历，一层一层向外叠加，最后遍历到的海洋即为到陆地最远的海洋，且曼哈顿距离为广度优先遍历层数-1.
### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        int[]r=new int []{0,1,-1,0};
        int[]c=new int[]{1,0,0,-1};
        Queue<int[]>queue=new ArrayDeque();
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==1){
                    queue.offer(new int[]{i,j});
                }
            }
        }
        boolean hasOcea=false;
        int[] point=null;
        while(!queue.isEmpty()){
            point=queue.poll();
            int x=point[0],y=point[1];
            for(int i=0;i<4;i++){
                int newx=point[0]+r[i];
                int newy=point[1]+c[i];
                if(newx<0||newx>=grid[0].length||newy<0||newy>=grid.length||grid[newx][newy]!=0){
                    continue;
                }
                grid[newx][newy]=grid[x][y]+1;//相当于遍历层数
                queue.offer(new int []{newx,newy});
                hasOcea=true;
            }
        }
        if(queue==null||!hasOcea){
            return -1;
        }
        return grid[point[0]][point[1]]-1;//广度遍历在1的基础上加一，所以最后减一。曼哈度距离即广度遍历层数减一。

    }
}
```