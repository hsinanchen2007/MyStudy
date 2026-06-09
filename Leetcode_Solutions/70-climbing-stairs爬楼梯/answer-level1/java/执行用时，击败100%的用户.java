```
    public  int climbStairs(int n) {
        int sum1 = 0;
        int sum2 = 1;
        for (int i = 2; i <= n; i++) {
            int tmp = sum1;
            sum1 = sum2;
            sum2 += tmp;
        }
        return sum1 + sum2;
    }
```
