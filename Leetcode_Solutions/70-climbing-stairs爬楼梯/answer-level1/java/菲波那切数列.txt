### 解题思路
解题的时候，一定要考虑全面，一些特殊情况，计算机的本质，就是不断的重复执行
枚举法
 1台阶：1
 2台阶：2
 3台阶：1+2
 n台阶：f(n-1)+f(n-2) ,其本质斐波那契数列

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        //1.枚举法
        // 1台阶：1
        // 2台阶：2
        // 3台阶：1+2
        // n台阶：f(n-1)+f(n-2) ,其本质斐波那契数列
        if((n-1)==0){
            return 1;
        }
        int[] f= new int[n];
        f[0]=1;
        f[1]=2;
        int s = 0;
        for(int i= 2;i< n;i++){
            f[i]=f[i-1]+f[i-2];
        }
        return f[n-1];
    }
}
```