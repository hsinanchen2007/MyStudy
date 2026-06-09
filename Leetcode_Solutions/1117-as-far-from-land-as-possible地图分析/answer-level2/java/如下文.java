### 解题思路
注释写了，BFS

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        //异常处理
        if(grid.length==0){
            return 0;
        }
        //存放陆地位置
        List<Position> list = new ArrayList<>();
        int len = grid.length;
        //遍历存放陆地位置
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(grid[i][j]==1){
                    list.add(new Position(i,j));
                }
            }
        }
        //如果都为海洋或者都为陆地，返回-1
        if(list.size()==0 || list.size()==len*len){
            return -1;
        }
        return maxDistance(grid, list, 0);
    }
    
    public int maxDistance(int[][] grid, List<Position> list, int cur){
        //存放遍历每一个陆地后上下左右填海为陆地后的状态
        List<Position> levelList = new ArrayList<>();
        //遍历每一个陆地然后把新填的海放进去levelList，以便于后面的遍历
        for(Position position:list){
            if(position.x>0){
                //如果陆地的左边是海洋，则把位置放进levelList,然后填海，下面同理，四个方向做同样的操作
                if(grid[position.y][position.x-1]!=1){
                    levelList.add(new Position(position.y,position.x-1));
                    grid[position.y][position.x-1]=1;
                }
            }
            if(position.x<grid.length-1){
                if(grid[position.y][position.x+1]!=1){
                    levelList.add(new Position(position.y,position.x+1));
                    grid[position.y][position.x+1]=1;
                }
            }
            if(position.y>0){
                if(grid[position.y-1][position.x]!=1){
                    levelList.add(new Position(position.y-1,position.x));
                    grid[position.y-1][position.x]=1;
                }
            }
            if(position.y<grid.length-1){
                if(grid[position.y+1][position.x]!=1){
                    levelList.add(new Position(position.y+1,position.x));
                    grid[position.y+1][position.x]=1;
                }
            }
        }
        //已经没有需要遍历的陆地了，则返回结果
        if(levelList.size()==0){
            return cur;
        }
        //每次递归，层数加一
        return maxDistance(grid, levelList, cur+1);
    }
    
    class Position{
        int x;
        int y;
        Position(int x, int y){
            this.x = y;
            this.y = x;
        }
    }
}
```