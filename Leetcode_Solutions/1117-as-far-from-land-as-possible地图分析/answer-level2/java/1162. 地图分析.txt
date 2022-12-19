### 解法1：从陆地开始BFS
思路是：
- 先找出所有的陆地
- 从陆地开始，向四周扩展（上下左右）
    - 被扩展到的海洋，其值为陆地值+1
    - 直到不能继续扩展时结束
- 最后一个被扩展的海洋，即为所求


代码：
```java
class Solution {
    public int maxDistance(int[][] grid) {
        // 空地图临界处理
        if(grid.length<=0){
            return -1;
        }

        // 地图长宽
        int m = grid.length;
        int n = grid[0].length;

        // 陆地队列
        Queue<Area> landQueue = new LinkedList();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    landQueue.offer(new Area(i,j));
                }
            }
        }

        // 全是海洋或陆地的临界处理
        if(landQueue.size() == 0 || landQueue.size() == n*m){
            return -1;
        }

        // 从陆地开始，可以扩展的四个方向
        List<Area> spanAreas = new ArrayList();
        spanAreas.add(new Area(0,-1));
        spanAreas.add(new Area(0,1));
        spanAreas.add(new Area(1,0));
        spanAreas.add(new Area(-1,0));

        // 记录最后一个访问的单元格（海洋）
        Area lastVisited = null;

        // 从队列中取陆地，向四方扩展
        while(!landQueue.isEmpty()){
            Area currentLand = landQueue.poll();
            for(Area span:spanAreas){
                int newX = currentLand.x + span.x;
                int newY = currentLand.y + span.y;
                if(newX<0 || newY<0 || newX>=m || newY>=n){
                    continue;
                }
                // 是海洋，则把它的值变为当前陆地的值+1，标记为最后一个访问的，然后入队列
                if(grid[newX][newY]==0){
                    grid[newX][newY] = grid[currentLand.x][currentLand.y]+1;
                    lastVisited = new Area(newX,newY);
                    landQueue.add(lastVisited);
                }
            }
        }

        return grid[lastVisited.x][lastVisited.y]-1;
    }

    private class Area{
        public int x;
        public int y;
        Area(int x,int y){
            this.x=x;
            this.y=y;
        }
    }
}
```

### 解法2：暴力解法（超时）
思路是：
- 先找出所有陆地和海洋
- 每一个海洋找可达的最近陆地
- 所有距离中最大的为所求

```java
// 暴力解法，能得到正确的值，但是会超时
class Solution {
    public int maxDistance(int[][] grid) {
        if(grid.length<=0){
            return -1;
        }

        // 先找出所有陆地和所有海洋
        List<area> areaOceanList = new LinkedList();
        List<area> areaLandList = new LinkedList();
        int m = grid.length;
        int n = grid[0].length;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    areaLandList.add(new area(i,j));
                }else{
                    areaOceanList.add(new area(i,j));
                }
            }
        }

        // 全是海洋或陆地
        if(areaOceanList.size()==0 || areaLandList.size()==0){
            // System.out.println("全是海洋或陆地");
            return -1;
        }

        int distance = -1;// 用来记录，距离陆地最远的海洋到其最近陆地的距离

        // 每一块海洋，尝试往陆地上走
        for(area ocean:areaOceanList){
            int minDistanceFromNow = -1;// 用来记录从ocean出发，距离最近的陆地距离
            for(area land:areaLandList){
                if(accessible(ocean,land,grid)){
                    int currentDistance = Math.abs(ocean.x-land.x) + Math.abs(ocean.y-land.y);
                    if(minDistanceFromNow == -1){
                        minDistanceFromNow = currentDistance;
                    }else{
                        minDistanceFromNow = Math.min(minDistanceFromNow,currentDistance);
                    }
                }
            }

            distance = Math.max(distance,minDistanceFromNow);
        }
        return distance;
    }

    // 怎么尝试？
    private boolean accessible(area ocean,area land,int[][] grid){
        return accessibleTry1(ocean,land,grid) || accessibleTry2(ocean,land,grid);
    }


    // 第一种方法：先 x=ocean.x，再 y=land.y
    private boolean accessibleTry1(area ocean,area land,int[][] grid){
        int x = ocean.x;
        int smallerY = Math.min(ocean.y,land.y);
        int biggerY = Math.max(ocean.y,land.y);
        for(int y = smallerY ; y<=biggerY;y++){
            if(grid[x][y] == 1 && y!=land.y){
                return false;
            }
        }

        int y = land.y;
        int smallerX = Math.min(ocean.x,land.x);
        int biggerX = Math.max(ocean.x,land.x);
        for(x=smallerX; x<=biggerX; x++){
            if(grid[x][y] == 1 && x!=land.x){
                return false;
            }
        }

        return true;
    }

    // 第二种方法：先 x=land.x，再 y=ocean.y
    private boolean accessibleTry2(area ocean,area land,int[][] grid){
        int x = land.x;
        int smallerY = Math.min(ocean.y,land.y);
        int biggerY = Math.max(ocean.y,land.y);
        for(int y = smallerY ; y<=biggerY;y++){
            if(grid[x][y] == 1 && y!=land.y){
                return false;
            }
        }

        int y = ocean.y;
        int smallerX = Math.min(ocean.x,land.x);
        int biggerX = Math.max(ocean.x,land.x);
        for(x=smallerX; x<=biggerX; x++){
            if(grid[x][y] == 1 && x!=land.x){
                return false;
            }
        }

        return true;
    }


    private class area{
        public int x;
        public int y;
        area(int x,int y){
            this.x=x;
            this.y=y;
        }
    }
}
```