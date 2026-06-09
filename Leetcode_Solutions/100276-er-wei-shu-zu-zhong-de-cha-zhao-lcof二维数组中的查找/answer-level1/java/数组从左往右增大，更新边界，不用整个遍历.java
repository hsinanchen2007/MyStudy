### 解题思路
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :46 MB, 在所有 Java 提交中击败了100.00%的用户

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix.length==0||matrix[0].length==0|| matrix[0][0]>target||matrix[matrix.length-1][matrix[0].length-1]<target) return false;
       int row=0;
        int col=0;
        int rowMax=matrix.length-1;
        int colMax=matrix[0].length-1;
        while(row<=rowMax){
            if(matrix[row][col]==target) return true;
            if(matrix[row][col]>target){//更新右边界
                if(col==0){//在第一列，退出遍历，输出false
                   break;
                }else {
                    colMax=col-1;
                    row++;
                    col=0;
                }  
            }else{//小于target 正常循环
                if(col==colMax){
                    row++;
                    col=0;
                }else{
                    col++;
                }
            }
        }
        return false;

    }
}
```