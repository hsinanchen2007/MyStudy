### 从最外圈开始，依次向内圈旋转
先写一个旋转一条边的函数，接收边界，旋转这个边界内的数据。

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int left = 0;
        int right = matrix.length-1;
        while(left < right){
            rotateEdge(matrix,left,right);
            left++;
            right--;
        }
        //rotateEdge(matrix,left,right-1);
    }

    private void rotateEdge(int[][] matrix,int left,int right){
        for(int i=left;i<right;i++){
            int tmp = matrix[i][right];
            matrix[i][right] = matrix[left][i];

            int tmp2 = matrix[right][right-i+left];
            matrix[right][right-i+left] = tmp;

            int tmp3 = matrix[right-i+left][left];
            matrix[right-i+left][left] = tmp2;

            matrix[left][i] = tmp3;

        }
    }
}
```