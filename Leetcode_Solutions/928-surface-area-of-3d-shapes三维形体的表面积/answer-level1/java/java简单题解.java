### 解题思路
1、先理解题目的意思，题目最外面的大数组
    如[[2]] 指的是 1*1   [[1,2],[3,4]] 指的是 2*2
    而其中[2] 指在 1*1 中有两个小方块
    [1,2]指的是 在第一行 1*1 有一个 1*2 有两个
    [3,4]指的是 在第二行 2*1 有三个 2*2 有四个

2、先计算数值方向重复的
    可以得出公式为  n*4 + 2

3、计算下和右挨着的面积
    比较当前位置的个数和下或右个小方块数，较小的个数即为重复的面数
    注意： 面积重复有两个面，所以后面要乘以2

4、计算最后面积


### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int temp = 0; //用于计算下右挨着重复面积
        int res = 0;
        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[i].length; j++){
                //当前有方块,计算面积并除去竖直方向重复的
                if(grid[i][j] != 0)
                    res = res + grid[i][j]*4 +2;

                //计算下一行挨着重复的面积
                if(i<grid.length-1){
                    if(grid[i][j]>grid[i+1][j]){
                        temp = temp + grid[i+1][j];
                    }
                    else{
                        temp = temp + grid[i][j];
                    }
                }

                //计算右边挨着重复面积
                if(j<grid[i].length-1){
                    if(grid[i][j]>grid[i][j+1]){
                        temp = temp + grid[i][j+1];
                    }
                    else{
                        temp = temp + grid[i][j];
                    }
                }
                  
            }
        }

        //计算最终面积
        res = res - 2*temp;
        return res;
    }
}
```