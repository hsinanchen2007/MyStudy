### 解题思路
此处撰写解题思路
这道题题意比较难理解，我大概解释一下[[1,2],[3,4]]表示在grid【0，0】上有一个正方体，【0,1】上有一个【1,0】有3个，【1,1】有4个
按照这个来理解题意
首先 先计算有多少个正方体，然后乘以6 算出总面积
第二步 依次减去从X,Y,Z轴重叠的部分
### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int sum = 0;
        for(int i=0;i<grid.length;i++){//计算正方体的总个数
            for(int j=0;j<grid.length;j++){
                sum+=grid[i][j];
            }
        }
        sum = sum*6;
        for(int i=0;i<grid.length;i++){//计算X轴的重叠面
            for(int j=1;j<grid.length;j++){
                sum -= Math.min(grid[i][j],grid[i][j-1])*2;
            }
        }
        for(int j=0;j<grid.length;j++){//计算Y轴的重叠面
            for(int i=1;i<grid.length;i++){
                sum -= Math.min(grid[i][j],grid[i-1][j])*2;
            }
        }
        for(int i=0;i<grid.length;i++){//计算Z轴的重叠面
            for(int j=0;j<grid.length;j++){
                if(grid[i][j]>1){
                    sum=sum-grid[i][j]*2+2;
                }
            }
        }
        return sum;

    }
}
```