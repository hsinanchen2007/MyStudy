### 解题思路
根据题目，可以推导出递推公式：
公式 f(n) = f(n-1) + f(n-2)
其中 f(1) = 1, f(2) = 2
但是直接写递归的方法，超时，所以转换为循环的方式，代码如下：

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        /*
            公式 f(n) = f(n-1) + f(n-2)
            f(1) = 1, f(2) = 2
        */
        if (n < 3) return n;
        int a = 1, b = 2, c = 3;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}
```