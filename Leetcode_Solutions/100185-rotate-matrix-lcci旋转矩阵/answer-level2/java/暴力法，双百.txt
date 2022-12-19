### 解题思路
整体顺时针旋转90°，可以考虑把一个矩阵的每一层作为一个空心矩阵， 只旋转四条边，从外到内旋转每一个空心矩阵的每一条边即可。

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int len = matrix.length;
        int[] now = new int[]{0,0};
        while (now[0]<len/2){
            int y = now[1];
            for (int i = now[0]; i < len-now[0]-1; i++) {
                int x = i;
                int last = matrix[y][x];
                for(int z = 0;z < 4;z++){
                    int t = y;
                    y = x;
                    x = len-1-t;
                    int temp = matrix[y][x];
                    matrix[y][x] = last;
                    last = temp;
                }
            }
            now[0]++;
            now[1]++;
        }
    }
}
```