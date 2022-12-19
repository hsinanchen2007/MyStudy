### 解题思路
斐波那契数列变形
每次你可以爬 1 或 2 个台阶
设n个台阶有f(n)个走法，问题可以简化为两种情况相加：
- 第一次走1个台阶，接下来n-1个台阶有f(n-1)种走法
- 第一次走2个台阶，接下来n-2个台阶有f(n-2)种走法
所以f(n) = f(n-1)+f(n-2)，满足斐波那契数列。

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        if(n == 0)
            return 0;
        if(n==1)
            return 1;
        int f_n_2 = 0;
        int f_n_1 = 1;
        int f_n = 0;
        for(int i = 0;i<n;i++){
            f_n = f_n_1+f_n_2;
            f_n_2 = f_n_1;
            f_n_1 = f_n;
        }
        return f_n;
    }
}
```