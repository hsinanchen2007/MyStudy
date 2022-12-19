### 解题思路

简单的斐波那契额数列相似问题。

#### 优化思路 ：

- 加缓存

### 代码

```java

class Solution {

    private static long[] cache;

    private static final int REMAINDER = 1000000007;

    public Solution() {
        this.cache = new long[1000000];
        this.cache[0] = 0;
        this.cache[1] = 1;
        this.cache[2] = 2;
        this.cache[3] = 4;
        this.cache[4] = 7;
        this.cache[5] = 13;
    }

    public int waysToStep(int n) {
        if (cache[n] == 0 && n > 5) {
            int tmp = n;
            while (cache[--tmp] == 0) {
            }
            for (int i = tmp + 1; i <= n; i++) {
                cache[i] = (cache[i - 1] + cache[i - 2] + cache[i - 3]) % REMAINDER;
            }
        }
        return (int) cache[n];
    }
}

```

- 简化变量

### 代码

```java
class Solution {

    public int waysToStep(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 4;
        int a = 1, b = 2, c = 4, d = 0;
        while (n >= 4) {
            d = ((a + b) % 1000000007 + c) % 1000000007;
            a = b;
            b = c;
            c = d;
            n--;
        }
        return d;
    }
}
```