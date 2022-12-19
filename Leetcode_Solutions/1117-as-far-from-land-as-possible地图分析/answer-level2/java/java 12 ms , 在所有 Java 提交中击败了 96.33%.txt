### 解题思路
以岛为中心，遍历向外扩展。

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        int row = grid.length;
        int col =grid[0].length;
        int count=2;
        
        while(true){
            boolean hasChange=false;
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    if(grid[i][j]!=count-1){
                        continue;
                    }
                    if(doChange(grid,i+1,j,count)){
                        hasChange=true;
                    }
                    if(doChange(grid,i-1,j,count)){
                        hasChange=true;
                    }
                    if(doChange(grid,i,j+1,count)){
                        hasChange=true;
                    }
                    if(doChange(grid,i,j-1,count)){
                        hasChange=true;
                    }
                }
            }
            if(!hasChange){
                if(count==2){
                    return -1;
                }
                return count-2;
            }
            count++;
        }
    }

    //改变海洋值
    private boolean doChange(int[][] grid,int i,int j,int count){
        if(i<0||i>=grid.length || j<0||j>=grid[0].length ||grid[i][j]!=0){
            return false;
        }
        grid[i][j]=count;
        return true;
    }
}
```