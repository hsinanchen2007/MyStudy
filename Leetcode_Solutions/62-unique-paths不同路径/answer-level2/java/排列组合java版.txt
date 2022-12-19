```java
    public int uniquePaths(int m, int n) {
        if (m <= 1 || n <= 1) return 1;

        int x = Math.min(m, n)-1;
        int y = m + n-2;

        long fenzi = jiecheng(y, x);
        long fenmu = jiecheng(x, x);
        return Integer.parseInt(String.valueOf(fenzi/fenmu));
    }

    private long jiecheng(int m, int size) {
        long ans = 1;
        while (size > 0) {
            ans *= m;
            m--;
            size--;
        }
        return ans;
    }
```
