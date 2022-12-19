### 代码（递归版）：

```java
class Solution {
    public int lastRemaining(int n, int m) {
        if (n == 1) {
            return 0;
        }

        if (n <= 0 || m <= 0) {
            return -1;
        }

        return (lastRemaining(n - 1, m) + m) % n;
    }
}
```