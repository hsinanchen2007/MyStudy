### 解题思路
思路是对于每行，计算prefixSum

然后两个for循环遍历所有列，然后计算这两列之间的数量和是否等于target

### 代码

```java
class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;
        for (int i = 0; i < n; i ++) {
            for (int j = 1; j < m; j ++) {
                matrix[i][j] = matrix[i][j] + matrix[i][j - 1];
            }
        }
        int res = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = i; j < m; j ++) {
                Map<Integer, Integer> map = new HashMap<>();
                map.put(0, 1);
                int cur = 0;
                for (int k = 0; k < n; k ++) {
                    cur += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    res += map.getOrDefault(cur - target, 0);
                    map.put(cur, map.getOrDefault(cur, 0) + 1);
                }
            }
        }
        return res;
    }
}
```