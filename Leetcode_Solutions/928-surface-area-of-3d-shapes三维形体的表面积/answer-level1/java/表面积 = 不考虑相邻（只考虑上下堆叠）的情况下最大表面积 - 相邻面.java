### 解题思路
表面积 = 不考虑相邻（只考虑上下堆叠）的情况下最大表面积 - 相邻面
相邻面 = grid[i][j]与它左边相邻格子里比较，块数较少的值 + grid[i][j]与它上边相邻格子里比较，块数较少的值

### 代码

```java
//int[][] arr3 = {{1,2},{3,4}}; //测试用例
    public static int surfaceArea(int[][] grid) {

        int n = grid.length;//获得N
        int cover = 0;//表面积

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 0){//防止出现0方块，结果cover+2的情况
                    cover = cover + grid[i][j] * 4 + 2;//不考虑相邻（只考虑上下堆叠）的情况下最大表面积
                }
                //每一个格子grid[i][j]，只跟它的上和左进行比较，
                //1、防止数组越界
                //2、防止重复比较
                //选择方块少的那个作为重叠面
                if(i > 0){
                    cover -=  Math.min(grid[i-1][j],grid[i][j])*2;
                }
                if(j > 0){
                    cover -= Math.min(grid[i][j-1],grid[i][j])*2;
                }
            }
        }
        return cover;
    }
```