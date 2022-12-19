### 解题思路
此处撰写解题思路
首先需要设置四个控制变量，能够遍历完一圈后能接着遍历下一圈，主要需要注意的是二维数组的边界。
先向右遍历然后再向下遍历，这两步只要满足c0<=c1 && r0 <= r1，但是在进行向左向上操作的时候需要满足，c0<c1 && r0<r1，不然当行数为1或者列数为1的时候则会超出边界。
### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        if(matrix.length == 0)
            return new int[0];
        int r0 = 0, r1 = matrix.length-1;
        int c0 = 0, c1 = matrix[0].length-1;
        int[] res = new int[(c1+1)*(r1+1)];
        int count = 0;
        while(c0 <= c1 && r0 <= r1){
            for(int i = c0; i <= c1; i++){
                res[count++] = matrix[c0][i];
            }
            for(int i = r0+1; i <= r1; i++){
                res[count++] = matrix[i][c1];
            }
            if(c0 < c1 && r0 < r1){
                for(int i = c1-1; i >= c0; i--){
                    res[count++] = matrix[r1][i];
                }
                 for(int i = r1-1; i > r0; i--){
                    res[count++] = matrix[i][c0];
                }
            }
            c0++;
            c1--;
            r0++;
            r1--;
        }
        return res;
    }
}
```