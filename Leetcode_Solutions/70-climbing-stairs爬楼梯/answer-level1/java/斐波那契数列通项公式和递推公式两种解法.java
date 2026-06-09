### 解题思路
斐波那契数列的问题，可以根据其通项公式或递推公式来解题。

斐波那契：1,1,2,3,5……

### 代码
1、通项公式解法，需要注意n+1这个地方，因为本题最前面少了一项1；
```java
class Solution {
    public int climbStairs(int n) {
        double sqrt_5 = Math.sqrt(5);
        double fib_n = Math.pow((1 + sqrt_5) / 2, n + 1) - Math.pow((1 - sqrt_5) / 2,n + 1);
        return (int)(fib_n / sqrt_5);
    }
}

解法二：递推公式解法：
class Solution {
    public int climbStairs(int n){
        if(n <= 2){
            return n;
        }
        int f1 = 1,f2 = 2,f3 = 3;
        for(int i = 3;i <= n; i++){
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
}

```