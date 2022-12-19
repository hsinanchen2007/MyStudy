### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    long[] caches;

    public int fib(int n) {
        if (n == 0) {
            return 0;
        }
        caches = new long[n + 1];
        Arrays.fill(caches, -1);
        caches[0] = 0;
        caches[1] = 1;
        if (n == 1) {
            return n;
        }

        return  helper(n);
    }

    private int helper(int n) {
        if (caches[n] != -1) {
            return (int) caches[n];
        }
        caches[n] = (helper(n - 1) + helper(n - 2)) % 1000000007;
        return (int) caches[n];
    }
}
```