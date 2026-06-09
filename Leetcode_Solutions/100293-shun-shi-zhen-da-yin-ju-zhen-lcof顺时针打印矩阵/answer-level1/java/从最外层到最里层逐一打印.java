### 解题思路
首先把边界定义好，然后按照往右、往下、往左、往上这样的顺序遍历数组的最外层。最外层遍历完成后将4个边界往里面收缩一步，继续按照右下左上的顺序遍历下一层。注意当达到最里层，左/上边界和右/下边界重合的时候，则只需要遍历右和下，无需打印左和上，否则会重复打印。

### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {
         if(matrix==null||matrix.length==0||matrix[0].length==0){
             return new int[0];
         }
         int[] answer=new int[matrix.length * matrix[0].length];
         int rl=0,rh=matrix.length-1;
         int cl=0,ch=matrix[0].length-1;
         int cur=0;
         while(rl<=rh&&cl<=ch){
             for(int j=cl;j<=ch;j++){
                 answer[cur++]=matrix[rl][j];
             }
             for(int i=rl+1;i<=rh;i++){
                 answer[cur++]=matrix[i][ch];
             }
             if(rl<rh&&cl<ch){
                for(int j=ch-1;j>=cl;j--){
                     answer[cur++]=matrix[rh][j];
                 }
                 for(int i=rh-1;i>=rl+1;i--){
                     answer[cur++]=matrix[i][cl];
                 } 
             }
             rl++;
             cl++;
             rh--;
             ch--;
         }
         return answer;
    }
}



```