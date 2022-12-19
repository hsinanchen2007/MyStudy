### 解题思路
主要特点：使用了时间标记 minuteFlag

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        int row=grid.length;
        int col =grid[0].length;
        int minuteFlag=2; 
        while(true){
            boolean hasChange=false;
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    if(grid[i][j]==1){
                        if(change(grid,i-1,j,minuteFlag)
                            || change(grid,i+1,j,minuteFlag) 
                            || change(grid,i,j+1,minuteFlag) 
                            || change(grid,i,j-1,minuteFlag)
                        ){
                            grid[i][j]=minuteFlag+1;
                            hasChange=true;
                        }
                    }  
                }
            }
            minuteFlag++;
            if(!hasChange){
                if(hasGood(grid)){
                     return -1;
                }else{
                    return minuteFlag-3;
                }
            }
        }
    }

    private boolean change(int[][] grid,int i,int j,int minuteFlag){
        if(i<0||i>=grid.length||j<0||j>=grid[0].length || grid[i][j]!=minuteFlag){
            return false;
        }
        return true;
    }

    private boolean hasGood(int[][] grid){
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==1){
                    return true;
                }  
            }
        }
        return false;
    }
}
```