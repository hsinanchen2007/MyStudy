### 解题思路
1.数组左下角的值为此列的最大值，此行的最小值。将它和target比较可用于消除行或者列
### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix.length==0 || matrix[0].length==0){
            return false;
        }
        //左下角标记法(i,j)表示左下角
        int i=matrix.length-1;
        int j=0;
        while(i>=0&&j<matrix[0].length){
            if(matrix[i][j]==target){
                return true;
            }else if (matrix[i][j]>target){
                //消除行
                i--;
            }else{
                //消除列
                j++;
            }
        }
        //循环结束证明未找到，则直接返回false
        return false;

    }
}
```