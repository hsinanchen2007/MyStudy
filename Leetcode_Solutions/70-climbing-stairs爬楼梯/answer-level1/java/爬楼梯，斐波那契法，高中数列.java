### 解题思路
f(i,n)=f(i+1,n)+f(i+2,n);在第i阶上到达第n阶，等价于从第i阶走一步次数加上从第i阶走两步的次数（递归思想）；
这道爬楼梯可以转化为以下数学问题：
f(1)=1,f(2)=2,f(n)=f(n-1)+f(n-2)，求f(n)？
斐波那契数列


### 代码

```java
class Solution {
    public int climbStairs(int n) {
       //斐波那契法
        int a = 1, b = 2, sum ;
        if (n == 1){
            return 1;
        }
        for (int i=2 ; i <= n; i ++ ){
            sum = a+b;
            a = b;
            b = sum;
        }
        return a;

    }
}
```