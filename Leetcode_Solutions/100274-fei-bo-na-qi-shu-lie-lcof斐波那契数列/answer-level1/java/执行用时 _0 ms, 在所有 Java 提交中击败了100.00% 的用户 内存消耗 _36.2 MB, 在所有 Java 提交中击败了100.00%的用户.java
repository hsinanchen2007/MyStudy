### 解题思路
此处撰写解题思路 用三个参数循环的加

### 代码

```java
class Solution {
    public int fib(int n) {
         if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;

        int a = 0;
        int b = 1;
        int c = 0;
        for (int i = 3; i <= n + 1; i++) {
            c = (a % 1000000007 + b % 1000000007) % 1000000007;
            a = b;
            b = c;
        }
        return c;
    }
}
```