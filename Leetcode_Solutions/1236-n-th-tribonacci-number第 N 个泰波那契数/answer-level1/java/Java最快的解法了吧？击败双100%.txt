算法不解释了，应该都能懂

```
class Solution {
    public int tribonacci(int n) {
        if (n < 2) return n;
        if (n == 2) return 1;
        int t0 = 0;
        int t1 = 1;
        int t2 = 1;
        for (int i = 3; i <= n; i++){
            t2 = t0 + t1 + t2;
            t1 = t2 - t1 - t0;
            t0 = t2 - t1 - t0;
        };
        return t2;
    }
}
```
