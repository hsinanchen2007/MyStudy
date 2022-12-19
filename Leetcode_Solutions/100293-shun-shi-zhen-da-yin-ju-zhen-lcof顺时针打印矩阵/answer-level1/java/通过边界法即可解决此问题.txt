### 解题思路
代码十分详细，四个边界每次走完一行，边界缩短一部分，样例里有个[]的数组，要小心
### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        if(matrix.length==0){
            return new int[]{};
        }
        int left,right,top,down;
        int[] k=new int[matrix.length*matrix[0].length];
        int index=0;
        left=0;
        right=matrix[0].length-1;
        top=0;
        down=matrix.length-1;
        while (true){
            for(int i=left;i<=right;i++){
                k[index]=matrix[top][i];
                index++;
            }
            top++;
            if(top>down){
                break;
            }
            for(int i=top;i<=down;i++){
                k[index]=matrix[i][right];
                index++;
            }
            right--;
            if(right<left){
                break;
            }
            for(int i=right;i>=left;i--){
                k[index]=matrix[down][i];
                index++;
            }
            down--;
            if(down<top){
                break;
            }
            for(int i=down;i>=top;i--){
                k[index]=matrix[i][left];
                index++;
            }
            left++;
            if(left>right){
                break;
            }

        }
        return k;
    }
}
```