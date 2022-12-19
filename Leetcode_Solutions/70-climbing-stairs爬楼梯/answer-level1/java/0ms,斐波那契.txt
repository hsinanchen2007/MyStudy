### 解题思路
数组来存储已经计算过的结果，避免重复计算

### 代码

```java
class Solution {
    private int[] results;

    public int climbStairs(int n) {
        if (results == null) {
            results = new int[n];
        }
        if (n == 1) {
            results[0] = 1;
            return 1;
        } else if (n == 2) {
            results[1] = 2;
            return 2;
        }
        if (results[n - 1] != 0) {
            return results[n - 1];
        } else {
            int result = climbStairs(n - 1) + climbStairs(n - 2);
            results[n - 1] = result;
            return result;
        }
    }
}
```