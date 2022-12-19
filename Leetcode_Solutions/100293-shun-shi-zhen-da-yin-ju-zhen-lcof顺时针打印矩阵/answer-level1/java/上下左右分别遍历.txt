### 解题思路
其实就是官方给的第二中解法，我理解为是对每一圈对上下左右数据分别进行遍历，每次遍历只要主要行数和列数对增减变化即可；
一直循环结束对条件是：上面的行数值始终小于等于下面的行数值，左边的列数值始终小于等于右边的列数值

### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        if(matrix==null||matrix.length==0||(matrix.length==1&&matrix[0].length==0)){
            return new int[0];
        }
      int cow=matrix.length;
      int col=matrix[0].length;
      int top=0;//上行数
      int bottom=cow-1;//下行数
      int left=0;//左列数
      int right=col-1;//右列数
      int[] result = new int[cow*col];
      int index=0;
      while(top<=bottom&&left<=right){
         
         //上行
         for(int i=left;i<=right;i++){
           result[index++]=matrix[top][i];
         }
           //右列
         for(int i=top+1;i<=bottom;i++){
           result[index++]=matrix[i][right];
         }
           //下行
           if(top!=bottom){
             for(int i=right-1;i>=left;i--){
            result[index++]=matrix[bottom][i];
         }
           }
       
           //左列
           if(left!=right){
            for(int i=bottom-1;i>=top+1;i--){
            result[index++]=matrix[i][left];
            }
           }
        top++;
        bottom--;
        left++;
        right--;

      }


return result;


    }
}
```