学好数学对算法的确有帮助
其实好好思考一下这道题，在一个m*n的长方形里从左上角一直到右下角一共要向右走n-1步，向下走m-1步。一共需要走m+n-2步，而所有的走法就是n-1个向右和m-1个向下的无重复的排列。
所以公式就是(m+n-2)!/((m-1)! * (n-1)!)
代码如下：
``` JAVA
    public int uniquePaths(int m, int n) {
        // 化简CommonFunctions.factorial(n+m-2)/CommonFunctions.factorial(n-1)
        // 把较大数用来做化简，这样尽量保证被除数较小不会溢出
        if (m > n) {
            int t = n;
            n = m;
            m = t;
        }
        long ret = 1;
        for (int i = n; i < n + m - 1; i++) {
        	ret *= i;
        }
        // 下面的直接使用会溢出
        // return
        // factorial(n+m-2)/factorial(n-1)/factorial(m-1);
        return (int) (ret / factorial(m - 1));
    }

    public static int factorial(int n) {
        int res = 1;
        for (int i = 1; i <= n; i++) {
            res *= i;
        }
        return res;
    }
```
