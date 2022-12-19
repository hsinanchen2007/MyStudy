设要爬的阶梯数为n，
f(n)为爬到n的方法的数量
那么有
f(n) = f(n-1) + f(n-2)
1-1,2-2,3-3,4-5,5-8...
可以看出答案集合是一个斐波那契数列
```
class Solution {
    public int climbStairs(int n) {
        if(n < 1)
            return 0;
        if(n == 1 || n == 2)
            return n;
        int n1 = 1;
        int n2 = 2;
        for(int i = 3; i < n; i++){
            n2 += n1;
            n1 = n2 - n1;
        }
        return n1 + n2;
    }
}
```