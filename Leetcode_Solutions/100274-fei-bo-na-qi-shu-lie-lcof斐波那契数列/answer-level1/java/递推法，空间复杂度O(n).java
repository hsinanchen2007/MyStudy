定义两个变量f1、f2来保存f(n - 1) 和 f(n -2)的值。

class Solution {
    public int fib(int n) {
        if(n <= 1)
            return n;
        int f1 = 0;
        int f2 = 1;
        for(int i=2;i<n;i++)
        {
            int f3 = (f1 + f2)%1000000007;
            f1 = f2;
            f2 = f3;
        }
        return (f1 + f2)%1000000007;
    }
}