## 心理路程
看到题目的时候,首先会想着,如果是手算的话会怎么去算,大家可以想想,手算最快的方法是啥
其实就是看到几面是露出来的,就是多少面积(废话︿(￣︶￣)︿)

这题给我的感觉就是
人类和计算机的思考方式还是有点不一样的
人类有一些主观的感受,根据你的经历不同,感受不同,会有不同的解法去算这道题
但是计算机层面更希望一些机械的动作,可重复的动作,而且这个动作尽量小

其实就一个个去算,遍历的时候,再把旁边的挨着的面积减掉就行了(人为的算可能就不会用这种方法了)

## 
```
class Solution {
    public int surfaceArea(int[][] grid) {
        // 上下左右的面积都要减掉
        int ans = 0;
        for(int i = 0 ; i < grid.length ; i++){
            for(int j = 0 ; j < grid[0].length ; j ++){
                if (grid[i][j] != 0){
                    ans = ans + grid[i][j] * 4 + 2;
                }
                // 上边的面积减掉
                if (i-1 >= 0){
                    ans -= minNum(grid[i-1][j],grid[i][j]); 
                }
                if (j-1 >= 0){
                    ans -= minNum(grid[i][j-1],grid[i][j]);
                }
                if (i+1 < grid.length){
                    ans -= minNum(grid[i+1][j],grid[i][j]);
                }
                if (j+1 < grid[0].length){
                    ans -= minNum(grid[i][j+1],grid[i][j]);
                }
            }
        }
        return ans;
    }

    public int minNum(int x, int y){
        if (x >= y){
            return y;
        }
        return x;
    }
}
```
