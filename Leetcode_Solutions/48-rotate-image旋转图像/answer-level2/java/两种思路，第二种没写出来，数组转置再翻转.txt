### 解题思路
1. 思路一：通过观察可以知道在数组可以通过将数组先转置再按每一行翻转，这样时间复杂度为O($n^2)
2. 思路二：通过观察数组中的下标可以知道顺时针90°旋转，下边变换从 （x,y）-> (y,|x-n+1|) ，时间复杂度同样为 O(n^2)

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        for(int i = 0;i<n;i++) {
            int start = 0;
            int end = n-1;
            while(start<end) {
                int tmp = matrix[i][start];
                matrix[i][start] = matrix[i][end];
                matrix[i][end] = tmp;
                start++;
                end--;
            }
        }
    }
}
```