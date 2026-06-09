### 解题思路
单纯的递归是反计算机的，要结合剪枝和缓存数组，不然很容易时间复杂度爆炸。

### 代码

```java
class Solution {
        public int fib(int N) {
        Integer[] helps = new Integer[N + 1];
        if (N <= 1) {
            return N;
        }
        helps[0] = 0;
        helps[1] = 1;
        return helper(N, helps);
    }

    private int helper(int n, Integer[] helps) {
        if (helps[n] != null) {
            return helps[n];
        }
        helps[n] = helper(n - 1, helps) + helper(n - 2, helps);
        return helps[n];
    }
}
```