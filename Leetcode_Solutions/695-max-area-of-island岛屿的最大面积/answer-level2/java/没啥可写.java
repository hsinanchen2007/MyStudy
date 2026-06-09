### 解题思路
主要是要记录已经遍历过的数组，防止重复扫描，这样理论上可以节约时间，然而并没有，应该还可以优化，算了就这样吧

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        line=grid.length;
        row=grid[0].length;
        List<Integer> areas=new ArrayList<>();
        
        for(int i=0;i<line;i++){
                for(int j=0;j<row;j++){
                    if(grid[i][j]==1 && !contain(i,j)){
                        area=0;
                    
                        areas.add(islandArea(grid,i,j));
                    }
                }
        }
        
        return areas.stream().max((i,j)->i-j).isPresent()?(areas.stream().max((i,j)->i-j).get()):0;
    }

     private Set<Integer> sums=new LinkedHashSet<>();  //记录已经扫描过的1，免得重复计算

    private int line,row,area;  //数组的行列、单个岛屿的面积



    private void addLine(int x,int y){
        sums.add(x*53+y);
    }
    private boolean contain(int x,int y){
        return sums.contains(x*53+y);
    }
    private int islandArea(int[][] grid,int x,int y){
        if(grid[x][y]==0){
            return area;
        }else if(grid[x][y]==1&&!contain(x,y)){
            addLine(x,y);
            area++;
            if(x>=1){
                islandArea(grid,x-1,y);
            }
            if(y>=1){
                islandArea(grid,x,y-1);
            }
            if(x<line-1){
                islandArea(grid,x+1,y);
            }
            if(y<row-1){
                islandArea(grid,x,y+1);
            }
        }
        return area;
    }
}
```