递归的解决办法会超时，故用动态规划的方式
```
class Solution {
    public int tribonacci(int n) {
       //第一种：递归
        // if (n == 1 || n == 2)
        //     return 1;
        // else if (n == 0)
        //     return 0;
        // return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);

        
        //第二种：动态规划
        if (n == 0)
            return 0;
        int[] f = new int[n + 1];
        f[0] = 0;
        f[1] = f[2] = 1;
        for (int i = 3; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2] + f[i - 3];
        }
        return f[n];

    }
}
```
