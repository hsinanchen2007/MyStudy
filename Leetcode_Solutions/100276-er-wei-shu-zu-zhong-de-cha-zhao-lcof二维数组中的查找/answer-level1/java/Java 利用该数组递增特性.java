### 解题思路
充分利用数组右上角元素（行中最大，列中最小）的特性

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target)      {
        if(matrix.length==0)
            return false;
        // 初始化查找点位右上角（行中最大，列中最小）
        int row=0,column=matrix[0].length-1;
        //  条件 数组索引不越界
        while(row<matrix.length && column>=0){
            //  获取查找点
            int n = matrix[row][column];
            //  比较查找点 
            if(n == target)
                return true;
            // 说明：（因列中最小）这列都不符合要求 列数减一
            else if(n > target) 
                column--;
            //  （因行中最大）这行都不符合要求
            else row++;
        }
        return false;
    }
    
}
```