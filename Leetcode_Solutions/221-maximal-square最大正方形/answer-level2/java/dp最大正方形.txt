### 解题思路
动态规划做，这里我为了优化空间，将存储的子数据存在一个两排大小的数组中，但是最后效率很低，且空间复杂度依然高，后序再来优化

### 代码

```java
class Solution {
    public int maximalSquare(char[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return 0;
        }
        int[][] length = new int [2][matrix[0].length];
        int flag =  1;
        int unflag = 0;
        int maxValue = 0;
        for (int i=0;i<matrix.length;i++) {
            for (int j=0;j<matrix[0].length;j++) {
                if (matrix[i][j] == '0') {
                    length[flag][j] = 0;
                    continue;
                }
                if (i == 0 || j == 0) {
                    length[flag][j] = 1;
                } else {
                int minOne = Math.min(length[unflag][j], length[flag][j - 1]);
                length[flag][j] = Math.min(minOne, length[unflag][j - 1]) + 1;
                }
                
                System.out.println(i+":"+j+":"+length[flag][j]);
                if (length[flag][j] > maxValue) {
                        maxValue = length[flag][j];
                }
            }
            int temp = flag;
            flag = unflag;
            unflag = temp;
        }
        return maxValue*maxValue;
    }
} 
```