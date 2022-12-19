### 解题思路

先用快速幂拿到10^n, 然后再循环打印

### 代码

```java
class Solution {
    // 先用快速幂拿到10^n, 然后再循环打印
    public int[] printNumbers(int n) {
        int res = getPow(10, n);
        int[] out = new int[res - 1];
        for (int i = 0; i < res - 1; i ++) out[i] = i + 1;
        return out;
    }
    private int getPow(int base, int n) {
        if (n == 0) return 1;
        int res = getPow(base, n >> 1);
        res *= res;
        if ((n & 1) != 0) res *= base;
        return res;
    }
}
```