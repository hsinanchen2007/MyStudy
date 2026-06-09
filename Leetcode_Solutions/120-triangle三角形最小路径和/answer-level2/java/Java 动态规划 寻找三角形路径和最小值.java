### 解题思路
将原有的二维数组优化为一维数组。

### 代码

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle == null || triangle.size() == 0) {
            return 0;
        }
        
        int rows = triangle.size();
        int cols = triangle.get(rows - 1).size();

        // 之所以可以一维数组就可以，是因为之后的结果会覆盖之前的数据，之前的数据本质已经无用
        int[] dp = new int[rows]; // 仅存储下一行的结果即可，下标代表原数据的列即可

        for (int i = 0; i < cols; i++) {
            dp[i] = triangle.get(rows - 1).get(i);
        }

        for (int i = rows - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                dp[j] = Math.min(dp[j], dp[j + 1]) + triangle.get(i).get(j);
            }
        }

        return dp[0];
    }
}
```