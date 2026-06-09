### 解题思路
动态规划方法：

dp状态定义为： 走到第n阶台阶需要的步数为：即为：第n-1阶走到n阶的走法 + 加上第n-2阶走到n阶的走法
dp方程为：f(n) = f(n-1) + f(n-2)  (
初始状态为：f(1) = 1 (一阶台阶只有1种走法，两阶台阶有2种走法)

结合代码：
one_step_before 代表 走到第 n-1 阶的走法
two_step_before 代表 走到第 n-2 阶的走法


### 代码

```java
class Solution {
    public int climbStairs(int n) {
        
        if (n <= 2) {
            return n;
        }

        int result = 0;
        // 初始状态
        int one_step_before = 2;
        int two_step_before = 1;

        for (int i = 2; i < n; i++) {
            result = one_step_before + two_step_before;
            // 新的 n-2 阶的走法，就是当前的 n-1 阶的走法 
            two_step_before = one_step_before;
            // 新的 n-1 阶的走法，就是当前的 n 阶的走法
            one_step_before = result;
        }
        return result;
    }
}
```