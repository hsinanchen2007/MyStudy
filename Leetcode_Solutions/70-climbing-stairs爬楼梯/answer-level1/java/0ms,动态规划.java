其实思路，用动态规划解：
就是第一项为1第二项为2的斐波那契数列，求第n项数列的值
```
    public int climbStairs(int n) {
         if (n == 1) {
            return 1;
        }
        int a = 1;
        int b = 2;
        for (int i = 2; i < n; i++) {
            b = a + b;
            a = b - a;
        }
        return b;
    }
```
