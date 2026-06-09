### 解题思路

### 代码

```java
class Solution {
   public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int[] bp = new int[obstacleGrid[0].length];
        bp[0] = 1;
        for (int[] ints : obstacleGrid) {
            if (ints[0] == 1) bp[0] = 0;
            for (int j = 1; j < obstacleGrid[0].length; j++) {
                if (ints[j] == 1) bp[j] = 0;
                else bp[j] += bp[j - 1];
            }
        }
        return bp[obstacleGrid[0].length - 1];
    }
}
```