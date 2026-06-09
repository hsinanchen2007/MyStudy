### 解题思路
此处撰写解题思路、
采用两个list分别 海洋和陆地，然后遍历计算每个海洋到陆地的距离，选出距离最远的那个岛出来

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        List<Point> oceanList = new ArrayList<>();
        List<Point> landList = new ArrayList<>();
        int N = grid.length;
        for (int i=0; i<N;i++){
            for (int j=0; j<N;j++){
                if (grid[i][j] == 0 ) {
                    if (i >0 && i<N-1 && j>0 && j<N-1){
                        if ( grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1] > 0){
                            continue;
                        }     b
                    }

                    oceanList.add(new Point(i,j));
                } else {
                    landList.add(new Point(i,j));
                }
            }
        }

        if (oceanList.size() == 0 || landList.size()==0)
           return -1;
        int max = 0;
        int min = 0;
        for (Point p:oceanList){
            int x = p.getX();
            int y = p.getY();
            int minV = Integer.MAX_VALUE;
            for(Point p2:landList){
                int dis = Math.abs(x-p2.getX()) + Math.abs(y-p2.getY());
                if (minV > dis){
                    minV = dis;
                }
            }
            if (minV > min){
                min = minV;
            }
        }
        return min;
    }

    class Point{
        int x;
        int y;
        public Point(int x,int y){
            this.x = x;
            this.y = y;
        }

        public int getX(){
            return x;
        }

        public int getY(){
            return y;
        }
    }
}
```