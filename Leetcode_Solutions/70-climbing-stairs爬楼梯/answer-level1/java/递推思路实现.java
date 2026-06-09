思路：
1.走到n阶梯，必须是站在n-1或n-2台阶上。fn=fn-1  +  fn-2；
2.第一阶梯时，只有1种。f1=1；
3.第二阶梯，2种。  f2=2；
单看条件可知是一个简单递归。
考虑时间空间，斐波拉契就是个无底洞了。
公式已有的情况下，递归可以转为递推思路求解。
f3=f2+f1； f4=f3+f2；使用3个指针，分别指向fm ，fm+1 ，fm+2；移动指针直到n即可。
空间复杂度时间复杂度均为常量（执行时间0ms）；
```java []
class Solution {
    public int climbStairs(int n) {
        if (n==1||n==2) return n;
       int n1=1;
       int n2=2;
       int n3=n1+n2;
        for (int i = 3; i <= n; i++) {
            n3=n1+n2;
            n1=n2;
            n2=n3;
        }
        return n3;
    }
}
```
```c# []
class Solution {
    public int climbStairs(int n) 
    {
        if (n==1||n==2) return n;
       int n1=1;
       int n2=2;
       int n3=n1+n2;
        for (int i = 3; i <= n; i++) 
        {
            n3=n1+n2;
            n1=n2;
            n2=n3;
        }
        return n3;
    }
}
```
