![image.png](https://pic.leetcode-cn.com/17930037270b558b537dccb492a9498d637db2aea918ebef576502da386420af-image.png)
int fib(int n)
{
    if (n == 0)
    {
        return 0; 
    }
    else if(n == 1){
        return 1;
    }
    else
    {
        long long fib_one = 1;
        long long fib_two = 0;
        long long fibn = 0;
        for (int i = 2; i <= n; i++)
        {
            fibn = (fib_one + fib_two)%1000000007;
            fib_two = fib_one;
            fib_one = fibn;
        }
        return fibn;
    }    
}