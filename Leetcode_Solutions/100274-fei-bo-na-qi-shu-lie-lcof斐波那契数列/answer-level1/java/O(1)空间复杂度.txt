### 解题思路
执行用时 :0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :36.2 MB, 在所有 Java 提交中击败了100.00%的用户

### 代码

```java
class Solution {
    public int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int f0 = 0;
        int f1 = 1;
        for (int i = 0; i < n-1; i++) {
            int res = (f0 + f1) % 1000000007;
            f0 = f1;
            f1 = res;
        }
        return f1;
    }
}
```